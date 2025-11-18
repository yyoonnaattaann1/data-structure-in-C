/*------------------------------------------------------
* Filename: encryption
* Description: This program find the encryption and helps gargamel find the message 
* Author:Yonatan shami
-------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

#define message_len 26
#define steps_forward 5
#define steps_backwards 4
#define div 7
#define sub 5


void forwards(int arr[], int steps, int length){//iterates forward the array steps times
    int store;
    int i;
    for(int j=0; j<steps; j++){//iterates at the number of steps
        store=0;
        for(i=length-1; i>-1; i--){//itarate the array one time forwards
            if(i==length-1){
                store= arr[i];
            }else{
                arr[i+1]=arr[i];
            }
        }
        arr[0]=store;
    }

}

void backwards(int arr[], int steps, int length){//iterates backwards the array steps times
    int store;
    int i;
    for(int j=0; j<steps; j++){//iterates at the number of steps
        store=0;
        for(i=0; i<length-1; i++){//itarate the array one time forwards
            if(i==0){
                store= arr[i];
            }else{
                arr[i-1]=arr[i];
            }
        }
        arr[length-1]=store;
    }

}

void flip(int arr[], int length){//flips the first and second halfs of the array
    int store=0;
    for(int i=0; i<length/2; i++){
        store=arr[i];
        arr[i]=arr[i+(length/2)];
        arr[i+(length/2)]=store;
    }

}

void subtract(int arr[], int number, int length){//subtracts a constant number to every integer in the array
    for(int i=0; i<length; i++){
        arr[i]-=number;
    }

}


void divEven(int arr[], int diva, int length){//divides every even located number in the array with multi
    for(int i=0; i<length/2; i++){
        arr[i*2]/=diva;
    }
}


void getSmaller(int arr[], int length){//Each cell gets substructed by the value of the previous cell. starting from the end
    for(int i=length-1; i>0; i--){
        arr[i]=arr[i]-arr[i-1];
    }

}

void printArr(int arr[], int length){//print array function
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[message_len];
    for(int i=0; i<message_len; i++){
        printf("enter a number to the array:\n");
        scanf("%d", &arr[i]);
    }

    /*apply functions in the correct order*/
    flip(arr, message_len);
    printArr(arr, message_len);

    getSmaller(arr, message_len);
    printArr(arr, message_len);

    forwards(arr, steps_forward, message_len);
    printArr(arr, message_len);

    divEven(arr, div, message_len);
    printArr(arr, message_len);

    backwards(arr, steps_backwards, message_len);
    printArr(arr, message_len);

    subtract(arr, sub, message_len);
    printArr(arr, message_len);
    
    char reversed[message_len+1];
    for(int i=0; i<message_len; i++){//convert the int array to a string adding '\0' to the last cell
        reversed[i]=(char)arr[i];
    }
    reversed[message_len]='\0';

    printf("%s", reversed);
    return 0;
}