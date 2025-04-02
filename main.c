#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <stdarg.h>
#include <windows.h>

#define MAX_CLIENTES 100
#define ARQUIVO_DADOS "clientes_imc.dat"

#define MASCULINO 'M'
#define FEMININO 'F'

// Estrutura para gerenciar cores do console
typedef struct {
    const char* reset;
    const char* preto;
    const char* branco;
    const char* vermelho;
    const char* verde;
    const char* amarelo;
    const char* azul;
    const char* fundo_preto;
    const char* fundo_branco;
    const char* fundo_vermelho;
    const char* fundo_verde;
    const char* fundo_amarelo;
} ConsoleCores;

// Estrutura para armazenar dados do cliente
typedef struct {
    char nome[50];
    char sexo; // 'M' ou 'F'
    float peso;
    float altura;
    float imc;
    char classificacao[30];
} Cliente;

// Variáveis globais
Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;
ConsoleCores cor;

// Protótipos de funções
void inicializarCores();
void liberarCores();
void imprimirColorido(const char* cor, const char* formato, ...);
void limparBuffer();
float lerFloatPositivo(const char* mensagem);
void calcularIMC(Cliente *cliente);
void cadastrarCliente();
void listarClientes();
void pesquisarCliente();
void salvarDados();
void carregarDados();
void mostrarMenu();
void imprimirTabelaIMC();
void configuracoes();

void imprimirTabelaIMC_Homem();
void imprimirTabelaIMC_Mulher();

