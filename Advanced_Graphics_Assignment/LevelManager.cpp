#include "LevelManager.h"


// This is the constructor for our level(s). The mCurrentLevel(0) would be used to load the very first level of our game. I am hoping this is an easy way to allow us to add as many levels as we want.
LevelManager::LevelManager() : mCurrentLevel(0) {
    // If we want to load level 2 we would change the 0 to 1. So on and so forth. So 0 should be level 1, 1 would be level 2 and so on.
}

LevelManager::~LevelManager() {
    for (Level* level : mLevels) {
        delete level;
    }

    //Deconstructor. This should ensure we remove a level from memory when we no longer need it. Helps avoid memory leaks and such.
}

void LevelManager::AddLevel(Level* level) {
    mLevels.push_back(level);

    // This function should hopefully allow us to add new levels to the game instead of having to hard code all the levels directly into the game like I did in the Mario project. It sould add to the mLevels vector above using push_back.
}

void LevelManager::LoadLevel(int levelIndex) {
    if (levelIndex >= 0 && levelIndex < mLevels.size()) {
        mCurrentLevel = levelIndex;
    }

    // Hoping this function works as well. LoadLevel is supposed to set the current level in the level manager. 0 is supposed to check to ensure that levelIndex is never a negative number. I don't know if this was completely correct I will look into this further. ***
}

void LevelManager::Update() {
    mLevels[mCurrentLevel]->Update();

    //This should allow any level that is currently being used (mCurrentLevel) to update anything required such as player movement or enemy movement and stuff like that.
}

void LevelManager::Render() {
    mLevels[mCurrentLevel]->Render();
}


