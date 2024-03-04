#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CADASTROS 200


    // Função cabeçalho
void cabecalho() {
printf(" ________                     ________        __    __       ________       ___   __        ________         _______         _______  \n");
printf("/      / |                   /        |      /  |  /  |     /        |     /  /  /  |      /        |       /      /|       /      / \n");
printf("/$$$$$$  |                   $$$$$$$$/       $$ |  |$$|     $$$$$$$$/      $$  / $$ |      $$$$$$$$/       /$$$$$$  |      /$$$$$$ |\n");
printf("$$ |  $$/        _____       $$ |__          $$ |  |$$|     $$ |__         $$$  /$$ |         $$ |         $$ |  $$ |      $$ /__$$/ \n");
printf("$$ |            /     |      $$    |         $$ |  /$$/     $$    |        $$$$  $$ |         $$ |         $$ |  $$ |      $$      / \n");
printf("$$ |   __       $$$$$$/      $$$$$/           $$ \\/$$/      $$$$$/         $$ $$ $$ |         $$ |         $$ |  $$ |      $$$$$$  |\n");
printf("$$ /__|  |                   $$ |_____         $$ $$/       $$ |____       $$ |$$$$ |         $$ |         $$ /__$$ |      /   /$$ |\n");
printf("$$    $$/                    $$       |         $$$/        $$      |      $$ | $$$ |         $$ |         $$    $$/       $$    $$/ \n");
printf("$$$$$$/                      $$$$$$$$/           $/         $$$$$$$/       $$/   $$/          $$/           $$$$$$/         $$$$$$/  \n");
}
   
    
    // Struct para as variaveis do cadastro
struct Cadastro {
    char nome[100];
    char cpf[12];
    char telefone[20];
    int estudante;
    char email[100];
};

    // Strucut para declaração dos valores
struct Valores{
    float valor_vip; 
    float valor_arquibancada;
    float valor_pista;
    float valor_skank;
    float valor_fagner;
    float valor_jorge;
    float valor_total;
};

// Variavel global para os valores
    struct Cadastro c;
    struct Valores v;
    char email[50];
    
    // Função para venda de ingressos
