#pragma once
#include "PointBuffer2D.hpp"
#include <memory>
namespace graphics {

class BuffersManager {
 public:
  BuffersManager();
  std::shared_ptr<PointBuffer2D> GetPointBuffer();
 private:
  std::shared_ptr<PointBuffer2D> mPointBuffer;
};

}  // namespace Graphics