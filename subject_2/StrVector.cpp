#include "StrVector.hpp"

 std::allocator<std::string>  StrVector::alloc;

std::ostream& operator<<(std::ostream& os,const StrVector& strv)
{
    for(const auto &x : strv)
    os<<x<<" ";
    return os;
}

void StrVector::push_back(const std::string& s)
{
    /*往string容器push一个string前检查容量是不是满了*/
    chk_n_alloc(); 
    /*程序到这表明有空位，在first_free的位置构建一个s*/
    alloc.construct(first_free++,s);
}
 
 /*这个函数仅仅完成了分配和拷贝，用于拷贝构造函数*/
std::pair<std::string*,std::string*> StrVector::alloc_n_copy(const std::string* beg,const std::string* end)
{
    /*分配空间，大小为end-beg，这里new_zoom_beg表示新空间的首地址指向*/
    auto new_zoom_beg=alloc.allocate(end-beg);
    /*函数将beg到end范围的元素拷贝到新空间，返回新空间尾后指向*/
    return {new_zoom_beg,uninitialized_copy(beg,end,new_zoom_beg)};
}

/*先逆序销毁对象范围内的每个元素（即string对象），然后释放该范围所占空间
   free（）主要用于StrVector的析构*/
void StrVector::free()
{
    if(elements)
    {
        for(auto p=first_free;p!=elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap-elements);
    }
}

/*拷贝构造函数
   分配了新的空间并将元素拷入，再用新空间的首地址初始化成员elements，最后用新空间的尾后初始化first_free和cap*/
StrVector::StrVector(const StrVector& strv)
{
    /*分配了新的空间并将元素拷入*/
    auto new_data= alloc_n_copy(strv.begin(),strv.end());
    elements=new_data.first;
    first_free=cap=new_data.second;
}

StrVector::~StrVector()
{
    free();
}

StrVector& StrVector::operator=(const StrVector& strv)
{
    /*分配了新的空间并将元素拷入*/
    auto new_data=alloc_n_copy(strv.begin(),strv.end());
    /*销毁对象所有元素并释放对象所占的旧空间*/
    free();
    /*将实例的的成员变量（即首、尾、容器尾）更新，返回更新后的实例*/
    elements=new_data.first;
    first_free=cap=new_data.second;
    return *this;
}

/*旧空间满容量的条件下再push元素时，开辟一个2倍旧容量大小的新空间，因此要做到：
1.开辟一个2倍旧容量大小的新空间
2.把旧空间的元素搬过去
3.销毁旧空间的元素并释放旧空间
4.将实例的的成员变量（即首、尾、容器尾）更新，使其指向新空间
*/
void StrVector::reallocate()
{
    auto newcapcity=size()?2*size():1;
    std::cout<<newcapcity<<std::endl;
    auto  new_zoom_beg=alloc.allocate(newcapcity);
    auto dest=new_zoom_beg;
    auto elem=elements;
    for(size_t i=0;i!=size();i++)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements=new_zoom_beg;
    first_free=dest;
    cap=elements+newcapcity;
}

void StrVector::resize(size_t c)
{
    if(c<=size()) return;
    else
    {
        auto newcapcity=c;
        auto new_zoom_beg=alloc.allocate(newcapcity);
        auto dest=new_zoom_beg;
        auto elem=elements;
        for(size_t i=0;i!=size();++i)
        {
            alloc.construct(dest++,std::move(*elem++));
        }
        elements=new_zoom_beg;
        first_free=dest;
        cap=new_zoom_beg+newcapcity;
    }
}

StrVector::StrVector(std::initializer_list<std::string> i1)
{
    auto newcapcity=i1.size();
    auto new_zoom_beg=alloc.allocate(newcapcity);
    auto elements=new_zoom_beg;
    auto first_free=elements+newcapcity;
    auto cap=elements+newcapcity;
        for(auto it=i1.begin();it!=i1.end();++it)
        {
            alloc.construct(new_zoom_beg++,std::move(*it));
        }

}

