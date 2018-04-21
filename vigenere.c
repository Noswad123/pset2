/**
 * Same concerns here...
 * You did pretty good job. The code looks clean. The only thing missing
 * is a brief description what the program does.
*/

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
    for(int i=0;i<strlen(key);i++)
    {
        if(!isalpha(key[i]))
        {
            return 1;
        }
    }
     plainText=get_string("plain text: ");

    printf("ciphertext: ");
    for(int i=0, length= strlen(plainText); i<length;i++)
    {
        if(!isalpha(plainText[i]))          //check for non alphabetical characters
        {
            printf("%c", plainText[i]);
        }
        else
        {
            if(isupper(key[keyCounter]))
            {
                keyChar = key[keyCounter] -'A';
            }else{
                keyChar=key[keyCounter]-'a';
            }

            if(isupper(plainText[i]))         //check case
            {
                if(plainText[i] + keyChar >'Z')
                {
                    keyChar = (((plainText[i] + keyChar) % 'Z') % 26);        //Wrap ciphertext
                    //debug comment printf("uppercase char: %c keyChar:%i cipherText: %c\n",plainText[i], newkey, ('A' + newkey - 1));
                    printf("%c", 'A' + keyChar - 1);
                }
                else
                {
                    //debug comment printf("upper case char: %c plaintext + keyChar:%i newkey: %i\n",plainText[i], plainText[i]+key, 'A' + key);
                     printf("%c", plainText[i] + keyChar);
                }
            }
            else
            {
                if((plainText[i] + keyChar) >'z')
                {
                    keyChar = (((plainText[i] + keyChar) % 'z') % 26);      //Wrap ciphertext
                    //debugger comment printf("lowercase char: %c newkey:%i cipherText: %c\n",plainText[i], newkey, ('a' + newkey - 1));
                     printf("%c", 'a' + keyChar - 1);
                }else{
                   //debugger coment printf("lowercase char: %c plaintext + key:%i cipherText: %c\n",plainText[i], plainText[i]+key, plainText[i] + key );
                    printf("%c", plainText[i] + keyChar);
                }
            }

            keyCounter++;
            if(keyCounter==strlen(key))
            {
                keyCounter=0;
            }
        }

    }
    printf("\n");
}