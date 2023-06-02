#include <iostream>
#include <list>
#include <math.h>
#include "struct.h"
#include "kdTree.h"
#include "shortestPath.h"
#include <unordered_set>

bool isValidIntArray(int* arr) {
   
    return (arr != nullptr) && (arr[0] != '\0') && (arr[1] != '\0');
}
    // Constructor
Graph::Graph(int n) {
    adjacencyMatrix.resize(n, std::vector<double>(n, std::numeric_limits<double>::infinity()));
}

void Graph::addEdge(const std::pair<double, double>& pointU, const std::pair<double, double>& pointV, double weight) {
    // Find the indices corresponding to the given points
    int u = findIndexForPoint(pointU);
    int v = findIndexForPoint(pointV);

    if (u < 0 || u >= adjacencyMatrix.size() || v < 0 || v >= adjacencyMatrix.size()) {
        // Handle the error, such as printing an error message or throwing an exception
        std::cout << "Invalid indices for adding an edge." << std::endl;
        return; // or throw an exception if appropriate
    }

    // Update the adjacency matrix with the weight
    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
}

int Graph::findIndexForPoint(const std::pair<double, double>& point){
    // Iterate over the pointMap to find the index corresponding to the given point
    auto it = std::find_if(pointMap.begin(), pointMap.end(), [&](const auto& entry) {
        return entry.second == point;
    });

    if (it != pointMap.end()) {
        return it->first;  // Return the index if the point is found
    }

    // If the point is not found, add it to the pointMap and return the new index
    int newIndex = pointMap.size();
    pointMap[newIndex] = point;
    return newIndex;
}


void Graph::printGraph() const {
    for (const auto& row : adjacencyMatrix) {
        for (const auto& weight : row) {
            if (weight == std::numeric_limits<double>::infinity()) {
                std::cout << "XXXXXXX ";
            } else {
                std::cout << weight << " ";
            }
        }
        std::cout << std::endl;
    }
}

int countStructs(const std::list<Elemento>& myList) {
    int count = 0;

    if (!myList.empty()) {
        for (const Elemento& elem : myList) {
            if (typeid(elem) == typeid(Elemento)) {
                count++;
            }
        }
    }

    return count;
}

void getNearestNeighbor(Node<2>* root, std::list<Node<2>*>& listaVecinos, Node<2>*& nearest) {
    if (listaVecinos.empty()) {
        nearest = nullptr;
        return;
    }

    double firstDistance = std::numeric_limits<double>::infinity();
    Node<2>* firstNode = nullptr;

    for (Node<2>* node : listaVecinos) {
        if (node == root) {
            continue;
        }
        if (node->distancia < firstDistance) {
            firstDistance = node->distancia;
            firstNode = node;
        }
    }

    nearest = firstNode;
}


