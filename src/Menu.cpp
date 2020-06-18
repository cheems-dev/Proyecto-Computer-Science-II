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
  // El programa se ejecuta a 60 frames x segundo, se ejecuta lo mismo en todas las maquinas
  window->setFramerateLimit(60);
  // Cargar las texturas
  texBackground.loadFromFile("./assets/swamp-game-tileset/2 Background/Background.png");
  // texLogo.loadFromFile("./assets/menu-tiles/swampescape-logo.png");
  // texPlay.loadFromFile("./assets/menu-tiles/play-unsel.png");
  // texRecords.loadFromFile("./assets/menu-tiles/records-unsel.png");
  // texExit.loadFromFile("./assets/menu-tiles/exit-unsel.png");
  texChar.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter.png");
  textEnemy.loadFromFile("./assets/desert-enemys/2 Hyena/Hyena.png");

  spBackground.setTexture(texBackground);
  // spLogo.setTexture(texLogo);
  // spPlay.setTexture(texPlay);
  // spRecords.setTexture(texRecords);
  // spExit.setTexture(texExit);
  spChar.setTexture(texChar);
  spEnemy.setTexture(textEnemy);

  spLogo.scale(1.7f, 1.7f);
  // spLogo.setPosition(0, 80);
  // spPlay.setPosition(400, 50);
  // spRecords.setPosition(400, 125);
  // spExit.setPosition(400, 200);
  spChar.setPosition(100, 200);
  // Posicionar al enemigo
  srand(time(0));
  spEnemy.setPosition(rand()%300,200);
  vellEnemy.x = 2 + rand() % 3;
  
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
    Update();
    Draw();
  }
}

void Menu::Update()
{
  // Movimiento de nuestro sprite
  if (Keyboard::isKeyPressed(Keyboard::A))
    spChar.move(-5, 0);
  else if (Keyboard::isKeyPressed(Keyboard::D))
    spChar.move(5, 0);
  // else if (Keyboard::isKeyPressed(Keyboard::W))
  // {
  //   spChar.move(2, -2);
  //   spChar.move(2, -1);
  //   spChar.move(2, -0);
  //   spChar.move(2, +2);
  //   // spChar.move(5, 0);
  // }
  

  //Limitar el movimiento del personaje a la ventana
  Vector2f charPos = spChar.getPosition();
  if (charPos.x < 0)
    charPos.x = 0;
  if (charPos.x > 600)
    charPos.x = 600;
  spChar.setPosition(charPos);

  // Mover al enemigo
  spEnemy.move(vellEnemy);
  Vector2f charPosEnemy = spEnemy.getPosition();
  if(charPosEnemy.x < 200){
    charPosEnemy.x = 200;
    vellEnemy.x *= -1;
  }
  if(charPosEnemy.x > 350){
    charPosEnemy.x = 350;
    vellEnemy.x *= -1;
  }
  spEnemy.setPosition(charPosEnemy);
}

void Menu::Draw()
{
  // Limpiar a ventana
  window->clear(Color::Black);
  // Dibujar los sprites del juego
  window->draw(spBackground);
  // window->draw(spLogo);
  // window->draw(spPlay);
  // window->draw(spRecords);
  // window->draw(spExit);
  window->draw(spChar);
  window->draw(spEnemy);
  // Refrescar la ventana
  window->display();
}
