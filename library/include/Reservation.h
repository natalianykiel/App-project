//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_RESERVATION_H
#define HOTELPROJECT_RESERVATION_H
#include <iostream>
#include "typedefs.h"

class Reservation{
private:
    int reservationID;
    double pricePerPerson;
    Client_ptr client;
public:
    Reservation(int reservationId, double pricePerPerson, const Client_ptr &client);

    ~Reservation();

    int getReservationId();
    double getPricePerPerson();
    virtual int getNumberOfAdults() = 0;
    virtual double getPrice() = 0;

    const Client_ptr &getClient() const;
    virtual std::string getReservationInfo() = 0;
};


#endif //HOTELPROJECT_RESERVATION_H
