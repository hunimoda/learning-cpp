#include <iostream>
#include <vector>

class Shape {
 public:
  virtual ~Shape() {}
  virtual void Draw() = 0;
  virtual void Rotate(double degree) = 0;
};

class OpenShape : public Shape {
 public:
  virtual ~OpenShape() {}
};

class ClosedShape : public Shape {
 public:
  virtual ~ClosedShape() {}
};

class Line : public OpenShape {
 public:
  virtual ~Line() {}
  virtual void Draw() override {
    std::cout << "Drawing a line" << std::endl;
  }
  virtual void Rotate(double degree) override {
    std::cout << "Rotating line by " << degree << " degree" << std::endl;
  }
};

class Circle : public ClosedShape {
 public:
  virtual ~Circle() {}
  virtual void Draw() override {
    std::cout << "Drawing a circle" << std::endl;
  }
  virtual void Rotate(double degree) override {
    std::cout << "Rotating circle by " << degree << " degree" << std::endl;
  }
};

class Square : public ClosedShape {
 public:
  virtual ~Square() {}
  virtual void Draw() override {
    std::cout << "Drawing a square" << std::endl;
  }
  virtual void Rotate(double degree) override {
    std::cout << "Rotating square by " << degree << " degree" << std::endl;
  }
};

void RefreshScreen(std::vector<Shape *> &active_shapes) {
  for (Shape *shape: active_shapes)
    shape->Draw();
}

int main() {
  // Shape s;
  // Shape *p = new Shape();
  // Circle circle;
  // circle.Draw();
  // Shape *ptr = new Circle();
  // ptr->Draw();
  // ptr->Rotate(180.0);
  Shape *s1 = new Circle();
  Shape *s2 = new Line();
  Shape *s3 = new Square();

  // Shape *shapes[] = { s1, s2, s3 };
  // for (Shape *shape: shapes) {
  //   shape->Draw();
  //   shape->Rotate(180.0);
  // }
  
  // for (Shape *shape: shapes)
  //   delete shape;
  std::vector<Shape *> active_shapes{s1, s2, s3};
  std::cout << "\n==== Refresh screen ===========" << std::endl;
  RefreshScreen(active_shapes);
  std::cout << "\n===============================" << std::endl;

  return 0;
}