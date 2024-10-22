#ifndef APPLICATION_USER_SERVICE_HPP
#define APPLICATION_USER_SERVICE_HPP

#include <vector>


#include "../../domain/user/user-service.hpp"
#include "../../application/user/dto-assembler.hpp"


namespace UserApplicationService {
    inline void addUser(const std::string &name, const std::string &surname, const std::string &email, const std::string &phoneNumber, pqxx::connection &conn)
    {
        UserService::addUser(name, surname, email, phoneNumber, conn);
    }

    inline User getUserById(const int id, pqxx::connection &conn)
    {
        return UserService::getUserById(id,conn);
    }

    inline void removeUserById(const int id, pqxx::connection& conn)
    {
        UserService::removeUserById(id, conn);
    }

    inline crow::json::wvalue userList(pqxx::connection &conn)
    {
        const std::vector<User> userList=UserService::userList(conn);
        return DtoAssembler::generateGetList(userList);
    }

    inline  void updateUser(const int& id, const string& name, const string& surname, const string& email, const string& phoneNumber, pqxx::connection& conn)

    {
        UserService::updateUser(id, name, surname, email, phoneNumber, conn);
    }


}

#endif