#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"
using namespace std;

int main()
{

    GameMap Map;
    Player Hero;
    Map.DrawIntro();
    Map.Draw();
    //cout <<"Inica el juego" <<endl;
    while(Map.isGameOver == false){
        cout<<"Introduce el comando de movimiento a,s,d,w"<<endl;
        Hero.Callimput();
        if(Map.SetPlayerCell(Hero.x,Hero.y)){;
            Map.Draw();
        }
        else{
            Hero.ResteToSafePosition();
            Map.Draw();
        }
    }
    return 0;
}
