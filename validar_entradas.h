#include "definicoes.h"

#include <algorithm>
#include <sstream>

#include <iostream>
#include <limits> 

#include <cstring> 
#include <string>

using namespace std;

int validarEntradaFloat(float numero) {
	string valores_decimais;

    getline(cin, valores_decimais);

    // Substitui vírgula por ponto
    replace(valores_decimais.begin(), valores_decimais.end(), ',', '.');

    // Tenta converter a string para float usando stringstream
    stringstream string_stream(valores_decimais);
    string_stream >> numero;

    if (string_stream.fail()) {
        return FALSE;
    }

    return TRUE;
}

float validarFaixaDeValor(char *texto, float FAIXA_MINIMA, float FAIXA_MAXIMA) {
	float valor;
	
	CoresConsole corConsole;
	
	do {
		cout << "\t\t\t\t\t" << texto;
		cin >> valor;
		
		validarEntradaFloat(valor);
		
		if ( valor <= FAIXA_MINIMA || valor >= FAIXA_MAXIMA || cin.fail()) {
			cin.clear(); // Limpa o estado de erro
            cin.ignore(10000, '\n'); // Descarta entrada inválida
			cout << "\t\t\t\t\t" << corConsole.vermelhoNeon << "\nErro: Espera-se valores entre " << FAIXA_MINIMA << " e " << FAIXA_MAXIMA << corConsole.reset << endl;
			continue;
		}
		
	} while (	valor <= FAIXA_MINIMA || valor >= FAIXA_MAXIMA	);

	
	return valor;
}

string validarTexto(char *texto_output, int TAMANHO_LIMITE_TEXTO, int TAMANHO_MINIMO_CARACTERES) {
	
	string texto_input;
	
	texto_input = new char[TAMANHO_LIMITE_TEXTO];
	
	CoresConsole corConsole;
	
	do {
		cout << "\t\t\t\t\t" << texto_output;
		getline(cin, texto_input);
		
		if ( texto_input.size() <= TAMANHO_MINIMO_CARACTERES ) {
		
			cin.clear(); // Limpa o estado de erro
            cin.ignore(10000, '\n'); // Descarta entrada inválida
			cout << "\t\t\t\t\t" << corConsole.vermelhoNeon << "\nErro: Foi digitado um texto com menos de " << TAMANHO_MINIMO_CARACTERES << " caracteres" << corConsole.reset << endl;
	
			continue;
		}
	} while (	texto_input.size() <= TAMANHO_MINIMO_CARACTERES	);	
	
	
	return texto_input;
}


// valida o caractere, e retorna true ou false;
int compararCaracteres(char PRIMEIRO_CARACTERE, char SEGUNDO_CARACTERE) {
	
	PRIMEIRO_CARACTERE = toupper(PRIMEIRO_CARACTERE);
	SEGUNDO_CARACTERE = toupper(SEGUNDO_CARACTERE);
	
    if (PRIMEIRO_CARACTERE == SEGUNDO_CARACTERE) {
		return TRUE;
	}
	
	return FALSE;
}

char validarCaractere(char *texto, char PRIMEIRO_CARACTERE, char SEGUNDO_CARACTERE) {
	
	char caractere;
	
	do {
		cout << texto;
		cin >> caractere;
	} while (	!(compararCaracteres(caractere, PRIMEIRO_CARACTERE) || compararCaracteres(caractere, SEGUNDO_CARACTERE))	);	
	
	
	return caractere;
}
