#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key;
    int newkey=0;
    string plainText;

    if (argc != 2)
    {
        return 1;       //or exit(1);
    }

    key = atoi(argv[1]);

     plainText = get_string("plain text: ");

    printf("ciphertext: ");

    for(int i = 0, length = strlen(plainText); i < length; i++)
    {
        newkey = key;
        if(!isalpha(plainText[i])) //check for non alphabetical characters
        {
          //debugger comment printf("special char: %c plaintext + key:%i newkey: %i\n",plainText[i], plainText[i]+key, newkey);
            printf("%c", plainText[i]);

        }else if(isupper(plainText[i]))     //checking case
        {

           if(plainText[i] + key >'Z')
            {
                newkey = (((plainText[i] + newkey) % 'Z') % 26);        //Wrap ciphertext
                //debug comment printf("uppercase char: %c newkey:%i cipherText: %c\n",plainText[i], newkey, ('A' + newkey - 1));
               printf("%c", 'A' + newkey - 1);

            }else{
                printf("%c", plainText[i] + key);
                //printf("upper case char: %c plaintext + key:%i newkey: %i\n",plainText[i], plainText[i]+key, 'A' + key);
            }

        }else{

            if((plainText[i] + newkey) >'z')
            {
                newkey = (((plainText[i] + newkey) % 'z') % 26);      //Wrap ciphertext
                //debugger comment printf("lowercase char: %c newkey:%i cipherText: %c\n",plainText[i], newkey, ('a' + newkey - 1));
                 printf("%c", 'a' + newkey - 1);

            }else{

               //debugger coment printf("lowercase char: %c plaintext + key:%i cipherText: %c\n",plainText[i], plainText[i]+key, plainText[i] + key );
                printf("%c", plainText[i] + key);
            }
        }
    }
    printf("\n");

}