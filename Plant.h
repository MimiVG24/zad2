#ifndef PLANT_H
#define PLANT_H

#pragma once
#include <iostream>

enum Type {
    Grass = 16,
    Tree = 8, 
    Bush = 4, 
    Moss = 2, 
    Other = 1
};

class Plant
{
public:
    Plant(const char* p, const char* s, const unsigned int h, const Type t);

    Plant(const Plant& other); 
    Plant& operator=(const Plant& other);

    const char* getProduce() const;
    const char* getSort() const;
    const unsigned int getHeight() const;
    const Type getType() const;
    void setProduce(const char* produce);
    void setSort(const char* sort);
    void setHeight(unsigned int h);

    virtual Plant* clone() const = 0;
    virtual char* description() const = 0;

    virtual ~Plant();
protected:
    char* produce;
    char* sort;
    unsigned int height;

private:
    Type type;
    virtual bool typePred(const Type& t) const;

};

#endif
