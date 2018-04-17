#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
 int key;
    string plainText;

    if(argc!=2)
    {
        return 1;//or exit(1);
    }

    key=atoi(argv[1]);

     plainText=get_string("plain text: ");
    char cipherArray[strlen(plainText)];

    printf("cipher text: ");
    for(int i=0, length= strlen(plainText); i<length;i++)
    {
        //check for alpha characters
        if(!isalpha(plainText[i])){
           cipherArray[i]=plainText[i];
        //check case
        }else if(isupper(plainText[i])){
            //convert ascii to alpha index

            cipherArray[i]=plainText[i]+key;

        }else{
            //convert ascii to alpha index
            cipherArray[i]=plainText[i]+key;

        }
        printf("%c",cipherArray[i]);
    }
    printf("\n");

}