void imprimir_ascii_art() {
    printf("\n");
imprimirColorido(cor.azul, "___________  __       __  ___________       ___________  ___________  ___________  __       __  ___________  ___________  _         _  ___________  _         _  ___________  \n");
imprimirColorido(cor.vermelho, "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
imprimirColorido(cor.vermelho, " ¯¯¯¯¦¦¦¯¯¯¯ ¦¦¦¦¦   ¦¦¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯      ¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯  ¯¯¯¯¦¦¦¯¯¯¯ ¦¦¦       ¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦       ¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ \n");
imprimirColorido(cor.vermelho, "     ¦¦¦     ¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦               ¦¦¦       ¦¦¦¦¦¦       ¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦               ¦¦¦     ¦¦¦       ¦¦¦¦¦¦          ¦¦¦       ¦¦¦¦¦¦          \n");
imprimirColorido(cor.vermelho, "     ¦¦¦     ¦¦¦ ¦¦¦¦¦ ¦¦¦¦¦¦               ¦¦¦_______¦¦¦¦¦¦_______¦¦¦¦¦¦       ¦¦¦¦¦¦ ¦¦¦¦¦ ¦¦¦¦¦¦_________      ¦¦¦     ¦¦¦_______¦¦¦¦¦¦_________ ¦¦¦       ¦¦¦¦¦¦_________ \n");
imprimirColorido(cor.vermelho, "     ¦¦¦     ¦¦¦  ¦¦¦  ¦¦¦¦¦¦               ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
imprimirColorido(cor.vermelho, "     ¦¦¦     ¦¦¦   ¯   ¦¦¦¦¦¦               ¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦¯¯¯¯¦¦¦¯¯ ¦¦¦       ¦¦¦¦¦¦   ¯   ¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯      ¦¦¦     ¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦       ¦¦¦ ¯¯¯¯¯¯¯¯¯¦¦¦\n");
imprimirColorido(cor.vermelho, "     ¦¦¦     ¦¦¦       ¦¦¦¦¦¦               ¦¦¦          ¦¦¦     ¦¦¦  ¦¦¦       ¦¦¦¦¦¦       ¦¦¦¦¦¦               ¦¦¦     ¦¦¦       ¦¦¦¦¦¦          ¦¦¦       ¦¦¦          ¦¦¦\n");
imprimirColorido(cor.vermelho, " ____¦¦¦____ ¦¦¦       ¦¦¦¦¦¦_________      ¦¦¦          ¦¦¦      ¦¦¦ ¦¦¦_______¦¦¦¦¦¦       ¦¦¦¦¦¦_________      ¦¦¦     ¦¦¦       ¦¦¦¦¦¦_________ ¦¦¦_______¦¦¦ _________¦¦¦\n");
imprimirColorido(cor.vermelho, "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦     ¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
imprimirColorido(cor.azul, " ¯¯¯¯¯¯¯¯¯¯¯  ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯       ¯            ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯       ¯       ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯ \n");
                                                                                                                                                                              
imprimirColorido(cor.verde, " __        _  ___________  ___________       ___________  _         _  __       __  ___________  ___________  ___________  _         _  ___________ \n");                          
imprimirColorido(cor.amarelo, "¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");                          
imprimirColorido(cor.amarelo, "¦¦¦¦¦     ¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦     ¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦       ¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦ ¯¯¯¯¦¦¦¯¯¯¯ ¦¦¦       ¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ \n");                          
imprimirColorido(cor.amarelo, "¦¦¦¦¦¦    ¦¦¦¦¦¦       ¦¦¦¦¦¦       ¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦       ¦¦¦     ¦¦¦     ¦¦¦       ¦¦¦¦¦¦          \n");                          
imprimirColorido(cor.amarelo, "¦¦¦ ¦¦¦   ¦¦¦¦¦¦_______¦¦¦¦¦¦       ¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦ ¦¦¦¦¦ ¦¦¦¦¦¦_______¦¦¦¦¦¦_______¦¦¦     ¦¦¦     ¦¦¦       ¦¦¦¦¦¦_________ \n");                          
imprimirColorido(cor.amarelo, "¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦     ¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");                          
imprimirColorido(cor.amarelo, "¦¦¦   ¦¦¦ ¦¦¦¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦       ¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦   ¯   ¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦¯¯¯¯¦¦¦¯¯      ¦¦¦     ¦¦¦       ¦¦¦ ¯¯¯¯¯¯¯¯¯¦¦¦\n");                          
imprimirColorido(cor.amarelo, "¦¦¦    ¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦       ¦¦¦     ¦¦¦          ¦¦¦       ¦¦¦¦¦¦       ¦¦¦¦¦¦          ¦¦¦     ¦¦¦       ¦¦¦     ¦¦¦       ¦¦¦          ¦¦¦\n");                          
imprimirColorido(cor.amarelo, "¦¦¦     ¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦_______¦¦¦     ¦¦¦_________ ¦¦¦_______¦¦¦¦¦¦       ¦¦¦¦¦¦          ¦¦¦      ¦¦¦  ____¦¦¦____ ¦¦¦_______¦¦¦ _________¦¦¦\n");                          
imprimirColorido(cor.amarelo, "¦¦¦      ¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦          ¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");                          
imprimirColorido(cor.verde, " ¯        ¯¯  ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯       ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯         ¯  ¯            ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯ \n");                          
                                                                                                                                                                              
    printf("\n");
}

int main() {
    configuracoes();
    inicializarCores();
    carregarDados();

	
    int opcao;

	imprimir_ascii_art();
	printf("\n\n\n");
	system("pause");
	system("cls");
	
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
                listarClientes();
                break;
            case 3:
                pesquisarCliente();
                break;
            case 5:
                imprimirColorido(cor.verde, "Saindo...\n");
                break;
            default:
                imprimirColorido(cor.vermelho, "Opção inválida!\n");
        }
    } while (opcao != 5);

    liberarCores();
    return 0;
}

// Implementação das funções

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

void inicializarCores() {
    // Aloca e inicializa todas as cores
    cor.reset = "\033[0m";
    cor.preto = "\033[30m";
    cor.branco = "\033[37m";
    cor.vermelho = "\033[31m";
    cor.verde = "\033[32m";
    cor.amarelo = "\033[33m";
    cor.azul = "\033[34m";
    cor.fundo_preto = "\033[40m";
    cor.fundo_branco = "\033[47m";
    cor.fundo_vermelho = "\033[41m";
    cor.fundo_verde = "\033[42m";
    cor.fundo_amarelo = "\033[43m";
}

void liberarCores() {
    // Não é necessário liberar memória pois usamos strings literais
}

void imprimirColorido(const char* cor_, const char* formato, ...) {
    va_list args;
    va_start(args, formato);
    
    printf("%s", cor_);
    vprintf(formato, args);
    printf("%s", cor.reset);
    
    va_end(args);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float lerFloatPositivo(const char* mensagem) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        limparBuffer();
        if (valor <= 0) {
            imprimirColorido(cor.vermelho, "Valor inválido! Digite um número positivo.\n");
        }
    } while (valor <= 0);
    return valor;
}

