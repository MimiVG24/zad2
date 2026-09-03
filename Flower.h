#ifndef FLOWER_H
#define FLOWER_H

#pragma once
#include "Plant.h"

const char* months[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Flower : public Plant
{
public:
    Flower(const char* p, const char* s, const unsigned int h, const Type t, const unsigned int* g);

    Flower(const Flower& other);
    Flower& operator=(const Flower& other);

    const unsigned int* getGrowingMonths() const;
    void  setGrowingMonths(const unsigned int* months);
    virtual Plant* clone() const override;
    virtual char* description() const override;
    ~Flower();

private:
    unsigned int growingMonths[12]{};
};

#endif
