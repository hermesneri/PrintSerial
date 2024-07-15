/**
 * @file PrintSerial.cpp
 * @author github.com/hermesneri
 * @brief 
 * @version 1.2
 * @date 2024
 */
#include "PrintSerial.h"
#define SERIAL_COLOR //turn-on or turn-off the Color print

uint8_t PRINT_LEVEL;

PrintSerial::PrintSerial()
{
}

/**
 * @brief Configure the baudrate and the level of Prints
 * '0' to NO prints/
 * '1' to print All/
 * '2' to just LOG prints and infos/
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

void PrintSerial::done(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 3)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[32m"); // Green color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset Color
        #endif
    }
}

void PrintSerial::log(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[37m"); // White color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset color
        #endif
    }
}

void PrintSerial::logln(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[37m"); // White color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset color
        #endif
    }
}

void PrintSerial::warning(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 4 || PRINT_LEVEL == 6)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[33m"); // Yellow color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset Color
        #endif
    }
}

void PrintSerial::error(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 5 || PRINT_LEVEL == 6)
    {
        char buffer[256];
        char errorBuffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        snprintf(errorBuffer, sizeof(errorBuffer), "[ERRO] %s", buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[31m"); // Red color ANSI code
        #endif

        Serial.println(errorBuffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset color
        #endif
    }
}

void PrintSerial::infos(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[36m"); // Cyan color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset color
        #endif
    }
}

void PrintSerial::backg(const char* format, ...)
{
    if (PRINT_LEVEL == 1 || PRINT_LEVEL == 2)
    {
        char buffer[256];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        #ifdef SERIAL_COLOR
        setColor("\033[46m"); // Cyan background color ANSI code
        #endif

        Serial.println(buffer);

        #ifdef SERIAL_COLOR
        setColor("\033[0m"); // Reset color
        #endif
    }
}

void PrintSerial::setColor(const char *colorCode)
{
    Serial.print(colorCode);
}
