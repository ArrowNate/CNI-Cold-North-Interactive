#include "Timer.h"

Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance()
{
	if (sInstance == nullptr) {
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

float Timer::DeltaTime() const
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
	mElapsedTicks = glfwGetTime() - mStartTicks;
	mDeltaTime = mElapsedTicks * 0.001f;
}
Timer::Timer()
{
	Reset();
	mTimeScale = 1.0f;
}
Timer::~Timer()
{
}
