#include "menu.h"

Conta* logar(ListaContas listaContasBanco){

    char cpf[20], senha[20];
    
    getchar();
    
    printf("Insira seu CPF: ");
    fgets(cpf, 20, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    printf("Insira sua SENHA: ");
    fgets(senha, 50, stdin);
    senha[strcspn(senha, "\n")] = 0;

    Conta *conta = buscarListaContas(&listaContasBanco, cpf);
    if(conta != NULL && strcmp(conta->senha, senha) == 0){
        printf("Usuário logado com sucesso!\n");
        return conta;
    } else {
        printf("Conta ou senha inválida\n");
        return NULL;
    }
}

void telaInicial(){
    ListaContas listaContasBanco;
    iniciarListaContas(&listaContasBanco, 1);  

    int comandoCriarConta = 0, logado = 0, funcao;
    while(1){
        printf("Deseja criar sua conta? Insira (1) Sim. Caso já possua e queira realizar o login insira (0).\n");
        scanf("%d", &comandoCriarConta);

        if(comandoCriarConta == 1){
            Conta conta = criarConta();
            inserirListaContas(&listaContasBanco, conta);
        }else if(comandoCriarConta == 0){
            Conta* conta = logar(listaContasBanco);

            if(conta != NULL){
                verificaTransferencias(conta);
                logado = 1;
                while(logado){
                    printf("\nEscolha uma das opções abaixo:\n");
                    printf("(0) Encerrar sessão\n");
                    printf("(1) Trocar senha\n");
                    printf("(2) Mostrar saldo conta corrente, conta poupança e empréstimo devido\n");
                    printf("(3) Sacar conta corrente\n");
                    printf("(4) Sacar conta poupança\n");
                    printf("(5) Depositar conta corrente\n");
                    printf("(6) Depositar conta poupança\n");
                    printf("(7) Guardar dinheiro na poupança\n");
                    printf("(8) Resgatar da poupança\n");
                    printf("(9) Pedir empréstimo\n");
                    printf("(10) Pagar empréstimo\n");
                    printf("(11) Transferência\n");
                    printf("(12) Exibir contatos\n");
                    printf("(13) Adicionar contato\n");
                    scanf("%d", &funcao);

                    switch (funcao){
                    case 0:
                        logado = 0;
                        break;
                    case 1:
                        trocarSenha(conta);
                        break;
                    case 2:
                        mostrarSaldoContas(conta);
                        break;
                    case 3: 
                        sacarContaCorrente(conta);
                        break;
                    case 4:
                        sacarContaPoupanca(conta);
                        break;
                    case 5:
                        depositarContaCorrente(conta);
                        break;
                    case 6:
                        depositarContaPoupanca(conta);
                        break;
                    case 7:
                        moverCorrenteParaPoupanca(conta);
                        break;
                    case 8:
                        moverPoupancaParaCorrente(conta);
                        break;
                    case 9:
                        realizarEmprestimo(conta);
                        break;
                    case 10:
                        pagarEmprestimo(conta);
                        break;
                    case 11:
                        transferir(&listaContasBanco, conta);
                        break;
                    case 12:
                        exibirContatos(conta);
                        break;
                    case 13:
                        adicionarContato(&listaContasBanco, conta);
                        break;
                    default:
                        printf("Insira um número válido!\n");
                        break;
                    }
                }
            }
        } else {
            printf("Insira um comando válido!\n");
        }
    }
}