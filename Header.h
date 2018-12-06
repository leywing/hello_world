//
//  Header.h
//  test
//
//  Created by ley on 2018/11/19.
//  Copyright © 2018年 ley. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



template <typename T>
T maxme(T a,T b) {
    return a>b?a:b;
}

//Definition for singly-linked list.
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int numl1=0;
        int numl2=0;
        
        ListNode* temp;
        temp=l1;
        while(temp->next!=nullptr){
            numl1=numl1+1;
            temp=temp->next;
        }
        temp=l2;
        while(temp->next!=nullptr){
            numl2=numl2+1;
            temp=temp->next;
            
        }
        int dist=numl1-numl2;
        ListNode* head;
        ListNode* p1;
        head=p1;
        if(dist>0){
            for(;dist>=1;dist--){
                
              
                
            }
        }
        
        ListNode* temp002;
        int a=0;
        for(i)
            temp.val=l1.val+l2.val;
        if(temp>=10) a=1;
        else a=0;
        temp.val=temp.val-a*10;
        
    }
};



#endif /* Header_h */
