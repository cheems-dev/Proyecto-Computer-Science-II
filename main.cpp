#include "./src/Game.cpp"
#include "./src/PlayScene.cpp"
#include "./src/MenuScene.cpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    BaseScene *scene = new MenuScene();
    Game &g = Game::create(VideoMode(576, 324), scene, "GTA 5");
    g.run();

    return 0;
}
