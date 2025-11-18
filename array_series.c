/*------------------------------------------------------
* Filename: array_series
* Description: This program will define and input an int array and prints the corespond message about its state. 
* Author:Yonatan shami
-------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

int main(void){
    const int length=5;
    int arr[length];

    int down=0, up=0, still=0;//constants for each option
    for(int i=0; i<length; i++){
        printf("enter a number to the array:\n");
        scanf("%d", &arr[i]);

        if(i){//checks if i=0 so we can compare each number in the array to its previous
            if(arr[i-1]<arr[i]){
                up++;
            }else if(arr[i-1]>arr[i]){
                down++;
            }else{
                still++;
            }
        }else{//continue to the next i if i=0 in order to compare two arguments
            continue;
        }
    }
    if(up==length-1){//checks the value of each constant and if its with the size of the length of the array-1
        printf("The array is increasing\n");
    }else if(down==length-1){
        printf("The array is decreasing\n");
    }else if(still==length-1){
         printf("The array is constant\n");
    }else{
        printf("The array messed up\n");
    }

}