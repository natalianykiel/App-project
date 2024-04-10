//
// Created by student on 19.06.23.
//

#include "Client.h"

Client::Client(std::string firstName, std::string lastName, int clientId, std::string phoneNumber)
        : firstName(firstName), lastName(lastName), clientID(clientId), phoneNumber(phoneNumber) {}

Client::~Client() {

}

std::string Client::getFirstName() {
    return firstName;
}

std::string Client::getLastName() {
    return lastName;
}

int Client::getClientId() {
    return clientID;
}

std::string Client::getPhoneNumber() {
    return phoneNumber;
}
