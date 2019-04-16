#include<stdio.h>
#include<stdlib.h>
/* TO DO LIST
Menu System
Encrypt with a rotaion cipher
Decrypt with a rotaion cipher and key
Encrypt with a substitution key
Decrypt with a substitution key with given subs

*/
/*
    How to rotation cipher
        Take a letter from a string in an array add a 'key' i.e a number to modify it and then put the charater that we modified back into the array
        Now hol'u a minute what happenes if you have a Z and when you modify it you get a ascii value of 91 or 92, then we have to recognise that the
        value of the character is to high then, we modifiy it to come back around to the start of the alphabet, to do this, we can take away from the
        value of the charater that is being modified the value of Z (90) and take away 1 and add the value of A (65) so if the key is a 2 and the message is Z.
        we would do this 90+2=92 92>90 so 92-90-1+65= 66 which turns Z into B which is the correct letter with the given key. Now wait hol'up a minute what
        happens if our user accidentally inputs a lowercase letter, well we can test for a lowercase character and then take away 24 the difference between a
        lower case letter and its uppercase counterpart and then do the algorithm above
*/
void EncyptionofRotationCipher (char ercs[], int key);//ercs means EncryptRotationCipherString this is the string which we will encrypt given a number to shift by int of the key

int main(){
    int menu1number;
    FILE *Inputfile;
    printf("Welcome to Henry's Encryption and Decryption Services\n");
    printf("If you want to encrypt a message with a rotaion cipher press 1\n");
    printf("if you want to decrypt a message encyrpted with a rotaion cipher and you have the rotaion key press 2\n");
    printf("If you want to encrypt a message using a substitution cipher press 3\n");
    printf("If you want to decrypt a message with a substitution cipher with the known substitutions press 4\n");
    printf("If you want to decrypt a message encrypted with a rotaion cipher without the \"cipher hey\" press 5\n");
    printf("If you want to decrypt a message with a message encrypted with a substitution cipher without the \"cipher key\" press 6\n");
    scanf("%d", &menu1number);

    switch (menu1number){
        case 1:
                Inputfile=fopen("Input.txt","r");
                char Inputmsg[1000];
                int key;
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(Inputmsg,1000,Inputfile);
                    fscanf(Inputfile,"%d",&key);
                    EncyptionofRotationCipher(Inputmsg,key);
                }
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
    }


    return 0;

}
void EncyptionofRotationCipher(char ercs[], int key){
    int pos;
    char letter;
    for(pos = 0; ercs[pos] != '\0'; ++pos){
        letter=ercs[pos];
        //printf("%c\n", letter);
       // printf("%d\n", key);
        if(letter >= 'a' && letter <= 'z'){
           letter = letter - 24;
        }
        if(letter >= 'A' && letter <= 'Z'){
            letter = letter + key;
            printf("%c", letter);

        if(letter > 'Z'){
            letter = letter - 'Z' + 'A' - 1;
        }
        ercs[pos] = letter;
        }
    }
    printf("%s",ercs);
    return 0;
}
