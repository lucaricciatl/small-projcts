#include "windowManager.hpp"
#include "GraphicsThread.hpp"


void MyRenderFunction() {
  // Your rendering code here
  std::cout << "Rendering frame..." << std::endl;
}

int main() {
  // Create a WindowManager instance
  WindowManager window(800, 600, "Raylib Window");
  // Main game loop
  while (!WindowShouldClose()) {
    // Draw
    BeginDrawing();
    GraphicsThread graphicsThread(MyRenderFunction, 30);

    // Let the graphics thread run for a while
    std::this_thread::sleep_for(std::chrono::seconds(5));
    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  return 0;
}