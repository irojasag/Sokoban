/*
Para el manejo de la librería SFML me basé en los ejemplos que se desarrollan en
esta lista de repoducción:
https://www.youtube.com/watch?v=FLpD54gx_5w&list=PLRtjMdoYXLf776y4K432eL_qPw4na_py3
*/



#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"



class ventana
{
private:
	bool cargar;
	mapa mapat;
	sf::Texture pared;
	sf::Texture caja;
	sf::Texture mario;
	sf::Texture meta;
	sf::Texture suelo;
	sf::Texture inicio;
	sf::Texture continuar;
	sf::Texture guardar;
	sf::Texture repeticion;
	sf::Texture salir;
	sf::Texture victoria;
	sf::Texture Map1;
	sf::Texture Map2;
	sf::Texture Map3;
	sf::Texture Map4;
	sf::Texture Map5;
	sf::Texture restart;
	sf::Texture mapasT;

	sf::Sprite paredSprite;
	sf::Sprite cajaSprite;
	sf::Sprite pjSprite;
	sf::Sprite metaSprite;
	sf::Sprite sueloSprite;
	sf::Sprite inicioSprite;
	sf::Sprite continuarSprite;
	sf::Sprite guardarSprite;
	sf::Sprite repeticionSprite;
	sf::Sprite salirSprite;
	sf::Sprite victoriaSprite;
	sf::Sprite map1Sprite;
	sf::Sprite map2Sprite;
	sf::Sprite map3Sprite;
	sf::Sprite map4Sprite;
	sf::Sprite map5Sprite;
	sf::Sprite restartSprite;
	sf::Sprite mapasSprite;

	sf::RenderWindow window;
	sf::RenderWindow menuInicio;
	sf::RenderWindow menuFin;
	sf::RenderWindow mapas;
	sf::RenderWindow Repeticion;


public:
	ventana();
	int manejaEvento();
	void abrirJuego();
	void abrirMenuInicio();
	void abrirMenuFin();
	void abrirMapas();
	void abrirRepeticion();
	void init();
	void refresh();
	void refresh2();
	void closeAll();

	~ventana();
};


