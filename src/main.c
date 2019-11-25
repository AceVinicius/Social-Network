/********************************************************************************
 ********************************************************************************
 *****                                                                      *****
 *****                      Engenharia de Computação                        *****
 *****                                                                      *****
 *****                            Social Network                            *****
 *****                            Version 1.0.0                             *****
 *****                                                                      *****
 *****                           Vinícius Aguiar                            *****
 *****                                                                      *****
 *****                       20.10.2019 - 24.11.2019                        *****
 *****                                                                      *****
 ********************************************************************************
 ********************************************************************************/
# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/operations.h"
# include "../lib/headers/parseInput.h"
# include "../lib/headers/CUI.h"



int
main( void )
{
    DB_BST_NODE *db_tree = NULL;
    char buffer[ BUFFER_LIMIT ];
    bool status = true;

    while(status)
    {
        printMenu( db_tree );
        
        printf(">> ");
        scanf(" %s%*c", buffer );
    
        status = parseInput( &db_tree, buffer );
    }

    DB_free( db_tree );

    return 0;
}