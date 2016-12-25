#include "map.h"

mapa::mapa()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->genera(tam);
	cajas = 0;
	pasos = "";
	this->mapaActual = "Map1";
}

void mapa::cargaArch()
{
	string direc = "maps/";
	direc += this->mapaActual + ".txt";
	
	ifstream entrada (direc.c_str());
	string fila;
	cajas = 0;
	for (int i = 0; i < tam; i++)
	{
		
		getline(entrada, fila);
		for (int j = 0; j < tam; j++)
		{
			this->setSuelo(fila[j]-48, i, j);
		}
		
	}
	
	for (int i = 0; i < tam; i++)
	{

		getline(entrada, fila);
		for (int j = 0; j < tam; j++)
		{
			this->setMovible(fila[j] - 48, i, j);
			if (fila [j]-48== CAJA)
				this->cajas++;
		}

	}

	entrada.close();

}

void mapa::genera(int largo)
{
	if (largo == 0)
		return;

	if (this->primero == nullptr)
	{
		this->primero = new nodo;
		this->primero->createRight(largo);
		ant = primero;
		this->genera(largo - 1);
	}
	else
	{
		aux = new nodo;
		aux->createRight(tam);
		for (int i = 0; i < tam; i++)
		{
			aux->getRight(i)->setUp(ant->getRight(i));
			ant->getRight(i)->setDown(aux->getRight(i));
		}
		ant = aux->getRight(0);
		this->genera(largo - 1);
	}
}

nodo* mapa::getNodo(int x, int y)
{
	ant = primero;
	ant = primero->getDown(x)->getRight(y);
	return ant;
}

string mapa::toString()
{
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			std::cout << this->getNodo(i, j)->getSuelo().id << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			std::cout << this->getNodo(i, j)->getMovible().id << " ";
		}
		std::cout << "\n";
	}

	return "";
}

void mapa::setSuelo(cosaSuelo* cosa, int x, int y)
{
	this->getNodo(x, y)->setSuelo(cosa);
}

void mapa::setMovible(cosaMovible* cosa, int x, int y)
{
	this->getNodo(x, y)->setMovible(cosa);
}

void mapa::setMovible(int cosa, int x, int y)
{

	switch (cosa)
	{
	case 0: this->getNodo(x, y)->setMovible(new cosaMovible); break;
	case 2: this->getNodo(x, y)->setMovible(new caja); break;
	case 3: this->getNodo(x, y)->setMovible(new personaje); this->pj[0] = x; this->pj[1] = y; break;
	default:
		break;
	}

}

void mapa::setSuelo(int cosa, int x, int y)
{

	switch (cosa)
	{
	case 0: this->getNodo(x, y)->setSuelo(new suelo); break;
	case 1: this->getNodo(x, y)->setSuelo(new pared); break;
	case 4: this->getNodo(x, y)->setSuelo(new meta); break;

	default:
		break;
	}
	
}

