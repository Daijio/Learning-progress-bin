#include <iostream>
using namespace std;
//定义学生类
class Student
{
    public://公有权限
        // void fun()
        // {
        //     cout<<"fun()"<<endl;
        //     cout<<a<<endl;   //写一个公开接口就可以对私有权限进行访问
        //     cout<<b<<endl;
        // }
        //设置函数
        void set_Data(string names,int ages,double highs)
        {
            name = names;
            age = ages;
            high = highs;
        }
        //获取
        void get_Data()
        {
            cout<<" 姓名："<<name <<" 年龄："<<age <<" 身高："<<high <<endl;
        }
    private://私有权限
        int a;
        string name;  //学生名
        int age;     //年龄
        double high; //身高
    
    protected:
        int b;
};

int main()
{
    cout<<sizeof(Student)<<endl;

    //实例化对象
    Student jack;  //类对象变量
    cout<<sizeof(jack)<<endl;
    // jack.fun();
    // cout<<jack.a<<endl;  //私有权限不允许直接访问
    // cout<<jack.b<<endl;   //保护权限不允许直接访问
    //调用私有权限的数据需要通过公开接口进行私有成员进行数据操作
    jack.set_Data("jack",18,185.3);
    jack.get_Data();

    Student *rose = new Student; //类对象指针
    cout<<sizeof(rose)<<endl;
    // rose->fun();
    rose->set_Data("rose",17,165.8);
    rose->get_Data();

    return 0;
}