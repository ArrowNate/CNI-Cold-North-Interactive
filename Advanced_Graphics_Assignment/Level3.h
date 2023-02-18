#ifndef _LEVEL3_H
#define _LEVEL3_H
#include "Level.h"


class Level3 : public Level
{
private:

    /*float mRandVelx = rand() % -20 + 10 * .001;
    float mRandVely = rand() % -20 + 10 * .001;
    float mRandDirx = rand() % -20 + 10 * .001;
    float mRandDiry = rand() % -20 + 10 * .001;*/

    
    float mRandVely = rand() % -20 + 10 * .01;
    float mRandDirx = rand() % -20 + 10 * .001;
    float mRandDiry = rand() % -20 + 10 * .001;

public:

    Level3();
    ~Level3();

    void Update();

    void Render();

    void LateUpdate();
    
};

#endif // !_LEVEL3_H

