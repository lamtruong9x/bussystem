//
// Created by Lam Truong on 6/12/23.
//

#ifndef BUSSYSTEM_PASSENGER_REPO_H
#define BUSSYSTEM_PASSENGER_REPO_H
#include "../dtos/passenger.h"
#include "repository.h"

namespace repo {
    class passenger_repo {
        repository& repo;

    public:
        explicit passenger_repo(repository &repo);
        bool create(dto::Passenger &p);
        dto::Passenger* getByPhone(std::string phoneNumber);
        dto::Passenger* getByName(std::string name);
        bool isExist(std::string phoneNumber);
    };
}


#endif //BUSSYSTEM_PASSENGER_REPO_H
