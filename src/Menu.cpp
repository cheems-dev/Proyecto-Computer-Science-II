#include "../headers/include/Menu.h"

Menu::Menu()
{
  Init();
}

Menu::~Menu()
{
  delete window;
}

void Menu::Init()
{
  window = new RenderWindow(VideoMode(576, 324), "LlamaGames");
  // Cargar las texturas
  texBackground.loadFromFile("./assets/swamp-game-tileset/2 Background/Background.png");
  textChar.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter_idle.png");

  spBackground.setTexture(texBackground);
  spChar.setTexture(textChar);
  spChar.setTextureRect({0,0,48,48});
  spChar.setPosition(200, 200);
  Run();
}

void Menu::Run()
{
  // Bucle del juego
  while (window->isOpen())
  {
    // Eventos de pantalla
    Event event;
    while (window->pollEvent(event))
    {
      if (event.type == event.Closed)
        window->close();
    }
    Draw();
  }
}

void Menu::Update()
{
}

void Menu::Draw()
{
  // Limpiar a ventana
  window->clear(Color::Black);
  // Dibujar los sprites del juego
  window->draw(spBackground);
  window->draw(spChar);
  // Refrescar la ventana
  window->display();
}