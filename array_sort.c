/*------------------------------------------------------
* Filename: array_sort.c
* Description: this program inputs 10 integers and creats two arrays, one of the numbers and of int pointer, the pointer array will be sorted depense on the int array
* Author:Yonatan shami
-------------------------------------------------------*/
/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - swaps between to pointers in the pointers array in location loc1 and loc2
*
* Parameters –  [IN first_parameter - int* pointers[], int loc1, int loc2] 
*
* Author - Yonatan Shami
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Name - sort 
*
* Function Purpose - sort the pointers array by from the one that points to the smallest value to the largest
*
* Parameters –  [IN first_parameter - int* pointers[], int len] 
*
*
* Author - Yonatan Shami
-------------------------------------------------------*/
/*------------------------------------------------------
* Function Name - printArr
*
* Function Purpose - prints pointers addresses and the correspond integers pointed at
*
* Parameters –  [IN first_parameter - int* pointers[], int len] 
*
*
* Author - Yonatan Shami
-------------------------------------------------------*/
#include <stdio.h>

#define length 10

void swap(int* pointers[], int loc1, int loc2){
    int *store=pointers[loc1];//pointer that helps us store address of pointer in location loc1
    pointers[loc1]=pointers[loc2];
    pointers[loc2]=store;
}

void sort(int* pointers[], int len){
    int first;//the number in the array at location i in the i-st iteration. "brings it in front"
    for(int i=0; i<length; i++){
        first=*pointers[i];
        for(int j=i; j<length; j++){
            if(*pointers[j]<first){
                swap(pointers, i, j);
                first=*pointers[i];
            }
        }
    }
}

void printArr(int* pointers[], int len){
    for(int i=0; i<len; i++){
        printf("%d ", *pointers[i]);/*printing the values of the integers each pointer points to*/
    }
    printf("\n");
    for(int i=0; i<len; i++){
        printf("%p ", pointers[i]);/*printing address*/
    printf("\n");
    }
}


int main(void) {
    int numbers[length];
    int* pointers[length];

    for(int i=0; i<length; i++){/*inputs a number*/
        printf("enter your number: \n");
        scanf("%d", &numbers[i]);
    }

    for(int i=0; i<length; i++){
        pointers[i]=&numbers[i];
    }

    printArr(pointers, length);

    sort(pointers, length);//use the sort function on pointers

    printArr(pointers, length);
    return 0;
}
