//
// Created by azubi on 17/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting.h" //linging the header file associated with this source file
void swap(char array [20][500], int i, int j){//swaping the positions of the sentences
    char temp[500] ;
    strcpy(temp, array[i]);
    strcpy(array[i],array[j]);
    strcpy(array[j],temp);
}
int partition(char array[20][500], int first, int last) {
    swap(array, first, (first + last) / 2); // swap middle value into first pos
    int pivot = array[first]; 	 // remember pivot

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value

    while (index1 <= index2) { // while some values still unknown
        if (strcmpi(array[index1], pivot)<=0)      //using strcmpi to ignore wether its capital or not
           index1++;     //incrementing the index
        else if (strcmpi(array[index2], pivot)>0)
            index2--;   //decrementing the index
        else {
            swap(array, index1, index2);
            index1++;  //incrementing the index
            index2--;  //decrementing the index
        }
    }
    swap(array, first, index2); // put the pivot value between the two
    // sublists and return its index
    return index2;
}
void quicksort(char array[20][500], int first, int last){

    //if the size of the array is equal to 0 or 1, the array is sorted by definition
    if(first < last){
        int pivotindex = partition(array, first, last);
        quicksort(array, first, pivotindex-1);
        quicksort(array, pivotindex+1, last);  //recursion function
    }

}