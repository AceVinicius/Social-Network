# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/operations.h"



int
getNewId( void )
{
    static int k = 0;

    return ++k;
}


void
pressEnter()
{\
    char enter;
    
    printf("\n[Press 'enter' to continue]\n\n");
    do
    {
        scanf("%*c%c", &enter);
    }
    while (enter != '\n');
}


void
createProfile( DB_BST_NODE **profile_tree )
{
    *profile_tree = DB_insert( *profile_tree, getNewId() );
}



void
removeProfile( DB_BST_NODE *profile_tree, const int id )
{
    DB_BST_NODE *profile = DB_search( profile_tree, id );

    if (profile == NULL)
    {
        printf( "  error: removeProfile: Profile '%d' does not exist\n\n", id );
        pressEnter();
        return;
    }

    FL_free( profile_tree, profile->fl_root, id );

    profile = DB_delete( profile, id );
}



void
showProfile( DB_BST_NODE *profile_tree, const int id )
{
    DB_BST_NODE *profile = DB_search( profile_tree, id );
    
    system("clear");
    
    printf( "\n+-------------------------------------------------------+\n" );
    printf( "|                    Friends of %04d                    |\n", profile->id );
    printf( "+-------------------------------------------------------+\n" );
    
    if (profile->fl_root == NULL)
    {
        printf( "|             You don't have any friends :(             |\n" );
    }
    else
    {
        FL_printInOrder( profile->fl_root );
    }
    
    printf( "+-------------------------------------------------------+\n\n" );

    pressEnter();
}



void
addFriend( DB_BST_NODE *profile_tree, const int id_1, const int id_2 )
{
    DB_BST_NODE *profile_1 = DB_search( profile_tree, id_1 );
    DB_BST_NODE *profile_2 = DB_search( profile_tree, id_2 );

    if (profile_1 == NULL)
    {
        printf( "  error: addFriend: Profile '%d' does not exist\n\n", id_1 );
        pressEnter();
        return;
    }
    
    if (profile_2 == NULL)
    {
        printf( "  error: addFriend: Profile '%d' does not exist\n\n", id_2 );
        pressEnter();
        return;
    }

    if (!isFriend( profile_tree, id_1, id_2 ))
    {
        profile_1->fl_root = FL_insert( profile_1->fl_root, id_2 );
        profile_2->fl_root = FL_insert( profile_2->fl_root, id_1 );

        profile_1->qtd_friends++;
        profile_2->qtd_friends++;
    }
}



void
removeFriend( DB_BST_NODE *profile_tree, const int id_1, const int id_2 )
{
    DB_BST_NODE *profile_1 = DB_search( profile_tree, id_1 );
    DB_BST_NODE *profile_2 = DB_search( profile_tree, id_2 );

    if (profile_1 == NULL)
    {
        printf( "  error: removeFriend: Profile '%d' does not exist\n\n", id_1 );
        pressEnter();
        return;
    }

    if (profile_2 == NULL)
    {
        printf( "  error: removeFriend: Profile '%d' does not exist\n\n", id_2 );
        pressEnter();
        return;
    }

    if (isFriend( profile_tree, id_1, id_2 ))
    {
        profile_1->fl_root = FL_delete( profile_1->fl_root, id_2 );
        profile_2->fl_root = FL_delete( profile_2->fl_root, id_1 );

        profile_1->qtd_friends--;
        profile_2->qtd_friends--;
    }
}



bool
isFriend( DB_BST_NODE *profile_tree, const int id_1, const int id_2 )
{
    DB_BST_NODE *profile_1 = DB_search( profile_tree, id_1 );
    DB_BST_NODE *profile_2 = DB_search( profile_tree, id_2 );

    if (profile_1 == NULL)
    {
        printf( "  error: isFriend: Profile '%d' does not exist\n\n", id_1 );
        return false;
    }

    if (profile_2 == NULL)
    {
        printf( "  error: isFriend: Profile '%d' does not exist\n\n", id_2 );
        return false;
    }
    
    system("clear");

    if (FL_search( profile_1->fl_root, id_2 ) == NULL)
    {
        printf("\nYou are not friend. :(\n");

        pressEnter();

        return false;
    }

    printf("\nYou are friend. :)\n");
    
    pressEnter();

    return true;
}