bool mapa::mover(int direc)
{
	switch (direc)
	{

	case ARRIBA:
		if (pj[0] - 1 < 0)
			return false;
		if (this->getNodo(pj[0], pj[1])->getUp()->getSuelo().id != PARED)
		{
			if (this->getNodo(pj[0], pj[1])->getUp()->getMovible().id == CAJA)
			{
				if (this->getNodo(pj[0], pj[1])->getUp(2)->getSuelo().id != PARED &&  this->getNodo(pj[0], pj[1])->getUp(2)->getMovible().id != CAJA)
				{
					if (pj[0] - 2 < 0)
						return false;
					this->setMovible(0, pj[0], pj[1]);
					this->pj[0] -= 1;

					this->setMovible(2, pj[0] - 1, pj[1]);
				}
			}
			else
			{
				this->setMovible(0, pj[0], pj[1]);
				this->pj[0] -= 1;
			}
		}
		
		this->setMovible(3, pj[0], pj[1]);
	
		return true;
	case DERECHA:
		if (pj[1] + 1 >= tam)
			return false;
		if (this->getNodo(pj[0], pj[1])->getRight()->getSuelo().id != PARED)
		{
			if (this->getNodo(pj[0], pj[1])->getRight()->getMovible().id == CAJA)
			{
				if (this->getNodo(pj[0], pj[1])->getRight()->getRight()->getSuelo().id != PARED && this->getNodo(pj[0], pj[1])->getRight(2)->getMovible().id != CAJA)
				{
					if (pj[1] + 2 >= tam)
						return false;
					this->setMovible(0, pj[0], pj[1]);
					this->pj[1] += 1;
					
					this->setMovible(2, pj[0], pj[1]+1);
				}
			}
			else
			{
				this->setMovible(0, pj[0], pj[1]);
				this->pj[1] += 1;
			}
			
		}
		
		
		this->setMovible(3, pj[0], pj[1]);
		
		return true;
	case ABAJO: 
		if (pj[0] + 1 >= tam)
			return false;
		if (this->getNodo(pj[0], pj[1])->getDown()->getSuelo().id != PARED)
		{
			if (this->getNodo(pj[0], pj[1])->getDown()->getMovible().id == CAJA)
			{
				if (this->getNodo(pj[0], pj[1])->getDown()->getDown()->getSuelo().id != PARED && this->getNodo(pj[0], pj[1])->getDown(2)->getMovible().id != CAJA)
				{
					if (pj[0] + 2 >= tam)
						return false;
					this->setMovible(0, pj[0], pj[1]);
					this->pj[0] += 1;
					
					this->setMovible(2, pj[0]+1, pj[1]);
				}
			}
			else
			{
				this->setMovible(0, pj[0], pj[1]);
				this->pj[0] += 1;
			}

		}
		
		
		this->setMovible(3, pj[0], pj[1]);
		
		return true;
	case IZQUIERDA: 
		if (pj[1] - 1 < 0)
			return false;
		if (this->getNodo(pj[0], pj[1])->getLeft()->getSuelo().id != PARED)
		{
			if (this->getNodo(pj[0], pj[1])->getLeft()->getMovible().id == CAJA)
			{
				if (this->getNodo(pj[0], pj[1])->getLeft()->getLeft()->getSuelo().id != PARED && this->getNodo(pj[0], pj[1])->getLeft(2)->getMovible().id != CAJA)
				{
					if (pj[1] - 2 < 0)
						return false;
					this->setMovible(0, pj[0], pj[1]);
					this->pj[1] -= 1;

					this->setMovible(2, pj[0], pj[1] - 1);
				}
			}
			else
			{
				this->setMovible(0, pj[0], pj[1]);
				this->pj[1] -= 1;
			}
		}
		
		this->setMovible(3, pj[0], pj[1]);
		
		return true;

	default:
		return false;
	}
}

void mapa::anadePaso(int paso)
{
	this->pasos += (char)(paso+48);
	//actualizaJug();
}

/*void mapa::quitaPaso()
{
	pasos.pop_back();
}
*/
bool mapa::gano()
{
	int aux = 0;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			if (getNodo(i, j)->getMovible().id == CAJA && getNodo(i, j)->getSuelo().id == META)
			{
				aux++;
				if (aux == cajas)
					return true;
			}
				
		}
	}
	return false;
}

void mapa::actualizaJug()
{
	ofstream salida;
	if (mapaActual == "")
		return;
	if (mapaActual == "Map1")
		salida.open("saves/M1Save.txt");
	if (mapaActual == "Map2")
		salida.open("saves/M2Save.txt");
	if (mapaActual == "Map3")
		salida.open("saves/M3Save.txt");
	if (mapaActual == "Map4")
		salida.open("saves/M4Save.txt");
	if (mapaActual == "Map5")
		salida.open("saves/M5Save.txt");

	salida << pasos;
	salida.close();
}

/*void mapa::pasoAnt()
{
	this->cargaArch();

	int i = 0;
	if (pasos[i] == '\0')
		return;
	while (pasos[i] != '\0')
	{
		this->mover((int)pasos[i]);
		i++;
	}	
	rep();
}
*/
void mapa::cargaJugada()
{
	pasos = "";
	ifstream entrada;
	if (mapaActual == "")
		return;
	if (mapaActual == "Map1")
		entrada.open("saves/M1Save.txt");
	if (mapaActual == "Map2")
		entrada.open("saves/M2Save.txt");
	if (mapaActual == "Map3")
		entrada.open("saves/M3Save.txt");
	if (mapaActual == "Map4")
		entrada.open("saves/M4Save.txt");
	if (mapaActual == "Map5")
		entrada.open("saves/M5Save.txt");
	
	getline(entrada, pasos);
	this->rep();
	entrada.close();
}


void mapa::rep()
{
	int i = 0;
	this->cargaArch();

	while (pasos[i] != '\0')
	{
		this->mover((int)pasos[i]-48);
		i++;
	}
}

/*void mapa::continua()
{
	cargaJugada();

	rep();

}*/

mapa::~mapa()
{
	for (int i = 0; i < tam-1; i++)
	{
		aux = primero->getDown(1);
		primero->deleteRight();
		primero = aux;
	}
}



