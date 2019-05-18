#include<iostream>
#include<fstream>
using namespace std;
//总体思想就是流，和标准输入输出cin/cout很类似
//只是这个流是在文件中发生而不是显示器上
 
class Person
{
public:
    //放个空的构造函数方便创建空对象
    Person(){};
    //纯粹赋值用
    Person(int id,int age)
    {
        this->id = id;
        this->age = age;
    }
    //打印下信息
    void detail()
    {
        cout<<"id: "<<this->id<<" age: "<<this->age<<endl;
    }
private:
    int age;
    int id;
};
 
void seri()
{
    //创建两个家伙
    Person p1(1,20);
    Person p2(2,40);
    //注意字符串的单双引号问题 
    ofstream osm("ser",ios::out|ios::binary);
    //这个地址一定要转换成char*
    osm.write((char*)&p1,sizeof(Person));
    osm.write((char*)&p2,sizeof(Person));
    osm.close();
    
    //先写就先读到
    Person p;
    ifstream ism("ser",ios::in|ios::binary);
    //不用写左值
    ism.read((char*)&p,sizeof(Person));
    p.detail();
    ism.read((char*)&p,sizeof(Person));
    p.detail();
    ism.close();
}
 
int main()
{
    seri();
    return 0;
}