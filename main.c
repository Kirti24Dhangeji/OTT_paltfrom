#include "functions.h"

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