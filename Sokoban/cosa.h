#pragma once
#include <iostream>
using namespace std;
/*
	Esta clase va a ser para poder tener una Interface de el tipo de cosas que usarán los nodos del mapa
	de esta clase se heredará a PJ, Pared y Caja
*/

// global
enum Direcciones { NO, ARRIBA, DERECHA, ABAJO, IZQUIERDA };
enum Cosas {SUELO, PARED, CAJA, PERSONAJE, META};


class Cosa
{

public:
	int id;
	Cosa();

	~Cosa();

};

