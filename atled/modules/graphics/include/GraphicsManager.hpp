#pragma once 
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include "GraphicsContext.hpp"
#include "CameraManager.hpp"

namespace graphics{
class GraphicsManager {
 public:
  GraphicsManager();
  ~GraphicsManager();
  void RenderLoop();
  void CameraStep();
  void SetTargetFramerate(unsigned int frameRate);
  std::shared_ptr<GraphicsContext> GetGraphicsContext();
	
  void Render();
  void Start();
  void Stop();


  std::atomic<bool> mRunning;
  unsigned int mFrameRate;
  
  private:
  std::unique_ptr<std::thread> mThread;
  std::shared_ptr<GraphicsContext> mContext;
  std::shared_ptr<CameraManager> mCamera;

};
}