//
//  monkeybanana.cpp
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
    vector<int> monkey;
    char s='a';
    int temp=0;
    while(s!='\n'){
        scanf("%d",&temp);
        monkey.push_back(temp);
        s=getchar();
        n++;
    }
    vector<int> banana(n);
    for(int i=0;i<n;i++){
        scanf("%d",&banana[i]);
    }
    
    sort(monkey.begin(), monkey.begin()+n);
    sort(banana.begin(),banana.begin()+n);
    int max=0;
    for(int i=0;i<n;i++){
        monkey[i]=abs(monkey[i]-banana[i]);
        if(i==0){max=monkey[0];}
        else{
            max=max>monkey[i]?max:monkey[i];
        }
    }
    
   
    printf("%d",max);
    
    
    
    
    
    
    return 0;
}

