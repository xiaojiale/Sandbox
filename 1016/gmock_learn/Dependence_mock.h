#ifndef DEPENDENCE_MOCK_H_
#define DEPENDENCE_MOCK_H_

#include <string>
#include "gmock/gmock.h"
#include "Base.h"

/*
 * mock类单独提取出来，可以供其他测试用例使用
 */
class DependenceMock: public Dependence
{
public:
    /*
     * 被mock的方法需要注意三点
     * 1) 公开修饰符一致（public,protected,private）
     * 2) 是否是const，使用对应的MOCK宏
     * 3) 必须声明为virtual，C++的多态机制需要virtual申明
     */
    MOCK_CONST_METHOD0(show, void()); // 声明 show的mock函数，注意要是public,同时需要注意是否是const方法

    /*
     * MOCK_METHOD*  *代表参数的个数，1.6.0的源代码中最多可以为10，估计gmock的开发人员认为如果一个函数的
     * 参数超过10，就可以重构了。
     * 第一个参数是被mock的函数
     * 第二个参数是被mock的函数指针，说明了返回参数和输出参数
     */
    MOCK_METHOD1(show, void(const string&));

    MOCK_CONST_METHOD1(addSomethingToString, string(const string&));
};

#endif /* DEPENDENCE_MOCK_H_ */
