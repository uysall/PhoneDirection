#ifndef PRODUCT_SERVICE_HPP
#define PRODUCT_SERVICE_HPP

#include "product-repository.hpp"
#include "product.hpp"
#include <pqxx/pqxx>


namespace  ProductService {

    inline void addProduct(const int& id, std::string& name, std::string& categoryId, pqxx::connection& conn) {
        const Product product{id, name, categoryId};
        ProductRepository::addProduct(product, conn);
    }
    inline std::vector<Product> listProducts(const int& id, std::string& name, std::string& categoryId,  pqxx::connection& conn) {
        const Product product{id, name, categoryId};
        return ProductRepository::listProducts(product, conn);
    }
    inline void deleteProduct(const Product& id, pqxx::connection& conn) {
        ProductRepository::removeProduct(id, conn);
    }
    inline void updateProduct(const int& id, std::string& name, std::string& categoryId,  pqxx::connection& conn) {
        Product product{id, name, categoryId};
        product.id = id;
        ProductRepository::updateProduct(product, conn);
    }
}


#endif