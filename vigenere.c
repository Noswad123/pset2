#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key;
    string plainText;
    int keyCounter=0;
    int keyChar;

    if(argc!=2)
    {
        return 1;//or exit(1);
    }

    key=argv[1];
    for(int i=0;i<strlen(key);i++){

        if(!isalpha(key[i])){
            return 1;
        }
    }
     plainText=get_string("plain text: ");
    char cipherArray[strlen(plainText)];

    //printf("cipher text: ");
    for(int i=0, length= strlen(plainText); i<length;i++)
    {

        //check for alpha characters
        if(!isalpha(plainText[i])){
           cipherArray[i]=plainText[i];
        //check case
        }else if(isupper(plainText[i])){
            //convert ascii to alpha index
            keyChar=key[keyCounter]-'a';
            cipherArray[i]=plainText[i]+keyChar;

            keyCounter++;
            if(keyCounter==strlen(key)){
                keyCounter=0;
            }

        }else{
            keyChar=key[keyCounter]-'a';
            //convert ascii to alpha index
            cipherArray[i]=plainText[i]+keyChar;

            keyCounter++;
            if(keyCounter==strlen(key)){

                keyCounter=0;

            }
        }
       printf("%c",cipherArray[i]);


        }

    printf("\n");

}