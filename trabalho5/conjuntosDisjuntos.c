#include <stdlib.h>
#include <stdio.h>

void makeSet (int value, int *parent, int *rank){
    rank[value] = 0;
    parent[value] = value;
}

int findSet (int value, int *parent){
    if(value != parent[value]){
        parent[value] = findSet(parent[value], parent);
    }
    return parent[value];
}

void search (int *parent){
    int value, root;
    printf("\nInsira o valor que deseja saber o seu representante raiz: \n");
    scanf("%d", &value);
    root = findSet(value, parent);
    printf("\nA raiz do valor escolhido %d é de: %d\n", value, root);
}

void insert (int *parent, int *rank){
    int value;
    printf("\nInsira o valor da vértice que deseja colocar:\n");
    scanf("%d", &value);
    makeSet(value, parent, rank);
    printf("\nO valor da vértice foi inserido com sucesso!\n");
}

void UnionByRank (int value1, int value2, int *parent, int *rank){
    int rootValue1 = findSet(value1, parent);
    int rootValue2 = findSet(value2, parent);

    if(rootValue1 == rootValue2){
        printf("\nOs valores estão no mesmo conjunto!\n");
        return; //é necessario esse return??
    }

    if(rank[rootValue1] > rank[rootValue2]){
        parent[rootValue2] = rootValue1;
    } else{
        parent[rootValue1] = rootValue2;

      if(rank[rootValue2] == rank[rootValue1])
        rank[rootValue2]++;
    }
    printf("\nA união dos valores foi feita com sucesso!\n");
}

void normalUnion (int *parent, int *rank){
    int value1, value2;
    printf("\nInsira o valor do primeiro vértice:\n");
    scanf("%d", &value1);
    printf("\nInsira o valor do primeiro vértice:\n");
    scanf("%d", &value2);
    UnionByRank(value1, value2, parent, rank);
}

void conection (int value1, int value2, int *parent){
    int rootValue1 = findSet(value1, parent);
    int rootValue2 = findSet(value2, parent);

    if(rootValue1 == rootValue2){
        printf("\nOs valores estão no mesmo conjunto, com raiz = %d\n", rootValue1);
    } else{
        printf("\nOs valores estão em conjuntos diferentes, com raiz de %d = %d e raiz de %d = %d\n", value1, rootValue1, value2, rootValue2);
    }
}

void path (int *parent){
    int value, root;
    printf("\nInsira o valor que deseja saber sua raiz:\n");
    scanf("%d", &value);

    root = findSet(value, parent);
    printf("\nA raiz de %d é: %d\n", value, root);
}

void check (int *parent){
    int value1, value2;

    printf("\nDigite o valor do primeiro vértice:\n");
    scanf("%d", &value1);

    printf("\nDigite o valor do segundo vértice:\n");
    scanf("%d", &value2);

    conection(value1, value2, parent);
}

void show (int size, int *parent, int *rank, int beginning){
    if(beginning == 1 ){
        beginning = 0;
    } else {
        beginning = 1;
    }

    for(int i = beginning; i < size+1; i++){
        printf("\nPosição: %d parent: %d Rank: %d\n", i, parent[i], rank[i]);
    }
}

int main(){
  int quantity, zero;
  printf("\nInsira o tamanho que deseja para os vetores (valor da maior aresta):\n");
  scanf("%d", &quantity);

  printf("\nDeseja incluir o '0' como posicao? Insira '1' para sim e '0' para não\n");
  scanf("%d", &zero);

  int *rank = (int*)malloc(sizeof(int*)*(quantity+1));
  int *parent = (int*)malloc(sizeof(int*)*(quantity+1));

  int control = 1, function;

  while(control){
    printf("\nEscolha uma das seguintes funções abaixo:\n");
    printf("Sair do programa: (0)\n");
    printf("Inserir aresta: (1)\n");
    printf("Procurar a raiz de um valor: (2)\n");
    printf("Unir elementos: (3)\n");
    printf("Verificar se 2 vértices estao conectados: (4)\n");
    printf("Mostrar parent e rank de cada um: (5)\n");
    scanf("%d", &function);
    
    switch(function){
        case 0:
        control = 0;
            break;
        case 1:
            insert(parent, rank);
            break;
        case 2:
            search(parent);
            break;
        case 3:
            normalUnion(parent, rank);
            break;
        case 4:
            check(parent);
            break;
        case 5:
            show(quantity, parent, rank, zero);
            break;
        default:
            printf("\nErro! Use um número válido\n");
            break;
    }
}

    free(parent);
    free(rank);

    return 0;
}

