<<<<<<< HEAD
//
// Created by santiagovera on 24/03/23.
//
#include <string>
#include <math.h>
#include "funcionalidades.h"
=======
#include <string>
#include <math.h>
#include "funcionalidades.h"
#include <stdexcept>
>>>>>>> 0711070 (entrega2)
#define MAX_LENGHT 100
#define UNIDAD_MEDIDA "mt"
#define UNIDAD_MEDIDA_AREA "mt^2"
#define factorConversionCM 0.01;
#define factorConversionMM 0.001;
#define factorConversionKM 1000;
#define PI atan(1)*4


float conversionRadianes(std::string unidad_med,std::string valorAConvertir){
<<<<<<< HEAD

    float nValor = std::stof(valorAConvertir.c_str());

    bool comandoValido = true;

    for (auto& c: unidad_med){
        c= std::toupper(c);
    }//CONVERTIR A MAYUSCULAS

    if(unidad_med == "RADIANES"){
        return nValor;
    }else if(unidad_med == "GRADOS"){
        return (nValor*2*PI)/360;
    }else{

        printf("Por favor vuelva a escribir el comando\n");
        help();
    }

=======
   
   try{float nValor = std::stof(valorAConvertir.c_str());

    bool comandoValido = true;

     for (auto& c: unidad_med){
        c= std::toupper(c);
    }//CONVERTIR A MAYUSCULAS

  if(unidad_med == "RADIANES"){
     return nValor;
  }else if(unidad_med == "GRADOS"){
     return (nValor*2*PI)/360;
  }else{

    printf("Por favor vuelva a escribir el comando\n");
    help();
  }}
  catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
    return -1;
      
}
>>>>>>> 0711070 (entrega2)
//-----------------------------------------------------------------------------------------------//
//CONVERSION A METROS, SE PODRA CM,MM Y KM
//-----------------------------------------------------------------------------------------------//
}

float conversionUnidades(std::string unidad_med,std::string valorAConvertir){

<<<<<<< HEAD
    float nValor = std::stof(valorAConvertir.c_str());
=======
   try{ float nValor = std::stof(valorAConvertir.c_str());
>>>>>>> 0711070 (entrega2)
    bool comandoValido = true;
    //CONVERTIR DATOS STRING AL TIPO DE DATO QUE SE NECESITA
    for (auto& c: unidad_med){
        c= std::toupper(c);
    } //CONVERTIR A MAYUSCULAS PARA HACER VALIDACION

    if(unidad_med == "MT"){
        return nValor;
    }else if(unidad_med == "CM"){
        return nValor*factorConversionCM;
    }else if(unidad_med == "MM"){
        return nValor*factorConversionMM;
<<<<<<< HEAD
    }else if(unidad_med == "KM") {
        return nValor*factorConversionKM;
    }else{
        comandoValido = false;
    };
=======
   }else if(unidad_med == "KM") {
        return nValor*factorConversionKM;
    }else{
    comandoValido = false;
};
>>>>>>> 0711070 (entrega2)

    if(comandoValido == false){
        printf("por favor vuelva a escribir el comando\n");
        help();
    }
<<<<<<< HEAD

=======
}
  catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return -1;
}
>>>>>>> 0711070 (entrega2)
}

//-----------------------------------------------------------------------------------------------//
//CONVERSION A METROS CUADRADOS, SE SOBREENTIENDE mt^2 ASI QUE EL USUARIO DIGITARA CM,MM,KM
//-----------------------------------------------------------------------------------------------//
float conversionUnidadesCuadradas(std::string unidad_med,std::string valorAConvertir){
<<<<<<< HEAD

    float nValor = std::stof(valorAConvertir.c_str());

=======
try{
    float nValor = std::stof(valorAConvertir.c_str());
    
>>>>>>> 0711070 (entrega2)
    bool comandoValido = true;
    //CONVERTIR DATOS STRING AL TIPO DE DATO QUE SE NECESITA
    for (auto& c: unidad_med){
        c= std::toupper(c);
    } //CONVERTIR A MAYUSCULAS PARA HACER VALIDACION

<<<<<<< HEAD
    float res;
    if(unidad_med == "MT"){
        return nValor;
    }else if(unidad_med == "CM"){
        float cm = factorConversionCM;
        res=pow(cm,2);
=======
  float res;
    if(unidad_med == "MT"){
        return nValor;
    }else if(unidad_med == "CM"){
      float cm = factorConversionCM;
      res=pow(cm,2);
>>>>>>> 0711070 (entrega2)
        return nValor*res;
    }else if(unidad_med == "MM"){
        float mm = factorConversionMM;
        res = pow(mm,2);
        return nValor*res;
<<<<<<< HEAD
    }else if(unidad_med == "KM") {
        float km = factorConversionKM;
        res = pow(km,2);
        return nValor*res;
    }else{
        comandoValido = false;
    };
=======
   }else if(unidad_med == "KM") {
      float km = factorConversionKM;
      res = pow(km,2);
        return nValor*res;
    }else{
    comandoValido = false;
};
>>>>>>> 0711070 (entrega2)

    if(comandoValido == false){
        printf("Por favor vuelva a escribir el comando\n");
        help();
    }
<<<<<<< HEAD
=======
  }
  catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return -1;
}
>>>>>>> 0711070 (entrega2)

}