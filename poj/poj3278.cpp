//深度搜索加上优先队列
#include <iostream>
#include<algorithm>
#include <queue>
#include <string.h>
#include <cstdio>

#define max 100001
using namespace std;
typedef struct node{
    int n;
    int step; //记录一共的步数
    bool friend operator <(node a,node b){ //重载运算符< , priority_queue默认使用该运算符
        return a.step > b.step;
    }
//    这个时候优先队列首先弹出的是步数大的
}node;

int N,K;
int mark[max+5];
void bfs(int N)
{
    int ans;
    priority_queue<node> q;
    node p,temp;
    p.step = 0;
    p.n = N;
    q.push(p);
    while(!q.empty()){
        temp = q.top();
        q.pop();
        if(temp.n == K){
            printf("%d\n",temp.step);
            return ;
        }
        if(temp.n-1>=0&&temp.n-1<max&&mark[temp.n-1]!=1){
            mark[temp.n-1] = 1;
            p.n = temp.n-1;
            p.step = temp.step+1;
            q.push(p);
        }
        if(temp.n+1<max&&temp.n+1>=0&&mark[temp.n+1]!=1){
            mark[temp.n+1] = 1;
            p.n =temp.n+1;
            p.step = temp.step+1;
            q.push(p);
        }
        if(temp.n*2<max&&temp.n*2>=0&&mark[temp.n*2]!=1){
            mark[temp.n*2] = 1;
            p.n = temp.n*2;
            p.step = temp.step+1;
            q.push(p);
        }
    }
}
int main(void)
{
    while(scanf("%d%d",&N,&K)!=EOF){
        memset(mark,0, sizeof(mark));
        bfs(N);
    }
    return 0;
}

