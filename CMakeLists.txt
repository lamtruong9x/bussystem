cmake_minimum_required(VERSION 3.25)
project(BusSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BusSystem main.cpp dtos/date.h menuchoice.hpp dtos/date.cpp dtos/time.cpp menuchoice_modify.hpp dtos/passenger.cpp dtos/passenger.h dtos/trip.cpp dtos/trip.h dtos/ticket.cpp dtos/ticket.h dtos/bus.cpp dtos/bus.h repo/repository.cpp repo/repository.h repo/trip_repo.cpp repo/trip_repo.h repo/passenger_repo.cpp repo/passenger_repo.h)

