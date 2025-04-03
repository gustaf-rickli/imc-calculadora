// Inclusão de bibliotecas necessárias
#include <stdio.h>      // Para funções de entrada/saída
#include <string.h>     // Para manipulação de strings
#include <ctype.h>      // Para funções de caracteres (toupper, etc.)
#include <stdlib.h>     // Para funções gerais (system, etc.)
#include <locale.h>     // Para configuração de localidade
#include <stdarg.h>     // Para funções variádicas (va_list)
#include <windows.h>    // Para funções específicas do Windows

// Definição de constantes
#define MAX_CLIENTES 100               // Número máximo de clientes
#define ARQUIVO_DADOS "clientes_imc.dat"  // Nome do arquivo de dados
#define MASCULINO 'M'                  // Definição para sexo masculino
#define FEMININO 'F'                   // Definição para sexo feminino

// Estrutura para gerenciar cores do console
typedef struct {
    const char* reset;         // Código para resetar cor
    const char* preto;         // Código para cor preta
    const char* branco;        // Código para cor branca
    const char* vermelho;      // Código para cor vermelha
    const char* verde;         // Código para cor verde
    const char* amarelo;       // Código para cor amarela
    const char* azul;          // Código para cor azul
    const char* laranja;       // Código para cor laranja
    const char* fundo_preto;   // Código para fundo preto
    const char* fundo_branco;  // Código para fundo branco
    const char* fundo_vermelho;// Código para fundo vermelho
    const char* fundo_verde;   // Código para fundo verde
    const char* fundo_amarelo; // Código para fundo amarelo
} ConsoleCores;

// Estrutura para armazenar dados do cliente
typedef struct {
    char nome[50];          // Nome do cliente
    char sexo;              // Sexo ('M' ou 'F')
    float peso;             // Peso em kg
    float altura;           // Altura em metros
    float imc;              // Valor do IMC calculado
    char classificacao[30]; // Classificação do IMC
} Cliente;

// Variáveis globais
Cliente clientes[MAX_CLIENTES];  // Array para armazenar clientes
int totalClientes = 0;           // Contador de clientes
ConsoleCores cor;               // Variável para cores do console

// Protótipos de funções
void inicializarCores();        // Inicializa as cores do console
void liberarCores();            // Libera recursos das cores (não usado)
void imprimirColorido(const char* cor, const char* formato, ...); // Imprime texto colorido
void limparBuffer();            // Limpa o buffer de entrada
float lerFloatPositivo(const char* mensagem); // Lê um float positivo
void calcularIMC(Cliente *cliente); // Calcula o IMC do cliente
void cadastrarCliente();        // Cadastra um novo cliente
void listarClientes();          // Lista todos os clientes
void pesquisarCliente();        // Pesquisa clientes por nome
void salvarDados();             // Salva dados no arquivo
void carregarDados();           // Carrega dados do arquivo
void mostrarMenu();             // Mostra o menu principal
void imprimirTabelaIMC();       // Mostra a tabela de classificação IMC
void configuracoes();           // Configurações iniciais do programa
void imprimirTabelaIMC_Homem(); // Mostra tabela IMC para homens
void imprimirTabelaIMC_Mulher(); // Mostra tabela IMC para mulheres

// Função para imprimir arte ASCII colorida
void imprimir_ascii_art() {
    printf("\n");
    // Imprime várias linhas de arte ASCII com cores diferentes
    imprimirColorido(cor.azul, "___________  __       __  ___________       ___________  ___________  ___________  __       __  ___________  ___________  _         _  ___________  _         _  ___________  \n");
    // ... (outras linhas de arte ASCII)
    printf("\n");
}

// Função principal
int main() {
    configuracoes();        // Configura o ambiente
    inicializarCores();     // Inicializa as cores
    carregarDados();        // Carrega dados salvos

    int opcao;

    // Mostra arte ASCII e pausa
    imprimir_ascii_art();
    printf("\n\n\n");
    system("pause");
    system("cls");
    
    // Loop principal do menu
    do {
        mostrarMenu();      // Mostra o menu
        scanf("%d", &opcao); // Lê a opção
        limparBuffer();     // Limpa o buffer
        
        system("cls");      // Limpa a tela
        switch(opcao) {     // Executa ação conforme opção
            case 1:
                imprimirTabelaIMC(); // Mostra tabela IMC
                cadastrarCliente();  // Cadastra cliente
                break;
            case 2:
                listarClientes();    // Lista clientes
                break;
            case 3:
                pesquisarCliente();  // Pesquisa cliente
                break;
            case 5:
                imprimirColorido(cor.verde, "Saindo...\n"); // Sai do programa
                break;
            default:
                imprimirColorido(cor.vermelho, "Opção inválida!\n"); // Opção inválida
        }
    } while (opcao != 5);  // Repete até opção sair

    liberarCores();        // Libera recursos (não usado)
    return 0;              // Fim do programa
}