void calcularIMC(Cliente *cliente) {
    cliente->imc = cliente->peso / (cliente->altura * cliente->altura);
    
    if (cliente->sexo == 'M' || cliente->sexo == 'm') {
        if (cliente->imc < 20.7) strcpy(cliente->classificacao, "Abaixo do peso");
        else if (cliente->imc < 26.4) strcpy(cliente->classificacao, "Peso normal");
        else if (cliente->imc < 27.8) strcpy(cliente->classificacao, "Marginalmente acima");
        else if (cliente->imc < 31.1) strcpy(cliente->classificacao, "Acima do peso ideal");
        else strcpy(cliente->classificacao, "Obeso");
    } else {
        if (cliente->imc < 19.1) strcpy(cliente->classificacao, "Abaixo do peso");
        else if (cliente->imc < 25.8) strcpy(cliente->classificacao, "Peso normal");
        else if (cliente->imc < 27.3) strcpy(cliente->classificacao, "Marginalmente acima");
        else if (cliente->imc < 32.3) strcpy(cliente->classificacao, "Acima do peso ideal");
        else strcpy(cliente->classificacao, "Obeso");
    }
}

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        imprimirColorido(cor.vermelho, "Limite de clientes atingido!\n");
        return;
    }
    
    Cliente novo;
    
    imprimirColorido(cor.azul, "\n--- Cadastro de Cliente ---\n");
    
    printf("Nome: ");
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;
    
    do {
        printf("Sexo (M/F): ");
        scanf(" %c", &novo.sexo);
        limparBuffer();
        novo.sexo = toupper(novo.sexo);
        if (novo.sexo != 'M' && novo.sexo != 'F') {
            imprimirColorido(cor.vermelho, "Sexo inválido! Digite M ou F.\n");
        }
    } while (novo.sexo != 'M' && novo.sexo != 'F');
    
    novo.peso = lerFloatPositivo("Peso (kg): ");
    novo.altura = lerFloatPositivo("Altura (m): ");
    
    calcularIMC(&novo);
    
    clientes[totalClientes++] = novo;
    
    system("cls");
    
    
    imprimirColorido(cor.amarelo, " Dados do Cliente:\n");
    imprimirColorido(cor.azul, "  Nome: %s\n", novo.nome);
    imprimirColorido(cor.azul, "  Sexo: %c\n", novo.sexo);
    imprimirColorido(cor.azul, "  Peso: %.2f\n", novo.peso);
    imprimirColorido(cor.azul, "  Altura: %.2f\n", novo.altura);
    imprimirColorido(cor.verde, "\n IMC calculado: %.2f - %s\n", novo.imc, novo.classificacao);
    printf("\n");
    
    if (novo.sexo == MASCULINO) {
		imprimirTabelaIMC_Homem();
	}
	
	if (novo.sexo == FEMININO) {
		imprimirTabelaIMC_Mulher();
	}
    
    printf("\n\n\t");
    salvarDados();
}

void listarClientes() {
    if (totalClientes == 0) {
        imprimirColorido(cor.amarelo, "\nNenhum cliente cadastrado!\n");
        return;
    }
    
    imprimirColorido(cor.azul, "\n--- Lista de Clientes ---\n");
    
    // Cabeçalho da tabela com fundo branco e texto preto
    printf("%s%s", cor.fundo_amarelo, cor.preto);
    printf("%-30s %-5s %-8s %-8s %-8s %-25s\n%-89s\n", 
           "Nome", "Sexo", "Peso", "Altura", "IMC", "Classificação", " ");
    printf("%s", cor.reset);
    
    for (int i = 0; i < totalClientes; i++) {
        // Alterna cores para melhor legibilidade
        const char* corLinha = (i % 2 == 0) ? cor.fundo_branco : cor.fundo_preto;
        printf("%s%s", corLinha, (i % 2 == 0) ? cor.preto : cor.branco);
        
        printf("%-30s %-5c %-8.2f %-8.2f %-8.2f %-25s\n", 
               clientes[i].nome, 
               clientes[i].sexo, 
               clientes[i].peso, 
               clientes[i].altura, 
               clientes[i].imc, 
               clientes[i].classificacao);
        
        printf("%s", cor.reset);
    }
}

