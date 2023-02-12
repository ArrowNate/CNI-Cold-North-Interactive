#include <GLFW/glfw3.h>
#include "Timer.h"
#include <iostream>

Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance()
{
    if (sInstance == nullptr)
    {
        sInstance = new Timer();
    }
    return sInstance;
}

void Timer::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

void Timer::Reset()
{
    mStartTicks = glfwGetTime();
    mElapsedTicks = glfwGetTime();
    mDeltaTime = 0.0f;
}

float Timer::DeltaTime()
{
    return mDeltaTime;
}

void Timer::TimeScale(float ts)
{
    mTimeScale = ts;
}

float Timer::TimeScale() const
{
    return mTimeScale;
}

void Timer::Update()
{
  
}

Timer::Timer()
{
    mTimeScale = 0.0f;
    mLastFrameTime = 0.0;
}

Timer::~Timer()
{
}