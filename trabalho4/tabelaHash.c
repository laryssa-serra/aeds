#include <stdio.h>
#include <stdlib.h>
int length = 23;

struct node{
    int content;
    struct node *next;
};

void start(struct node *table){    
    for(int i = 0; i < length; i++){
        table[i].next = NULL;
    }
}

int hash(int value){
    return value%length;
}

struct node *search(struct node *table, int value, int position){
    struct node *test = table[position].next;
    struct node *temp = &table[position];
    
    while(test != NULL){
        if(test -> content == value){
            return temp;
        } else{
            temp = test;
            test = test -> next;
        }
    }
    return NULL;
}

void insert(struct node *table, int value){
    int position = hash(value);
    
    if(search(table, value, position) == NULL){
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->content = value;
        new->next = table[position].next;
        table[position].next = new;
        printf("Valor inserido com sucesso!\n");
    }else{
        printf("Valor já existe na tabela\n");
    }
}

void removeNode(struct node *table, int value){
    int position = hash(value);
    struct node *temp = search(table, value, position);
    
    if(temp != NULL){    
        struct node *temp2 = temp -> next;
        temp -> next = temp -> next;
        free(temp2);
        printf("O valor foi removido com sucesso!\n");    
    }else{
        printf("O valor não existe na tabela! Ele não pode ser removido\n");
    }
}

void print(struct node *table, int position){
    if(table[position].next == NULL){
        printf("Não exite valor nessa posição\n");
    }else{
        struct node *print = table[position].next;        
        while(print != NULL){
        printf("valor: %d\n", print->content);
        print = print -> next;
        }
    }
}

void add(struct node *table){
    int value;

    printf("Digite o valor que deseja inserir:\n");
    scanf("%d", &value);

    insert(table, value);
}

void takeOut(struct node *table){
    int value;

    printf("Insira o valor que deseja remover:\n");
    scanf("%d", &value);

    removeNode(table, value);
}

void fetch(struct node *table){
    int value;

    printf("Insira o valor que deseja verificar se está na tabela:\n");
    scanf("%d", &value);

    int position = hash(value);

    struct node *temp = search(table, value, position);

    if(temp == NULL){
        printf("O valor %d não esta na tabela\n", value);
    }else{
        printf("O valor %d esta na tabela\n", value);
    }
}

void show(struct node *table){
    int value;

    printf("Escolha a posicao até %d da tabela que deseja ver os valores:\n", length);
    scanf("%d", &value);

    if(value > length || value < 0){
        printf("ERRO! Valor inserido está fora da tabela\n");
        return;
    }
    print(table, value);
}

void freeTable(struct node *table){
    struct node *temp, *prev;

    temp = table;
    while(temp != NULL){
        prev = temp;
        temp = temp -> next;
        free(prev);
    }
}

int main()
{
    struct node *table = (struct node*)malloc(sizeof(struct node)*length);
    
    start(table);
    
    int control = 1, function;

    while(control){
        printf("Escolha uma das seguintes opções abaixo:\n");
        printf("(0) Sair do programa\n");
        printf("(1) Adicionar valor\n");
        printf("(2) Remover valor\n");
        printf("(3) Saber de um valor específico está na tabela\n");
        printf("(4) Escolha a posicao que deseja ver os valores\n");
        scanf("%d", &function);
    
        switch(function){
            case 0:
                control = 0;
                break;
            case 1:
                add(table);
                break;
            case 2:
                takeOut(table);
                break;
            case 3:
                fetch(table);
                break;
            case 4:
                show(table);
                break;

            default:
                printf("Insira um número válido\n");
                break;
        }
    }

    free(table);
    return 0;
}