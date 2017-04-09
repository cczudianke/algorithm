//优先队列
/*priority queue是一种用来维护由一组元素构成的集合S的数据结构
  主要有这样的几个操作：
  INSERT(S,x) => 插入x 
  MAXIMUM(s)  => 返回最大值
  EXTARCT-MAX(s) => 删除最大值 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Left(i) 2*(i+1)-1 
#define Right(i) 2*(i+1)
#define Parent(i) (i+1)/2-1 
//这里我们使用堆排序的部分策略来实现priority queue 
struct heap{
	int *mark;//用来标记最初分配的空间的地址，主要用来free内存，防止内存泄露 
	int *a; //现在的策略是，a指向一个数组，也使用malloc动态分配，使可扩展性增加 
	int length; 
	int heapSize;
}heap;
//保持最大堆的性质 
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
//建堆： 
void BUILD_MAX_HEAP(struct heap *A){
	A->heapSize = 0;
	A->length = 100;
	A->a = (int*)malloc(100*sizeof(int));	
}  
void INSERT(struct heap *S,int x){
	//向集合S插入x
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
	S->a = S->a + sizeof(int); //操作简单，但是会导致内存的泄露,一旦操作多了，就会导致严重问题 
	S->heapSize--;
	S->length--;
	//重新调整堆的结构
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
