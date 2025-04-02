
#include <iostream>
#include <sstream>
#include <string>
#include <cstring> // Para strdup()
#include <memory> // Para smart pointers


using namespace std;


/*
Ex. de uso!
	CoresConsole cores; // Criar a instância com as cores otimizadas
    demonstrarCores(cores);

*/

// Estrutura com um conjunto reduzido de cores vibrantes e elegantes
struct CoresConsole {
    string reset;
    
    // Texto brilhante
    string brancoBrilhante;
    string azulNeon;
    string verdeNeon;
    string vermelhoNeon;
    string dourado;
    string cianoVibrante;

    // Fundos estilosos
    string fundoPretoProfundo;
    string fundoAzulReal;
    string fundoVermelhoNobre;

    // Construtor para inicializar as cores
    CoresConsole() {
        reset = "\033[0m";

        // Cores vibrantes para texto
        brancoBrilhante = "\033[97m";  // Branco bem claro
        azulNeon = "\033[94m";         // Azul forte
        verdeNeon = "\033[92m";        // Verde neon
        vermelhoNeon = "\033[91m";     // Vermelho vibrante
        dourado = "\033[93m";          // Amarelo ouro
        cianoVibrante = "\033[96m";    // Azul claro vibrante

        // Fundos elegantes
        fundoPretoProfundo = "\033[40m";  // Preto escuro
        fundoAzulReal = "\033[44m";       // Azul intenso
        fundoVermelhoNobre = "\033[41m";  // Vermelho chamativo
    }
    
    
};




