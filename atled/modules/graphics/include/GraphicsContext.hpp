#pragma once
#include "raylib-cpp.hpp"
#include "LayerManager.hpp"

namespace graphics {
class GraphicsContext {
 public:
  GraphicsContext();
  GraphicsContext(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle); 
  ~GraphicsContext();

  void InitWindowManager();
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  int GetWidth() const;
  int GetHeight() const;
  void SetTargetFPS(int fps);
  void Begin() const ;
  void End() const ;
  void Clear();
  bool isReady;
  LayerManager mLayerManager;
 private:
  int windowWidth;
  int windowHeight;
  const char* windowTitle;


};
}  // namespace graphics