#include <iostream>
#include "../headers/include/Game.h"

Game::Game(){
  init();
}

void Game::init(){
  window.create(VideoMode(height, width), "GTA 5");
  // El programa se ejecuta a 60 frames x segundo, se ejecuta lo mismo en todas las maquinas
  window.setFramerateLimit(60);
  // Fondo del juego
  texBackground.loadFromFile("./assets/swamp-game-tileset/2 Background/Background.png");
  spBackground.setTexture(texBackground);

  if(!bgm.openFromFile("./assets/music/GameBGM.wav"))
  {
    cout<<"error"<<endl;
  }
  else
  {
    bgm.setLoop(true);
    bgm.play();
  }

  //Terreno
  ground= new Terrain(Vector2f(32.0f,32.0f),Vector2f(16,308.0f));
  
  // Crear el personaje
  character = new Character(Vector2f(100, 200));
  add(character);

  // Crear enemy
  enemy = new Enemy();
  add(enemy);

}

void Game::add(Entity *e){
  entities.push_back(e);
}

void Game::run(){
    // Bucle del juego
  while (window.isOpen())
  {
    // Eventos de pantalla
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == event.Closed)
        window.close();
    }
    update();
    draw();
  }
}

void Game::update(){
  for(auto e: entities)
    e->update();
  // detectar colisiones entre el personjae y la bola
  if (character->collidesWithEnemy(enemy))
    std::cout<<"collide"<<c++<<"\n";
    //window.close();
}

void Game::draw(){

  // Limpia la pantalla
  window.clear(Color::Black);
  // Dibujar los elementos del juego
  window.draw(spBackground);

  //Dibujar el piso :c
  ground->Draw(window);

  for (auto e: entities)
    e->draw(window);

  // refrescar la ventana
  window.display();
}
