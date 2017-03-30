// heapsort
/* heapsort的基本策略：
1.首先建立最大堆
2.从最大堆中找到最大的元素(即第一个元素)和最后一个元素交换
3.对新生成的堆使用MAX-HEAPIFY,恢复最大堆的性质
4.重复操作
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Left(i) 2*(i+1)-1 
#define Right(i) 2*(i+1)
#define Parent(i) (i+1)/2-1 
//二叉堆是一个数组，他可以被看成是一个近似的完全二叉树。
//除了树的最底层以外，该树是完全充满的，而且是从左向右填充 
//表示堆的数组一般有两个性质，A.length表示数组元素的个数，A.heap-size表示有多少个堆元素存储在数组里 
struct heap{
	int *a; //现在的策略是，a指向一个数组，也使用malloc动态分配，使可扩展性增加 
	int length; 
	int heapSize;
}heap; 
//函数MAX-HEAPIFY用来保持堆的性质 
//不断地将当前节点和子节点相比较，直到完成该子树的MAX-HEAP性质的调整 ，复杂度O(lgn)，即树的高度 
void MAX_HEAPIFY(struct heap *A,int i){
	int l = Left(i);
	int r = Right(i);
	printf("left is %d  right is %d \n",l,r); 
	int largest;
	int j;
	if(l<= A->heapSize && A->a[l]>A->a[i])
		largest = l;
	else 
		largest = i;
	if(r<= A->heapSize && A->a[r]>A->a[largest])
		largest = r;
		printf("\n");
	if(largest != i){
		int temp;
		temp = A->a[i];
		A->a[i] = A->a[largest];
		A->a[largest] = temp;
		MAX_HEAPIFY(A,largest);
	}
}
//建堆：将一个大小为A.lenght的数组转化为最大堆，O(n) 
void BUILD_MAX_HEAP(struct heap *A,int a[],int n){
	A->heapSize = n;
	A->length = n;
	int i;
	A->a = a;
	//根据堆的性质：n/2+1...n节点都是树的叶子节点，每个叶子结点可以看作只包含一个元素的堆。 
	for(i=n/2; i>=0; i--){
		MAX_HEAPIFY(A,i);
		//调用MAX-HEAPIFY时假设当前的节点的左右子树都是堆，只有从下向上调用才能满足前提。(堆从左向右填充 ) 
	}
	
} 
void HEAPSORT(struct heap *A){
	int temp;
	int i;
	for(i=A->length; i>=1; i--){
		temp = A->a[i];
		A->a[i] = A->a[0];
		A->a[0] = temp;
		A->heapSize = A->heapSize - 1;
		printf("heapSize :%d",A->heapSize);
		MAX_HEAPIFY(A,0); 
	}
}
int main(void)
{
	int a[10],cnt;
	struct heap A;
	int i;
	srand((int)time(NULL));
	for(cnt=0;cnt<10;cnt++)
		a[cnt] = rand();
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	BUILD_MAX_HEAP(&A,a,sizeof(a)/sizeof(int)-1);
	printf("success\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	HEAPSORT(&A);
	for(i=0;i<10;i++){
		printf("%d ",A.a[i]);
	}
	printf("\n%d",A.heapSize);
	return 0;	
}		
		
	

 
