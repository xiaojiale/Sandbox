#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <string>
using namespace std;

/*
 * 被mock的对象
 */
class Dependence
{
public:
    /**
     * 析构函数没有申明为virtual时，会产生一些warning，你可以试一试
     */
    virtual ~Dependence(){}

    /*
     * 没有任何参数
     */
    virtual void show() const
    {
        cout << "I am dependecen" << endl;
    }

    /*
     * 接受一些参数
     */
    virtual void show(const string& sSth)
    {
        cout << "show: " << sSth << endl;
    }

    /*
     * 返回某些值
     */
    virtual string addSomethingToString(const string& sStr) const
    {
        return string(sStr + "something");
    }

};

/*
 * 调用mock的对象
 */
class Foo
{
public:
    void call(const Dependence& oDep)const
    {
        cout << "before call show" << endl;
        oDep.show();
        cout << "after call show" << endl;
    }

    void showSomething(Dependence& oDep, const string& sSth)const
    {
        cout << "before show something" << endl;
        oDep.show(sSth);
        cout << "after show something" << endl;
    }

    void showAddSomething(const Dependence& oDep, const string& sSth)const
    {
        if (sSth == "yes")
        {
            cout << oDep.addSomethingToString(sSth) << endl;
        }
    }
};

#endif /* BASE_H_ */
