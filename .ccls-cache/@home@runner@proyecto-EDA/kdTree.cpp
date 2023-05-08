#include "kdTree.h"
template<int DIMENSION>
Node<DIMENSION>::Node(int arr[]) {
    for (int i = 0; i < DIMENSION; i++)
        point[i] = arr[i];
    left = right = nullptr;
}

template<int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::newNode(int arr[]) {
    Node<DIMENSION>* temp = new Node<DIMENSION>(arr);
    return temp;
}

template<int DIMENSION>
Node<DIMENSION>* kdTree<DIMENSION>::insertRec(Node<DIMENSION>* node, int point[], unsigned depth) {
    if (node == nullptr)
        return newNode(point);

    unsigned cd = depth % DIMENSION;

    if (point[cd] < node->point[cd])
        node->left = insertRec(node->left, point, depth + 1);
    else
        node->right = insertRec(node->right, point, depth + 1);

    return node;
}

template<int DIMENSION>
bool kdTree<DIMENSION>::arePointsSame(int point1[], int point2[]) {
    for (int i = 0; i < DIMENSION; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}

template<int DIMENSION>
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

template<int DIMENSION>
kdTree<DIMENSION>::kdTree(int point[]) {
    root = newNode(point);
}

template<int DIMENSION>
void kdTree<DIMENSION>::insert(int point[]) {
    root = insertRec(root, point, 0);
}

template<int DIMENSION>
bool kdTree<DIMENSION>::search(int point[]) {
    return searchRec(root, point, 0);
}