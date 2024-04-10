//
// Created by student on 21.06.23.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Group.h"
#include "Individual.h"
#include "Client.h"
BOOST_AUTO_TEST_SUITE(ReservationTest)

BOOST_AUTO_TEST_CASE(Constructor1Test) {
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        Group_ptr g(new Group(1, 50, client, 3, 5));
        BOOST_CHECK_EQUAL(g->getReservationId(),1);
        BOOST_CHECK_EQUAL(g->getPricePerPerson(),50);
        BOOST_CHECK_EQUAL(g->getClient(),client);
        BOOST_CHECK_EQUAL(g->getNumberOfGroups(),3);
        BOOST_CHECK_EQUAL(g->getGroupSize(), 5);
}

    BOOST_AUTO_TEST_CASE(Constructor2Test) {
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        Individual_ptr i(new Individual(1, 60, client, 5, 2, true));
        BOOST_CHECK_EQUAL(i->getReservationId(),1);
        BOOST_CHECK_EQUAL(i->getPricePerPerson(),60);
        BOOST_CHECK_EQUAL(i->getClient(),client);
        BOOST_CHECK_EQUAL(i->getNumberOfPeople(), 5);
        BOOST_CHECK_EQUAL(i->getNumberOfKids(), 2);
    }

    BOOST_AUTO_TEST_CASE(PriceTest) {
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        Individual_ptr i1(new Individual(1, 60, client, 5, 2, true));
        Individual_ptr i2(new Individual(2, 50, client, 4, 1, false));
        Group_ptr g1(new Group(1, 50, client, 3, 5));
        Group_ptr g2(new Group(1, 30, client, 5, 6));
        BOOST_CHECK_EQUAL(i1->getPrice(),720);
        BOOST_CHECK_EQUAL(i2->getPrice(),175);
        BOOST_CHECK_EQUAL(g1->getPrice(),675);
        BOOST_CHECK_EQUAL(g2->getPrice(),720);
    }

BOOST_AUTO_TEST_SUITE_END()
