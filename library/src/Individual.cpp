//
// Created by student on 19.06.23.
//

#include "Individual.h"
#include <sstream>


Individual::~Individual() {

}

int Individual::getNumberOfAdults() {
    return numberOfPeople-numberOfKids;
}

double Individual::getPrice() {
    return (getNumberOfAdults() * (isVip() * getPricePerPerson())) + (numberOfKids * (isVip() * getPricePerPerson() * 0.50));
}

int Individual::isVip() const {
    if(VIP==true){
        return 3;
    }else{
        return 1;
    }
}

Individual::Individual(int reservationId, double pricePerPerson, const Client_ptr &client, int numberOfPeople,
                       int numberOfKids, bool vip) : Reservation(reservationId, pricePerPerson, client),
                                                     numberOfPeople(numberOfPeople), numberOfKids(numberOfKids),
                                                     VIP(vip) {}

int Individual::getNumberOfKids() const {
    return numberOfKids;
}

int Individual::getNumberOfPeople() const {
    return numberOfPeople;
}

std::string Individual::getReservationInfo() {
    std::stringstream info;
    info << "Individual Reservation id: "<<getReservationId()<<" ,pricePerPerson "<<getPricePerPerson()<<", number of People: "<<numberOfPeople<<", VIP: "<<VIP;
    return info.str();
}
