#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <iostream>
#include <memory>

class Polygon {
    protected:
        double width;
        double height;

    public:
        Polygon() = delete; 
        Polygon(double width, double height) {
            this->width = width; 
            this->height = height;
        }
        virtual double calculateArea () = 0;
};

class Rectangle: public Polygon {
    public:
        Rectangle(double width, double height) : Polygon(width, height) {
        }

        double calculateArea (void) override {
            return (width * height);
        }
};

class Triangle: public Polygon {
    public:
        Triangle(double width, double height) : Polygon(width, height) {
        }

        double calculateArea (void) override {
            return (width * height / 2.0);
        }
};

int hello_world();

#endif
