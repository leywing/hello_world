//
//  leetcode3_longestsubstring.cpp
//  test
//
//  Created by ley on 2018/12/11.
//  Copyright © 2018年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mymap;
    for(int i=0;i<nums.size();i++){
        mymap[nums[i]]=i;
    }
    vector<int> result(2);
    for(int i=0;i<nums.size();i++){
        int t=target-nums[i];
        if(mymap.count(t)&&mymap[t]!=i){
            result[0]=i;
            result[1]=mymap[t];
            return result;
        }
    }
    return result;
}

int lengthOfLongestSubstring(string s) {
    
    unordered_map<char, int> mymap;
    
    
    
    
    
    
    
}
