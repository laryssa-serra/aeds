#include "conta.h"

void iniciarListaTransferencias(ListaTransferencias *listaTransferencias, size_t tamanhoInicial) {
    listaTransferencias->transferencias = malloc(tamanhoInicial * sizeof(Transferencia));
    listaTransferencias->posicoes_usadas = 0;
    listaTransferencias->posicoes_totais = tamanhoInicial;
}

void inserirListaTransferencias(ListaTransferencias *listaTransferencias, Transferencia transferencia) {
    // Duplica o tamanho da array sempre que chega ao limite do tamanho
    if (listaTransferencias->posicoes_usadas == listaTransferencias->posicoes_totais) {
        listaTransferencias->posicoes_totais *= 2;
        listaTransferencias->transferencias = realloc(listaTransferencias->transferencias, listaTransferencias->posicoes_totais * sizeof(transferencia));
    }

    size_t posicaoAtualInsercao = listaTransferencias->posicoes_usadas++;

    strcpy(listaTransferencias->transferencias[posicaoAtualInsercao].nome, transferencia.nome);
    listaTransferencias->transferencias[posicaoAtualInsercao].valorTransferido = transferencia.valorTransferido;
}

void liberarListaTransferencias(ListaTransferencias *listaTransferencias) {
    free(listaTransferencias->transferencias);
    listaTransferencias->transferencias = NULL;
    listaTransferencias->posicoes_usadas = listaTransferencias->posicoes_totais = 0;
}

void iniciarListaContatos(ListaContatos *listaContatos, size_t tamanhoInicial) {
    listaContatos->contatos = malloc(tamanhoInicial * sizeof(Contato));
    listaContatos->posicoes_usadas = 0;
    listaContatos->posicoes_totais = tamanhoInicial;
}

void inserirListaContatos(ListaContatos *listaContatos, Contato contato) {
    // Duplica o tamanho da array sempre que chega ao limite do tamanho
    if (listaContatos->posicoes_usadas == listaContatos->posicoes_totais) {
        listaContatos->posicoes_totais *= 2;
        listaContatos->contatos = realloc(listaContatos->contatos, listaContatos->posicoes_totais * sizeof(contato));
    }

    size_t posicaoAtualInsercao = listaContatos->posicoes_usadas++;

    strcpy(listaContatos->contatos[posicaoAtualInsercao].nome, contato.nome);
}

void liberarListaContatos(ListaContatos *listaContatos) {
    free(listaContatos->contatos);
    listaContatos->contatos = NULL;
    listaContatos->posicoes_usadas = listaContatos->posicoes_totais = 0;
}

void iniciarListaContas(ListaContas *listaContas, size_t tamanhoInicial) {
    listaContas->conta = malloc(tamanhoInicial * sizeof(Conta));
    listaContas->posicoes_usadas = 0;
    listaContas->posicoes_totais = tamanhoInicial;
}

void inserirListaContas(ListaContas *listaContas, Conta conta) {
    // Duplica o tamanho da array sempre que chega ao limite do tamanho
    if (listaContas->posicoes_usadas == listaContas->posicoes_totais) {
        listaContas->posicoes_totais *= 2;
        listaContas->conta = realloc(listaContas->conta, listaContas->posicoes_totais * sizeof(conta));
    }

    size_t posicaoAtualInsercao = listaContas->posicoes_usadas++;

    strcpy(listaContas->conta[posicaoAtualInsercao].nome, conta.nome);
    strcpy(listaContas->conta[posicaoAtualInsercao].cpf, conta.cpf);
    strcpy(listaContas->conta[posicaoAtualInsercao].senha, conta.senha);
    listaContas->conta[posicaoAtualInsercao].valorContaCorrente = conta.valorContaCorrente;
    listaContas->conta[posicaoAtualInsercao].valorContaPoupanca = conta.valorContaPoupanca;
    listaContas->conta[posicaoAtualInsercao].valorEmprestimoDevido = conta.valorEmprestimoDevido;
    listaContas->conta[posicaoAtualInsercao].listaTransferencias = conta.listaTransferencias;
    listaContas->conta[posicaoAtualInsercao].listaContatos = conta.listaContatos;
}

