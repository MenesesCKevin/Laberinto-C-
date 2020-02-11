#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
    public:
        GameMap();
        MapCell* PlayerCell;
        MapCell cells[15][10] ;
        void Draw();
        void DrawIntro();
        void DrawVitory();
        bool SetPlayerCell(int PlayerX, int PlayerY);
        bool isGameOver;


    protected:
        void LoadMapFromFile();

    private:
};

#endif // GAMEMAP_H
