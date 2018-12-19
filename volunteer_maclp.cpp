//
//  volunteer_maclp.cpp
//  test
//
//  Created by ley on 2018/12/18.
//  Copyright © 2018年 ley. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
#define M 10000
//全局变量
float kernel[11][31];//核心矩阵表
int m = 0, n = 0, t = 0;//m:结构向量的个数
//n:约束不等式个数
//t:目标函数类型：－1代表求求最小值，1代表求最大值
//输入接口函数
void input()
{
    //读入所求问题的基本条件
    cout << "－－－－－－－－－－参 数 输 入－－－－－－－－－－－" << endl;
    cout << "请按提示输入下列参数：" << endl << endl;
    cout << "  结构向量数m:  " << "   m=  ";
    cin >> m;
    cout << endl << "  约束不等式数n:" << "   n=  ";
    cin >> n;
    int i, j;
    //初始化核心向量
    for (i = 0; i <= n + 1; i++)
        for (j = 0; j <= m + n + n; j++)
            kernel[i][j] = 0;
    //读入约束条件
    cout << endl << "  约束方程矩阵的系数及不等式方向（1代表<=,-1代表>=）:" << endl << endl << "          ";
    for (i = 1; i <= m; i++)
        cout << "   x" << i;
    cout << "  不等式方向 " << " 常数项" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "    不等式" << i << "  ";
        for (j = 1; j <= m + 2; j++)
            cin >> kernel[i][j];
    }
    
    for (i = 1; i <= n; i++)
    {
        kernel[i][0] = kernel[i][m + 2];
        kernel[i][m + 2] = 0;
    }
    //读入目标条件
    cout << endl << endl << " 目标函数的系数及类型（求最小值:1；求最大值:-1）:" << endl << endl << "                ";
    for (i = 1; i <= m; i++)
        cout << "x" << i << "   ";
    cout << "类型" << endl << "  ";
    cout << "  目标函数:   ";
    for (i = 1; i <= m; i++)
        cin >> kernel[0][i];
    cin >> t;
    //矩阵调整
    if (t == -1)
        for (i = 1; i <= m; i++)
            kernel[0][i] = (-1)*kernel[0][i];
    for (i = 1; i <= n; i++)
    {
        kernel[i][m + i] = kernel[i][m + 1];
        if (i != 1)
            kernel[i][m + 1] = 0;
    }
}

//算法函数
void comput()
{
    int i, j, flag, temp1, temp2, h, k = 0, temp3[10];
    float a, b[11], temp, temp4[11], temp5[11], f = 0, aa, d, c;
    //初始化
    for (i = 1; i <= n; i++)
        temp3[i] = 0;
    for (i = 0; i < 11; i++)
    {
        temp4[i] = 0;
        temp5[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        if (kernel[i][m + i] == -1)
        {
            kernel[i][m + n + i] = 1;
            kernel[0][m + n + i] = M;
            temp3[i] = m + n + i;
        }
        else
            temp3[i] = m + i;
    }
    for (i = 1; i <= n; i++)
        temp4[i] = kernel[0][temp3[i]];
    
    //循环求解
    do {
        for (i = 1; i <= m + n + n; i++)
        {
            a = 0;
            for (j = 1; j <= n; j++)
                a += kernel[j][i] * temp4[j];
            kernel[n + 1][i] = kernel[0][i] - a;
        }
        for (i = 1; i <= m + n + n; i++)
        {
            if (kernel[n + 1][i] >= 0) flag = 1;
            else
            {
                flag = -1;
                break;
            }
        }
        if (flag == 1)
        {
            for (i = 1; i <= n; i++)
            {
                if (temp3[i] <= m + n) temp1 = 1;
                else
                {
                    temp1 = -1;
                    break;
                }
            }
            //输出结果
            cout << endl << endl;
            cout << "－－－－－－－－－－结 果 输 出－－－－－－－－－－－" << endl << endl;
            if (temp1 == 1)
            {
                cout << " 此线性规划的最优解存在!" << endl << endl << "  最优解为：" << endl << endl << "     ";
                for (i = 1; i <= n; i++)
                    temp5[temp3[i]] = kernel[i][0];
                for (i = 1; i <= m; i++)
                    f += t*kernel[0][i] * temp5[i];
                
                for (i = 1; i <= m; i++)
                {
                    cout << "x" << i << " = " << temp5[i];
                    if (i != m)
                        cout << "， ";
                }
                cout << " ;" << endl << endl << "     最优目标函数值f= " << f << endl << endl;
                return;
            }
            else
            {
                cout << " 此线性规划无解" << endl << endl;
                return;
            }
        }
        if (flag == -1)
        {
            temp = 100000;
            for (i = 1; i <= m + n + n; i++)
                if (kernel[n + 1][i] < temp)
                {
                    temp = kernel[n + 1][i];
                    h = i;
                }
            
            for (i = 1; i <= n; i++)
            {
                if (kernel[i][h] <= 0) temp2 = 1;
                else {
                    temp2 = -1;
                    break;
                    
                }
            }
        }
        if (temp2 == 1)
        {
            cout << "此线性规划无约束";
            return;
        }
        if (temp2 == -1)
        {
            c = 100000;
            for (i = 1; i <= n; i++)
            {
                if (kernel[i][h] != 0)  b[i] = kernel[i][0] / kernel[i][h];
                if (kernel[i][h] == 0)  b[i] = 100000;
                if (b[i] < 0)     b[i] = 100000;
                if (b[i] < c)
                {
                    c = b[i];
                    k = i;
                }
            }
            temp3[k] = h;
            temp4[k] = kernel[0][h];
            d = kernel[k][h];
            for (i = 0; i <= m + n + n; i++)
                kernel[k][i] = kernel[k][i] / d;
            for (i = 1; i <= n; i++)
            {
                if (i == k)
                    continue;
                aa = kernel[i][h];
                for (j = 0; j <= m + n + n; j++)
                    kernel[i][j] = kernel[i][j] - aa*kernel[k][j];
            }
        }
    } while (1);
    return;
}

int main()
{
    cout << "-------------------单纯形算法程序----------------------" << endl << endl;
    input();
    comput();
    system("pause");
    return 1;
}
