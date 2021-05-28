#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "zyj.h"


using namespace std;
/*
 * ------------------------------------------------
 * ------------------------------------------------
 * ------------------------------------------------
 * ------------------letcode代码------------------
 * --------------------501------------------------
 * ------------------------------------------------
 * ------------------------------------------------
*/
class Solution {
public:
    struct cmp
    {
        bool operator()(pair<string,int> &a,pair<string,int> &b){
            return a.second<b.second || (a.second==b.second && a.first>b.first);
        }

    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue < pair<string,int>,vector<pair<string,int>>,cmp > que;
        map<string,int> mp;
        vector<string> res;
        for(auto s : words)
            mp[s]++;
        for(auto m : mp)
            que.push(m);
        while(k--)
        {
            res.emplace_back(que.top().first);
            que.pop();
        }

        return res;
    }
};

int main()
{

    //--------------------测试用例--------------------------
    vector<string> words = {
            "i", "love", "leetcode", "i", "love", "coding"
    };



    //--------------------待测试方法--------------------------
    Solution s;
    auto res=s.topKFrequent(words,2);
    for(auto r:res)
    cout<<r<<endl;

    //--------------------查看结果--------------------------



    return 0;
}

// //--------------------排序验证--------------------------
//vector<int> vec={1,3,6,4,11,8,2,10,9,7,6,5,4,8,1,9,3,4,5,7,3,6,0};
//    bubblesort(vec);
//for(int i=0;i<vec.size();i++)
//    cout<<vec.at(i)<<" ";
//    cout<<endl;

