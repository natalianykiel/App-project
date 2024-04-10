//
// Created by student on 19.06.23.
//

#include "Group.h"
#include <sstream>


Group::~Group() {

}

int Group::getNumberOfAdults() {
    return numberOfGroups*groupSize;
}

std::string Group::getReservationInfo() {
    std::stringstream info;
    info << "Group Reservation id: "<<getReservationId()<<" ,pricePerPerson "<<getPricePerPerson()<<", number of People: "<<getNumberOfAdults();
    return info.str();
}

double Group::getPrice() {
    if(getNumberOfAdults() <= 15){
        return getNumberOfAdults() * getPricePerPerson() * 0.90;
    }else{
        return getNumberOfAdults() * getPricePerPerson() * 0.80;
    }
}

Group::Group(int reservationId, double pricePerPerson, const Client_ptr &client, int numberOfGroups, int groupSize)
        : Reservation(reservationId, pricePerPerson, client), numberOfGroups(numberOfGroups), groupSize(groupSize) {}

int Group::getNumberOfGroups() const {
    return numberOfGroups;
}

int Group::getGroupSize() const {
    return groupSize;
}


