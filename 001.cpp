//#pragma once
#include <iostream>
//#include <unordered_map>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class p {
public:
	double x;
	double y;
};

//#include "d201831.h"

int main() {
	//std::cout << "helloworld,\n" << "jiaotong" << std::endl;

	int n;
	cin >> n;
	vector<p> v1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i].x >> v1[i].y;
	}
	double dmin=sqrt(pow(v1[0].x-v1[1].x,2)+pow(v1[0].y-v1[1].y,2));
	double tem;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n ; j++) {

			tem= sqrt(pow(v1[i].x- v1[j].x,2) + pow(v1[i].y- v1[j].y,2));
			if (tem < dmin) { dmin = tem; }
		}
	}
	cout.fill('0');
	cout.flags(ios::fixed);
	cout.precision(2);
	cout << dmin << endl;

	


	
	system("pause");
	return 0;
}