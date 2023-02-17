#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H


#include <GLFW/glfw3.h>
#include <string>
#include "Font.h"
#include "Texture.h"
#include "LevelManager.h"
#include "Buttons.h"






class GameOverScreen : GameEntity
{
public:
    GameOverScreen();
    ~GameOverScreen();

    int SelectedMode();
    int SelectedScreen();
    void setSelectedScreen(int Screen);

    void CurrentLevel(int currentlevel);

    void Render();
    void Update();
    void ReturnToMainMenu();

    /*static bool isGameOverScreen;*/

private:
    Font* m_pFont;
    Texture* m_pGameOverBackground;
    Buttons* m_pButtons;
    InputManager* m_pInputManager;
    AudioManager* m_pAudioManager;
    LevelManager* m_pLevelManager;
    
    int ScreenSelected;

    
};

#endif // GAMEOVERSCREEN_H

