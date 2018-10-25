#define CRT_SECURE_NO_WARNINGS 1

#ifndef SQLIST_H_
#define SQLIST_H_

#include <iostream>
#include <string>

template <typename T>
class Sqlist
{
  template <typename T>
    friend ostream &operator<< <T>(ostream &os, const Sqlist<T> &list);

  public:
  Sqlist();
  ~Sqlist();
  Sqlist(const Sqlist &list);
};

