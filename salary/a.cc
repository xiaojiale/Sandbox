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
          int    num;      //ѧ��
         char    name[10];   //����
} Student;

typedef struct DoubleNode
{	
	Student 	data;
	DoubleNode	*plink;
	DoubleNode	*nlink;
} DoubleNode; //������

typedef struct
{	
	HeadEType 	Hdata;
	DoubleNode	*first;
} DoubleChainList;//�����ͷ

typedef struct 
{		
	DoubleNode	*plink;
	DoubleNode	*nlink;
} ResultNode;//����ֱ��ǰ����ֱ�Ӻ���������Ԫ�صĵ�ַ���

typedef struct Tree_Node{	
	char 	data;
	Tree_Node	*son;
	Tree_Node	*next;
} Tree_Node;

 
typedef DoubleChainList ChainList;
typedef DoubleNode ChainNode;

ChainList *L;

ChainList *Creat(ChainList *L)
{// ����һ��������

	L=new ChainList;//����һ�����б�ͷ��������
	L->first=NULL;//first��ֵ��Ϊ�գ�NULL��ֵ 
	L->Hdata=0;
	return L;
}
Status Delete(DoubleChainList *L, int k )
{// ��˫������L��ɾ����k������Ԫ��,��������ڵ�k��Ԫ�ط��س���״̬��
	if (k < 1 || ! L->first) return ERROR;
	DoubleNode   * current = L->first;
	DoubleNode   * p;
	if (k == 1)		 // ɾ�����������е�һ�����
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
			current = q;       // current ָ���k�����
		q = current ->plink;  
		p = current ->nlink;
		q->nlink = p; 
		if(p)
		p->plink = q; 
	}
	delete current;         // �ͷű�ɾ�����current�Ŀռ�
	return OK;
}
Status Insert(DoubleChainList *L, int k, Student *student )
{
 		if (k < 0) 
			return ERROR;

		int	index = 1,i=0;
		DoubleNode	 *current= L->first;

		while (index < k && current)
		{//�ҵ�k�����
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
		{// ������current ֮��, ���������������޸� 
			q->nlink = current ->nlink;
			q->plink = current;
			DoubleNode   *p = current ->nlink ;
			current ->nlink = q;
			if(p)
				p->plink = q;
		}
		else 
		{// ��Ϊ��һ��Ԫ�ؽ�����
			q->nlink = L->first;
			q->plink = NULL;
			DoubleNode   *p = L->first;
			if(p)
				p->plink = q;
			L->first = q;
		}
		return OK;
}

void Welcome()		//��������
{	
	char line[]={"��������������������"};
	char bar[]={"...."};
	int i,j,k=0,x=0,y=0;	
	for(i=1;i<=strlen(line)/2;)
	{
		system("cls");
		for(j=0;j<9;j++)   //�ı�������
			cout<<endl;
		for(j=0;j<(75-strlen(line))/2;j++)  //�ı�������
			cout<<" ";
		for(j=1;j<=i;j++)			//������ʾ��
			cout<<"��";
		for(x=strlen(line)/2;x>i;x--)
			cout<<"��";
		if(k==4)
			i++;
		cout<<endl;	
		for(j=0;j<(75-strlen(line))/2;j++)	//�����궨λ
			cout<<" ";
		cout<<line;			//�������
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
		cout<<"      Ф���֡�����\n"<<endl;
		cout<<"		    ���ϲƾ�������ѧ��Ϣ�밲ȫ����ѧԺ"<<endl;
		for(j=0;j<19;j++)
			cout<<" ";
		for(j=0;j<=17;j++)
			cout<<"��";
		cout<<endl;
		for(j=0;j<1000000;j++);//��ʱЧ��
		k++;
		if(k>4)
			k=0;
	}
}


void Cover()		//������Ϣ
{   
	printf("\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                    ������ǰ���С�����ǵݹ��������α���\n\n");
	printf("                           ����: Ф����\n");
	printf("                           �༶: ����1202��\n");
	printf("                           ѧ��: 1209040120\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              *************************************************\n");
	printf("\n\n\n\t");
}

/*void Output(DoubleChainList *L)
{// ������������L�е�����Ԫ��
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




void PreOrderN(BinaryTreeNode *BT)		//��������ǰ������ǵݹ��㷨
{
	SType	temp;
	Stack				S;
	BinaryTreeNode	*p=BT;
	CreatStack(S);	//����һ����ջ����һ���̺������Բ����������
	while(p||!IsEmpty(S))
	{
		if (p)
		{
			cout<<p->data<<"  ";		//����"��"���
			temp.ptr =p;
			Push(S,temp);					//�����ָ���ջ���Ժ��˷ʱ����ջ
			p = p->LChild;					//ָ��ָ����ʹ���"��"���������
		}
		else							//������Ϊ��ʱ�����ö�ջ��˷
		if (!IsEmpty(S))
		{
			Pop(S, temp); 					//�Ӷ�ջ�е�����˷���ָ�루�ý���ѷ��ʹ���
			p=temp.ptr;
			p=p->RChild;					//ָ��ָ���˷����������
		} 
	}
	cout<<endl;
	cout<<endl;
}

void InOrderN(BinaryTreeNode *BT)		//����������������ǵݹ��㷨 
{
	SType	temp;
	Stack				S;
	BinaryTreeNode	*p = BT;
	CreatStack (S);						//����һ����ջ����һ���̺������Բ����������
	do
	{
		while (p)						//����������
		{
			temp.ptr =p;
			Push (S, temp);				//"��"��㣨δ���ʣ�ָ���ջ���Ժ��˷ʱ����ջ
			p = p->LChild;				//ָ��ָ���"��"���������
		}
		if (!IsEmpty(S)) 				//������Ϊ��ʱ�����ö�ջ��˷
		{
			Pop(S, temp); 				//�Ӷ�ջ�е�����˷���ָ�루�ý��δ���ʹ���
			p=temp.ptr;
			cout << p->data << "  ";	//����"��"���
			p=p->RChild;				//ָ��ָ���˷����������
		} 
	}
	while((p)||!IsEmpty(S));
	cout<<endl;
	cout<<endl;
}


void PostOrderN(BinaryTreeNode *BT)		//�������ĺ�������ǵݹ��㷨
{
	SType	temp;
	Stack	S;
	BinaryTreeNode	*p=BT;
	CreatStack(S);		//����һ����ջ����һ���̺������Բ����������

	while ((p)||!IsEmpty(S))
		if (p)						//����������
		{
			temp.B = false;			//׼����ջ�Ľ���ջ��־��Ϊ��һ�ν�ջ
			temp.ptr =p;
			Push (S,temp);	//"��"��㣨δ���ʣ�ָ�뼰��־��ջ���Ժ��˷ʱ����ջ
			p = p->LChild;				//ָ��ָ���"��"���������
		}
		else
		if (!IsEmpty(S)) 				//������Ϊ��ʱ�����ö�ջ��˷
		{
			Pop(S,temp); 		//�Ӷ�ջ�е�����˷���ָ�뼰��־���ý��δ���ʹ���
			p=temp.ptr;				//pָ����ջ���
			if (temp.B)
			{
				cout << p->data << "  ";		//���ʸý��
				p = NULL;				//��p��Ϊ�յ�Ŀ����Ϊǿ����ջ��׼��
			}
			else
			{
				temp.B = true;			//�ı��ջ��־��׼�����½�ջ
				Push(S, temp);
				p= p->RChild;			//ָ��ָ��"��"��������
			}
		} 
	cout<<endl;
	cout<<endl;
}

void TreeLevelOrderN(BinaryTreeNode *BT)		//�������Ĳ�α����㷨
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
			cout << BT->data << "  ";	//���ʽ��
			if (BT->son )	
			  Enqueue(S,BT->son); 
			BT=BT->next;
		}
	}
	cout<<endl;
	cout<<endl;
}



void Menu()		//�˵�����
{

		printf("\n\n\n\n\n\n");
		printf("              ==================================================\n\n");
		printf("		     	      ��ѡ��Ҫִ�еĹ���\n\n");
		printf("                      1.��ʼ������;\n");
		printf("                      2.�Զ�������;\n");
		printf("                      3.��ʾ��ǰ������������ͼ;\n");
		printf("                      4.��ʾ��ǰ��������ǰ��ǵݹ����;\n");
		printf("                      5.��ʾ��ǰ������������ǵݹ����;\n");
		printf("                      6.��ʾ��ǰ�������ĺ���ǵݹ����;\n");
		printf("                      7.��ʾ��ǰ�������Ĳ�α�����\n");
		printf("                      0.�˳�.\n\n");
		printf("              ==================================================\n");
		printf("\n\n\n\t\t");

}

void InitRecord()	//��ʼ�����ݣ�Ĭ�����ݣ�
{
	char name[10][10]={"����","����","�","����","����","����","����"};	
	int No[7]={1001,1002,1003,1004,1005,1006,1007};
	
	for(int i=0;i<7;i++)
	{
		strcpy(student[i].Name,name[i]);		
		student[i].No=No[i];
	}

	FILE *f;
	int datewrite;

	f=fopen("��ʼ������.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	for (i=0;i<7;i++)
		datewrite=fwrite(&student[i], sizeof(Student),1,f);
	fclose(f);
}

void InitRecord()	//��ʼ�����ݣ�Ĭ�����ݣ�
{
	char name[10][10]={"����","����","�","����","����","����","����"};	
	int No[7]={1001,1002,1003,1004,1005,1006,1007};
	
	for(int i=0;i<7;i++)
	{
		strcpy(student[i].Name,name[i]);		
		student[i].No=No[i];
	}

	FILE *f;
	int datewrite;

	f=fopen("��ʼ������.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	for (i=0;i<7;i++)
		datewrite=fwrite(&student[i], sizeof(Student),1,f);
	fclose(f);
}

void Output_L(LinearList &L)		// �����������Ա�L�е�����Ԫ��
{
	cout<<"\n\n";
	cout<<" ����������������������"<<endl;
	cout<<" ��   �� ǰ �� ��    ��"<<endl;
	cout<<" �����������Щ���������"<<endl;
	cout<<" ��        ��        ��"<<endl;
	cout<<" ��ѧ    �ũ�ƽ���ɼ���"<<endl;
	cout<<" ������������������  ��"<<endl;
	cout<<" �����������੤��������"<<endl;	
	
	for (int i=0;i<7;i++)
	{
     cout<<" ��"<<setw(8)<<L.element[i].No<<"��"<<setw(8)<<L.element[i].Name<<"��"<<endl;	
	 cout<<" �����������੤��������"<<endl;

	}
	
	cout<<" ��        ��        ��"<<endl;
 	cout<<" �����������ة���������"<<endl;
}

void Output_C()
{
	printf("\t\t\t\t      A\n");
	printf("\t\t\t\t �����ܩ���\n");
	printf("\t\t\t\t B	  C\n");
	printf("\t\t\t    �����ܩ���\n");
	printf("\t\t\t    D	     E\n");
	printf("\t\t\t\t�����ܩ���\n");
	printf("\t\t\t\tF	 G\n");

}
void Switch(int x)		//����ѡ��
{
	switch(x)
	{
		case 1:cout<<"Ĭ�����ݵ���ɹ�!��ǰ����Ϊ:"<<endl;
            Output(L);
			system("pause");
			system("cls");
			break;
		case 2:cout<<"������ѧ����name��num�Լ�����ڼ���ѧ����k:";
//            student=new Student;
//		    cin>>student->name>>student->num>>k;
//			h=Insert(L,k,student);
//			if(h) cout<<"����ɹ���"<<endl; 
//		 	else  cout<<"����ʧ�ܣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case 3:cout<<"��ǰ������������ͼΪ:"<<endl;

			system("pause");
			system("cls");
			break;
		case 4:cout<<"��ǰ��������ǰ��ǵݹ����Ϊ:	 ";
			PreOrderN(treeNode[0]);

			system("pause");
			system("cls");
			break;

		case 5:cout<<"��ǰ������������ǵݹ����Ϊ:	 ";

			system("pause");
			system("cls");
			break;
		case 6:cout<<"��ǰ�������ĺ���ǵݹ����Ϊ:  ";

			system("pause");
			system("cls");
			break;
		case 7:cout<<"��ǰ�������Ĳ�α���Ϊ:  ";

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
	L=Creat(L);//����������
    for(i=0;i<=4;i++)
	{
		student=new Student;
		cout<<"������ѧ����name��num:";
		cin>>student->name>>student->num;
		Insert(L,i,student);
		L->Hdata++;
	}//������ֵ����ʼ��
	cout<<"����������Ϊ:"<<endl;
    Output(L);//��ʾ���ڵ�����
*/

	while(flag)
	{

		system("cls");
		Menu();	
		printf("\n\t�����빦�ܱ��:");

		cin>>n;
		while(n<0&&n>7) 
		{
			cout<<"����������������������:"<<endl;
			cin>>n;
		}
		Switch(n);
/*    
	switch(n)//ʵ�ֹ���
	{
    case 1:cout<<"����������Ϊ:"<<endl;
            Output(L);
			break;
	case 2:cout<<"������ѧ����name��num�Լ�����ڼ���ѧ����k:";

	case 3:cout<<"������Ҫɾ���ڼ�λ��ѧ����";

	case 4:cout<<"���������ѧ������Ϣ��ѧ�ţ���"<<endl;

    case 0:;
    default:;
	}
*/

/*
	if(n) 
	{cout<<"   �Ƿ������ 1.����  0.ֹͣ  �� "<<endl;
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
	printf("�������Ľṹ:\n");

	printf("\t\tA\n");
	printf("\t\t��\n");
	printf("\t\tB\n");
	printf("\t\t����������\n");
	printf("\t\tC       D\n");
	printf("\t\t        ������\n");
	printf("\t\t             E\n");

	MakeBinaryTree(treeNode[0],treeNode[1],NULL);			//A:B(L) ,	NULL(R)
	MakeBinaryTree(treeNode[1],treeNode[2],treeNode[3]);	//B:c(L) ,	d(R)
	MakeBinaryTree(treeNode[3],NULL,treeNode[4]);			//D:NULL(L) , E(R)

	cout<<"��ǰ��������ǰ��ǵݹ����Ϊ:	";		//��������ǰ������ǵݹ��㷨
	PreOrderN(treeNode[0]);	
	cout<<"��ǰ������������ǵݹ����Ϊ:	";		//����������������ǵݹ��㷨
	InOrderN(treeNode[0]);	
	cout<<"��ǰ�������ĺ���ǵݹ����Ϊ:	";		//�������ĺ�������ǵݹ��㷨
	PostOrderN(treeNode[0]);	
	cout<<"��ǰ�������Ĳ�α���Ϊ:	";				//�������Ĳ�α����㷨
	TreeLevelOrderN(treeNode[0])��
*/
	}
	return;
}