void findNearestNeighborsRecursively(kdTree<2>& KdTree, Node<2>* currentNode, int nVecinos, Graph& graph, std::unordered_set<Node<2>*>& visited, double distanciaInicial,int& index) {
    
    index++;
    // Check if the current node is null or if the desired number of neighbors has been reached
    if (currentNode == nullptr || nVecinos == 0 || visited.count(currentNode) > 0) {
        std::cout<<"Terminado: "<<std::endl;
        return;
    }

    visited.insert(currentNode);
     std::cout << "Estamos en: (" << currentNode->point[0] << ", " << currentNode->point[1] << ")\n";
     std::cout <<"KDTree tiene la raiz: " << KdTree.getRoot()->point[0] << ", " << KdTree.getRoot()->point[1]<<"\n";

   std::list<int*> newLista = KdTree.preorderList();
  
  
   int coords[2];
        kdTree<2> newKdTree;
        newKdTree.setRoot(currentNode);
      
        for (int* i : newLista) {
            coords[0] = i[0];
            coords[1] = i[1];
            newKdTree.insert(coords, index);
            index++;
        }

  std::cout << "Estamos en: (" << currentNode->point[0] << ", " << currentNode->point[1] << ")\n";
     std::cout <<"KDTree tiene la raiz: " << KdTree.getRoot()->point[0] << ", " << KdTree.getRoot()->point[1]<<"\n";

    // Get the coordinates of the current node
    int currentCoords[2];
    currentCoords[0] = currentNode->point[0];
    currentCoords[1] = currentNode->point[1];

    // Find the nearest neighbor for the current node
    int rootCoords[2];
    rootCoords[0] = KdTree.getRoot()->point[0];
    rootCoords[1] = KdTree.getRoot()->point[1];
    KdTree.preorderVisual();
    std::list<Node<2>*> listaVecinos = KdTree.vecinosMasCercanos(currentCoords, nVecinos);
    for (Node<2>* node : listaVecinos) {
        // Access the data of the node or perform any other desired operation
        // For example, print the coordinates of the node's point
        std::cout << "Coordenadas de los vecinos: (" << node->point[0] << ", " << node->point[1] << ")\n";
    }
    double distance;
    Node<2>* nearestNeighbor = nullptr;
    getNearestNeighbor(currentNode, listaVecinos, nearestNeighbor);
    if (nearestNeighbor != nullptr) {
    std::cout << "Coordenadas del vecino mas cercano: (" << nearestNeighbor->point[0] << ", " << nearestNeighbor->point[1] << ")\n";

    // Add the distance as a weighted edge in the graph
    distance = nearestNeighbor->distancia;
    distanciaInicial = distanciaInicial + distance;
    std::cout<<"Distancia: "<<distance<<std::endl;
    std::cout<<"Distancia recorrida: "<<distanciaInicial<<std::endl;

   
    
    
    }
    if (nearestNeighbor != nullptr) {
        // Update the root of the kdTree with the nearestNeighbor
       //std::list<int*> newLista = KdTree.preorderList();
        index++;
        int coords[2];
        newKdTree.setRoot(nearestNeighbor);
        for (int* i : newLista) {
            coords[0] = i[0];
            coords[1] = i[1];
            newKdTree.insert(coords, index);
            index++;
        }
    if (currentNode != nullptr && nearestNeighbor != nullptr) {
      std::pair<int, int> currentPoint = std::make_pair(currentNode->point[0], currentNode->point[1]);
       std::pair<int, int> neighborPoint = std::make_pair(nearestNeighbor->point[0], nearestNeighbor->point[1]);
       graph.addEdge(currentPoint, neighborPoint, distance);
    }
        // Recursively find the nearest neighbors for the nearest neighbor
        findNearestNeighborsRecursively(newKdTree, nearestNeighbor, nVecinos - 1, graph, visited, distanciaInicial, index);
      
        
    }
  
  return;

  
}

