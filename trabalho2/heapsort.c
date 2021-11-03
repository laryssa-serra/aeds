#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void createVector(int number, int*heap){
    srand((unsigned)time(NULL));
    printf("\nO vetor é: ");

    for(int i = 1; i <= number; i++){
        heap[i] = (rand() % 100);
        printf("%d, ", heap[i]);
    }

    printf("\n");

}

void showHeap(int number, int*heap){
    printf("O vetor é: ");
    
    for(int i = 1; i <= number; i++){
        printf("%d, ", heap[i]);
    }

    printf("\n");
}

void maxHeap(int position, int number, int*heap){
    int aux = heap[position];

    while(heap[position/2] < aux){
        showHeap(number, heap);
        printf("troca: %d, %d \n", aux, heap[position/2]);
        heap[position] = heap[position/2];
        position = position/2;
        
        if(position/2 == 0){
            break;
        }
    }
    heap[position] = aux;
}

int downHeap(int position, int number, int*heap){
   int aux = heap[position];
   int hasChildren = (position <= number/2);
   int childrenPosition;

   while(hasChildren){
       childrenPosition = position*2;
       printf("parent: %d, children 1: %d, children 2: %d\n", heap[position], heap[childrenPosition], heap[childrenPosition+1]);
       if((childrenPosition < number) && (heap[childrenPosition+1] > heap[childrenPosition])){
           childrenPosition = childrenPosition+1;
        }

        if(heap[childrenPosition] <= aux){
            hasChildren = 0;
        } else {
            showHeap(number, heap);
            printf("troca: %d com %d\n", aux, heap[childrenPosition]);
            heap[position] = heap[childrenPosition];
            position = childrenPosition;
            hasChildren = (position <= number/2);
        }

        showHeap(number, heap);
        heap[position] = aux;
       
   }
    showHeap(number, heap);
    return *heap;
}

int createMaxHeapMax(int number, int*heap){
    for(int i = 2; i <= number; i++){
        maxHeap(i, number, heap);
    }
    showHeap(number, heap);

    return *heap;
}

int createMinHeap(int number, int*heap){
    for(int i = number/2; i > 1; i--){
        downHeap(i, number, heap); 
    }
    showHeap(number, heap);

    return *heap;
}

int swap(int*heap, int first, int second){
    int aux = heap[first];
    heap[first] = heap[second];
    heap[second] = aux;

    return *heap;
}

int minHeap(int number, int* heap){
    *heap = createMaxHeapMax(number, heap);
    for(int i = 1; i <= number; i++){
        printf("troca: %d com %d\n", heap[1], heap[number+1-i]);
        *heap = swap(heap, 1, (number+1-i));
        downHeap(1, number-i, heap);
    }
    showHeap(number, heap);

    return *heap;
}

int insert(int number, int*heap){
    int new;
    printf("Insira o elemento que deseja adicionar: \n");
    scanf("%d", &new);
    heap = realloc(heap, (sizeof(int)*(number+2)));
    showHeap(number, heap);
    heap[number+1] = new;
    showHeap(number, heap);
    return *heap;

}

int exclude(int number, int*heap){
    int positionRemove;
    printf("Insira a posição que deseja remover: \n");
    scanf("%d", &positionRemove);

    if(positionRemove > number){
        printf("Posição inválida!");
        return *heap;
    }

    printf("positionRemove: %d, number: %d\n", heap[positionRemove], heap[number]);
    *heap = swap(heap, positionRemove, number);
    printf("positionRemove: %d, number: %d\n", heap[positionRemove], heap[number]);
    heap[number] = 0;
    heap = realloc(heap, (sizeof(int)*(number)));
    return *heap;
}

int priority(int number, int*heap){
   int changePriority;
   printf("Insira a posição que deseja mudar a prioridade: ");
   scanf("%d", &changePriority);

   if(changePriority > number){
       printf("Posição inválida!");
       return *heap;
   } 

   int newPriority; 
   printf("Insira o valor que deseja como prioridade: ");
   scanf("%d", &newPriority);

   printf("troca: %d por %d\n", heap[changePriority], newPriority);

   if(heap[changePriority] > newPriority){
       heap[changePriority] = newPriority;
       downHeap(changePriority, number, heap);
   } else{
       heap[changePriority] = newPriority;
       maxHeap(changePriority, number, heap);
   }
   showHeap(number, heap);

   return *heap;
}

int main(){
    printf("\nInsira um valor para o Heap que deseja criar: \n");

    int number;
    scanf("%d", &number);
    
    int *heap;
    heap = (int*)malloc(sizeof(int)*(number+1));
    createVector(number, heap);
    
    int function, command = 1;

    printf("\nEscolha uma das opções abaixo:\n");
    while(command){
        printf("Deseja sair do programa? (0)\n");
        printf("Deseja montar o Heap de máximo? (1)\n" );
        printf("Deseja montar o Heap de minimo? (2)\n" );
        printf("Deseja inserir um elemento ao vetor e mostrar o Heap formado? (3)\n" );
        printf("Deseja imprimir a Heap (4)\n" );
        printf("Deseja remover um elemento do vetor e mostrar o novo Heap? (5)\n" );
        printf("Deseja ordernar pelo método de heapsort (6)\n" );
        printf("Deseja alterar a prioridade e mostrar o novo Heap? (7)\n" );
        scanf("%d", &function);

      switch(function){
      case 0:
              command = 0;
              break;
      case 1:
              *heap = createMaxHeapMax(number, heap);
              break;
      case 2:
              *heap = createMinHeap(number, heap);
              break;
      case 3:
              insert(number, heap);
              number++;
              *heap = createMaxHeapMax(number, heap);
              showHeap(number, heap);
              break;
      case 4:
              showHeap(number, heap);
              break;
      case 5:
              exclude(number, heap);
              number--;
              *heap = createMaxHeapMax(number, heap);
              showHeap(number, heap);
              break;
      case 6:
              minHeap(number, heap);
              break;
      case 7:
              priority(number, heap);
              break;
      default:
              printf("Insira um número válido!\n");
              break;
      }
    }

 free(heap);
 return 0;   
}
