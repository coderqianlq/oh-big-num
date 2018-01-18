#include"bigNumQLQ.h"
#include<string>//字符串头文件
#include <iostream>//数据流输入输出
#include<fstream>//文件流输入输出，包含iostream
#include<sstream>//它是提供程序和string对象之间的I/O
#include <ctime>//记录程序运行时间
using namespace std;//命名空间 std::cout c++库中所有的标识符都是在一个名为std的命名空间中定义的

//********************************************************窗口********************************************************
//打印欢迎窗口 
void welcome()
 {
	cout<<"================================================================================\n\n";     
	cout<<"                           欢迎使用长整数运算程序\n\n";     
	cout<<"*请按如下提示进行操作:\n\n";  
	cout<<"*首先，根据屏幕的提示选择您想进行的操作。\n\n";  
	cout<<"*其次，根据提示输入两个或三个操作数。\n\n";  
	cout<<"\n\n";  
	cout<<"              姓名:钱立清  班级:软件工程1405班  学号:201427920214\n";     
	cout<<"================================================================================";
	cout<<"                               \n\n"; 
}
//打印标题窗口
void title()
{  
	int i; 
	cout<<endl;
	for(i=0;i<35;i++)   
	    cout<<"*";  
	cout<<"长整数运算";  
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"\n";
	cout<<"                          输入1、2、3、4、5或6选择操作:              \n";  
	cout<<"                                    1、加法                              \n";  
	cout<<"                                    2、减法                              \n";  
	cout<<"                                    3、乘法                              \n"; 
	cout<<"                                    4、除法                              \n"; 
	cout<<"                                    5、指数                              \n"; 
	cout<<"                                    6、退出                              \n";    
	cout<<"========================================= ======================================\n";
	cout<<"请选择:";		 
}  
//打印文件读入方式的标题窗口
void ftitle()
{  
	int i; 
	cout<<endl;
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"长整数运算";  
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"\n";
	cout<<"                         输入1、2、3、4、5或6选择操作:              \n";  
	cout<<"                                    1、加法                              \n";  
	cout<<"                                    2、减法                              \n";  
	cout<<"                                    3、乘法                              \n"; 
	cout<<"                                    4、除法                              \n"; 
	cout<<"                                    5、指数                              \n"; 
	cout<<"                                    6、文件                              \n";
    cout<<"                                    7、退出                              \n";
	cout<<"========================================= ======================================\n";
	cout<<"请选择:";		 
}
  
//********************************************************双向循环链表类********************************************************
//构造函数
linkedList::linkedList()
{
    node* dummynode=new node();//在构造函数中建立哑元节点,dummynode即为哑元节点
	dummynode->prev=dummynode;
	dummynode->next=dummynode;
	head=dummynode;
	lsize=0;//带哑元节点的链表长度为0
}



//拷贝构造函数
linkedList::linkedList(const linkedList & obj)
{
//自定义了拷贝构造函数，当调用拷贝构造函数时不会调用默认构造函数
	if(obj.size()==0)//针对仅仅有哑元节点的空链表的拷贝
	{
	      node* dummynode=new node();
	      dummynode->prev=dummynode;
	      dummynode->next=dummynode;
	      head=dummynode;
	      lsize=0;
	}
	else
	{
		node* dummynode=new node();//哑元节点的构建
	    dummynode->prev=dummynode;
     	dummynode->next=dummynode;
	    head=dummynode;
     	lsize=0;
	    node*front=NULL,*newNode,*back;//哑元节点其后部分链表框架的构建
	    node*ptr=obj.head->next;
	    int n=obj.size();
        int i=0;
        while(i<n)//从前往后实现链表的创建
		{	
		    if(i==0)//创建第一个节点
			{
		       front=new node();
		       back=front;
		       front->data=ptr->data;
		       ptr=ptr->next;
			}
	        else//创建之后节点
			{
		       newNode=new node();
		       back->next=newNode;
		       newNode->prev=back;
		       back=back->next;
		       back->data=ptr->data;
		       ptr=ptr->next;
			}
	     i++;
		}
        head->next=front;//将哑元节点指向新建好的链表的头节点
	    front->prev=head;
	    back->next=head;
     	head->prev=back;
	    lsize=n;//此时链表长度为n
	}
}



//赋值重载
linkedList & linkedList ::operator=(const linkedList& rhs)
{
//自定义了拷贝构造函数，当调用拷贝构造函数时不会调用默认构造函数
	if(rhs.size()==0)//针对仅仅有哑元节点的空链表执行赋值操作
	{
		node* dummynode=new node();
	    dummynode->prev=dummynode;
     	dummynode->next=dummynode;
	    head=dummynode;
     	lsize=0;
	}
	else
	{
		node*front=NULL,*newNode,*back;
	    node*ptr=rhs.head->next;
	    int n=rhs.size();
        int i=0;
        while(i<n)//从前往后实现链表的创建
		{	
		    if(i==0)//创建第一个节点
			{
		        front=new node();
		        back=front;
		        front->data=ptr->data;
		        ptr=ptr->next;
			}
	        else//创建之后节点
			{
				newNode=new node();
		        back->next=newNode;
		        newNode->prev=back;
		        back=back->next;
		        back->data=ptr->data;
		        ptr=ptr->next;
			}
	        i++;
		}
        head->next=front;//将哑元节点指向新建好的链表的头节点
	    front->prev=head;
	    back->next=head;
	    head->prev=back;
	    lsize=n;//此时链表长度为n
	}
    return *this;
}


