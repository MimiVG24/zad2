#include "Garden.h"

Garden::Garden(size_t cap) {
    plants = new Plant*[cap];
}

void Garden::plant(const Plant& p) {
    if (count >= capacity) throw std::logic_error("cannot plant");
    plants[count] = p.clone();
    ++count;
}
void Garden::eradicate(const Type& type) {
    for (size_t i = 0; i < count; ) {
        if (plants[i]->getType() & type) {
            std::swap(plants[i], plants[count - 1]);
            delete plants[count - 1];
            --count;
        }
        else ++i;
    }
}
void Garden::info() const {
    for (size_t i = 0; i < count; ++i) {
        std::cout << plants[i]->description() << std::endl;
    }
}

Garden::~Garden() {
    for (size_t i = 0; i < count; ++i) {
        delete plants[i];
    }
    delete[] plants;
}