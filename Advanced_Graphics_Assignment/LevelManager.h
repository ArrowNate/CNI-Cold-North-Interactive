#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <map> // This is what Richard used in class
#include <string>

class Level;

class LevelManager {
public:
    LevelManager();
    ~LevelManager();
    void loadLevel(const std::string& levelName); // Double check this
    void unloadLevel(const std::string& levelName); // Double check this as well 
    void update(float deltaTime); // deltaTime for smoother animations?
    void render();
    Level* getCurrentLevel();

private:
    std::map<std::string, Level*> levels; // Same as what Richard used in class
    Level* currentLevel;
};

#endif // !_LEVELMANAGER_H