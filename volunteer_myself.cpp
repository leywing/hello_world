//
//  volunteer_myself.cpp
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
double a[maxm][maxn];//a[i][j]:i表第几条约束 j表第几个元素
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
    //
    //cout<<endl;
    //cout<<"hello"<<endl;
    //int n=0,m=0;
    int b[201]={0};
    int first[1001][4]={0};
    int aa[201][1001]={0};
    scanf("%d",&m);
    scanf("%d",&n);
    //cout<<"b"<<endl;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    //cout<<"first"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&first[i][j]);
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=first[i][1];j<=first[i][2];j++){
            aa[j][i]=1;
        }
    }
    //
    //    for(int i=1;i<=n;i++){
    //        for(int j=1;j<=m;j++){
    //            cout<<aa[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    
    //
    
    //    cout<<"n,m,t(0,1)"<<endl;
    //    int t,i,j;
    //    scanf("%d%d%d",&n,&m,&t);
    //n个变量 m条约束
    int i,j;
    //cout<<"c"<<endl;
    for (i=1;i<=n;i++) a[0][i]=-first[i][3];   //scanf("%lf",&a[0][i]);//c
    //输入a[i][j],b[i]
    //cout<<"a,b"<<endl;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
            a[i][j]=-aa[i][j];//scanf("%lf",&a[i][j]);
        a[i][0]=-b[i];//scanf("%lf",&a[i][0]);
    }
    for (i=1;i<=n;i++) id[i]=i;
    if (initialize() && simplex())
    {
        //printf("%.8lf\n",-a[0][0]);
        printf("%d",int(a[0][0]));
        //        if (t)
        //        {
        //            for (i=1;i<=m;i++) ans[id[n+i]]=a[i][0];
        //            for (i=1;i<=n;i++) printf("%.8lf ",ans[i]);
        //        }
    }
    return 0;
}


