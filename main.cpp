

#include <iomanip> 
#include <locale.h>
#include <windows.h>
#include "imprimir_tabelas.h"
#include "cores_console.h"
#include "validar_entradas.h"
#include "configuracoes.h"
#include "definicoes.h"
//#include "imprimir_menu.h"

#include <string>

#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <memory>

#include <algorithm> // std::replace

#include <sstream>
#include <math.h> 
#include <ctype.h>

using namespace std;

// Função para exibir as cores selecionadas
void demonstrarCores(CoresConsole cores) {
    cout << cores.brancoBrilhante << "Texto Branco Brilhante" << cores.reset << endl;
    cout << cores.azulNeon << "Texto Azul Neon" << cores.reset << endl;
    cout << cores.verdeNeon << "Texto Verde Neon" << cores.reset << endl;
    cout << cores.vermelhoNeon << "Texto Vermelho Neon" << cores.reset << endl;
    cout << cores.dourado << "Texto Dourado" << cores.reset << endl;
    cout << cores.cianoVibrante << "Texto Ciano Vibrante" << cores.reset << endl;
    
    cout << cores.fundoPretoProfundo << "Texto com Fundo Preto Profundo" << cores.reset << endl;
    cout << cores.fundoAzulReal << "Texto com Fundo Azul Real" << cores.reset << endl;
    cout << cores.fundoVermelhoNobre << "Texto com Fundo Vermelho Nobre" << cores.reset << endl;
}

#define PESO_MINIMO 24.9
#define PESO_MAXIMO 339

#define ALTURA_MINIMA 1.35
#define ALTURA_MAXIMA 2.16

#define LIMITE_NOME 20

int main() {
	
	setup();
	
	//imprimir_menu();
	
	cout << cores.azulNeon << endl;
	cout << "\t¦¦ ¦¦¦    ¦¦¦  ¦¦¦¦¦¦     ¦¦¦¦¦¦  ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦    ¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦¦" << endl;;
	cout << "\t¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦          ¦¦   ¦¦ ¦¦   ¦¦ ¦¦    ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦         ¦¦    ¦¦   ¦¦ ¦¦      ¦¦    ¦¦ ¦¦     " << endl;
	cout << "\t¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦          ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦    ¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦      ¦¦    ¦¦¦¦¦¦¦ ¦¦¦¦¦   ¦¦    ¦¦ ¦¦¦¦¦¦¦" << endl;
    cout << "\t¦¦ ¦¦  ¦¦  ¦¦ ¦¦          ¦¦      ¦¦   ¦¦ ¦¦    ¦¦ ¦¦  ¦¦  ¦¦ ¦¦         ¦¦    ¦¦   ¦¦ ¦¦      ¦¦    ¦¦      ¦¦" << endl;
    cout << "\t¦¦ ¦¦      ¦¦  ¦¦¦¦¦¦     ¦¦      ¦¦   ¦¦  ¦¦¦¦¦¦  ¦¦      ¦¦ ¦¦¦¦¦¦¦    ¦¦    ¦¦   ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦¦" << endl;
    cout << "\n" << endl;
    cout << "\t¦¦¦    ¦¦  ¦¦¦¦¦   ¦¦¦¦¦¦       ¦¦¦¦¦¦ ¦¦    ¦¦ ¦¦¦    ¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦¦  " << endl;
    cout << "\t¦¦¦¦   ¦¦ ¦¦   ¦¦ ¦¦    ¦¦     ¦¦      ¦¦    ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦ ¦¦    ¦¦ ¦¦       " << endl;
    cout << "\t¦¦ ¦¦  ¦¦ ¦¦¦¦¦¦¦ ¦¦    ¦¦     ¦¦      ¦¦    ¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦¦  " << endl;
    cout << "\t¦¦  ¦¦ ¦¦ ¦¦   ¦¦ ¦¦    ¦¦     ¦¦      ¦¦    ¦¦ ¦¦  ¦¦  ¦¦ ¦¦      ¦¦   ¦¦ ¦¦ ¦¦    ¦¦      ¦¦  " << endl;
    cout << "\t¦¦   ¦¦¦¦ ¦¦   ¦¦  ¦¦¦¦¦¦       ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦      ¦¦ ¦¦      ¦¦   ¦¦ ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦¦  " << endl;
    
    // Reseta a cor no final
	
	CoresConsole corConsole; // Instância da struct de cores

	 
	 // Agora funciona com ambos:
    
	
	// cout << cores.azulNeon << "texte" << cores.reset << "foo bar" << endl;
 
	 
	 //demonstrarCores(cores);
	 
	 
    //imprimirLegendaIMC();
    
    
    int sair;
	sair = FALSE;
    
    do {
    	
    	imprimirLegendaIMC();
    	
    	cout << "\n\n";
		
		string nome;
		nome = validarTexto("Digite seu nome: ", LIMITE_NOME, 2);
		
		float altura;
		altura = validarFaixaDeValor("Digite sua altura: ", ALTURA_MINIMA, ALTURA_MAXIMA);
		
		float peso;
		peso = validarFaixaDeValor("Digite seu peso: ", PESO_MINIMO, PESO_MAXIMO);
		
		sair = TRUE;
		
		// system("cls");
		
		cout << "\n\n\n" << "\t\t\t\t\t Nome: " << nome << "\t Altura: " << altura << "\t Peso: " << peso << endl;
		
	} while (sair == TRUE);
	
	
	// 
	
	return 0;
}




