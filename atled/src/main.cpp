#include "GraphicsContext.hpp"
#include "GraphicsManager.hpp"
#include "Polyline2D.hpp"
#include "Color.hpp"

int main() {
  // Initialize the GraphicsManager
  auto graphicsthread = std::make_shared<graphics::GraphicsManager>();

  // Set the context and render function
  graphicsthread->SetTargetFramerate(60);
  auto ctx = graphicsthread->GetGraphicsContext();
  auto lm = ctx->mLayerManager;
  lm.AddLayer(1);
  auto l1 = lm.GetLayerById(1);
  auto pb =l1->GetBufferManager();
  pb->GetPointBuffer()->addPoint(300, 300); 
  auto clr = graphics::colors::Color(244, 244, 244, 244) ;
  l1->GetBufferManager()->GetPointBuffer()->SetColor(
      clr);

  graphicsthread->Start();
  // Main game loop
  while (true) {
    // depending on your GraphicsManager class design.
  }

  return 0;
}