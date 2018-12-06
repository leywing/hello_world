//
//  crossriver.cpp
//  test
//
//  Created by ley on 2018/11/19.
//  Copyright © 2018年 ley. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>


using namespace std;


int main() {
    
    
    int n=0;
    scanf("%d",&n);
    int limit=0;
    scanf("%d",&limit);
    vector<int> people(n);
    for(int i=0;i<n;i++){
        scanf("%d",&people[i]);
    }
    sort(people.begin(),people.begin()+n);
   //从小到大排序 a[0]是最小的
    int numofship=0;
    int min=0;
    int max=0;
    for(int j=n-1;j>=0&&j>min;){
        if(people[j]+people[min]<=limit){
            min++;
            numofship++;
        }
        else{
            numofship++;
        }
        j--;
        max=j;
    }
    if(max==min)numofship++;
    
    printf("%d",numofship);
   
    
    
    
    return 0;
}
