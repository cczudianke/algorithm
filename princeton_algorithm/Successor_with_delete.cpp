/*
Successor with delete.
Given a set of N integers S={0,1,...,n-1} and a sequence of requests of the following form:
Remove x from S
Find the successor of x: the smallest y in S such that y≥x.
design a data type so that all operations (except construction) take logarithmic time or better in the worst case.
*/
/*
如何将union-find 和set的操作结合起来的一些思考：
初始化时，x的successor就是他自身，当它被删掉之后，它的successor就是后面未被删掉的第一个元素
if(root(x)==x) return x;
else {
		p = x + 1;
		while(root(p)!=p){
			p++;
		}
		return p;
	}
*/ 
#include<iostream>
using namespace std;
class  QuickFindUF{
	private :
		int *id;
		int root(int i);
	public :
		QuickFindUF(int N);
		int successor(int x);
		void myunion(int p,int q); 
		void deletenode(int x);
};
QuickFindUF::QuickFindUF(int N){
	id = new int[N];
	if(id!=NULL){
		cout<<"SUCCESS"<<endl;
		for(int i=0;i<N;i++)
			id[i] = i;
		}else{
			cout<<"failed"<<endl; 
		}	
}
int QuickFindUF::root(int i){
	while(i!=id[i]) i = id[i];
	return i;
}
int QuickFindUF::successor(int x){
	if(root(x) == x) return x;
	else {
		int p = x + 1;
		while(root(p)!=p){
			p++;
		}
		return p;
	}
}
void QuickFindUF::myunion(int p,int q){//将p的根节点置为q的根节点 
	int i = root(p);
	int j = root(q);
	id[i] = j;
}
void QuickFindUF::deletenode(int x){
	myunion(x,x-1);
}
int main(void)
{
	QuickFindUF uf(6);
	uf.deletenode(2);
	uf.deletenode(1);
	cout<<uf.successor(2)<<endl;
	cout<<uf.successor(1)<<endl;
	return 0;	 
} 
