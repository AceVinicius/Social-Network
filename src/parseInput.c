# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/dbBinaryTree.h"
# include "../lib/headers/flBinaryTree.h"
# include "../lib/headers/operations.h"
# include "../lib/headers/parseInput.h"



void
printLog(char *string, int a, int b)
{
    FILE *logFile = fopen("../lib/log/socialMediaLog.txt", "a");

    fprintf( logFile, "%s", string );

    if( a != NO_PARAMETER ) fprintf(logFile, " %d", a);
    if( b != NO_PARAMETER ) fprintf(logFile, " %d", b);

    fprintf(logFile, "\n");

    fclose( logFile );
}



bool
parseInput(DB_BST_NODE **tree, char *buffer)
{
    int id_1;
    int id_2;

    if (strcmp(buffer, "createprofile") == 0)
    {
#ifdef LOG
        printLog("createprofile", NO_PARAMETER, NO_PARAMETER);
#endif

        createProfile( tree );
    }
    else if (strcmp(buffer, "removeprofile") == 0)
    {
        scanf(" %d", &id_1);
        removeProfile( *tree, id_1 );   

#ifdef LOG
        printLog("removeprofile", id_1, NO_PARAMETER);
#endif

    }
    else if (strcmp(buffer, "showprofile") == 0)
    {
        scanf(" %d", &id_1);
        showProfile(*tree, id_1);
    }
    else if (strcmp(buffer, "addfriend") == 0)
    {
        scanf(" %d", &id_1);
        scanf(" %d", &id_2);            
        addFriend(*tree, id_1, id_2);

#ifdef LOG
        printLog("addfriend", id_1, id_2);
#endif

    }
    else if (strcmp(buffer, "removefriend") == 0)
    {
        scanf(" %d", &id_1);
        scanf(" %d", &id_2);            
        removeFriend(*tree, id_1, id_2); 

#ifdef LOG
        printLog("removefriend", id_1, id_2);
#endif

    }
    else if (strcmp(buffer, "isfriend") == 0)
    {
        scanf(" %d", &id_1);
        scanf(" %d", &id_2);
        isFriend(*tree, id_1, id_2);
    }
    else if (strcmp(buffer, "exit") == 0)
    {
        return false;
    }

    return true;
}