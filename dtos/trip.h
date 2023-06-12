//
// Created by Working on 6/11/2023.
//

#ifndef BUSSYSTEM_TRIP_H
#define BUSSYSTEM_TRIP_H
#include <string>
#include <ostream>
#include "time.h"
#include "date.h"
#include "bus.h"

namespace dto {
    class Trip {
        Bus bus;
        std::string id;
        std::string departure;
        std::string destination;
        dt::Date travelDate;
    public:
        Trip();

    private:
    public:
        void setId(const std::string &id);

        void setDestination(const std::string &destination);

        void setDeparture(const std::string &departure);

        void setTravelDate(const dt::Date &travelDate);

        void setTravelTime(const dt::Time &travelTime);

    private:
        dt::Time travelTime;
    public:
        Bus &getBus();

    public:
        Trip(const int busId, const std::string &departure,  const std::string &destination, const dt::Date &travelDate,
             const dt::Time &travelTime);

        const std::string &getId() const;

        const std::string &getDestination() const;

        const std::string &getDeparture() const;

        const dt::Date &getTravelDate() const;

        const dt::Time &getTravelTime() const;

        friend std::ostream &operator<<(std::ostream &os, const Trip &trip);
    };

}
#endif //BUSSYSTEM_TRIP_H
