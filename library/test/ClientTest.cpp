//
// Created by student on 21.06.23.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Client.h"


BOOST_AUTO_TEST_SUITE(ClientTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Client_ptr client(new Client("Jan","Kowalski",1,"123456789"));
        BOOST_CHECK_EQUAL(client->getFirstName(),"Jan");
        BOOST_CHECK_EQUAL(client->getLastName(),"Kowalski");
        BOOST_CHECK_EQUAL(client->getClientId(),1);
        BOOST_CHECK_EQUAL(client->getPhoneNumber(),"123456789");
    }

BOOST_AUTO_TEST_SUITE_END()