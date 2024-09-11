#pragma once
#include "PointBuffer2D.hpp"


namespace graphics {
// Constructor
PointBuffer2D::PointBuffer2D() {}

// Destructor
PointBuffer2D::~PointBuffer2D() {}

// Add a point to the buffer
void PointBuffer2D::addPoint(float x, float y) { buffer.emplace_back(x, y); }

// Get the point at a specific index
Point2D PointBuffer2D::getPoint(size_t index) const {
  if (index < buffer.size()) {
    return buffer[index];
  }
  // Return a default point if index is out of bounds
  return Point2D();
}

// Remove the point at a specific index
void PointBuffer2D::removePoint(size_t index) {
  if (index < buffer.size()) {
    buffer.erase(buffer.begin() + index);
  }
}

// Clear all points
void PointBuffer2D::clearBuffer() { buffer.clear(); }

// Get the number of points
size_t PointBuffer2D::getSize() const { return buffer.size(); }

// Utility function to check if the buffer is empty
bool PointBuffer2D::isEmpty() const { return buffer.empty(); }

std::vector<Point2D> PointBuffer2D::GetBuffer() { return buffer; };

void PointBuffer2D::SetColor(colors::Color newColor) { color = newColor; }
}  // namespace graphics