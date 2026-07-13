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

class LinkedList{               //with head and tail also
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    
    void insert(int value){     //specifically add at tail
        Node* newNode=new Node(value);
        if (head==nullptr) {
            head=newNode;
            tail=newNode;
            return;
        }
        
        Node* temp=head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
        tail=newNode;
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
        prevnode=0;
        currentnode=head;
        nextnode=head;
        while (nextnode!=0) {
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
class PriorityQueue{
public:
    LinkedList list;
    void enqueue(int num){
        Node* newNode=new Node(num);
        if(list.head==nullptr || num<list.head->data){
            newNode->next=list.head;
            list.head=newNode;
            if(list.tail==nullptr)
                list.tail=newNode;
            return;
        }

        Node* temp=list.head;
        while(temp->next!=nullptr && temp->next->data<=num){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(temp==list.tail)
            list.tail=newNode;
    }
    int dequeue(){
        if (list.head==nullptr) {
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        Node* temp=list.head;
        int value=list.head->data;
        list.head=list.head->next;
        if(list.head==nullptr)
            list.tail=nullptr;
        delete temp;
        return value;
    }
    int peek(){
      if (list.head==nullptr) {
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        return list.head->data;
    }
    bool isEmpty(){
        return list.head==nullptr;
    }
    int size(){
        return list.getLength();
    }
    void display(){
        list.traverse();
    }
};


int main(){
    LinkedList list;
    PriorityQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.peek();
    q.display();
    return 0;
}