#include "MyString.hpp"
#include "StrVector.hpp"
#include <iostream>
#include <algorithm>


using  namespace std;

vector <int> vec={0,1};
int main(int argc,char* argv[])
{
    reverse(vec.begin(),vec.end());
    for(int i=0;i++;i<vec.size()-1)
    cout<<vec.at(i)<<endl;
}