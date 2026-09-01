#include "Plant.h"

Plant::Plant(const char* p, const char* s, const unsigned int h, const Type t) : height(h), type(t)
{
    setProduce(p);
    setSort(s);
}

Plant::Plant(const Plant& other) : Plant(other.produce, other.sort, other.height,other.type) {}
Plant& Plant::operator=(const Plant& other) {
    if (this != &other) {
        char* newProduce = new char[strlen(other.produce) + 1];
        strcpy(newProduce, other.produce);
        char* newSort;

        try {
            newSort = new char[strlen(other.sort) + 1];
            strcpy(newSort, other.sort);
            
        } catch (...) {
            delete[] newProduce;
            throw;
        }

        delete[] this->sort;
        this->sort = newSort;

        delete[] this->produce;
        this->produce = newProduce;
        this->height = other.height;
    }

    return *this;
}

const char* Plant::getProduce() const {return produce;}
const char* Plant::getSort() const {return sort;}
const unsigned int Plant::getHeight() const {return height;}
const Type Plant::getType() const {return type;}

void Plant::setProduce(const char* produce) {
    if (!produce) throw std::logic_error("produce is null");

    char* copy = new char[strlen(produce) +1];
    strcpy(copy, produce);
    delete[] this->produce;
    this->produce = copy;
}
void Plant::setSort(const char* sort) {
    if (!sort) throw std::logic_error("sort is null");

    char* copy = new char[strlen(sort) +1];
    strcpy(copy, sort);
    delete[] this->sort;
    this->sort = copy;
}
void Plant::setHeight(unsigned int h) {this->height = h;}

Plant::~Plant()
{
    delete[] produce;
    delete[] sort;
}
