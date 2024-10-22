#ifndef APPLICATION_PRODUCT_SERVICE_HPP
#define APPLICATION_PRODUCT_SERVICE_HPP

#include "../../domain/product/product-service.hpp"


namespace ProductApplicationService {
    inline void addProduct(const int& id, std::string &name, std::string& categoryId, pqxx::connection &conn)
    {
        ProductService::addProduct(id,name,categoryId, conn);
    }
    inline void deleteProduct(const Product& id, pqxx::connection &conn)
    {
        ProductService::deleteProduct(id,conn );
    }
    inline std::vector<Product> listProducts(const int& id,std::string& name, std::string& categoryId, pqxx::connection& conn)
    {
        return ProductService::listProducts(id,name,categoryId,conn);
    }
    inline void updateProduct(const int& id,std::string name,std::string& categoryId, pqxx::connection &conn)
    {
        ProductService::updateProduct( id,name,categoryId,conn);
    }
}

#endif //APPLICATION_PRODUCT_SERVICE_HPP
