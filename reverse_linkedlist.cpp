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
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head=nullptr;
    }

    void insert(int value){
        Node* newNode=new Node(value);
        if (head==nullptr) {
            head=newNode;
            return;
        }
        
        Node* temp=head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void deleteNode(int value){
        if(head==nullptr)
            return;

        //head is to be deleted
        if(head->data==value){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        //Node is after head 
        Node* current=head;
        while (current->next != nullptr && current->next->data != value) {
            current=current->next;
        }

        //deleting phase
        if(current->next != nullptr){
            Node* temp=current->next;
            current->next=temp->next;
            delete temp;
            
        }
    }

    void getLength(){
        int count=0;
        struct Node* temp;
        temp=head;
        while(temp!=0){
            count++;
            temp=temp->next;
        }
        cout<<count<<endl;
    }
    void reverse(){
        struct Node *prevnode,*currentnode,*nextnode;
        prevnode=0;
        currentnode=head;
        nextnode=head;
        while (nextnode!=0) {
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
    }
};


int main(){
    LinkedList list;
    list.insert(1); 
    list.reverse();
    list.getLength();
    list.deleteNode(1);
    list.getLength();
    return 0;
}