void Menu_shows(){
    int opcao, opcao_skank, opcao_fagner, opcao_jorge, quantidade = 0;
    float precos[3][3] = {{200.00, 100.00, 50.00}, {250.00, 150.00, 100.00}, {300.00, 200.00, 150.00}};
    
    printf("\n\nVocê é estudante?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    
	do {
        printf("Digite a opção: ");
        scanf("%d", &c.estudante);

        if (c.estudante != 1 && c.estudante != 2) {
            printf("Opção inválida. Por favor, digite novamente.\n");
        }
    } while (c.estudante != 1 && c.estudante != 2);
	
    if (c.estudante == 1) {
        printf("========================================\n\n\n");
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                precos[i][j] = precos[i][j] / 2;
            }
        }
    } else {
        printf("\n========================================\n\n\n");
    }

    system("cls");

    printf("\n \t\t\t Bem-vindo à venda de ingressos do C-EVENTOS!\n");

    if (c.estudante == 1) {
    printf("\n======================DESCONTO=================================");
    printf("\nJá que você é estudante, você tem direito a 50%% de desconto\n");
    printf("===============================================================\n");
    }
    
    // Loop para o usuario escolher qual show deseja
    do{
        printf("\n===== VENDA DE INGRESSOS =====\n");
        printf("1. Skank\n");
        printf("2. Fagner\n");
        printf("3. Jorge e Matheus\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        
        switch (opcao) {
            case 1:
                // loop para que o usuario escolher qual tipo de ingresso deseja
                do {
                    printf("\n==== INGRESSOS SKANK ====\n");
                    printf("1. VIP (R$%.2f)\n", precos[0][0]);
                    printf("2. Arquibancada (R$%.2f)\n", precos[0][1]);
                    printf("3. Pista (R$%.2f)\n", precos[0][2]);
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_skank);
                    
                    // Escolha dos ingressos
                    switch (opcao_skank) {
                        case 1:
                            v.valor_vip = 0;
                            printf("\nIngresso VIP para o show do Skank selecionado. \nPreço: R$ %.2f\n", precos[0][0]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_vip = precos[0][0] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_vip);
                            break;
                        case 2:
                            v.valor_arquibancada = 0;
                            printf("\nIngresso arquibancada para o show do Skank selecionado. \nPreço: R$ %.2f\n", precos[0][1]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_arquibancada = precos[0][1] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_arquibancada);
                            break;
                        case 3:
                            v.valor_pista = 0;
                            printf("\nIngresso pista para o show do Skank selecionado. \nPreço: R$ %.2f\n", precos[0][2]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_pista = precos[0][2] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_pista);
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpção inválida! Tente novamente.\n");
                            break;
                    }
                } while (opcao_skank != 0);
                break;
            case 2:
            // loop para que o usuario escolher qual tipo de ingresso deseja
                do {
                    printf("\n==== INGRESSOS FAGNER ====\n");
                    printf("1. VIP (R$%.2f)\n", precos[1][0]);
                    printf("2. Arquibancada (R$%.2f)\n", precos[1][1]);
                    printf("3. Pista (R$%.2f)\n", precos[1][2]);
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_fagner);
                    
                    // Escolha dos ingressos
                    switch (opcao_fagner) {
                        case 1:
                            v.valor_vip = 0;
                            printf("\nIngresso VIP para o show do Fagner selecionado. \nPreço: R$ %.2f\n", precos[1][0]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_vip = precos[1][0] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_vip);
                            break;
                        case 2:
                            v.valor_arquibancada = 0;
                            printf("\nIngresso arquibancada para o show do Fagner selecionado. \nPreço: R$ %.2f\n", precos[1][1]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_arquibancada = precos[1][1] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_arquibancada);
                            break;
                        case 3:
                            v.valor_pista = 0;
                            printf("\nIngresso pista para o show do Fagner selecionado. \nPreço: R$ %.2f\n", precos[1][2]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_pista = precos[1][2] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_pista);
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpção inválida! Tente novamente.\n");
                            break;
                    }
                } while (opcao_fagner != 0);
                break;
            case 3:
            // loop para que o usuario escolher qual tipo de ingresso deseja
                do {
                    printf("\n==== INGRESSOS JORGE E MATHEUS ====\n");
                    printf("1. VIP (R$%.2f)\n", precos[2][0]);
                    printf("2. Arquibancada (R$%.2f)\n", precos[2][1]);
                    printf("3. Pista (R$%.2f)\n", precos[2][2]);
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_jorge);
                    
                    // Escolha dos ingressos
                    switch (opcao_jorge) {
                        case 1:
                            v.valor_vip = 0;
                            printf("\nIngresso VIP para o show de Jorge e Matheus selecionado. \nPreço: R$ %.2f\n", precos[2][0]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_vip = precos[2][0] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_vip);
                            break;
                        case 2:
                            v.valor_arquibancada = 0;
                            printf("\nIngresso arquibancada para o show de Jorge e Matheus selecionado. \nPreço: R$ %.2f\n", precos[2][1]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_arquibancada = precos[2][1] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_arquibancada);
                            break;
                        case 3:
                            v.valor_pista = 0;
                            printf("\nIngresso pista para o show de Jorge e Matheus selecionado. \nPreço: R$ %.2f\n", precos[2][2]);
                            printf("Digite a quantidade de ingressos que deseja comprar: ");
                            scanf("%d", &quantidade);
                            v.valor_pista = precos[2][2] * quantidade;
                            printf("\nCompra adicionada ao carrinho com sucesso!");
                            printf("\nValor adicionado ao carrinho: R$ %.2f\n", v.valor_pista);
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpção inválida! Tente novamente.\n");
                            break;
                    }
                } while (opcao_jorge != 0);
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        v.valor_total = v.valor_vip + v.valor_arquibancada + v.valor_pista;

    } while (opcao != 0);
}
 
    // Função para forma de pagamento
