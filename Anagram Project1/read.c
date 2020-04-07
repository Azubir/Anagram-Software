//
// Created by azubi on 07/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "read.h"
int lineNum;
int i;
const char *ANAGRAM_FILE_PATH="../input/input (3).txt";
void fillescanning_ok(char x[Max_Lines][Max_Elements], int *y){
    FILE *fp = fopen(ANAGRAM_FILE_PATH, "r+");//opening a file to read from
    if (fp == NULL) {
        perror("Eroor opening weather file");   //checks weather the file does exist or not
        lineNum = -1;
    } else {
        while (fgets(x[lineNum], sizeof(x[lineNum]), fp) != NULL) {//reading the information from the file and storing into a 2d array
            lineNum++;//incrementing lineNum in order to get the length of the file
        }
        fclose(fp);//closes the file

    }
    *y=lineNum;//assigns the value of lineNum to the pointer which indicates the length of the columns


}
