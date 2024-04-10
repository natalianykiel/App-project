cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/managers/HotelManager.cpp
        src/Hotel.cpp
        src/managers/ReservationManager.cpp
        src/Reservation.cpp
        src/Individual.cpp
        src/Group.cpp
        src/Client.cpp
        src/managers/ClientManager.cpp
        include/repositories/Repository.h include/exceptions/FormatErrorException.h include/exceptions/ReservationException.h src/exceptions/ReservationException.cpp src/exceptions/FormatErrorException.cpp include/exceptions/ReservationException.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/master.cpp

        src/Client.cpp
        src/Group.cpp
        src/Individual.cpp
        src/Hotel.cpp
        include/repositories/Repository.h test/ClientTest.cpp test/HotelTest.cpp test/ReservationTest.cpp test/ReservationManagerTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})
target_include_directories(LibraryTest PUBLIC include)

target_link_libraries(LibraryTest
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
