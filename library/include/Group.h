//
// Created by student on 19.06.23.
//
#ifndef HOTELPROJECT_GROUP_H
#define HOTELPROJECT_GROUP_H
#include <iostream>
#include "typedefs.h"
#include "Reservation.h"


class Group: public Reservation {
private:
    int numberOfGroups;
    int groupSize;
public:
    Group(int reservationId, double pricePerPerson, const Client_ptr &client, int numberOfGroups, int groupSize);

    ~Group();
    int getNumberOfAdults();
    double getPrice();

    int getNumberOfGroups() const;

    int getGroupSize() const;

    std::string getReservationInfo();

};


#endif //HOTELPROJECT_GROUP_H
