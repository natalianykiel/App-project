//
// Created by student on 21.06.23.
//

#ifndef HOTELPROJECT_RESERVATIONEXCEPTION_H
#define HOTELPROJECT_RESERVATIONEXCEPTION_H
#include <stdexcept>
#include <string>


class ReservationException : public std::logic_error
{
public:
    explicit ReservationException(const std::string &);

    static const std::string invalidNumberOfAdults;
};






#endif //HOTELPROJECT_RESERVATIONEXCEPTION_H
