#include "ventana.h"


ventana::ventana()
{
	cargar = false;
	this->mapat.cargaArch();
	//this->mapat.toString();
}

int ventana::manejaEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->mapat.anadePaso(ARRIBA);
		return ARRIBA;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->mapat.anadePaso(ABAJO);
		return ABAJO;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->mapat.anadePaso(IZQUIERDA);
		return IZQUIERDA;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->mapat.anadePaso(DERECHA);
		return DERECHA;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		this->mapat.cargaArch();
		this->mapat.pasos = "";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (restartSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			this->mapat.cargaArch();
			this->mapat.pasos = "";
		}
		if (salirSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			window.close();
		if (mapasSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			cargar = false;
			window.close();
			abrirMapas();
		}
		if (inicioSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			window.close();
			abrirMenuInicio();
		}
		if (continuarSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{	
			cargar = true;
			this->abrirMapas();
		}

		if (guardarSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			this->mapat.actualizaJug();
		}

	}

}

void ventana::init()
{
	if (!suelo.loadFromFile("imagenes/suelo.png"))
		cout << "erro al cargar suelo";
	if (!meta.loadFromFile("imagenes/meta.png"))
		cout << "error al cargar meta";
	if (!pared.loadFromFile("imagenes/pared.png"))
		cout << "error al cargar pared";
	if (!caja.loadFromFile("imagenes/caja.png"))
		cout << "error al cargar caja";
	if (!mario.loadFromFile("imagenes/mario.png"))
		cout << "error al cargar mario";
	if (!inicio.loadFromFile("imagenes/inicio.png"))
		cout << "error al cargar inicio";
	if (!continuar.loadFromFile("imagenes/continuar.png"))
		cout << "error al cargar continuar";
	if (!guardar.loadFromFile("imagenes/guardar.png"))
		cout << "error al cargar guardar";
	if (!salir.loadFromFile("imagenes/salir.png"))
		cout << "error al cargar salir";
	if (!repeticion.loadFromFile("imagenes/repeticion.png"))
		cout << "error al cargar repeticion";
	if (!victoria.loadFromFile("imagenes/victoria.png"))
		cout << "error al cargar victoria";
	if (!Map1.loadFromFile("imagenes/Map1.png"))
		cout << "error al cargar Map1";
	if (!Map2.loadFromFile("imagenes/Map2.png"))
		cout << "error al cargar Map2";
	if (!Map3.loadFromFile("imagenes/Map3.png"))
		cout << "error al cargar Map3";
	if (!Map4.loadFromFile("imagenes/Map4.png"))
		cout << "error al cargar Map4";
	if (!Map5.loadFromFile("imagenes/Map5.png"))
		cout << "error al cargar Map5";
	if (!restart.loadFromFile("imagenes/Reiniciar.png"))
		cout << "error al cargar Map5";
	if (!mapasT.loadFromFile("imagenes/mapas.png"))
		cout << "error al cargar mapas";

	sueloSprite.setTexture(suelo);
	paredSprite.setTexture(pared);
	cajaSprite.setTexture(caja);
	pjSprite.setTexture(mario);
	metaSprite.setTexture(meta);
	inicioSprite.setTexture(inicio);
	repeticionSprite.setTexture(repeticion);
	continuarSprite.setTexture(continuar);
	guardarSprite.setTexture(guardar);
	salirSprite.setTexture(salir);
	victoriaSprite.setTexture(victoria);
	map1Sprite.setTexture(Map1);
	map2Sprite.setTexture(Map2);
	map3Sprite.setTexture(Map3);
	map4Sprite.setTexture(Map4);
	map5Sprite.setTexture(Map5);
	restartSprite.setTexture(restart);
	mapasSprite.setTexture(mapasT);



	sueloSprite.setScale(0.5, 0.5);
	paredSprite.setScale(0.5, 0.5);
	cajaSprite.setScale(0.5, 0.5);
	pjSprite.setScale(1,1);
	metaSprite.setScale(1, 1);
	inicioSprite.setScale(1, 1);
	repeticionSprite.setScale(1, 1);
	guardarSprite.setScale(1, 1);
	continuarSprite.setScale(1, 1);
	salirSprite.setScale(1, 1);
	victoriaSprite.setScale(1, 1);
	map1Sprite.setScale(1, 1);
	map2Sprite.setScale(1, 1);
	map3Sprite.setScale(1, 1);
	map4Sprite.setScale(1, 1);
	map5Sprite.setScale(1, 1);
	restartSprite.setScale(1, 1);
	mapasSprite.setScale(0.7, 1);
}

