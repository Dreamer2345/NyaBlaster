#include "Object.h"




class Heart : public Object {
  public:
  Heart(uint8_t _x, uint8_t _y){
    Type = 1;
    x = _x;
    y = _y;
    Active = true; 
  }
  
  void Update(){
    x--;

    if(x > 200){
      Active = false;
    }
  }

  void OnCollide(uint8_t Type){
    switch(Type){
      case ObjectTypes::Nya: break;
    }
  }
};
