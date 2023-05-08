#include <cstring>
#include <string>
#include "funcionalidades.h"
#define MAX_LENGHT 100

std::string* tokenizacion(std::string comand) {
    char comando[MAX_LENGHT];
    char* token;
    strcpy(comando, comand.substr(0, MAX_LENGHT - 1).c_str());
    token = strtok(comando, " ");
    std::string last; // ULTIMO COMANDO CADENA
    std::string* userInput = new std::string[MAX_LENGHT];
    int argc = 0;
    while (token != NULL) {
        argc++;
        userInput[argc] = token;
        last = token; // GUARDA ULTIMO COMANDO CADENA
        token = strtok(NULL, " ");
    }
    argc++;
    userInput[argc] = last; // AGREGAR LAST A ARRAY DE USER INPUT
    if ((argc - 1) > 6) {
        printf("opcion no valida\n");
        help();
    }
    return userInput;
}