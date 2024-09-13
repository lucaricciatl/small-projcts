#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"
#include "Color.hpp"

int main() {
  // Initialize the GraphicsManager
  auto graphicsthread = std::make_shared<graphics::GraphicsManager>();

  graphicsthread->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}