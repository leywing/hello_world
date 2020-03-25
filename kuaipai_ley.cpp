#include <cstdio>
#include <ctime>
#include <omp.h>
#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;
//#define N 2147000000
#define N 10040000


int main() {
	
	int A[N];
	int n;
	while (scanf("%d", &n) != EOF) {
		srand(time(0));
		for (int i = 0; i < n; i++) {
			A[i] = rand();
		}
		cout << A[7] << endl;
		cout << rand() << endl;

	}

	cout << "当前可用处理器个数  "<<omp_get_num_procs() << endl;

	
}