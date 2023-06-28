#include <iostream>
using namespace std;

//引用在c++内部实现为一个常指针：Type* const name 《==》type &name

//给指针申请内存空间
void getMemory1(int **p) //一级指针申请空间会发生段错误 
{
    *p = new int;   //检引用申请堆空间
} 

//给指针申请内存空间
void getMemory2(int *&p)//指针的引用
{
    p=new int; 
} 

int main()
{
    //定义指针
    int *ptr;

    //通过函数申请指针内存
    getMemory1(&ptr);
    *ptr=100;//申请空间赋值
    cout<<*ptr<<endl;

    getMemory2(ptr);
    *ptr=200;//申请空间赋值
    cout <<*ptr<<endl;
}

/*
//引用的特殊用法
int a=10;
int *p= &a;//指针
int *&ptr=a;//指针的引用

int (*fun)(void);//定义函数指针
int (*&pfun)(void)=fun();//定义函数指针的引用

int (*arr)[10];//定义数组指针
int (*&p)[10]=arr;//定义数组指针的引用
*/