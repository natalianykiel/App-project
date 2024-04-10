//
// Created by student on 19.06.23.
//

#include "managers/HotelManager.h"

HotelManager::~HotelManager() = default;


Hotel_ptr HotelManager::createHotel(const int &capacity) {
    Hotel_ptr newHotel = std::make_shared<Hotel>(capacity);
    //Hotel *newHotel = new Hotel(capacity);
    hotelRepository.add(newHotel);
    return newHotel;
}

HotelManager::HotelManager(const Repository<Hotel> &hotelRepository) : hotelRepository(hotelRepository) {}
