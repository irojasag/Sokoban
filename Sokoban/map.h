#pragma once
#include "nodo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
const int tam = 20;



class mapa // mapa lleno de nodos
{
private:
	nodo* primero; // "Primer" nodo, de referencia
	nodo* ultimo; // para cuando se recorre saber cuando ha terminado
	nodo *aux, *ant;
	int pj[2];
	
	int cajas;

public:
	string mapaActual;
	string pasos;
	mapa();

	void genera(int);

	nodo* getNodo(int, int);

	void setMovible (cosaMovible*, int, int);
	void setSuelo(cosaSuelo*, int, int);
	void setSuelo(int, int, int);
	void setMovible(int, int, int);

	bool mover(int);

	void cargaArch();

	//void pasoAnt();
	void rep();

	void anadePaso(int);
	//void quitaPaso();
	void cargaJugada();
	bool gano();

//	void continua();

	void actualizaJug();
	string toString();

	~mapa();
};

