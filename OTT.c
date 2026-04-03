#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//********************************************************************************Link list struct*************************************************************** */
typedef struct Linklist // structure for linkist to store names .
{
    char list_category[50]; // sub category of movie , series...

    char list_Maincategory[50]; // types in ott platform

    char sub_category[50]; // eg name of movies = CONJURING, IT...etc.

    int ratings; // ratings of that particular video

    struct Linklist *next; // next link node to build a list
} Lkl;

//********************************************************************************Sub  treee struct*************************************************************** */

typedef struct Node // structure for tree(BST)
{
    char category[50]; // sub category of movie , series...

    int countAciiSubTree; // counting the ascii value of string

    struct Node *right, *left; // BST

    Lkl *list; // pointer of linlkist structure.
} Node;

//********************************************************************************main treee struct*************************************************************** */
typedef struct Maintree // types in ott platform
{
    char Maincategory[50];

    int countAciiMainTree; // counting the ascii value of string

    Node *root;

    struct Maintree *left, *right;

} Maintree;

//********************************************************************************Link list creation *************************************************************** */

Lkl *createList(Lkl *head, char listMainCat[50] , char c[30]) // linkList creation
{
    FILE * lptr;
    lptr = fopen("DisplayList.txt" , "a");

    if(lptr == NULL)
    {
        printf("Unable to open file Display");
        exit(0);
    }
    
    Lkl *newNode = NULL, *lastNode = NULL;
    int choice;
    char decor[50] = "--------------";
    char rat[50] = "Ratings : ";
    char type[50] = "Type : ";
    char genre[50] = "Genre : ";

    do
    {
        newNode = (Lkl *)malloc(sizeof(Lkl));

        printf("\n\tEnter the title of (movie , series...) : ");
        fgets(newNode->sub_category, sizeof(newNode->sub_category), stdin);
        newNode->sub_category[strcspn(newNode->sub_category, "\n")] = '\0';
        
        fprintf(lptr , "%s",decor);   //adding name of movie in the file
        fprintf(lptr , "%s", newNode->sub_category);
        fprintf(lptr , "%s",decor);   


        printf("\n\tEnter the ratings : ");
        scanf("%d", &newNode->ratings);
        getchar();
        
        fprintf(lptr, "\n%s", rat);   
        fprintf(lptr , "%d" , newNode->ratings);       //adding ratings to txt file
        
        strcpy(newNode->list_Maincategory , listMainCat);
        fprintf(lptr, "\n%s", type);
        fprintf(lptr , "%s", newNode->list_Maincategory);       //adding type to txt file

        strcpy(newNode->list_category, c);
        fprintf(lptr , "\n%s", genre );                         
        fprintf(lptr , "%s\n", newNode->list_category);         //adding genre to txt file 

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }

        else
        {
            lastNode->next = newNode;
        }
        lastNode = newNode;

        printf("\n\tDo you want to enter more types(Conjuring, ring ....)?? : if yes enter 1 else 0 : ");
        scanf("%d", &choice);
        getchar();

    } while (choice == 1);
    fclose(lptr);
    return head; // returning the pointer of Lkl to tree
}

//********************************************************************************Sub tree creation*************************************************************** */
Node *create(Node *root, char listMainCat[50]) // tree creation
{
    Node *new, *p;
    int ans;

    do
    {
        new = (Node *)malloc(sizeof(Node));

        printf("\n\tEnter the sub category of %s : ", root->category);
        fgets(new->category, sizeof(new->category), stdin);
        new->category[strcspn(new->category, "\n")] = '\0';

        int total = 0;

        for (int i = 0; new->category[i] != '\0'; i++)
        {
            total = total + new->category[i];
        }

        new->countAciiSubTree = total;

        new->right = new->left = NULL;
        new->list = NULL;

        new->list = createList(new->list, listMainCat, new->category); // sending the Linklist node to create list

        if (root == NULL)
            root = new;

        else
        {

            p = root;

            while (1)
            {

                if (new->countAciiSubTree < p->countAciiSubTree)
                {
                    if (p->left == NULL)
                    {
                        p->left = new;
                        break;
                    }

                    p = p->left;
                }

                else if (new->countAciiSubTree > p->countAciiSubTree)
                {
                    if (p->right == NULL)
                    {
                        p->right = new;
                        break;
                    }
                    p = p->right;
                }

                else if (new->countAciiSubTree == p->countAciiSubTree)
                {
                    printf("\n\tCATEGORY ALREADY EXITS!!");
                    break; // if yes break
                }
            }
        }
        printf("\n\tDo you want to enter more sub category (Thriller , Horror) : ");
        scanf("%d", &ans);
        getchar();
    } while (ans == 1);
    return root;
}

