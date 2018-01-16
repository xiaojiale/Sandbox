#include<iostream>
using namespace std;
const int ArrayNum=101;
int main()
{
  int r[ArrayNum],n,t;
  cout<<"请输入数组的元素个数(<=100)：";
  cin>>n;
  cout<<"请输入"<<n<<"个整数:";
  for(t=0;t<n;t++)
    cin>>r[t];
  for(int i=0;i<n;i++)
    cout<<r[i]<<" ";
  return 0;
}
