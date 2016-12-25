#include "nodo.h"


nodo::nodo()
{
	this->up = nullptr;
	this->right = nullptr;
	this->left = nullptr;
	this->down = nullptr;
	this->movil = new cosaMovible;
	this->suelo = new cosaSuelo;
}

// gets

nodo* nodo::getUp()
{
	return this->up;
}

nodo* nodo::getDown()
{
	return this->down;
}

nodo* nodo::getLeft()
{
	return this->left;
}

nodo* nodo::getRight()
{
	return  this->right;
}

// sets

void nodo::setUp (nodo* up)
{
	this->up = up;
}

void nodo::setDown(nodo* down)
{
	this->down = down;
}

void nodo::setLeft(nodo* left)
{
	this->left = left;
}

void nodo::setRight(nodo* right)
{
	this->right = right;
}

// metodos para Cosa

void nodo::setMovible(cosaMovible* cosa)
{
	delete (movil);
	this->movil = cosa;
}


cosaMovible nodo::getMovible()
{
	return *this->movil;
}

void nodo::setSuelo(cosaSuelo* cosa)
{
	delete (suelo);
	this->suelo = cosa;
}


cosaSuelo nodo::getSuelo()
{
	return *this->suelo;
}


nodo* nodo::getLeft(int cant) // busco en esta "lista" el nodo # cant
{
	if (cant == 0) // cuando llego al que busco
		return this;
	else
		return this->getLeft()->getLeft(cant - 1); // paso al siguiente
}

nodo* nodo::getRight(int cant) // busco en esta "lista" el nodo # cant
{
	if (cant == 0) // cuando llego al que busco
		return this;
	else
		return this->getRight()->getRight(cant - 1); // paso al siguiente
}

nodo* nodo::getDown(int cant) // busco en esta "lista" el nodo # cant
{
	if (cant == 0) // cuando llego al que busco
		return this;
	else
		return this->getDown()->getDown(cant - 1); // paso al siguiente
}

nodo* nodo::getUp(int cant) // busco en esta "lista" el nodo # cant
{
	if (cant == 0) // cuando llego al que busco
		return this;
	else
		return this->getUp()->getUp (cant -1); // paso al siguiente
}

void nodo::createLeft(int cant)// creo una "lista" hacia la izquierda
{
	if (cant == 0)// cuando terminé
	{
		this->left = nullptr; // 
		return;
	}
	else
	{
		this->setLeft(new nodo()); // creo un nuevo nodo hacia "izquierda"
		this->getLeft()->setRight(this); // A este nodo le doy el "derecha" que sería este
		this->getLeft()->createLeft(cant - 1); // sigo con el siguiente
	}
}

void nodo::createRight(int cant)// creo una "lista" hacia la derecha
{
	if (cant == 0)// cuando terminé
	{
		this->right = nullptr; // 
		return;
	}
	else
	{
		
		


		this->setRight(new nodo()); // creo un nuevo nodo hacia "derecha"
		this->getRight()->setLeft(this); // A este nodo le doy el "izquierda" que sería este
	
		this->getRight()->createRight(cant - 1); // sigo con el siguiente
	}
}

void nodo::createDown(int cant)// creo una "lista" hacia abajo
{
	if (cant == 0)// cuando terminé
	{
		this->down = nullptr; // 
		return;
	}
	else
	{
		this->setDown(new nodo()); // creo un nuevo nodo hacia "abajo"
		this->getDown()->setUp(this); // A este nodo le doy el "arriba" que sería este
		this->getDown()->createDown(cant - 1); // sigo con el siguiente
	}
}

void nodo::createUp(int cant)// creo una "lista" hacia arriba
{
	if (cant == 0)// cuando terminé
	{
		this->up = nullptr; // 
		return;
	}
	else
	{
		this->setUp(new nodo()); // creo un nuevo nodo hacia "arriba"
		this->getUp()->setDown(this); // A este nodo le doy el "abajo" que sería este
		this->getUp()->createUp(cant - 1); // sigo con el siguiente
	}
}

void nodo::deleteUp() // iré borrando en esta dirección
{
	if (this->getUp() == nullptr) // llegué al final
	{
		delete (this); // borro
		return;
	}
	else
	{
		this->getUp()->deleteUp();// voy buscando el final de esta "lista"
		delete (this);//borro
	}
}

void nodo::deleteDown() // iré borrando en esta dirección
{
	if (this->getDown() == nullptr) // llegué al final
	{
		delete (this); // borro
		return;
	}
	else
	{
		this->getDown()->deleteDown();// voy buscando el final de esta "lista"
		delete (this);//borro
	}
}

void nodo::deleteRight() // iré borrando en esta dirección
{
	if (this->getRight() == nullptr) // llegué al final
	{
		delete (this); // borro
	}
	else
	{
		this->getRight()->deleteRight();// voy buscando el final de esta "lista"
		delete (this);//borro
	}
}

void nodo::deleteLeft() // iré borrando en esta dirección
{
	if (this->getLeft() == nullptr) // llegué al final
	{
		delete (this); // borro
		return;
	}
	else
	{
		this->getLeft()->deleteLeft();// voy buscando el final de esta "lista"
		delete (this);//borro
	}
}









nodo::~nodo()
{

}