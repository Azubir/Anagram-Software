#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "Sorting.h"
#include "anagram.h"
#define Max_Lines 40 //This is used for the 2d array to store the information from the file
#define Max_Elements 500 //This is used for the 2d array to store the information from the file
int main() {
    char anagramArr[Max_Lines][Max_Elements];
    int lineNum;
    fillescanning_ok(anagramArr, &lineNum);//reads in the the text file and stores it into 2d array
    quicksort(anagramArr, 0, lineNum-1);//sorts the 2d array in an alphabetic order
    anagramfinding(anagramArr,lineNum);//identifies the anagrams
}

