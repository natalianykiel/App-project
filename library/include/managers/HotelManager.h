//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_HOTELMANAGER_H
#define HOTELPROJECT_HOTELMANAGER_H
#include <memory>
#include <vector>
#include "typedefs.h"
#include "Hotel.h"
#include "repositories/Repository.h"

class HotelManager{
private:
    Repository<Hotel> hotelRepository;
public:
    explicit HotelManager(const Repository<Hotel> &hotelRepository);

    ~HotelManager();

    Hotel_ptr createHotel(const int &capacity);
};


#endif //HOTELPROJECT_HOTELMANAGER_H
