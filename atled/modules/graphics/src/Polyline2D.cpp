#include "Polyline2D.hpp"
#include "raylib.h"

namespace graphics {

// Constructor to initialize an empty polyline with a specified color
Polyline2D::Polyline2D(Color color) : color(color) {}

// Add a point to the polyline
void Polyline2D::AddPoint(std::vector<float> point) { points.push_back(point); }

// Draw the polyline
void Polyline2D::Draw() const {
  if (points.size() < 2) return;  // Need at least 2 points to draw a line

  for (size_t i = 0; i < points.size() - 1; ++i) {
    DrawLine(points[i][0], points[i][1], points[i + 1][0],
                     points[i + 1][1], color);
  }
}

// Get the number of points in the polyline
size_t Polyline2D::GetPointCount() const { return points.size(); }

// Get a point by index
std::vector<float> Polyline2D::GetPoint(size_t index) const {
  if (index < points.size()) {
    return points[index];
  }
  return {0, 0};  // Return a default value if index is out of bounds
}

// Change the color of the polyline
void Polyline2D::SetColor(Color newColor) { color = newColor; }

}  // namespace graphics