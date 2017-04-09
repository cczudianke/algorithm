/*Union-find with specific canonical element
Add a method find() to the union-find data type 
so that find(i) returns the largest element in the connected component containing i. 
The operations, union(), connected(), 
and find() should all take logarithmic time or better.
*/ 
#include<iostream>
using namespace std;
class UnionWithFind{
	private:
		int *id; //id[i] is parent of node i
		int *sz; //sz[i] is size of node i
		int *large; // large[i] is largest element in connect component
		int root(int p);
	public:
		UnionWithFind(int N);
		int find(int p); // return largest element in connect component
		bool connect(int p,int q);
		void myunion(int p,int q);
}; 
UnionWithFind::UnionWithFind(int N)
{
	id = new int[N];
	sz = new int[N];
	large = new int[N];
	for(int i=0; i < N; i++){
		id[i] = i;
		sz[i] = 1;
		large[i] = i;
	}
}
int UnionWithFind::root(int p)
{
	while(id[p]!=p){
		id[p] = id[id[p]]; //path compression,将id[p]的值设为p的父亲的父亲 
		p = id[p];			
	}
	return p;
}

int UnionWithFind::find(int p)
{
	return large[root(p)];
}
void UnionWithFind::myunion(int p,int q)
{
	int i = root(p);
	int j = root(q);
	if (i == j) return ;
	int largep = large[i];
	int largeq = large[j];
	if(sz[i]<sz[j]){
		id[i] = id[j];//size大的根作为size小的父亲	
		sz[j] += sz[i];
		if(largep > largeq)
			large[j] = largep;
	}else {
		id[j] = id[i];
		sz[i] += sz[j];
		if(largeq > largep)
			large[i] = largeq;
	}
} 
bool UnionWithFind::connect(int p,int q)
{	
	return root(p) == root(q);	
} 
int main(void)
{
	 	UnionWithFind uf(10);
	 	uf.myunion(0, 2);
     	uf.myunion(8, 4);
     	cout<<uf.find(0)<<"== 2"<<endl;
        cout<<uf.find(4)<<"== 8"<<endl;
        uf.myunion(0, 4);
		cout<<uf.find(0)<<"== 8"<<endl;
        cout<<uf.find(2)<<"== 8"<<endl;	
        uf.myunion(0, 6);
        cout<<uf.find(6)<<"== 8"<<endl;
        uf.myunion(1, 9);
        uf.myunion(1, 2);
	 	cout<<uf.find(9)<<"== 9"<<endl;
}
