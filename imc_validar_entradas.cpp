#include <iostream>
#include <iomanip> 
#include <locale.h>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

#define CONSTANTE_HOMEM 72.7
#define CONSTANTE_MULHER 62.1

#define MASCULINO 'M'
#define FEMININO 'F'

#define TRUE 1
#define FALSE 0

#define PESO_MINIMO 24.9
#define PESO_MAXIMO 339

#define ALTURA_MINIMA 1.35
#define ALTURA_MAXIMA 2.16

#define LIMITE_NOME 20

float entradaPeso(char nome) {
	float altura;
	
	do {
		cout << "\nDigite sua altura " << nome << " (Altura Mín. 1.35 | Altura Máx. 2.16)\n\n";
		validarEntradaFloat(&altura);
	} while (	altura < ALTURA_MINIMA || altura > ALTURA_MAXIMA	);

	return altura;
}

float entradaPeso(char nome) {
	
	float peso;
	
	
	do {
		cout << "\tRegras para valores válidos:\n\t- pode usar ponto(.) ou vírgula(,)\n\t- peso mínimo 25kg - peso máximo 339kg)\n" << endl;
		cout << "\tDigite seu peso " << nome << ": ";
		
		validarEntradaFloat(&peso);
		
		if ( !(peso < PESO_MINIMO || peso >= PESO_MAXIMO) ) {
			system("cls");
			cout << "\nAltura errada, foi digitado " << (double)peso << "\n\n";
		}

	} while (	peso < PESO_MINIMO || peso >= PESO_MAXIMO	);
	
	return &nome;
}

char* entradaNome() {
	char nome[LIMITE_NOME];
	
	do {
		cout << "\nDigite seu nome: ";
		cin >> nome;
	} while (	strlen(nome) < 2	);	
	
	return &nome;
}

char entradaSexo() {
	char sexo;
	
	do {
		cout << DEST << COR_T << COR_E_7 << "\n\tDigite seu sexo [M - masculino	| F - feminino]: " << RESET;
		cin >> sexo;
	} while (	!(compararSexo(&sexo, MASCULINO) || compararSexo(&sexo, FEMINONO))	);	
	
	return sexo;
}

int compararSexo(char sexo1, char sexo2) {
	
	sexo1 = toupper(sexo1);
	sexo2 = toupper(sexo2);
	
	if (sexo1 == sexo2) {
		return TRUE;
	}
	
	return FALSE;
}

int validarSexo(char *sexo) {
	if (compararSexo(*sexo, MASCULINO)) {
		*sexo = MASCULINO;	
		
		return TRUE;
	}
	
	if (compararSexo(*sexo, FEMINONO)) {
		*sexo = FEMINONO;	
		
		return TRUE;
	}
	
	return FALSE;
}

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
