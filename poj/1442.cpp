/*************************************************************************
	> File Name: 1442.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/ 2 15:19:20 2017
 ************************************************************************/


//有两个操作 get 获取第i大的数,获取后i++;add 加入一个数，
//输入M 一共要add的数的个数
//输入N 一共要get的个数
//A(1..N) N个要add的数
//u(1..M) M个Get的次序,例如u(i),就是在add i次之后Get
//这里我们可以使用优先队列来实现这个算法需求，一个优先队列使用最大堆
//一个队列使用最小堆，用来保存Get获得数，一个最大堆保存add加入的数      
//在add一个新的数的时候，就与最小堆中最小的数相比较，如果大于最小堆的数
//就交换
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> big_queue; //最大堆保存add
priority_queue<int, vector<int>,greater<int> > small_queue;
int num[30010];
int main(void)
{
    int M,N,x;
    scanf("%d%d",&M,&N);
    for(int i=1;i<=M;i++)
        scanf("%d",&num[i]);
    int k = 1;
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        while(k<=x){
            small_queue.push(num[k]);
            if(!big_queue.empty() && big_queue.top()>small_queue.top()){
                int t = big_queue.top();
                big_queue.pop();
                small_queue.push(t);
                t = small_queue.top();
                small_queue.pop();
                big_queue.push(t);
            }
            k++;
        }
        printf("%d\n",small_queue.top());
        int t = small_queue.top();
        small_queue.pop();
        big_queue.push(t);
    }
    return 0;
}