//双向循环链表的创建并赋值
void linkedList::create_linkedList1(int n)
{
    node*front=NULL,*newNode,*back;
    int i=0;
    while(i<n)//从前往后实现链表的创建
	{	
		if(i==0)//创建第一个节点并将数据部分初始化
		{
		front=new node(0,NULL,NULL);
		back=front;
		}
	    else//创建之后节点
		{
		newNode=new node(0,NULL,NULL);//将数据部分初始化
		back->next=newNode;
		newNode->prev=back;
		back=back->next;
		}
	i++;
	}
    head->next=front;
	front->prev=head;
	back->next=head;
	head->prev=back;
	lsize=n;//此时链表长度为n
}



//双向循环链表的创建但并不赋值
void linkedList::create_linkedList2(int n)
{
    node*front=NULL,*newNode,*back;
    int i=0;
    while(i<n)//从前往后实现链表的创建
	{	
		if(i==0)//创建第一个节点
		{
		front=new node();
		back=front;
		}
	    else//创建之后节点
		{
		newNode=new node();
		back->next=newNode;
		newNode->prev=back;
		back=back->next;
		}
	i++;
	}
    head->next=front;//将哑元节点指向新建好的链表的头节点
	front->prev=head;
	back->next=head;
	head->prev=back;
	lsize=n;//此时链表长度为n
}



//链表长度,常成员函数，无法修改本类中的数据成员
int linkedList::size()const
{
	return lsize;
	//lsize=lsize+1;//修改，所以报错
}



//插入函数
void linkedList::insert(int item, int pos)//插入数据item到pos后
{
	int i;
	node*newptr,*preptr,*ptr;
	newptr=new node(item,NULL);//新建节点，数据部分为item
	preptr=head;
	ptr=preptr->next;
	for(i=0;i<pos;i++)//循环找到所要插入节点的位置
	{
		preptr=preptr->next;//节点前
		ptr=ptr->next;//节点后
	}
    newptr->next=preptr->next;
	preptr->next=newptr;
	ptr->prev=newptr;
	newptr->prev=preptr;
	lsize=lsize+1;//长度自增1
}



//删除函数
void linkedList::erase(int pos)//删除pos处的节点
{
	int i;
	node*preptr,*ptr,*beptr;
	preptr=head;
	ptr=preptr->next;
	beptr=ptr->next;
	for(i=1;i<pos;i++)//循环找到删除节点的位置
	{
		preptr=preptr->next;//位置前
		ptr=ptr->next;//删除节点的位置
		beptr=beptr->next;//位置后
	}
	preptr->next=beptr;
	beptr->prev=preptr;
	delete ptr;//释放节点空间，删除
	lsize=lsize-1;//长度自减1
}



//输出链表
void linkedList::display(ostream & out)
{
	int i; 
	node*temp;
	temp=head->next;
	for(i=0;i<lsize;i++)//循环将链表数据逐一输出
	{
		out<<temp->data;
		temp=temp->next;
	}
}



//重载位操作符，输出
ostream & operator<<(ostream & out,  linkedList & aList )
{
	aList.display(out);
	return out;
}



//********************************************************大整数类********************************************************
//链表长度比较
int bigNum::cmplinklen(linkedList& opr1,linkedList& opr2)
{
	int m=opr1.size();//opr1的长度
	int n=opr2.size();//opr2的长度
    if(m>=n) return 1;
	else return -1;
}



//比较两个长整数的大小,比较完毕后1代表opr1>opr2,-1代表opr1<opr2,0代表opr1=opr2
int bigNum::compare(linkedList& opr1,linkedList &opr2)
{   int m=0; 
	int l1=opr1.size();
	int l2=opr2.size();
    if(l1>l2)//opr1长度大于opr2长度 
		m=1;
	else if(l1==l2)//长度相等
	{
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//长度相等时又分两种情况
		{
			if(optr1->data>optr2->data)
			{
				m=1;break;//如果符合跳出循环
			}
			else if(optr1->data<optr2->data)
			{
				m=-1;break;//如果符合跳出循环
			}
			optr1=optr1->next;
			optr2=optr2->next;

		}
	}
	else  m=-1;//opr1长度小于opr2
    return m;
}



//将链表数据转换成字符串
string bigNum::translation(linkedList &opr)//将所得结果输出至文件中
{   
    node*back;
	int l=opr.size();
	string s(l,0);//创建长度为l，初始化为0的字符串
	back=opr.head->prev;
	for(int i=l-1;i>=0;i--)//循环将链表数据输入到字符串中
	{
		s[i]=back->data+'0';
		back=back->prev;
	}
	return s;
}



