#include <iostream>
#include <functional>

class A
{
  public:
    int i_ = 0;
    char c = 'x';
    std::string d = "hello world";
    void output(int x, int y) {
      std::cout << x << " " << y << std::endl;
    }
};

int main()
{
  A a;
  std::function<void(int, int)> fr = std::bind(&A::output, &a, std::placeholders::_1, std::placeholders::_2);
  fr(1, 2);

  std::function<int&(void)> fr2 = std::bind(&A::i_, &a);
  fr2() = 100;
  std::cout << a.i_ << std::endl;

  std::function<char&(void)> fr3 = std::bind(&A::c, &a);
  fr3() = 'n';
  std::cout << a.c << std::endl;

  std::function<std::string&(void)> fr4 = std::bind(&A::d, &a);
  fr4() = "nihao shijie";
  std::cout << a.d << std::endl;

  return 0;
}
