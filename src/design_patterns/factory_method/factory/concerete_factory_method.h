#ifndef CONCERETE_FACTORY_METHOD_H
#define CONCERETE_FACTORY_METHOD_H

#include <memory>

#include "factory_method.h"
#include "../product/product.h"

class ConcereteFactoryMethod: public FactoryMethod {

    public:
        ConcereteFactoryMethod();
        ~ConcereteFactoryMethod();
        std::shared_ptr<Product> createProduct () override;
};

#endif
