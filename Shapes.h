#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#define PI 3.14159f
using namespace std;

class Shape {
public:
  virtual void Scale(float scaleFactor) = 0;
  virtual void Display() const = 0;
  virtual ~Shape();
};

class Shape2D : virtual public Shape {
public:
  virtual float Area() const = 0;
  void ShowArea() const;
  virtual string GetName2D() const = 0;
  bool operator>(const Shape2D &rhs) const;
  bool operator<(const Shape2D &rhs) const;
  bool operator==(const Shape2D &rhs) const;
  virtual ~Shape2D();
};

class Shape3D : virtual public Shape {
public:
  virtual float Volume() const = 0;
  void ShowVolume() const;
  virtual string GetName3D() const = 0;
  bool operator>(const Shape3D &rhs) const;
  bool operator<(const Shape3D &rhs) const;
  bool operator==(const Shape3D &rhs) const;
  virtual ~Shape3D();
};
//*****************************************2D**********************
class Square : public Shape2D {

  float sideLength;

public:
  float Area() const;
  Square();
  Square(float side);
  void Scale(float scaleFactor);
  void Display() const;
  string GetName2D() const;
};
class Triangle : public Shape2D {

  float base;
  float height;

public:
  float Area() const;
  Triangle();
  Triangle(float base, float height);
  void Scale(float scaleFactor);
  void Display() const;
  string GetName2D() const;
};

class Circle : public Shape2D {

  float radius;

public:
  float Area() const;
  Circle();
  Circle(float radius);
  void Scale(float scaleFactor);
  void Display() const;
  string GetName2D() const;
  float GetRadius() const;
};
//*****************************************3D**********************
//*********************************************TriangularPyramid***
class TriangularPyramid : public Shape3D, private Triangle {
  float heightPyramid;

public:
  TriangularPyramid();
  TriangularPyramid(float height, float triBaseLength, float triBaseHeight);
  float Volume() const;
  string GetName3D() const;
  void Scale(float scaleFactor);
  void Display() const;
};
//****************************************cylinder************
class Cylinder : public Shape3D, private Circle {
  float heightCylinder;

public:
  Cylinder();
  Cylinder(float heightCylinder, float radiusCirlce);
  float Volume() const;
  string GetName3D() const;
  void Scale(float scaleFactor);
  void Display() const;
};
//********************************************Sphere*************
class Sphere : public Shape3D, private Circle {
public:
  Sphere();
  Sphere(float radius);
  float Volume() const;
  string GetName3D() const;
  void Scale(float scaleFactor);
  void Display() const;
};
