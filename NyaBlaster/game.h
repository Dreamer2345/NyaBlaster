#include "bitmaps.h"
#include "Object.cpp"

enum class GameState {Mainmenu, Initgame ,Gameplay, Gameover};

class Game{
  public:
    static Object * Objects[MaxObjects]; 
    static uint8_t NumberOfObjects;
    static void AddObject(Object obj);
    static void RemoveObject(uint8_t ID);
    static void ResetObjects();
    static void SimObjects();
    static void DrawObjects();

    
    long UniversalVar = -1;
    GameState currentGameState;
    void Init();
    void Update();
    void Draw();
};
