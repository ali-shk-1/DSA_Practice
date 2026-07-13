#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};
class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        root=nullptr;
    }

    Node* insert(Node* node,int value){
        if(node==nullptr)
            return new Node(value);
        if(value<node->data)
            node->left=insert(node->left,value);
        else
            node->right=insert(node->right,value);
        return node;
    }
    void insert(int value){
        root=insert(root,value);
    }
    //left root right
    void inorder(Node*node){
        if(node==nullptr)   
            return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    void inorder(){
        inorder(root);
        cout<<endl;
    }
    
    //root left right
    void preorder(Node*node){
        if(node==nullptr)   
            return;
        cout<<node->data<<" ";    
        preorder(node->left);
        preorder(node->right);
    }
    void preorder(){
        preorder(root);
        cout<<endl;
    }
    
    //left right root
    void postorder(Node*node){
        if(node==nullptr)   
            return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";    
    }
    void postorder(){
        postorder(root);
        cout<<endl;
    }
};
int main(){
    BinaryTree bt;
    bt.insert(50);
    bt.insert(60);
    bt.insert(30);
    bt.insert(40);
    bt.insert(10);

    bt.inorder();
}