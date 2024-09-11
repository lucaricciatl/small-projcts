#include "GraphicsManager.hpp"

#include <chrono>
#include <iostream>
#include <thread>

#include "GraphicsContext.hpp"
#include "PolyLine2D.hpp"

namespace {
constexpr unsigned int defaultFramerate = 30;
}

namespace graphics {

GraphicsManager::GraphicsManager(){
  mContext = std::make_shared<GraphicsContext>();
  mThread = std::make_unique<std::thread>();

};
    // Destructor
GraphicsManager::~GraphicsManager() {
  // Stop the thread
  Stop();
}

void GraphicsManager::SetTargetFramerate(unsigned int frameRate) {
  mFrameRate = frameRate;
}

std::shared_ptr<GraphicsContext> GraphicsManager::GetGraphicsContext() {
  return mContext;
}

void GraphicsManager::Stop() {
  // Stop the thread and join it
  mRunning = false;
  if (mThread->joinable()) {
    mThread->join();
  }
}

void GraphicsManager::Start() {
  mRunning = true;
  mThread = std::make_unique<std::thread>(&GraphicsManager::RenderLoop, this);
}

// The rendering loop method
void GraphicsManager::RenderLoop() {
  using namespace std::chrono;
  auto frameDuration = milliseconds(1000 / mFrameRate);

  while (mRunning) {
    auto frameStart = steady_clock::now();

    if (true) {
      try {
        Render();
      } catch (const std::exception& e) {
        std::cerr << "Render function threw an exception: " << e.what()
                  << std::endl;
        mRunning = false;  // Stop the loop on exception
      }
    }

    auto frameEnd = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
    auto sleepTime = frameDuration - elapsed;

    if (sleepTime > milliseconds(0)) {
      std::this_thread::sleep_for(sleepTime);
    }
  }
}

void GraphicsManager::Render() {
  if (!mContext) {
    mContext = std::make_shared<GraphicsContext>();
  }
  if (mContext->isReady) {
    mContext->Begin();
    mContext->Clear();
    mContext->End();

  } else {
    std::cerr << "Error: Graphics context is not initialized." << std::endl;
  }
}


}  // namespace graphics
