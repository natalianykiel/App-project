//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_CLIENT_H
#define HOTELPROJECT_CLIENT_H
#include <iostream>
#include "typedefs.h"

class Client {
private:
   std::string firstName;
   std::string lastName;
   int clientID;
   std::string phoneNumber;
public:
    Client(std::string, std::string, int, std::string);
    ~Client();

    std::string getFirstName();
    std::string getLastName();
    int getClientId();
    std::string getPhoneNumber();

};


#endif //HOTELPROJECT_CLIENT_H
