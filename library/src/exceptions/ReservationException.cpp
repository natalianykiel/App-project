//
// Created by student on 21.06.23.
//
#include "exceptions/ReservationException.h"
using namespace std;
ReservationException::ReservationException(const std::string &exc) : logic_error(exc)
{}

const string ReservationException::invalidNumberOfAdults = "Invalid number of people. Please provide a valid number.";
