#include<stdio.h>
#include<stdlib.h>
/* TO DO LIST
Menu System
Encrypt with a rotaion cipher
Decrypt with a rotaion cipher and key
Encrypt with a substitution key
Decrypt with a substitution key with given subs

*/


int main(){
    int menu1number;
    printf("Welcome to Henry's Encryption and Decryption Services\n");
    printf("If you want to encrypt a message with a rotaion cipher press 1\n");
    printf("if you want to decrypt a message encyrpted with a rotaion cipher and you have the rotaion key press 2\n");
    printf("If you want to encrypt a message using a substitution cipher press 3\n");
    printf("If you want to decrypt a message with a substitution cipher with the known substitutions press 4\n");
    printf("If you want to decrypt a message encrypted with a rotaion cipher without the \"cipher hey\" press 5\n");
    printf("If you want to decrypt a message with a message encrypted with a substitution cipher without the \"cipher key\" press 6\n");
    scanf("%d", &menu1number);
    switch (menu1number){
        case 1: ;
        break;
        /*case 2:
        break;
        case 3:
        break;
        case 4;
        break;
        case 5:
        break;
        case 6:
        break; */
    }
    return 0;

}
