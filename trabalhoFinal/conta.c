#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conta {
    char nome[150];
    char cpf[150];
    char senha[150];
    double valorContaCorrente;
    double valorContaPoupanca;
    double valorEmprestimoDevido;
    
} conta;

conta* criarConta(){
    int criar=0;
    
    conta* conta;
    while(criar != 1){
        printf("Deseja cria uma nova conta?\nInsira (0) Sim e (1) Não.\n");
        scanf("%d", &criar);

        if(criar == 0){
            printf("Informe o nome completo:\n");
            getchar();
            fgets(conta->nome, 150, stdin);
            printf("Informe seu CPF:\n");
            fgets(conta->cpf, 150, stdin);
            printf("Crie uma senha:\n");
            fgets(conta->senha, 150, stdin);
            
            conta->valorContaCorrente = 0;
            conta->valorContaPoupanca = 0;
            conta->valorEmprestimoDevido = 0;

            printf("Conta criada com sucesso!\n");
            return conta;
        } else if(criar != 1){
            printf("Comando inválido.\n");
        }
    }   
    return conta; 
}

void logar(conta *conta){
    int login=0;

    while(login != 1){
        printf("Deseja logar em sua conta?\nInsira (0) Sim e (1) Não.\n");
        scanf("%d", &login);

        if(login == 0){
            printf("Insira o CPF:\n");
            fgets(conta->cpf, 150, stdin);
            printf("Insira a senha:\n");
            fgets(conta->senha, 150, stdin);
            return;
        } else if(login != 1){
            printf("Comando inválido.\n");
        }
    }
}

void trocarSenha(conta *conta){
    int troca=0;
    char novaSenha[150];
    
    while(troca != 1){
        printf("Deseja trocar a sua senha?\n Insira (0) Sim e (1) Não.\n");
        scanf("%d", &troca);
        
        if(troca == 0){
            getchar();
            printf("Insira sua senha atual:\n");
            fgets(conta->senha, 150, stdin);
            printf("Insira a nova senha: \n");
            fgets(novaSenha, 150, stdin);
            
            strcpy(conta->senha, novaSenha);
            printf("Senha cadastrada com sucesso!\n");
            return;
        } else if(troca != 1){
            printf("Comando inválido.\n");
        } 
    }    
}

void mostrarSaldoContas(conta *conta){
    double saldoCorrente;
    saldoCorrente = conta->valorContaCorrente;
    printf("O saldo da sua Conta Corrente é de: %2.lf\n", saldoCorrente);

    double saldoPoupanca;
    saldoPoupanca = conta->valorContaPoupanca;
    printf("O saldo da sua Conta Poupança é de: %2.lf\n", saldoPoupanca);
}

void sacarContaCorrente(conta *conta){
    double valorSaque;
    printf("Insira o valor que deseja sacar da sua conta corrente:\n");
    scanf("%lf", &valorSaque);

    if(valorSaque <= conta->valorContaCorrente){
        conta->valorContaCorrente = conta->valorContaCorrente - valorSaque;
        printf("Saque realizado com sucesso!\n");
        printf("O saldo atual das suas contas é de:\n");
        mostrarSaldoContas(conta);
    } else{
        printf("Não foi possível realizar essa operação. Saldo insuficiente.\n");
    }

}

void sacarContaPoupanca(conta *conta){
    double valorSaque;
    printf("Insira o valor que deseja sacar da sua conta poupança:\n");
    scanf("%lf", &valorSaque);

    if(valorSaque <= conta->valorContaPoupanca){
        conta->valorContaPoupanca = conta->valorContaPoupanca - valorSaque;
        printf("Saque realizado com sucesso!\n");
        printf("O saldo atual das suas contas é de:\n");
        mostrarSaldoContas(conta);
    } else{
        printf("Não foi possível realizar essa operação. Saldo insuficiente.\n");
    }
}

void depositarContaCorrente(conta *conta){
    double valorDepositoCorrente;
    printf("Insira o valor que deseja depositar em sua conta corrente:\n");
    scanf("%lf", &valorDepositoCorrente);

    conta->valorContaCorrente = conta->valorContaCorrente + valorDepositoCorrente;
    printf("Valor depositado com sucesso!\n");
    mostrarSaldoContas(conta);
}

void depositarContaPoupanca(conta *conta){
    double valorDepositoPoupanca;
    printf("Insira o valor que deseja depositar em sua conta poupança:\n");
    scanf("%lf", &valorDepositoPoupanca);

    conta->valorContaPoupanca = conta->valorContaPoupanca + valorDepositoPoupanca; 
    printf("Valor depositado com sucesso!\n");
    mostrarSaldoContas(conta);

}

