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
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;
}

float Timer::DeltaTime()
{
    double currentTime = glfwGetTime();
    mDeltaTime = (float)(currentTime - mLastFrameTime);
    mLastFrameTime = currentTime;
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
    double currentTime = glfwGetTime();
    mDeltaTime = (float)((currentTime - mLastFrameTime) * mTimeScale);
    mLastFrameTime = currentTime;
    std::cout << "Delta time: " << mDeltaTime << std::endl;
}

Timer::Timer()
{
    mTimeScale = 1.0f;
    mLastFrameTime = 0.0;
}

Timer::~Timer()
{
}