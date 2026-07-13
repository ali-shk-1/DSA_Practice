#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* create();  // forward declaration

int main() {
    Node* root;
    root = create();
    return 0;
}

Node* create() {
    int x;
    cout << "Enter Data: ";
    cin >> x;

    if (x == -1)
        return nullptr;

    Node* newNode = new Node();
    newNode->data = x;

    cout << "Left Child of " << x << endl;
    newNode->left = create();

    cout << "Right Child of " << x << endl;
    newNode->right = create();

    return newNode;
}