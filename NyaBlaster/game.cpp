#include "game.h"



const uint8_t full = 16;
const uint8_t Squares[] = {0,1,4,9,16,25,36,49,64,100,121,144,169,196,225,256};
Object * Objects[MaxObjects]; 
uint8_t NumberOfObjects = 0;

uint8_t Sqrt(uint8_t n){
  uint8_t Pointer = full / 2;
  for(int i = 0; i < 3; i++){
    if(n > Squares[Pointer])
      Pointer += full / (2*(i+2));
    else
      Pointer -= full / (2*(i+2));
  }
  return Squares[Pointer];
}


bool Collision(Object* obj1, Object* obj2){
  uint16_t XDist = abs(obj1->x - obj2->x);
  uint16_t YDist = abs(obj1->y - obj2->y);
  uint16_t DiagDist = Sqrt(XDist + YDist);
  
  uint16_t Radius = obj1->r + obj2->r;
  if (DiagDist < Radius){
    return true;
  } else{
    return false;
  }
  
}

void Game::DrawObjects(){
  for(int i = 0; i < MaxObjects; i++){
    if(Objects[i] != NULL)
      {
        Objects[i]->Draw(); 
      }
  }
}

void Game::SimObjects(){
  for(int i = 0; i < MaxObjects; i++){
    if(Objects[i] != NULL)
      {
        Objects[i]->Update(); 
      }
  }

  for(int i = 0; i < MaxObjects; i++){
      for(int j = 0; j < MaxObjects; j++){
      if((Objects[i] != NULL)&&(Objects[j] != NULL))
        {
          if(Collision(Objects[i],Objects[j])){
            Objects[i]->OnCollide(Objects[j]->Type);
            Objects[j]->OnCollide(Objects[i]->Type);
          }
        }
    }
  }

  for(int i = 0; i < MaxObjects; i++){
    if(Objects[i] != NULL)
      {
        if(!Objects[i]->Active)
          Objects[i] = NULL;
      }
  }


  
}

void Game::AddObject(Object obj){};
void Game::RemoveObject(uint8_t ID){};

void Game::ResetObjects(){
  for(int i = 0; i < MaxObjects; i++){
    Objects[i] = NULL;
  }

  NumberOfObjects = 0;
}

void Game::Update(){
  switch(currentGameState){
    case GameState::Mainmenu: break;
    case GameState::Gameplay: break;
    case GameState::Initgame: break;
    case GameState::Gameover: break;
  }
}


void Game::Draw(){
  switch(currentGameState){
    case GameState::Mainmenu: break;
    case GameState::Gameplay: break;
    case GameState::Initgame: break;
    case GameState::Gameover: break;
  }
}

void Game::Init(){
  currentGameState = GameState::Mainmenu;
  Game::ResetObjects();
}
