#pragma once
#include "LineBuffer2D.hpp"

namespace graphics {

LineBuffer2D::LineBuffer2D() : mLine(RED) {
  // Additional initialization if necessary
}
LineBuffer2D::~LineBuffer2D() {}

void LineBuffer2D::addPoint(float x, float y) { mBuffer.emplace_back(x, y); }

Point2D LineBuffer2D::getPoint(size_t index) const {
  if (index < mBuffer.size()) {
    return mBuffer[index];
  }
  return Point2D();
}

void LineBuffer2D::removePoint(size_t index) {
  if (index < mBuffer.size()) {
    mBuffer.erase(mBuffer.begin() + index);
  }
}

void LineBuffer2D::clearBuffer() { mBuffer.clear(); }

size_t LineBuffer2D::getSize() const { return mBuffer.size(); }

bool LineBuffer2D::isEmpty() const { return mBuffer.empty(); }

std::vector<Point2D> LineBuffer2D::GetBuffer() { return mBuffer; };

void LineBuffer2D::SetBuffer(std::vector<Point2D> aBuffer) { mBuffer = aBuffer; };

void LineBuffer2D::SetColor(Color newColor) { color = newColor; }

void LineBuffer2D::LoadBuffer() {
  for (auto p : mBuffer) {
    mLine.AddPoint({
        p.x,p.y
    });
  }
};

// Implementation of AppendToBuffer(std::vector<Point2D>)
void LineBuffer2D::AppendToBuffer(std::vector<Point2D> points) {
  mBuffer.insert(mBuffer.end(), points.begin(), points.end());
}

// Implementation of AppendToBuffer(Point2D)
void LineBuffer2D::AppendToBuffer(Point2D point) { mBuffer.push_back(point); }

void LineBuffer2D::DrawBuffer() { mLine.Draw(); };

}  // namespace graphics