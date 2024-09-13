#pragma once
#include <vector>

#include "Color.hpp"
#include "PointBuffer2D.hpp"
#include "Polyline2D.hpp"

namespace graphics {

class LineBuffer2D {
 public:
  LineBuffer2D();
  ~LineBuffer2D();
  void addPoint(float x, float y);
  void SetColor(Color newColor);
  Point2D getPoint(size_t index) const;

  std::vector<Point2D> GetBuffer();
  void AppendToBuffer(std::vector<Point2D>);
  void AppendToBuffer(Point2D);
  void SetBuffer(std::vector<Point2D> aBuffer);

  void removePoint(size_t index);
  void clearBuffer();
  size_t getSize() const;
  bool isEmpty() const;
  void LoadBuffer();
  void DrawBuffer();

 private:
  Color color;
  std::vector<Point2D> mBuffer;  // A dynamic list of 2D points
  Polyline2D mLine;
};

}  // namespace graphics