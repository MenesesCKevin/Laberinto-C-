#include "Player.h"
#include <iostream>

using namespace std;
Player::Player()
{
    x=1;
    y=1;
}
void Player::Callimput(){
    char UserInput = ' ';
    cin >> UserInput;
    switch(UserInput){
    case 'w':
        lastY = y;
        y --;
        //cout<<"El jugador se mueve arriba"<<endl;
        break;
    case 's':
        lastY = y;
        y++;
        //cout<<"El jugador se mueve abajo"<<endl;
        break;
    case 'a':
        lastX = x;
        x--;
        //cout<<"El jugador se mueve izquierda"<<endl;
        break;
    case 'd':
        lastX = x;
        x++;
        //cout<<"El jugador se mueve derecha"<<endl;
        break;
    }

}
void Player::ResteToSafePosition()
{

    x = lastX;
    y= lastY;
}
