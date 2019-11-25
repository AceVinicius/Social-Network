/**
 * @file define.h
 * @author Vinícius Ferreira Aguiar
 * @date 20.10.2019
 * @brief This file contains the structs and constants from this project
 * 
 * @see https://github.com/AceVinicius
 * 
 */
#ifndef DEFINE_H_
# define DEFINE_H_

# define LOG
# define NO_PARAMETER     -1
# define BUFFER_LIMIT    128



/**
 * @brief Friend's List BST Node
 *
 * This struct is used to store the
 * id's of only the friends of each
 * user (the user itself is not in
 * this tree).
 */
typedef struct fl_bst_node
{
    int id;  /**< Store the id of a friend (same id of the other tree). */
    
    struct fl_bst_node * left;   /**< Store the address of the left subtree. */
    struct fl_bst_node * right;  /**< Store the address of the right subtree. */
}
FL_BST_NODE;



/**
 * @brief Database BST Node
 *
 * This struct is used to store the
 * profile information of each user.
 */
typedef struct db_bst_node
{
    int  id;           /**< Store the id of that user. The id is unique and is used to organize the tree. */
    int  qtd_friends;  /**< Store the number of friends of the profile. */
    char name[ 50 ];   /**< Store the name of the profile. */

    
    struct fl_bst_node * fl_root;  /**< Store the address of the root of friend's list tree. */
    
    struct db_bst_node * left;   /**< Store the address of the left subtree. */
    struct db_bst_node * right;  /**< Store the address of the right subtree. */
}
DB_BST_NODE;



#endif    // DEFINE_H_
