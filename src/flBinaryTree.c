# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/operations.h"


FL_BST_NODE *
FL_createNewNode( const int id )
{
    FL_BST_NODE *new_fl_node = (FL_BST_NODE*) malloc( sizeof(FL_BST_NODE) );
    
    if (new_fl_node == NULL)
    {
        printf(" error: Could not allocate new 'FL_BST_NODE'\n");
        return NULL;
    }

    new_fl_node->left  = NULL;
    new_fl_node->right = NULL;
    new_fl_node->id    = id;

    return new_fl_node;
}



FL_BST_NODE *
FL_insert( FL_BST_NODE *tree, const int id )
{
    if (tree == NULL) return FL_createNewNode( id );

    if (id < tree->id) tree->left  = FL_insert( tree->left, id );
    else               tree->right = FL_insert( tree->right, id );

    return tree;
}



FL_BST_NODE *
FL_delete( FL_BST_NODE *tree, const int id )
{
    if (tree == NULL) return NULL;
    
    if (id < tree->id)
    {
        tree->left = FL_delete( tree->left, id );
    }
    else if (id > tree->id)
    {
        tree->right = FL_delete( tree->right, id );
    }
    else
    {
        // Has no child
        if (tree->left  == NULL)
        {
            FL_BST_NODE *tmp = tree->right;
            free( tree );
            return tmp;
        }

        // Has one child
        else if (tree->right  == NULL)
        {
            FL_BST_NODE *tmp = tree->left;
            free( tree );
            return tmp;
        }

        // Has two children
        else
        {
            FL_BST_NODE *tmp = FL_findMinimum( tree->right );
            
            tree->id = tmp->id;
            
            tree->right = FL_delete( tree->right, tmp->id );
        }
    }

    return tree;
}



FL_BST_NODE *
FL_findMinimum( FL_BST_NODE *tree )
{    
    while (tree->left != NULL)
    {
        tree = tree->left;
    }

    return tree;
}



FL_BST_NODE *
FL_search( FL_BST_NODE *tree, const int id )
{
    if (tree == NULL || tree->id == id) return tree;

    if (id < tree->id) return FL_search(tree->left, id);
    else               return FL_search(tree->right, id);
}



void
FL_free( DB_BST_NODE *DB_tree, FL_BST_NODE *FL_tree, const int id )
{
    if (FL_tree == NULL) return;

    FL_free( DB_tree, FL_tree->left, id );
    FL_free( DB_tree, FL_tree->right, id );

    removeFriend( DB_tree, id, FL_tree->id );
}



void
FL_printInOrder(const FL_BST_NODE *tree)
{
    if (tree == NULL) return;

    FL_printInOrder(tree->left);
    FL_printNode(tree);
    FL_printInOrder(tree->right);
}



void
FL_printNode(const FL_BST_NODE *tree)
{
    printf("||   id: %04d                                            ||\n", tree->id);
}