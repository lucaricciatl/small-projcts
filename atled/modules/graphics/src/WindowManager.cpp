
#include "WindowManager.hpp"
#include <string_view>

namespace {
static constexpr int defaultHeight = 420;
static constexpr int defaultWidth = 680;
static constexpr const char* defaultTitle = "Window";
}  // namespace

namespace graphics {


  ContextManager::ContextManager(){
    windowWidth = defaultWidth;
    windowHeight = defaultHeight;
    windowTitle = defaultTitle;
    InitWindowManager();
  }

    ContextManager::ContextManager(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle) {
    windowWidth = aWindowWidth;
      windowHeight = aWindowHeight;
    windowTitle = aWindowTitle;
    InitWindowManager();
  }

  ContextManager::~ContextManager() { raylib::CloseWindow(); }

  void ContextManager::InitWindowManager() {
    raylib::InitWindow(windowWidth, windowHeight, windowTitle);
    isReady = true;
  }

  void ContextManager::SetTitle(const char* title) {
    raylib::SetWindowTitle(title);
    windowTitle = title;
  }

  void ContextManager::SetSize(int width, int height) {
    raylib::SetWindowSize(width, height);
    windowWidth = width;
    windowHeight = height;
  }

  int ContextManager::GetWidth() const { return windowWidth; }

  int ContextManager::GetHeight() const { return windowHeight; }

  void ContextManager::BeginDrawing() const {
    raylib::BeginDrawing();
  }

  void ContextManager::EndDrawing() const { raylib::EndDrawing(); }
  }