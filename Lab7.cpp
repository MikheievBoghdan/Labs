#include <iostream>
#include <list>

class GeometricShape {
public:
    virtual double calculateSurfaceArea() const = 0; 
};

class Sphere : public GeometricShape {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double calculateSurfaceArea() const override {
        return 4 * 3.14 * radius * radius;
    }
};

class Cuboid : public GeometricShape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    double calculateSurfaceArea() const override {
        return 2 * (length * width + length * height + width * height);
    }
};

class Tetrahedron : public GeometricShape {
private:
    double edgeLength;

public:
    Tetrahedron(double e) : edgeLength(e) {}

    double calculateSurfaceArea() const override {
        return sqrt(3) * edgeLength * edgeLength;
    }
};

void main() {
    std::list<GeometricShape*> shapes;

    Sphere sphere(6);
    Cuboid cuboid(3, 4, 5);
    Tetrahedron tetrahedron(6);

    shapes.push_back(&sphere);
    shapes.push_back(&cuboid);
    shapes.push_back(&tetrahedron);

    for (const auto& shape : shapes) {
        std::cout << "Surface Area: " << shape->calculateSurfaceArea() << std::endl;
    }  
}
