#include "GraphicsThread.hpp"
#include <chrono>
#include <thread>
#include <iostream>

// Constructor
GraphicsThread::GraphicsThread(std::function<void()> renderFunction,
                               unsigned int frameRate)
    : mRenderFunction(std::move(renderFunction)),
      mFrameRate(frameRate),
      mRunning(true) {
  // Start the rendering thread
  mThread = std::thread(&GraphicsThread::RenderLoop, this);
}

// Destructor
GraphicsThread::~GraphicsThread() {
  // Stop the thread
  mRunning = false;
  if (mThread.joinable()) {
    mThread.join();
  }
}

// The rendering loop method
void GraphicsThread::RenderLoop() {
  using namespace std::chrono;
  auto frameDuration = milliseconds(1000 / mFrameRate);

  while (mRunning) {
    auto frameStart = steady_clock::now();

    // Call the rendering function
    if (mRenderFunction) {
      mRenderFunction();
    }

    auto frameEnd = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(frameEnd - frameStart);
    auto sleepTime = frameDuration - elapsed;

    if (sleepTime > milliseconds(0)) {
      std::this_thread::sleep_for(sleepTime);
    }
  }
}
