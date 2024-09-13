#pragma once
#include <vector>
#include "Color.hpp"
namespace graphics {

// Simple structure to represent a 2D point
struct Point2D {
  float x;
  float y;
  
  Point2D(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
};

class PointBuffer2D {
 public:
  PointBuffer2D();
  ~PointBuffer2D();
  void addPoint(int x, int y);
  void SetColor(Color newColor);
  Point2D getPoint(size_t index) const;

  std::vector<Point2D> GetBuffer();

  void removePoint(size_t index);
  void clearBuffer();
  size_t getSize() const;
  bool isEmpty() const;
  void DrawBuffer();

 private:
  Color color;
  std::vector<Point2D> buffer;  // A dynamic list of 2D points
};

}  // namespace graphics