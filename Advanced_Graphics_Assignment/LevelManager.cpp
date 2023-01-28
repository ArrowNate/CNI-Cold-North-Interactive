#include "levelmanager.h"
#include "Level.h"

LevelManager::LevelManager() {
    currentLevel = nullptr;
}

LevelManager::~LevelManager() {
    for (auto& level : levels) {
        delete level.second;
    }
}

void LevelManager::loadLevel(const std::string& levelName) {
    if (levels.find(levelName) == levels.end()) {
        levels[levelName] = new Level(levelName);
    }
    currentLevel = levels[levelName];
    currentLevel->initialize();
}

void LevelManager::unloadLevel(const std::string& levelName) {
    if (levels.find(levelName) != levels.end()) {
        delete levels[levelName];
        levels.erase(levelName);
    }
}

void LevelManager::update(float deltaTime) {
    if (currentLevel) {
        currentLevel->update(deltaTime);
    }
}

void LevelManager::render() {
    if (currentLevel) {
        currentLevel->render();
    }
}

Level* LevelManager::getCurrentLevel() {
    return currentLevel;
}