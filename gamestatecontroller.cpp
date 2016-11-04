#include "gamestatecontroller.h"

GameStateController::GameStateController()
{

}

GameStateController::init(){
    GameStateController::newTower = false;
    GameStateController::gameEnded = false;
    GameStateController::towerOptions = false;
    GameStateController::upgradeTower = false;
}

GameStateController::setGameEnded(bool state){
    GameStateController::gameEnded = state;
}

GameStateController::setNewTower(bool state){
    GameStateController::newTower = state;
}

GameStateController::setTowerOptions(bool state){
    GameStateController::towerOptions = state;
}

GameStateController::setUpgradeTower(bool state){
    GameStateController::upgradeTower = state;
}

bool GameStateController::getGameEnded(){
    return GameStateController::gameEnded;
}

bool GameStateController::getNewTower(){
    return GameStateController::newTower;
}

bool GameStateController::getTowerOptions(){
    return GameStateController::towerOptions;
}

bool GameStateController::getUpgradeTower(){
    return GameStateController::upgradeTower;
}
