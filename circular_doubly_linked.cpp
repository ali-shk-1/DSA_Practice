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
    Node* prev;

    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }

    void insert(int value){
        Node* newNode=new Node(value);
        if (head==nullptr) {
            head=newNode;
            newNode->next=newNode;
            newNode->prev=newNode;
            tail=newNode;
            return;
        }
        
        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }

    void deleteNode(int value){
        if(head==nullptr)
            return;

        if(head==tail && head->data==value){
            delete head;
            head=nullptr;
            tail=nullptr;
            return;
        }
        //head is to be deleted
        if(head->data==value){
            Node* temp=head;
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete temp;
            return;
        }
        //Node is after head 
        Node* current=head;
        while (current->next != head && current->next->data != value) {
            current=current->next;
        }

        //deleting phase
        if(current->next != head){
            Node* temp=current->next;
            current->next=temp->next;    
            temp->next->prev=current;
            if(temp==tail)
                tail=current;
            delete temp;   
        }
    }

    int getLength(){
        if(head==nullptr)   return 0;
        int count=1;
        struct Node* temp;
        temp=head->next;
        while(temp!=head){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void reverse(){
        if(head==nullptr) return;    
        struct Node *current=head;
        struct Node *temp=nullptr;
        do{                          
            temp=current->prev;
            current->prev=current->next;
            current->next=temp;
            current=current->prev;
        }while(current!=head);
        head=temp->prev;             
        tail=head->prev;             
    }
    void traverse(){
        if(head==nullptr)   return;
        struct Node* curr=head;
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }while(curr!=head);
        cout<<endl;
    }
    vector<int> getValues(){
        struct Node* curr=head;
        vector<int> vec;
        if(head==nullptr)   return vec;
        do{
            vec.push_back(curr->data);
            curr=curr->next;
        }while(curr!=head);
        return vec;
    }

    void removeDuplicateSorted(){
        vector<int> vec=getValues();
        
        for(int i=0;i< (int)vec.size()-1 ;i++ ){ //prevent underflow
            if(vec[i]==vec[i+1])
                deleteNode(vec[i]);
        }
    }
};


int main(){
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(3); 
    list.insert(3); 
    list.insert(3); 
    list.insert(4);  
    list.removeDuplicateSorted();
    list.traverse();
    return 0;
}