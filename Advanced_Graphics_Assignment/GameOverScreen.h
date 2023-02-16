#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Font.h"
#include "Texture.h"
#include "Buttons.h"
#include "StartScreen.h"
#include "InputManager.h"
#include "AudioManager.h"


class GameOverScreen : GameEntity
{
public:
    GameOverScreen();
    ~GameOverScreen();

    int SelectedMode();
    int SelectedScreen();
    void setSelectedScreen(int Screen);

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
    
    int ScreenSelected;

    
};

#endif // GAMEOVERSCREEN_H

