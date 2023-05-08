#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include "funcionalidades.h"
#include "simulacion_de_movimiento.h"
#include <vector>
#include <sstream>
#include <cstring>
std::string addTxtExtension(std::string filename);

void cargar_elementos(std::string nombre_archivo,std::list<Elemento> *ListaElemento){

std::string nNombre_archivo = addTxtExtension(nombre_archivo);
  
    std::ifstream archivo(nNombre_archivo);
    std::string linea;

  if(archivo.is_open()){
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        Elemento elemento;
        std::getline(ss, elemento.tipo_comp, '|');
        std::string nTam;
        std::getline(ss,nTam,'|');
        elemento.tam = std::stof(nTam);
        std::getline(ss, elemento.unidad_med, '|');
        std::string nCoordx;
        std::getline(ss,nCoordx,'|');
        elemento.coordx = std::stof(nCoordx);
        std::string nCoordy;
        std::getline(ss,nCoordy,'|');
        elemento.coordy = std::stof(nCoordy);
        ListaElemento->push_back(elemento);
    }
  }
  else{

    printf("No se pudo leer el archivo");
  }
}



void cargar_comandos(std::string nombre_archivo,std::list<Analisis> *listaAnalisis,std::list<Movimientos> *listaMovimientos){
    //1. VER SI SE TRATA DE COMANDO DE ANALISIS Y COMANDO DE MOVIMIENTO
    //2. GUARDAR EN LISTA CORRESPONDIENTE 
    std::string nNombre_archivo = addTxtExtension(nombre_archivo);
    
    std::ifstream archivo(nNombre_archivo);
    std::string linea;
     
    if(archivo.is_open()){
     while(std::getline(archivo,linea)){
        std::stringstream ss(linea);
       std::string primerArgumento;
       std::getline(ss,primerArgumento,'|');
       if(primerArgumento == "0" || primerArgumento == "1"){
         printf("Movimiento\n");
         Movimientos mov;
         bool nTam;
         if(primerArgumento == "0"){
           nTam = false;
         }else{
           nTam = true;
         }
         mov.tipo_mov = nTam;
         std::string nMag;
         std::getline(ss,nMag,'|');
         mov.magnitud = std::stof(nMag);
         std::getline(ss,mov.unidad_med,'|');
         listaMovimientos->push_back(mov);
       }
         else if(primerArgumento == "f" || primerArgumento == "p" || primerArgumento == "c"){
           printf("Analisis\n");
           Analisis a;
           char nTipo;
           nTipo = primerArgumento[0];
           a.tipo_analisis = nTipo;
           std::getline(ss,a.objeto,'|');

          std::stringstream nComentario;
        while (std::getline(ss, linea, '|')) {
            nComentario << linea;
        }
           
           a.comentario = nComentario.str();
           listaAnalisis->push_back(a);
         }
     else{
       printf("Comando no valido");
     }
    }
}
}
void guardar(std::string tipo_archivo,std::string nombre_archivo,std::list<Elemento> *ListaElemento,std::list<Analisis> *listaAnalisis,std::list<Movimientos> *listaMovimientos){


  std::string nNombre_archivo = addTxtExtension(nombre_archivo);
  //SI EXISTE, SE DEBERA SOBREESCRIBIR EL ARCHIVO CON LOS ELEMENTOS PUESTOS DEL USUARIO
  
  
  for (auto& c: tipo_archivo){
        c= std::toupper(c);
    }
  if(tipo_archivo == "COMANDO"){
        //GUARDAR COMANDOS
    std::ofstream archivo(nNombre_archivo);
    if(archivo.is_open()){
    for(Analisis& a : *listaAnalisis){

    archivo << a.tipo_analisis << "|" << a.objeto<< "|" << a.comentario << std::endl;
    } 
      for(Movimientos& a: *listaMovimientos){
    archivo << a.tipo_mov << "|" << a.magnitud << "|" << a.unidad_med << std::endl;
   }
  archivo.close();
    }else{
      archivo.open(nNombre_archivo,std::fstream::out);
      for(Analisis& a : *listaAnalisis){
    archivo << a.tipo_analisis << "|" << a.objeto<< "|" << a.comentario << std::endl;
    } 
      for(Movimientos& a: *listaMovimientos){
    archivo << a.tipo_mov << "|" << a.magnitud << "|" << a.unidad_med << std::endl;
   }
      archivo.close();
    }
  
        //AQUI SE GUARDARA LOS COMANDOS PUESTOS POR EL USUARIO PUESTOS POR EL USUARIO, SE DEBERA VER ENTE listaAnalisis y listaMovimientos
    //SI EXISTE SOBREESCRIBIR
    printf("guardando comandos");
    }else if(tipo_archivo == "ELEMENTO"){
          //GUARDAR ELEMENTOS
          //AQUI SE GUARDARA LOS ELEMENTOS PUESTOS POR EL USUARIO, SE DEBERA PONER EN listaElemento
    //SI EXISTE SOBREESCRIBIR
    std::ofstream archivo(nNombre_archivo);
    if(archivo.is_open()){
    for(Elemento& a : *ListaElemento){

    archivo << a.tipo_comp << "|" << a.tam << "|" << a.unidad_med << "|" << a.coordx << "|"<<a.coordy<<std::endl;
    } 
  archivo.close();
    }else{
      archivo.open(nNombre_archivo,std::fstream::out);
       for(Elemento& a : *ListaElemento){

    archivo << a.tipo_comp << "|" << a.tam << "|" << a.unidad_med << "|" << a.coordx << "|"<<a.coordy<<std::endl;
    } 
  archivo.close();
    printf("guardando elementos");
    }}else{
        printf("Comando Invalido");
    }
}
void simular_comandos(std::string coordX,std::string coordY,std::list<Movimientos> *listaMovimientos,std::list<Elemento> *ListaElemento,Curiosity *curiosity){

    
  printf("...............\n");
  try{
  //CONVERTIR DATOS STRING AL TIPO DE DATO QUE SE NECESITA
    float NcoordX = std::stof(coordX.c_str());
    float NcoordY = std::stof(coordY.c_str());

 curiosity->coordX = NcoordX;
 curiosity->coordy = NcoordY;

  printf("a");
 /* 

 
 bool simularCoolicionConObjetos(float tamaño, float coordX, float coordY, float posicionActualX, float posicionActualY);

float CoordenadasEnY(float magnitud,float radianes);

float CoordenadasEnX(float magnitud,float radianes);
SE ENCUENTRA EL VALOR DE LAS COORDENADAS X Y Y PARA SIMULAR EL MOVIMIENTO DEL CURIOSITY
SI NO SE HA GIRADO ALGUNA VEZ, RADIANES = O
AL CAMBIAR A GIRO, TOMAR MAGNITUD AVANZAR DEL GIRO SIGUIENTE
AVANZAR AVANZAR AVANZAR GIRO AVANZAR
SI GIRA DE MANERA CONSECUTIVA TOMAR EL ULTIMO GIRO Y AVANZAR LA MAGNITUD QUE DIGA EL SIGUIENTE AVANZAR
AVANZAR AVANZAR AVANZAR GIRO GIRO AVANZAR
SI EL ULTIMO ES UN GIRO NO HACER NADA
AVANZAR AVANZAR GIRAR GIRAR
Curiosity simulacionMovimiento(float magnitudX,float radianesX, float magnitudY, float radianesY, Curiosity *self);*/
int cont = 0;
float ultimoGiro ;
float nRadianes=0.0f; //INICIALIZAR RADIANES, RADIANES ES UN VALOR GLOBAL
     

    auto it = listaMovimientos->begin();
    while (it != listaMovimientos->end()) { 
      if(cont == 0){

        if(it->tipo_mov == true && std::next(it)->tipo_mov == false){
          float nMagnitud = it->magnitud;
         coolicionDelCuriosity(nMagnitud, nRadianes, curiosity, ListaElemento);
          simulacionMovimiento(nMagnitud, nRadianes, curiosity);
          
        }
      }
    cont++;
        if(it->tipo_mov == false) {
            if (it->tipo_mov == false && std::next(it) != listaMovimientos->end() && std::next(it)->tipo_mov == true) {
                //el primer caso es si es un girro y luego avanza, se avanzara con el giro anterior
                nRadianes = it->magnitud;
                float nMagnitud = std::next(it)->magnitud;
                coolicionDelCuriosity(nMagnitud, nRadianes, curiosity, ListaElemento);
                simulacionMovimiento(nMagnitud, nRadianes, curiosity);
                std::cout<<nRadianes;
                std::cout<<nMagnitud;
                it = (std::next(it, 2));
            } else {
                it++;
            }
        }else{
        if (std::next(it) != listaMovimientos->end() && std::next(it)->tipo_mov == true) {
            float nMagnitud = it->magnitud;
            float ultimoGiro = 0.0f;
            //SI NO SE GIRA SE MANTENDRA EL GIRO, POR ELLO nRadianes no es una variable global
            coolicionDelCuriosity(nMagnitud, nRadianes, curiosity, ListaElemento);
            simulacionMovimiento(nMagnitud, nRadianes, curiosity);
            std::cout<<nRadianes;
                std::cout<<nMagnitud;
            bool encontroNuevoGiro = false;
            auto end_it = it;
            while (std::next(end_it) != listaMovimientos->end() && std::next(end_it)->tipo_mov == true) {
                end_it = std::next(end_it);
                if (end_it->tipo_mov == false) {//END_IT IRA HASTA EL ULTIMO GIRO
                    ultimoGiro = end_it->magnitud;
                    encontroNuevoGiro = true;
                }
            }
            if (encontroNuevoGiro) {
                std::cout << "se girara " << ultimoGiro << std::endl;
            }
            it = std::next(end_it);
        }else if(std::next(it) == listaMovimientos->end()){
          float nMagnitud = it->magnitud;
                    coolicionDelCuriosity(nMagnitud, nRadianes, curiosity, ListaElemento);
            simulacionMovimiento(nMagnitud, nRadianes, curiosity);
          break;
        }else{
            it++;
        }
        }
        
    }
 }catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return;
}
  
 

        }
