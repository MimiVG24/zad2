#ifndef GARDEN_H
#define GARDEN_H

#pragma once
#include "Plant.h"

class Garden
{
public:
    Garden(size_t cap);
    void plant(const Plant& p);
    void eradicate(const Type& type);
    void info() const;
    ~Garden();

private:
    Plant** plants;
    size_t capacity;
    size_t count;
};

#endif
