//
// Created by student on 19.06.23.
//
#ifndef HOTELPROJECT_TYPEDEFS_H
#define HOTELPROJECT_TYPEDEFS_H
#include <memory>
#include <functional>


class Individual;
class Group;
class Reservation;
class Hotel;
class Client;

//repositories
class ReservationRepository;
class ClientRepository;

//managers
class ReservationManager;
class HotelManager;
class ClientManager;


//smart pointer
typedef std::shared_ptr<Client> Client_ptr;
typedef std::shared_ptr<Group> Group_ptr;
typedef std::shared_ptr<Hotel> Hotel_ptr;
typedef std::shared_ptr<Individual> Individual_ptr;
typedef std::shared_ptr<Reservation> Reservation_ptr;

//typedef std::function<bool(Hotel_ptr)> HotelPredicate;
//typedef std::function<bool(Reservation_ptr)> ReservationPredicate;
//typedef std::function<bool(Client_ptr)> ClientPredicate;


#endif //HOTELPROJECT_TYPEDEFS_H
