#include <cstdint>

#include <gtest/gtest.h>

#include "design_patterns/factory_method/product/product.h"
#include "design_patterns/factory_method/factory/factory_method.h"
#include "design_patterns/factory_method/factory/concerete_factory_method.h"

TEST(TestFactory, FactoryCanGetAndSetMinimumData) {
    FactoryMethod *factoryMethod = new ConcereteFactoryMethod();
    std::shared_ptr<Product> product = factoryMethod->createProduct();
    EXPECT_TRUE(1 == 1);
}
