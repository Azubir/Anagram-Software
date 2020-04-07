//
// Created by azubi on 21/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "anagram.h"
void anagramfinding(char anagramArr[20][500],int lineNum){
    FILE *fp3 = fopen("OUTPUT.txt", "w");//creating a file to write to
    printf("The sorted list: ");//printing out a sentence to the terminal
    fprintf(fp3,"The sorted list: ");//writing out a sentence to a file
    for (int i= 0; i < lineNum; i++) {
        printf("\n%s\n", anagramArr[i]);//printing out the contents of the array which are sorted to the terminal
        fprintf(fp3,"\n%s\n", anagramArr[i]);//writing out the contents of the array which are sorted to the terminal
    }
    char alpha[26] = "abcdefghijklmnopqrstuvwxyz";
    int frequency[lineNum][26];
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < 26; j++) {
            frequency[i][j] = 0;/*intialising the contents of the array to zero; this array will be used to store the frequency of each of the letters in the*/
        }                                                    /*anagramArr array*/
    }
    int count = 0;
    for (int f = 0; f < lineNum; f++) {
        for (int x = 0; x < 26; x++) {
            for (int j = 0; anagramArr[f][j] != '\0'; j++) {
                if (anagramArr[f][j] == alpha[x] || anagramArr[f][j] == (alpha[x] - 32)) {
                    count = count + 1;//counting the number of time a letter appeared in a specific column
                }
            }
            frequency[f][x] = count;//assigning the frequency of the letter of a specific row to a 2d array
            count = 0;//reseting count to find the frequency of the next letter
        }
    }
    printf("\n");
    int record[lineNum][10];//creating a 2d array which will be used  for storing the index of the anagrams
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < 10; j++) {
            record[i][j] = -1;//assigning -1 to each element which will aid us later in printing out the anagrams
        }
    }
    int flag = 0;
    int  r = 0;
    for (int i = 0; i < lineNum; i++) {
        for (int x = i+1; x < lineNum; x++) {
            for (int j = 0; j < 26; j++) {
                if (frequency[i][j] != frequency[x][j]) {
                    flag = 1;//comparing  each element of a row to the others one if one single elment is not the same 1 will be assigned to flag and the loop will be exited
                    break;
                }
            }
            if (flag == 0) {
                record[i][r++]=x;//checking if flag is equal to 0 if it is then x value will be stored to a 2d array which will keep an index of the row that was identical to row thats been compared against
            }//r is incrementing each time a row was identified as this will allow for multiple storage of indexes of the anagrams on the column
            flag =0;//flag will be rested to 0
        }
        r=0;//r is reseted to 0 as it will be used again as the next row will examined
    }
    int alreadyprinted[lineNum];
    for(int i=0; i<lineNum; i++){
        alreadyprinted[i]=0;//assigning 0 to each element of a 2d array with a length og the columns
    }
    int hh=1;
    for(int i=0; i<lineNum; i++){
        if(alreadyprinted[i]==0 && record[i][0]!=-1){
            printf("Anagram %d: ", hh);//this is to print the number of the anagram we are on to the terminal
            printf("\"%s\"",anagramArr[i]);//This will print out the line of the anagram that has the indexes of the anagrams
            fprintf(fp3,"Anagram %d: ", hh);
            fprintf(fp3,"\"%s\"",anagramArr[i]);//this is to write the number of the anagram we are on to a file
            for(int j=0; j<10; j++){
                if(record[i][j]!=-1){//while theres an index which will be identified by a number other than -1
                printf("\"%s\"", anagramArr[record[i][j]]);//the index stored in the record will be evaluated to print out the row of a 2d array which are anagrams
                fprintf(fp3,"\"%s\"", anagramArr[record[i][j]]);//the index stored in the record will be evaluated to write out to a file  the row of a 2d array which are anagrams
                alreadyprinted[record[i][j]]=1;}//the ones that have been printed out already are not printed out again as this will avoid printing out unnecessary replicates
            }
            hh++;//this incremented to see which anagram we are on
            printf("\n");
            fprintf(fp3,"\n");
        }
    }
    int together[lineNum];//this will be used to store size of the frequency of each row
    int track=0;
    for(int i=0; i<lineNum; i++){
        for(int j=0; j<26; j++){
            track=track+frequency[i][j];//the size of frequency of each row is calculated and stored
            together[i]=track;//the size is then assigned to an elemnt to a 1d array
        }
        track=0;//reseting track to zero
    }
    flag = 0;
    r = 0;
    for (int i = 0; i < lineNum; i++) {
        for (int x =0; x < lineNum; x++) {
            if(x==i){//this is to avoid comparing the same row of each other
                x++;
            }
            if (together[x] > together[i]) {//if the row thats being compared against is bigger then this row then there could be a missing anagram if its less then theres no possible way of making that sentence as the amount of letters are less
                for (int j = 0; j < 26; j++) {
                    if (frequency[i][j] > frequency[x][j]) {//this checks the frequency of the current row against the row being compared to
                        flag = 1;                              //if this row has more frequency of certain letter aginst the row being compared to then its not possible to be a missing anagram
                        break;//                                 and assigns 1 to flag and exists the loop
                    }
                }
                if (flag == 0) {
                    record[i][r++] = x;//checking if flag is equal to 0 if it is then x value will be stored to a 2d array which will keep an index of the row that has frequency which could some frequency be removed and could make this sentemce
                }
                flag = 0;//flag will be rested to 0
            }
            r = 0;//r is reseted to 0 as it will be used again as the next row will examined
        }
    }
    for (int i = 0; i < lineNum; i++) {
        alreadyprinted[i] = 0;
    }
    hh = 1;
    for (int i = 0; i < lineNum; i++)  {         //                THIS WHOLE LOOP IS THE EXACT SAME ONE FROM LINES 63 TO 79
        if (alreadyprinted[i] == 0 && record[i][0] != -1) {//                 THIS IS TO PRINT OUT THE MISSING
            printf("Missing Anagram %d: ", hh);//                                 ANAGRAMS
            printf("\"%s\" is an anagram of", anagramArr[i]);
            fprintf(fp3,"Missing Anagram %d: ", hh);
            fprintf(fp3,"\"%s\" is an anagram of", anagramArr[i]);
            for (int j = 0; j < 10; j++) {
                if(record[i][j]!=-1){
                printf(" \"%s\" ", anagramArr[record[i][j]]);
                fprintf(fp3," \"%s\" ", anagramArr[record[i][j]]);
                alreadyprinted[record[i][j]] = 1;}
            }
            hh++;
            printf("\n");
            fprintf(fp3,"\n");
        }
    }
fclose(fp3);//This is to close the file
}