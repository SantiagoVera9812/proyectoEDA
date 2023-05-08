#pragma once
#include "struct.h"
#include <list>
bool simularCoolicionConObjetos(float tamaño, float coordX, float coordY, float posicionActualX, float posicionActualY);

float CoordenadasEnY(float magnitud,float radianes);

float CoordenadasEnX(float magnitud,float radianes);

Curiosity simulacionMovimiento(float magnitud,float radianes, Curiosity *self);

void coolicionDelCuriosity(float nMagnitud, float nRadianes,Curiosity *curiosity,std::list<Elemento> *ListaElemento);