//********************************************************************************main tree creation*************************************************************** */
Maintree *createMainTree(Maintree *rootNode)
{

    FILE * mptr;
    mptr=fopen("MainCategory(Movies..).txt", "a");

    if(mptr == NULL)
    {
        printf("\nUnable to open file");
        exit(0);
    }

    Maintree *new, *p;
    int ans, flag = 0;

    do
    {
        new = (Maintree *)malloc(sizeof(Maintree));

        printf("\n\tEnter the main category : ");
        fgets(new->Maincategory, sizeof(new->Maincategory), stdin);
        new->Maincategory[strcspn(new->Maincategory, "\n")] = '\0';

        int total = 0;

        for (int i = 0; new->Maincategory[i] != '\0'; i++)
        {
            total = total + new->Maincategory[i];
        }
        new->countAciiMainTree = total;

        new->right = new->left = NULL;
        new->root = NULL;
        new->root = create(new->root, new->Maincategory); // calling  the sub tree creation function

        if (rootNode == NULL)
        {            
            rootNode = new;
            flag = 1;
        }

        else
        {
            p = rootNode;

            while (1)
            {

                if (new->countAciiMainTree < p->countAciiMainTree)
                {
                    if (p->left == NULL)
                    {
                        p->left = new;
                        flag = 1;
                        break;
                    }

                    p = p->left;
                }

                else if (new->countAciiMainTree > p->countAciiMainTree)
                {
                    if (p->right == NULL)
                    {
                        p->right = new;
                        flag = 1;
                        break;
                    }
                    p = p->right;
                }

                else if (new->countAciiMainTree == p->countAciiMainTree)
                {
                    printf("\n\tCATEGORY ALREADY EXITS!!");
                    break; // if yes break
                }
            }
        }
        
        if(flag == 1)
        {
            fprintf(mptr, "%s\n", new->Maincategory);
            flag = 0;
        }

        printf("\n\tDo you want to enter more main category (Movies , Series....): ");
        scanf("%d", &ans);
        getchar();
    } while (ans == 1);

    fclose(mptr);
    return rootNode;
}

//********************************************************************************search main treee*************************************************************** */

Maintree *search_category(char category_choice[50], Maintree *mainRoot)
{
    int count = 0;

    for (int i = 0; category_choice[i] != '\0'; i++)
    {
        count = category_choice[i] + count;
    }
    while (1)
    {

        if (mainRoot == NULL)
            return NULL;

        if (count == mainRoot->countAciiMainTree)
        {
            return mainRoot;
        }

        if (mainRoot->countAciiMainTree > count)
            mainRoot = mainRoot->left;

        else if (mainRoot->countAciiMainTree < count)
            mainRoot = mainRoot->right;
    }
}

//********************************************************************************search sub treee *************************************************************** */
Node *search_subCategory(char category_sub[50], Maintree *mainRoot)
{

    int count = 0;

    for (int i = 0; category_sub[i] != '\0'; i++)
    {
        count = category_sub[i] + count;
    }

    Node *head_root = mainRoot->root;

    while (1)
    {

        if (head_root == NULL)
            return NULL;

        if (head_root->countAciiSubTree == count)
        {
            return head_root;
        }

        if (count < head_root->countAciiSubTree)
            head_root = head_root->left;

        else if (count > head_root->countAciiSubTree)
            head_root = head_root->right;
    }
}

//******************************************************************************** Link list search*************************************************************** */

