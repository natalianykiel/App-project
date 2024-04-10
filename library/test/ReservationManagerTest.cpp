//
// Created by student on 21.06.23.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Hotel.h"
#include "Client.h"
#include "managers/ReservationManager.h"
#include "repositories/Repository.h"

BOOST_AUTO_TEST_SUITE(ReservationManagerTest)

    BOOST_AUTO_TEST_CASE(CreateReservationTest) {
        Repository<Reservation> testCurrentReservations;
        Repository<Reservation> testArchiveReservations ;
        Hotel_ptr hotel(new Hotel(10));
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        ReservationManager rm(testCurrentReservations, testArchiveReservations);
        rm.createIndividualReservation(1, 60, 5, 2, true, hotel, client);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),3);
        rm.createGroupReservation(2, 40, 2, 3, hotel, client);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),9);
        rm.createIndividualReservation(3, 90, 2, 0, false, hotel, client);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),9);
    }

    BOOST_AUTO_TEST_CASE(RemoveReservationTest) {
        Repository<Reservation> testCurrentReservations;
        Repository<Reservation> testArchiveReservations ;
        Hotel_ptr hotel(new Hotel(10));
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        ReservationManager rm(testCurrentReservations, testArchiveReservations);
        rm.createIndividualReservation(1, 60, 5, 2, true, hotel, client);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),3);
        Reservation_ptr r1 = rm.createGroupReservation(2, 40, 2, 3, hotel, client);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),9);
        rm.endReservation(r1);
        BOOST_CHECK_EQUAL(rm.getCurrentAdults(),3);
    }

    BOOST_AUTO_TEST_CASE(ExceptionTest) {
        Repository<Reservation> testCurrentReservations;
        Repository<Reservation> testArchiveReservations ;
        Hotel_ptr hotel(new Hotel(10));
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        ReservationManager rm(testCurrentReservations, testArchiveReservations);
        BOOST_REQUIRE_THROW(rm.createIndividualReservation(1, 60, 0, 0, true, hotel, client), std::logic_error);
        BOOST_REQUIRE_THROW(rm.createGroupReservation(2, 40, 0, 0, hotel, client), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(ReservationSizeTest) {
        Repository<Reservation> testCurrentReservations;
        Repository<Reservation> testArchiveReservations ;
        Hotel_ptr hotel(new Hotel(10));
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        ReservationManager rm(testCurrentReservations, testArchiveReservations);
        BOOST_CHECK_EQUAL(rm.sizeCurrentReservations(),0);
        BOOST_CHECK_EQUAL(rm.sizeArchiveReservations(),0);
        rm.createIndividualReservation(1, 60, 5, 2, true, hotel, client);
        BOOST_CHECK_EQUAL(rm.sizeCurrentReservations(),1);
        BOOST_CHECK_EQUAL(rm.sizeArchiveReservations(),0);
        Reservation_ptr r2 = rm.createGroupReservation(2, 40, 2, 3, hotel, client);
        BOOST_CHECK_EQUAL(rm.sizeCurrentReservations(),2);
        BOOST_CHECK_EQUAL(rm.sizeArchiveReservations(),0);
        rm.endReservation(r2);
        BOOST_CHECK_EQUAL(rm.sizeCurrentReservations(),1);
        BOOST_CHECK_EQUAL(rm.sizeArchiveReservations(),1);
    }
BOOST_AUTO_TEST_SUITE_END()