void agregar_analisis(std::string tipo_analisis,std::string objeto,std::string comentario,std::list<Analisis> *listaAnalisis){
    std::cout<<tipo_analisis<<objeto<<comentario;
    char ntipo_a;
    bool comandoValido=true;
    for (auto& c: tipo_analisis){
        c= std::toupper(c);
    }//CONVERTIR A MAYUSCULAS PARA HACER VALIDACION
    if(tipo_analisis == "FOTOGRAFIAR"){
        ntipo_a = 'f';
      Analisis ed = analisis(ntipo_a, objeto, comentario);
  listaAnalisis->push_back(ed);
    }else if(tipo_analisis == "COMPOSICION"){
        ntipo_a = 'c';
      Analisis ed = analisis(ntipo_a, objeto, comentario);
  listaAnalisis->push_back(ed);
    }else if(tipo_analisis == "PERFORAR"){
        ntipo_a = 'p';
      Analisis ed = analisis(ntipo_a, objeto, comentario);
  listaAnalisis->push_back(ed);
    }else{
        comandoValido = false;
    }

    if(comandoValido == false){

        printf("Por favor vuelva a escribir el comando\n");
    }

}

void agregar_movimiento(std::string tipo_mov,std::string magnitud,std::string unidad_med,std::list<Movimientos> *listaMovimientos){

    try {
    float nMagnitud = std::stof(magnitud.c_str());
 
    //CONVERTIR DATOS STRING AL TIPO DE DATO QUE SE NECESITA
    for (auto& c: tipo_mov){
        c= std::toupper(c);
    } //CONVERTIR A MAYUSCULAS PARA HACER VALIDACION
    bool ntipo_mov = true;
    if(tipo_mov == "AVANZAR"){
        ntipo_mov = true;
      Movimientos mov = movimiento(ntipo_mov, nMagnitud, unidad_med);
  listaMovimientos -> push_back(mov);
  
    }else if(tipo_mov == "GIRAR"){
        ntipo_mov = false;
      Movimientos mov = movimiento(ntipo_mov, nMagnitud, unidad_med);
  listaMovimientos -> push_back(mov);
    }else{
        printf("Por favor vuelva a digitar el comando\n");
    };
    }
  catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return;
}

}

