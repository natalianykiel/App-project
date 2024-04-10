//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_RESERVATIONMANAGER_H
#define MHOTELPROJECT_RESERVATIONMANAGER_H
#include <iostream>
#include <memory>
#include <vector>
#include "typedefs.h"
#include "repositories/Repository.h"
#include "Hotel.h"
#include "Client.h"
#include "Reservation.h"
#include "Individual.h"
#include "Group.h"


class ReservationManager{
private:
    Repository<Reservation> currentReservations;
    Repository<Reservation> archiveReservations;
public:
    ReservationManager(Repository<Reservation> repository, Repository<Reservation> repository1);

    ~ReservationManager();

    Reservation_ptr createIndividualReservation(const int &reservationID, const double &pricePerPerson, const int &numberOfPeople,const int &numberOfKids, const bool &VIP, Hotel_ptr hotel, Client_ptr client);
    Reservation_ptr createGroupReservation(const int &reservationID, const double &pricePerPerson,const int numberOfGroups,const int groupSize, Hotel_ptr hotel, Client_ptr client);
    void endReservation(Reservation_ptr reservation);
    int getCurrentAdults();
    int sizeCurrentReservations();
    int sizeArchiveReservations();
    Reservation_ptr findReservation(int id);
    void saveToFileReservations();
};


#endif //HOTELPROJECT_RESERVATIONMANAGER_H
