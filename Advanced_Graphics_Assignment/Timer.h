#ifndef _TIMER_H
#define _TIMER_H

#include <GLFW/glfw3.h>

class Timer
{
private:
    static Timer* sInstance;
    double mStartTicks;
    double mElapsedTicks;
    float mDeltaTime;
    float mTimeScale;
    double mLastFrameTime;

public:
    static Timer* Instance();
    static void Release();
    float DeltaTime() const;
    void Reset();
    void TimeScale(float ts);
    float TimeScale() const;
    void Update();


private:
    Timer();
    ~Timer();
};

#endif // !_TIMER_H

