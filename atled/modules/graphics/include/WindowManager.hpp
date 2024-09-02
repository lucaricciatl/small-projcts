#pragma once
#include "raylib.h"

class WindowManager {
 public:
  WindowManager(int width, int height, const char* title);
  ~WindowManager();

  void InitWindowManager();
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  int GetWidth() const;
  int GetHeight() const;
  void SetTargetFPS(int fps);
  void BeginDrawing() const;
  void EndDrawing() const;

 private:
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
};