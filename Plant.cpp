#include "Plant.h"

Plant::Plant()
{

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
void Plant::setHeight(unsigned int h) {this->height = height;}

Plant* Plant::clone() const {
    return new Plant(*this);
}
Plant::~Plant()
{

}