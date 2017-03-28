/*************************************************************************
	> File Name: counting_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/28 20:22:33 2017
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
//counting_sort的实现原理：假设输入的数据是大小在[0..K]的一组数
//使用C[i]记录小于等于i的数的数目，既可以用B[C[A[j]]]=A[j]来安排A[j]的位置
//计数排序是一个稳定的排序算法，算法复杂度为O(n)
//假设输入为A[1..n],B[1..n]存放排序的输出,C[0..K]提供临时存储
//算法的实现中最重要的一点是找到K,这里我使用find_K来找到最大值K
int find_K(int *A,int n)
{
    int max=0;//最小值肯定大于0
    for(int i=1;i<=n;i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
}
//counting_sort
void counting_sort(int *A,int *B,int n){
    //首先获得K的值并创建新数组C[0..K]
    int K = find_K(A,n);
    cout<<K<<endl;
    int *C = (int*)malloc(K*sizeof(int));
    for(int i = 0;i<= K;i++){
        C[i] = 0;
    }
    for(int j = 1;j<= n;j++){
        C[A[j]] = C[A[j]] + 1;
    }
    for(int i = 1;i<= K; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j = n;j >=1; j--){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] -1;
    }
    free(C);
}
//test
int main(void)
{
    int A[]={0,2,4,5,6,1,4,8,23,12};
    int B[10];
    counting_sort(A,B,9);
    for(int i=1;i<=9;i++){
        cout<<B[i]<<endl;
    }
    return 0;
}
