
/*Peso (kg)	1,50m	1,55m	1,60m	1,65m	1,70m	1,75m	1,80m	1,85m	1,90m	1,95m	2,00m
50	Peso normal		Peso normal		Peso normal		Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso
55	Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal		Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso
60	Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal		Peso normal		Abaixo do peso	Abaixo do peso	Abaixo do peso	Abaixo do peso
65	Sobrepeso		Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal		Peso normal		Abaixo do peso	Abaixo do peso	Abaixo do peso
70	Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal		Peso normal		Abaixo do peso	Abaixo do peso
75	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal		Peso normal
80	Obesidade II	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal		Peso normal
85	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Sobrepeso		Peso normal		Peso normal		Peso normal
90	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Sobrepeso		Peso normal		Peso normal
95	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Sobrepeso		Peso normal
100	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso		Sobrepeso
105	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso		Sobrepeso
110	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Obesidade I		Sobrepeso		Sobrepeso
115	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Sobrepeso		Sobrepeso
120	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade II	Obesidade I		Obesidade I		Obesidade I
125	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade II	Obesidade I		Obesidade I
130	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade I		Obesidade I
135	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II	Obesidade I
140	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade III	Obesidade II	Obesidade II

Classificação do IMC para Mulheres
Abaixo do peso: IMC < 18,5

Peso normal: IMC entre 18,5 e 23,9

Sobrepeso: IMC entre 24,0 e 28,9

Obesidade Grau I: IMC entre 29,0 e 34,9

Obesidade Grau II: IMC entre 35,0 e 39,9

Obesidade Grau III (mórbida): IMC = 40,0
*/


using namespace std;

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






void enableANSI() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    // Verificar se o console tem suporte a modos ANSI
    if (hConsole == INVALID_HANDLE_VALUE) return;

    // Obter o modo atual do console
    if (!GetConsoleMode(hConsole, &dwMode)) return;
    
     // Ativar o modo ANSI
    dwMode |= 0x0004;  // ENABLE_VIRTUAL_TERMINAL_PROCESSING (0x0004)

    SetConsoleMode(hConsole, dwMode);
}

