<<<<<<< HEAD
#pragma once
#include <string>
=======
   #pragma once
#include <string>
//al parecer no se usa, toca revisar bien otra vez
>>>>>>> 0711070 (entrega2)
struct info_separada{
    std::string tipo_comando;
    std::string nombre_accion;
    std::string argumento1;
    std::string argumento2;
};

struct Curiosity{

    float coordX;
    float coordy;

};

Curiosity Makecuriosity(float ncoordX,float ncoordY);
<<<<<<< HEAD
float getcoordX(Curiosity *self);
float getCoordY(Curiosity *self);
=======
    float getcoordX(Curiosity *self);
    float getCoordY(Curiosity *self);
>>>>>>> 0711070 (entrega2)

struct Movimientos{

    bool tipo_mov; //0 para movimiento, 1 para giro
    float magnitud;
    std::string  unidad_med; //unidad de medida
};

<<<<<<< HEAD
Movimientos movimiento(bool ntipo_mov,float nmagnitud,std::string nunidad_med);
void getMovimientos(Movimientos *self);
=======
 Movimientos movimiento(bool ntipo_mov,float nmagnitud,std::string nunidad_med);
    void getMovimientos(Movimientos *self);
>>>>>>> 0711070 (entrega2)
struct Analisis{

    char tipo_analisis;
    std::string objeto;
    std::string comentario;
};

<<<<<<< HEAD
Analisis analisis(char ntipo_analisis,std::string nobjeto,std::string comentario);
void getAnalisis(Analisis *self);
=======
 Analisis analisis(char ntipo_analisis,std::string nobjeto,std::string comentario);
    void getAnalisis(Analisis *self);
>>>>>>> 0711070 (entrega2)

struct Elemento{

    std::string tipo_comp;
    float tam;
    std::string unidad_med;
    float coordx;
    float coordy;

};

Elemento elemento(std::string nTipo_comp,float tam,std::string unidad_med,float ncoordx, float ncoordy );
<<<<<<< HEAD
void getElemento(Elemento *self);
=======
    void getElemento(Elemento *self);
>>>>>>> 0711070 (entrega2)
