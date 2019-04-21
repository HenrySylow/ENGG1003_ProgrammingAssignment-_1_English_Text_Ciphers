#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void DecryptionofRotationCipherWthKey (char drcwk[], int key); // drcwk means Decryption of Rotation Cipher With Key
void EncyptionofSubstitutionCipherWthKey(char escs[],char ssk[]);// escs means EncryptSubtitutionCipherString, sk means StringSubtitutionKey

int main(){
    int menu1number;
    FILE *Inputfile;
    printf("Welcome to Henry's Encryption and Decryption Services\n");
    printf("If you want to encrypt a message with a rotaion cipher press 1\n");
    printf("if you want to decrypt a message encyrpted with a rotaion cipher and you have the rotaion key press 2\n");
    printf("If you want to encrypt a message using a substitution cipher press 3\n");
    printf("If you want to decrypt a message with a substitution cipher with the known substitutions press 4\n");
    printf("If you want to decrypt a message encrypted with a rotaion cipher without the \"cipher key\" press 5\n");
    printf("If you want to decrypt a message with a message encrypted with a substitution cipher without the \"cipher key\" press 6\n");
    scanf("%d", &menu1number);

    switch (menu1number){
        case 1: Inputfile=fopen("Input.txt","r");
                char Inputmsg[1000];
                int key;
                if (Inputfile == NULL){ // check if the file is there
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(Inputmsg,1000,Inputfile); // get the message string to be encrypted
                    fscanf(Inputfile,"%d",&key);// get the number to shift by
                    EncyptionofRotationCipher(Inputmsg,key);// calls the function to manipulate the arguments
                }
        break;
        case 2: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg2[1000];
                int key2;
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(Inputmsg2,1000,Inputfile);
                    fscanf(Inputfile,"%d",&key2);
                    DecryptionofRotationCipherWthKey(Inputmsg2,key2);
                }
        break;
        case 3: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg3[1000], subkey1[27];
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(Inputmsg3,1000,Inputfile);
                    fscanf(Inputfile,"%s",&subkey1);
                    //printf("%c", subkey1[0]);
                    EncyptionofSubstitutionCipherWthKey(Inputmsg3, subkey1);

                }
                //printf("%s", Inputmsg3);
                //printf("%s", subkey1);
        break;
        case 4: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg4[1000], subkey2[27];
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(Inputmsg4,1000,Inputfile);
                    fscanf(Inputfile,"%s",&subkey1);
                    //printf("%c", subkey1[0]);
                    (Inputmsg4, subkey2);

                }
        break;
        case 5:
        break;
        case 6:
        break;
    }


    return 0;

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//This is a function for Ecryption of a rotation cipher with a given 'key' or shift key
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void EncyptionofRotationCipher(char ercs[], int key){
    int pos; // position counter
    char letter; // the letter we are modifing
    for(pos = 0; ercs[pos] != '\0'; pos++){ // This 'for' allows the funtion to modify each part of the array indvidually untill we hit the end of the string
        letter=ercs[pos]; // take the letter in the given position in the array
        //printf("%c\n", letter);
       // printf("%d\n", key);
        if(letter >= 'a' && letter <= 'z'){
           letter = letter - 32;// taking away 32 the difference between uppercase and its lower case counter part
        }
        if(letter >= 'A' && letter <= 'Z'){
            letter = letter + key; // here we take our letter, and add the amount we are shifting by
          //  printf("%c", letter);

        if(letter > 'Z'){
            letter = letter - 26;
        /*if our shift key gives a value greater than Z if it is left it will return a charater not of the uppercase alphabet,
          so we take 26 to bring it back around to the start of the alaphbet so Z shifted 1 would give a value of 91 but we need 65
          91-26=65 which is the ascii number for 'A'*/
        }
        ercs[pos] = letter; // replace the letter we are modifing with the modified letter
        }
    }
    printf("%s",ercs);//print the string to the terminal
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//This is a function for Decryption of a rotation cipher with a given key
//This function is exactly the same as the encryption function just backwards so instead of adding a key we take it away and instead of checking for a character
//greater than 'Z' we check for one less than 'A' and add 26 instead of taking away 26
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void DecryptionofRotationCipherWthKey(char drcwk[], int key){
    int pos;
    char letter;
    for(pos = 0; drcwk[pos] != '\0'; pos++){
        letter = drcwk[pos];
        if(letter >= 'a' && letter <= 'z'){
            letter = letter - 32;
        }
        if(letter >= 'A' && letter <= 'Z'){
            letter = letter - key;
         //  printf("%c", letter);

        if(letter < 'A'){
            letter = letter + 26;
        }
        drcwk[pos] = letter;
        }
    }
    printf("%s", drcwk);
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//This is a function for Encryption of a message using a substution key
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void EncyptionofSubstitutionCipherWthKey(char escs[],char ssk[]){
    int posstring;
    char letter;
    for(posstring = 0; escs[posstring] != '\0'; posstring++){
        letter = escs[posstring];
        if(letter >= 'a' && letter <= 'z'){
            letter = letter - 32;
            escs[posstring] = letter;
        }
        switch (letter){
        case 'A': letter = ssk[0];
            break;
        case 'B': letter = ssk[1];
            break;
        case 'C': letter = ssk[2];
            break;
        case 'D': letter = ssk[3];
            break;
        case 'E': letter = ssk[4];
            break;
        case 'F': letter = ssk[5];
            break;
        case 'G': letter = ssk[6];
            break;
        case 'H': letter = ssk[7];
            break;
        case 'I': letter = ssk[8];
            break;
        case 'J': letter = ssk[9];
            break;
        case 'K': letter = ssk[10];
            break;
        case 'L': letter = ssk[11];
            break;
        case 'M': letter = ssk[12];
            break;
        case 'N': letter = ssk[13];
            break;
        case 'O': letter = ssk[14];
            break;
        case 'P': letter = ssk[15];
            break;
        case 'Q': letter = ssk[16];
            break;
        case 'R': letter = ssk[17];
            break;
        case 'S': letter = ssk[18];
            break;
        case 'T': letter = ssk[19];
            break;
        case 'U': letter = ssk[20];
            break;
        case 'V': letter = ssk[21];
            break;
        case 'W': letter = ssk[22];
            break;
        case 'X': letter = ssk[23];
            break;
        case 'Y': letter = ssk[24];
            break;
        case 'Z': letter = ssk[25];
            break;
        }
        escs[posstring]= letter;
    }

    printf("%s", escs);
    return 0;
}