void ventana::refresh()
{
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam*0.8; j++)
		{
			switch (this->mapat.getNodo(j, i)->getSuelo().id)
			{
			case PARED:
				paredSprite.setPosition(i * 32, j * 32);
				window.draw(paredSprite);
				break;
			case SUELO:
				sueloSprite.setPosition(i * 32, j * 32);
				window.draw(sueloSprite);
				break;
			case META:
				metaSprite.setPosition(i * 32, j * 32);
				window.draw(metaSprite);
				break;
			default:
				break;
			}


			switch (this->mapat.getNodo(j, i)->getMovible().id)
			{
			case CAJA:
				cajaSprite.setPosition(i * 32, j * 32);
				window.draw(cajaSprite);
				break;
			case PERSONAJE:
				pjSprite.setPosition(i * 32, j * 32);
				window.draw(pjSprite);
				break;
			default:
				break;
			}

		}
	}
}

void ventana::refresh2()
{
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam*0.75; j++)
		{
			switch (this->mapat.getNodo(j, i)->getSuelo().id)
			{
			case PARED:
				paredSprite.setPosition(i * 32, j * 32);
				Repeticion.draw(paredSprite);
				break;
			case SUELO:
				sueloSprite.setPosition(i * 32, j * 32);
				Repeticion.draw(sueloSprite);
				break;
			case META:
				metaSprite.setPosition(i * 32, j * 32);
				Repeticion.draw(metaSprite);
				break;
			default:
				break;
			}


			switch (this->mapat.getNodo(j, i)->getMovible().id)
			{
			case CAJA:
				cajaSprite.setPosition(i * 32, j * 32);
				Repeticion.draw(cajaSprite);
				break;
			case PERSONAJE:
				pjSprite.setPosition(i * 32, j * 32);
				Repeticion.draw(pjSprite);
				break;
			default:
				break;
			}

		}
	}
}

void ventana::abrirJuego()
{
	this->cargar = false;
	this->closeAll();
	window.create(sf::VideoMode(800, 505), "Sokoban");
	
	inicioSprite.setPosition(640, 0);
	restartSprite.setPosition(640, 80);
	mapasSprite.setPosition(640,160);
	salirSprite.setPosition(640, 240);
	guardarSprite.setPosition(640, 320);
	inicioSprite.setScale(0.70,1);
	guardarSprite.setScale(0.70, 1);
	salirSprite.setScale(0.7, 1);
	restartSprite.setScale(0.7, 1);

	while (window.isOpen())
	{	
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			this->mapat.mover(manejaEvento());
			if (mapat.gano())
			{
				window.close();
				this->abrirMenuFin();
			}
			

		}
	
		window.clear(sf::Color::Black);
		window.draw(inicioSprite);
		window.draw(restartSprite);
		window.draw(salirSprite);
		window.draw(guardarSprite);
		window.draw(inicioSprite);
		window.draw(mapasSprite);
		refresh();
		window.display();
		
	}

}

void ventana::abrirMapas()
{
	this->closeAll();
	mapas.create(sf::VideoMode(250, 500), "Sokoban");
	map1Sprite.setPosition(0, 0);
	map2Sprite.setPosition(0, 100);
	map3Sprite.setPosition(0, 200);
	map4Sprite.setPosition(0, 300);
	map5Sprite.setPosition(0, 400);
	Sleep(100);
	while (mapas.isOpen())
	{
		
		sf::Event event;
		while (mapas.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				mapas.close();
				this->abrirMenuInicio();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (map1Sprite.getGlobalBounds().contains(mapas.mapPixelToCoords(sf::Mouse::getPosition(mapas))))
				{
					mapas.close();
					this->mapat.pasos = "";
					mapat.mapaActual = "Map1";
					mapat.cargaArch();
					if (cargar)
					{
						this->mapat.cargaJugada();
						this->mapat.rep();
					}
					abrirJuego();
				}
				if (map2Sprite.getGlobalBounds().contains(mapas.mapPixelToCoords(sf::Mouse::getPosition(mapas))))
				{
					mapas.close();
					this->mapat.pasos = "";
					mapat.mapaActual = "Map2";
					mapat.cargaArch();
					if (cargar)
						this->mapat.cargaJugada();
					abrirJuego();
				}
				if (map3Sprite.getGlobalBounds().contains(mapas.mapPixelToCoords(sf::Mouse::getPosition(mapas))))
				{
					mapat.mapaActual = "Map3";
					this->mapat.pasos = "";
					mapat.cargaArch();
					if (cargar)
						this->mapat.cargaJugada();
					abrirJuego();
				}
				if (map4Sprite.getGlobalBounds().contains(mapas.mapPixelToCoords(sf::Mouse::getPosition(mapas))))
				{

					mapas.close();
					this->mapat.pasos = "";
					mapat.mapaActual = "Map4";
					mapat.cargaArch();
					if (cargar)
						this->mapat.cargaJugada();
					abrirJuego();
				}
				if (map5Sprite.getGlobalBounds().contains(mapas.mapPixelToCoords(sf::Mouse::getPosition(mapas))))
				{
					mapas.close();
					this->mapat.pasos = "";
					mapat.mapaActual = "Map5";
					mapat.cargaArch();
					if (cargar)
						this->mapat.cargaJugada();
					abrirJuego();
				}



			}

		}

		mapas.clear(sf::Color::Black);
		mapas.draw(map1Sprite);
		mapas.draw(map2Sprite);
		mapas.draw(map3Sprite);
		mapas.draw(map4Sprite);
		mapas.draw(map5Sprite);
		mapas.display();

	}
}

