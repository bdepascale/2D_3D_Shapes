#include "Shapes.h"
#include <math.h>
#define PI 3.14159f

using namespace std;

bool Shape2D::operator>(const Shape2D &rhs) const {
  if (this->Area() > rhs.Area()) {
    return true;
  } else {
    return false;
  }
}
bool Shape3D::operator>(const Shape3D &rhs) const {
  if (this->Volume() > rhs.Volume()) {
    return true;
  } else {
    return false;
  }
}
bool Shape2D::operator<(const Shape2D &rhs) const {
  if (this->Area() < rhs.Area()) {
    return true;
  } else {
    return false;
  }
}
bool Shape3D::operator<(const Shape3D &rhs) const {
  if (this->Volume() < rhs.Volume()) {
    return true;
  } else {
    return false;
  }
}
bool Shape2D::operator==(const Shape2D &rhs) const {
  if (this->Area() == rhs.Area()) {
    return true;
  } else {
    return false;
  }
}

bool Shape3D::operator==(const Shape3D &rhs) const {
  if (this->Volume() == rhs.Volume()) {
    return true;
  } else {
    return false;
  }
}

void Shape2D::ShowArea() const {
  cout << "The area of the " << this->GetName2D() << " is : " << this->Area()
       << endl;
}
Shape::~Shape() {}
Shape2D::~Shape2D() {}
Shape3D::~Shape3D() {}
void Shape3D::ShowVolume() const {
  cout << "The volume of the " << this->GetName3D()
       << " is : " << this->Volume() << endl;
}
//***********************************************Square***********
Square::Square() { sideLength = 0.0f; }
Square::Square(float side) { sideLength = side; }

float Square::Area() const {
  float A = 0.0f;
  A = pow(sideLength, 2.0f);
  return A;
}

void Square::Scale(float scaleFactor) { sideLength = sideLength * scaleFactor; }

void Square::Display() const {
  cout << "The area of the Square is : " << Area() << endl;
  cout << "Length of a side: " << this->sideLength << endl;
}

string Square::GetName2D() const {
  string Name = "Square";
  return Name;
}

//*********************************************Triangle************
Triangle::Triangle() {
  this->base = 0.0f;
  this->height = 0.0f;
}

Triangle::Triangle(float base, float height) {
  this->base = base;
  this->height = height;
}

float Triangle::Area() const {
  float A = 0.0f;
  A = (base * height) * .5f;
  return A;
}
void Triangle::Scale(float scaleFactor) {
  base = base * scaleFactor;
  height = height * scaleFactor;
}

void Triangle::Display() const {
  cout << "The area of the Triangle is : " << Area() << endl;
  cout << "Base: " << this->base << endl;
  cout << "Height: " << this->height << endl;
}
string Triangle::GetName2D() const {
  string Name = "Triangle";
  return Name;
}
//************************************************Circle*********
Circle::Circle() { this->radius = 0.0f; }

Circle::Circle(float radius) { this->radius = radius; }

float Circle::Area() const {
  float A = 0.0f;
  A = PI * radius * radius;
  return A;
}
void Circle::Scale(float scaleFactor) { radius = radius * scaleFactor; }

void Circle::Display() const {
  cout << "The area of the Circle is : " << Area() << endl;
  cout << "Radius: " << this->radius << endl;
}
string Circle::GetName2D() const {
  string Name = "Circle";
  return Name;
}
float Circle::GetRadius() const { return radius; }

//**************************************3D*************************
//*****************************************TriangularPyramid*****
TriangularPyramid::TriangularPyramid() { this->heightPyramid = 0; }
TriangularPyramid::TriangularPyramid(float height, float triBaseLength,
                                     float triBaseHeight)
    : Triangle(triBaseLength, triBaseHeight) {
  this->heightPyramid = height;
}
float TriangularPyramid::Volume() const {
  float V = 0.0f;
  V = (1.0f / 3.0f) * Triangle::Area() * heightPyramid;
  return V;
}
string TriangularPyramid::GetName3D() const {
  string name = "Triangular Pyramid";
  return name;
}
void TriangularPyramid::Scale(float scaleFactor) {
  Triangle::Scale(scaleFactor);
  heightPyramid = heightPyramid * scaleFactor;
}
void TriangularPyramid::Display() const {
  ShowVolume();
  cout << "The height is: " << heightPyramid << endl;
  Triangle::Display();
}
//***********************************************cylinder***************
Cylinder::Cylinder() { heightCylinder = 0; }
Cylinder::Cylinder(float heightCylinder, float radiusCircle)
    : Circle(radiusCircle) {
  this->heightCylinder = heightCylinder;
}
float Cylinder::Volume() const {

  float V = 0.0f;
  V = Circle::Area() * heightCylinder;
  return V;
}
string Cylinder::GetName3D() const {
  string name = "Cylinder";
  return name;
}
void Cylinder::Scale(float scaleFactor) {
  Circle::Scale(scaleFactor);
  heightCylinder = heightCylinder * scaleFactor;
}
void Cylinder::Display() const {
  ShowVolume();
  cout << "The height is: " << heightCylinder << endl;
  Circle::Display();
}
//***********************************************Sphere******************

Sphere::Sphere() {}
Sphere::Sphere(float radius) : Circle(radius) {}
float Sphere::Volume() const {
  float V = 0.0f;
  V = (4.0f / 3.0f) * Circle::Area() * Circle::GetRadius();
  return V;
}
string Sphere::GetName3D() const {
  string name = "Sphere";
  return name;
}
void Sphere::Scale(float scaleFactor) { Circle::Scale(scaleFactor); }
void Sphere::Display() const {
  ShowVolume();
  Circle::Display();
}
