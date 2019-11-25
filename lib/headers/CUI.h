/**
 * @file CUI.h
 * @author Vinícius Ferreira Aguiar
 * @date 20.10.2019
 * @brief This file contains the CUI interface
 * 
 * Functions in this file:
 *   @see printMenu()
 * 
 * @see https://github.com/AceVinicius
 *
 */
#ifndef CUI_H_
# define CUI_H_



/**
 * @brief Prints the menu before prompt line.
 * 
 * @code
 * printMenu( tree );
 * @endcode
 * 
 * @param tree Is a pointer to the tree that will be printed.
 * 
 * @return Returns void.
 * 
 */
void printMenu( DB_BST_NODE *profile );



#endif  // CUI_H_