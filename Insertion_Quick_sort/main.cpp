//
//  main.cpp
//  Insertion_Quick_sort
//
//  Created by 张越 on 2018/3/8.
//  Copyright © 2018年 Yue Zhang. All rights reserved.
//

#include<iostream>
#include <cmath>
#include <time.h>

using namespace std;


int partition(int *A, int p, int r) {
//    for(int i=0;i<r-p+1;i++){
//        cout<<A[i]<<"  ";
//    }
//    cout<<endl;
    int x, i, j, tmp;
    
    x = A[r];
    i = p-1 ;
    
    for (j = p; j < r ; j++) {
        if (A[j] <= x) {
            i = i+1;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
//    for(int i=0;i<r-p+1;i++){
//        cout<<A[i]<<"  ";
//    }
//    cout<<endl;
    return i+1;
}


void insert_sort(int *A ,int n)
{
    int key,j;
    for(int i=1;i<n;++i){
        key=A[i];
        j=i-1;
        while(j>=0 && key<A[j]){
            A[j+1]=A[j];
            --j;
        }
        A[j+1]=key;
    }
}



void modified_quicksort(int *A, int p, int r, int k) {
    if (p<r) {
        if (r - p < k) {
            insert_sort(A+p, r-p+1);
        }
        else{
            int q = partition(A, p, r);
            modified_quicksort(A, p, q-1, k);
            modified_quicksort(A, q + 1, r, k);
        }
    }
}

void quicksort(int *A, int p, int r) {
    if (p<r) {
            int q = partition(A, p, r);
            quicksort(A, p, q-1);
            quicksort(A, q + 1, r);
    }
}


int main()
{
    for(int i = 0;i<=50;i++)
    {
        int n;
        n=pow(10, 7);
        int * a=new int[n];
        int * b=new int[n];
        int * c=new int[n];

        for(int j=0;j<n;j++){          //random permutation array；
            a[j]=rand()%n;
            b[j]=rand()%n;
            c[j]=rand()%n;
        }

        //int k = pow(2, i);
        int k = i;
        clock_t start,finish;          //Program counter;
        start = clock();               //Start time
        modified_quicksort(a, 0, n-1, k);   //Repeat execution 3 times;
        modified_quicksort(b, 0, n-1, k);
        modified_quicksort(c, 0, n-1, k);
        //quicksort(a,0,n-1);
        //insert_sort(a, n);
        finish = clock();              //Termaination;
        long time = 1000/3 * (finish - start)/CLOCKS_PER_SEC;  //Average time;
        cout<<"time: "<<time<<"ms   "<<"when k = "<<k<<endl;
        delete [] a;
        delete [] b;
        delete [] c;
    }
}