void PuntoAOtro(kdTree<2>& KdTree, Node<2>* currentNode, int nVecinos, Graph& graph, std::unordered_set<Node<2>*>& visited, double distanciaInicial,int& index, Node<2>* NodoAParar) {
    
    index++;
    // Check if the current node is null or if the desired number of neighbors has been reached
    if (currentNode == nullptr || nVecinos == 0 || visited.count(currentNode) > 0 || currentNode == NodoAParar) {
        std::cout<<"Terminado: "<<std::endl;
        return;
    }

    visited.insert(currentNode);
     std::cout << "Estamos en: (" << currentNode->point[0] << ", " << currentNode->point[1] << ")\n";
     std::cout <<"KDTree tiene la raiz: " << KdTree.getRoot()->point[0] << ", " << KdTree.getRoot()->point[1]<<"\n";

   std::list<int*> newLista = KdTree.preorderList();
  
  
   int coords[2];
        kdTree<2> newKdTree;
        newKdTree.setRoot(currentNode);
      
        for (int* i : newLista) {
            coords[0] = i[0];
            coords[1] = i[1];
            newKdTree.insert(coords, index);
            index++;
        }

  std::cout << "Estamos en: (" << currentNode->point[0] << ", " << currentNode->point[1] << ")\n";
     std::cout <<"KDTree tiene la raiz: " << KdTree.getRoot()->point[0] << ", " << KdTree.getRoot()->point[1]<<"\n";

    // Get the coordinates of the current node
    int currentCoords[2];
    currentCoords[0] = currentNode->point[0];
    currentCoords[1] = currentNode->point[1];

    // Find the nearest neighbor for the current node
    int rootCoords[2];
    rootCoords[0] = KdTree.getRoot()->point[0];
    rootCoords[1] = KdTree.getRoot()->point[1];
    KdTree.preorderVisual();
    std::list<Node<2>*> listaVecinos = KdTree.vecinosMasCercanos(currentCoords, nVecinos);
    for (Node<2>* node : listaVecinos) {
        // Access the data of the node or perform any other desired operation
        // For example, print the coordinates of the node's point
        std::cout << "Coordenadas de los vecinos: (" << node->point[0] << ", " << node->point[1] << ")\n";
    }
    double distance;
    Node<2>* nearestNeighbor = nullptr;
    getNearestNeighbor(currentNode, listaVecinos, nearestNeighbor);
    if (nearestNeighbor != nullptr) {
    std::cout << "Coordenadas del vecino mas cercano: (" << nearestNeighbor->point[0] << ", " << nearestNeighbor->point[1] << ")\n";

    // Add the distance as a weighted edge in the graph
    distance = nearestNeighbor->distancia;
    distanciaInicial = distanciaInicial + distance;
    std::cout<<"Distancia: "<<distance<<std::endl;
    std::cout<<"Distancia recorrida: "<<distanciaInicial<<std::endl;

   
    
    
    }
    if (nearestNeighbor != nullptr) {
        // Update the root of the kdTree with the nearestNeighbor
       //std::list<int*> newLista = KdTree.preorderList();
        index++;
        int coords[2];
        newKdTree.setRoot(nearestNeighbor);
        for (int* i : newLista) {
            coords[0] = i[0];
            coords[1] = i[1];
            newKdTree.insert(coords, index);
            index++;
        }
    if (currentNode != nullptr && nearestNeighbor != nullptr) {
      std::pair<int, int> currentPoint = std::make_pair(currentNode->point[0], currentNode->point[1]);
       std::pair<int, int> neighborPoint = std::make_pair(nearestNeighbor->point[0], nearestNeighbor->point[1]);
       graph.addEdge(currentPoint, neighborPoint, distance);
    }
        // Recursively find the nearest neighbors for the nearest neighbor
        PuntoAOtro(newKdTree, nearestNeighbor, nVecinos - 1, graph, visited, distanciaInicial, index, NodoAParar);
      
        
    }
  
  return;

  
}
void rutaMasLarga(Node<2>* root, std::list<Node<2>*>& listaVecinos, Node<2>*& largest) {
    if (listaVecinos.empty()) {
        largest = nullptr;
        return;
    }

    double firstDistance = 0;
    Node<2>* firstNode = nullptr;

    for (Node<2>* node : listaVecinos) {
        
        if (node->distancia > firstDistance) {
            firstDistance = node->distancia;
            firstNode = node;
        }
    }

    largest = firstNode;
}

/*void rutaMasLarga(Node<2>*& nodo){
  std::vector<Node<2>*> puntosLejanos;
  Node<2> nodoMasIzquierdo=nullptr, nodoMasDerecho=nullptr;
  nodoMasIzquierdo=mostLeft(nodo, nodoMasIzquierdo);
  NodoMasDerecho=mostRight(nodo, nodoMasDerecho);

  if(nodoMasDerecho!=nodoMasIzquierdo){ 
  cout<<"los puntos de interes mas lejanos son: "<<nodoMasIzquierdo.index<<" y "<<nodoMasDerecho<<endl;
  //poner la funcion de encontrar camino mas corto    
  }else{
    std::cout<<"no hay suficientes elementos para encontrar los mas lejanos"<<endl;
    return;    
  }

}

Node<2>*& mostLeft(Node<2>*& nodo, Node<2>* & nodoMasIzquierdo){
  if((nodo->left)=NULL){
    nodoMasIzquierdo=nodo;
    return nodoMasIzquierdo;
  }else{
    nodoMasIzquierdo=mostLeft(nodo->left, nodoMasIzquierdo);
    }
}

Node<2>*& mostRight(Node<2>*& nodo, Node<2>* & nodoMasDerecho){
  if((nodo->right)=NULL){
    nodoMasDerecho=nodo;
    return nodoMasDerecho;
  }else{
    nodoMasDerecho=mostLeft(nodo->left, nodoMasDerecho);
    }
} */