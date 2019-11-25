# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/operations.h"



void
printMenu( DB_BST_NODE *profile )
{
    // system("clear");

    printf( "+----------+------------------------------------------------------+-----------------------+\n" );
    printf( "|    ID    |                         Name                         |    Qtd. of friends    |\n" );
    printf( "+----------+------------------------------------------------------+-----------------------+\n" );

    if (profile == NULL)
    {
        printf( "|  (void)  |                        (void)                        |        (void)         |\n" );
    }
    else
    {
        DB_printInOrder( profile );
    }
    
    printf( "+----------+------------------------------------------------------+-----------------------+\n" );
}