//输入两个字符串类型的操作数,并将其存储在链表中
void bigNum::input_store(linkedList& opr1,linkedList &opr2)//两个形参
{
	int length;
	node*back;
	int i;
	cout<<"请输入第一个长整数:";
	string s1;
	cin>>s1;
	length=s1.length();
    opr1.create_linkedList2(length);//将opr1创建成长度为length的链表
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)//循环将其存储在链表中
	{
		back->data=s1[i]-'0';
		back=back->prev;
	}
	cout<<"请输入第二个长整数:";
    string s2;
	cin>>s2;
	length=s2.length();
	opr2.create_linkedList2(length);//将opr1创建成长度为length的链表
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)//循环将其存储在链表中
	{
		back->data=s2[i]-'0';
		back=back->prev;
	}
}



//输入三个字符串类型的操作数,并将其存储在链表中
void bigNum::input_store(linkedList& opr1,linkedList &opr2,linkedList &opr3)//三个形参
{
	int length;
	node*back;
	int i;
	cout<<"请输入第一个长整数B1:";
	string s1;
	cin>>s1;
	length=s1.length();
    opr1.create_linkedList2(length);//将opr1创建成长度为length的链表
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)//循环将其存储在链表中
	{
		back->data=s1[i]-'0';
		back=back->prev;
	}
	cout<<"请输入第二个长整数B2:";
    string s2;
	cin>>s2;
	length=s2.length();
	opr2.create_linkedList2(length);//将opr1创建成长度为length的链表
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)//循环将其存储在链表中
	{
		back->data=s2[i]-'0';
		back=back->prev;
	}
	cout<<"请输入第三个数模数B3:";
    string s3;
	cin>>s3;
	length=s3.length();
	opr3.create_linkedList2(length);//将opr1创建成长度为length的链表
	back=opr3.head->prev;
	for( i=length-1;i>=0;i--)//循环将其存储在链表中
	{
		back->data=s3[i]-'0';
		back=back->prev;
	}
}



//将文件f1的第n行数据存储在链表中
void bigNum::finput_store(linkedList& opr1,linkedList &opr2)//两个形参
{  
	//直接将文件中第n行的数据读入到内存中   
	int n1;
	cout<<"请输入第一个长整数要读取的行数"<<endl;
    cin>>n1;
	//第一个长整数读取文件中的第n1行字符串
    ifstream in1("f:\\f1.txt");//以输出方式打开文件   
    string line1;  
    if(in1) // 有该文件  
    {  
		for(int i=0;i<n1;i++)//找到文件中的第n行
             getline (in1, line1);
        cout<<line1<<endl;   
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }
	in1.close();
    //第二个长整数读取文件中的第n2行字符串
    ifstream in2("f:\\f1.txt");//以输出方式打开文件 
	int n2;
	cout<<"请输入第二个长整数要读取的行数"<<endl;
    cin>>n2; 
    string line2;  
    if(in2) // 有该文件  
    {  
		for(int i=0;i<n2;i++)//找到文件中的第n2行
             getline (in2, line2);
        cout<<line2<<endl;  
   
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }
	in2.close();
    //将line1和line2分别赋给链表B1,B2
	//第一个
	node*back;
	int i;
	int length=line1.length();
    opr1.create_linkedList2(length);
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line1[i]-'0';
		back=back->prev;
	}
    //第二个
	length=line2.length();
	opr2.create_linkedList2(length);
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)
	{
		back->data=line2[i]-'0';
		back=back->prev;
	}
}



//将文件中的第n行数据存储在链表中
void bigNum::finput_store(linkedList& opr1,linkedList &opr2,linkedList &opr3)//三个形参
{  
	//直接将文件中第n行的数据读入到内存中   
	int n1;
	cout<<"请输入第一个长整数要读取的行数"<<endl;
    cin>>n1;
	//第一个长整数读取文件中的第n1行字符串
    ifstream in1("f:\\f1.txt");   
    string line1;  
    if(in1) // 有该文件  
    {  
		for(int i=0;i<n1;i++)//找到文件中的第n行
             getline (in1, line1);//读取整行
        cout<<line1<<endl;   
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }
	in1.close();
    //第二个长整数读取文件中的第n2行字符串
    ifstream in2("f:\\f1.txt");
	int n2;
	cout<<"请输入第二个长整数要读取的行数"<<endl;
    cin>>n2; 
    string line2;  
    if(in2) // 有该文件  
    {  
		for(int i=0;i<n2;i++)//找到文件中的第n2行
             getline (in2, line2);//读取整行
        cout<<line2<<endl;  
   
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }
	in2.close();
    //第一个长整数读取文件中的第n1行字符串
	ifstream in3("f:\\f1.txt");
	int n3;
	cout<<"请输入第二个长整数要读取的行数"<<endl;
    cin>>n3; 
    string line3;  
    if(in3) // 有该文件  
    {  
		for(int i=0;i<n3;i++)//找到文件中的第n3行
             getline (in3, line3);//读取整行
        cout<<line3<<endl;  
   
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }
	in3.close();
    //将line1和line2和line3分别赋给链表B1,B2,B3
	//第一个
	node*back;
	int i;
	int length=line1.length();
    opr1.create_linkedList2(length);
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line1[i]-'0';
		back=back->prev;
	}
    //第二个
	length=line2.length();
	opr2.create_linkedList2(length);
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)
	{
		back->data=line2[i]-'0';
		back=back->prev;
	}
	//第三个
	length=line3.length();
    opr3.create_linkedList2(length);
	back=opr3.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line3[i]-'0';
		back=back->prev;
	}
}