void moverCorrenteParaPoupanca(conta *conta){
    double valorMovimentacao;
    printf("Insira o valor que deseja fazer a movimentação:\n");
    scanf("%lf", &valorMovimentacao);

    if(valorMovimentacao <= conta->valorContaCorrente){
        conta->valorContaCorrente -= valorMovimentacao;
        conta->valorContaPoupanca += valorMovimentacao;
        printf("Movimentação feita com sucesso!\n");
        mostrarSaldoContas(conta);
    } else{
        printf("Não foi possível realizar a operação. Saldo insuficiente.\n");
        mostrarSaldoContas(conta);
    }

}

void moverPoupancaParaCorrente(conta* conta){
    double valorMovimentacao;
    printf("Insira o valor que deseja fazer a movimentação:\n");
    scanf("%lf", &valorMovimentacao);
    
    if(valorMovimentacao <= conta->valorContaPoupanca){
        conta->valorContaPoupanca -= valorMovimentacao;
        conta->valorContaCorrente += valorMovimentacao;
        printf("Movimentação feita com sucesso!\n");
        mostrarSaldoContas(conta);
    } else{
        printf("Não foi possível realizar a operação. Saldo insuficiente.\n");
        mostrarSaldoContas(conta);
    }

}

void emprestimo(conta* conta){
    
    printf("Insira o valor que deseja fazer o empréstimo:\n");
    scanf("%lf", &conta->valorEmprestimoDevido);

    conta->valorContaCorrente += conta->valorEmprestimoDevido;

    printf("O valor devido é de: %2.lf\n", conta->valorEmprestimoDevido);
    
    mostrarSaldoContas(conta);
    
}

void pagarEmprestimo(conta *conta){
    double valorPagamentoEmprestimo;
    printf("Insira o valor que deseja liquidar da divida:\n");
    scanf("%lf", &valorPagamentoEmprestimo);

    printf("O valor pago do empréstimo é de: %2.lf\n", valorPagamentoEmprestimo);
   
    conta->valorContaCorrente = conta->valorContaCorrente - valorPagamentoEmprestimo;
    conta->valorEmprestimoDevido = conta->valorEmprestimoDevido - valorPagamentoEmprestimo;

    printf("O valor devido é de: %2.lf\n", conta->valorEmprestimoDevido);

    mostrarSaldoContas(conta);
}

void transferir(conta *contaOrigem){
    conta *contaDestino;
    double valorTransferencia;
    int transferencia=0;

    while(transferencia != 1){
        printf("Deseja fazer uma transferência? Digite (0) Sim e (1) Não. \n");
        scanf("%d", &transferencia);

        if(transferencia == 0){
        printf("Insira o valor que deseja transferir: \n");
        scanf("%lf", &valorTransferencia);

            if(contaOrigem->valorContaCorrente >= valorTransferencia ){
                contaDestino->valorContaCorrente = contaOrigem->valorContaCorrente - valorTransferencia;
                
            } else{
                printf("Não é possível fazer a transferência pois não há saldo suficiente!\n");
            }

        } else if(transferencia != 1){
            printf("Comando inválido.\n");
        }
    }
}

// Menu
// 1 - Criar uma nova conta OU logar
// 1.1 - Criar conta -> Informar o nome completo, cpf e senha
// 2.1 - Login -> Cpf + senha

// Saque e deposito
// Deve ser possivel sacar, depositar e mostrar saldo atual da conta corrente e poupança
// Tambem deve ser possivel guardar da poupança e resgatar da poupança.

// Emprestimos 
// PEgar e pagar o emprestimo. Sendo necessario salvar o emprestimo guardado

// Transferencias
// Sao sempre entre contas correntes
// Para transferir para outro usuario é necessario o nome completo OU CPF da pessoa
// Tambem Pode escolher alguem da lista de contatos para transferencias
// Antes da transferencia ocorrer, tera uma tela mostrando o nome e CPF do destinatario e a quantia para transferir. O usuario pode permitir ou cancelar a açao
// Quando o destinario fizer login, devera ter notificar uma vez das trasnferencias destinadas a ele e a quantia de cada transferencia

// Lista de contatos
// Adicionar, deletar e mostrar contatos
// Adicionar e deletar  atraves do nome completo ou CPF
// Mostrar contato sera em ordem alfabetica

// Trocar de senha
// A senha atual do usuário deve ser perguntada antes de trocar par a nova

// Exportacao e importar os dados.



