//
// Created by student on 19.06.23.
//

#include "Reservation.h"



Reservation::~Reservation() {

}

int Reservation::getReservationId() {
    return reservationID;
}

double Reservation::getPricePerPerson() {
    return pricePerPerson;
}

Reservation::Reservation(int reservationId, double pricePerPerson, const Client_ptr &client) : reservationID(
        reservationId), pricePerPerson(pricePerPerson), client(client) {}

const Client_ptr &Reservation::getClient() const {
    return client;
}

