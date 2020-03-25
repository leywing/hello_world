#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include "iostream"
#include <unistd.h>
using namespace std;
#define SWAP(a,b){a=a+b;b=a-b;a=a-b}

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
    omp_set_num_threads(4);
    int j=100,k=0,i=0;

    int short_len=j/4;
    int m=0,n=0;
    clock_t begin, end;
    double cost;
    srand((unsigned)time( NULL ));
    int len=j;
    int shu=len/2;
    int B[len],C[short_len],D[short_len],E[short_len],F[short_len];

    for(i=0;i<len;i++){
        B[i]=j--;
        }

    for (int i = 0; i < shu; i++)
    {
        swap(B[i],B[i+(rand()%shu)]);
    }
 
    for(i=0;i<short_len;i++){

        C[i]=B[i];
        D[i]=B[i+short_len];
        E[i]=B[i+short_len*2];
        F[i]=B[i+short_len*3];
        }          
    begin = clock();
    int B1[short_len*2],B2[short_len*2];

    //#pragma omp parallel default(none) shared(C,D,short_len) //private(i)------快速排序的并行region
    //{

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
    }

	for(int i=0;i<len/4;i++)
		cout<<E[i]<<"  "<<F[i] <<endl;
	cout<<endl;
    //}
    //#pragma omp parallel sections 
    //{
        //#pragma omp section
        //{
			merge(short_len, C ,D, B1,k);
            //printf("%d \n",1) ;      
        //}
		//#pragma omp section
        //{
			for(int i=0;i<len/4;i++)
				cout<<E[i]<<"  "<<F[i] <<endl;
            merge(short_len,E,F,B2,k);
            //printf("%d \n",2);    
        //}

    //}
	int f[len];
    merge(short_len*2,B1,B2,f,k);
    for(int i=0;i<len;i++)
        cout<<f[i] <<endl;
    end = clock();//----------------计时结束点
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf seconds", cost);//输出运行interval
    cout<<endl;
    return 0;
}