void ventana::abrirMenuInicio()
{
	this->closeAll();
	menuInicio.create(sf::VideoMode(250, 300), "Sokoban");


	while (menuInicio.isOpen())
	{
		inicioSprite.setScale(1, 1);
		salirSprite.setScale(1, 1);
		inicioSprite.setPosition(0, 00);;
		continuarSprite.setPosition(0, 100);
		salirSprite.setPosition(0, 200);

		sf::Event event;
		while (menuInicio.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				menuInicio.close();

			if (sf::Mouse::isButtonPressed (sf::Mouse::Left))
			{
				if (inicioSprite.getGlobalBounds().contains(menuInicio.mapPixelToCoords(sf::Mouse::getPosition(menuInicio))))
				{
					menuInicio.close();
					this->abrirMapas();
				}

				if (continuarSprite.getGlobalBounds().contains(menuInicio.mapPixelToCoords(sf::Mouse::getPosition(menuInicio))))
				{
					menuInicio.close();
					cargar = true;
					this->abrirMapas();
				}

				if (salirSprite.getGlobalBounds().contains(menuInicio.mapPixelToCoords(sf::Mouse::getPosition(menuInicio))))
				{
					menuInicio.close();
				}
			}
			
			
		}
		menuInicio.clear(sf::Color::Black);
		menuInicio.draw(inicioSprite);
		menuInicio.draw(continuarSprite);
		menuInicio.draw(salirSprite);
		menuInicio.display();
	}
}

void ventana::abrirMenuFin()
{
	this->closeAll();
	menuFin.create(sf::VideoMode(800, 600), "Sokoban");

	victoriaSprite.setPosition(100,0);
	repeticionSprite.setPosition(300, 300);
	continuarSprite.setPosition(300, 400);
	salirSprite.setPosition(300, 500);
	salirSprite.setScale(1, 1);

	while (menuFin.isOpen())
	{
		sf::Event event;
		while (menuFin.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				menuInicio.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (repeticionSprite.getGlobalBounds().contains(menuFin.mapPixelToCoords(sf::Mouse::getPosition(menuFin))))
				{
					abrirRepeticion();
				}

				if (continuarSprite.getGlobalBounds().contains(menuFin.mapPixelToCoords(sf::Mouse::getPosition(menuFin))))
				{
					this->menuFin.close();
					
					switch (mapat.mapaActual[3])
					{
					case 49: mapat.mapaActual = "Map2"; break;
					case 50: mapat.mapaActual = "Map3"; break;
					case 51: mapat.mapaActual = "Map4"; break;
					case 52: mapat.mapaActual = "Map5"; break;
					case 53: mapat.mapaActual = "Map1"; break;
					default: menuFin.close(); window.close();
					}
					mapat.pasos = "";
					mapat.cargaArch();
					this->abrirJuego();
				}

				if (salirSprite.getGlobalBounds().contains(menuFin.mapPixelToCoords(sf::Mouse::getPosition(menuFin))))
				{
					menuFin.close();
					window.close();
				}
			}
		}

		menuFin.clear(sf::Color::Black);
		menuFin.draw(victoriaSprite);
		menuFin.draw(repeticionSprite);
		menuFin.draw(continuarSprite);
		menuFin.draw(salirSprite);
		menuFin.display();

	}

}

void ventana::abrirRepeticion()
{
	Repeticion.create(sf::VideoMode(640, 482), "Repeticion");
	mapat.cargaArch();
	int i = 0;
	
	while (Repeticion.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		Sleep(200);
		mapat.mover(int(mapat.pasos[i]) -48);
		Repeticion.clear(sf::Color::Black);
		refresh2();
		Repeticion.display();
		i++;
		
		if (i == mapat.pasos.length())
			Repeticion.close();
	}

	

}


void ventana::closeAll()
{
	this->window.close();
	this->menuFin.close();
	this->menuInicio.close();
	this->mapas.close();
}

ventana::~ventana()
{
}

