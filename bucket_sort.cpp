/*************************************************************************
	> File Name: bucket_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/29 09:55:21 2017
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void inc_sort(int A[],int size,int bucket_size);
typedef struct node{
    int key;
    struct node* next;
}KeyNode;
int main(void)
{
    int raw[]={78,17,39,26,72,94,21,12,23,68};     
    int size=sizeof(raw)/sizeof(int);       
    inc_sort(raw,size,10);    
    
}
void inc_sort(int A[],int size,int bucket_size)
{
    KeyNode **bucket = (KeyNode**)malloc(bucket_size*sizeof(KeyNode*)); //二维数组
    for(int i=0;i<bucket_size;i++){
        bucket[i] = (KeyNode*)malloc(sizeof(KeyNode));
        bucket[i]->key = 0; //初始化桶中的数据
        bucket[i]->next = NULL;
    }
    for(int j=0;j<size;j++){
        KeyNode *node = (KeyNode*)malloc(sizeof(KeyNode));
        node->key = A[j];
        node->next = NULL;
        int index = A[j]/10; //映射函数计算桶号
        KeyNode *p = bucket[index]; //将p初始化为头指针
        if(p->key==0)
            //没有数据
            bucket[index]->next = node;
        else{
            //链表结构的插入排序
            while((p->next!=NULL)&&(p->next->key<=node->key))
                p = p->next;
            node->next = p->next;
            p->next = node;
        }
        (bucket[index]->key)++; //第一个为桶标号，key标明桶中有多少元素
    }
        for(int i=0;i<bucket_size;i++){
            for(KeyNode *k=bucket[i]->next;k!=NULL;k=k->next)
                printf("%d ",k->key);
        }
        printf("\n");
}
