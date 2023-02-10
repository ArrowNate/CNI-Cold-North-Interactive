#ifndef _LEVEL_MANAGER_H
#define _LEVEL_MANAGER_H

#include <vector>
#include "Level.h"

// I am not sure if I still need to add deltaTime for this. Richard used a while statement in class however this was in the main.cpp and I don't think this should be handled by LevelManager or Level class.

class LevelManager {

private:
    std::vector<Level*> mLevels; // This vector stores the levels managed by the LevelManager.
    int mCurrentLevel; // The current level being used by the program.

public:
    LevelManager();
    ~LevelManager();

    void AddLevel(Level* level); // This should add a level to the list of levels handled by our LevelManager? Check into this ***
    void LoadLevel(int levelIndex); // this should load a specific level in the game based off the number in the if statement we placed in the .cpp
    void Update();
    void Render();
};

#endif // !_LEVEL_MANAGER_H



