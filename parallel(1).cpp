#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include "iostream"
//#include <unistd.h>
#include <ctime>
using namespace std;
#define SWAP(a,b){a=a+b;b=a-b;a=a-b}
#define N 20000000
int B[N],C[N/4],D[N/4],E[N/4],F[N/4],A[N];
int B1[N/2],B2[N/2];
int f[N];
void MedianOfThree (int * a,int l,int m , int r){
    if(a[m]> a[r])
        swap(a[m],a[r]);
    if(a[l]> a[r])
        swap(a[l],a[r]);
    if(a[l]> a[m])
        swap(a[l],a[m]);
    swap(a[m],a[l]);
}
void merge(int short_len,int *C,int *D,int *B,int k)
{
    int m=0,n=0 ;
    for(;k<short_len*2;k++)
    {
        if(m < short_len && n < short_len)
        {   //cout<<" C "<< C[n] <<" D " <<D[m]<<endl;       
            if(C[n]<=D[m])
            {
                B[k] = C[n];
                n++;
            }
            else
            {
                B[k]=D[m];
                m++;
            }
        }
    if(m==short_len || n==short_len)
    {
        if(m==short_len)
            B[k]=D[m-1];
        else
            B[k]=C[n-1];
        k+=1;
        break;
    }
    }
    if(n<short_len)
    {
        int tem=short_len-n;
        for(int p=0;p<tem;p++)
        {
            B[k]=C[n];
            n++;
            k++;
        }
    }
    else if(m<short_len)
    {
        int tem=short_len-m;
        for(int q=0;q<tem;q++)
        {
            B[k]=D[m];
            m++;
            k++;
        }
    }
}
void quicksort(int *A,int l, int u){
    
    int i,m,k;
    if (l >= u) return;
	MedianOfThree(A,l,l+((u-l)>>1),u);
    m = l;
    for (i = l+1; i <= u; i++)
    {
        if (A[i] < A[m])
        {   
            swap(A[m+1], A[i]);
            swap(A[m+1], A[m]);
            m=m+1;
        }
    }    
    quicksort(A,l, m-1);
    quicksort(A,m+1, u);
    }

int main() 
{
	///*int ley[3] = { 8,10,5 };
	//MedianOfThree(ley, 0, 1, 2);
	//for (int i = 0; i < 3; i++) {
	//	cout << ley[i] << endl;
	//}*/
	//cout << "ending" << endl;
    omp_set_num_threads(4);
    int j=N,k=0,i=0;

    int short_len=j/4;
    int m=0,n=0;
   // clock_t begin, end;
	time_t begin, end;
	time_t serial_begin, serial_end;

	double cost;

	srand(time(0));
   // srand((unsigned)time( NULL ));
    int len=j;
    int shu=len/2;


    /*for(i=0;i<len;i++){
        B[i]=j--;
        }

    for (int i = 0; i < len; i++)
    {
        swap(B[i],B[(rand()%len-1)]);
    }*/
 
	for (int i = 0; i < j; i++) {
		B[i] = A[i] = rand();
	}
    for(i=0;i<short_len;i++){

        C[i]=B[i];
        D[i]=B[i+short_len];
        E[i]=B[i+short_len*2];
        F[i]=B[i+short_len*3];
        } 

      
    begin = clock();


    // #pragma omp parallel default(none) shared(C,D,E,F,short_len) //private(i)------快速排序的并行region
    // {

    #pragma omp parallel sections 
    {
        #pragma omp section
        {
            quicksort(C, 0, short_len-1);//对C[]排序
            //printf("%d \n",1) ;      
        }
        #pragma omp section
        {
            quicksort(D, 0, short_len-1);//对D[]排序
            //printf("%d \n",2);    
        }
        #pragma omp section
        {
            quicksort(E, 0, short_len-1);//对C[]排序
            //printf("%d \n",3) ;      
        }
        #pragma omp section
        {
            quicksort(F, 0, short_len-1);//对C[]排序
            //printf("%d \n",4) ;      
        }
    // }



    }
    #pragma omp parallel sections 
    {
        #pragma omp section
        {
			merge(short_len, C ,D, B1,k);     
        }
		#pragma omp section
        {
            merge(short_len,E,F,B2,k);    
        }

    }
	
    merge(short_len*2,B1,B2,f,k);
    //  for(int i=0;i<len;i++)
    //      cout<<f[i] <<endl;
    end = clock();//----------------计时结束点
    //cost = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%lf seconds", cost);//输出运行interval
	double f1, f2;

	//printf("n is %d\n", n);
	printf("parallel time is %lf\n", f1 = (end - begin) * 1.0 / CLOCKS_PER_SEC);

	serial_begin = clock();
	quicksort(A,0,N-1);
	serial_end = clock();
	printf("sequence time is %lf\n", f2 = (serial_end - serial_begin) * 1.0 / CLOCKS_PER_SEC);
	printf("rate is %lf\n", f2 / f1);

    cout<<endl;
    return 0;
}
