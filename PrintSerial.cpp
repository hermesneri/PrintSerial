#include "PrintSerial.h"

uint8_t PRINT_LEVEL;

PrintSerial::PrintSerial()
{
    // Construtor, se necessário
}

/**
 * @brief Configure the baudrate and the level of Prints
 * '0' to NO prints/
 * '1' to print All/
 * '2' to just LOG prints/
 * '3' to just DONE prints/
 * '4' to just WARNING prints/
 * '5' to just ERROR prints/
 * '6' to just WARNING and ERROR prints
 * @param baudrate
 * @param print_level
 */
bool PrintSerial::begin(int baudrate, uint8_t print_level)
{
    if (baudrate < 0)
    {
        return false;
    }
    else
    {
        if (print_level > 7 || print_level < 0)
        {
            return false;
        }
    }
    PRINT_LEVEL = print_level;
    Serial.begin(baudrate);
    return true;
}

void PrintSerial::done(const String &message)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 3)
    {
        setColor("\033[32m"); // Código de cor ANSI para verde
        Serial.write(message.c_str(), message.length());
        Serial.write('\n');
        setColor("\033[0m"); // Resetar cor
    }
}

void PrintSerial::log(const String &message)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        setColor("\033[37m"); // Código de cor ANSI para branco
        Serial.write(message.c_str(), message.length());
        setColor("\033[0m"); // Resetar cor
    }
}

void PrintSerial::logln(const String &message)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        setColor("\033[37m"); // Código de cor ANSI para branco
        Serial.write(message.c_str(), message.length());
        Serial.write('\n');
        setColor("\033[0m"); // Resetar cor
    }
}

void PrintSerial::warning(const String &message)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 4 || PRINT_LEVEL == 6)
    {
        setColor("\033[33m"); // Código de cor ANSI para amarelo
        Serial.write(message.c_str(), message.length());
        Serial.write('\n');
        setColor("\033[0m"); // Resetar cor
    }
}

void PrintSerial::error(const String &message)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 5 || PRINT_LEVEL == 6)
    {
        setColor("\033[31m"); // Código de cor ANSI para vermelho
        Serial.write(message.c_str(), message.length());
        Serial.write('\n');
        setColor("\033[0m"); // Resetar cor
    }
}

void PrintSerial::setColor(const char *colorCode)
{
    Serial.print(colorCode);
}
