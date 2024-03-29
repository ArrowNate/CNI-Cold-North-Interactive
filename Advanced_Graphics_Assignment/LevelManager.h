#ifndef _LEVEL_MANAGER_H
#define _LEVEL_MANAGER_H

#include <vector>
#include "Level.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"

class LevelManager {

private:

    int ScreenSelected;
    static LevelManager* sInstance;

    /*HUD* m_pHUD;*/
    Level* m_pLevel1;
    Level2* m_pLevel2;
    Level3* m_pLevel3;
    Level4* m_pLevel4;

    std::vector<Level*> m_pLevels; // This vector stores the levels managed by the LevelManager.
    int mCurrentLevel = 0; // The current level being used by the program.


public:
    static LevelManager* Instance();

    static void Release();

    LevelManager();
    ~LevelManager();

    int SelectedScreen();

    void setSelectedScreen(int Screen);

    void ChangeLevel();
    void NextLevel();
    void setCurrentLevel(int Level);

    void AddLevel(Level* level); // This should add a level to the list of levels handled by our LevelManager? Check into this ***
    void LoadLevel(int levelIndex); // this should load a specific level in the game based off the number in the if statement we placed in the .cpp
    void Update();
    void LateUpdate();
    void Render();

    void Reset();
};

#endif // !_LEVEL_MANAGER_H