int main(){

    conta contaTeste;

     strcpy(contaTeste.nome, "Daniel Karam");
     strcpy(contaTeste.cpf, "135.134.187-56");
     strcpy(contaTeste.senha , "Look Here");
     contaTeste.valorContaCorrente = 3000.00;
     contaTeste.valorContaPoupanca = 1000.00;
     contaTeste.valorEmprestimoDevido = 200.00;

    printf("%s\n" ,contaTeste.nome);
    printf("%s\n" ,contaTeste.cpf);
    printf("%s\n" ,contaTeste.senha);
    printf("%lf\n" ,contaTeste.valorContaCorrente);
    printf("%lf\n" ,contaTeste.valorContaPoupanca);
    printf("%lf\n" ,contaTeste.valorEmprestimoDevido);

    int logando, controle=1, funcao;
    while(logando != 1){
        printf("Deseja logar em sua conta? Insira (0) Sim. Não possui uma conta? Insira (1) para criar.\n");
        scanf("%d", &logando);

        if(logando == 1){
            criarConta;
        }else if(logando == 0){
            while(controle){
                printf("Escolha uma das opções abaixo:\n");
                printf("(0) Encerrar sessão\n");
                printf("(1) Trocar senha\n");
                printf("(2) Mostrar saldo conta corrente e conta poupança\n");
                printf("(3) Sacar conta corrente\n");
                printf("(4) Sacar conta poupança\n");
                printf("(5) Depositar conta corrente\n");
                printf("(6) Depositar conta poupança\n");
                printf("(7) Mover saldo conta corrente para conta poupança\n");
                printf("(8) Mover saldo conta poupança para conta corrente\n");
                printf("(9) Pedir empréstimo\n");
                printf("(10) Pagar empréstimo\n");
                printf("(11) Transferência\n");
                scanf("%d", &funcao);

                switch (funcao){
                case 0:
                    controle=0;
                    break;
                case 1:
                    trocarSenha(&contaTeste);
                    break;
                case 2:
                    mostrarSaldoContas(&contaTeste);
                    break;
                case 3: 
                    sacarContaCorrente(&contaTeste);
                    break;
                case 4:
                    sacarContaPoupanca(&contaTeste);
                    break;
                case 5:
                    depositarContaCorrente(&contaTeste);
                    break;
                case 6:
                    depositarContaPoupanca(&contaTeste);
                    break;
                case 7:
                    moverCorrenteParaPoupanca(&contaTeste);
                    break;
                case 8:
                    moverPoupancaParaCorrente(&contaTeste);
                    break;
                case 9:
                    emprestimo(&contaTeste);
                    break;
                case 10:
                    pagarEmprestimo(&contaTeste);
                    break;
                case 11:
                    transferir(&contaTeste);
                default:
                    printf("Insira um número válido!\n");
                    break;
                }
            } 
        } else if(logando != 1 || logando != 0){
            printf("Insira um comando válido!\n");
        }
    }

    // conta* contaTeste = criarConta();


     


    // trocarSenha(&contaTeste);

    // printf("%s\n" ,contaTeste.senha);

    // conta *conta1 = (conta*)malloc(sizeof(conta));

    // int controle = 1, funcao;

    // while(controle){
    //     printf("Escolha uma das opções abaixo:\n");
    //     printf("(0) Encerrar sessão\n");
    //     printf("(1) Criar uma nova conta\n");
    //     printf("(2) Logar numa conta já existente\n");
    //     printf("(3) Trocar senha\n");
    //     printf("(4) Sacar conta corrente\n");
    //     printf("(5) Sacar conta poupança\n");
    //     printf("(6) Depositar conta corrente\n");
    //     printf("(7) Depositar conta poupança\n");
    //     printf("(8) Mostrar saldo conta corrente e conta poupança\n");
    //     printf("(9) Mover saldo conta corrente para conta poupança\n");
    //     printf("(10) Mover saldo conta poupança para conta corrente\n");
    //     printf("(11) Pedir empréstimo\n");
    //     printf("(12) Pagar empréstimo\n");
    //     printf("(13) Transferência\n");
    //     scanf("%d", funcao);

    //     switch(funcao){
    //         case 0:
    //         controle = 0;
    //         break;
    //         case 1:
    //         criarConta ()

    //     }

    // }
  






    // conta1->cpf = 123456789;
    // conta1->senha = 4321;
    // conta1->valorContaCorrente = 1000.00;
    // conta1->valorContaPoupanca = 3000.00;

    // printf("Valor antes de sacar: %2.lf \n", conta1->valorContaCorrente);
    // sacarContaCorrente(conta1, 1000.00);
    // printf("Valor depois de sacar: %2.lf \n", conta1->valorContaCorrente);

    // printf("Valor antes de sacar: %2.lf \n", conta1->valorContaPoupanca);
    // sacarContaPoupanca(conta1, 1000.00);
    // printf("Valor depois de sacar: %2.lf \n", conta1->valorContaPoupanca);

    // printf("Valor antes de depositar: %2.lf \n", conta1->valorContaCorrente);
    // depositarContaCorrente(conta1, 1000.00);
    // printf("Valor depois de depositar: %2.lf \n", conta1->valorContaCorrente);

    //  printf("Valor antes de depositar: %2.lf \n", conta1->valorContaPoupanca);
    // depositarContaPoupanca(conta1, 1000.00);
    // printf("Valor depois de depositar: %2.lf \n", conta1->valorContaPoupanca);

    // mostrarSaldoContas(conta1);

    // moverCorrentePoupanca(conta1, 500.00);

    // moverPoupancaCorrente(conta1, 4000.00);



    // emprestimo(conta1);

    // pagarEmprestimo(conta1, 3000);

    // trocarSenha(conta1);


}