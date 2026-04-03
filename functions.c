#include "functions.h"

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

