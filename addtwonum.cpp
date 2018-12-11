//
//  addtwonum.cpp
//  test
//
//  Created by ley on 2018/12/11.
//  Copyright © 2018年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode* forward;
    ListNode(int x):val(x),next(nullptr),forward(nullptr){};
};






ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int n1=0;
        int n2=0;
        ListNode* temp;
        temp=l1;
        while(temp!=nullptr){
            n1++;
            temp=temp->next;
        }
        temp=l2;
        while(temp!=nullptr){
            n2++;
            temp=temp->next;
        }
        ListNode* result=new ListNode(0);
        ListNode* head=result;
        int jinwei=0;
        int tempint=0;
        int max=n1>n2?n1:n2;
        for(int i=0;i<max;i++){
            if(l1!=nullptr&&l2!=nullptr){
                tempint=l1->val+l2->val+jinwei;
                jinwei=tempint<10?0:1;
                result->val=tempint-(jinwei*10);
                l1=l1->next;
                l2=l2->next;
            }else if (l1!=nullptr){
                tempint=l1->val+jinwei;
                jinwei=tempint<10?0:1;
                result->val=tempint-(jinwei*10);
                l1=l1->next;
            }else if (l2!=nullptr){
                tempint=l2->val+jinwei;
                jinwei=tempint<10?0:1;
                result->val=tempint-(jinwei*10);
                l2=l2->next;
            }
            if(i!=max-1){
            result->next=new ListNode(0);
            result=result->next;
            }else{
                if(jinwei==1){
                    result->next=new ListNode(1);
                    result=result->next;
                }
            }
        }
     
        return head;
        
       //result 没删
    }


int main(){
    
    ListNode one(4);//没删
    ListNode* l1=&one;
    l1->next=new ListNode(5);
    ListNode two(7);
    ListNode* l2=&two;//没删
    l2->next=new ListNode(6);
    
    ListNode* resu=addTwoNumbers(l1, l2);
    while(resu!=nullptr){
        cout<<resu->val<<" ";
        resu=resu->next;
    }
    
    return  0;
}

