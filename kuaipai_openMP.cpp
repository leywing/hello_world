#include <cstdio>
#include <ctime>
#include <omp.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
#define N 50040000

int A[N], f[N], LC[N], RC[N], ans[N], cnt;
int n;// length of sequence
int th;// number of thread
void output(int i)
{
	if (i >= n) return;
	output(LC[i]);
	ans[cnt++] = A[i];
	output(RC[i]);
}

int main()
{
	//cout << "sizeof(int) "<<sizeof(int) << endl;
	int i, root;
	bool flag = false;
	double f1, f2;
	int T = 12;
	while (scanf("%d%d", &n, &th) != EOF) // input the length of sequence and number of thread
	{
		cnt = 0;
		//generate the original sequence
		srand(time(0));
		for (i = 0; i < n; ++i) A[i] = rand();

		//printf("generate rand finish!!!!!");
	
		time_t first, second;
		first = clock();
		//printf("%d", first);
		omp_set_num_threads(th);
#pragma omp parallel private(i) shared(root)
		{
#pragma omp for 
			for (i = 0; i < n; ++i)
			{
				root = i;// compete to be the root of the balance tree
				LC[i] = RC[i] = n + 1;
			}
#pragma omp for
			for (i = 0; i < n; ++i)
				f[i] = root;
		}

#pragma omp parallel private(i,flag) shared(A,f,LC,RC)
		{
#pragma omp for
			for (i = 0; i < n; ++i)
				if (i != root)
				{
					flag = false;
					while (!flag)
					{
						if (A[i] < A[f[i]] || A[i] == A[f[i]] && i < f[i]) //go to left
						{
							if (LC[f[i]] > n)// if no left child
							{
								LC[f[i]] = i;
								flag = true;
							}
							else f[i] = LC[f[i]];
						}
						else //go to right
						{
							if (RC[f[i]] > n)// if no right child
							{
								RC[f[i]] = i;
								flag = true;
							}
							else f[i] = RC[f[i]];
						}
					}
				}
		}
		output(root); // recursively get the sorted sequence
		second = clock();
		printf("n is %d\n", n);
		printf("parallel time is %lf\n", f1 = (second - first) * 1.0 / CLOCKS_PER_SEC);
		//for (int i = 0; i < n; i++) {
		//	cout << ans[i] << endl;
		//}
		first = clock();
		sort(A, A + n);
		second = clock();
		printf("sequence time is %lf\n", f2 = (second - first) * 1.0 / CLOCKS_PER_SEC);
		printf("rate is %lf\n", f2 / f1);
	}
	return 0;
}

