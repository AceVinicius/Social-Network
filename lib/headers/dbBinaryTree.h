/**
 * @file dbBinaryTree.h
 * @author Vinícius Ferreira Aguiar
 * @date 20.10.2019
 * @brief Contains the operations of the profile database tree
 *
 * The binary search tree (a.k.a. BST) is a data structure used to store
 * data and find elements faster than arrays, where the search is made
 * element by element. In a BST, the left subtree always have smaller
 * values (the field used to organize the tree, in our case the id) than
 * the root and the right subtree always have greater values which gives
 * us a O(log n) search in average, where 'n' is the number of nodes in
 * tree. With this in mind, all the operations used to manipulate this
 * data structure are in this file.
 * 
 * Functions in this file:
 *   @see DB_createNewNode()
 *   @see DB_insert()
 *   @see DB_delete()
 *   @see DB_findMinimum()
 *   @see DB_search()
 *   @see DB_free()
 *   @see DB_printInOrder()
 *   @see DB_printNode()
 * 
 * @see https://github.com/AceVinicius
 * 
 */
#ifndef DBBINARYTREE_H_
# define DBBINARYTREE_H_

# include "define.h"



/**
 * @brief Allocates a new node for database tree to heap memory.
 *
 * Allocate new_db_node dynamically in heap and initialize it's parameters.
 * 
 * @code
 * return DB_createNewNode( 123 );
 * @endcode
 * 
 * @param id Is the id that will be inserted on the new node.
 * 
 * @return Returns the address of the position where the node was allocated
 *         in heap. Returns NULL if there is no space in heap.
 * 
 * @see DB_insert()
 * 
 * @warning This function is only called inside DB_insert. There is no need
 *          to use it outside of it.
 */
extern DB_BST_NODE * DB_createNewNode( const int id );



/**
 * @brief Insert an element in the BST.
 *
 * In a BST we always insert the element in the root (if the tree is empty) or
 * in a leaf (if have at least one node). So, we start checking if current node
 * is a a leaf (in both cases, it will be equals to NULL, being a leaf or an 
 * empty tree), if it is, we return calling for DB_createNewNode. If it isn't 
 * we compares the current @p id with the id of the current node (tree->id).
 * 
 * If it's greater we call:
 * @code
 * tree->right = DB_insert( tree->right, 123 );
 * @endcode
 * 
 * If it's smaller we call:
 * @code
 * tree->left = DB_insert( tree->left, 123 ).
 * @endcode
 * 
 * @code
 * root = DB_insert( root, 123 );
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree where the new element will 
 *             be inserted.
 * @param id   Is the key that will be used to place the node inside the BST.
 * 
 * @return Returns the address of the position where the new_db_node was inserted.
 * 
 * @see DB_allocateNewNode()
 * 
 * @note This is a recursive function. It calls itself for find the correct
 *       place to insert the node.
 */
extern DB_BST_NODE * DB_insert( DB_BST_NODE *tree, const int id );



/**
 * @brief Removes an element in the BST.
 *
 * In a BST we can't just remove the element in the tree. First, we check if the tree is
 * empty. If it's not, then we look for the node to be deleted. When we find we have
 * three things to check, if it's a leaf, if it have one child or two children. In the 
 * first case, we can just free the node. In the second case assign the pointer from
 * the root to the child. In the third case, it's a bit more complicated. We have to
 * find the smallest node in the right subtree, assign it to the node we want to delete,
 * and call DB_delete to the node we found with the smallest value. Doing this, we 
 * simplify our complexity of case three to a case one or two.
 * 
 * @code
 * DB_delete( root, 123 );
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree where the element will be
 *             removed.
 * @param id   Is the key that will be used to find the node inside the BST to be
 *             removed.
 * 
 * @return Returns the address of the position where the node was removed. Returns
 *         NULL if the node was not found.
 * 
 * @see DB_findMinimum()
 * 
 * @note This is a recursive function. It calls itself to simplify the problem
 *       if the desired node has two children.
 */
extern DB_BST_NODE * DB_delete( DB_BST_NODE *tree, const int id );



/**
 * @brief Finds the smallest value of a BST.
 * 
 * @code
 * tmp = DB_findMinimum( root, 123 );
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree where we will look for the
 *             smallest node.
 * @param id   Is the key that will be used to find the node with the smallest
 *             value of the BST.
 * 
 * @return Returns the address of the position where the node has the smallest
 *         @p id . Returns NULL if current node is the smallest or no valid tree 
 *         was inserted in @p tree .
 * 
 * @see DB_delete()
 * 
 * @note This is a recursive function. It calls itself to find if there is a
 *       left subtree or not.
 * @note Can be used to find the smallest value in a subtree inside the tree,
 *       as you can see in DB_delete().
 */
extern DB_BST_NODE * DB_findMinimum( DB_BST_NODE *tree );



/**
 * @brief Looks for a specific value of a BST.
 * 
 * @code
 * if( DB_search( root, 123 ) != NULL )
 * {
 *     // Found the element.
 * }
 * else
 * {
 *     // Didn't find an element with id 123.
 * }
 * @endcode
 * @code
 * element = DB_search( root, 123 );
 * if( element == NULL )
 * {
 *     // Didn't find an element with id 123.
 * }
 * else
 * {
 *     // Found the element.
 * }
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree where we will search the 
 *             element.
 * @param id   Is the key that will be used to find the node of the BST.
 * 
 * @return Returns the address of the position where the node with @p id was found.
 *         Returns NULL if there is no element with @p id or no valid tree was
 *         inserted in @p tree .
 * 
 * @note This is a recursive function. It calls itself to check if the left or
 *       right subtree will be called.
 */
extern DB_BST_NODE * DB_search( DB_BST_NODE *tree, const int id );



/**
 * @brief Free entire profile and friend's list tree.
 *
 * @code
 * DB_free( tree );
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree.
 * 
 * @return void.
 * 
 * @see FL_free()
 * 
 * @warning This function is only called in the end of the file, to close it.
 */
extern void DB_free( DB_BST_NODE *tree );



/**
 * @brief Prints the profiles in ascendant id order.
 * 
 * @code
 * DB_printInOrder( tree );
 * @endcode
 * 
 * @param tree Is a pointer to the root of the tree where we will print.
 * 
 * @return Returns void.
 * 
 * @see DB_printNode()
 * 
 * @note This is a recursive function.
 */
extern void DB_printInOrder( const DB_BST_NODE *tree );



/**
 * @brief Prints the node content.
 * 
 * @code
 * DB_printNode( tree );
 * @endcode
 * 
 * @param tree Is a pointer to the node that will be printed.
 * 
 * @return Returns void.
 * 
 * @see DB_printInOrder()
 * 
 * @warning No need to call this function outside DB_printInOrder().
 */
extern void DB_printNode( const DB_BST_NODE *tree );



#endif    // DBBINARYTREE_H_