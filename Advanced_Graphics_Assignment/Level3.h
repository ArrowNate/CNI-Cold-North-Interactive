#ifndef _LEVEL3_H
#define _LEVEL3_H
#include "Level.h"


class Level3 :
    public Level
{

public:

    Level3();
    ~Level3();

    void Update();

    void Render();

    void LateUpdate();
    
};

#endif // !_LEVEL3_H

