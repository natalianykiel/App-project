//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_INDIVIDUAL_H
#define HOTELPROJECT_INDIVIDUAL_H

#include <iostream>
#include "typedefs.h"
#include "Reservation.h"

class Individual:public Reservation {
private:
    int numberOfPeople;
    int numberOfKids;
    bool VIP;
public:
    Individual(int reservationId, double pricePerPerson, const Client_ptr &client, int numberOfPeople, int numberOfKids,
               bool vip);

    ~Individual();

    int getNumberOfAdults();
    double getPrice();

    int isVip() const;

    int getNumberOfKids() const;

    int getNumberOfPeople() const;

    std::string getReservationInfo();
};


#endif //HOTELPROJECT_INDIVIDUAL_H
