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
  window = new RenderWindow(VideoMode(1000, 800), "LlamaGames");
  // Cargar las texturas
  texBackground.loadFromFile("./assets/background/background.png");
  textChar.loadFromFile("./assets/character/veggeta.png");

  spBackground.setTexture(texBackground);
  spChar.setTexture(textChar);

  spChar.setPosition(304, 305);
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