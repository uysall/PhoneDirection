#include "crow.h"
#include <nlohmann/json.hpp>
#include "application/user/application-user-service.hpp"
#include "domain/user/user.hpp"

int main() {
    crow::SimpleApp app;

    pqxx::connection conn("dbname=direction user=Ömer password=Ou131973 host=127.0.0.1 port=5432");

    CROW_ROUTE(app, "/list_users").methods(crow::HTTPMethod::GET)([&conn]() {
        auto users = UserApplicationService::userList(conn);
        return crow::response(201, users);
    });

    CROW_ROUTE(app, "/add_users").methods(crow::HTTPMethod::POST)([&conn](const crow::request& req) {
        try {
            auto body = nlohmann::json::parse(req.body);

            UserApplicationService::addUser(
                body["name"].get<std::string>(),
                body["surname"].get<std::string>(),
                body["email"].get<std::string>(),
                body["phoneNumber"].get<std::string>(),
                conn
            );

            return crow::response(201, "User added successfully");
        } catch (...) {
            return crow::response(400, "Invalid user data");

        }
    });

    CROW_ROUTE(app, "/remove_user/<int>").methods(crow::HTTPMethod::DELETE)([&conn](const int id) {
        try {
            UserApplicationService::removeUserById(id, conn);
            crow::json::wvalue response;
            response["message"]= "User removed successfully";
            return crow::response(200, response);
        } catch (...) {
            crow::json::wvalue error;
            error["error"] = "User not found";
            return crow::response(404, error);
        }
    });

    CROW_ROUTE(app, "/updated_user/<int>").methods(crow::HTTPMethod::PUT)([&conn](const crow::request& req, const int id) {
        try {
            auto body = nlohmann::json::parse(req.body);
            UserApplicationService::updateUser(
            id,
            body["name"].get<std::string>(),
                body["surname"].get<std::string>(),
                body["email"].get<std::string>(),
                body["phoneNumber"].get<std::string>(),
                conn
            );

            crow::json::wvalue response;
            response["message"] = "User updated successfully";
            return crow::response(200, response);
        } catch (...) {
            crow::json::wvalue error;
            error["error"] = "Invalid user data";
            return crow::response(400, error);
        }
    });

    CROW_ROUTE(app, "/get_user/<int>").methods(crow::HTTPMethod::GET)
    ([&conn](const int id) {
        try {
            const User user = UserApplicationService::getUserById(id, conn);
            crow::json::wvalue response;
            return crow::response(200, response);
        } catch (...) {
            crow::json::wvalue error;
            error["error"] = "User not found";
            return crow::response(404, error);
        }
    });


    app.port(18081).multithreaded().run();

    return 0;
}

#include <pqxx/pqxx>