int search_list(char category_last[50], Node *key_sub)
{
    Lkl *head = NULL;
    head = key_sub->list;

    if (head == NULL)
    {
        printf("\n\tHead==NULL");
        return 1;
    }

    else
    {
        for (; head != NULL; head = head->next)
        {
            int flag = 0;
            for (int i = 0; category_last[i] != '\0'; i++)
            {
                if (category_last[i] != head->sub_category[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                return 2;
        }
    }

    for (; head != NULL; head = head->next)
    {
        printf("%s\n", head->sub_category);
    }
    return 1;
}


void displayList()
{
    char buffer[100];
    FILE *lptr;
    lptr = fopen("DisplayList.txt", "r");
    if(lptr == NULL)
    {
        printf("Unable to display The Display List File");
        exit(0);
    }
    while(fgets(buffer, sizeof(buffer), lptr) != NULL)
    {
        printf("\n%s", buffer);
    }
    fclose(lptr);
}
//*********************************************************************************ADMIN AUTHENTICATION******************************************************** */

int adminPass(char pass[50])
{
    char passFile[50];
    FILE *fptr ;
    fptr = fopen("password.txt" , "r");
    if(fptr == NULL)
    {
        printf("Error opening thr file");
        exit(1);
    }

    fscanf(fptr , "%s", &passFile);
    for(int i = 0 ; passFile[i]!='\0' ; i++)
    {
        if(passFile[i]!= pass[i])
        return 1;
    }

    fclose(fptr);

    return 2;

}



//********************************************************************************main function*************************************************************** */

int main()
{
    printf("\n------------------------ADMIN-------------------------\n");
    
    char pass[50] ;

    printf("\nEnter the password of admin :");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';
    int passAuthen = 0 ;

    passAuthen = adminPass(pass);

    if(passAuthen == 2)
    {
        printf("\nENTERING AS ADMIN!");
    }
    else
    {
        printf("\nWrong password!");
        exit(0);
    }
    char ott[50];
    printf("\n\tEnter the name of the ott : ");
    fgets(ott, sizeof(ott), stdin);
    ott[strcspn(ott, "\n")] = '\0';

    Maintree *mainRoot = NULL;
    mainRoot = createMainTree(mainRoot);
    displayList();
    int choice_of_consumer;

    do
    {
        printf("\n\t-------------------------------%s------------------------------------", ott);
        printf("\n\t1.Display the categories");
        printf("\n\t2.Search a movie/series....");
        printf("\n\t3.EXIT");

        printf("\n\n\tEnter your choice : ");
        scanf("%d", &choice_of_consumer);
        getchar();

        switch (choice_of_consumer)
        {
        case 1:
        {
            //Inorder_printing(mainRoot);
            break;
        }
        

        case 2:
        {
            char category_choice[50];
            printf("\n\tEnter a category you want to browse : ");
            fgets(category_choice, sizeof(category_choice), stdin);
            category_choice[strcspn(category_choice, "\n")] = '\0';

            Maintree *key = NULL;
            key = search_category(category_choice, mainRoot);

            if (key == NULL)
            {

                printf("\n\tNo such category exists !!!");
                break;
            }

            else
            {
                char category_sub[50];
                printf("\n\tEnter sub  category you want to browse : ");
                fgets(category_sub, sizeof(category_sub), stdin);
                category_sub[strcspn(category_sub, "\n")] = '\0';

                Node *key_sub = NULL;
                key_sub = search_subCategory(category_sub, key);

                if (key_sub == NULL)
                {
                    printf("\n\tNo such sub_category exists !!!");
                    break;
                }
                else
                {
                    char category_last[50];
                    printf("\n\tEnter main category you want to Watch: ");
                    fgets(category_last, sizeof(category_last), stdin);
                    category_last[strcspn(category_last, "\n")] = '\0';

                    int ans = search_list(category_last, key_sub);

                    if (ans == 2)
                    {
                        printf("\n                 *************************************************************************");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                         Now playing %s                                *", category_last);
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *                                                                       *");
                        printf("\n                 *************************************************************************");

                        printf("\n\n\t THE END!!");
                    }

                    else
                        printf("\n\t No such Movie/Series exist!!");
                   
                }
            }
            break;
        }
        case 3:
        {
            printf("\nEXITINGGGGGGGGGGGGGGG");
            exit(0);
        }

        default:
        {
            printf("\n Invlaid input try again!");
        }
        }
    } while (choice_of_consumer == 3);

    return 0;
}