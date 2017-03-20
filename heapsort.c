// heapsort
/* heapsort�Ļ������ԣ�
1.���Ƚ�������
2.���������ҵ�����Ԫ��(����һ��Ԫ��)�����һ��Ԫ�ؽ���
3.�������ɵĶ�ʹ��MAX-HEAPIFY,�ָ����ѵ�����
4.�ظ�����
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Left(i) 2*(i+1)-1 
#define Right(i) 2*(i+1)
#define Parent(i) (i+1)/2-1 
//�������һ�����飬�����Ա�������һ�����Ƶ���ȫ��������
//����������ײ����⣬��������ȫ�����ģ������Ǵ���������� 
//��ʾ�ѵ�����һ�����������ʣ�A.length��ʾ����Ԫ�صĸ�����A.heap-size��ʾ�ж��ٸ���Ԫ�ش洢�������� 
struct heap{
	int *a; //���ڵĲ����ǣ�aָ��һ�����飬Ҳʹ��malloc��̬���䣬ʹ����չ������ 
	int length; 
	int heapSize;
}heap; 
//����MAX-HEAPIFY�������ֶѵ����� 
//���ϵؽ���ǰ�ڵ���ӽڵ���Ƚϣ�ֱ����ɸ�������MAX-HEAP���ʵĵ��� �����Ӷ�O(lgn)�������ĸ߶� 
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
//���ѣ���һ����СΪA.lenght������ת��Ϊ���ѣ�O(n) 
void BUILD_MAX_HEAP(struct heap *A,int a[],int n){
	A->heapSize = n;
	A->length = n;
	int i;
	A->a = a;
	//���ݶѵ����ʣ�n/2+1...n�ڵ㶼������Ҷ�ӽڵ㣬ÿ��Ҷ�ӽ����Կ���ֻ����һ��Ԫ�صĶѡ� 
	for(i=n/2; i>=0; i--){
		MAX_HEAPIFY(A,i);
		//����MAX-HEAPIFYʱ���赱ǰ�Ľڵ�������������Ƕѣ�ֻ�д������ϵ��ò�������ǰ�ᡣ(�Ѵ���������� ) 
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
		
	

 
