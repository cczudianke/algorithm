/*************************************************************************
	> File Name: priority_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/ 2 19:06:17 2017
 ************************************************************************/

#include<iostream>
//#include'priority_queue.cpp'
//测试std::priority_queue的效率
#include<queue>
#include<time.h>
#include<stdlib.h>
using namespace std;
priority_queue<int>big_queue; //最大堆
priority_queue<int,vector<int>,greater<int> >small_queue;
int main(void)
{
    srand((int)time(NULL));
    for(int i=0;i<1000000;i++)
       big_queue.push(rand());
    for(int i=0;i<1000000;i++){
        printf("%d",big_queue.top());
        big_queue.pop();
    } 
    printf("\n");
    return 0;
}

