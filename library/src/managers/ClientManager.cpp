//
// Created by student on 19.06.23.
//

#include "managers/ClientManager.h"
#include "typedefs.h"

ClientManager::~ClientManager() = default;


Client_ptr ClientManager::createClient(const std::string &firstName, const std::string &lastName,
                              const int &personalID, const std::string &phoneNumber) {
    Client_ptr newClient = std::make_shared<Client>(firstName, lastName, personalID, phoneNumber);
    clientRepository.add(newClient);
    return newClient;
}

ClientManager::ClientManager(const Repository<Client> &clientRepository) : clientRepository(clientRepository) {}
