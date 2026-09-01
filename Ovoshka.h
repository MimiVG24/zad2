#ifndef OVOSHKA_H
#define OVOSHKA_H

#pragma once
#include "Plant.h"

class Ovoshka : public Plant
{
public:
    Ovoshka(const char* p, const char* s, const unsigned int h, const Type t, const char* rec);

    Ovoshka(const Ovoshka& other);
    Ovoshka& operator=(const Ovoshka& other);

    const char* getRecepie() const;
    void setRecepie(const char* rec);

    virtual Plant* clone() const override;
    virtual char* description() const override;

    ~Ovoshka();

private:
    char* recepie = nullptr;
    virtual bool typePred(const Type& t) const override;
};

#endif
