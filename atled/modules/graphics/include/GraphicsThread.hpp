#pragma once 
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include "windowManager.hpp"

namespace graphics{
class GraphicsThread {
 public:
  ~GraphicsThread();
  void RenderLoop();
  void SetTargetFramerate(unsigned int frameRate);
  std::shared_ptr<ContextManager> GetGraphicsContext();
  void Render();
  void Start();
  void Stop();
  std::atomic<bool> mRunning;
  unsigned int mFrameRate;
  std::unique_ptr<std::thread> mThread;
  std::shared_ptr<ContextManager> mContext;

};
}