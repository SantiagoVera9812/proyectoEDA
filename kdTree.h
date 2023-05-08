#pragma once
#include <vector>
#include <iostream>
template <int DIMENSION>
struct Node {
    int point[DIMENSION];
    Node* left;
    Node* right;
    Node(int arr[]);
};

template <int DIMENSION>
class kdTree {
    Node<DIMENSION>* root;
    Node<DIMENSION>* newNode(int arr[]);
    Node<DIMENSION>* insertRec(Node<DIMENSION>* node, int point[], unsigned depth);
    bool arePointsSame(int point1[], int point2[]);
    bool searchRec(Node<DIMENSION>* node, int point[], unsigned depth);
    std::vector<Node<DIMENSION>*> PRIVen_cuadrante(Node<DIMENSION>* node, int minPoint[], int maxPoint[], unsigned depth);
 void preorderTraversal(Node<DIMENSION>* node);
public:
    kdTree() : root(nullptr) {}
    kdTree(int point[]);
    void insert(int point[]);
    bool search(int point[]);
    void en_cuadrante(int minPoint[], int maxPoint[]);
    void preorder();
};

template <int DIMENSION>
Node<DIMENSION>::Node(int arr[]) {
    for (int i = 0; i < DIMENSION; i++)
        point[i] = arr[i];
    left = right = nullptr;
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::newNode(int arr[]) {
    Node<DIMENSION>* temp = new Node<DIMENSION>(arr);
    return temp;
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::insertRec(Node<DIMENSION>* node, int point[], unsigned depth) {
    if (node == nullptr)
        return newNode(point);

   if (arePointsSame(node->point, point))
        return node; 
  
    unsigned cd = depth % DIMENSION;

    if (point[cd] < node->point[cd])
        node->left = insertRec(node->left, point, depth + 1);
    else
        node->right = insertRec(node->right, point, depth + 1);

    return node;
}

template <int DIMENSION>
bool kdTree<DIMENSION>::arePointsSame(int point1[], int point2[]) {
    for (int i = 0; i < DIMENSION; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}

template <int DIMENSION>
bool kdTree<DIMENSION>::searchRec(Node<DIMENSION>* node, int point[], unsigned depth) {
    if (node == nullptr)
        return false;

    if (arePointsSame(node->point, point))
        return true;

    unsigned cd = depth % DIMENSION;

    if (point[cd] < node->point[cd])
        return searchRec(node->left, point, depth + 1);

    return searchRec(node->right, point, depth + 1);
}

template <int DIMENSION>
std::vector<Node<DIMENSION>*> kdTree<DIMENSION>:: PRIVen_cuadrante(Node<DIMENSION>* node, int minPoint[], int maxPoint[], unsigned depth) {
    std::vector<Node<DIMENSION>*> result;
    std::vector<Node<DIMENSION>*> leftResult;
    std::vector<Node<DIMENSION>*> rightResult;
    if (node == nullptr)
        return result;

    unsigned cd = depth % DIMENSION;

    // Verificar si el nodo actual está dentro del cuadrante
    bool isInsideQuadrant = true;
    for (int i = 0; i < DIMENSION; ++i) {
        if (node->point[i] < minPoint[i] || node->point[i] > maxPoint[i]) {
            isInsideQuadrant = false;
            break;
        }
    } 
    // Si el nodo actual está dentro del cuadrante, añadirlo al resultado
    if (isInsideQuadrant){
        result.push_back(node);
      std::cout << "Node encontrado: ";
        for (int i = 0; i < DIMENSION; ++i) {
    std::cout << node->point[i] << " ";
}
std::cout << std::endl;

    }
    // Verificar recursivamente en los subárboles izquierdo y derecho
    if (node->left != nullptr && minPoint[cd] <= node->point[cd])
        leftResult = PRIVen_cuadrante(node->left, minPoint, maxPoint, depth + 1);
    
    if (node->right != nullptr && maxPoint[cd] >= node->point[cd])
    rightResult = PRIVen_cuadrante(node->right, minPoint, maxPoint, depth + 1);

    // Combinar los resultados de los subárboles izquierdo y derecho
     if (!leftResult.empty())
    result.insert(result.end(), leftResult.begin(), leftResult.end());
     if (!rightResult.empty())
    result.insert(result.end(), rightResult.begin(), rightResult.end());

    return result;
}

template <int DIMENSION>
void kdTree<DIMENSION>::preorderTraversal(Node<DIMENSION>* node) {
    if (node == nullptr)
        return;

    for (int i = 0; i < DIMENSION; ++i) {
        std::cout << node->point[i] << " ";
    }
    std::cout << std::endl;

    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
template <int DIMENSION>
void kdTree<DIMENSION>::en_cuadrante(int minPoint[], int maxPoint[]) {

  std::cout << "minPoint: " << minPoint[0] << ", " << minPoint[1] << std::endl;
std::cout << "maxPoint: " << maxPoint[0] << ", " << maxPoint[1] << std::endl;
    std::vector<Node<DIMENSION>*> nodes = PRIVen_cuadrante(root, minPoint, maxPoint, 0);

  if (!nodes.empty())
        root = nodes[0];
    else
        root = nullptr;

  if (!nodes.empty()) {
        for (const auto& node : nodes) {
            for (int i = 0; i < DIMENSION; ++i) {
                std::cout << node->point[i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No se encontro nigun nodo" << std::endl;
    }
}

template <int DIMENSION>
void kdTree<DIMENSION>::preorder(){
preorderTraversal(root);
}

template <int DIMENSION>
kdTree<DIMENSION>::kdTree(int point[]) {
    root = newNode(point);
}

template <int DIMENSION>
void kdTree<DIMENSION>::insert(int point[]) {
    root = insertRec(root, point, 0);
}

template <int DIMENSION>
bool kdTree<DIMENSION>::search(int point[]) {
    return searchRec(root, point, 0);
}


  
