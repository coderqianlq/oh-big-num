#include <iostream>
using namespace std;
class node//节点类
{
   public:
      int data;     
      node *prev,*next;    
	  node():prev(NULL),next(NULL){}	  
      node(const int&item,node *prevNode=NULL,node *nextNode=NULL):
	  data(item), prev(prevNode),next(nextNode){ }

};
class linkedList//链表类
{       
	public:
		friend class bigNum;//将大整数类声明为链表类的友元类
		linkedList();//默认构造函数
		linkedList(const linkedList & obj);//拷贝构造函数
		linkedList & operator=(const linkedList& rhs);//赋值重载
		void create_linkedList1(int n);//创建双向循环链表并初始化为0
		void create_linkedList2(int n);//创建双向循环链表
		int size()const;//获取链表长度
		void insert(int item, int pos);//在pos位置后插入节点
		void erase(int pos);//删除节点
		void display(ostream & out);//直接输出链表数据
		~linkedList();//析构函数，释放内存
    private:
		node *head;//头指针
		int lsize;//长度
};
ostream & operator<<(ostream & ,linkedList & );
class bigNum
{
    public:
	    string translation(linkedList&opr);//将链表数据存储到字符串中
		void input_store(linkedList& opr1,linkedList &opr2);////输入两个字符串类型的操作数,并将其存储在链表中
		void input_store(linkedList& opr1,linkedList &opr2,linkedList &opr3);//输入三个字符串类型的操作数,并将其存储在链表中
		void finput_store(linkedList& opr1,linkedList &opr2);//将文件中的第n行数据存储在链表中
		void finput_store(linkedList& opr1,linkedList &opr2,linkedList &opr3);//将文件中的第n行数据存储在链表中
		void fout_put(string & s1);//将计算所得结果输出至文件的下一行
		void fdisplay();//将文件内容显示于屏幕
		int  compare(linkedList& opr1,linkedList &opr2);//比较两个长整数的大小
		int  cmplinklen(linkedList& opr1,linkedList &opr2);//链表长度比较
		linkedList add_bigNum(linkedList &opr1,linkedList &opr2);//加法
		void add_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		void sub_bigNum(linkedList &opr1,linkedList &opr2);//减法
		void sub_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		linkedList mul_bigNum(linkedList &opr1,linkedList &opr2);//乘法
		void mul_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		linkedList div_subbigNum(linkedList &opr1,linkedList &opr2);//除法子函数
		linkedList ind_mulbigNum(linkedList &opr1,linkedList &opr2);//指数子函数
		linkedList mod_bigNum(linkedList &opr1,linkedList &opr2);//取模
	    linkedList div_bigNum(linkedList &opr1,linkedList &opr2);//除法
		void div_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
	    linkedList ind_bigNum(linkedList opr1,linkedList opr2);//指数
		void ind_bigNum(linkedList opr1,linkedList opr2,linkedList &opr3);
};
 
