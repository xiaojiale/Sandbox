#include <random>
#include <iostream>
#include <memory>
#include <functional>

void f(int , int , int , const int& , int );
int g(int);

struct Foo {
  void print_sum(int n1, int n2)
  {
    std::cout << n1 + n2 << '\n';
  }
  int data = 10;
};

int main()
{
  using namespace std::placeholders;
  int n = 7;

  auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
  n = 10;
  f1(1, 2, 1001);

  auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
  f2(10, 11, 12);

  std::default_random_engine e;
  std::uniform_int_distribution<> d(0, 10);
  std::function<int()> rnd = std::bind(d, e);

  for(int n = 0; n < 10; ++n)
  {
    std::cout << rnd() << ' ';
  }
  std::cout << '\n';

  Foo foo;
  auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
  f3(5);

  auto f4 = std::bind(&Foo::data, _1);
  std::cout << f4(foo) << '\n';

  std::cout << f4(std::make_shared<Foo>(foo)) << '\n'
            << f4(std::make_unique<Foo>(foo)) << '\n';
}

void f(int n1, int n2, int n3, const int& n4, int n5)
{
  std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
  return n1;
}