//将结果换行输出至文件ad5中
void bigNum::fout_put(string & s1)
{
	//以输出方式代开并将结果输出至文件尾
	ofstream out("f:\\ad5.txt",ios::out | ios::app);
    out.write("\n",1); //接着原来的数据换行输出至文件中
	if(!out)
	{
		cout<<"open add.txt error!"<<endl;
	}
	else   out<<s1;
}



//将文件ad5内容全部输入到显示器
void bigNum::fdisplay()
{
	ifstream in("f:\\ad5.txt");   
    string line;  
    if(in) // 有该文件  
    {  
        while (getline (in, line)) 
		{
            cout<<line<<endl;  
        }  
    }  
    else // 没有该文件  
    {  
        cout<<"no such file"<<endl;  
    }  
	in.close();//关闭文件
}



//大整数的加法
//如果不用引用传递而用值传递会出错，错误貌似在拷贝构造函数过程中
linkedList bigNum::add_bigNum(linkedList &opr1,linkedList &opr2)//两个参数,(文件)
{
	int i=cmplinklen(opr1,opr2);//比较opr1和opr2的长度
    if(i==1)//长度opr1>=opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1指向表尾节点
		node*ptr2=opr2.head->prev;//ptr2指向表尾节点
	    linkedList A1;
		A1.create_linkedList2(l1);//和链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;//ptr3指向表尾节点
		for(int j=0;j<l2;j++)//做较小的长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum记录每位的和
		    remainder=sum%10;//remainder为每位的结果
		    quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;

		}
		for(int k=l2;k<l1;k++)//做相差长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+quotient;//现在仅仅剩opr1的多余位
			remainder=sum%10;//remainder为每位的结果
			quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;
		}
		if(quotient==1)//最后的进位
		{
			A1.insert(1, 0);//在pos位置后插入节点
		}
       
         return A1;
	}
	
	else//长度opr1<opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		linkedList A1;
		A1.create_linkedList2(l2);//和链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		for(int j=0;j<l1;j++)//做较小的长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum记录每位的和
		    remainder=sum%10;//remainder为每位的结果
		    quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;

		}
		for(int k=l1;k<l2;k++)//做相差长度次循环
		{
			int sum,remainder;
			sum=ptr2->data+quotient;//现在仅仅剩opr2的多余位
			remainder=sum%10;//remainder为每位的结果
			quotient=sum/10;//quotient记录进位
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;
		}
		return A1;
	}  
}



//大整数的加法
void bigNum::add_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//三个参数,设置了程序运行时间(取余)
{
	time_t t1, t2;
    time(&t1);//起始时间
	int i=cmplinklen(opr1,opr2);//比较opr1和opr2的长度
	linkedList A1;
    if(i==1)//长度opr1>=opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1指向表尾节点
		node*ptr2=opr2.head->prev;//ptr2指向表尾节点
		A1.create_linkedList2(l1);//和链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		for(int j=0;j<l2;j++)//做较小的长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum记录每位的和
		    remainder=sum%10;//remainder为每位的结果
		    quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;

		}
		for(int k=l2;k<l1;k++)//做相差长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+quotient;//现在仅仅剩opr1的多余位
			remainder=sum%10;//remainder为每位的结果
			quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;
		}
		if(quotient==1)//最后的进位
		{
			A1.insert(1, 0);//在pos位置后插入节点
		}  
	}
	else//长度opr1<opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1指向表尾节点
		node*ptr2=opr2.head->prev;//ptr2指向表尾节点
		A1.create_linkedList2(l2);//和链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		for(int j=0;j<l1;j++)//做较小的长度次循环
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum记录每位的和
		    remainder=sum%10;//remainder为每位的结果
		    quotient=sum/10;//quotient记录进位
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;

		}
		for(int k=l1;k<l2;k++)//做相差长度次循环
		{
			int sum,remainder;
			sum=ptr2->data+quotient;//现在仅仅剩opr2的多余位
			remainder=sum%10;//remainder为每位的结果
			quotient=sum/10;//quotient记录进位
			ptr2=ptr2->prev;
			ptr3->data=remainder;//将结果计入和链表中
			ptr3=ptr3->prev;
		}
	}  

    A1=mod_bigNum(A1,opr3);//A1对opr3取余
	cout<<A1<<endl;
	time(&t2);//终止时间
	cout <<"运行时间为:"<<t2-t1<< endl;

}



