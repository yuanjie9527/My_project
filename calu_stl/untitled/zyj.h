//
// Created by zyj on 2020/11/1.
//

#ifndef UNTITLED_ZYJ_H
#define UNTITLED_ZYJ_H

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
//#include <algorithm>
using namespace std;
void bubblesort(vector<int> &vec);
void choosesort(vector<int> &vec);
void insertsort(vector<int> &vec);
void quicksort(vector<int> &vec,int lbound,int rbound);
void mergesort(vector<int> &vec,int left,int right);
void merge(vector<int> &vec,int leftptr,int rightptr,int rightbound);
void heapbuild(vector<int> &vec,int index,int length);
void heapsort(vector<int> &vec,int size);

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* VectorNodeToBinaryTree(vector<TreeNode*> &vec);// 用vector<TreeNode*>构建二叉树


class tree{//二叉树生成
public:
    TreeNode* root;
    tree(vector<int> &arr){//建树,-1为空节点
        int len=arr.size();
        queue<TreeNode*> bfsque;
        root=new TreeNode(arr[0]);
        bfsque.push(root);
        int i=0;
        while(bfsque.size()){
            if(++i>=len)    break;
            auto node=bfsque.front();    bfsque.pop();
            if(arr[i]!=-1){
                node->left=new TreeNode(arr[i]);
                bfsque.push(node->left);
            }
            if(++i>=len)    break;
            if(arr[i]!=-1){
                node->right=new TreeNode(arr[i]);
                bfsque.push(node->right);
            }
        }
    }
    ~tree(){
        stack<TreeNode*> sta;
        sta.push(root);
        while(sta.size()){
            auto tmp=sta.top(); sta.pop();
            auto left=tmp->left;
            auto right=tmp->right;
            delete tmp;
            if(right)   sta.push(right);
            if(left)    sta.push(left);
        }
    }
};





#endif //UNTITLED_ZYJ_H
