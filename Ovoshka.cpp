#include "Ovoshka.h"

Ovoshka::Ovoshka(const char* p, const char* s, const unsigned int h, const Type t, const char* rec) : Plant(p, s, h, t)
{
    if (!typePred(t)) throw std::logic_error("ovoshkite can be only trees or bushes");
    setRecepie(rec);
}

Ovoshka::Ovoshka(const Ovoshka& other) : Ovoshka(other.produce, other.sort, other.height, other.getType(),other.recepie) {}
Ovoshka& Ovoshka::operator=(const Ovoshka& other) {
    if(this != &other) {
        char* copy = new char[strlen(other.recepie) + 1];
        strcpy(copy, other.recepie);
        try{
        Plant::operator=(other);
        } catch (...) {
            delete[] copy;
            throw;
        }
        delete[] this->recepie;
        this->recepie = copy;
    }
    return *this;
}

const char* Ovoshka::getRecepie() const {return recepie;}
void Ovoshka::setRecepie(const char* rec) {
    if (!rec) throw std::logic_error("recepie is null");

    char* copy = new char[strlen(rec) +1];
    strcpy(copy, rec);
    delete[] this->recepie;
    this->recepie = copy;
}
Plant* Ovoshka::clone() const {
    return new Ovoshka(*this);
}
char* Ovoshka::description() const {
    char* desc = new char[strlen(produce) + strlen(sort) + strlen(recepie) + 3];
    strcpy(desc, produce);
    strcat(desc, " ");
    strcat(desc, sort);
    strcat(desc, " ");
    strcat(desc, recepie);

    return desc;
}
bool Ovoshka::typePred(const Type& t) const {
    return (t & Type::Bush) || (t & Type::Tree);
}

Ovoshka::~Ovoshka()
{
    delete[] recepie;
}
