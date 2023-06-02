#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <stack>
template <int DIMENSION>
struct Node {
    int point[DIMENSION];
    Node* left;
    Node* right;
    Node(int arr[],int index);
    unsigned int cd;
    double distancia;
    int index;
};

template <int DIMENSION>
class kdTree {
    Node<DIMENSION>* root;
    Node<DIMENSION>* newNode(int arr[], int index);
    Node<DIMENSION>* insertRec(Node<DIMENSION>* node, int point[], unsigned depth, int index);
    bool arePointsSame(int point1[], int point2[]);
    Node<DIMENSION>* searchRec(Node<DIMENSION>* node, int point[], unsigned depth);
    std::vector<Node<DIMENSION>*> PRIVen_cuadrante(Node<DIMENSION>* node, int minPoint[], int maxPoint[], unsigned depth);
 void preorderTraversal(Node<DIMENSION>* node);
Node<DIMENSION>* balanceTree(Node<DIMENSION>* node);
Node<DIMENSION>* constructBalancedTree(typename std::list<int*>::iterator begin, typename std::list<int*>::iterator end, typename std::vector<int>::iterator indices);
void extractPoints(Node<DIMENSION>* node, std::list<int*>& pointsList);
std::list<int*> preorderTraversalList(Node<DIMENSION>* node);
Node<DIMENSION>* insertRecBal(Node<DIMENSION>* node, int point[], unsigned depth, int index);
std::list<Node<DIMENSION>*> findNearestNeighbors(Node<DIMENSION>* node, const int target[], int desiredCount);
void findNearestNeighborsRecursive(Node<DIMENSION>* node, const int target[], std::priority_queue<std::pair<double, Node<DIMENSION>*>>& pq, double& maxDistance, int desiredCount);
void clearRecursive(Node<DIMENSION>* node);
void preorderTraversalVisual(Node<DIMENSION>* node, std::string indent = "");

public:
    kdTree() : root(nullptr) {}
    kdTree(int point[]);
    void insert(int point[], int index);
    void insertBalTree(int point[], int index);
    Node<DIMENSION>* search(int point[]);
    void en_cuadrante(int minPoint[], int maxPoint[]);
    void preorder();
    std::list<int*> preorderList();
    std::list<Node<DIMENSION>*> vecinosMasCercanos(const int target[], int desiredCount);
    Node<DIMENSION>* getRoot() const;
    void setRoot(Node<DIMENSION>* newRoot);
     void preorderVisual();
    void clear();
  
};

