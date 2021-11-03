#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} no;

void imprimirLista(no *cabeca){
    no* noAtual = cabeca;

    while(1){
        printf("%d ", noAtual->valor);
        noAtual = noAtual->proximo;
        
        if(noAtual == cabeca){
            printf("\n");
            break;
        }
    }
}

no *buscarNo(no *cabeca, int valor){
    no *noAtual = cabeca;
    
    while(1){
        if(noAtual->valor == valor){
            return noAtual;
        }

        noAtual = noAtual->proximo;
        if(noAtual == cabeca){
            return NULL;
        }
    }
}

no *inserirInicio(no *cabeca, int valor){
    if(buscarNo(cabeca, valor) != NULL){
        printf("O valor %d já existe!\n", valor);
        return cabeca;
    }
    
    no *final = cabeca->anterior;
    
    no *novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->proximo = cabeca;
    novoNo->anterior = final;
    
    cabeca->anterior = novoNo;
    final->proximo = novoNo;

    printf("O valor %d foi inserido com sucesso!\n", valor);
    return novoNo;
}

no *inserirCrescente(no *cabeca, int valor){
    if(buscarNo(cabeca, valor) != NULL){
        printf("O valor %d já existe!\n", valor);
        return cabeca;
    }
    
    no *noAtual = cabeca;
    
    while(1){
        if(valor < noAtual->valor){
            no *final = noAtual->anterior;
            
            no *novoNo = (no*)malloc(sizeof(no));
            novoNo->valor = valor;

            novoNo->proximo = noAtual;
            novoNo->anterior = final;

            noAtual->anterior = novoNo;
            final->proximo = novoNo;

            printf("O valor %d foi inserido com sucesso!\n", valor);
            if(novoNo->proximo == cabeca){
                return novoNo;
            } else {
                return cabeca;
            }
        }
        noAtual = noAtual->proximo;

        if(noAtual == cabeca){
            no *final = noAtual->anterior;
            
            no *novoNo = (no*)malloc(sizeof(no));
            novoNo->valor = valor;

            novoNo->proximo = noAtual;
            novoNo->anterior = final;

            noAtual->anterior = novoNo;
            final->proximo = novoNo;

            printf("O valor %d foi inserido com sucesso!\n", valor);
            return cabeca;
        }
    }
}

no *removerNo(no *cabeca, int valor){
    no *noParaRemover = buscarNo(cabeca, valor);

    if(noParaRemover == NULL){
        printf("O valor %d não existe!\n", valor);
        return cabeca;
    } else {
        noParaRemover->anterior->proximo = noParaRemover->proximo;
        noParaRemover->proximo->anterior = noParaRemover->anterior;
        
        printf("O valor %d foi removido com sucesso!\n", valor);
        if(noParaRemover == cabeca){
            return cabeca->proximo;
        } else {
            return cabeca;
        }
    }
}

int main(){
    no *cabeca = (no*)malloc(sizeof(no));
    int escolhaInsercao, escolha, valor;

    printf("Qual modelo de inserção irá escolher: (1)inicio da lista (2)ordem crescente\n");
    scanf("%d", &escolhaInsercao);
    if(escolhaInsercao != 1 && escolhaInsercao != 2){
        return 0;
    }

    printf("Insira um valor para o primeiro nó:\n");
    scanf("%d", &cabeca->valor);
    cabeca->proximo = cabeca;
    cabeca->anterior = cabeca;

    while(1){
        printf("Deseja fazer outros nós? (1) \n");
        printf("Deseja excluir algum elemento? (2)\n");
        printf("Deseja visualizar a lista que foi criada? (3)\n");
        printf("Deseja buscar por algum elemento? (4)\n");
        printf("Deseja finalizar o programa. (Qualquer outra tecla)\n");
        scanf("%d", &escolha);

        if(!escolha){
            break;
        }

        else if(escolha == 1){
            printf("Diga o valor a ser inserido:\n");
            scanf("%d", &valor);
            if(escolhaInsercao == 1){
                cabeca = inserirInicio(cabeca, valor);
            } else if (escolhaInsercao == 2){
                cabeca = inserirCrescente(cabeca, valor);
            }
        }
        else if(escolha == 2){
            printf("Diga o valor a ser excluído:\n");
            scanf("%d", &valor);
            cabeca = removerNo(cabeca, valor);
        }
        else if(escolha == 3){
            imprimirLista(cabeca);
        }
        else if(escolha == 4){
             printf("Diga o valor que deseja buscar:\n");
            scanf("%d", &valor);
            if(buscarNo(cabeca,valor) == NULL){
                printf("O valor NÃO existe!\n");
            } else {
                printf("O valor EXISTE!\n");
            }
        }
        else {
            break;
        }
    }
}