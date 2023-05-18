#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <map>
#include <functional>
#include <math.h>
#include "funcionalidades.h"
#include "struct.h"
#include <list>
#include <vector>
#include "conversionUnidades.h"
#include "kdTree.h"

//DEFINICION DE VALORES PARA CONVERSION DE UNIDADES
#define MAX_LENGHT 100
#define UNIDAD_MEDIDA "mt"
#define UNIDAD_MEDIDA_AREA "mt^2"
#define UNIDAD_MEDIDA_GIRO "Radianes"
//-----------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------------------//
std::string *tokenizacion(std::string comand);
int main(){

    bool running = true;
    std::list<Movimientos> listaDeMovimientos;
    std::list<Analisis> listaDeAnalisis;
    std::list<Elemento> listaDeElementos;
    Curiosity curiosity;
    while(running){
//TOKENIZACION, SEPARACION DEL COMANDO POR ESPACIOS
        std::string comand;
        printf("$");
        getline(std::cin,comand);
        char comando[MAX_LENGHT];
        char* token;
        strcpy(comando,comand.substr(0,MAX_LENGHT-1).c_str());
        token = strtok(comando," ");
        std::string last; //ULTIMO COMANDO CADENA
        std::string userInput[MAX_LENGHT];
        int argc = 0;
        while(token != NULL) {
            argc++;
            userInput[argc] = token;
            last = token; //GUARDA ULTIMO COMANDO CADENA
            token = strtok(NULL," ");
        }
        argc++;
        userInput[argc] = last; //AGREGAR LAST A ARRAY DE USER INPUT
        if((argc-1) > 6){
            printf("opcion no valida\n");
            return 0;
        }

  bool running = true;
std::list<Movimientos> listaDeMovimientos;
std::list<Analisis> listaDeAnalisis;
std::list<Elemento> listaDeElementos;
kdTree<2> KDTree;
Curiosity curiosity;
  while(running){
//TOKENIZACION, SEPARACION DEL COMANDO POR ESPACIOS
    std::string comand;
    printf("$");
    getline(std::cin,comand);
    char comando[MAX_LENGHT];
    char* token;
    strcpy(comando,comand.substr(0,MAX_LENGHT-1).c_str());
    token = strtok(comando," ");
    std::string last; //ULTIMO COMANDO CADENA
    std::string userInput[MAX_LENGHT];
    int argc = 0;
    while(token != NULL) {
        argc++;
        userInput[argc] = token;
        last = token; //GUARDA ULTIMO COMANDO CADENA
        token = strtok(NULL," ");
    }
    argc++;
    userInput[argc] = last; //AGREGAR LAST A ARRAY DE USER INPUT
    if((argc-1) > 6){
        printf("opcion no valida\n");
        return 0;
    }

//-----------------------------------------------------------------------------------------------//
//DE ESTE PROCESO SALE LAS VARIABLES ARGC, Y USERINPIT[], USERINPUT ES UNA VARIABLE DE STRINGS QUE REPRESENTA LOS ARGUMENTOS PUESTOS POR EL USUARIO, ARGC-1 REPRESENTARA EL NUMERO DE ARGUMENTOS YA QUE EL ARRAY DE ARGUMENTOS EMPEZARA EN USERINPUT[1]
//-----------------------------------------------------------------------------------------------//
// ARRAY DE USERINPUT EMPIEZA EN 1, NOMBRE DE FUNCION EMPIEZA EN 1
//-----------------------------------------------------------------------------------------------//
//MAPA QUE RELACIONA UN STRING CON EL NOMBRE DE LA FUNCION CON UNA FUNCION VOID QUE HARA EL LLAMADO A LA FUNCION A LA QUE SE LE LLEGA EL NOMBRE
//-----------------------------------------------------------------------------------------------//
//PARA AGREGAR UNA FUNCION SE HARA func[nombreDeFuncion] = [lambdaDeExpresion](){Llamado a la funcion} donde lambda de expresion es el numero de argumentos para validar que sea un comando valido y el array userinput puesto por el usuario

        //-----------------------------------------------------------------------------------------------//


        std::map<std::string, std::function<void()>> func;
        func["cargar_elementos"] = [&argc,&userInput,&listaDeElementos](){
            //cargar_elementos userInput[1], nombre_archivo userInput[2]

            if((argc-1) > 2){
                printf("Comando invalido\n");
                help();
            }else{
                printf("Cargando elemento\n");
                //LLamado a funcion
                cargar_elementos(userInput[2],&listaDeElementos);
            }


            for(Elemento& a : listaDeElementos){
                std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_comp<<" "<<a.tam<<" "<<a.unidad_med<<" "<<a.coordx<<" "<<a.coordy<<std::endl;
            };
        };
        func["cargar_comando"] = [&argc,&userInput,&listaDeAnalisis,&listaDeMovimientos](){
            //cargar_comandos userInput[1], nombre_archivo userInput[2]
            if((argc-1) != 2){
                printf("Comando invalido\n");
            }else{
                printf("Cargando comando\n");
                //LLamado a funcion
                cargar_comandos(userInput[2],&listaDeAnalisis,&listaDeMovimientos);
            };

            for(Movimientos& a : listaDeMovimientos){
                std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_mov<<" "<<a.magnitud<<" "<<a.unidad_med<<std::endl;
            }

            for(Analisis& a : listaDeAnalisis){
                std::cout<<"Se ha seleccionado los analisis\n"<<" "<<a.tipo_analisis<<" "<<a.objeto<<" "<<a.comentario<<std::endl;
            }
        };
        func["guardar"] = [&argc,&userInput,&listaDeElementos,&listaDeAnalisis,&listaDeMovimientos](){
            if((argc-1) != 3){
                //guardar userInput[1], tipo_archivo userInput[2], nombre_archivo userInput[3]
                printf("Comando invalido\n");
            }else{
                printf("guardando\n");
                guardar(userInput[2],userInput[3],&listaDeElementos,&listaDeAnalisis,&listaDeMovimientos);
                //LLamado a funcion
            }


        };
        func["simular_comando"] = [&argc,&userInput,&listaDeMovimientos,&listaDeElementos,&curiosity](){
            //simular_comandos userInput[1], coordX userInput[2], coordY userInput[3]
            if((argc-1) != 3){
                printf("Comando invalido\n");
                help();
            }else{
                printf("Simulando\n");
                simular_comandos(userInput[2],userInput[3],&listaDeMovimientos,&listaDeElementos,&curiosity);

                //LLamado a funcion
            }
        };
        func["agregar_analisis"] = [&argc,&userInput,&listaDeAnalisis](){
            //agregar_analisis userInput[1], tipo_analisis userInput[2], objeto userInput[3], comentario userInput[4]
            if((argc-1) != 4){
                printf("Comando invalido\n");
            }else{
                printf("Agregando\n");
                agregar_analisis(userInput[2],userInput[3],userInput[4],&listaDeAnalisis);
                //LLamado a funcion

                for(Analisis& a : listaDeAnalisis){
                    std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_analisis<<" "<<a.objeto<<" "<<a.comentario<<std::endl;
                }

            }
        };
        func["agregar_movimiento"] = [&argc,&userInput,&listaDeMovimientos](){
//agregar_analisis userInput[1], tipo_movuserInput[2], magnitud userInput[3], unidaddeMedida userInput[4]
            for (auto& c: userInput[2]){
                c= std::toupper(c);
            }
            std::string unidad_med;
            float nMagnitud;
            if(userInput[2] == "GIRAR"){
                nMagnitud = conversionRadianes(userInput[4],userInput[3]);
                unidad_med = UNIDAD_MEDIDA_GIRO;
            }else{
                nMagnitud = conversionUnidades(userInput[4],userInput[3]);
                unidad_med = UNIDAD_MEDIDA;
            }
            //SI LA CADENA PUESTA POR EL USUARIO NO ES VALIDA LA FUNCION CONVERSION RETORNARA -1 POR ELLO SE HACE UNA VALIDACION PRIMERO

            std::string magnitud = std::to_string(nMagnitud);
            if((argc-1) != 4){
                printf("Comando invalido\n");
            }else{
                printf("Agregando\n");
                agregar_movimiento(userInput[2],magnitud,unidad_med,&listaDeMovimientos);

                for(Movimientos& a : listaDeMovimientos){
                    std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_mov<<" "<<a.magnitud<<" "<<a.unidad_med<<std::endl;
                }
                //LLamado a funcion
            }

        };
        func["agregar_elemento"] = [&argc,&userInput,&listaDeElementos](){
//agregar_elemento userInput[1], tipo_comp userInput[2], tamaño userInput[3], unidad_med[4], coordX[5], coordY[6]

            float nMagnitud = conversionUnidadesCuadradas(userInput[4],userInput[3]);
            //SI LA CADENA PUESTA POR EL USUARIO NO ES VALIDA LA FUNCION CONVERSION RETORNARA -1 POR ELLO SE HACE UNA VALIDACION PRIMERO||
            if(nMagnitud < 0){
                printf("Comando Invalido\n");
            }else{
                //ENCONTRAR AREA DEL TAMAÑO
                std::string magnitud = std::to_string(nMagnitud);
                if((argc-1) != 6){
                    printf("Comando invalido|| afdref||\n");
                }else{
                    printf("Agregando\n");
                    //LLamado a funcion
                    std::cout<<listaDeElementos.size();
                    agregar_elemento(userInput[2],magnitud,UNIDAD_MEDIDA_AREA,userInput[5],userInput[6],&listaDeElementos);
                    std::cout<<listaDeElementos.size();

                    for(Elemento& a : listaDeElementos){
                        std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_comp<<" "<<a.tam<<" "<<a.unidad_med<<" "<<a.coordx<<" "<<a.coordy<<std::endl;
                    }

                }
            }

        };
        func["help"] = [](){

            help();
            //Llamado a funcion
        };
        func["salir"] = [](){

            exit(0);
        };
//-----------------------------------------------------------------------------------------------//
//DADO EL MAPA, LLAMAMOS A LA FUNCION CON EL NOMBRE QUE EL USUARIO PONDRA EN EL PRIMER ARGUMENTO
//-----------------------------------------------------------------------------------------------//
        try {
            func[userInput[1]]();
        }
        catch(const std::bad_function_call& e){
            std::cout << "Error: " << e.what() << "\n";
            std::cout << "Comando Invalido.\n";
        }
    }

    return 0;
}

  //-----------------------------------------------------------------------------------------------//

  
    std::map<std::string, std::function<void()>> func;
    func["cargar_elementos"] = [&argc,&userInput,&listaDeElementos](){
        //cargar_elementos userInput[1], nombre_archivo userInput[2]
         
        if((argc-1) > 2){
            printf("Comando invalido\n");
        }else{
            printf("Cargando elemento\n");
            //LLamado a funcion
            cargar_elementos(userInput[2],&listaDeElementos);
        } 

                
    for(Elemento& a : listaDeElementos){
            std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_comp<<" "<<a.tam<<" "<<a.unidad_med<<" "<<a.coordx<<" "<<a.coordy<<std::endl;
          };
    };
    func["cargar_comando"] = [&argc,&userInput,&listaDeAnalisis,&listaDeMovimientos](){
        //cargar_comandos userInput[1], nombre_archivo userInput[2]
        if((argc-1) != 2){
            printf("Comando invalido\n");
        }else{
            printf("Cargando comando\n");
            //LLamado a funcion
            cargar_comandos(userInput[2],&listaDeAnalisis,&listaDeMovimientos); 
        };

                for(Movimientos& a : listaDeMovimientos){
            std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_mov<<" "<<a.magnitud<<" "<<a.unidad_med<<std::endl;
          }

        for(Analisis& a : listaDeAnalisis){
            std::cout<<"Se ha seleccionado los analisis\n"<<" "<<a.tipo_analisis<<" "<<a.objeto<<" "<<a.comentario<<std::endl;
          }
    };
    func["guardar"] = [&argc,&userInput,&listaDeElementos,&listaDeAnalisis,&listaDeMovimientos](){
        if((argc-1) != 3){
            //guardar userInput[1], tipo_archivo userInput[2], nombre_archivo userInput[3]
            printf("Comando invalido\n");
        }else{
            printf("guardando\n");
            guardar(userInput[2],userInput[3],&listaDeElementos,&listaDeAnalisis,&listaDeMovimientos);
            //LLamado a funcion
        }


    };
    func["simular_comando"] = [&argc,&userInput,&listaDeMovimientos,&listaDeElementos,&curiosity](){
        //simular_comandos userInput[1], coordX userInput[2], coordY userInput[3]
      if((argc-1) != 3){
            printf("Comando invalido\n");
        }else{
            printf("Simulando\n");
            simular_comandos(userInput[2],userInput[3],&listaDeMovimientos,&listaDeElementos,&curiosity);

            //LLamado a funcion
        }
    };
    func["agregar_analisis"] = [&argc,&userInput,&listaDeAnalisis](){
        //agregar_analisis userInput[1], tipo_analisis userInput[2], objeto userInput[3], comentario userInput[4]
        if((argc-1) != 4){
            printf("Comando invalido\n");
        }else{
            printf("Agregando\n");
            agregar_analisis(userInput[2],userInput[3],userInput[4],&listaDeAnalisis);
            //LLamado a funcion

          for(Analisis& a : listaDeAnalisis){
            std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_analisis<<" "<<a.objeto<<" "<<a.comentario<<std::endl;
          }

        }
    };
    func["agregar_movimiento"] = [&argc,&userInput,&listaDeMovimientos](){
//agregar_analisis userInput[1], tipo_movuserInput[2], magnitud userInput[3], unidaddeMedida userInput[4]
       for (auto& c: userInput[2]){
        c= std::toupper(c);
    }
      std::string unidad_med;
      float nMagnitud;
      if(userInput[2] == "GIRAR"){
          nMagnitud = conversionRadianes(userInput[4],userInput[3]);
          unidad_med = UNIDAD_MEDIDA_GIRO;
        }else{
        nMagnitud = conversionUnidades(userInput[4],userInput[3]);
         unidad_med = UNIDAD_MEDIDA;
        }
       //SI LA CADENA PUESTA POR EL USUARIO NO ES VALIDA LA FUNCION CONVERSION RETORNARA -1 POR ELLO SE HACE UNA VALIDACION PRIMERO
      if(nMagnitud < 0){
           printf("Comando Invalido\n");
        }else{
        std::string magnitud = std::to_string(nMagnitud);
        if((argc-1) != 4){
            printf("Comando invalido\n");
        }else{
            printf("Agregando\n");
            agregar_movimiento(userInput[2],magnitud,unidad_med,&listaDeMovimientos);

          for(Movimientos& a : listaDeMovimientos){
            std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_mov<<" "<<a.magnitud<<" "<<a.unidad_med<<std::endl;
          }
    //LLamado a funcion
        }
      }
    };
    func["agregar_elemento"] = [&argc,&userInput,&listaDeElementos](){
//agregar_elemento userInput[1], tipo_comp userInput[2], tamaño userInput[3], unidad_med[4], coordX[5], coordY[6]

        float nMagnitud = conversionUnidadesCuadradas(userInput[4],userInput[3]);
        //SI LA CADENA PUESTA POR EL USUARIO NO ES VALIDA LA FUNCION CONVERSION RETORNARA -1 POR ELLO SE HACE UNA VALIDACION PRIMERO||
        if(nMagnitud < 0){
           printf("Comando Invalido\n");
        }else{
        //ENCONTRAR AREA DEL TAMAÑO
        std::string magnitud = std::to_string(nMagnitud);
        if((argc-1) != 6){
            printf("Comando invalido|| afdref||\n");
          help();
        }else{
            printf("Agregando\n");
            //LLamado a funcion
            std::cout<<listaDeElementos.size();
          agregar_elemento(userInput[2],magnitud,UNIDAD_MEDIDA_AREA,userInput[5],userInput[6],&listaDeElementos);  
          std::cout<<listaDeElementos.size();

          for(Elemento& a : listaDeElementos){
            std::cout<<"Se ha seleccionado los movimientos\n"<<" "<<a.tipo_comp<<" "<<a.tam<<" "<<a.unidad_med<<" "<<a.coordx<<" "<<a.coordy<<std::endl;
          }

        }
        }
      
    };

    func["ubicar_elementos"] = [&argc, &KDTree, &listaDeElementos](){

      if((argc-1) != 1){
            printf("Comando invalido\n");
        help();
        }else{
            printf("Agregando\n");

        ubicar_elementos(&listaDeElementos, &KDTree);

        KDTree.preorder();
        //Llamado a funcion
      }

    };

    func["en_cuadrante"] = [&argc,&userInput, &KDTree,&listaDeElementos](){
      
      if((argc-1) != 5){
            printf("Comando invalido\n");
        help();
        }else{
            printf("Agregando\n");
      
        try{
         ubicar_elementos(&listaDeElementos, &KDTree);
         
            int minNCoordX = std::atoi(userInput[2].c_str());
            int minNCoordY = std::atoi(userInput[3].c_str());
            int maxNCoordX = std::atoi(userInput[4].c_str());
            int maxNCoordY = std::atoi(userInput[5].c_str());

            if (minNCoordX > maxNCoordX || minNCoordY > maxNCoordY) {
                printf("Comando invalido\n");
            }
            else {
                

                int minPoint[2];
                int maxPoint[2];
                minPoint[0] = minNCoordX;
                minPoint[1] = minNCoordY;
                maxPoint[0] = maxNCoordX;
                maxPoint[1] = maxNCoordY;

          
          KDTree.en_cuadrante(minPoint, maxPoint);
          }
        }

        //Llamado a funcion
      catch (const std::invalid_argument& e) {

      printf("Comando Invalido");
      return;
    }
      
    }
    };
    func["help"] = [&argc](){

      if((argc-1) != 1){
            printf("Comando invalido\n");
        }else{
            help();
        //Llamado a funcion
      }
        //Llamado a funcion
    };
    func["salir"] = [](){

        exit(0);
    };
//-----------------------------------------------------------------------------------------------//
//DADO EL MAPA, LLAMAMOS A LA FUNCION CON EL NOMBRE QUE EL USUARIO PONDRA EN EL PRIMER ARGUMENTO
//-----------------------------------------------------------------------------------------------//
    try {
        func[userInput[1]]();
    }
    catch(const std::bad_function_call& e){
        std::cout << "Error: " << e.what() << "\n";
        std::cout << "Comando Invalido.\n";
    }
  }  

    return 0;
}



