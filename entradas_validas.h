using namespace std;

float validarFaixaDeValor(char *nome, float FAIXA_MINIMA, float FAIXA_MAXIMA) {
	float valor;
	
	do {
		cout << nome;
		cin >> valor;
		validarEntradaFloat(valor);
		
		if ( !(valor < FAIXA_MINIMA || valor >= FAIXA_MAXIMA) ) {
			system("cls");
			cout << "\nValor digitado Incorreto, espera-se valores entre " << FAIXA_MINIMA << " e " << FAIXA_MAXIMA;
		}
	} while (	altura < FAIXA_MINIMA || altura > FAIXA_MAXIMA	);

	return altura;
}

char* validarTexto() {
	char nome[LIMITE_NOME];
	
	do {
		cout << "\nDigite seu nome: ";
		cin >> nome;
	} while (	strlen(nome) < 2	);	
	
	return &nome;
}

char validarCaractere(char *caractere, char PRIMEIRO_CARACTERE, char SEGUNDO_CARACTERE) {
	
	do {
		cout << DEST << COR_T << COR_E_7 << "\n\tDigite seu sexo [M - masculino	| F - feminino]: " << RESET;
		cin >> *caractere;
	} while (	!(compararSexo(&caractere, MASCULINO) || compararSexo(&caractere, FEMINONO))	);	
	
	return sexo;
}

int compararSexo(char PRIMEIRO_CARACTERE, char SEGUNDO_CARACTERE) {
	
	PRIMEIRO_CARACTERE = toupper(PRIMEIRO_CARACTERE);
	SEGUNDO_CARACTERE = toupper(SEGUNDO_CARACTERE);
	
	if (sexo1 == sexo2) {
		return TRUE;
	}
	
	return FALSE;
}

// valida o caractere, e retorna true ou false;
int validarCaractere(char *caractere, char PRIMEIRO_CARACTERE, char SEGUNDO_CARACTERE) {
	if (compararSexo(caractere, PRIMEIRO_CARACTERE)) {
		*caractere = PRIMEIRO_CARACTERE;	
		
		return TRUE;
	}
	
	if (compararSexo(caractere, SEGUNDO_CARACTERE)) {
		*caractere = SEGUNDO_CARACTERE;	
		
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
