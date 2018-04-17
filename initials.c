#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string myName;
    myName=get_string("What is your full name?: ");
    char initials[strlen(myName)];
    printf("initials: ");
   for(int i=0;i<strlen(myName);i++){
       if(i==0){
           initials[i]=myName[i];

       }else if(isspace(myName[i-1])){

        if(isupper(myName[i])){
            initials[i]=initials[i]=toupper(myName[i]);
        }else{
           initials[i]=initials[i]=myName[i];
        }
       }
    printf("%c",initials[i]);
   }

    printf("\n");
}
