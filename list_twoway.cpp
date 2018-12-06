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
    node* forward;
    node(int x):val(x),next(nullptr),forward(nullptr){};
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
            temp->forward=tail;
            tail=temp;
            num++;
        }
    }
    void print_all(){
        node* temp;
        temp=head;
        for(int i=0;i<num;i++){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void print_all_inverse(){
        node* temp;
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
    void remove(int x){
        node* temp;
        node* count;
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
    list a;
    a.insert_tail(5);
    a.insert_tail(8);
    a.insert_tail(9);
    a.print_all();
    a.remove(5);
    a.print_all();
    a.print_all_inverse();
    cout<<a.return_length()<<endl;
    
    return 0;
}

