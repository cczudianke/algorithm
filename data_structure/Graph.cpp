/*************************************************************************
	> File Name: Graph.cpp
	> Author: lidajun
	> Mail: 
	> Created Time: 一  5/22 15:22:05 2017
 ************************************************************************/
//邻接链表法表示
#include<iostream>
using namespace std;

#define N 100
struct Edge{
    int start;
    int end;
    int value;
    Edge* next;
    Edge(int s,int e,int v):start(s),end(e),value(v),next(NULL){}
};
struct Vertex{
    Edge *head;
    Vertex():head(NULL){};
};
class Link_Graph{
public:
    int n;
    Vertex *V;
    Link_Graph(int num):n(num){
        V = new Vertex[n+1];
    }
    ~Link_Graph(){delete []V;}
    void AddSingleEdge(int start,int end,int value = 1)
    {
        Edge *NewEdge = new Edge(start,end,value);
        if(V[start].head == NULL || V[start].head->end > end) //如果该节点的邻接表为空或者节点大于插入的节点（表里有小到大排列）
        {
            NewEdge->next = V[start].head;
            V[start].head = NewEdge;
        }
        else
        {
            Edge *e = V[start].head, *pre = e;
            while(e != NULL && e->end < end) {
                pre = e; //记录e前的边
                e = e->next;
            }
            if(e && e->end == end) {
                delete NewEdge;
                return ;
            }
            NewEdge->next = e;
            pre->next = NewEdge;
        }
    }
    void AddDoubleEdge(int a,int b,int value = 1)
    {
        AddSingleEdge(a,b,value);
        AddSingleEdge(b,a,value);
    }
    void DeleteSingleEdge(int start,int end)
    {
        Edge *e = V[start].head, *pre = e;
        while (e && e->end < end) {
            pre = e;
            e = e->next;
        }
        if(e == NULL || e->end >end){
            return ;
        }
        if(e == V[start].head)
            V[start].head = e->next;
        else
            pre->next = e->next;
        delete e;            
    }
    void DeleteDoubleEdge(int a,int b)
    {
        DeleteSingleEdge(a,b);
        DeleteSingleEdge(b,a);
    }
    void OutDegree();
    void InDegree();
    
    void PrintGraph();
    
    Link_Graph* Reverse(); //图的转置=>图的所有边的方向反过来的图
    
    Link_Graph* Square();
};
void Link_Graph::OutDegree()
{
    int i,cnt = 0;
    Edge *e;
    for(i = 1; i <= n; i++)
    {
        cnt = 0;
        e = V[i].head;
        while(e){
            cnt++;
            e = e->next;
        }
        cout<<"顶点"<<i<<"的出度为"<<cnt<<endl;
    }
}
void Link_Graph::InDegree()
{
    int ret[N+1] = {0}, i;
    Edge *e;
    for(i = 1; i <= n; i++)
    {
        e = V[i].head;
        while (e) {
            ret[e->end]++;
            e = e->next;
        }
    }
    for (i = 1; i <= n; i++) {
        cout<<"定点"<<i<<"的入度为"<<ret[i]<<endl;
    }
}
void Link_Graph::PrintGraph()
{
    int i;
    Edge *e;
    for(i =1; i <= n; i++)
    {
        cout<<i;
        e = V[i].head;
        while(e){
            cout<<"->"<<e->end;
            e = e->next;
        }
        cout<<endl;
    }
}
Link_Graph* Link_Graph::Reverse()
{
    Link_Graph* rev = new Link_Graph(n); //每一个节点的邻接表都为空
    //遍历图中的每一个节点，然后改变每一个节点的边的方向
    int i;
    for (i = 1; i <= n; i++) {
        Edge *e = V[i].head;
        //遍历该节点的每一个边，然后将每一条边转置
        while(e){
            rev->AddSingleEdge(e->end,e->start);
            e = e->next;
        }
    }
    return rev;
}
Link_Graph* Link_Graph::Square()
{
    Link_Graph* ret = new Link_Graph(n);
    int i;
    //遍历每一个节点
    for(i = 1; i <= n; i++){
        Edge *e = V[i].head,*a;
        while(e){
            ret->AddSingleEdge(e->start,e->end);
            cout<<e->start<<"和"<<e->end<<endl;
            a = V[e->end].head;
            //把以 该节点指向的节点的指向的点 和 当前节点 组成的边加入图中
            //a->b b->c, b->d => a->c ,a->d;
            while(a){
                ret->AddSingleEdge(e->start,a->end);
                a = a->next;
            }
            e = e->next;
        }
    }
    return ret;
}
int main(void)
{
    Link_Graph *a = new Link_Graph(10);
    a->AddSingleEdge(1,2);
    a->AddSingleEdge(1,3);
    a->AddSingleEdge(3,4);
    a->PrintGraph();
    Link_Graph *b = a->Reverse();
    b->PrintGraph();
    Link_Graph *c = a->Square();
    c->PrintGraph();
    return 0;
}
















