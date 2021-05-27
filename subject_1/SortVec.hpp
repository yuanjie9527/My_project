#ifndef SORT_VEC_HPP
#define SORT_VEC_HPP

#include<vector>
#include <random>
#include <iostream>

using namespace std;


template <class T> 
class SortVec
{
    public:
static void heapbuild(vector<T> &vec,int index,int length);
static void heapsort(vector<T> &vec,int size);

static vector<T> randomvec(int size,int begin,int end);
static void showvec(vector<T> vec); 

static void insertsort(vector<T> &vec);

static void insertsort_binary_search(vector<T> &vec);
static int binary_search(vector<T> &vec,T value);

static void mergesort(int begin,int end,vector<T> &vec);
static void merge(int begin,int mid,int end);


private:

     
public:
    SortVec(){}
    ~SortVec();
};



template <class T> 
void SortVec<T>::heapbuild(vector<T> &vec,int index,int length)
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

template <class T> 
void SortVec<T>::heapsort(vector<T> &vec,int size)
 {
     for (int i= (size>>1)-1;i>=0;i--) heapbuild(vec,i,size);
     for (int end_index=size-1;end_index>=1;end_index--)
     {
         swap(vec[end_index],vec[0]);
         heapbuild(vec,0,end_index);
     }
 }

template <class T> 
vector<T> SortVec<T>::randomvec(int size,int begin,int end)
{
    vector<T> res;
    res.reserve(size);
    int s=end-begin+1;
    srand(time(NULL));
    for(int i=0;i<size;i++) 
    {
        res.emplace_back(begin+(rand()%s));
    }
    return res;
}

template <class T> 
void SortVec<T>::showvec(vector<T> vec)
{
    if(vec.empty()) cout<<"{ }"<<endl;
    else 
    {
        cout<<"{ ";
        for(int i=0;i<vec.size();i++)
        {
            cout<<vec.at(i)<<" ";
        }
        cout<<"}"<<endl;
    }
}

template <class T> 
void SortVec<T>::insertsort(vector<T> &vec)
{
    for(int i=1;i<vec.size();i++)
    {
        int cur=i;
        T temp=vec.at(cur);
        while( cur>0 && temp<vec.at(cur-1) )
        {
            vec.at(cur)=vec.at(cur-1);
            cur--;
        }
        vec.at(cur)=temp;
    }
}

template <class T> 
void SortVec<T>::insertsort_binary_search(vector<T> &vec)
{
    for(int i=1;i<vec.size();i++)
    {
        int cur=i;
        int index=binary_search(vec,vec.at(cur));
        T temp=vec.at(cur);
        while (cur>index)
        {
            vec.at(cur)=vec.at(cur-1);
            cur--;
        }
        vec.at(cur)=temp;    
    }
}


template <class T> 
int SortVec<T>::binary_search(vector<T> &vec,T value)
{
    int begin=0;
    int end=vec.size();
    int mid=(begin+end)>>1;
    while(begin<end)
    {
        mid=(begin+end)>>1;
        if (vec.at(mid)<=value) begin=mid+1;
        else if (vec.at(mid)>value) end=mid;
    }
    return  begin;
    
    
    
}


template <class T>
void SortVec<T>::mergesort(int begin,int end,vector<T> &vec)
{
    if(end-begin<2) return;
    int mid=begin+(end-begin)>>1;
    mergesort(begin,mid);
    mergesort(mid,end);
    merge(begin,mid,end);
}

template <class T>
void SortVec<T>::merge(int begin,int mid,int end)
{
    
}

#endif 