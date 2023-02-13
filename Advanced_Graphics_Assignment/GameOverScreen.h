#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Font.h"
#include "Texture.h"
#include "Buttons.h"
#include "StartScreen.h"

class GameOverScreen
{
public:
    GameOverScreen();
    ~GameOverScreen();

    void Render();
    void Update();
    void ReturnToMainMenu();

    /*static bool isGameOverScreen;*/

private:
    Font* m_pFont;
    Texture* m_pGameOverBackground;
    Buttons* m_pButtons;

};

#endif // GAMEOVERSCREEN_H

