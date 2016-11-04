#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H


class GameStateController
{
public:
    GameStateController();
    init();
    setNewTower(bool state);
    bool getNewTower();
    setGameEnded(bool state);
    bool getGameEnded();
    setTowerOptions(bool state);
    bool getTowerOptions();
    setUpgradeTower(bool state);
    bool getUpgradeTower();
private:
    bool newTower;
    bool gameEnded;
    bool towerOptions;
    bool upgradeTower;


};

#endif // GAMESTATECONTROLLER_H
