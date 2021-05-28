//
// Created by zyj on 2020/11/1.
//
#include "zyj.h"



void bubblesort(vector<int> &vec)
{
    for(int i=0;i<vec.size()-1;i++)
        for (int j =vec.size()-1; j > i; j--)
            if(vec.at(j)<vec.at(j-1)) swap(vec.at(j), vec.at(j-1));
}


void choosesort(vector<int> &vec)
{
    for(int i=0;i<vec.size()-1;i++)
        for (int j = i+1; j < vec.size(); j++)
        if(vec.at(i)>vec.at(j)) swap(vec.at(i), vec.at(j));
/****************减少交换次数**************/
//    for(int i=0;i<vec.size()-1;i++)
//    {
//        int min_idx=i;
//        for (int j = i+1; j < vec.size(); j++)
//            if (vec.at(min_idx)> vec.at(j)) min_idx=j;
//        swap(vec.at(i), vec.at(min_idx));
//    }
}

void insertsort(vector<int> &vec)
{
    for(int i=1;i<vec.size();i++)
    {
        int cur=i;
        while( cur>0 && vec.at(cur) <vec.at(cur-1) )
        {
            swap(vec.at(cur),vec.at(cur-1));
            cur--;
        }
    }

    /****************减少交换次数**************/
//    for(int i=1;i<vec.size();i++)
//    {
//        int cur=i;
//        int temp=vec.at(cur);
//        while( cur>0 && temp<vec.at(cur-1) )
//        {
//            vec.at(cur)=vec.at(cur-1);
//            cur--;
//        }
//        vec.at(cur)=temp;
//    }
}

void quicksort(vector<int> &vec,int lbound,int rbound)
{
    if(lbound>=rbound) return;
    int idx=rbound;
    int l=lbound;
    int r=rbound-1;
    while(l<=r)
    {
        while(l<=r && vec.at(l)<=vec.at(idx)) l++;
        while(l<=r && vec.at(r)>vec.at(idx)) r--;
        if(l<r) swap(vec.at(l),vec.at(r));
    }
        swap(vec.at(l),vec.at(idx));

    quicksort(vec,lbound,l-1);
    quicksort(vec,l+1,rbound);

}

void mergesort(vector<int> &vec,int left,int right)
{
    if(left>=right) return;
    int mid=left+((right-left)>>1);
    mergesort(vec,left,mid);
    mergesort(vec,mid+1,right);
    merge(vec,left,mid+1,right);
}
void merge(vector<int> &vec,int leftptr,int rightptr,int rightbound)
{
    int i=leftptr;
    int j=rightptr;
    int temp_k=0;
    int mid=rightptr-1;
    vector<int> temp(rightbound-leftptr+1);
    while(i<=mid && j<=rightbound)
        temp.at(temp_k++)=vec.at(i)<=vec.at(j)?vec.at(i++):vec.at(j++);
    while(i<=mid) temp.at(temp_k++)=vec.at(i++);
    while(j<=rightbound) temp.at(temp_k++)=vec.at(j++);
    for(int m=0;m<temp.size();m++) vec.at(leftptr+m)=temp.at(m);
}


void heapbuild(vector<int> &vec,int index,int length)
{
    int left=2*index+1;
    int right=2*index+2;
    int max_index=index;
    if(left<length && vec[left]>vec[max_index])   max_index=left;
    if(right<length &&vec[right]>vec[max_index])   max_index=right;
    if( max_index!=index)
    {
        swap(vec[max_index],vec[index]);
        heapbuild(vec,max_index,length);
    }
}

void heapsort(vector<int> &vec,int size)
{
    for (int i= (size>>1)-1;i>=0;i--) heapbuild(vec,i,size);
    for (int end_index=size-1;end_index>=1;end_index--)
    {
        swap(vec[end_index],vec[0]);
        heapbuild(vec,0,end_index);
    }
}


TreeNode* VectorNodeToBinaryTree(vector<TreeNode*> &vec) {
    if (vec.size() <= 0) {
        return nullptr;
    }
    int i = 0;
    int j = 1;

    bool left = true;
    while (j < vec.size()) {
        if (left) {
            vec[i]->left = vec[j++];
            left = 1 - left;
        }
        else {
            vec[i++]->right = vec[j++];
            while (!vec[i]) {
                ++i;
            }
            left = 1 - left;
        }
    }
    return vec[0];
}
