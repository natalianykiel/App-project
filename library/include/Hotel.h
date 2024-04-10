//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_HOTEL_H
#define HOTELPROJECT_HOTEL_H
#include <iostream>
#include <string>
#include "typedefs.h"
#include <vector>
#include "Reservation.h"

class Hotel {
private:
    int capacity;
public:
    Hotel(int capacity);
    ~Hotel();
    int getCapacity();

};


#endif //HOTELPROJECT_HOTEL_H
