/**
 * @file parseInput.h
 * @author Vinícius Ferreira Aguiar
 * @date 20.10.2019
 * @brief Interpretate user input and run
 * 
 * Functions in this file:
 *   @see parseInput()
 * 
 * @see https://github.com/AceVinicius
 * 
 */
#ifndef PARSEINPUT_H_
# define PARSEINPUT_H_

# include "define.h"



/**
 * @brief Print lof file in /lib/log folder.
 * 
 * @code
 * printLog( "something", nuymber_1, number_2 );
 * @endcode
 * 
 * @param string Is a string to be printed.
 * @param a      A number to beprinter alongside @p string.
 * @param b      A number to beprinter alongside @p a.
 *
 * @return Returns void.
 * 
 */
void printLog(char *string, int a, int b);



/**
 * @brief Interprete the user input and execute the right action.
 * 
 * @code
 * parseInput( tree_adr, buffer_ptr );
 * @endcode
 * 
 * @param tree   Is a pointer to pointer to the root of the tree.
 * @param buffer A pointer to string where the input was stored.
 *
 * @return Returns a boolean value, which determines if the exit
 *         input was inserted.
 * 
 * @see operations.h
 * 
 */
bool parseInput(DB_BST_NODE **tree, char *buffer);


#endif    // PARSEINPUT_H_