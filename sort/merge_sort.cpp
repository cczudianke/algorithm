//һ���򵥵�merge_sort��ʵ�֣�˫·�鲢����
/*
�������²��ԣ�
1.��һ������ֳ���������
2.��ÿһ�������������
3���ϲ������Ѿ��ź�������� 
��Ϊ���������������ʵ������Ҫ������Ϊ�ڲ��ϵض������飬���ÿһ��������һ�����������飬ֻ��ʹ��merge��������
����������鲢
�鲢�㷨����Ҫ�Ĳ������� 
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
		_mergesort(a,first,mid,c);			//��߶��� 
		_mergesort(a,mid+1,last,c);			//�ұ߶��� 
		merge(a,first,mid,mid+1,last,c);  //�ϲ���������� 
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
