#ifndef FLOWER_H
#define FLOWER_H

#pragma once
#include "Plant.h"

static char* months[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Flower : public Plant
{
public:
    Flower(const char* p, const char* s, const unsigned int h, const Type t, unsigned int* g);
    virtual Plant* clone() const override;
    virtual char* description() const override;
    ~Flower();

private:
    unsigned int growingMonths[12]{};
    virtual bool typePred(const Type& t) const override;
};

#endif