#include <chrono>
#include <iostream>
#include <thread>
#include "GraphicsThread.hpp"
#include "windowManager.hpp"
#include "PolyLine2D.hpp"
namespace {
constexpr unsigned int defaultFramerate = 30;
}

namespace graphics {

void MyRenderFunction(const std::shared_ptr<graphics::ContextManager>& aContext) {
  // Create a polyline with a specified color (e.g., RED)
  graphics::Polyline2D polyline(raylib::RED);
  aContext->BeginDrawing();
  // Add some points to the polyline
  polyline.AddPoint({1.0f, 15.0f});
  polyline.AddPoint({2.0f, 25.0f});
  polyline.AddPoint({30.0f, 2.0f});
  polyline.AddPoint({40.0f, 35.0f});

  // Draw the polyline
  polyline.Draw();
  aContext->EndDrawing();
  // For debugging purposes, print the number of points in the polyline
  std::cout << "Rendering frame... Number of points in polyline: "
            << polyline.GetPointCount() << std::endl;
}

    // Destructor
GraphicsThread::~GraphicsThread() {
  // Stop the thread
  Stop();
}

void GraphicsThread::SetTargetFramerate(unsigned int frameRate) {
  mFrameRate = frameRate;
}

std::shared_ptr<ContextManager> GraphicsThread::GetGraphicsContext() {
  return mContext;
}

void GraphicsThread::Stop() {
  // Stop the thread and join it
  mRunning = false;
  if (mThread->joinable()) {
    mThread->join();
  }
}

void GraphicsThread::Start() {
  mRunning = true;
  mThread = std::make_unique<std::thread>(&GraphicsThread::RenderLoop, this);
}

// The rendering loop method
void GraphicsThread::RenderLoop() {
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


void GraphicsThread::Render() {
  if (!mContext) {
    mContext = std::make_shared<ContextManager>();
  }
    if (mContext->isReady) {

      mContext->BeginDrawing();

      graphics::Polyline2D polyline(raylib::RED);
      // Add some points to the polyline
      polyline.AddPoint({1.0f, 15.0f});
      polyline.AddPoint({2.0f, 25.0f});
      polyline.AddPoint({30.0f, 2.0f});
      polyline.AddPoint({40.0f, 35.0f});

      // Draw the polyline
      polyline.Draw();
      mContext->EndDrawing();

      // For debugging purposes, print the number of points in the polyline
      std::cout << "Rendering frame... Number of points in polyline: "
                << polyline.GetPointCount() << std::endl;
    } else {
      std::cerr << "Error: Graphics context is not initialized." << std::endl;

    }
  }

}  // namespace graphics