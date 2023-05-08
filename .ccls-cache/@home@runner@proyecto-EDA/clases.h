#pragma once
#include <string>
struct info_separada{
    std::string tipo_comando;
    std::string nombre_accion;
    std::string argumento1;
    std::string argumento2;
};

struct Curiosity{

    float coordX;
    float coordy;

    Curiosity Makecuriosity(float ncoordX,float ncoordY);
    float getcoordX(Curiosity *self);
    float getCoordY(Curiosity *self);


};

struct Movimientos{

    bool tipo_mov; //0 para movimiento, 1 para giro
    float magnitud;
    std::string  unidad_med; //unidad de medida
    int posicion;

    Movimientos movimiento(bool ntipo_mov,float nmagnitud,std::string nunidad_med,int nposicion);

    void getMovimientos(Movimientos *self);

};

struct Analisis{

    char tipo_analisis;
    std::string objeto;
    std::string comentario;
    int posicion;

    Analisis analisis(char ntipo_analisis,std::string nobjeto,std::string comentario,int posicion);

    void getAnalisis(Analisis *self);

};


struct Elemento{

    std::string tipo_comp;
    int tam;
    std::string unidad_med;
    int coordx;
    int coordy;

    Elemento elemento(std::string nTipo_comp,int tam,std::string unidad_med,int ncoordx, int ncoordy );

    void getElemento(Elemento *self);

};