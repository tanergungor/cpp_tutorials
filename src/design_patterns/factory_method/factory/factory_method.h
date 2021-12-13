#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <memory>

#include "../product/product.h"

class FactoryMethod {

    public:
        FactoryMethod();
        ~FactoryMethod();
        virtual std::shared_ptr<Product> createProduct() = 0;
};

#endif
