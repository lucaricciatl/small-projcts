#pragma once 
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>


class GraphicsThread {
 public:
  GraphicsThread(std::function<void()> renderFunction,
                 unsigned int frameRate = 60);
  ~GraphicsThread();
  void RenderLoop();
  // Prevent copy construction and assignment
  GraphicsThread(const GraphicsThread&) = delete;
  GraphicsThread& operator=(const GraphicsThread&) = delete;

  std::function<void()> mRenderFunction;
  std::atomic<bool> mRunning;
  unsigned int mFrameRate;
  std::thread mThread;
};