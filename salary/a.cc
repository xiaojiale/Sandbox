#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iostream>
using namespace std;

#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERROR  0


typedef  bool  Status;
typedef int HeadEType;

typedef struct Student
{   
          int    num;      //学号
         char    name[10];   //姓名
} Student;

typedef struct DoubleNode
{	
	Student 	data;
	DoubleNode	*plink;
	DoubleNode	*nlink;
} DoubleNode; //链表结点

typedef struct
{	
	HeadEType 	Hdata;
	DoubleNode	*first;
} DoubleChainList;//链表的头

typedef struct 
{		
	DoubleNode	*plink;
	DoubleNode	*nlink;
} ResultNode;//返回直接前驱和直接后驱的数据元素的地址结果

typedef struct Tree_Node{	
	char 	data;
	Tree_Node	*son;
	Tree_Node	*next;
} Tree_Node;

 
typedef DoubleChainList ChainList;
typedef DoubleNode ChainNode;

ChainList *L;

ChainList *Creat(ChainList *L)
{// 构造一个空链表

	L=new ChainList;//产生一个仅有表头结点的链表
	L->first=NULL;//first的值设为空（NULL）值 
	L->Hdata=0;
	return L;
}
Status Delete(DoubleChainList *L, int k )
{// 在双向链表L中删除第k个数据元素,如果不存在第k个元素返回出错状态码
	if (k < 1 || ! L->first) return ERROR;
	DoubleNode   * current = L->first;
	DoubleNode   * p;
	if (k == 1)		 // 删除的是链表中第一个结点
	{
		p = current ->nlink;
		p ->plink = NULL;
		L->first = p; 
	}
	else 
	{ 
		DoubleNode   *q = L->first;
		for (int index = 1; index < k  && q ; index++)
			q = q->nlink;
		if(!q)   
			return ERROR; 
			current = q;       // current 指向第k个结点
		q = current ->plink;  
		p = current ->nlink;
		q->nlink = p; 
		if(p)
		p->plink = q; 
	}
	delete current;         // 释放被删除结点current的空间
	return OK;
}
Status Insert(DoubleChainList *L, int k, Student *student )
{
 		if (k < 0) 
			return ERROR;

		int	index = 1,i=0;
		DoubleNode	 *current= L->first;

		while (index < k && current)
		{//找第k个结点
			index++;
			current = current ->nlink;
		}

		if (k > 0 && ! current) 	return ERROR;

		DoubleNode   *q = new DoubleNode;
		while(i<10)
		{q->data.name[i] = student->name[i];
		i++;} 
		q->data.num=student->num;

		if (k)
		{// 插入在current 之后, 两个方向的链域的修改 
			q->nlink = current ->nlink;
			q->plink = current;
			DoubleNode   *p = current ->nlink ;
			current ->nlink = q;
			if(p)
				p->plink = q;
		}
		else 
		{// 作为第一个元素结点插入
			q->nlink = L->first;
			q->plink = NULL;
			DoubleNode   *p = L->first;
			if(p)
				p->plink = q;
			L->first = q;
		}
		return OK;
}

