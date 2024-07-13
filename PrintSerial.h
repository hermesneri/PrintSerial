#ifndef PrintSerial_h
#define PrintSerial_h

#include <Arduino.h>

class PrintSerial {
public:
    PrintSerial();

    bool begin(int baudrate, uint8_t print_level);

    // Métodos de impressão com diferentes cores
    void done(const std::string &message);
    void log(const std::string &message);
    // void logln(const std::string &message);
    void logln(const char* format, ...);
    void warning(const std::string &message);
    void error(const std::string &message);

private:
    void setColor(const char *colorCode);
};

#endif