void liberarListaContas(ListaContas *listaContas) {
    free(listaContas->conta);
    listaContas->conta = NULL;
    listaContas->posicoes_usadas = listaContas->posicoes_totais = 0;
}

Conta* buscarListaContas(ListaContas *listaContas, char *nomeOuCpf) {
    for(int i = 0; i < listaContas->posicoes_usadas; i++){
        if(strcmp(listaContas->conta[i].cpf, nomeOuCpf) == 0 || strcmp(listaContas->conta[i].nome, nomeOuCpf) == 0){
            return &listaContas->conta[i];
        } 
    }

    return NULL;
}

Conta criarConta(){   
    Conta conta;
 
    getchar();
    
    printf("Informe o nome completo: ");
    fgets(conta.nome, 50, stdin);
    conta.nome[strcspn(conta.nome, "\n")] = 0;
    
    printf("Informe seu CPF: ");
    fgets(conta.cpf, 20, stdin);
    conta.cpf[strcspn(conta.cpf, "\n")] = 0;
    
    printf("Crie uma senha: ");
    fgets(conta.senha, 50, stdin);
    conta.senha[strcspn(conta.senha, "\n")] = 0;
    
    conta.valorContaCorrente = 0;
    conta.valorContaPoupanca = 0;
    conta.valorEmprestimoDevido = 0;
    iniciarListaTransferencias(&conta.listaTransferencias, 1);
    iniciarListaContatos(&conta.listaContatos, 1);

    printf("Conta criada com sucesso!\n");
    return conta;
}

void trocarSenha(Conta *conta){
    char senhaAtual[50], novaSenha[50];

    getchar();
    
    printf("Insira sua senha atual: ");
    fgets(senhaAtual, 50, stdin);
    senhaAtual[strcspn(senhaAtual, "\n")] = 0;
    
    if(strcmp(conta->senha, senhaAtual) != 0){
        printf("Esta NÃO é a senha da conta logada!\n");
        return;
    }

    printf("Insira a nova senha: ");
    fgets(novaSenha, 50, stdin);
    novaSenha[strcspn(novaSenha, "\n")] = 0;

    strcpy(conta->senha, novaSenha);
    printf("Senha cadastrada com sucesso!\n");    
}

void mostrarSaldoContaCorrente(Conta *conta){
    printf("O saldo da sua conta corrente é: %.2lf\n", conta->valorContaCorrente);
}

void mostrarSaldoContaPoupanca(Conta *conta){
    printf("O saldo da sua conta poupança é: %.2lf\n", conta->valorContaPoupanca);
}

void mostrarEmprestimoDevido(Conta *conta){
    printf("O valor total de empréstimo devido é de: %.2lf\n", conta->valorEmprestimoDevido);
}

void mostrarSaldoContas(Conta *conta){
    mostrarSaldoContaCorrente(conta);
    mostrarSaldoContaPoupanca(conta);
    mostrarEmprestimoDevido(conta);
}

void sacarContaCorrente(Conta *conta){
    double valorSaque;
    
    printf("Disponível em sua conta corrente atual: %.2lf\n", conta->valorContaCorrente);
    printf("Insira o valor que deseja sacar da sua conta corrente: ");
    scanf("%lf", &valorSaque);

    if(valorSaque <= conta->valorContaCorrente){
        conta->valorContaCorrente = conta->valorContaCorrente - valorSaque;
        printf("Saque realizado com sucesso!\n");
        mostrarSaldoContaCorrente(conta);
    } else{
        printf("Não foi possível realizar essa operação. Saldo insuficiente.\n");
    }

}

