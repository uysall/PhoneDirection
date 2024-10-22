#ifndef PRODUCT_REPOSITORY_HPP
#define PRODUCT_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "product-factory.hpp"
#include "product.hpp"

namespace ProductRepository {

    inline std::vector<Product> generateProductListFromDb(pqxx::connection& conn) {
        pqxx::work txn(conn);
        const pqxx::result result = txn.exec(
            "SELECT p.id, p.name, c.categoryId "
            "FROM product_table p "
            "LEFT JOIN product_category c ON p.categoryId = c.id;"
        );
        return ProductFactory::generateProductListFromDb(result);
    }

    inline void addProduct(const Product &product, pqxx::connection &conn) {
        pqxx::work txn{conn};
        txn.exec_params("INSERT INTO products (id, name, categoryId) VALUES ($1, $2, $3)",
                product.id, product.name, product.categoryId);
        txn.commit();
    }

    inline void removeProduct(const Product& product, pqxx::connection &conn) {
        pqxx::work txn{conn};
        txn.exec_params("DELETE FROM products WHERE id = $1", product.id);
        txn.commit();
    }

    inline std::vector<Product> listProducts(const Product& product, pqxx::connection& conn) {
        pqxx::work txn(conn);
        const pqxx::result result = txn.exec("SELECT id, name, categoryId  FROM products");
        return ProductFactory::generateProductListFromDb(result);
    }

    inline void updateProduct(const Product& product, pqxx::connection& conn) {
        pqxx::work txn{conn};
        txn.exec_params("UPDATE products SET name = $2, categoryId = $3 WHERE id = $1",
                product.id, product.name, product.categoryId);
        txn.commit();
    }

}

#endif //PRODUCT_REPOSITORY_HPP