void agregar_elemento(std::string tipo_comp,std::string tamaño,std::string unidad_med,std::string coordX,std::string coordY, std::list<Elemento> *listaElemento){

    bool comandoValido = true;
    for (auto& c: tipo_comp){
        c= std::toupper(c);
    }//CONVERTIR A MAYUSCULAS PARA HACER VALIDACION
    //CONVERTIT DATOS STRING AL TIPO DE DATO QUE SE NECESITA
    try{
    float nTamaño = std::stof(tamaño.c_str());
    float nCoordX = std::stof(coordX.c_str());
    float nCoordY = std::stof(coordY.c_str());

    if(tipo_comp == "ROCA"){
        tipo_comp = "Roca";
       Elemento el = elemento(tipo_comp, nTamaño, unidad_med, nCoordX, nCoordY);
  listaElemento->push_back(el);
    }else if(tipo_comp == "CRATER"){
        tipo_comp = "Crater";
      Elemento el = elemento(tipo_comp, nTamaño, unidad_med, nCoordX, nCoordY);
  listaElemento->push_back(el);
    }else if(tipo_comp == "MONTICULO"){
        tipo_comp = "Monticulo";
       Elemento el = elemento(tipo_comp, nTamaño, unidad_med, nCoordX, nCoordY);
  listaElemento->push_back(el);
    }else if(tipo_comp == "DUNA"){
        tipo_comp = "Duna";
       Elemento el = elemento(tipo_comp, nTamaño, unidad_med, nCoordX, nCoordY);
  listaElemento->push_back(el);

    }else{
        comandoValido = false;
    }
    if(comandoValido == false){
        printf("por favor vuelva a digitar el comando\n");
    }
}catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return;
}
}

void help(){

std::ifstream file("help.txt");

if(!file)
{
std::cerr<<"No se encontro el archivo"<<std::endl;
  
}

  std::string linea;

  while(std::getline(file,linea)){

    std::cout<<linea<<std::endl;
  }
  
  return;
} 

std::string addTxtExtension(std::string filename) {
    if (filename.length() < 4 || filename.substr(filename.length()-4) != ".txt") {
        filename += ".txt";
    }
    return filename;
}

void ubicar_elementos(std::list<Elemento> *ListaElemento,kdTree<2> *kdtree){
  int coords[2];
for (Elemento ele: *ListaElemento){
  coords[0]=ele.coordx;
  coords[1]=ele.coordy;
  kdtree->insert(coords);
}
}