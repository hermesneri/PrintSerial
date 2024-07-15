#ifndef PrintSerial_h
#define PrintSerial_h

#include <Arduino.h>

class PrintSerial {
public:
    PrintSerial();

    bool begin(int baudrate, uint8_t print_level);

    // Métodos de impressão com diferentes cores
    void done(const char* format, ...);
    void log(const char* format, ...);
    void logln(const char* format, ...);
    void warning(const char* format, ...);
    void error(const char* format, ...);
    void infos(const char* format, ...);
    void backg(const char* format, ...);

private:
    void setColor(const char *colorCode);
};

#endif



/*
>> Text Colors:
Preto: \033[30m
Vermelho: \033[31m
Verde: \033[32m
Amarelo: \033[33m
Azul: \033[34m
Magenta: \033[35m
Ciano: \033[36m
Branco: \033[37m

>> Background Colors:
Preto: \033[40m
Vermelho: \033[41m
Verde: \033[42m
Amarelo: \033[43m
Azul: \033[44m
Magenta: \033[45m
Ciano: \033[46m
Branco: \033[47m

>> Atributes:
Resetar: \033[0m
Negrito: \033[1m
Sublinhado: \033[4m
*/