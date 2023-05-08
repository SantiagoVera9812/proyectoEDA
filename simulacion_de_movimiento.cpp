#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "simulacion_de_movimiento.h"
#include "struct.h"

bool simularCoolicionConObjetos(float tamaño, float coordX, float coordY, float posicionActualX, float posicionActualY){

<<<<<<< HEAD
    float mitadLongitud = sqrt(tamaño)/2;

    float PuntoAlCentro = sqrt((pow((posicionActualY-coordY),2))+(pow((posicionActualX-coordX),2)));

    if(PuntoAlCentro >= mitadLongitud){
        return false;
    }else{
        return true;
    }
}

float CoordenadasEnY(float magnitud,float radianes){
    return sin(radianes)*magnitud;
}

float CoordenadasEnX(float magnitud,float radianes){
    return cos(radianes)*magnitud;
}

Curiosity simulacionMovimiento(float magnitud,float radianes, Curiosity *self){

    self->coordX = self->coordX + CoordenadasEnX(magnitud,radianes);

    self->coordy = self->coordy + CoordenadasEnY(magnitud,radianes);

    std::cout<<"Curiosity esta en " <<self->coordX<<"en la coordenada x\n";
    std::cout<<"Curiosity esta en " <<self->coordy<<"en la coordenada y\n";

    return *self;
=======
float mitadLongitud = sqrt(tamaño)/2;
float PuntoAlCentro = sqrt((pow((posicionActualY-coordY),2))+(pow((posicionActualX-coordX),2)));
if(PuntoAlCentro >= mitadLongitud){
return false;
}else{
return true;
}
}

float CoordenadasEnY(float magnitud,float radianes){
return sin(radianes)*magnitud;
  }

float CoordenadasEnX(float magnitud,float radianes){
return cos(radianes)*magnitud;
  }

Curiosity simulacionMovimiento(float magnitud,float radianes, Curiosity *self){

   self->coordX = self->coordX + CoordenadasEnX(magnitud,radianes);

   self->coordy = self->coordy + CoordenadasEnY(magnitud,radianes);

  std::cout<<"Curiosity esta en " <<self->coordX<<"en la coordenada x\n"<<std::endl;
          std::cout<<"Curiosity esta en " <<self->coordy<<"en la coordenada y\n"<<std::endl;

  return *self;
<<<<<<< HEAD
>>>>>>> 0711070 (entrega2)
=======
=======
    float mitadLongitud = sqrt(tamaño)/2;

    float PuntoAlCentro = sqrt((pow((posicionActualY-coordY),2))+(pow((posicionActualX-coordX),2)));

    if(PuntoAlCentro >= mitadLongitud){
        return false;
    }else{
        return true;
    }
}

float CoordenadasEnY(float magnitud,float radianes){
    return sin(radianes)*magnitud;
}

float CoordenadasEnX(float magnitud,float radianes){
    return cos(radianes)*magnitud;
}

Curiosity simulacionMovimiento(float magnitud,float radianes, Curiosity *self){

    self->coordX = self->coordX + CoordenadasEnX(magnitud,radianes);

    self->coordy = self->coordy + CoordenadasEnY(magnitud,radianes);

    std::cout<<"Curiosity esta en " <<self->coordX<<"en la coordenada x\n";
    std::cout<<"Curiosity esta en " <<self->coordy<<"en la coordenada y\n";

    return *self;
>>>>>>> 9678abb (24_deMarzo)
>>>>>>> 18da1e2 (Coreccion simulacion)
}

void coolicionDelCuriosity(float nMagnitud, float nRadianes,Curiosity *curiosity,std::list<Elemento> *ListaElemento){

<<<<<<< HEAD
    float coordx = CoordenadasEnX(nMagnitud, nRadianes);
    float coordy = CoordenadasEnY(nMagnitud, nRadianes);

    float giro = atan(coordy/coordy);
    for(auto it = ListaElemento->begin();it != ListaElemento->end();it++){

        bool coalicion = simularCoolicionConObjetos(it->tam, it->coordx, it->coordy, coordx, coordy);
        if(coalicion == true){
            printf("Nos hemos chocado");
            exit(0);
        }else{
            std::cout<<"Curiosity esta en " <<curiosity->coordX<<"en la coordenada x";
            std::cout<<"Curiosity esta en " <<curiosity->coordy<<"en la coordenada y";

        }
    };

<<<<<<< HEAD
}
=======
      float coordx = CoordenadasEnX(nMagnitud, nRadianes);
      float coordy = CoordenadasEnY(nMagnitud, nRadianes);

      float giro = atan(coordy/coordy);
      for(auto it = ListaElemento->begin();it != ListaElemento->end();it++){

       bool coalicion = simularCoolicionConObjetos(it->tam, it->coordx, it->coordy, coordx, coordy);
        if(coalicion == true){
           printf("Nos hemos chocado");
          exit(0);
        }else{
          std::cout<<"Curiosity esta en " <<curiosity->coordX<<"en la coordenada x";
          std::cout<<"Curiosity esta en " <<curiosity->coordy<<"en la coordenada y";
          
        }
      };
  
}
>>>>>>> 0711070 (entrega2)
=======
<<<<<<< HEAD
>>>>>>> 9678abb (24_deMarzo)
}
=======
}
>>>>>>> 37fc58b (Coreccion simulacion)
>>>>>>> 18da1e2 (Coreccion simulacion)
