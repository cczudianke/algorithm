/*Social network connectivity.
 Given a social network containing n members and a log file containing m timestamps 
 at which times pairs of members formed friendships, 
 design an algorithm to determine the earliest time at which all members are connected 
 (i.e., every member is a friend of a friend of a friend ... of a friend). 
 Assume that the log file is sorted by timestamp and that friendship is an equivalence relation. 
The running time of your algorithm should be mlogn or better and use extra space proportional to n. 
*/ 
//假设log如下
/* 
0 1 2015-08-14 18:00:00
1 9 2015-08-14 18:01:00
0 2 2015-08-14 18:02:00
0 3 2015-08-14 18:04:00
0 4 2015-08-14 18:06:00
0 5 2015-08-14 18:08:00
0 6 2015-08-14 18:10:00
0 7 2015-08-14 18:12:00
0 8 2015-08-14 18:14:00
1 2 2015-08-14 18:16:00
1 3 2015-08-14 18:18:00
1 4 2015-08-14 18:20:00
1 5 2015-08-14 18:22:00
2 1 2015-08-14 18:24:00
2 3 2015-08-14 18:26:00
2 4 2015-08-14 18:28:00
5 5 2015-08-14 18:30:00 
*/ 
//data structure UnionFind pesudo-code 
//func find( var element )
//  while ( element is not the root ) element = element's parent
//  return element
//end func
//
//func union( var setA, var setB )
//  var rootA = find( setA ), rootB = find( setB )
//  if ( rootA is equal to rootB ) return
//  else
//     set rootB as rootA's parent
//end func
//普林斯顿算法Interview Questions 1
//找到所有人相连接的最早时间 
//pseudo-code
//G := UnionFind(1..N)  初始化data structure
//count := 0	计数器置为0 
//for timestamp, p1, p2 in friendships { 遍历时间戳里的friendship 
//    if G.Find(p1) != G.Find(p2) {  如果根节点不同， 
//        G.Union(p1, p2)			 
//        count++
//        if count == N-1 {   因为我们知道一共只有N个friend，所以Union N-1次之后，所有的好友必然connect 
//            return timestamp  这时候返回timestamp 
//        }
//    }
//}
//return +infinity	如果没有Union N-1次，说明social network disconnected
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string> 
#include<fstream>
#include"istream.cpp" 
#define M 10 
using namespace std;
class UnionFind{
	private:
		int  *id;
		int  *sz;
		
	public:
		UnionFind(int N);
		int  find(int number);
		void  MyUnion(int p,int q);
};
UnionFind::UnionFind(int N)
{
	id = new int[N];
	sz = new int[N];
	if(id!=NULL){
		cout<<"success!"<<endl;
		for(int i=0;i<N;i++)
			id[i] = i;
		for(int i=0;i<N;i++)
			sz[i] = 1;
	}else
		cout<<"failed"<<endl;
}
int UnionFind::find(int number)
{
	int i = number;
	while(id[i]!=i){
		id[i] = id[id[i]];  
		//only one extra line of code !It make weighted QU + path compression => N + M lg* N!
		i = id[i]; 
	}
	return i;
}
void UnionFind::MyUnion(int p,int q)
{
	int i = find(p);
	int j = find(q);
	if(i==j) return ;
	if(sz[i]<sz[j]){
		id[j] = id[i];
		sz[j] += sz[i]; 
	}else{
		id[i] = id[j];
		sz[i] += sz[j];
	}
}

int main(void)
{
	UnionFind UF(M);
	int count = 0;
	//read log from log.txt
	readlogfile();
	for(vector<pair<pair<int,int>,string> >::iterator it = log.begin();it != log.end();++it){
		if(UF.find(it->first.first)!=UF.find(it->first.second)){
			UF.MyUnion(it->first.first,it->first.second);
			count++;
			if(count==M-1){
				cout<<it->second<<endl;
				break;
			}
		}
	}
	
}














