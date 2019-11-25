# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/operations.h"
# include "../lib/headers/parseInput.h"




DB_BST_NODE *
DB_createNewNode( const int id )
{
    DB_BST_NODE *new_db_node = (DB_BST_NODE *) malloc( sizeof(DB_BST_NODE) );

    if (new_db_node == NULL)
    {
        puts( "  error: Could not allocate new 'DB_BST_NODE'" );
        return NULL;
    }

    new_db_node->id          = id;
    new_db_node->left        = NULL;
    new_db_node->right       = NULL;
    new_db_node->fl_root     = NULL;
    new_db_node->qtd_friends = 0;

    // printf( "What's your name?  " );
    scanf( " %[^\n]%*c", new_db_node->name );

#ifdef LOG
        printLog( new_db_node->name, NO_PARAMETER, NO_PARAMETER );
#endif

    return new_db_node;
}



DB_BST_NODE *
DB_insert( DB_BST_NODE *tree, const int id )
{
    if (tree == NULL) return DB_createNewNode( id );

    if (id < tree->id) tree->left  = DB_insert( tree->left, id );
    else               tree->right = DB_insert( tree->right, id );

    return tree;
}



DB_BST_NODE *
DB_delete( DB_BST_NODE *tree, const int id )
{
    if (tree == NULL) return NULL;

    if (id < tree->id)
    {
        tree->left = DB_delete( tree->left, id );
    }
    else if (id > tree->id)
    {
        tree->right = DB_delete( tree->right, id );
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free( tree );
            tree = NULL;
        }

        // Has one child
        else if (tree->left == NULL)
        {
            DB_BST_NODE *tmp = tree;
            tree = tree->right;
            free( tmp );
        }
        else if (tree->right == NULL)
        {
            DB_BST_NODE *tmp = tree;
            tree = tree->left;
            free( tmp );
        }

        // Has two children
        else
        {
            DB_BST_NODE *tmp = DB_findMinimum( tree->right );

            strcpy( tree->name, tmp->name );
            tree->id      = tmp->id;
            tree->fl_root = tmp->fl_root;
            
            tree->right = DB_delete( tree->right, tmp->id );
        }
    }

    return tree;
}



DB_BST_NODE *
DB_findMinimum(DB_BST_NODE *tree)
{
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    
    return tree;
}



DB_BST_NODE *
DB_search( DB_BST_NODE *tree, const int id )
{
    if (tree == NULL || tree->id == id) return tree;

    if (id < tree->id) return DB_search( tree->left, id );
    else               return DB_search( tree->right, id );
}



void
DB_free( DB_BST_NODE *tree )
{
    if (tree == NULL) return;

    DB_free( tree->left );
    DB_free( tree->right );

    removeProfile( tree, tree->id );
}



void
DB_printInOrder( const DB_BST_NODE *tree )
{
    if (tree == NULL) return;
    
    DB_printInOrder( tree->left );
    DB_printNode( tree );
    DB_printInOrder( tree->right );
}



void
DB_printNode( const DB_BST_NODE *tree )
{
    printf( "|   %04d   |  %-50s  |         %4d          |\n", tree->id, tree->name, tree->qtd_friends );
}