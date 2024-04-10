//
// Created by student on 19.06.23.
//
#include "managers/ReservationManager.h"
#include "typedefs.h"
#include "Reservation.h"
#include "exceptions/ReservationException.h"
#include<fstream>
#include <sstream>

ReservationManager::~ReservationManager() = default;




Reservation_ptr ReservationManager::createIndividualReservation(const int &reservationID, const double &pricePerPerson,
                                                                const int &numberOfPeople, const int &numberOfKids,
                                                                const bool &VIP, Hotel_ptr hotel, Client_ptr client) {
    Individual_ptr newReservation = std::make_shared<Individual>(reservationID, pricePerPerson, client, numberOfPeople,
                                                                 numberOfKids, VIP);
    if (hotel->getCapacity() >= newReservation->getNumberOfAdults()+ getCurrentAdults()){
        if (newReservation->getNumberOfAdults() <= 0) {
            throw ReservationException(ReservationException::invalidNumberOfAdults);
        } else {
            currentReservations.add(newReservation);
            return newReservation;
        }
    }
}
Reservation_ptr ReservationManager::createGroupReservation(const int &reservationID, const double &pricePerPerson,
                                                           const int numberOfGroups, const int groupSize,
                                                           Hotel_ptr hotel, Client_ptr client) {
    Group_ptr newReservation = std::make_shared<Group>(reservationID, pricePerPerson, client, numberOfGroups,
                                                       groupSize);
    if (hotel->getCapacity() >= newReservation->getNumberOfAdults()+ getCurrentAdults()) {
        if(newReservation->getNumberOfAdults()<=0){
            throw ReservationException(ReservationException::invalidNumberOfAdults);
        }else {
            currentReservations.add(newReservation);
            return newReservation;
        }
    }
}

void ReservationManager::endReservation(Reservation_ptr reservation) {
    archiveReservations.add(reservation);
    currentReservations.eraseObjectFromRepository(reservation);
}
    ReservationManager::ReservationManager(Repository<Reservation>
    repository, Repository<Reservation>
    repository1){

    }

int ReservationManager::getCurrentAdults() {
    int licznik = 0;
    for(int i =0; i < currentReservations.size(); i++){
        licznik += currentReservations.get(i)->getNumberOfAdults();
    }
    return licznik;
}

Reservation_ptr ReservationManager::findReservation(int id) {
    for(int i=0;i < currentReservations.size();i++){
        if(currentReservations.get(i)->getReservationId()==id){
            return currentReservations.get(i);
        }
    }
}

int ReservationManager::sizeCurrentReservations() {
    return currentReservations.size();
}

int ReservationManager::sizeArchiveReservations() {
    return archiveReservations.size();
}

void ReservationManager::saveToFileReservations() {
    std::fstream plik;
    plik.open( "/home/student/CLionProjects/mkar_cz_1400_01/projekt/program/src/ReservationsRepository.txt", std::ios::out );
    if( plik.good() == true )
    {
        std::cout << "Dostep do pliku!" << std::endl;
        std::stringstream zmienna;
        for (int i = 0; i < this->currentReservations.findAll().size(); i++)
        {
            zmienna << this->currentReservations.get(i)->getReservationInfo()<< std::endl;
            plik << zmienna.str();
            zmienna.str("");
            zmienna << "---------" << std::endl;
            plik << zmienna.str();
            zmienna.str("");
        }
        plik.close();
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

