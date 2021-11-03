#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch (int min, int max, int * array , int search){
    
    while(min <= max){
    int middle = (max + min)/2;

        if(array[middle] == search){
            return middle;
        }
        if (array[middle] > search){
            max = middle - 1;
        }else{
            min = middle + 1;
        }
    }
    return -1;
}


int main(){

    int size, search, * array, result = 0;
    scanf("%d", &size);

    array = (int *)malloc(sizeof(int)* size);
    
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &search);

    result = binarySearch(0, size -1, array, search);

    if(result == -1){
        printf("O valor indicado não foi encontrado!\n");
    } else{
        printf("O valor indicado se encontra na posição %d\n", result);
    }

    return 0;
}
