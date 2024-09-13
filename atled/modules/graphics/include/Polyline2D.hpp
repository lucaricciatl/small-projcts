#pragma once 

#include <vector>
#include "raylib-cpp.hpp" // Include raylib header for Color and DrawLine functions
#include "PointBuffer2D.hpp"

namespace graphics {
class Polyline2D {
 public:
  Polyline2D(Color color);

  void AddPoint(Point2D point);

  void Draw() const;

  size_t GetPointCount() const;

  Point2D GetPoint(size_t index) const;

  void SetColor(Color newColor);

 private:
  mutable std::vector<Point2D>
      points;           
  Color color;  
};
}  // namespace graphics