//
// Created by student on 21.06.23.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Hotel.h"


BOOST_AUTO_TEST_SUITE(HotelTest)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Hotel_ptr hotel(new Hotel(50));
        BOOST_CHECK_EQUAL(hotel->getCapacity(),50);
    }

BOOST_AUTO_TEST_SUITE_END()