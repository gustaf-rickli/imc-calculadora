#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <locale.h>
#include <windows.h>

#define MAX_CLIENTES 100
#define ARQUIVO_HISTORICO "historico_imc.txt"

//PREDEFINIÇÃO
#define RESET   "\033[0m"
//TEXTO INVISÍVEL
#define INV  "\033[8m"       

//DESTAQUE FORTE
#define DEST  "\033[1m"

//SEM DESTAQUE FORTE
#define SDEST "\033[22m"

//COR DOS TITULOS 1
#define COR_T "\033[37m"

//COR PESO
#define COR_E_P "\033[44m"
#define COR_P "\033[37m"
#define PDEST  "\033[1m"

//COR ALTURA
#define COR_E_A "\033[104m"
#define COR_A "\033[37m"
#define ADEST  "\033[1m"


//COR LINHA TABELA (reduzida) 1 
#define COR_L "\033[37m"
#define COR_E_L "\033[40m"
#define DESTL  "\033[1m"


//COR DO TEXTO 1
#define COR_1 "\033[37m"
#define COR_2 "\033[37m"
#define COR_3 "\033[37m"
#define COR_4 "\033[37m"
#define COR_5 "\033[37m"
#define COR_6 "\033[30m"
#define COR_7 "\033[31m"


// DESTAQUES DO TEXTO 1
#define DEST1  "\033[1m"
#define DEST2  "\033[1m"
#define DEST3  "\033[1m"
#define DEST4  "\033[1m"
#define DEST5  "\033[1m"
#define DEST6  "\033[22m"
#define DEST7  "\033[22m"

//COR DO FUNDO 1
#define COR_E_1 "\033[101m"   // vermelho brilhante
#define COR_E_2 "\033[43m"    // amarelo
#define COR_E_3 "\033[42m"    // verde
#define COR_E_4 "\033[43m"    // amarelo
#define COR_E_5 "\033[101m"   // vermelho brilhante
#define COR_E_6 "\033[41m"    // vermelho
#define COR_E_7 "\033[40m"    // preto 

typedef struct {
    char nome[50];
    char sexo; // 'M' ou 'F'
    float peso;
    float altura;
    float imc;
    char classificacao[50];
} Cliente;

Cliente historico[MAX_CLIENTES];
int totalClientes = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float lerFloatPositivo(char *mensagem) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        limparBuffer();
        if (valor <= 0) {
            printf("Valor inválido! Digite um número positivo.\n");
        }
    } while (valor <= 0);
    return valor;
}

void calcularIMC(Cliente *cliente) {
    cliente->imc = cliente->peso / (cliente->altura * cliente->altura);
    
    if (cliente->sexo == 'M' || cliente->sexo == 'm') {
        if (cliente->imc < 20.7) strcpy(cliente->classificacao, "Abaixo do peso");
        else if (cliente->imc < 26.4) strcpy(cliente->classificacao, "Peso normal");
        else if (cliente->imc < 27.8) strcpy(cliente->classificacao, "Marginalmente acima do peso");
        else if (cliente->imc < 31.1) strcpy(cliente->classificacao, "Acima do peso ideal");
        else strcpy(cliente->classificacao, "Obeso");
    } else {
        if (cliente->imc < 19.1) strcpy(cliente->classificacao, "Abaixo do peso");
        else if (cliente->imc < 25.8) strcpy(cliente->classificacao, "Peso normal");
        else if (cliente->imc < 27.3) strcpy(cliente->classificacao, "Marginalmente acima do peso");
        else if (cliente->imc < 32.3) strcpy(cliente->classificacao, "Acima do peso ideal");
        else strcpy(cliente->classificacao, "Obeso");
    }
}

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }
    
    Cliente novo;
    
    printf("\n--- Cadastro de Cliente ---\n");
    
    printf("Nome: ");
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // Remove o \n
    
    do {
        printf("Sexo (M/F): ");
        scanf(" %c", &novo.sexo);
        limparBuffer();
        novo.sexo = toupper(novo.sexo);
        if (novo.sexo != 'M' && novo.sexo != 'F') {
            printf("Sexo inválido! Digite M ou F.\n");
        }
    } while (novo.sexo != 'M' && novo.sexo != 'F');
    
    novo.peso = lerFloatPositivo("Peso (kg): ");
    novo.altura = lerFloatPositivo("Altura (m): ");
    
    calcularIMC(&novo);
    
    historico[totalClientes++] = novo;
    
    printf("\nIMC calculado: %.2f - %s\n", novo.imc, novo.classificacao);
}

