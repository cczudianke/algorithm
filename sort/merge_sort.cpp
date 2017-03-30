//一个简单的merge_sort的实现，双路归并排序
/*
考虑如下策略：
1.将一个数组分成两个部分
2.对每一个数组进行排序
3，合并两个已经排好序的数组 
因为这里的数组排序其实并不需要做，因为在不断地二分数组，最后每一个数就是一个单独的数组，只需使用merge操作即可
将两个数组归并
归并算法中主要的操作在于 
merge(a[],i,j,p,q,c[])
{
	int k = m = i;
	while(i<=j && p<=q){
		if(a[i]<a[p]){
			c[k++] = a[i++];
		}else
			c[k++] = a[p++];		
	}
	while(i<=m){
		c[k++] = a[i++];
	}
	while(p<=q){
		c[k++] = a[p++];
	}
	while(m<k){
		a[m++] = c[m++];
	}
}
*/ 
#include<stdio.h> 
void merge(int a[],int i,int j,int p,int q,int c[])
{
	int k = i;
	int m = i;
	int cnt = i;
	while(i<=j && p<=q){
		if(a[i]<a[p]){
			c[k++] = a[i++];
		}else
			c[k++] = a[p++];		
	}
	while(i<=j){
		c[k++] = a[i++];
	}
	while(p<=q){
		c[k++] = a[p++];
	}
	while(m<k){
		a[m] = c[m];
//		printf("%d ",a[m++]);
		m++;
	}
	
}

void _mergesort(int a[],int first,int last,int c[]){
	if(first<last){
		int mid = (first+last)/2;
//		printf("%d\n",last);
		_mergesort(a,first,mid,c);			//左边二分 
		_mergesort(a,mid+1,last,c);			//右边二分 
		merge(a,first,mid,mid+1,last,c);  //合并有序的数组 
	}
}
bool MergeSort(int a[],int n){
	int *c = new int[n];
//	printf("%x",c);
	if(c == NULL){
		return 0;
	} 
	_mergesort(a,0,n-1,c);
}
int main(void){
	
	int a[]={1,4,56,7,3,7,9,10,3,6};
	MergeSort(a,10); 
	int n = 0;
	printf("\n");
	while(n<10){
		printf("%d ",a[n++]);
	}
	return 0;
} 
