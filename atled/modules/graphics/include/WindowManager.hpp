#pragma once
#include "raylib.h"


namespace graphics {
class ContextManager {
 public:
  ContextManager();
  ContextManager(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle); 
  ~ContextManager();

  void InitWindowManager();
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  int GetWidth() const;
  int GetHeight() const;
  void SetTargetFPS(int fps);
  void BeginDrawing() const;
  void EndDrawing() const;
  
  bool isReady;

 private:
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
};
}  // namespace graphics