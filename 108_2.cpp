//#include "d201831.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#define l 0
#define r 1
using namespace std;



double dmin;

class p {
public:
	int dex;
	double x;
	double y;
};

p ve[100002];
p bt[100002];

int compa(p a, p b) {
	return a.x < b.x;
}
int compa_y(p a, p b) {
	return a.y < b.y;
}

double min(double a, double b) {
	return a<b ? a : b;
}

double dis(int a, int b) {
	double tem;
	tem = sqrt(pow(ve[b].x - ve[a].x, 2) + pow(ve[b].y - ve[a].y, 2));
	return tem;
}






double fen(int a, int b) {
	//if (b - a == 0) { return 0; }
	if ((b - a) == 1)
	{
		dmin = min(dmin, dis(a, b));
	}
	if (b - a == 2) {
		dmin = min(dis(a, b), dmin);
		dmin = min(dis(a, a + 1), dmin);
		dmin = min(dis(a + 1, b), dmin);
	}
	if (b - a >2) {
		int zhong = a+((b - a) / 2);
		fen(a, zhong);
		fen(zhong + 1, b);
		int num = 0;
		for (int i = zhong; i >= a; i--) {
			double lengthleft;
			lengthleft = ve[zhong].x - ve[i].x;
			if (lengthleft >= dmin) break;
			bt[num].dex = l;
			bt[num].x = ve[i].x;
			bt[num].y = ve[i].y;
			num++;

		}
		for (int i = zhong + 1; i <= b; i++) {
			double lengthright = ve[i].x - ve[zhong + 1].x;
			if (lengthright >= dmin) break;
			bt[num].dex = r;
			bt[num].x = ve[i].x;
			bt[num].y = ve[i].y;
			num++;
		}

		sort(bt, bt + num, compa_y);
		for (int i = 0; i < num; i++) {
			for (int j = 1; (j <= 7 && i + j < num); j++) {
				if (bt[i].dex != bt[i + j].dex) {
					double tem;
					tem = sqrt(pow(bt[i+j].x - bt[i].x, 2) + pow(bt[i+j].y - bt[i].y, 2));
					dmin = min(dmin, tem);
				}
			}
		}


	}

	return dmin;
}




int main() {

	int n;
	scanf("%d", &n);

	
	for (int i = 0; i < n; i++)
		scanf("%lf%lf",&ve[i].x,&ve[i].y);
	

	sort(ve, ve+ n, compa);
	
	//dmin= sqrt(pow(ve[0].x - ve[1].x, 2) + pow(ve[0].y - ve[1].y, 2));

	dmin=fen(0,n);
	/*for (int i = 0; i < n; i++)
		printf("%d %lf %lf \n", i, ve[i].x, ve[i].y);*/
	


	
	cout.fill('0');
	cout.flags(ios::fixed);
	cout.precision(2);
	cout << dmin << endl;





	system("pause");
	return 0;
}