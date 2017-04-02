//���ȶ���
/*priority queue��һ������ά����һ��Ԫ�ع��ɵļ���S�����ݽṹ
  ��Ҫ�������ļ���������
  INSERT(S,x) => ����x 
  MAXIMUM(s)  => �������ֵ
  EXTARCT-MAX(s) => ɾ�����ֵ 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Left(i) 2*(i+1)-1 
#define Right(i) 2*(i+1)
#define Parent(i) (i+1)/2-1 
//��������ʹ�ö�����Ĳ��ֲ�����ʵ��priority queue 
struct heap{
	int *mark;//��������������Ŀռ�ĵ�ַ����Ҫ����free�ڴ棬��ֹ�ڴ�й¶ 
	int *a; //���ڵĲ����ǣ�aָ��һ�����飬Ҳʹ��malloc��̬���䣬ʹ����չ������ 
	int length; 
	int heapSize;
}heap;
//�������ѵ����� 
void MAX_HEAPIFY(struct heap *A,int i){
	int l = Left(i);
	int r = Right(i);
//	printf("left is %d  right is %d \n",l,r); 
	int largest;
	int j;
	if(l<= A->heapSize && A->a[l]>A->a[i])
		largest = l;
	else 
		largest = i;
	if(r<= A->heapSize && A->a[r]>A->a[largest])
		largest = r;
	if(largest != i){
		int temp;
		temp = A->a[i];
		A->a[i] = A->a[largest];
		A->a[largest] = temp;
		MAX_HEAPIFY(A,largest);
	}
}
//���ѣ� 
void BUILD_MAX_HEAP(struct heap *A){
	A->heapSize = 0;
	A->length = 100;
	A->a = (int*)malloc(100*sizeof(int));	
}  
void INSERT(struct heap *S,int x){
	//�򼯺�S����x
	if(S->heapSize < S->length){
		S->a[S->heapSize] = x;
		S->heapSize++;
	}else{
		int *b = S->a;
		S->a = (int*)malloc(2*S->heapSize*sizeof(int));
		S->length *= 2;
		for(int i=0;i<S->heapSize;i++){
			S->a[i] = b[i];
		}
		S->a[S->heapSize] = x;
		S->heapSize++;
		free(S->mark);
		S->mark = S->a; 
	}
	for(int i=S->heapSize/2;i>=0;i--){
		MAX_HEAPIFY(S,i);
	}	
} 
//return max-value 
int MAXIMUM(struct heap* S){
	return S->a[0];
}
void EXTRACT_MAX(struct heap* S){
	S->a = S->a + sizeof(int); //�����򵥣����ǻᵼ���ڴ��й¶,һ���������ˣ��ͻᵼ���������� 
	S->heapSize--;
	S->length--;
	//���µ����ѵĽṹ
	MAX_HEAPIFY(S,0); 
}
int main(void)
{
	//test 
	struct heap S;
	srand((int)time(NULL));
	BUILD_MAX_HEAP(&S);
	for(int i=0;i<1000000;i++){
		INSERT(&S,rand());
		
	}
	for(int i=0;i<1000000;i++)
		printf("%d ",S.a[i]);
	printf("\n");
	printf("%d",MAXIMUM(&S));
}
