//
//  main.cpp
//  test
//
//  Created by ley on 2018/11/19.
//  Copyright © 2018年 ley. All rights reserved.
//


#include "Header.h"
#include "listnode_oneway.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a={1,3,4,6};
//    for(int i=0;i<4;i++)
//    {cin>>a[i];}
//    cout<<a[1]<<" "<<a[0]<<endl;
    
//    int a1=3,b1=5;
//    printf("%d\n",maxme(a1, b1));
    
    Solution a2;
    vector<int> res(2);
    res=a2.twoSum(a, 5);
    
    for(int i=0;i<res.size();i++)
        printf("%d ",res[i]);
    
    printf("\nit's over;\n");
    
    return 0;
}
