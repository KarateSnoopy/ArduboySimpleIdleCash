#include <Arduboy2.h>
Arduboy2 arduboy;

uint64_t cash;
uint64_t buildings;
uint64_t towers;
uint64_t cities;

void printToScreen();

void setup() 
{
    cash = 0;
    buildings = 0;
    towers = 0;
    cities = 0;

    arduboy.begin();
    arduboy.setFrameRate(240);
}

void loop()
{
    if (!(arduboy.nextFrame()))
        return;

    if (arduboy.pressed(B_BUTTON) || arduboy.pressed(A_BUTTON))
    {
        uint64_t costOfBuilding = (buildings + 1) * 1000;
        if (cash >= costOfBuilding)
        {
            buildings++;
            cash -= costOfBuilding;
        }

        uint64_t costOfTower = (towers + 1) * 100;
        if (buildings >= costOfTower)
        {
            towers++;
            buildings -= costOfTower;
        }


        uint64_t costOfCities = (cities + 1) * 30;
        if (towers >= costOfCities)
        {
            cities++;
            towers -= costOfCities;
        }
    }

    cash++;
    cash += buildings * 10;
    buildings += towers;
    towers += cities;

    printToScreen();
}

void printToScreen()
{
    byte x = 10;
    byte y = 10;
    arduboy.clear();
    arduboy.setCursor(3, y);

    char str[256];
    sprintf(str, "Cash: $%lu", cash);
    arduboy.print(str);

    arduboy.setCursor(3, y + 10);
    sprintf(str, "Buildings: %lu", buildings);
    arduboy.print(str);

    arduboy.setCursor(3, y + 20);
    sprintf(str, "Towers: %lu", towers);
    arduboy.print(str);

    arduboy.setCursor(3, y + 30);
    sprintf(str, "Cities: %lu", cities);
    arduboy.print(str);

    arduboy.display();
}