#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
private:
    std::string color;

public:
    Carta(const std::string& color);
    std::string getColor() const;
};

#endif