//大整数的减法
void  bigNum::sub_bigNum(linkedList &opr1,linkedList &opr2)//两个参数,(文件)
{
	int l1=opr1.size();
	int l2=opr2.size();
	if(l1>l2)//长度opr1>opr2
	{
		node*ptr1=opr1.head->prev;//ptr1指向表尾节点
		node*ptr2=opr2.head->prev;//ptr2指向表尾节点
		linkedList A1;
		A1.create_linkedList2(l1);//差链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l2;i++)//做较小的长度次循环
		{    
			if((ptr1->data-sub)<ptr2->data)//退位后opr1<opr2
			{
				sum=ptr1->data+10-ptr2->data-sub;//从前一位借1,sum记录每位相减的差
				sub=1;//sub记录借位
			}
			else//opr2>opr1
			{
				sum=ptr1->data-ptr2->data-sub;//直接相减
				sub=0;//sub记录借位
			
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;
			ptr3=ptr3->prev;
		}
        for(int k=l2;k<l1;k++)//做相差长度次循环
		{
			if(ptr1->data<sub)//若此位为0
			{
			  sum=ptr1->data-sub+10;//从前一位借1,sum记录每位相减的差
		      sub=1;//sub记录借位
			}
		    else//若此位不为为0
			{
			 sum=ptr1->data-sub;
			 sub=0;//sub记录借位
			}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//若最大数位为0
		{
			A1.erase(1);//将0删除
		}
		cout<<A1<<endl;
	}
	if(l1<l2)//长度opr1<opr2
	{
		node*ptr1=opr1.head->prev;//ptr1指向表尾节点
		node*ptr2=opr2.head->prev;//ptr2指向表尾节点
		linkedList A1;
		A1.create_linkedList2(l2);//差链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l1;i++)//做较小的长度次循环
		{    
			if((ptr2->data-sub)<ptr1->data)
			{
				sum=ptr2->data+10-ptr1->data-sub;//从前一位借1,sum记录每位相减的差
				sub=1;//sub记录借位
			}
			else
			{
				sum=ptr2->data-ptr1->data-sub;//直接相减
				sub=0;//sub记录借位
			
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;//将结果记入链表
			ptr3=ptr3->prev;
		}
        for(int k=l1;k<l2;k++)//做相差长度次循环
		{
			if(ptr2->data<sub)//若此位为0
			{
			  sum=ptr2->data-sub+10;//从前一位借1,sum记录每位相减的差
		      sub=1;//sub记录借位
			}
		    else//若此位不为为0
			{
			 sum=ptr2->data-sub;
			 sub=0;//sub记录借位
			}
		    ptr2=ptr2->prev;
		    ptr3->data=sum;//将结果记入链表
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//若最大数位为0
		{
			A1.erase(1);//将0删除
		}
		cout<<"-"<<A1<<endl;}
	if(l1==l2)//l1与l2长度相等
	{   
		int m=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//循环用于比较两个长整数大小
		{
			//m=1时,第一个长整数大
			if(optr1->data>optr2->data)
			{
				m=1;break;
			}
			//m=2时,第二个长整数大
			else if(optr1->data<optr2->data)
			{
				m=2;break;
			}
			optr1=optr1->next;
			optr2=optr2->next;

		}
		if(m==0)//两个长整数相等
		{
			cout<<m<<endl;
		}
		if(m==1)//第一个长整数大
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//差链表长度为二者之中任意长度
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//循环位数次
			{
				if((ptr1->data-sub)<ptr2->data)
				{
					sum=ptr1->data+10-ptr2->data-sub;//从前一位借1,sum记录每位相减的差
				    sub=1;//sub记录借位
				}
			    else
				{
					sum=ptr1->data-ptr2->data-sub;//直接相减
				    sub=0;//sub记录借位
				}
			    ptr1=ptr1->prev;
		 	    ptr2=ptr2->prev;
			    ptr3->data=sum;//将结果记入链表
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//若最大数位为0
			{
			    A1.erase(1);//将0删除
			}
		    node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//存在0001情况,循环用于删除多余0
			{
			    delete ptr4;//删除
			    ptr4=ptr5;
		 	    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//链表长度减1
			}
		    ptr6->next=ptr4;//删除节点之后的连接操作
		    ptr4->prev=ptr6;
		    cout<<A1<<endl;
		}
		else if(m==2)//第二个长整数大
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//差链表长度为二者之中任意长度
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//循环位数次
			{
				if((ptr2->data-sub)<ptr1->data)
				{
					sum=ptr2->data+10-ptr1->data-sub;//从前一位借1,sum记录每位相减的差
				    sub=1;//sub记录借位
				}
			    else
				{
					sum=ptr2->data-ptr1->data-sub;//直接相减
				    sub=0;//sub记录借位
				}
			    ptr1=ptr1->prev;
			    ptr2=ptr2->prev;
			    ptr3->data=sum;//将结果记入链表
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//若最大数位为0
			{
			    A1.erase(1);//将0删除
			}
            node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//存在0001情况,循环用于删除多余0
			{
		 	    delete ptr4;//删除多余0
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//链表长度减1
			}
		    ptr6->next=ptr4;//删除节点之后的连接操作
		    ptr4->prev=ptr6;
		    cout<<"-"<<A1<<endl;
		}
	}	
}



//大整数减法
void  bigNum::sub_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//三个参数,设置了程序运行时间(取余)
{
	time_t t1, t2;//记录程序运行时间
    time(&t1);//起始时间
	int l1=opr1.size();
	int l2=opr2.size();
	if(l1>l2)//第一个长整数长度大于第二个长整数
	{
		node*ptr1=opr1.head->prev;//ptr1指向尾节点
		node*ptr2=opr2.head->prev;//ptr2指向尾节点
		linkedList A1;
		A1.create_linkedList2(l1);//差链表长度为opr1,opr2中长度较大者的长度
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l2;i++)//做较小的长度次循环
		{    
			if((ptr1->data-sub)<ptr2->data)
			{
				sum=ptr1->data+10-ptr2->data-sub;//从前一位借1,sum记录每位相减的差
				sub=1;//sub记录借位
			}
			else
			{
				sum=ptr1->data-ptr2->data-sub;//直接减
				sub=0;//sub记录借位
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;//将结果记入链表
			ptr3=ptr3->prev;
		}
        for(int k=l2;k<l1;k++)//做相差长度次循环
		{
			if(ptr1->data<sub)//若此位为0
			{
				sum=ptr1->data-sub+10;//向前一位借1
		        sub=1;//记录借位
			}
		    else
			{
				sum=ptr1->data-sub;//若此位不为0
			    sub=0;//记录借位
			}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;//将结果记入链表
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//若最大数位为0
		{
			A1.erase(1);//删除0
		}
		A1=mod_bigNum(A1,opr3);//取余操作
		cout<<A1<<endl;
	}
	if(l1<l2)//第一个长整数长度小于第二个长整数
	{
		cout<<"No Exit(Regardless of the negative)"<<endl;
	}
	if(l1==l2)//第一个长整数长度等于第二个长整数
	{   int m=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//循环比较两个大整数的大小
		{
			//m=1 opr1>opr2,m=2 opr1<opr2
			if(optr1->data>optr2->data)
			{
				m=1;break;
			}
			else if(optr1->data<optr2->data)
			{
				m=2;break;
			}
			optr1=optr1->next;
			optr2=optr2->next;
		}
		if(m==0)//opr1=opr2
		{
			cout<<m<<endl;//0对任何数取余均为0
		}
		if(m==1)//opr1>opr2
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//差链表长度为二者之中任意长度
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//循环位数次
			{
				if((ptr1->data-sub)<ptr2->data)
				{
					sum=ptr1->data+10-ptr2->data-sub;//从前一位借1,sum记录每位相减的差
				    sub=1;//记录借位
				}
			    else
				{
					sum=ptr1->data-ptr2->data-sub;//直接相减
				    sub=0;//记录借位
				}
			    ptr1=ptr1->prev;
			    ptr2=ptr2->prev;
			    ptr3->data=sum;//将结果记入链表中
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//若最大数位为0
			{
				A1.erase(1);//删除0
			}
		    node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//存在0001，循环实现删除
			{
				delete ptr4;//释放空间
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//长度减1
			}
		    ptr6->next=ptr4;
	     	ptr4->prev=ptr6;
		    A1=mod_bigNum(A1,opr3);//取余操作
		    cout<<A1<<endl;
		}
		else if(m==2)//opr1<opr2
		{
			cout<<"No Exit(Regardless of the negative)<<endl";
		}
	}
    time(&t2);//终止时间
    cout<<"运行时间:"<<t2-t1<<endl;	
}



//大整数乘法
linkedList bigNum::mul_bigNum(linkedList &opr1,linkedList &opr2)//两个形参
{
	//ptr3负责把每次相乘的结果记入链表,ptr4负责0000如图所示往前对位
	//                                        0000
 	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2用于从后往前实现相乘操作
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;//ptr1和ptr2用来判断两个链表是否为0链表
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//两个其中有一个为0
	{
		linkedList A1;
		A1.insert(0,0);//0链表
        return A1;
	}
	else
	{
		linkedList A1;
		A1.create_linkedList1(l1+l2);//积链表长度为二者之和,并全部初始化为0
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)//设置双重循环
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//跳出本次循环
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)//做第一个大整数位数次循环
			{ 
				//每次要相加三部分数字:
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//结果
			    temp=temp/10;//进位
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//进位后的结果记入链表
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//最大数位为0
			A1.erase(1);//删除0
	    return A1;
	}
}



//大整数乘法
void bigNum::mul_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//三个参数,设置了程序运行时间(取余)
{
	time_t t1, t2;//记录程序运行时间
    time(&t1);//记录起始时间
	//ptr3负责把每次相乘的结果记入链表,ptr4负责0000如图所示往前对位
	//                                        0000
	linkedList A1;
	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2用于从后往前实现相乘操作
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;//ptr1和ptr2用来判断两个链表是否为0链表
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//两个其中有一个为0
	{
		A1.insert(0,0);//0链表
	}
	else
	{
		A1.create_linkedList1(l1+l2);//积链表长度为二者之和,并全部初始化为0
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)//设置双重循环
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//跳出本次循环
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)//做第一个大整数位数次循环
			{  
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//结果
			    temp=temp/10;//进位
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//进位后的结果记入链表
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//最大数位为0
		    A1.erase(1);//删除0
	}
	 A1=mod_bigNum(A1,opr3);//取余操作
	 cout<<A1;
	 time(&t2);//终止时间
     cout<<"                                       *运行所需的时间为:"<<t2-t1<<"s"<< endl;	
}



//除法子函数--减法,此减法仅仅适用于大数减小数
linkedList bigNum::div_subbigNum(linkedList &opr1,linkedList &opr2)
{
	int l1=opr1.size();
	int l2=opr2.size();
	node*ptr1=opr1.head->prev;//指向链表尾
	node*ptr2=opr2.head->prev;//指向链表尾
	linkedList d;
	d.create_linkedList2(l1);//较长者的长度
	node*ptr3=d.head->prev;
	int sum,sub=0;
	for(int i=0;i<l2;i++)
	{    
		if((ptr1->data-sub)<ptr2->data)
		{
			sum=ptr1->data+10-ptr2->data-sub;//借位后相减
			sub=1;//记录借位
		}
		else
		{
			sum=ptr1->data-ptr2->data-sub;//直接相减
			sub=0;//记录借位
		}
		ptr1=ptr1->prev;
		ptr2=ptr2->prev;
		ptr3->data=sum;//将结果记入链表中
		ptr3=ptr3->prev;
	}
    for(int k=l2;k<l1;k++)//差位次循环
	{   
		if(ptr1->data<sub)//小于0
		{
			sum=ptr1->data-sub+10;//借位相减
		    sub=1;//记录借位
		}
		else
		{
			sum=ptr1->data-sub;//直接相减
			sub=0;//借位
		}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;//将结果记入链表中
		    ptr3=ptr3->prev;
	}
	node*ptr4=d.head->next;
    node*ptr5=ptr4->next;
    node*ptr6=d.head;
	while(ptr4->data==0&&d.size()>1)//存在0001情况,循环用于删除多余0
	{
		 	    delete ptr4;//删除多余0
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    d.lsize=d.lsize-1;//链表长度减1
	}
	ptr6->next=ptr4;//删除节点之后的连接操作
    ptr4->prev=ptr6;
	return d;
}



//大整数除法
linkedList bigNum::div_bigNum(linkedList &opr1,linkedList &opr2)//两个参数
{	
	if(compare(opr1,opr2)==-1)//除数比被除数大的情况
	{
		linkedList s;
		s.insert(0,0);
		return s;
	}
	else//除数和被除数相等或被除数比除数大的情况 
	{
		if(opr2.head->next->data==0)//除数为0的情况
		{
			cout<<"No Exit"<<endl;
		    linkedList s;//仅仅有头节点的链表
		    return  s;
		}
	    else if(opr1.head->next->data==0)//被除数为0的情况
		{
		    linkedList s;
		    s.insert(0,0);//0链表
		    return s;
		}
        else//其余情况
		{
		    linkedList c;
	        int m;
	        node*ptr;
	        int l1=opr1.size();
	        int l2=opr2.size();
	        linkedList s;//商
	        int clength=l2-1;
            if(clength!=0)
			{
				c.create_linkedList2(clength);
	            node*ptr1=c.head->next;
	            node*ptr2=opr1.head->next;
	            for(int i=0;i<l2-1;i++)//循环赋值
				{
					ptr1->data=ptr2->data;
		            ptr1=ptr1->next;
		            ptr2=ptr2->next;
				}
			}	
	        node*i1=opr1.head->next;
	        for(int k=0;k<l2-1;k++)//用i1记录i
		        i1=i1->next;
	        for(int i=l2-1;i<l1;i++)
			{
		       int cnt=0;//cnt记录相减次数
		       ptr=c.head->next;
		       if(ptr->data==0)//相减之后差为0,将0后的数代替0
			   {
			      node*change=c.head->next;
			      change->data=i1->data;
			   }
		       else//继续插入下一位数
			   {
			      c.insert(i1->data,c.size());

			   }
		       while( (m=compare(c,opr2))!=-1)//比较两个数的大小
			   {
			      c=div_subbigNum(c,opr2);//做连减
			      cnt++;//记录连减次数
			
			   }
		       i1=i1->next;
		       s.insert(cnt,s.size());//将每次连减的次数插入到s中
		   }
	       if(s.head->next->data==0)//若最大数为0
			   s.erase(1);//删除0
           return s;
	   }
	}
}



//大整数的除法
void bigNum::div_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//三个参数,设置了程序运行时间(取余)
{
	time_t t1, t2;//记录程序运行时间
    time(&t1);//记录起始时间
	if(compare(opr1,opr2)==-1)//除数比被除数大的情况
	{
		linkedList s;
		s.insert(0,0);
		cout<<s;
	}
	else//除数和被除数相等或被除数比除数大的情况
	{	
		if(opr2.head->next->data==0)//除数为0
		{
		    cout<<"No Exit"<<endl;
		}
	    else if(opr1.head->next->data==0)//被除数为0
		{
		    linkedList s;
		    s.insert(0,0);//0链表
		    cout<<s;
		}
	    else//其余情况
		{
			linkedList c,s;
	        int m;
	        node*ptr;
	        int l1=opr1.size();
	        int l2=opr2.size();
	        int clength=l2-1;
            if(clength!=0)
			{
				c.create_linkedList2(clength);
	            node*ptr1=c.head->next;
	            node*ptr2=opr1.head->next;
	            for(int i=0;i<l2-1;i++)//循环赋值
				{
					ptr1->data=ptr2->data;
		            ptr1=ptr1->next;
		            ptr2=ptr2->next;
				}
			}	
	        node*i1=opr1.head->next;
	        for(int k=0;k<l2-1;k++)//用i1记录i
		        i1=i1->next;
	        for(int i=l2-1;i<l1;i++)
			{
				int cnt=0;//cnt记录相减次数
		        ptr=c.head->next;
		        if(ptr->data==0)//相减之后差为0,将0后的数代替0
				{
					node*change=c.head->next;
			        change->data=i1->data;
				}
		        else
				{
					c.insert(i1->data,c.size());//继续插入下一位数

				}
		        while( (m=compare(c,opr2))!=-1)//比较两个数的大小
				{
					c=div_subbigNum(c,opr2);//连减
			        cnt++;//记录连减次数
				}
		        i1=i1->next;
		        s.insert(cnt,s.size());//将每次连减的次数插入到s中
			}
	
	        if(s.head->next->data==0)//若最大数为0
				s.erase(1);//删除0
	        s=mod_bigNum(s,opr3);//取余
            cout<<s;
		}	
	}
	time(&t2);//终止时间
    cout<<"                                       *运行所需的时间为:"<<t2-t1<<"s"<< endl;
}



//大整数取模
linkedList bigNum::mod_bigNum(linkedList &opr1,linkedList &opr2)
{
	linkedList c;
	if(compare(opr1,opr2)==-1)//模数比被模数大的情况
	{
		c=opr1;
	}
	else{
		if(opr2.head->next->data==0)//模数为零的情况
		{
		   cout<<"Modulus is not zero";
		}
	    int m;
	    node*ptr;
	    int l1=opr1.size();
	    int l2=opr2.size();
	    linkedList s;
	    int clength=l2-1;
        if(clength!=0)
		{
		    c.create_linkedList2(clength);
	        node*ptr1=c.head->next;
	        node*ptr2=opr1.head->next;
	        for(int i=0;i<l2-1;i++)
			{
			    ptr1->data=ptr2->data;
		        ptr1=ptr1->next;
		        ptr2=ptr2->next;
			}
		}	
	    node*i1=opr1.head->next;
	    for(int k=0;k<l2-1;k++)//用i1记录i
		   i1=i1->next;
	    for(int i=l2-1;i<l1;i++)
		{
		   int cnt=0;
		   ptr=c.head->next;
		   if(ptr->data==0)
		   {
			  node*change=c.head->next;
			  change->data=i1->data;
		   }
		   else
		   {
			  c.insert(i1->data,c.size());

		   }
		   while( (m=compare(c,opr2))!=-1)
		   {
			  c=div_subbigNum(c,opr2);//连减
			  cnt++;
			
		   }
		   i1=i1->next;
		}
	}
	return c;//余数
}



//用于指数运算的乘法子函数
linkedList bigNum::ind_mulbigNum(linkedList &opr1,linkedList &opr2)
{   
    //ptr3负责把每次相乘的结果记入链表,ptr4负责0000如图所示往前对位
	//                                        0000
	linkedList A1;
	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2用于从后往前实现相乘操作
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//其中有一个因数为0
	{
		A1.insert(0,0);//0链表
	}
	else
	{
		A1.create_linkedList1(l1+l2);//长度为两链表长度之和
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//跳出本次循环
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)
			{  
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//结果
			    temp=temp/10;//进位
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//进位后的结果记入链表
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//最大数位为0
		    A1.erase(1);//删除0
	}
	 return A1;
}



//大整数指数运算
linkedList bigNum::ind_bigNum(linkedList opr1,linkedList opr2)
{
	linkedList c;
    if(opr2.size()==1&&opr2.head->next->data==0)//指数是0的情况
	{
		c.insert(1,0);
	}
	else if(opr2.size()==1&&opr2.head->next->data==1)//指数是1的情况
	{
		c=opr1;
	}
	else
	{
		linkedList a;
        a.insert(1,0);
	    c=ind_mulbigNum(opr1,opr1);//做一次乘法,平方
	    opr2=div_subbigNum(opr2,a);//循环次数减1
	    while(compare(opr2,a)==1)//若opr2>=1
		{
		    c=ind_mulbigNum(c,opr1);//连乘
		    opr2=div_subbigNum(opr2,a);//循环次数减1
		}
	}
	return c;	
}



//大整数指数运算
void bigNum::ind_bigNum(linkedList opr1,linkedList opr2,linkedList &opr3)//三个参数,设置了程序运行时间(取余)
{
	time_t t1, t2;//记录程序运行时间
    time(&t1);//记录起始时间
	linkedList c;
	if(opr2.size()==1&&opr2.head->next->data==0)//指数是0的情况
	{
		c.insert(1,0);
	}
	else if(opr2.size()==1&&opr2.head->next->data==1)//指数是1的情况
	{
		c=opr1;
	}
	else
	{
		linkedList a;
        a.insert(1,0);
	    c=ind_mulbigNum(opr1,opr1);//先做一次乘法,平方
	    opr2=div_subbigNum(opr2,a);//循环次数减1
	    while(compare(opr2,a)==1)//当opr2>=1
		{
		   c=ind_mulbigNum(c,opr1);//连乘
		   opr2=div_subbigNum(opr2,a);//循环次数减1
		}
	}
	c=mod_bigNum(c,opr3);//取余
	cout<<c;
	time(&t2);//终止时间
	cout<<"                                       *运行所需的时间为:"<<t2-t1<<"s"<< endl;
}



//析构函数
linkedList::~linkedList()//析构函数，释放内存
{   
	int i;
	node*ptr=head;
	node*douptr;
	for(i=0;i<=lsize;i++)//释放节点空间
	{
		douptr=ptr;
	    ptr=ptr->next;
	    delete douptr;
    }
}

