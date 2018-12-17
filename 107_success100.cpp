

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>


using namespace std;

int main() {


	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		scanf("%d",&vec[i]);
	sort(vec.begin(), vec.begin() + n);

	printf("%d",vec[n - m]);





	system("pause");
	return 0;
}