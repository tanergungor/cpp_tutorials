#include "concerete_factory_method.h"
#include "../product/concerete_product.h"

ConcereteFactoryMethod::ConcereteFactoryMethod() : FactoryMethod() {
}

ConcereteFactoryMethod::~ConcereteFactoryMethod() {
}

std::shared_ptr<Product> ConcereteFactoryMethod::createProduct () {
    return std::make_shared<ConcereteProduct>();
}
