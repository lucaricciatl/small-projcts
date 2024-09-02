
#include "WindowManager.hpp"
#include <string_view>

namespace {
static constexpr int defaultHeight = 420;
static constexpr int defaultWidth = 680;
static constexpr const char* defaultTitle = "Window";
}  // namespace

WindowManager::WindowManager(int width = defaultWidth,
                             int height = defaultHeight,
                             const char* title = defaultTitle)
    : windowWidth(width), windowHeight(height), windowTitle(title) {
  InitWindowManager();
}

WindowManager::~WindowManager() { CloseWindow(); }

void WindowManager::InitWindowManager() {
  InitWindow(windowWidth, windowHeight, windowTitle);
  SetTargetFPS(60);
}

void WindowManager::SetTitle(const char* title) {
  SetWindowTitle(title);
  windowTitle = title;
}

void WindowManager::SetSize(int width, int height) {
  SetWindowSize(width, height);
  windowWidth = width;
  windowHeight = height;
}

int WindowManager::GetWidth() const { return windowWidth; }

int WindowManager::GetHeight() const { return windowHeight; }

void WindowManager::SetTargetFPS(int fps) { ::SetTargetFPS(fps); }

void WindowManager::BeginDrawing() const { BeginDrawing(); }

void WindowManager::EndDrawing() const { EndDrawing(); }
