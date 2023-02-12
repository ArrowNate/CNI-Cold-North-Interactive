#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Font.h"
#include "Texture.h"
#include "Buttons.h"

class GameOverScreen
{
public:
    GameOverScreen();
    ~GameOverScreen();

    void Render();
    void Update();

private:
    Font* m_pFont;
    Texture* m_pGameOverBackground;

    float buttonWidth;
    float buttonHeight;
    Button* m_pButton;
};

#endif // GAMEOVERSCREEN_H

