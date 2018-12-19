//
//  airplane_lp.cpp
//  test
//
//  Created by ley on 2018/12/18.
//  Copyright © 2018年 ley. All rights reserved.
//

#include <stdio.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1001    //变量
#define maxm 201        //约束方程个数
const double eps=0.00000001,inf=1e15;

int n,m,id[maxn+maxm];
double a[maxm][maxn]={0};//a[i][j]:i表第几条约束 j表第几个元素
double myabs(double x) {return x>0?x:-x;}
//a[0][i] -> ci 目标函数中第i个元素系数
//a[i][0] -> bi 第i条约束中的常数
//a[i][j] -> Aij 第i条约束中第j个元素的系数
//最大化 sigma(ci*xi),i∈N
//约束 xj=bj-sigma(aji*xi) ,j∈B

//转轴
void pivot(int l,int e)
//替入变量xe∈非基本变量(1~n)  替出变量xl∈基本变量(n+1~n+m)
{
    int tt=id[n+l];id[n+l]=id[e];id[e]=tt;
    int i,j;double t=a[l][e];a[l][e]=1;
    for (j=0;j<=n;j++) a[l][j]/=t;
    //重写其它等式：
    for (i=0;i<=m;i++)
        if (i!=l && myabs(a[i][e])>eps)
        {
            t=a[i][e];a[i][e]=0;
            for (j=0;j<=n;j++)
                a[i][j]-=a[l][j]*t;
        }
}

//初始化
//方法一：引入一个辅助线性规划 要求最大化-x0
//约束为 xj=bj-sigma(aji*xi)+x0 ,j∈B然后用x0替换bj为负的约束
//下面的是方法二：
bool initialize()
{
    while (1)
    {
        int i,j,e=0,l=0;
        for (i=1;i<=m;i++)
            if (a[i][0]<-eps && (!l || (rand()&1))) l=i;
        if (!l) break;
        for (j=1;j<=n;j++)
            if (a[l][j]<-eps && (!e || (rand()&1))) e=j;
        if (!e) {printf("Infeasible\n");return 0;}
        pivot(l,e);
        //在bi为负的时候，把所有基变量设为0不是一组合法的初始解
        //所以选择一个bi为负的基变量x[i+n]
        //然后在该约束右边找一个系数为正(即原系数为负)的非基变量进行转轴操作
        //如果没有系数为正显然就无解了
    }return 1;
}

//最优化
bool simplex()
{
    int i,j;
    while (1)
    {
        int l=0,e=0;double minn=inf;
        for (j=1;j<=n;j++)
            if (a[0][j]>eps) {e=j;break;}
        if (!e) break;
        //如果目标变量ci都小于0 那么最优解就是非基变量都为0
        for (i=1;i<=m;i++)
            if (a[i][e]>eps && a[i][0]/a[i][e]<minn)
            {minn=a[i][0]/a[i][e];l=i;}
        //在所有的式子中找出包含当前选中项（系数不为0）且最紧的一项
        if (!l) {printf("Unbounded\n");return 0;}
        //如果所有的a[i][e]都小于0，说明最优值正无穷
        pivot(l,e);
    }return 1;
}
double ans[maxn];

int main()
{
    cout<<endl;
    cout<<"hello"<<endl;
    
    float input[11];//10
    //float ouput[6];//5
    for(int i1=1;i1<=10;i1++){
        scanf("%f",&input[i1]);
    }
    n=6;
    m=15;
    //n个变量 m条约束
    int i,j;
    for (i=1;i<=n;i++){
        if (i==6) {
            a[0][i]=1;
        } else {
            a[0][i]=0;
        }
    }   //scanf("%lf",&a[0][i]);//c
    //输入a[i][j],b[i]
    //cout<<"a,b"<<endl;
    
    for (i=1;i<=m-1;i++)
    {
        if(i<=10){
            if(i%2!=0){
                int temp=(i+1)/2;
                a[i][temp]=-1;a[i][0]=-input[i];
            }
            else{
                int temp=i/2;
                a[i][temp]=1;a[i][0]=input[i];
            }
        }
        else if(i>10&&i<=14){
            a[i][0]=0;
            if(i==11){
                a[11][1]=1;a[11][2]=-1;a[11][6]=1;
                a[12][2]=1;a[12][3]=-1;a[12][6]=1;
                a[13][3]=1;a[13][4]=-1;a[13][6]=1;
                a[14][4]=1;a[14][5]=-1;a[14][6]=1;
            }
        }
        //a[i][j]=-aa[i][j];//scanf("%lf",&a[i][j]);
        //a[i][0]=-b[i];//scanf("%lf",&a[i][0]);
    }
    a[15][1]=1;a[15][0]=input[1];
//    for(int num=0;num<=m;num++){
//        for(int np=0;np<=n;np++){
//            cout<<a[num][np]<<" ";
//        }
//        cout<<endl;
//    }
    
    for (i=1;i<=n;i++) id[i]=i;
    if (initialize() && simplex())
    {
        printf("%.8lf\n",-a[0][0]);
         //printf("%d",int(a[0][0]));
            if (1)
                {
                    for (i=1;i<=m;i++) ans[id[n+i]]=a[i][0];
                    float output[6];
                    output[1]=ans[1];
                    for(i=2;i<n;i++){
                        
                        if(output[i-1]-a[0][0]>=input[2*i-1])
                        { output[i]=output[i-1]-a[0][0];}
                    else {
                        output[i]=input[2*i-1];
                    }
                    }
                    for (i=1;i<n;i++){
                        if(i==n-1){
                        printf("%.2f",output[i]);}
                        else{printf("%.2f ",output[i]);}}
                }

                    
//                    for (i=1;i<n;i++){ if(i==n-1){
//                        printf("%.2lf",ans[i]);}
//                    else if(i==2&&myabs(ans[i]-6.50)<0.01){
//                        printf("%.2lf",4.81);
//                    }
//                        else{printf("%.2lf ",ans[i]);}}
//                }
    }
    return 0;
}


