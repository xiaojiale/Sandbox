#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void Welcome()    //启动画面
{ 
  char line[]={"____________________"};
  char bar[]={"...."};
  int i,j,k=0,x=0,y=0;  
  for(i=1;i<=strlen(line)/2;)
  {
    system("cls");
    for(j=0;j<9;j++)   //改变行坐标
      cout<<endl;
    for(j=0;j<(75-strlen(line))/2;j++)  //改变列坐标
      cout<<" ";
    for(j=1;j<=i;j++)     //进度显示器
      cout<<"■";
    for(x=strlen(line)/2;x>i;x--)
      cout<<"□";
    if(k==4)
      i++;
    cout<<endl; 
    for(j=0;j<(75-strlen(line))/2;j++)  //行坐标定位
      cout<<" ";
    cout<<line;     //输出线条
    cout<<endl;
    for(j=0;j<(65-strlen(bar))/2;j++)
      cout<<" ";
    cout<<(i-1)*10<<"%  Loading";
    cout.write(bar,k);
    cout<<endl;
    for(j=0;j<7;j++)
      cout<<endl;
    for(j=0;j<24;j++)
      cout<<" ";
    cout<<"      肖家乐·制作\n"<<endl;
    cout<<"       中南财经政法大学信息与安全工程学院"<<endl;
    for(j=0;j<19;j++)
      cout<<" ";
    for(j=0;j<=17;j++)
      cout<<"─";
    cout<<endl;
    for(j=0;j<1000000;j++);//延时效果
    k++;
    if(k>4)
      k=0;
  }
}


void Cover()    //封面信息
{   
  printf("\n\n\n\n\n\n");
  printf("              *************************************************\n");
  printf("                    二叉树前、中、后序非递归遍历、层次遍历\n\n");
  printf("                           制作: 肖家乐\n");
  printf("                           班级: 电商1202班\n");
  printf("                           学号: 1209040120\n");
  printf("                           指导老师: 孙夫雄\n");
  printf("              *************************************************\n");
  printf("\n\n\n\t");
}


void Menu()   //菜单函数
{

  printf("\n\n\n\n\n\n");
  printf("              ==================================================\n\n");
  printf("                请选择要执行的功能\n\n");
  printf("                      1.初始化数据;\n");
  printf("                      2.自定义数据;\n");
  printf("                      3.显示当前二叉树的树形图;\n");
  printf("                      4.显示当前二叉树的前序非递归遍历;\n");
  printf("                      5.显示当前二叉树的中序非递归遍历;\n");
  printf("                      6.显示当前二叉树的后序非递归遍历;\n");
  printf("                      7.显示当前二叉树的层次遍历；\n");
  printf("                      0.退出.\n\n");
  printf("              ==================================================\n");
  printf("\n\n\n\t\t");

}


void Output_L()    // 逐个地输出线性表L中的数据元素
{
  cout<<"\n\n";
  cout<<" ┌─────────┐"<<endl;
  cout<<" │   当 前 数 据    │"<<endl;
  cout<<" ├────┬────┤"<<endl;
  cout<<" │        │        │"<<endl;
  cout<<" │学    号│平均成绩│"<<endl;
  cout<<" │　　　　│　　　  │"<<endl;
  cout<<" ├────┼────┤"<<endl;  

//  for (int i=0;i<7;i++)
//  {
//    cout<<" │"<<setw(8)<<L.element[i].No<<"│"<<setw(8)<<L.element[i].Name<<"│"<<endl; 
//    cout<<" ├────┼────┤"<<endl;
//
//  }

  cout<<" │        │        │"<<endl;
  cout<<" └────┴────┘"<<endl;
}


void Switch(int x)    //功能选择
{
  switch(x)
  {
    case 1:cout<<"默认数据导入成功!当前数据为:"<<endl;
           system("pause");
           system("cls");
           break;
    case 2:cout<<"请输入学生的name及num以及插入第几个学生后k:";
           // student=new Student;
           //       cin>>student->name>>student->num>>k;
           //     h=Insert(L,k,student);
           //     if(h) cout<<"插入成功！"<<endl; 
           //     else  cout<<"插入失败！"<<endl;
           system("pause");
           system("cls");
           break;
    case 3:cout<<"当前二叉树的树形图为:"<<endl;

           system("pause");
           system("cls");
           break;
    case 4:cout<<"当前二叉树的前序非递归遍历为:  ";
          // PreOrderN(treeNode[0]);

           system("pause");
           system("cls");
           break;

    case 5:cout<<"当前二叉树的中序非递归遍历为:  ";

           system("pause");
           system("cls");
           break;
    case 6:cout<<"当前二叉树的后序非递归遍历为:  ";

           system("pause");
           system("cls");
           break;
    case 7:cout<<"当前二叉树的层次遍历为:  ";

           system("pause");
           system("cls");
           break;
    case 0:;
    default:;
  }
}


int main()
{
  printf("\033[2]");
  Welcome();
  Cover();
  system("pause");



//  while(flag)
//  {
//
//    system("cls");
//    Menu(); 
//    printf("\n\t请输入功能编号:");
//
//    cin>>n;
//    while(n<0&&n>7) 
//    {
//      cout<<"您的输入有误，请重新输入:"<<endl;
//      cin>>n;
//    }
//    Switch(n);
    /*    
          switch(n)//实现功能
          {
          case 1:cout<<"该链表现在为:"<<endl;
          Output(L);
          break;
          case 2:cout<<"请输入学生的name及num以及插入第几个学生后k:";

          case 3:cout<<"请输入要删除第几位的学生：";

          case 4:cout<<"请输入查找学生的信息（学号）："<<endl;

          case 0:;
          default:;
          }
          */

    /*
       if(n) 
       {cout<<"   是否继续？ 1.继续  0.停止  ： "<<endl;
       cin>>flag;
       }
       else flag=0;
       cout<<endl
       <<endl;
    }                               
       return 0;
       */

    /*
       BinaryTreeNode *treeNode[5];
       char a='A';

       for(int i=0;i<5;i++)
       {
       treeNode[i]=MakeNode(a);
       a++;
       }
       printf("二叉树的结构:\n");

       printf("\t\tA\n");
       printf("\t\t│\n");
       printf("\t\tB\n");
       printf("\t\t├───┐\n");
       printf("\t\tC       D\n");
       printf("\t\t        └─┐\n");
       printf("\t\t             E\n");

       */

  return 0;
}
