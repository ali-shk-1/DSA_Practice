#include <cstddef>
#include <float.h>
#include<iostream>
#include <iterator>
#include <locale>
#include <ostream>
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

class Stack{
public:
    LinkedList list;
    void push(int val){
        Node* newNode=new Node(val);
        newNode->next=list.head;
        list.head=newNode;
    }
    int pop(){
        Node* temp=list.head;
        int val=temp->data;
        list.head=list.head->next;
        delete temp;
        return val;
    }
    int peek(){
        Node* temp=list.head;
        int val=temp->data;
        return val;
    }
    void display(){
        struct Node* curr=list.head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    
    
};


class Queue{
public:
    Stack s1,s2;
    void enqueue(int num){
        s1.push(num);
    }
    int dequeue(){
        if (s1.list.head==nullptr) {
            while(s1.list.head!=nullptr)
                s2.push(s1.pop());    
        }
        if(s2.list.head==nullptr){
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        return s2.pop();
    }
    int peek(){
        if(s2.list.head==nullptr){
            while(s1.list.head!=nullptr)
                s2.push(s1.pop());
        }
        if (s2.list.head==nullptr) {
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        return s2.peek();
    }
    bool isEmpty(){
        return s1.list.head==nullptr && s2.list.head==nullptr;
    }
    int size(){
        return s1.list.getLength() + s2.list.getLength();
    }
    void display(){
        Node* curr=s2.list.head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        vector<int> s1vals=s1.list.getValues();
        for(int i=(int)s1vals.size()-1;i>=0;i--){
            cout<<s1vals[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();

    return 0;
}