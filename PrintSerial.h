#ifndef PrintSerial_h
#define PrintSerial_h

#include <Arduino.h>

class PrintSerial {
public:
    PrintSerial();

    bool begin(int baudrate, uint8_t print_level);

    // Métodos de impressão com diferentes cores
    void done(const String &message);
    void log(const String &message);
    void logln(const String &message);
    void warning(const String &message);
    void error(const String &message);

private:
    void setColor(const char *colorCode);
};

#endif