// Configurações iniciais do ambiente
void configuracoes() {
    #ifdef _WIN32
    // Configura o console do Windows para suportar cores ANSI
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= 0x0004;  // Ativa modo VT (suporte a ANSI)
    if (!SetConsoleMode(hOut, dwMode)) return;
    #endif  
    
    setlocale(LC_ALL, "portuguese"); // Configura localidade para português
}

// Inicializa as cores do console
void inicializarCores() {
    // Atribui códigos ANSI para cada cor
    cor.reset = "\033[0m";
    cor.preto = "\033[30m";
    cor.branco = "\033[97m";
    cor.vermelho = "\033[31m";
    cor.verde = "\033[32m";
    cor.amarelo = "\033[38;2;255;255;0m";
    cor.azul = "\033[94m";
    cor.laranja = "\033[38;2;255;165;0m";
    cor.fundo_preto = "\033[40m";
    cor.fundo_branco = "\033[47m";
    cor.fundo_vermelho = "\033[41m";
    cor.fundo_verde = "\033[42m";
    cor.fundo_amarelo = "\033[43m";
}

// Função vazia (não é necessário liberar memória)
void liberarCores() {
}

// Imprime texto colorido no console
void imprimirColorido(const char* cor_, const char* formato, ...) {
    va_list args;
    va_start(args, formato);
    
    printf("%s", cor_);      // Aplica a cor
    vprintf(formato, args);  // Imprime o texto formatado
    printf("%s", cor.reset); // Reseta a cor
    
    va_end(args);
}

// Limpa o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Lê caracteres até encontrar nova linha ou EOF
}

// Lê um número float positivo
float lerFloatPositivo(const char* mensagem) {
    float valor;
    do {
        printf("%s", mensagem);  // Mostra a mensagem
        scanf("%f", &valor);     // Lê o valor
        limparBuffer();          // Limpa o buffer
        if (valor <= 0) {        // Valida se é positivo
            imprimirColorido(cor.vermelho, "Valor inválido! Digite um número positivo.\n");
        }
    } while (valor <= 0);       // Repete até valor válido
    return valor;
}

// Calcula o IMC e classifica conforme sexo
void calcularIMC(Cliente *cliente) {
    cliente->imc = cliente->peso / (cliente->altura * cliente->altura); // Fórmula IMC
    
    // Classificação diferente para homens e mulheres
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

// Cadastra um novo cliente
void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) { // Verifica limite
        imprimirColorido(cor.vermelho, "Limite de clientes atingido!\n");
        return;
    }
    
    Cliente novo; // Novo cliente
    
    imprimirColorido(cor.azul, "\n--- Cadastro de Cliente ---\n");
    
    // Lê nome
    printf("Nome: ");
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // Remove \n
    
    // Valida sexo
    do {
        printf("Sexo (M/F): ");
        scanf(" %c", &novo.sexo);
        limparBuffer();
        novo.sexo = toupper(novo.sexo);
        if (novo.sexo != 'M' && novo.sexo != 'F') {
            imprimirColorido(cor.vermelho, "Sexo inválido! Digite M ou F.\n");
        }
    } while (novo.sexo != 'M' && novo.sexo != 'F');
    
    // Lê peso e altura
    novo.peso = lerFloatPositivo("Peso (kg): ");
    novo.altura = lerFloatPositivo("Altura (m): ");
    
    calcularIMC(&novo); // Calcula IMC
    
    clientes[totalClientes++] = novo; // Adiciona ao array
    
    system("cls"); // Limpa tela
    
    // Mostra dados cadastrados
    imprimirColorido(cor.amarelo, " Dados do Cliente:\n");
    imprimirColorido(cor.azul, "  Nome: %s\n", novo.nome);
    imprimirColorido(cor.azul, "  Sexo: %c\n", novo.sexo);
    imprimirColorido(cor.azul, "  Peso: %.2f\n", novo.peso);
    imprimirColorido(cor.azul, "  Altura: %.2f\n", novo.altura);
    imprimirColorido(cor.verde, "\n IMC calculado: %.2f - %s\n", novo.imc, novo.classificacao);
    printf("\n");
    
    // Mostra tabela apropriada conforme sexo
    if (novo.sexo == MASCULINO) {
        imprimirTabelaIMC_Homem();
    }
    
    if (novo.sexo == FEMININO) {
        imprimirTabelaIMC_Mulher();
    }
    
    printf("\n\n\t");
    salvarDados(); // Salva os dados
}

