//
// Created by student on 19.06.23.
//

#ifndef HOTELPROJECT_CLIENTMANAGER_H
#define HOTELPROJECT_CLIENTMANAGER_H
#include <memory>
#include <vector>
#include "typedefs.h"
#include "repositories/Repository.h"
#include "Client.h"

class ClientManager{
private:
    Repository<Client> clientRepository;
public:
    explicit ClientManager(const Repository<Client> &clientRepository);

    ClientManager();

    ~ClientManager();

    Client_ptr createClient(const std::string &firstName, const std::string &lastName,
                         const int &personalID, const std::string &phoneNumber);
};




#endif //HOTELPROJECT_CLIENTMANAGER_H
