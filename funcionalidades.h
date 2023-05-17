#pragma once
#include <string>
#include <list>
#include "struct.h"
#include "kdTree.h"

//cargar_elementos userInput[1], nombre_archivo userInput[2]
void cargar_elementos(std::string nombre_archivo,std::list<Elemento> *ListaElemento);
//cargar_comandos userInput[1], nombre_archivo userInput[2]
void cargar_comandos(std::string nombre_archivo,std::list<Analisis> *listaAnalisis,std::list<Movimientos> *listaMovimientos);
//guardar userInput[1], tipo_archivo userInput[2], nombre_archivo userInput[3]
void guardar(std::string tipo_archivo,std::string nombre_archivo,std::list<Elemento> *ListaElemento,std::list<Analisis> *listaAnalisis,std::list<Movimientos> *listaMovimientos);
//simular_comandos userInput[1], coordX userInput[2], coordY userInput[3]
void simular_comandos(std::string coordX,std::string coordY,std::list<Movimientos> *listaMovimientos,std::list<Elemento> *ListaElemento,Curiosity *self);
//agregar_analisis userInput[1], tipo_analisis userInput[2], objeto userInput[3], comentario userInput[4]
void agregar_analisis(std::string tipo_analisis,std::string objeto,std::string comentario,std::list<Analisis> *listaAnalisis);
//agregar_movimiento userInput[1], tipo_mov userInput[2], magnitud userInput[3], unidad_med userInput[4]
void agregar_movimiento(std::string tipo_mov,std::string magnitud,std::string unidad_med,std::list<Movimientos> *listaMovimientos);
//agregar_elemento userInput[1], tipo_comp userInput[2], tamaño userInput[3], unidad_med[4], coordX[5], coordY[6]
void agregar_elemento(std::string tipo_comp,std::string tamaño,std::string unidad_med,std::string coordX,std::string coordY, std::list<Elemento> *ListaElemento);
void ubicar_elementos(std::list<Elemento> *ListaElemento,kdTree<2> *kdtree);

void help();