void sacarContaPoupanca(Conta *conta){
    double valorSaque;

    printf("Disponível em sua conta poupança atual: %.2lf\n", conta->valorContaPoupanca);
    printf("Insira o valor que deseja sacar da sua conta poupança: ");
    scanf("%lf", &valorSaque);

    if(valorSaque <= conta->valorContaPoupanca){
        conta->valorContaPoupanca = conta->valorContaPoupanca - valorSaque;
        printf("Saque realizado com sucesso!\n");
        mostrarSaldoContaPoupanca(conta);
    } else{
        printf("Não foi possível realizar essa operação. Saldo insuficiente.\n");
    }
}

void depositarContaCorrente(Conta *conta){
    double valorDepositoCorrente;
    
    printf("Disponível em sua conta corrente atual: %.2lf\n", conta->valorContaCorrente);
    printf("Insira o valor que deseja depositar em sua conta corrente:\n");
    scanf("%lf", &valorDepositoCorrente);

    conta->valorContaCorrente = conta->valorContaCorrente + valorDepositoCorrente;
    printf("Valor depositado com sucesso!\n");
    mostrarSaldoContaCorrente(conta);
}

void depositarContaPoupanca(Conta *conta){
    double valorDepositoPoupanca;
    
    printf("Disponível em sua conta poupança atual: %.2lf\n", conta->valorContaPoupanca);
    printf("Insira o valor que deseja depositar em sua conta poupança:\n");
    scanf("%lf", &valorDepositoPoupanca);

    conta->valorContaPoupanca = conta->valorContaPoupanca + valorDepositoPoupanca; 
    printf("Valor depositado com sucesso!\n");
    mostrarSaldoContaPoupanca(conta);
}