void Welcome()		//启动画面
{	
	char line[]={"━━━━━━━━━━"};
	char bar[]={"...."};
	int i,j,k=0,x=0,y=0;	
	for(i=1;i<=strlen(line)/2;)
	{
		system("cls");
		for(j=0;j<9;j++)   //改变行坐标
			cout<<endl;
		for(j=0;j<(75-strlen(line))/2;j++)  //改变列坐标
			cout<<" ";
		for(j=1;j<=i;j++)			//进度显示器
			cout<<"■";
		for(x=strlen(line)/2;x>i;x--)
			cout<<"□";
		if(k==4)
			i++;
		cout<<endl;	
		for(j=0;j<(75-strlen(line))/2;j++)	//行坐标定位
			cout<<" ";
		cout<<line;			//输出线条
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
		cout<<"		    中南财经政法大学信息与安全工程学院"<<endl;
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


void Cover()		//封面信息
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

/*void Output(DoubleChainList *L)
{// 逐个地输出链表L中的数据元素
	DoubleNode *current=L->first;
	while (current)
	{
		cout<<current->data.num << "  ";
		cout<<current->data.name << "  "<<endl;
		current=current->nlink ;
	}
	cout<<endl;
}
*/
bool Search(DoubleChainList *L,int x)
{
	
	DoubleNode  *current = L->first;
   while (current &&current->data.num!=x)
    		current=current->nlink;
   if(!current) return 0;
		cout<<"    "<<current->data.num << "  ";
		cout<<"    "<<current->data.name << "  "<<endl;
       return 1;
}




void PreOrderN(BinaryTreeNode *BT)		//二叉树的前序遍历非递归算法
{
	SType	temp;
	Stack				S;
	BinaryTreeNode	*p=BT;
	CreatStack(S);	//产生一个空栈，这一过程函数可以不在这里进行
	while(p||!IsEmpty(S))
	{
		if (p)
		{
			cout<<p->data<<"  ";		//访问"根"结点
			temp.ptr =p;
			Push(S,temp);					//根结点指针进栈，以后回朔时再退栈
			p = p->LChild;					//指针指向访问过的"根"结点左子树
		}
		else							//左子树为空时，利用堆栈回朔
		if (!IsEmpty(S))
		{
			Pop(S, temp); 					//从堆栈中弹出回朔结点指针（该结点已访问过）
			p=temp.ptr;
			p=p->RChild;					//指针指向回朔结点的右子树
		} 
	}
	cout<<endl;
	cout<<endl;
}

void InOrderN(BinaryTreeNode *BT)		//二叉树的中序遍历非递归算法 
{
	SType	temp;
	Stack				S;
	BinaryTreeNode	*p = BT;
	CreatStack (S);						//产生一个空栈，这一过程函数可以不在这里进行
	do
	{
		while (p)						//找最左子树
		{
			temp.ptr =p;
			Push (S, temp);				//"根"结点（未访问）指针进栈，以后回朔时再退栈
			p = p->LChild;				//指针指向该"根"结点左子树
		}
		if (!IsEmpty(S)) 				//左子树为空时，利用堆栈回朔
		{
			Pop(S, temp); 				//从堆栈中弹出回朔结点指针（该结点未访问过）
			p=temp.ptr;
			cout << p->data << "  ";	//访问"根"结点
			p=p->RChild;				//指针指向回朔结点的右子树
		} 
	}
	while((p)||!IsEmpty(S));
	cout<<endl;
	cout<<endl;
}


void PostOrderN(BinaryTreeNode *BT)		//二叉树的后序遍历非递归算法
{
	SType	temp;
	Stack	S;
	BinaryTreeNode	*p=BT;
	CreatStack(S);		//产生一个空栈，这一过程函数可以不在这里进行

	while ((p)||!IsEmpty(S))
		if (p)						//找最左子树
		{
			temp.B = false;			//准备进栈的结点进栈标志设为第一次进栈
			temp.ptr =p;
			Push (S,temp);	//"根"结点（未访问）指针及标志进栈，以后回朔时再退栈
			p = p->LChild;				//指针指向该"根"结点左子树
		}
		else
		if (!IsEmpty(S)) 				//左子树为空时，利用堆栈回朔
		{
			Pop(S,temp); 		//从堆栈中弹出回朔结点指针及标志（该结点未访问过）
			p=temp.ptr;				//p指向退栈结点
			if (temp.B)
			{
				cout << p->data << "  ";		//访问该结点
				p = NULL;				//将p设为空的目的是为强制退栈作准备
			}
			else
			{
				temp.B = true;			//改变进栈标志，准备重新进栈
				Push(S, temp);
				p= p->RChild;			//指针指向"根"的右子树
			}
		} 
	cout<<endl;
	cout<<endl;
}

void TreeLevelOrderN(BinaryTreeNode *BT)		//二叉树的层次遍历算法
{
	SType	temp;
	Stack	S;
//	Queue 		Q;
//	CreatQueue(Q);
//	Enqueue(Q ,BT);
	BinaryTreeNode	*p=BT;
	CreatStack(S);
	while ( !IsEmpty(S) )
	{		
		if (!BT)
			BT=new TreeNode;
		Dequeue(S,BT);
		while (BT)
		{
			cout << BT->data << "  ";	//访问结点
			if (BT->son )	
			  Enqueue(S,BT->son); 
			BT=BT->next;
		}
	}
	cout<<endl;
	cout<<endl;
}



void Menu()		//菜单函数
{

		printf("\n\n\n\n\n\n");
		printf("              ==================================================\n\n");
		printf("		     	      请选择要执行的功能\n\n");
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

void InitRecord()	//初始化数据（默认数据）
{
	char name[10][10]={"彭亮","王明","李华","刘丹","张三","李四","王二"};	
	int No[7]={1001,1002,1003,1004,1005,1006,1007};
	
	for(int i=0;i<7;i++)
	{
		strcpy(student[i].Name,name[i]);		
		student[i].No=No[i];
	}

	FILE *f;
	int datewrite;

	f=fopen("初始化数据.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	for (i=0;i<7;i++)
		datewrite=fwrite(&student[i], sizeof(Student),1,f);
	fclose(f);
}

void InitRecord()	//初始化数据（默认数据）
{
	char name[10][10]={"彭亮","王明","李华","刘丹","张三","李四","王二"};	
	int No[7]={1001,1002,1003,1004,1005,1006,1007};
	
	for(int i=0;i<7;i++)
	{
		strcpy(student[i].Name,name[i]);		
		student[i].No=No[i];
	}

	FILE *f;
	int datewrite;

	f=fopen("初始化数据.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	for (i=0;i<7;i++)
		datewrite=fwrite(&student[i], sizeof(Student),1,f);
	fclose(f);
}

void Output_L(LinearList &L)		// 逐个地输出线性表L中的数据元素
{
	cout<<"\n\n";
	cout<<" ┌─────────┐"<<endl;
	cout<<" │   当 前 数 据    │"<<endl;
	cout<<" ├────┬────┤"<<endl;
	cout<<" │        │        │"<<endl;
	cout<<" │学    号│平均成绩│"<<endl;
	cout<<" │　　　　│　　　  │"<<endl;
	cout<<" ├────┼────┤"<<endl;	
	
	for (int i=0;i<7;i++)
	{
     cout<<" │"<<setw(8)<<L.element[i].No<<"│"<<setw(8)<<L.element[i].Name<<"│"<<endl;	
	 cout<<" ├────┼────┤"<<endl;

	}
	
	cout<<" │        │        │"<<endl;
 	cout<<" └────┴────┘"<<endl;
}

void Output_C()
{
	printf("\t\t\t\t      A\n");
	printf("\t\t\t\t ┌─┸─┐\n");
	printf("\t\t\t\t B	  C\n");
	printf("\t\t\t    ┌─┸─┐\n");
	printf("\t\t\t    D	     E\n");
	printf("\t\t\t\t┌─┸─┐\n");
	printf("\t\t\t\tF	 G\n");

}
void Switch(int x)		//功能选择
{
	switch(x)
	{
		case 1:cout<<"默认数据导入成功!当前数据为:"<<endl;
            Output(L);
			system("pause");
			system("cls");
			break;
		case 2:cout<<"请输入学生的name及num以及插入第几个学生后k:";
//            student=new Student;
//		    cin>>student->name>>student->num>>k;
//			h=Insert(L,k,student);
//			if(h) cout<<"插入成功！"<<endl; 
//		 	else  cout<<"插入失败！"<<endl;
			system("pause");
			system("cls");
			break;
		case 3:cout<<"当前二叉树的树形图为:"<<endl;

			system("pause");
			system("cls");
			break;
		case 4:cout<<"当前二叉树的前序非递归遍历为:	 ";
			PreOrderN(treeNode[0]);

			system("pause");
			system("cls");
			break;

		case 5:cout<<"当前二叉树的中序非递归遍历为:	 ";

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

void main()
{
	int i,n,flag=1,k=0,h=0,j=0;
	Student *student;

	system("cls");
	Welcome();
	system("cls");
	Cover();
	system("pause");
	system("cls");

	InitRecord();
//	ReadRecord();
	Output(L);

/*
	L=Creat(L);//创建空链表
    for(i=0;i<=4;i++)
	{
		student=new Student;
		cout<<"请输入学生的name及num:";
		cin>>student->name>>student->num;
		Insert(L,i,student);
		L->Hdata++;
	}//给链表赋值即初始化
	cout<<"该链表现在为:"<<endl;
    Output(L);//显示现在的链表
*/

	while(flag)
	{

		system("cls");
		Menu();	
		printf("\n\t请输入功能编号:");

		cin>>n;
		while(n<0&&n>7) 
		{
			cout<<"您的输入有误，请重新输入:"<<endl;
			cin>>n;
		}
		Switch(n);
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

	MakeBinaryTree(treeNode[0],treeNode[1],NULL);			//A:B(L) ,	NULL(R)
	MakeBinaryTree(treeNode[1],treeNode[2],treeNode[3]);	//B:c(L) ,	d(R)
	MakeBinaryTree(treeNode[3],NULL,treeNode[4]);			//D:NULL(L) , E(R)

	cout<<"当前二叉树的前序非递归遍历为:	";		//二叉树的前序遍历非递归算法
	PreOrderN(treeNode[0]);	
	cout<<"当前二叉树的中序非递归遍历为:	";		//二叉树的中序遍历非递归算法
	InOrderN(treeNode[0]);	
	cout<<"当前二叉树的后序非递归遍历为:	";		//二叉树的后序遍历非递归算法
	PostOrderN(treeNode[0]);	
	cout<<"当前二叉树的层次遍历为:	";				//二叉树的层次遍历算法
	TreeLevelOrderN(treeNode[0])；
*/
	}
	return;
}
