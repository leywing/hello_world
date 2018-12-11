//
//  list_oneway.cpp
//  test
//
//  Created by ley on 2018/12/6.
//  Copyright © 2018年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;


//template <typename T>
//struct list_node {
//    T val;
//    list_node* next;
//    list_node(T x): val(x),next(nullptr){}
//};
//
//template <typename T>
//class list_oneway{
//private:
//    list_node<T>* head;
//    list_node<T>* tail;
//    int num;
//public:
//    list_oneway(){
//        head=nullptr;
//        num=0;
//    };
//    void insert(T x){
//
//    }
//
//
//};

template <class T>
struct node {
    T val;
    node<T>* next;
    node<T>* forward;
    node(T x):val(x),next(nullptr),forward(nullptr){};
};

template <class T>
class list{
private:
    node<T>* head;
    node<T>* tail;
    int num;
public:
    list(){
        head=nullptr;
        num=0;
    }
    ~list(){
        node<T>* temp=head;
        for(int i=0;i<num;i++){
            temp=head;
            head=head->next;
            delete temp;
        }
        //need attention
    }
    void insert_tail(T x1){
        if(num==0){
            head=new node<T>(x1);
            tail=head;
            num=1;
        }
        else{
            node<T>* temp=new node<T>(x1);
            tail->next=temp;
            temp->forward=tail;
            tail=temp;
            num++;
        }
    }
    void print_all(){
        node<T>* temp;
        temp=head;
        for(int i=0;i<num;i++){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void print_all_inverse(){
        node<T>* temp;
        temp=tail;
        for(int i=0;i<num;i++){
            cout<<temp->val<<" ";
            temp=temp->forward;
        }
        cout<<endl;
    }
    int return_length(){
        return num;
    }
    int find(T x){
        node<T>* temp=head;
        while(temp!=nullptr){
            if(temp->val==x){
                return 1;
            }
            temp=temp->next;
        }
        return 0;
    }
    void remove(T x){
        node<T>* temp;
        node<T>* count;
        temp=head;
        while(temp->next!=nullptr){
            if(temp->val==x&&temp==head){
                head=head->next;
                delete temp;
                temp=head;
                num--;
                
            }else if (temp->val==x){
                temp->forward->next=temp->next;
                temp->next->forward=temp->forward;
                count=temp->next;
                delete temp;
                temp=count;
                num--;
            }else{
            temp=temp->next;
            }
        }
    }
};

int main(){
    
    node<double> nd_1(6.5);
    cout<<nd_1.val<<endl;
    list<float> a;
    a.insert_tail(5.6);
    a.insert_tail(8.9);
    a.insert_tail(9.0);
    a.print_all();
    a.remove(5.6);
    a.print_all();
    a.print_all_inverse();
    if(a.find(7)){
        cout<<"success"<<endl;
    }
    else {cout<<"fail"<<endl;}
    cout<<a.return_length()<<endl;
    
    return 0;
}

