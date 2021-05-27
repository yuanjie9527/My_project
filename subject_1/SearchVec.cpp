#include "SearchVec.hpp"


void SearchVec::showvec(vector<int> vec)
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



int SearchVec::binarysearch(vector<int> &vec,int value)
{
    int begin=0;
    int end=vec.size();
    int mid=((end-begin)>>1)+begin;
    while(begin<end)
    {
        mid=((end-begin)>>1)+begin;
        if(vec.at(mid) == value ) return mid;
        else if(vec.at(mid) < value)   begin=mid+1;
        else if (vec.at(mid) > value)  end=mid;
    }
    return -1;
}