#include<iostream>
#include<cmath>
using namespace std;
#define M 10000
//ȫ�ֱ���   
float kernel[11][31];//���ľ����   
int m = 0, n = 0, t = 0;//m:�ṹ�����ĸ���   
						//n:Լ������ʽ����   
						//t:Ŀ�꺯�����ͣ���1����������Сֵ��1���������ֵ   
						//����ӿں���   
void input()
{
	//������������Ļ�������   
	cout << "���������������������� �� �� �룭��������������������" << endl;
	cout << "�밴��ʾ�������в�����" << endl << endl;
	cout << "  �ṹ������m:  " << "   m=  ";
	cin >> m;
	cout << endl << "  Լ������ʽ��n:" << "   n=  ";
	cin >> n;
	int i, j;
	//��ʼ����������   
	for (i = 0; i <= n + 1; i++)
		for (j = 0; j <= m + n + n; j++)
			kernel[i][j] = 0;
	//����Լ������   
	cout << endl << "  Լ�����̾����ϵ��������ʽ����1����<=,-1����>=��:" << endl << endl << "          ";
	for (i = 1; i <= m; i++)
		cout << "   x" << i;
	cout << "  ����ʽ���� " << " ������" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "    ����ʽ" << i << "  ";
		for (j = 1; j <= m + 2; j++)
			cin >> kernel[i][j];
	}

	for (i = 1; i <= n; i++)
	{
		kernel[i][0] = kernel[i][m + 2];
		kernel[i][m + 2] = 0;
	}
	//����Ŀ������   
	cout << endl << endl << " Ŀ�꺯����ϵ�������ͣ�����Сֵ:1�������ֵ:-1��:" << endl << endl << "                ";
	for (i = 1; i <= m; i++)
		cout << "x" << i << "   ";
	cout << "����" << endl << "  ";
	cout << "  Ŀ�꺯��:   ";
	for (i = 1; i <= m; i++)
		cin >> kernel[0][i];
	cin >> t;
	//�������   
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

//�㷨����   
void comput()
{
	int i, j, flag, temp1, temp2, h, k = 0, temp3[10];
	float a, b[11], temp, temp4[11], temp5[11], f = 0, aa, d, c;
	//��ʼ��   
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

	//ѭ�����   
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
			//������   
			cout << endl << endl;
			cout << "���������������������� �� �� ������������������������" << endl << endl;
			if (temp1 == 1)
			{
				cout << " �����Թ滮�����Ž����!" << endl << endl << "  ���Ž�Ϊ��" << endl << endl << "     ";
				for (i = 1; i <= n; i++)
					temp5[temp3[i]] = kernel[i][0];
				for (i = 1; i <= m; i++)
					f += t*kernel[0][i] * temp5[i];

				for (i = 1; i <= m; i++)
				{
					cout << "x" << i << " = " << temp5[i];
					if (i != m)
						cout << "�� ";
				}
				cout << " ;" << endl << endl << "     ����Ŀ�꺯��ֵf= " << f << endl << endl;
				return;
			}
			else
			{
				cout << " �����Թ滮�޽�" << endl << endl;
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
			cout << "�����Թ滮��Լ��";
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
	cout << "-------------------�������㷨����----------------------" << endl << endl;
	input();
	comput();
	system("pause");
	return 1;
}