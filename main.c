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
void DecryptionofRotationCipher(char drc[]);
void DecryptionofSubCipherwthKey (char dsck[], char subck[]);
void DecryptionofSubCipherStats (char dscs[]);
void swap(int *xp, int *yp);
void Printer(char printer1[]);

int main(){
    int menunumber, bin;
    char wordbin[100], wordbin1[100];
    FILE *Inputfile;
     printf("Welcome to Henry's Encryption and Decryption Services\n");
    Inputfile = fopen("Input.txt", "r");
    if (Inputfile == NULL){
        printf("Error");
        return (0);
    }
    if(Inputfile != NULL){
        fscanf(Inputfile,"%s %s %d",&wordbin, &wordbin1, &menunumber);
        //printf("%s %s %d",wordbin,wordbin1,menunumber);

    }



    switch (menunumber){
        case 1: Inputfile=fopen("Input.txt","r");
                char Inputmsg[1000];
                int key;
                if (Inputfile == NULL){ // check if the file is there
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(wordbin, 100, Inputfile);
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
                    fgets(wordbin, 100, Inputfile);
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
                    fgets(wordbin, 100, Inputfile);
                    fgets(Inputmsg3,1000,Inputfile);
                    fscanf(Inputfile,"%s",&subkey1);
                    //printf("%s\n %s\n %s\n",wordbin,Inputmsg3, subkey1);
                    EncyptionofSubstitutionCipherWthKey(Inputmsg3, subkey1);

                }
                //printf("%s", Inputmsg3);Decryption
                //printf("%s", subkey1);
        break;
        case 4: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg4[1000], subkey2[27];
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(wordbin, 100, Inputfile);
                    fgets(Inputmsg4,1000,Inputfile);
                    fscanf(Inputfile,"%s",&subkey2);
                    //printf("%s", subkey2);
                    DecryptionofSubCipherwthKey(Inputmsg4, subkey2);

                }
        break;
        case 5: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg5[1000000];//
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(wordbin, 100, Inputfile);
                    fgets(Inputmsg5,1000,Inputfile);
                    //fscanf(Inputfile,"%s",&subkey1);
                    //printf("%c", subkey1[0]);
                    DecryptionofRotationCipher(Inputmsg5);

                }
        break;
        case 6: Inputfile=fopen("Input.txt","r");// this case is the exactly the same as case 1
                char Inputmsg6[1000000];
                if (Inputfile == NULL){
                    printf("Error");
                    return (0);
                }
                if(Inputfile != NULL){
                    fgets(wordbin, 100, Inputfile);
                    fgets(Inputmsg6,1000000,Inputfile);
                    //fscanf(Inputfile,"%s",&subkey1);
                    //printf("%c", subkey1[0]);
                    DecryptionofSubCipherStats(Inputmsg6);

                }
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
    printf("%s\n",ercs);
    Printer(ercs);
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
    Printer(drcwk);
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//This is a function for Encryption of a message using a substution key. It is given the string and the key, and first converts evey letter in that string into an
//uppercase letter. It then takes the value of the letter from each position in the string and for each letter, it replaces it with letter that is in the equaivalent
//letter position in the string that holds the key i.e. if the letter is 'A' it will be replaced by what ever letter is in position 0 in the string.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void EncyptionofSubstitutionCipherWthKey(char escs[],char ssk[]){
    int posstring; // Used to call each charactrer in the string to be encrypted
    char letter; // Take the letter, and enables the character to be edited
    for(posstring = 0; escs[posstring] != '\0'; posstring++){ // Here we take every value in the string until we reach the null character that was stored by fgets
        letter = escs[posstring];
        if(letter >= 'a' && letter <= 'z'){ // this if statment takes any lowercase letter and makes it uppercase
            letter = letter - 32;
           // escs[posstring] = letter;
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
        escs[posstring]= letter; // move the modified letter into the string
    }

    printf("%s\n", escs); //print ot the terminal
    Printer(escs);
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void DecryptionofRotationCipher(char drc[]){
    int pos, key;
    char letter, buf[1000];
    int counter[26] = {0},sortedcounter[26] = {0}, thingimtrying[26]={0}, counterpos, pos, swapruntime, swapcomp, counterpos1, whatistheletterfrom0to25;
    char buf [1000], letter;

    //printf("%s\n", keyholder);
    /*for(int count = 0; count<strlen(dscs); count++){
            buf[count] = dscs[count];
            }
           // printf("%s\n", buf);
            printf("%s\n", dscs);
    for(pos = 0; dscs[pos] != '\0'; pos++){

            letter = dscs[pos];
            if(letter >= 'a' && letter <= 'z'){
                letter = letter - 32;
            }
            dscs[pos] = letter;
            if(letter >= 'A' && letter <= 'Z'){
                counterpos = letter - 'A' ;
                counter[counterpos]++;

            }
    for(int count = 0; count< 26; count++){
            sortedcounter[count] = counter[count];
            //printf("%d\n",sortedcounter[count]);
            }

    /*
    Get the array, for each letter increment the coresponding letter
    use a bubble sort to find which letter is the most frequent make this e, then make the second most frequent t then make the 3rd and so on
    write to a file, then using fscanf of the output file compare each word to the dictionary
    if there are no words that match change
    */
    }

       for (swapruntime = 0; swapruntime < 25; swapruntime++) { // This is a bubble sort algorithm it runs through the program i number of times where the i is the length of the string
        for (swapcomp = 0; swapcomp < 26-swapruntime-1; swapcomp++){ // For every value of i the program compares every value to its neibour and swaps it if one is larger
           if (sortedcounter[swapcomp] < sortedcounter[swapcomp+1]){
              swap(&sortedcounter[swapcomp], &sortedcounter[swapcomp+1]);
           }
        }
    }
    for (i = 0; i<3; i++){
        for(counterpos1= 0;counterpos1< 26 ;counterpos++)
            if(counter[counterpos1] == sortedcounter[i])
                if(counterpos1<) */
    }
    for(key = 0; key < 26; key++){
        for(int count = 0; count<strlen(drc); count++){
            buf[count] = drc[count];
        }
        for(pos = 0; buf[pos] != '\0'; pos++){
            letter = buf[pos];
            if(letter >= 'a' && letter <= 'z'){
                letter = letter - 32;
            }
            if(letter >= 'A' && letter <= 'Z'){
                letter = letter - key;
            //  printf("%c", letter);

            if(letter < 'A'){
                letter = letter + 26;
            }
            buf[pos] = letter;
            }
        }
        printf("Key: %d String:%s\n",key, buf); }
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//This function, takes the message to be decrypted and the key and takes each after being converted to uppercase if needs be, it then scans
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void DecryptionofSubCipherwthKey (char dsck[], char subck[]){
    int pos, poskey; //poskey is to call the values in the key from the string subck
    char letter;
    for(pos = 0; dsck[pos] != '\0'; ++pos){ // Converting to uppercase
            letter = dsck[pos];
            if(letter >= 'a' && letter <= 'z'){
                letter = letter - 32;
            }
            for(poskey = 0; poskey < 26; poskey++){ //for every position in the key run this until the poskey is at 25 or the break is hit
                if (letter == subck [poskey]){ // If the letter in the matches the letter in the key

                    switch(poskey){ /*(his changes the letter to the letter that should be in the correspoing position, so lets say our letter is 'B' and B is in the first
                    position in our key, it will turn that 'B' into an 'A'*/
                    case 0: letter = 'A';
                        break;
                    case 1: letter = 'B';
                        break;
                    case 2: letter = 'C';
                        break;
                    case 3: letter = 'D';
                        break;
                    case 4: letter = 'E';
                        break;
                    case 5: letter = 'F';
                        break;
                    case 6: letter = 'G';
                        break;
                    case 7: letter = 'H';
                        break;
                    case 8: letter = 'I';
                        break;
                    case 9: letter = 'J';
                        break;
                    case 10: letter = 'K';
                        break;
                    case 11: letter = 'L';
                        break;
                    case 12: letter = 'M';
                        break;
                    case 13: letter = 'N';
                        break;
                    case 14: letter = 'O';
                        break;
                    case 15: letter = 'P';
                        break;
                    case 16: letter = 'Q';
                        break;
                    case 17: letter = 'R';
                        break;
                    case 18: letter = 'S';
                        break;
                    case 19: letter = 'T';
                        break;
                    case 20: letter = 'U';
                        break;
                    case 21: letter = 'V';
                        break;
                    case 22: letter = 'W';
                        break;
                    case 23: letter = 'X';
                        break;
                    case 24: letter = 'Y';
                        break;
                    case 25: letter = 'Z';
                        break;

                    }
                    break; // breaks out of the for loop if the if condition is met
                }

            }
           // printf("%c\n",letter);
            dsck[pos]=letter;



    }
    printf("%s", dsck);
    Printer(dsck);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function uses statiscal analysis of the encrytpted text, and replaces the corresponding letter that occur most ferquently in the order that they are frequent in
// the english language, so for instance the program take the
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void DecryptionofSubCipherStats(char dscs[]) {
    int counter[26] = {0},sortedcounter[26] = {0}, thingimtrying[26]={0}, counterpos, pos, swapruntime, swapcomp, counterpos1, whatistheletterfrom0to25;
    int a, b, c, d, e, f, g, h, i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    char buf [1000], letter;
    char keyholder[26] = {'!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!','!'};

    //printf("%s\n", keyholder);
    /*for(int count = 0; count<strlen(dscs); count++){
            buf[count] = dscs[count];
            }
           // printf("%s\n", buf); */
            printf("%s\n", dscs);
    for(pos = 0; dscs[pos] != '\0'; pos++){

            letter = dscs[pos];
            if(letter >= 'a' && letter <= 'z'){
                letter = letter - 32;
            }
            dscs[pos] = letter;
            if(letter >= 'A' && letter <= 'Z'){
                counterpos = letter - 'A' ;
                counter[counterpos]++;

            }
    for(int count = 0; count< 26; count++){
            sortedcounter[count] = counter[count];
            //printf("%d\n",sortedcounter[count]);
            }

    /*
    Get the array, for each letter increment the coresponding letter
    use a bubble sort to find which letter is the most frequent make this e, then make the second most frequent t then make the 3rd and so on
    write to a file, then using fscanf of the output file compare each word to the dictionary
    if there are no words that match change
    */
    }

    for (swapruntime = 0; swapruntime < 25; swapruntime++) { // This is a bubble sort algorithm it runs through the program i number of times where the i is the length of the string
        for (swapcomp = 0; swapcomp < 26-swapruntime-1; swapcomp++){ // For every value of i the program compares the
           if (sortedcounter[swapcomp] < sortedcounter[swapcomp+1]){
              swap(&sortedcounter[swapcomp], &sortedcounter[swapcomp+1]);
           }
        }
    }

/*I dont really know how to write why im doing this, basically I am taking the sorted values and finding what letter was the highest frequency and then changing that letter accoring to the frequency of letter in the
english language, then I add the letter to a 'key' and change the value in the thingimtrying to 1 so that chjaracter that i replaced is effectivly blocked of from being used again */

    for (pos = 0; dscs[pos] != '\0'; ++pos){
        if(dscs[pos]>='A' && dscs[pos]<='Z'){dscs[pos]=letter;
            letter = dscs[pos];
            whatistheletterfrom0to25 = letter-'A'; //find the letters value from 0-25 so it tells you the letter
            //printf("%d", whatistheletterfrom0to25);
            if(keyholder[whatistheletterfrom0to25] == '!'){
                for(int counterpos1 = 0; counterpos1<25; counterpos1++){
                    int valueof = sortedcounter[counterpos1];

                    if(valueof==counter[whatistheletterfrom0to25] && thingimtrying[counterpos1]== 0){
                        //printf("Counterpos1 %d  Letter Position %d \n", valueof, whatistheletterfrom0to25);
                        switch(counterpos1){
                        case 0: letter = 'E';
                            break;
                        case 1: letter = 'T';
                            break;
                        case 2: letter = 'A';
                            break;
                        case 3: letter = 'O';
                            break;
                        case 4: letter = 'I';
                            break;
                        case 5: letter = 'N';
                            break;
                        case 6: letter = 'S';
                            break;
                        case 7: letter = 'R';
                            break;
                        case 8: letter = 'H';
                            break;
                        case 9: letter = 'D';
                            break;
                        case 10: letter = 'L';
                            break;
                        case 11: letter = 'U';
                            break;
                        case 12: letter = 'C';
                            break;
                        case 13: letter = 'M';
                            break;
                        case 14: letter = 'F';
                            break;
                        case 15: letter = 'Y';
                            break;
                        case 16: letter = 'W';
                            break;
                        case 17: letter = 'G';
                            break;
                        case 18: letter = 'P';
                            break;
                        case 19: letter = 'B';
                            break;
                        case 20: letter = 'V';
                            break;
                        case 21: letter = 'K';
                            break;
                        case 22: letter = 'X';
                            break;
                        case 23: letter = 'Q';
                            break;
                        case 24: letter = 'J';
                            break;
                        case 25: letter = 'Z';
                            break;

                        }
                        thingimtrying[counterpos1]++;
                        keyholder[whatistheletterfrom0to25]=letter;
                        dscs[pos]=letter;
                    }
                }

            }
            else if(keyholder[whatistheletterfrom0to25] != '!') {
                letter=keyholder[whatistheletterfrom0to25];
                //printf("%s...",keyholder);
                dscs[pos]=letter;
            }
            }
    }

     printf("%s\n", dscs);

    for (counterpos = 0; counterpos<26; counterpos++){
            printf("%d %d\n", sortedcounter[counterpos], counter[counterpos]);}

    return;
}
/*
This function is called to sort an array, which is only used for the final task, it take the pointer value of the 2 intergers that were called for a swap between where the interger in
the array that comes first is shifted to become second in the array if it is smaller than the second interger in the array
*/
void swap(int *interger1, int *interger2) {
    int temp = *interger1;
    *interger1 = *interger2;
    *interger2 = temp;
}
/*
Printer Function, does what it says on the tin
*/
void Printer(char printer1[]) {
    FILE *Outputfile;
    Outputfile = fopen("Output.txt", "w+");
    if (Outputfile == NULL){
        printf("Error");
        return (0);
    }
    if(Outputfile != NULL){
        fprintf(Outputfile, "%s\n", printer1);
        printf("printed");
        fclose(Outputfile);
    }


}




