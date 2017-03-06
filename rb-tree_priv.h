/*************************************************************************
	> File Name: rb-tree_priv.h
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Mar 2017 02:08:11 PM DST
 ************************************************************************/

#ifndef _RB-TREE_PRIV_H
#define _RB-TREE_PRIV_H
#include"rb-tree.h"
#include<stdio.h>
typedef struct rb_node{
    int key;
    struct rb_node* parent;
    struct rb_node* lchild,
             * rchild;
    char color;
}*rb_node;
struct rb_tree{
    rb_node root;
    rb_node nil;  //nil is one node means NULL 
};


#endif
