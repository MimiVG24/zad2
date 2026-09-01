#include "Flower.h"

Flower::Flower(const char* p, const char* s, const unsigned int h, const Type t, const unsigned int* g) : Plant(p, s, h, t)
{
    setGrowingMonths(g);
} 

Flower::Flower(const Flower& other) : Flower(other.produce, other.sort, other.height, other.getType(), other.growingMonths) {}
Flower& Flower::operator=(const Flower& other) {
    if (this != &other) {
    Plant::operator=(other);
    setGrowingMonths(other.growingMonths);
    } 
    return *this;
}

const unsigned int* Flower::getGrowingMonths() const {return growingMonths;}
void Flower::setGrowingMonths(const unsigned int* months) {
    unsigned index = 0;
    while (months[index]) {
        growingMonths[index] = months[index];
        index++;
    }
}

Plant* Flower::clone() const {
    return new Flower(*this);
}
char* Flower::description() const {
    char* concated = new char[strlen(produce) + strlen(sort) + 3];
    strcpy(concated, produce);
    strcat(concated, "-");
    strcat(concated, sort);
    strcat(concated, " ");

    unsigned totalLength = 0;
    unsigned counter = 0;
    while (growingMonths[counter] && counter < 12) {
        totalLength += strlen(months[growingMonths[counter++] - 1]);
    }
    char* monDesc = new char[totalLength + counter + 1];
    monDesc[0] = '\0';

    unsigned index = 0;
    while (growingMonths[index]) {
        strcat(monDesc, months[growingMonths[index++] - 1]);
        strcat(monDesc, " ");
    }

    char* desc = new char[strlen(concated) + strlen(monDesc) + 1];
    strcpy(desc, concated);
    strcat(desc, monDesc);

    delete[] concated;
    delete[] monDesc;

    return desc;

}

Flower::~Flower()
{

}
