#include "BuffersManager.hpp"
#include "PointBuffer2D.hpp"
namespace graphics {
BuffersManager::BuffersManager() {
  mPointBuffer = std::make_shared<PointBuffer2D>();
};
	std::shared_ptr<PointBuffer2D> BuffersManager::GetPointBuffer() {
  return mPointBuffer;
};




}  // namespace Graphics