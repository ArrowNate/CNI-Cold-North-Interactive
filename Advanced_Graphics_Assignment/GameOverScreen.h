#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Font.h"
#include "Texture.h"

class GameOverScreen
{
public:
    GameOverScreen();
    ~GameOverScreen();

private:
    Font* m_pFont;
    Texture* m_pGameOverBackground;


private:
   
    void Render();
    void Update();
};

#endif // GAMEOVERSCREEN_H

