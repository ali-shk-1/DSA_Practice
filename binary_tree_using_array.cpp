#include <cstddef>
#include <float.h>
#include<iostream>
#include <iterator>
#include <locale>
#include <random>
#include <type_traits>
#include<vector>
#include<math.h>
#include<algorithm>
#include <unordered_map>
#include<stdio.h>
#include <string>
using namespace std;

const int MAX_SIZE = 100;
int tree[MAX_SIZE];
bool exists[MAX_SIZE]; // tracks whether a node is present

void insertRoot(int value) {
    tree[0] = value;
    exists[0] = true;
    
}

// Insert left child of node at index i
void insertLeft(int i, int value) {
    int leftIndex = 2 * i + 1;
    tree[leftIndex] = value;
    exists[leftIndex] = true;

    
}

// Insert right child of node at index i
void insertRight(int i, int value) {
    int rightIndex = 2 * i + 2;
    tree[rightIndex] = value;
    exists[rightIndex] = true;
}

int getParent(int i) {
    if (i == 0) return -1; // root has no parent
    return (i - 1) / 2;
}

void display(int size) {
    cout << "Index: ";
    for (int i = 0; i < size; i++)
        cout << i << "\t";
    cout << "\nValue: ";
    for (int i = 0; i < size; i++)
        cout << (exists[i] ? to_string(tree[i]) : "-") << "\t";
    cout << endl;
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++)
        exists[i] = false;

    // Building the tree:
    //        10
    //       /  \
    //      -    20
    //          /  \
    //         -    30
    //               \
    //                40

    insertRoot(10);         // index 0
    insertRight(0, 20);     // index 2
    insertRight(2, 30);     // index 6
    insertRight(6, 40);     // index 14

    display(15);

    return 0;
}