void pesquisarCliente() {
    if (totalClientes == 0) {
        imprimirColorido(cor.amarelo, "\nNenhum cliente cadastrado para pesquisar!\n");
        return;
    }

    char termo[50];
    printf("\nDigite o nome ou parte do nome para pesquisar: ");
    fgets(termo, 50, stdin);
    termo[strcspn(termo, "\n")] = 0;

    imprimirColorido(cor.azul, "\n--- Resultados da Pesquisa ---\n");
    
    // Cabeçalho da tabela
    printf("%s%s", cor.fundo_branco, cor.preto);
    printf("%-30s %-5s %-8s %-8s %-8s %-25s\n", 
           "Nome", "Sexo", "Peso", "Altura", "IMC", "Classificação");
    printf("%s", cor.reset);

    int encontrados = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (strstr(clientes[i].nome, termo) != NULL) {
            const char* corLinha = (encontrados % 2 == 0) ? cor.fundo_branco : cor.fundo_preto;
            printf("%s%s", corLinha, cor.preto);
            
            printf("%-30s %-5c %-8.2f %-8.2f %-8.2f %-25s\n", 
                   clientes[i].nome, 
                   clientes[i].sexo, 
                   clientes[i].peso, 
                   clientes[i].altura, 
                   clientes[i].imc, 
                   clientes[i].classificacao);
            
            printf("%s", cor.reset);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        imprimirColorido(cor.vermelho, "\nNenhum cliente encontrado com o termo: %s\n", termo);
    } else {
        imprimirColorido(cor.verde, "\nTotal encontrado: %d\n", encontrados);
    }
}

void salvarDados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    if (arquivo == NULL) {
        imprimirColorido(cor.vermelho, "Erro ao abrir arquivo para salvar!\n");
        return;
    }
    
    fwrite(&totalClientes, sizeof(int), 1, arquivo);
    fwrite(clientes, sizeof(Cliente), totalClientes, arquivo);
    
    fclose(arquivo);
    imprimirColorido(cor.verde, "Dados salvos com sucesso!\n");
}

void carregarDados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");
    if (arquivo == NULL) {
        return; // Arquivo não existe ainda
    }
    
    fread(&totalClientes, sizeof(int), 1, arquivo);
    fread(clientes, sizeof(Cliente), totalClientes, arquivo);
    
    fclose(arquivo);
}

void mostrarMenu() {
    imprimirColorido(cor.azul, "\n=== CALCULADORA DE IMC ===\n");
    printf("1. Calcular IMC\n");
    printf("2. Listar clientes\n");
    printf("3. Pesquisar cliente\n");
    //printf("4. Salvar dados\n");
    printf("5. Sair\n");
    imprimirColorido(cor.amarelo, "Escolha uma opção: ");
}

void imprimirTabelaIMC() {
    // Título
    printf("%s%s", cor.fundo_preto, cor.azul);
    printf("\n=== TABELA DE CLASSIFICAÇÃO IMC ===\n");
    printf("%s", cor.reset);
    
    imprimirTabelaIMC_Homem();
    
    imprimirTabelaIMC_Mulher();
    
}

void imprimirTabelaIMC_Homem() {
	// Tabela para homens
    printf("\n%s%sCLASSIFICAÇÃO PARA HOMENS%s\n", cor.fundo_amarelo, cor.preto, cor.reset);
    printf("%s%s---------------------------------------------------%s\n", cor.fundo_branco, cor.preto, cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_branco, cor.preto, "Faixa de IMC", "Classificação", cor.reset);
    printf("%s%s|-------------------------------------------------|%s\n", cor.fundo_branco, cor.preto, cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_branco, cor.preto, "Abaixo de 20.7", "Abaixo do peso", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_verde, cor.branco, "20.7 - 26.4", "Peso normal", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_amarelo, cor.preto, "26.4 - 27.8", "Marginalmente acima", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_vermelho, cor.branco, "27.8 - 31.1", "Acima do peso ideal", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_preto, cor.vermelho, "Acima de 31.1", "Obeso", cor.reset);
    printf("%s%s---------------------------------------------------%s\n", cor.fundo_branco, cor.preto, cor.reset);
}

void imprimirTabelaIMC_Mulher() {
	// Tabela para mulheres
    printf("\n%s%sCLASSIFICAÇÃO PARA MULHERES%s\n", cor.fundo_amarelo, cor.preto, cor.reset);
    printf("%s%s---------------------------------------------------%s\n", cor.fundo_branco, cor.preto, cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_branco, cor.preto, "Faixa de IMC", "Classificação", cor.reset);
    printf("%s%s|-------------------------------------------------|%s\n", cor.fundo_branco, cor.preto, cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_branco, cor.preto, "Abaixo de 19.1", "Abaixo do peso", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_verde, cor.branco, "19.1 - 25.8", "Peso normal", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_amarelo, cor.preto, "25.8 - 27.3", "Marginalmente acima", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_vermelho, cor.branco, "27.3 - 32.3", "Acima do peso ideal", cor.reset);
    printf("%s%s| %-25s | %-19s |%s\n", cor.fundo_preto, cor.vermelho, "Acima de 32.3", "Obeso", cor.reset);
    printf("%s%s---------------------------------------------------%s\n\n", cor.fundo_branco, cor.preto, cor.reset);
}