#include "LevelManager.h"


LevelManager* LevelManager::sInstance = nullptr;

LevelManager* LevelManager::Instance()
{
    if (sInstance == nullptr) {
        sInstance = new LevelManager();
    }

    return sInstance;
}

void LevelManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

// This is the constructor for our level(s). The mCurrentLevel(0) would be used to load the very first level of our game. I am hoping this is an easy way to allow us to add as many levels as we want.
LevelManager::LevelManager() : mCurrentLevel(mCurrentLevel) {
    
    mCurrentLevel = 1;

    // If we want to load level 2 we would change the 0 to 1. So on and so forth. So 0 should be level 1, 1 would be level 2 and so on.
    ScreenSelected = 1;
    m_pLevels.push_back(new Level);
    m_pLevels.push_back(new Level2);
    m_pLevels.push_back(new Level3);
    m_pLevels.push_back(new Level4);
    //m_pLevels.push_back(new Level5);
}

LevelManager::~LevelManager() {
    for (Level* level : m_pLevels) {
        delete level;
    }

    //Deconstructor. This should ensure we remove a level from memory when we no longer need it. Helps avoid memory leaks and such.
}

void LevelManager::AddLevel(Level* level) {
    m_pLevels.push_back(level);

    // This function should hopefully allow us to add new levels to the game instead of having to hard code all the levels directly into the game like I did in the Mario project. It should add to the mLevels vector above using push_back.
}

//void LevelManager::LoadLevel(int levelIndex) {
//    if (levelIndex >= 0 && levelIndex < m_pLevels.size()) {
//        mCurrentLevel = levelIndex;
//    }
//
//    // Hoping this function works as well. LoadLevel is supposed to set the current level in the level manager. 0 is supposed to check to ensure that levelIndex is never a negative number. I don't know if this was completely correct I will look into this further. ***
//}

void LevelManager::Update() {
    m_pLevels[mCurrentLevel]->Update();

    if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
        ScreenSelected = 2;
       //m_pLevel1->Reset();
       //m_pLevels[mCurrentLevel]->Reset();
    }

    if (m_pLevels[mCurrentLevel]->GetLevelOver() == true || m_pLevels[mCurrentLevel]->GetNoAmmo() == true) {
        ScreenSelected = 4;
        //m_pLevels[mCurrentLevel]->Reset();
        
    }

    if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_G) == GLFW_PRESS) {
        NextLevel();
    }

    //This should allow any level that is currently being used (mCurrentLevel) to update anything required such as player movement or enemy movement and stuff like that.
}

void LevelManager::LateUpdate() {
    m_pLevels[mCurrentLevel]->LateUpdate();
}

void LevelManager::Render() {
    m_pLevels[mCurrentLevel]->Render();
}


int LevelManager::SelectedScreen()
{
    return ScreenSelected;
}

void LevelManager::setSelectedScreen(int Screen)
{
    ScreenSelected = Screen;
}

void LevelManager::NextLevel() {
    
    mCurrentLevel = 2;
    //m_pLevels[mCurrentLevel]->Reset();
}

void LevelManager::Reset() {
    m_pLevels[mCurrentLevel]->Reset();
}