/*------------------------------------------------------
* Filename: print_value-addr.c
* Description: this program inputs a string and array of numbers, prints each array character and his address usind pointes. 
* Author:Yonatan shami
-------------------------------------------------------*/

#include <stdio.h>

#define length 8

int main(void) {
    int numbers[length];
    char string[length];
    int * p = NULL;
    char * c = NULL;

    for(int i=0; i<length; i++){
        printf("enter your number: \n");/*inputs a number*/
        scanf("%d", &numbers[i]);
    }
    printf("enter your string: \n");/*inputs a string*/
    scanf("%s", string);
    
    p=&numbers[0];/*assining a pointer to the numbers array*/
    for(int i=0; i<length; i++){
        printf("the number is: %d\n", numbers[i]);
        printf("the number is: %d\n", *(p+i));/*two ways of printing the array charcters*/
        printf("his address is: %p\n", (void*)(p+i));/*printing address*/
    }

    c=&string[0];
    for(int i=0; i<length; i++){
        printf("the char is: %c\n", string[i]);
        printf("the char is: %c\n", *(c+i));
        printf("his address is: %p\n", (void*)(c+i));
    }
    
    return 0;
}