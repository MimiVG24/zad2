#include <iostream>
#include "Flower.h"
#include "Ovoshka.h"
#include "Garden.h"

void typeHelper() {
        std::cout << "1 - Other, 2 - Moss, 4 - Bush, 8 - Tree, 16 - Grass" << std::endl;
};


int main() {
    Type type = Type::Bush;
    unsigned int flowerMonths[2] = {3,4};
    

    Flower flower("VidCvete", "SortCvete", 7, type, flowerMonths);
    std::cout << flower.getType() << std::endl;
    typeHelper();
    std::cout << flower.getGrowingMonths() << std::endl;
    std::cout << flower.description() << std::endl;

    const char* rec = "recepie here";
    Ovoshka ovoshka("VidOvoshka", "SortOvoshka", 6, type, rec);
    std::cout << ovoshka.description() << std::endl;

    Garden garden(2);
    garden.plant(flower);
    garden.plant(ovoshka);
    garden.info();
}
