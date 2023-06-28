#include <iostream>

using namespace std;
//数据操作
class Data
{
public:
    int d;
    //返回当前类对象
    Data &fun1()//返回引用
    {
        this->d++;
        return *this;//返回对象
    }
    Data fun2()//返回普通值
    {
        this->d++;
        return *this;//返回对象
    }
private:

};


int main(int argc, char const *argv[])
{
    Data p;//定义对象
    p.d = 100;
    cout<<(p.fun1().fun1().fun1().d)<<endl;
    cout<<p.d<<endl;
    cout<<"============"<<endl;

    Data M;//定义对象
    M.d = 100;
    cout<<(M.fun2().fun2().fun2().d)<<endl;
    cout<<M.d<<endl;

    return 0;
}
