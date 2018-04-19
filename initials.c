#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string myName;
    myName = get_string( "What is your full name?: ");

   for ( int i = 0, length = strlen(myName); i <= (length - 1); i++)
   {
       if ( i == 0 )
       {
          printf( "%c", toupper(myName[i]));
       }else if ( isspace(myName[i - 1]))
       {
            printf("%c",toupper(myName[i]));
        }
   }
    printf("\n");
}