void Menu_pagamento() {
    int opcao_pagamento, opcao_parcelamento;

    printf("\n===============PAGAMENTO===============");
    printf("\nValor total da compra: R$ %.2f", v.valor_total);

    do{
        printf("\nSelecione a forma de pagamento:\n");
        printf("1. PIX\n");
        printf("2. Cartão de Débito\n");
        printf("3. Cartão de Crédito\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao_pagamento);
        
        switch(opcao_pagamento){
            case 1:
                printf("\nForma de pagamento escolhida: PIX.\n");
                printf("Valor total da compra: R$ %.2f", v.valor_total);
                break;
            case 2:
                printf("\nForma de pagamento escolhida: Cartão de Débito.\n");
                printf("Valor total da compra: R$ %.2f", v.valor_total);
                break;
            case 3:
                printf("\nForma de pagamento escolhida: Cartão de Crédito.\n");
                printf("Valor total da compra: R$%.2f\n", v.valor_total);
                
                if(v.valor_total >= 500){
                    printf("\nPara compras com valores acima de R$ 500,00 parcelamos em até 4 vezes.\n");
                    printf("Escolha o número de parcelas: \n");
                    printf("1 vez de R$ %.2f\n", v.valor_total);
                    printf("2 vezes de R$ %.2f\n", ((v.valor_total * 0.05) + v.valor_total) / 2);
                    printf("3 vezes de R$ %.2f\n", ((v.valor_total * 0.10) + v.valor_total) / 3);
                    printf("4 vezes de R$ %.2f\n", ((v.valor_total * 0.15) + v.valor_total) / 4);
                    printf("Digite a opção desejada: ");
                    scanf("%d", &opcao_parcelamento);
                    
                    while(opcao_parcelamento < 1 || opcao_parcelamento > 4){
                        printf("Opção inválida. Digite uma opção válida: ");
                        scanf("%d", &opcao_parcelamento);
                    }
                }
                
                if(opcao_parcelamento == 1){
                    printf("\nValor total da compra: 1 vez de R$ %.2f\n", v.valor_total);
                } else if (opcao_parcelamento == 2){
                    printf("\nValor total da compra: 2 vezes de R$ %.2f\n", ((v.valor_total * 0.05) + v.valor_total) / 2);
                } else if (opcao_parcelamento == 3){
                    printf("\nValor total da compra: 3 vezes de R$ %.2f\n", ((v.valor_total * 0.10) + v.valor_total) / 3);
                } else if (opcao_parcelamento == 4){
                    printf("\nValor total da compra: 4 vezes de R$ %.2f\n", ((v.valor_total * 0.15) + v.valor_total) / 4);
                } else if (opcao_parcelamento < 1 || opcao_parcelamento > 4){
                    printf("Opção inválida. Digite uma opção válida: \n");
                }

                printf("Obrigado por comprar!");
                break;
            default:
                printf("Opção inválida. Digite uma opção válida.\n");
        }
    } while (opcao_pagamento < 1 || opcao_pagamento > 3);
}

void Nota_fiscal(const struct Cadastro* c, const char* email, float valor_total) {
    printf("\n\n\n--------------------- NOTA FISCAL -------------------------------\n");
    printf("\n\t\t\t C-EVENTOS\n\n");
    printf("Nome: %s\n", c->nome);
    printf("E-mail: %s\n", email);
    printf("CPF: %s\n", c->cpf);
    printf("Telefone: %s\n", c->telefone);
    printf("Valor total da compra: %.2f\n", valor_total);
    printf("-----------------------------------------------------------------\n");
}

void salvarCSV(const struct Cadastro c[], int tamanho) {
    FILE* arquivo = fopen("dados.csv", "w");
    // Abre o arquivo "dados.csv" no modo de escrita ("w")

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

	  if (ftell(arquivo) == 0) {  // Verifica se o arquivo está vazio
        fprintf(arquivo, "Nome,Email,CPF,Telefone,  \n");
    }
	// Se o arquivo estiver vazio, escreve o cabeçalho com os nomes das colunas

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s,%s,%s,%s\n", c[i].nome, c[i].email, c[i].cpf, c[i].telefone);
    }
	// Escreve os dados do array de estruturas no arquivo, separados por vírgulas

    fclose(arquivo);
    

    printf("Arquivo CSV salvo com sucesso.\n");
}


void lerCSV(struct Cadastro c[], int* tamanho) {
    FILE* arquivo = fopen("dados.csv", "r");
    // Abre o arquivo "dados.csv" no modo de leitura ("r")

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    *tamanho = 0;

    fgets(linha, 200, arquivo);
    // Lê a primeira linha do arquivo (cabeçalho) e descarta

    while (fgets(linha, 200, arquivo) != NULL) {
        char* token = strtok(linha, ",");
        // Divide a linha em tokens, usando a vírgula como delimitador


        if (token == NULL) {
            continue;
        }

        strcpy(c[*tamanho].nome, token);
        // Copia o token para o campo 'nome' da estrutura 'Cadastro'
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(c[*tamanho].email, token);
        // Copia o token para o campo 'email' da estrutura 'Cadastro'
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(c[*tamanho].cpf, token);
        // Copia o token para o campo 'cpf' da estrutura 'Cadastro'
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(c[*tamanho].telefone, token);
        // Copia o token para o campo 'telefone' da estrutura 'Cadastro'
       
        token = strtok(NULL, ",");

        (*tamanho)++;
    }

    fclose(arquivo);
}

void imprimirPessoas() {
    FILE *arquivo;
    char linha[100];

    // Abrir o arquivo em modo de leitura
    arquivo = fopen("dados.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ler cada linha do arquivo e imprimir na tela
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
        
    }

    // Fechar o arquivo
    fclose(arquivo);
}

