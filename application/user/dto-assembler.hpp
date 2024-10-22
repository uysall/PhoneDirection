#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP
#include <nlohmann/json.hpp>
#include "../../domain/user/user.hpp"
namespace DtoAssembler {


    inline crow::json::wvalue generateGetList(const std::vector<User>& userList) {
        crow::json::wvalue jsonUsers = crow::json::wvalue::list();
        for (size_t i = 0; i < userList.size(); ++i) {
            const User& user = userList[i];
            crow::json::wvalue userJson;
            userJson["id"] = user.id;
            userJson["name"] = user.name;
            userJson["surname"] = user.surname;
            userJson["email"] = user.email;
            userJson["phoneNumber"] = user.phoneNumber;

            jsonUsers[i] = std::move(userJson);
        }

        return jsonUsers;
    }
}

inline nlohmann::json generateGetUser(const User &user) {
    nlohmann::json jsonUser;
    jsonUser["id"] = user.id;
    jsonUser["name"] = user.name;
    jsonUser["surname"] = user.surname;
    jsonUser["email"] = user.email;
    jsonUser["phoneNumber"] = user.phoneNumber;
    return jsonUser;
}


#endif //DTO_ASSEMBLER_HPP