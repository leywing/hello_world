//#include "d201831.h"

#include <iostream>
#include <algorithm>

int q[5000002];

using namespace std;

int main() {
	

	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> q[i];
	sort(q, q + n );

	cout << q[n - m];
	


	

	system("pause");
	return 0;
}