int main() {
    setlocale(LC_ALL, "");

    struct Cadastro c[200];
    int op, tamanho = 0;
    int tipoUsuario;
    char email[100];
	FILE* arquivo;
    
    printf("1 - Administrador\n");
    printf("2 - Usuário comum\n");
    printf("Digite o tipo de usuário: ");
    scanf("%d", &tipoUsuario);

    if (tipoUsuario == 1) {
        do {
        	lerCSV(c, &tamanho); 
            system("cls");
            printf("Digite uma opção: \n1 - Listar Cadastros\n2 - Excluir Cadastro\n3 - Alterar Cadastro\n4 - Sair\n\nEscolha: ");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    system("cls");
                    imprimirPessoas(c, tamanho);
                    system("pause");
                    break;
               	case 2:
    system("cls");
    lerCSV(c, &tamanho);
    printf("Digite o email do cadastro a ser excluído: ");
    char email[100];
    scanf(" %[^\n]s", email);

    int encontrado = 0; // Variável para acompanhar se o cadastro foi encontrado

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(email, c[i].email) == 0) {
            for (int j = i; j < tamanho - 1; j++) {
                c[j] = c[j + 1];
            }
            tamanho--;
            encontrado = 1; // Marcamos que o cadastro foi encontrado
            printf("Cadastro excluído com sucesso!\n");
            salvarCSV(c, tamanho);
            break;
        }
    }

    if (encontrado == 0) {
        printf("Cadastro não encontrado.\n");
    }
    system("pause");
    break;

                case 3:
    lerCSV(c, &tamanho);
    printf("Digite o email do cadastro a ser alterado: ");
    scanf(" %[^\n]s", email);
    
    int emailEncontrado = 0;  // Variável para controlar se o email foi encontrado (0 = false, 1 = true)

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(email, c[i].email) == 0) {
            emailEncontrado = 1;  // Marcar que o email foi encontrado
            int opcao;
            printf("\nEscolha o campo a ser alterado:\n");
            printf("1 - Nome\n");
            printf("2 - CPF\n");
            printf("3 - Telefone\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 1:
                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]s", c[i].nome);
                    printf("Nome alterado com sucesso!\n");
                    break;
                case 2:
                    printf("Digite o novo CPF: ");
                    scanf("%s", c[i].cpf);
                    printf("CPF alterado com sucesso!\n");
                    break;
                case 3:
                    printf("Digite o novo telefone: ");
                    scanf(" %[^\n]s", c[i].telefone);
                    printf("Telefone alterado com sucesso!\n");
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }
            
            salvarCSV(c, tamanho);
            break;
        }
    }

    if (emailEncontrado == 0) {
        printf("Email não cadastrado!\n");  // Mostrar mensagem de email não cadastrado
    }
    
    system("pause");
    break;
                case 4:
                    salvarCSV(c, tamanho);
                    break;
            }
        } while (op != 4);
    } else if (tipoUsuario == 2) {
        lerCSV(c, &tamanho);  // Mover a chamada da função lerCSV para antes do bloco if
		
		system("cls");
		cabecalho();
		
        printf("\nDigite seu email: ");
        scanf("%s", email);

        int cadastrado = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(email, c[i].email) == 0) {
                cadastrado = 1;
                printf(c[i].email);
                printf("E-mail já cadastrado no sistema!\n");
                printf("Já podemos dar início à compra de ingressos!\n");
                Menu_shows();
                Menu_pagamento();
                Nota_fiscal(&c[i], email, v.valor_total); // Valor total da compra deve ser passado como argumento
                break;
            }
        }

        if (!cadastrado) {
            printf("E-mail ainda não cadastrado!\n");
            printf("Vamos fazer o cadastro para que você possa iniciar sua compra de ingressos!\n");
            printf("Digite o seu nome: ");
            fflush(stdin);
            scanf(" %[^\n]s", c[tamanho].nome);
            printf("Digite o seu CPF: ");
            fflush(stdin);
            scanf("%s", c[tamanho].cpf);
            printf("Digite o seu telefone: ");
            fflush(stdin);
            scanf(" %[^\n]s", c[tamanho].telefone);
            strcpy(c[tamanho].email, email);
            tamanho++;
            printf("Cadastro realizado com sucesso!\n");
            salvarCSV(c, tamanho);
            Menu_shows();
            Menu_pagamento();
            Nota_fiscal(&c[tamanho - 1], email, v.valor_total); // Valor total da compra deve ser passado como argumento
        }
    }

    system("pause");
    return 0;
}