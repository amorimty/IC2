#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS (256)
#define MAX_COLUMNS (256)
#define FILE_NAME "myInputFile"

// prototypes
void bubbleSortWordsArray( int wordCount );
void printWordsArray( int wordCount );

static char words[MAX_ROWS][MAX_COLUMNS] = {{'\0','\0'}};

int main(void)
{
    FILE *fp = NULL;

    if( NULL == (fp = fopen( FILE_NAME, "r") ) )
    {
        perror( "fopen failed" );
        exit( EXIT_FAILURE );
    }

    // implied else, fopen successful

    // read each line from file into entry in words array
    int i = 0;
    while( fgets(words[i], MAX_COLUMNS, fp ) )
    {
        // remove trailing newline from string
        words[i][strlen(words[i])-1] = '\0';
        i++;
    }

     // 'i' contains number of valid entries in words[][]
    // sort the array of strings
    bubbleSortWordsArray(i);

    printWordsArray(i);

    return(0);
} // end function: main


void bubbleSortWordsArray( int wordCount )
{
    int c;  // outer index through rows
    int d;  // inner index through rows
    char swap[MAX_COLUMNS] = {'\0'};

    for (c = 0 ; c < ( wordCount - 1 ); c++)
    {
        for (d = 0 ; d <  (wordCount - c - 1); d++)
        {
            if(  0 > strcmp( words[d], words[d+1] ) )
            { // then words need to be swapped
                strcpy( swap, words[d]  );
                strcpy( words[d], words[d+1]);
                strcpy( words[d+1], swap );
            } // end if compare/swap
        } // end for
    } // end for each row
} // end function: bubbleSortWordsArray


void printWordsArray( int wordCount )
{
    int i; // loop index

    printf( "\n" ); // start on new output line
    for( i=0; i<wordCount; i++ )
    {
        printf( "%s\n", words[i] );
    }
} // end function: printWordsArray