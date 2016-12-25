#pragma once
#include "pared.h"
#include "caja.h"
#include "personaje.h"
#include "suelo.h"
#include "meta.h"
#include "cosaMovible.h"
#include "cosaSuelo.h"

class nodo // nodos del mapa
{
private:

	nodo *up;
	nodo *right;
	nodo *left;
	nodo *down;

	cosaSuelo *suelo;
	cosaMovible *movil;
	

public:
	
	nodo();
	// gets
	nodo* getUp();
	nodo* getRight();
	nodo* getLeft();
	nodo* getDown();
	// sets
	void setUp(nodo*);
	void setRight(nodo*);
	void setLeft(nodo*);
	void setDown(nodo*);

	cosaMovible getMovible();

	cosaSuelo getSuelo();

	void setMovible(cosaMovible*);
	void setSuelo(cosaSuelo*);

	void createRight(int);
	void createLeft(int);
	void createUp(int);
	void createDown(int);

	nodo* getUp(int);
	nodo* getRight(int);
	nodo* getLeft(int);
	nodo* getDown(int);

	void deleteUp();
	void deleteDown();
	void deleteRight();
	void deleteLeft();

	~nodo();
};