template <int DIMENSION>
Node<DIMENSION>::Node(int arr[],int index) {
    for (int i = 0; i < DIMENSION; i++)
        point[i] = arr[i];
    left = right = nullptr;
       cd = 0;
       distancia = NULL;
       index = 0;
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::newNode(int arr[],int index) {
    Node<DIMENSION>* temp = new Node<DIMENSION>(arr, index);
    return temp;
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::insertRec(Node<DIMENSION>* node, int point[], unsigned depth, int index) {
    if (node == nullptr)
        return newNode(point, index);

   if (arePointsSame(node->point, point))
        return node; 
  
    unsigned cd = depth % DIMENSION;

    if (point[cd] < node->point[cd])
        node->left = insertRec(node->left, point, depth + 1,index);
    else
        node->right = insertRec(node->right, point, depth + 1,index);

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
Node<DIMENSION>* kdTree<DIMENSION>::insertRecBal(Node<DIMENSION>* node, int point[], unsigned depth, int index) {
    if (node == nullptr) {
        return newNode(point, index);
    }

    if (arePointsSame(node->point, point)) {
        return node;
    }
    node->index = index;
    unsigned cd = depth % DIMENSION;

    if (point[cd] < node->point[cd]) {
        node->left = insertRecBal(node->left, point, depth + 1, index);
    } else if (point[cd] > node->point[cd]) {
        node->right = insertRecBal(node->right, point, depth + 1, index);
    } else {
        // Handle the case when the point is already present in the tree
        if (arePointsSame(node->point, point)) {
            return node;
        }

        // Insert to the left subtree if the points are not exactly the same
        node->left = insertRecBal(node->left, point, depth + 1, index);
    }

    return balanceTree(node);
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::balanceTree(Node<DIMENSION>* node) {
    std::list<int*> pointsList;
    extractPoints(node, pointsList);

    // Sort the points list along with their respective indices
    std::vector<std::pair<int*, int>> sortedPoints;
    for (auto it = pointsList.begin(); it != pointsList.end(); ++it) {
        sortedPoints.push_back(std::make_pair(*it, (*it)[DIMENSION]));  // Assuming the index is stored at the DIMENSION position
    }
    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const auto& p1, const auto& p2) {
        return p1.first < p2.first;
    });

    // Extract the sorted points and their indices into separate lists
    std::list<int*> sortedPointsList;
    std::vector<int> indices;
    for (const auto& pair : sortedPoints) {
        sortedPointsList.push_back(pair.first);
        indices.push_back(pair.second);
    }

    // Convert the sorted list of points and indices back into a balanced tree
    return constructBalancedTree(sortedPointsList.begin(), sortedPointsList.end(), indices.begin());
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::constructBalancedTree(typename std::list<int*>::iterator begin, typename std::list<int*>::iterator end, typename std::vector<int>::iterator indices) {
    if (begin == end) {
        return nullptr;
    }

    typename std::list<int*>::iterator mid = std::next(begin, std::distance(begin, end) / 2);
    Node<DIMENSION>* node = newNode(*mid, *indices);

    // Skip duplicate points
    std::list<int*>::iterator nextIter = std::next(mid);
    while (nextIter != end && arePointsSame(*mid, *nextIter)) {
        ++nextIter;
        ++indices;
    }

    node->left = constructBalancedTree(begin, mid, indices);
    node->right = constructBalancedTree(nextIter, end, indices);

    return node;
}


template <int DIMENSION>
void kdTree<DIMENSION>::extractPoints(Node<DIMENSION>* node, std::list<int*>& pointsList) {
    if (node == nullptr)
        return;

    pointsList.push_back(node->point);
    extractPoints(node->left, pointsList);
    extractPoints(node->right, pointsList);
}




template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::searchRec(Node<DIMENSION>* node, int point[], unsigned depth) {
    if (node == nullptr || arePointsSame(node->point, point)){
        return node;
    }

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
double euclideanDistance(const int point1[], const int point2[]) {
    double distance = 0.0;
    for (int i = 0; i < DIMENSION; ++i) {
        double diff = point1[i] - point2[i];
        distance += std::pow(diff, 2);
    }
    return std::sqrt(distance);
}

template <int DIMENSION>
std::list<Node<DIMENSION>*> kdTree<DIMENSION>::findNearestNeighbors(Node<DIMENSION>* node, const int target[], int desiredCount) {
    std::list<Node<DIMENSION>*> nearestNeighbors; // List to store nearest neighbors

    if (node == nullptr || desiredCount <= 0)
        return nearestNeighbors;

    std::priority_queue<std::pair<double, Node<DIMENSION>*>> pq;  // Max-heap based on distance
    double maxDistance = std::numeric_limits<double>::infinity();

    findNearestNeighborsRecursive(node, target, pq, maxDistance, desiredCount);

    while (!pq.empty()) {
        nearestNeighbors.push_front(pq.top().second); // Push the nearest neighbor at the front of the list
        pq.pop();
    }

    return nearestNeighbors;
}

template <int DIMENSION>
void kdTree<DIMENSION>::findNearestNeighborsRecursive(Node<DIMENSION>* node, const int target[], std::priority_queue<std::pair<double, Node<DIMENSION>*>>& pq, double& maxDistance, int desiredCount) {
    if (node == nullptr || maxDistance <= 0.0 || pq.size() >= desiredCount)
        return;

    double distance = euclideanDistance<DIMENSION>(node->point, target);
    node->distancia = distance;
    if (distance < maxDistance) {
        pq.push({ distance, node });
        if (pq.size() > desiredCount) {
            pq.pop();
            maxDistance = pq.top().first;
        }
    }

    unsigned cd = 0; // Start with the first dimension (assumes DIMENSION > 0)
    std::stack<Node<DIMENSION>*> stack;
    Node<DIMENSION>* current = node;

    // Traverse down the tree
    while (current != nullptr) {
        stack.push(current);
        current->cd = cd % DIMENSION;

        if (target[cd] < current->point[cd]) {
            current = current->left;
        } else {
            current = current->right;
        }

        cd++;
    }

    // Backtrack and check other subtrees
    while (!stack.empty()) {
        current = stack.top();
        stack.pop();

        // Check if there's a possibility of a closer point in the other subtree
        if (std::pow(target[current->cd] - current->point[current->cd], 2) < maxDistance) {
            if (target[current->cd] < current->point[current->cd]) {
                findNearestNeighborsRecursive(current->left, target, pq, maxDistance, desiredCount);
                // Check the other subtree as well
                findNearestNeighborsRecursive(current->right, target, pq, maxDistance, desiredCount);
            } else {
                findNearestNeighborsRecursive(current->right, target, pq, maxDistance, desiredCount);
                // Check the other subtree as well
                findNearestNeighborsRecursive(current->left, target, pq, maxDistance, desiredCount);
            }
        }
    }
}

template <int DIMENSION>
void kdTree<DIMENSION>::preorderTraversalVisual(Node<DIMENSION>* node, std::string indent) {
    if (node == nullptr)
        return;

    for (int i = 0; i < DIMENSION; ++i) {
        std::cout << node->point[i] << " ";
    }
    std::cout << std::endl;

   std::cout << indent << "|- Left: ";
    preorderTraversal(node->left);
   std::cout << indent << "|- Right: ";
    preorderTraversal(node->right);
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
std::list<int*> kdTree<DIMENSION>::preorderTraversalList(Node<DIMENSION>* node) {
    std::list<int*> pointsList;

    if (node == nullptr)
        return pointsList;

    // Add the current node's point to the list
    pointsList.push_back(node->point);

    // Recursively traverse the left and right subtrees
    std::list<int*> leftList = preorderTraversalList(node->left);
    std::list<int*> rightList = preorderTraversalList(node->right);

    // Append the points from the left and right subtrees to the main list
    pointsList.insert(pointsList.end(), leftList.begin(), leftList.end());
    pointsList.insert(pointsList.end(), rightList.begin(), rightList.end());

    return pointsList;
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
void kdTree<DIMENSION>::clearRecursive(Node<DIMENSION>* node) {
    if (node == nullptr) {
        return;
    }

    clearRecursive(node->left);
    clearRecursive(node->right);

    delete node;
}


template <int DIMENSION>
void kdTree<DIMENSION>::preorder(){
preorderTraversal(root);
}

template <int DIMENSION>
void kdTree<DIMENSION>::preorderVisual(){
preorderTraversalVisual(root);
}

template <int DIMENSION>
std::list<int*> kdTree<DIMENSION>::preorderList(){
  return preorderTraversalList(root);
}

template <int DIMENSION>
kdTree<DIMENSION>::kdTree(int point[]) {
    root = newNode(point);
}

template <int DIMENSION>
void kdTree<DIMENSION>::insert(int point[],int index) {
    root = insertRec(root, point, 0, index);
}

template <int DIMENSION>
void kdTree<DIMENSION>::insertBalTree(int point[], int index) {
    root = insertRecBal(root, point, 0, index);
}

template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::search(int point[]) {
    return searchRec(root, point, 0);
}

template <int DIMENSION>
 std::list<Node<DIMENSION>*> kdTree<DIMENSION>:: vecinosMasCercanos(const int target[], int desiredCount){
   return findNearestNeighbors(root, target, desiredCount);
 }
  
template <int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::getRoot() const {
    return root; 
}
template <int DIMENSION>
void kdTree<DIMENSION>::setRoot(Node<DIMENSION>* newRoot) {
        root = newRoot;
    }

template <int DIMENSION>
void kdTree<DIMENSION>::clear() {
    clearRecursive(root);
    root = nullptr;
} 