// Lista todos os clientes cadastrados
void listarClientes() {
    if (totalClientes == 0) { // Verifica se há clientes
        imprimirColorido(cor.amarelo, "\nNenhum cliente cadastrado!\n");
        return;
    }
    
    imprimirColorido(cor.azul, "\n--- Lista de Clientes ---\n");
    
    // Cabeçalho da tabela
    printf("%s%s", cor.fundo_amarelo, cor.preto);
    printf("%-30s %-5s %-8s %-8s %-8s %-25s\n%-89s\n", 
           "Nome", "Sexo", "Peso", "Altura", "IMC", "Classificação", " ");
    printf("%s", cor.reset);
    
    // Imprime cada cliente
    for (int i = 0; i < totalClientes; i++) {
        // Alterna cores das linhas
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

// Pesquisa clientes por nome
void pesquisarCliente() {
    if (totalClientes == 0) { // Verifica se há clientes
        imprimirColorido(cor.amarelo, "\nNenhum cliente cadastrado para pesquisar!\n");
        return;
    }

    char termo[50];
    printf("\nDigite o nome ou parte do nome para pesquisar: ");
    fgets(termo, 50, stdin);
    termo[strcspn(termo, "\n")] = 0; // Remove \n

    imprimirColorido(cor.azul, "\n--- Resultados da Pesquisa ---\n");
    
    // Cabeçalho da tabela
    printf("%s%s", cor.fundo_branco, cor.preto);
    printf("%-30s %-5s %-8s %-8s %-8s %-25s\n", 
           "Nome", "Sexo", "Peso", "Altura", "IMC", "Classificação");
    printf("%s", cor.reset);

    int encontrados = 0;
    // Procura em todos os clientes
    for (int i = 0; i < totalClientes; i++) {
        if (strstr(clientes[i].nome, termo) != NULL) { // Verifica se o termo está no nome
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

    if (encontrados == 0) { // Nenhum encontrado
        imprimirColorido(cor.vermelho, "\nNenhum cliente encontrado com o termo: %s\n", termo);
    } else {
        imprimirColorido(cor.verde, "\nTotal encontrado: %d\n", encontrados);
    }
}

// Salva os dados no arquivo
void salvarDados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb"); // Abre para escrita binária
    if (arquivo == NULL) {
        imprimirColorido(cor.vermelho, "Erro ao abrir arquivo para salvar!\n");
        return;
    }
    
    // Escreve total de clientes e depois o array
    fwrite(&totalClientes, sizeof(int), 1, arquivo);
    fwrite(clientes, sizeof(Cliente), totalClientes, arquivo);
    
    fclose(arquivo); // Fecha o arquivo
    imprimirColorido(cor.verde, "Dados salvos com sucesso!\n");
}

// Carrega os dados do arquivo
void carregarDados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb"); // Abre para leitura binária
    if (arquivo == NULL) return; // Se não existir, retorna
    
    // Lê total de clientes e depois o array
    fread(&totalClientes, sizeof(int), 1, arquivo);
    fread(clientes, sizeof(Cliente), totalClientes, arquivo);
    
    fclose(arquivo); // Fecha o arquivo
}

// Mostra o menu principal
void mostrarMenu() {
    imprimirColorido(cor.azul, "\n=== CALCULADORA DE IMC ===\n");
    printf("1. Calcular IMC\n");
    printf("2. Listar clientes\n");
    printf("3. Pesquisar cliente\n");
    printf("5. Sair\n");
    imprimirColorido(cor.amarelo, "Escolha uma opção: ");
}

// Mostra a tabela de classificação IMC
void imprimirTabelaIMC() {
    // Título
    printf("%s%s", cor.fundo_preto, cor.azul);
    printf("\n=== TABELA DE CLASSIFICAÇÃO IMC ===\n");
    printf("%s", cor.reset);
    
    imprimirTabelaIMC_Homem(); // Tabela homens
    imprimirTabelaIMC_Mulher(); // Tabela mulheres
}

// Mostra tabela IMC para homens
void imprimirTabelaIMC_Homem() {
    printf("\n%sCLASSIFICAÇÃO PARA HOMENS%s\n", cor.azul, cor.reset);
    printf("%s---------------------------------------------------%s\n", cor.branco, cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.amarelo ,"Faixa de IMC", "Classificação", cor.reset);
    printf("%s|-------------------------------------------------|%s\n", cor.branco, cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.azul, "Abaixo de 20.7", "Abaixo do peso", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.verde, "20.7 - 26.4", "Peso normal", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.amarelo, "26.4 - 27.8", "Marginalmente acima", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.laranja, "27.8 - 31.1", "Acima do peso ideal", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.vermelho, "Acima de 31.1", "Obeso", cor.reset);
    printf("%s---------------------------------------------------%s\n", cor.branco, cor.reset);
}

// Mostra tabela IMC para mulheres
void imprimirTabelaIMC_Mulher() {
    printf("\n%sCLASSIFICAÇÃO PARA MULHERES%s\n", cor.azul, cor.reset);
    printf("%s---------------------------------------------------%s\n", cor.branco, cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.amarelo, "Faixa de IMC", "Classificação", cor.reset);
    printf("%s|-------------------------------------------------|%s\n", cor.branco, cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.azul, "Abaixo de 19.1", "Abaixo do peso", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.verde, "19.1 - 25.8", "Peso normal", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.amarelo, "25.8 - 27.3", "Marginalmente acima", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.laranja, "27.3 - 32.3", "Acima do peso ideal", cor.reset);
    printf("%s| %-25s | %-19s |%s\n", cor.vermelho, "Acima de 32.3", "Obeso", cor.reset);
    printf("%s---------------------------------------------------%s\n\n", cor.branco, cor.reset);
}
