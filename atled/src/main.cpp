#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"


int main() {
  // Initialize the GraphicsManager
  auto graphicsthread = std::make_shared<graphics::GraphicsManager>();

  // Set the context and render function
  graphicsthread->SetTargetFramerate(60);
  graphicsthread->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}