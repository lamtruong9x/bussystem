#include <iostream>
#include "vector"
#include "./repo/passenger_repo.h"
int main() {
    auto repo = repo::repository();
    auto passenger_repo = repo::passenger_repo(repo);

    auto truong = dto::Passenger("0387855500", "Dam Lam Truong");
    passenger_repo.create(truong);
    auto tr = passenger_repo.getByPhone("0387855500");
    std::cout << tr->getFullName() << std::endl;
}
