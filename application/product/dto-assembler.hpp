#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP

#include "../../domain/product/product.hpp"
#include <crow/json.h>

inline crow::json::wvalue listProducts (const std::vector<Product>& listProducts) {
    crow::json::wvalue jsonProduct = crow::json::wvalue::list();
    for (size_t i = 0; i < listProducts.size(); ++i) {
        const Product& product = listProducts[i];
        crow::json::wvalue productJson;
        productJson["id"] = product.id;
        productJson["name"] = product.name;
        productJson["categoryId"] = product.categoryId;

        productJson[i] = listProducts;
    }
    return jsonProduct;
}

#endif //DTO_ASSEMBLER_HPP
