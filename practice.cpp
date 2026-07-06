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
//d
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

    int getLength(){
        int count=0;
        struct Node* temp;
        temp=head;
        while(temp!=0){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void reverse(){
        struct Node *prevnode,*currentnode,*nextnode;
        prevnode=nullptr;
        currentnode=head;
        nextnode=head;
        while (nextnode!=nullptr) {
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        head=prevnode;
    }
    void traverse(){
        struct Node* curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    vector<int> getValues(){
        struct Node* curr=head;
        vector<int> vec;
        while(curr!=nullptr){
            vec.push_back(curr->data);
            curr=curr->next;
        }
        return vec;;
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
    LinkedList list;
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