void imprimirTabelaIMC() {
    const int alturas = 11; // Número de colunas (alturas)
    const int pesos = 19;   // Número de linhas (pesos)

    double valoresIMC[pesos][alturas] = {
        {22.22, 20.81, 19.53, 18.37, 17.30, 16.33, 15.43, 14.61, 13.85, 13.15, 12.50},  // 50kg
        {24.44, 22.89, 21.48, 20.20, 19.03, 17.96, 16.98, 16.07, 15.24, 14.48, 13.75},  // 55kg
        {26.67, 24.97, 23.44, 22.04, 20.76, 19.59, 18.52, 17.53, 16.62, 15.78, 15.00},  // 60kg
        {28.89, 27.06, 25.39, 23.88, 22.49, 21.22, 20.06, 18.99, 18.01, 17.09, 16.25},  // 65kg
        {31.11, 29.14, 27.34, 25.71, 24.22, 22.86, 21.60, 20.45, 19.39, 18.41, 17.50},  // 70kg
        {33.33, 31.22, 29.30, 27.55, 25.95, 24.49, 23.15, 21.91, 20.78, 19.72, 18.75},  // 75kg
        {35.56, 33.30, 31.25, 29.38, 27.68, 26.12, 24.69, 23.37, 22.16, 21.04, 20.00},  // 80kg
        {37.78, 35.38, 33.20, 31.22, 29.41, 27.76, 26.23, 24.84, 23.55, 22.35, 21.25},  // 85kg
        {40.00, 37.46, 35.16, 33.06, 31.14, 29.39, 27.78, 26.30, 24.93, 23.67, 22.50},  // 90kg
        {42.22, 39.54, 37.11, 34.89, 32.87, 31.02, 29.32, 27.76, 26.32, 24.98, 23.75},  // 95kg
        {44.44, 41.62, 39.06, 36.73, 34.60, 32.65, 30.86, 29.22, 27.70, 26.30, 25.00},  // 100kg
        {46.67, 43.70, 41.02, 38.57, 36.33, 34.29, 32.41, 30.68, 29.09, 27.61, 26.25},  // 105kg
        {48.89, 45.79, 42.97, 40.40, 38.06, 35.92, 33.95, 32.14, 30.47, 28.93, 27.50},  // 110kg
        {51.11, 47.87, 44.92, 42.24, 39.79, 37.55, 35.49, 33.60, 31.86, 30.24, 28.75},	// 115kg
        {53.33, 49.95, 46.88, 44.08, 41.52, 39.18, 37.04, 35.06, 33.24, 31.56, 30.00},  // 120kg
		{55.56, 52.03, 48.83, 45.91, 43.25, 40.82, 38.58, 36.52, 34.63, 32.87, 31.25},  // 125kg
    	{57.78, 54.11, 50.78, 47.75, 44.98, 42.45, 40.12, 37.98, 36.01, 34.19, 32.50},  // 130kg
    	{60.00, 56.19, 52.73, 49.59, 46.71, 44.08, 41.67, 39.44, 37.40, 35.50, 33.75},  // 135kg
		{62.22, 58.27, 54.69, 51.42, 48.44, 45.71, 43.21, 40.91, 38.78, 36.82, 35.00},  // 140kg
        	 	 	 	 	 
    };

    double pesosList[] = { 50, 55, 60, 65, 70, 75, 80, 85,  90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140};
    double alturasList[] = {1.50, 1.55, 1.60, 1.65, 1.70, 1.75, 1.80, 1.85, 1.90, 1.95, 2.00};

    cout << setw(16) << COR_E_A << ADEST << COR_A << "Altura(m)" << RESET 
	<< COR_T << DEST << setw(54) <<"Tabela do IMC (Estendida)" << endl << endl; // tabela extendida
    cout << RESET << COR_E_P << PDEST << COR_P << " Peso(kg)" << RESET << " " << RESET;
    for (int i = 0; i < alturas; i++) {
    	if(alturasList[i] >= 1.50 && alturasList[i] <= 1.9 && alturasList[i] != 1.55 && alturasList[i] != 1.65 && alturasList[i] != 1.75 && alturasList[i] != 1.85){
        cout << RESET << COR_E_A << ADEST << COR_A << setw(4) << "" << alturasList[i] << "0m" << RESET << " ";
		}
		
    	if(alturasList[i] >= 1.55 && alturasList[i] <= 1.95 && alturasList[i] != 1.6 && alturasList[i] != 1.85 && alturasList[i] != 1.7 && alturasList[i] != 1.8 && alturasList[i] != 1.9){
        cout << RESET << COR_E_A << ADEST << COR_A << setw(4) << ""  << alturasList[i] << "m" << RESET << " ";
		}
		
		if (alturasList[i] == 1.85){
		cout << RESET << COR_E_A << ADEST << COR_A << setw(4) << ""  << alturasList[i] << "m" << RESET << " ";	
		}
		
  		else  if(alturasList[i] == 2 ){
		cout << RESET << COR_E_A << ADEST << COR_A << setw(4) << ""  << alturasList[i] << ".00m" << RESET << " ";
		}
    }
    cout << endl;

       for (int i = 0; i < pesos; i++) {
       	if(pesosList[i] <= 50){
			   cout << RESET << COR_E_P << PDEST << COR_P << setw(7) 
			   << endl << setw(4)<< pesosList[i] << ".00kg" << RESET << " ";
		   }
		   
		if(pesosList[i] >= 55 && pesosList[i] <=95 ){
			   cout << RESET << COR_E_P << PDEST << COR_P << setw(7) 
			   << endl << setw(7)<< pesosList[i] << "kg" << RESET << " ";
		   }
		   
        else if (pesosList[i] >= 100)
   	           cout << RESET << COR_E_P << PDEST << COR_P << setw(7) 
		  << endl << pesosList[i] << "kg" << RESET << " " << RESET;

		  
        for (int j = 0; j < alturas; j++) {
            double imc = valoresIMC[i][j];
		
            if (imc >= 12.50 && imc <= 16) {
                cout << COR_E_1 << DEST1 << COR_1 << setw(9) 
				<< fixed << setprecision(2) << imc << RESET << " " << RESET;
            }
            
            if (imc >= 16.01 && imc <= 18.4) {
                cout << COR_E_2 << DEST2 << COR_2 << setw(9) 
				<< fixed << setprecision(2) << imc << RESET << " " << RESET;
            }
            
            if (imc >= 18.41 && imc <= 23.9) {
                cout << COR_E_3 << DEST3 << COR_3 << setw(9) 
				<< fixed << setprecision(2) << imc << RESET << " " << RESET;
            }
            
            if (imc >= 23.91 && imc <= 28.9) {
                cout << COR_E_4 << DEST4 << COR_4 << setw(9) 
				<< fixed << setprecision(2) << imc << RESET << " " << RESET;
            }
            
            if (imc >= 28.91 && imc <= 34.9) {
                cout << COR_E_5 << DEST5 << COR_5 << setw(4) 
				<< fixed << setprecision(2) << "I " << imc << RESET << " " << RESET;
            }
            
            if (imc >= 34.91 && imc <= 39.9) {
                cout << COR_E_6 << DEST6 << COR_6 << setw(4) 
				<< fixed << setprecision(2) << "II " << imc << RESET << " " << RESET;
            }
            if (imc >= 39.91 && imc <= 62.22) {
                cout << COR_E_7 << DEST7 << COR_7 << setw(3) 
				<< fixed << setprecision(2) << "III " << imc << RESET << " " << RESET;
            }
            
        }
        cout << endl;
    }
}

void imprimirLegendaIMC() {
    cout << DEST << endl << setw(72) << "Tabela do IMC (Reduzida)\n" << RESET // tamanho reduzida

<< setw(80) << "|---------------------------------------|\n"  
	<< setw(43) << COR_L << "|" << RESET << COR_E_1 
	<< "IMC < 16 -> Muito abaixo do peso" 
	<< setw(12) << COR_L << COR_E_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"
	<< setw(43) << COR_L << "|" << RESET << COR_E_2 
	<< "16 - 18.49 -> Abaixo do peso" 
	<< setw(16) << COR_L << COR_E_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"    
	<< setw(43) << COR_L << "|" << RESET << COR_E_3 
	<< "18.5 - 23.99 -> Peso normal" 
	<< setw(17) << COR_L << COR_E_L << "|" << RESET  <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"    
	<< setw(43) << COR_L << "|" << RESET << COR_E_4 
	<<"24 - 28.99 -> Acima do peso" 
	<< setw(17) << COR_L  << COR_E_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"
	<< setw(43) << COR_L << "|" << RESET << COR_E_5 
	<< "29 - 34.99 -> Obesidade I" 
	<< setw(19) << COR_L << COR_E_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"
	<< setw(43) << COR_L << "|" << RESET << COR_E_6 
	<< COR_6 <<"35 - 39.99 -> Obesidade II (severa)" 
	<< setw(9) << COR_L << COR_E_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n"
	<< setw(43) << COR_L << "|" << RESET << COR_E_7 
	<< COR_7 <<">= 40 -> Obesidade III (mórbida)" 
    << setw(12) << COR_L << "|" << RESET <<"\n" << RESET

<< setw(80) << "|---------------------------------------|\n";
}

