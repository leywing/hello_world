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

struct node {
    int val;
    node* next;
    node(int x):val(x),next(nullptr){};
};

class list{
private:
    node* head;
    node* tail;
    int num;
public:
    list(){
        head=nullptr;
        
        num=0;
    }
    ~list(){
        node* temp=head;
        for(int i=0;i<num;i++){
            temp=head;
            head=head->next;
            delete temp;
        }
        //need attention
    }
    void insert_tail(int x1){
        if(num==0){
            head=new node(x1);
            tail=head;
            num=1;
        }
        else{
            node* temp=new node(x1);
            tail->next=temp;
            tail=temp;
            num++;
        }
    }
    void print_all(){
        node* temp;
        temp=head;
        for(int i=0;i<num;i++){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
    int return_length(){
        return num;
    }
    
};

int main(){
    list a;
    a.insert_tail(5);
    a.insert_tail(8);
    a.insert_tail(9);
    a.print_all();
    cout<<a.return_length()<<endl;
    
    return 0;
}

