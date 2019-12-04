#include <Arduboy2.h>
#define MaxObjects 10
enum ObjectTypes {Heart, Bullet, Nya, Love};

class Object {
  public:
    uint8_t x,y,r,ID,Type;
    bool Active = false;
    virtual void Update();
    virtual void Draw();
    virtual void OnCollide(uint8_t Type);
};



