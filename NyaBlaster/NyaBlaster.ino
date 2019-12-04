#include <Arduboy2.h>
#include "game.cpp"
Arduboy2 ard;
Sprites sprites;




Game game;

void setup() {
  ard.boot();
  ard.flashlight();
  ard.clear();
  ard.setFrameRate(30);
  game.Init();
}

void loop() {
  if(!ard.nextFrame())
    return;
    
  ard.pollButtons();
  ard.clear();
    
  game.Update();
  
  ard.display();
}
