//
// Created by Working on 6/11/2023.
//

#include "bus.h"

dto::Bus::Bus(int id) : id(id) {}

int dto::Bus::getId() const {
    return id;
}

const int dto::Bus::getNumOfSeat() {
    return numOfSeat;
}

std::ostream &dto::operator<<(std::ostream &os, const dto::Bus &bus) {
    os << "id: " << bus.id;
    return os;
}

dto::Bus::Bus() {}

void dto::Bus::setId(int id) {
    Bus::id = id;
}
