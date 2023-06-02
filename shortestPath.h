#pragma once
#include "struct.h"
#include "kdTree.h"
#include <list>
#include <unordered_set>
#include <unordered_map>
struct Graph {
    std::vector<std::vector<double>> adjacencyMatrix;
    std::unordered_map<int, std::pair<double, double>> pointMap;

    Graph(int n);
    void addEdge(const std::pair<double, double>& pointU, const std::pair<double, double>& pointV, double weight);
    int findIndexForPoint(const std::pair<double, double>& point);
    void printGraph() const;
};

void rutaMasLarga(Node<2>* root, std::list<Node<2>*>& listaVecinos, Node<2>*& largest);
int countStructs(const std::list<Elemento>& myList);
void getNearestNeighbor(Node<2>* root, std::list<Node<2>*>& listaVecinos, Node<2>*& nearest);
void findNearestNeighborsRecursively(kdTree<2>& KdTree, Node<2>* currentNode, int nVecinos, Graph& graph, std::unordered_set<Node<2>*>& visited, double distanciaInicial,int& index);
void PuntoAOtro(kdTree<2>& KdTree, Node<2>* currentNode, int nVecinos, Graph& graph, std::unordered_set<Node<2>*>& visited, double distanciaInicial,int& index, Node<2>* NodoAParar);
bool isValidIntArray(int* arr);