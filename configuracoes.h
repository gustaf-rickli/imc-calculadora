
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


void setup() {
	setlocale(LC_ALL, "portuguese");
	enableANSI();
}

