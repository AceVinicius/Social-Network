/**
 * @file operations.h
 * @author Vinícius Ferreira Aguiar
 * @date 20.10.2019
 * @brief This file contains the guiding functions from social network
 *
 * The operations file is related to minimize common mistakes that can
 * result in memory leak or inconsistent database. It helps mantain clear
 * in the main.c file what can be done with the social media.
 * 
 * Functions in this file:
 *   @see createProfile()
 *   @see removeProfile()
 *   @see showProfile()
 *   @see addFriend()
 *   @see removeFriend()
 *   @see isFriend()
 *   @see findFriendPath()
 * 
 * @see https://github.com/AceVinicius
 * 
 */
#ifndef OPERATIONS_H_
# define OPERATIONS_H_

# include "define.h"



/**
 * @brief Simply creates a new profile.
 * 
 * @code
 * createProfile( &tree );
 * @endcode
 * 
 * @param profile_tree Is a pointer to pointer to the tree.
 * 
 * @return Returns void.
 * 
 * @see DB_insert() 
 */
extern void createProfile(DB_BST_NODE **profile_tree);



/**
 * @brief Simply removes a profile.
 * 
 * @code
 * removeProfile( &tree );
 * @endcode
 * 
 * @param profile_tree Is a pointer to the tree.
 * 
 * @return Returns void.
 * 
 * @see DB_insert() 
 */
extern void removeProfile(DB_BST_NODE *profile_tree, const int id);



/**
 * @brief Prints the profile info and friends.
 * 
 * @code
 * showProfile( tree, 123 );
 * @endcode
 * 
 * @param profile_tree Is a pointer to the root of the tree.
 * @param id           Identifier of the node that will be printed,
 *                     if exists.
 * 
 * @return Returns void.
 * 
 * @see DB_printInOrder()
 * @see DB_printNode()
 * 
 */
extern void showProfile(DB_BST_NODE *profile_tree, const int id);



/**
 * @brief Adds @p id_1 to friend's tree of @p id_2 and vice-versa.
 * 
 * @code
 * addFriend( tree, 123, 321 );
 * @endcode
 * 
 * @param profile_tree Is a pointer to the root of the tree.
 * @param id_1         Id of the first user.
 * @param id_2         Id of the second user.
 *
 * @return Returns void.
 * 
 * @see DB_search()
 * @see FL_insert()
 * 
 */
extern void addFriend(DB_BST_NODE *profile_tree, const int id_1, const int id_2);



/**
 * @brief Removes @p id_1 to friend's tree of @p id_2 and vice-versa.
 * 
 * @code
 * removeFriend( tree, 123, 321 );
 * @endcode
 * 
 * @param profile_tree Is a pointer to the root of the tree.
 * @param id_1         Id of the first user.
 * @param id_2         Id of the second user.
 *
 * @return Returns void.
 * 
 * @see DB_search()
 * @see FL_delete()
 * 
 */
extern void removeFriend(DB_BST_NODE *profile_tree, const int id_1, const int id_2);



/**
 * @brief Verifies if @p id_1 is friend of @p id_2 .
 * 
 * @code
 * removeFriend( tree, 123, 321 );
 * @endcode
 * 
 * @param profile_tree Is a pointer to the root of the tree.
 * @param id_1         Id of the first user.
 * @param id_2         Id of the second user.
 *
 * @return Returns void.
 * 
 * @see DB_search()
 * @see FL_search()
 * 
 */
extern bool isFriend(DB_BST_NODE *profile_tree, const int id_1, const int id_2);



#endif    // OPERATIONS_H_