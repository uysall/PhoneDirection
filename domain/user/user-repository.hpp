#ifndef USER_REPOSITORY_HPP
#define USER_REPOSITORY_HPP

#include <pqxx/pqxx>

#include "user-factory.hpp"
#include "user.hpp"

namespace UserRepository {

    inline void addUser(const User& user, pqxx::connection& conn)
    {
        pqxx::work nt(conn);
        nt.exec_params("INSERT INTO direction.direction_table(name, surname, email, phoneNumber) VALUES ($1, $2, $3, $4);",
            user.name, user.surname, user.email, user.phoneNumber
        );
    }

    inline void removeUserById(const int& id, pqxx::connection& conn)
    {
        pqxx::work nt(conn);
        nt.exec_params("DELETE FROM direction.direction_table WHERE id = $1;", id);
        nt.commit();
    }

    inline std::vector <User>  userList(pqxx::connection &conn)
    {
        pqxx::work txn(conn);

        const pqxx::result result = txn.exec("SELECT id, name, surname, email, phoneNumber FROM direction.direction_table;");

        return UserFactory::generateListFromDb(result);
    }

    inline void updateUser(const User& user, pqxx::connection& conn) {
        pqxx::work nt(conn);
        nt.exec_params(
        "UPDATE direction.direction_table SET name = $1, surname = $2, email = $3 WHERE id = $4;",
            user.name, user.surname, user.email, user.id);
    }


    inline User getUserById( pqxx::connection &conn) {
        pqxx::work nt(conn);
        const pqxx::result res = nt.exec_params("SELECT name, surname, email, phoneNumber FROM direction.direction_table WHERE id = $1;");

        return UserFactory::generateFromDb(res[0]);
    }

}
#endif //USER_REPOSITORY_HPP