#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
public:
    int id{};
    std::string name;
    std::string categoryId;

    Product() = default;

    Product(const int& id, std::string& name, std::string& categoryId)
        : id(id), name(std::move(name)), categoryId(std::move(categoryId)) {}
};



#endif //PRODUCT_HPP
