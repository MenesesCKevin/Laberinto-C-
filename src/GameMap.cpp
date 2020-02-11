#include "GameMap.h"
#include <iostream>
#include <fstream>
using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;
}
void GameMap::DrawIntro(){
    string line;
    int row = 0;
    ifstream MyFile("Intro.txt");
    if(MyFile.is_open()){

            while(getline(MyFile, line)){
                cout << line<<endl;
            }
            cin >> line;

    }else{
        cout << "FATAL ERROR: INTRO FILE COULD NOT BE LOADED"<<endl;
    }

}
void GameMap::DrawVitory(){
    string line;
    int row = 0;
    ifstream MyFile("Vitory.txt");
    if(MyFile.is_open()){

            while(getline(MyFile, line)){
                cout << line<<endl;
            }
            cin >> line;

    }else{
        cout << "FATAL ERROR: Vitory FILE COULD NOT BE LOADED"<<endl;
    }

}
void GameMap::Draw(){
    for(int i =0; i<15 ; i++){
        for(int j =0; j <10; j++){
            cout << cells[i][j].id;
        }
        cout <<endl;
    }
}
bool GameMap::SetPlayerCell(int PlayerX, int PlayerY){
    if(cells[PlayerY][PlayerX].IsBlocked()==false){
        if(cells[PlayerY][PlayerX].id =='$'){
            DrawVitory();
            isGameOver = true;
            return true;

        }else{
            if (PlayerCell != NULL){
                PlayerCell->id =0;
            }
            PlayerCell = &cells[PlayerY][PlayerX];
            PlayerCell->id = '3';
            //cout <<"Coordenadas: " << PlayerX << "," << PlayerY<<endl;
            return true;
        }
    }
    else{
        return false;
    }
}
void GameMap::LoadMapFromFile(){
    /*ofstream FileCreated("Map.txt");
    if(FileCreated.is_open()){

    }*/
    string line;
    int row = 0;
    ifstream MyFile("Map.txt");
    if(MyFile.is_open()){
            //cout <<"Prueba de dubijado"<<endl;
            while(getline(MyFile, line)){
                //cout << line<<endl;
                for(int k = 0; k < line.length(); k++){
                    if(line[k]== '0') cells[row][k].id = 0;
                    else cells[row][k].id = line[k];
                }
                row ++;
            }
            //cout <<"Prueba de dubijado"<<endl;

    }else{
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED"<<endl;
    }
}
