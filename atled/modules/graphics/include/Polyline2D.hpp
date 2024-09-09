#pragma once 

#include <vector>
#include "raylib-cpp.hpp" // Include raylib header for Color and DrawLine functions

namespace graphics {
class Polyline2D {
 public:
  // Constructor to initialize an empty Polyline2D with a specified color
  Polyline2D(Color color);

  // Add a point to the Polyline2D
  void AddPoint(std::vector<float> point);

  // Draw the Polyline2D
  void Draw() const;

  // Get the number of points in the Polyline2D
  size_t GetPointCount() const;

  // Get a point by index
  std::vector<float> GetPoint(size_t index) const;

  // Change the color of the Polyline2D
  void SetColor(Color newColor);

 private:
  std::vector<std::vector<float>>
      points;           // Vector of points representing the Polyline2D
  Color color;  // Color of the Polyline2D
};
}  // namespace graphics