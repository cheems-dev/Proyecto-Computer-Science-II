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
  window = new RenderWindow(VideoMode(576, 324), "Swamp Escape v1.0");
  // Cargar las texturas
  texBackground.loadFromFile("./assets/swamp-game-tileset/2 Background/Background.png");
  texLogo.loadFromFile("./assets/menu-tiles/swampescape-logo.png");
  texPlay.loadFromFile("./assets/menu-tiles/play-unsel.png");
  texRecords.loadFromFile("./assets/menu-tiles/records-unsel.png");
  texExit.loadFromFile("./assets/menu-tiles/exit-unsel.png");

  spBackground.setTexture(texBackground);
  spLogo.setTexture(texLogo);
  spPlay.setTexture(texPlay);
  spRecords.setTexture(texRecords);
  spExit.setTexture(texExit);

  spLogo.scale(1.7f , 1.7f);
  spLogo.setPosition(0, 80);
  spPlay.setPosition(400,50);
  spRecords.setPosition(400,125);
  spExit.setPosition(400,200);
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
  window->draw(spLogo);
  window->draw(spPlay);
  window->draw(spRecords);
  window->draw(spExit);
  // Refrescar la ventana
  window->display();
}