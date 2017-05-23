//根据普林斯顿算法课改写的cpp版本的连通性的快速查找，快速合并版本 
#include<iostream>
using namespace std;
class  QuickFindUF{
	private :
		int *id;
		int root(int i);
	public :
		QuickFindUF(int N);
		bool connected(int p,int q);
		void myunion(int p,int q); 
		
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
bool QuickFindUF::connected(int p,int q){
	return root(p) == root(q);
}
void QuickFindUF::myunion(int p,int q){//将p的根节点置为q的根节点 
	int i = root(p);
	int j = root(q);
	id[i] = j;
}
int main(void){
	QuickFindUF myuf(10);	
	return 0; 
}