void moverCorrenteParaPoupanca(Conta *conta){
    double valorMovimentacao;
    
    mostrarSaldoContas(conta);
    printf("Insira o valor que deseja mover da conta corrente para a conta poupança: ");
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

void moverPoupancaParaCorrente(Conta* conta){
    double valorMovimentacao;
    
    mostrarSaldoContas(conta);
    printf("Insira o valor que deseja mover da conta poupança para a conta corrente: ");
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

void realizarEmprestimo(Conta* conta){
    double valorEmprestimo;
    
    mostrarSaldoContaCorrente(conta);
    mostrarEmprestimoDevido(conta);
    
    printf("Insira o valor que deseja pegar de empréstimo: ");
    scanf("%lf", &valorEmprestimo);

    conta->valorContaCorrente += valorEmprestimo;
    conta->valorEmprestimoDevido += valorEmprestimo;

    mostrarSaldoContaCorrente(conta);
    mostrarEmprestimoDevido(conta);
}

void pagarEmprestimo(Conta *conta){
    double valorPagamentoEmprestimo;

    mostrarSaldoContaCorrente(conta);
    mostrarEmprestimoDevido(conta);

    printf("Insira o valor que deseja liquidar da divida: ");
    scanf("%lf", &valorPagamentoEmprestimo);
   
    conta->valorContaCorrente = conta->valorContaCorrente - valorPagamentoEmprestimo;
    conta->valorEmprestimoDevido = conta->valorEmprestimoDevido - valorPagamentoEmprestimo;

    mostrarSaldoContaCorrente(conta);
    mostrarEmprestimoDevido(conta);
}

void exibirContatos(Conta *conta){
    char lista_temp[conta->listaContatos.posicoes_usadas][50];
    char temp[50];
    
    // Cria lista temporaria
    for (int i = 0; i < conta->listaContatos.posicoes_usadas; i++){
        strcpy(lista_temp[i], conta->listaContatos.contatos[i].nome);
    }

    // Ordena lista temporaria
    for(int i=0; i<conta->listaContatos.posicoes_usadas; i++){
        for(int j=0; j<conta->listaContatos.posicoes_usadas-1-i; j++){
            if(strcmp(lista_temp[j], lista_temp[j+1]) > 0){
                strcpy(temp, lista_temp[j]);
                strcpy(lista_temp[j], lista_temp[j+1]);
                strcpy(lista_temp[j+1], temp);
            }
        }
    }

    // Reescreve os valores da lista de contatos da conta
    for (int i = 0; i < conta->listaContatos.posicoes_usadas; i++){
        strcpy(conta->listaContatos.contatos[i].nome, lista_temp[i]);
    }

    // Imprime a lista de contatos de forma ordenada
    printf("\n");
    for (int i = 0; i < conta->listaContatos.posicoes_usadas; i++){
        printf("(%d) %s\n", i, conta->listaContatos.contatos[i].nome);
    }
}

void transferir(ListaContas *listaContas, Conta *contaOrigem){
    Conta *contaDestino;
    double valorTransferencia;
    char nomeOuCpf[50];
    int confirmarTransferencia = 0, opcao = 0, numeroListaContato = 0;
    
    printf("Deseja realizar a transferencia a partir da lista de contatos ou digitar o nome/cpf? (1)Lista de contatos (2)Digitar nome ou CPF: ");
    scanf("%d", &opcao);
    if (opcao == 1){
        exibirContatos(contaOrigem);
        scanf("%d", &numeroListaContato);

        strcpy(nomeOuCpf, contaOrigem->listaContatos.contatos[numeroListaContato].nome);
        
        contaDestino = buscarListaContas(listaContas, nomeOuCpf);
    } else if(opcao == 2) {
        getchar();
        printf("Insira o nome ou cpf da conta destino de transferência: ");
        fgets(nomeOuCpf, 50, stdin);
        nomeOuCpf[strcspn(nomeOuCpf, "\n")] = 0;

        contaDestino = buscarListaContas(listaContas, nomeOuCpf);
    } else {
        printf("Opcao inválida");
        return;
    }

    if(contaDestino == NULL){
        printf("Conta destino NÃO encontrada!");
        return;
    } else {
        mostrarSaldoContaCorrente(contaOrigem);
        printf("Insira o valor que deseja transferir: ");
        scanf("%lf", &valorTransferencia);

        if(contaOrigem->valorContaCorrente >= valorTransferencia){
            printf("Você tem certeza que deseja transferir %.2lf para %s com cpf %s? (1)Sim (0)Não: ", valorTransferencia, contaDestino->nome, contaDestino->cpf);
            scanf("%d", &confirmarTransferencia);

            if(confirmarTransferencia == 1){
                contaOrigem->valorContaCorrente -= valorTransferencia;
                contaDestino->valorContaCorrente += valorTransferencia;
                
                Transferencia transferencia;
                strcpy(transferencia.nome, contaOrigem->nome);
                transferencia.valorTransferido = valorTransferencia;

                inserirListaTransferencias(&contaDestino->listaTransferencias, transferencia);
                
                printf("Transferência executada com sucesso!\n");
            } else {
                printf("Transferência cancelada!\n");
            }
        } else{
            printf("Não é possível fazer a transferência pois não há saldo suficiente!\n");
        }
    }
}

void verificaTransferencias(Conta *conta){
    if(conta->listaTransferencias.posicoes_usadas == 0){
        return;
    } else {
        printf("\n");
        for(int i = 0; i < conta->listaTransferencias.posicoes_usadas; i++){
            printf("%s transferiu %.2lf\n", conta->listaTransferencias.transferencias[i].nome, conta->listaTransferencias.transferencias[i].valorTransferido);
        }
        liberarListaTransferencias(&conta->listaTransferencias);
    }
}

void adicionarContato(ListaContas *listaContasBanco, Conta *conta){
    char nomeOuCpf[50];
    Conta *contaDestino;
    Contato contatoParaAdicionar;

    getchar();
    printf("Diga o nome ou cpf do contato que deseja adicionar: ");
    fgets(nomeOuCpf, 50, stdin);
    nomeOuCpf[strcspn(nomeOuCpf, "\n")] = 0;

    contaDestino = buscarListaContas(listaContasBanco, nomeOuCpf);

    if(contaDestino == NULL){
        printf("Esta conta não existe neste banco!\n");
        return;
    } else {
        strcpy(contatoParaAdicionar.nome, contaDestino->nome);
        inserirListaContatos(&conta->listaContatos, contatoParaAdicionar);
        printf("Contato adicionado com sucesso!\n");
    }
}