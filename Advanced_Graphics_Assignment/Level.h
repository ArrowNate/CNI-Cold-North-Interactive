#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <GLFW/glfw3.h>

class Level {
public:
    Level(const std::string& levelName);
    void initialize();
    void update(float deltaTime);
    void render();
private:
    std::string m_levelName;
};

#endif  // !_LEVEL_H