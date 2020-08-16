#include "./src/Game.cpp"
#include "./src/PlayScene.cpp"
#include "./src/MenuScene.cpp"
#include "./src/EndScene.cpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    BaseScene *scene = new MenuScene();
    Game &g = Game::create(VideoMode(576, 324), scene, "Jungle Arcade");
    g.run();
    return 0;
}