#include "Color.hpp"
#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"

int main() {
  // Initialize the GraphicsManager
  auto graphicsMng = std::make_shared<graphics::GraphicsManager>();
  auto ctx = graphicsMng->GetGraphicsContext();
  ctx->SetSize(900,900);
  ctx->SetTitle("Atled");
  auto configs = graphics::GfxConfig(
      { FLAG_MSAA_4X_HINT, FLAG_WINDOW_RESIZABLE});

  graphicsMng->SetConfigs(configs);
  graphicsMng->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}