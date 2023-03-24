#include "struct.h"
#include <string>
Curiosity Makecuriosity(float ncoordX, float ncoordY) {

    Curiosity initialized = {ncoordX, ncoordY};

    return initialized;
}

float getCoordY(Curiosity *self) {

    return self->coordX;
}

float getcoordX(Curiosity *self) {

    return self->coordy;
}

Movimientos movimiento(bool ntipo_mov, float nmagnitud, std::string nunidad_med) {

    Movimientos initialized = {ntipo_mov,nmagnitud,nunidad_med};

    return initialized;
}

Analisis analisis(char ntipo_analisis, std::string nobjeto, std::string ncomentario) {

    Analisis initialized = {ntipo_analisis,nobjeto,ncomentario};

    return initialized;
}

Elemento elemento(std::string nTipo_comp, float ntam, std::string nunidad_med, float ncoordx, float ncoordy) {

    Elemento initialized = {nTipo_comp,ntam,nunidad_med,ncoordx,ncoordy};

    return initialized;
}