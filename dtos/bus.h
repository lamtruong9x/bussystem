//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_BUS_H
#define BUSSYSTEM_BUS_H

#include <ostream>

namespace dto {
    class Bus {
        int id;
        static const int numOfSeat = 20;
    public:
        int getId() const;

        static const int getNumOfSeat();

        void setId(int id);

        explicit Bus(int id);

        friend std::ostream &operator<<(std::ostream &os, const Bus &bus);

        Bus();
    };
}

#endif //BUSSYSTEM_BUS_H