void listarHistorico() {
    printf("\n--- Histórico de Clientes ---\n");
    printf("%-30s %-5s %-8s %-8s %-8s %s\n", 
           "Nome", "Sexo", "Peso", "Altura", "IMC", "Classificação");
    
    for (int i = 0; i < totalClientes; i++) {
        printf("%-30s %-5c %-8.2f %-8.2f %-8.2f %s\n", 
               historico[i].nome, 
               historico[i].sexo, 
               historico[i].peso, 
               historico[i].altura, 
               historico[i].imc, 
               historico[i].classificacao);
    }
}

void salvarHistorico() {
    FILE *arquivo = fopen(ARQUIVO_HISTORICO, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar!\n");
        return;
    }
    
    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%s;%c;%.2f;%.2f;%.2f;%s\n", 
                historico[i].nome, 
                historico[i].sexo, 
                historico[i].peso, 
                historico[i].altura, 
                historico[i].imc, 
                historico[i].classificacao);
    }
    
    fclose(arquivo);
    printf("Histórico salvo com sucesso!\n");
}

void carregarHistorico() {
    FILE *arquivo = fopen(ARQUIVO_HISTORICO, "r");
    if (arquivo == NULL) {
        return; // Arquivo não existe ainda
    }
    
    totalClientes = 0;
    while (!feof(arquivo) && totalClientes < MAX_CLIENTES) {
        Cliente temp;
        if (fscanf(arquivo, "%49[^;];%c;%f;%f;%f;%49[^\n]\n", 
                   temp.nome, &temp.sexo, &temp.peso, &temp.altura, &temp.imc, temp.classificacao) == 6) {
            historico[totalClientes++] = temp;
        }
    }
    
    fclose(arquivo);
}

void mostrarMenu() {
    printf("\n=== CALCULADORA DE IMC ===\n");
    printf("1. Calcular IMC\n");
    printf("2. Ver histórico\n");
    printf("3. Salvar histórico\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

void imprimirTabelaIMC() {
    printf("\n\033[1;37m=== TABELA DE CLASSIFICAÇÃO IMC ===\033[0m\n");
    
    // Tabela para homens
    printf("\n\t\033[1;34mCLASSIFICAÇÃO PARA HOMENS\033[0m\n");
    printf("\t\033[1;37m---------------------------------------------------\033[0m\n");
    printf("\t\033[1;37m| %-25s | %-19s |\033[0m\n", "Faixa de IMC", "Classificação");
    printf("\t\033[1;37m|-------------------------------------------------|\033[0m\n");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "Abaixo de 20.7", "Abaixo do peso");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;32m%-19s\033[0m |\n", "20.7 - 26.4", "Peso normal");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "26.4 - 27.8", "Acima");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "27.8 - 31.1", "Acima do peso ideal");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;31m%-19s\033[0m |\n", "Acima de 31.1", "Obeso");
    printf("\t\033[1;37m---------------------------------------------------\033[0m\n");
    
    // Tabela para mulheres
    printf("\n\t\033[1;35mCLASSIFICAÇÃO PARA MULHERES\033[0m\n");
    printf("\t\033[1;37m---------------------------------------------------\033[0m\n");
    printf("\t\033[1;37m| %-25s | %-19s |\033[0m\n", "Faixa de IMC", "Classificação");
    printf("\t\033[1;37m|-------------------------------------------------|\033[0m\n");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "Abaixo de 19.1", "Abaixo do peso");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;32m%-19s\033[0m |\n", "19.1 - 25.8", "Peso normal");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "25.8 - 27.3", "Acima ");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;33m%-19s\033[0m |\n", "27.3 - 32.3", "Acima do peso ideal");
    printf("\t| \033[1;36m%-25s\033[0m | \033[1;31m%-19s\033[0m |\n", "Acima de 32.3", "Obeso");
    printf("\t\033[1;37m---------------------------------------------------\033[0m\n\n");
}

void configuracoes() {
    #ifdef _WIN32
    // Obter handle para o console de saída
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Verificar se é um console válido
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }
    
    // Obter modo atual do console
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }
    
    // Ativar modo virtual terminal (suporte a ANSI)
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode)) {
        return;
    }
    #endif	
	
	setlocale(LC_ALL, "portuguese");	
	
}

int main() {
    configuracoes();
    
    int opcao;
    do {

        mostrarMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        system("cls");
        switch(opcao) {
            case 1:
            	imprimirTabelaIMC();
                cadastrarCliente();
                break;
            case 2:
                listarHistorico();
                break;
            case 3:
                salvarHistorico();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}