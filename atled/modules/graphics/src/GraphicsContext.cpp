
#include "GraphicsContext.hpp"
#include "raylib-cpp.hpp"
#include <string_view>

namespace {
static constexpr int defaultHeight = 420;
static constexpr int defaultWidth = 680;
static constexpr const char* defaultTitle = "Window";
}  // namespace

namespace graphics {
GraphicsContext::GraphicsContext() {
  windowWidth = defaultWidth;
  windowHeight = defaultHeight;
  windowTitle = defaultTitle;
  InitWindowManager();
}

GraphicsContext::GraphicsContext(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle) {
  windowWidth = aWindowWidth;
  windowHeight = aWindowHeight;
  windowTitle = aWindowTitle;
  InitWindowManager();
}

GraphicsContext::~GraphicsContext() { CloseWindow(); }

void GraphicsContext::InitWindowManager() {
  InitWindow(windowWidth, windowHeight, windowTitle);
  isReady = true;
}

void GraphicsContext::SetTitle(const char* title) {
  SetWindowTitle(title);
  windowTitle = title;
}

void GraphicsContext::SetSize(int width, int height) {
  SetWindowSize(width, height);
  windowWidth = width;
  windowHeight = height;
}

int GraphicsContext::GetWidth() const { return windowWidth; }

int GraphicsContext::GetHeight() const { return windowHeight; }

void GraphicsContext::Begin() const { BeginDrawing(); }
void GraphicsContext::End() const { EndDrawing(); }

void GraphicsContext::Clear() {  };

}  // namespace graphics