#include "hello_world.h"

#include <vector>

int hello_world()
{
    std::cout << "Hello World!" << std::endl;

    std::unique_ptr<Polygon> rectangle = std::make_unique<Rectangle>(5.0, 5.0);
    std::unique_ptr<Polygon> triangle = std::make_unique<Triangle>(5.0, 5.0);

    std::vector<std::unique_ptr<Polygon>> polygon_vector;
    polygon_vector.push_back(std::move(rectangle));
    polygon_vector.push_back(std::move(triangle));

    for(auto& c_polygon : polygon_vector) {
      std::cout << c_polygon->calculateArea() << std::endl;
    }

    return 0;
}
