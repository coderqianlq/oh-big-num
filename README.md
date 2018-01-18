# bigNum
## 问题描述
密码学分为两类密码：对称密码和非对称密码。对称密码主要用于数据的加/解密，而非对称密码则主要用于认证、数字签名等场合。非对称密码在加密和解密时，是把加密的数据当作一个大的正整数来处理，这样就涉及到大整数的加、减、乘、除和指数运算等，同时，还需要对大整数进行输出。**请采用相应的数据结构实现大整数的加、减、乘、除和指数运算**，以及大整数的输入和输出。
## 基本实验要求
1. 要求采用链表来实现大整数的存储和运算，**不允许使用标准模板类的链表类(list)和函数**。同时要求可以从键盘输入大整数，也可以文件输入大整数，大整数可以输出至显示器，也可以输出至文件。大整数的存储、运算和显示，可以同时支持二进制和十进制，但至少要支持十进制。大整数输出显示时，必须能清楚地表达出整数的位数。测试时，各种情况都需要测试，并附上测试截图；要求测试例子要比较详尽，各种极限情况也要考虑到，测试的输出信息要详细易懂，表明各个功能的执行正确。
2. 要求大整数的长度可以不受限制，即大整数的十进制位数不受限制，可以为十几位的整数，也可以为500多位的整数，甚至更长；大整数的运算和显示时，只需要考虑正的大整数。如果可能的话，**请以秒为单位显示每次大整数运算的时间**。
3. 要求采用类的设计思路，不允许出现类以外的函数定义，但允许友元函数。主函数中只能出现类的成员函数的调用，不允许出现对其它函数的调用。
4. 要求采用多文件方式：.h文件存储类的声明，.cpp文件存储类的实现，主函数main存储在另外一个单独的cpp文件中。如果采用类模板，则类的声明和实现都放在.h文件中。
5. 不强制要求采用类模板，也不要求采用可视化窗口；要求源程序中有相应注释。
6. 要求采用Visual C++ 6.0及以上版本进行调试。
## 实验目的
1. 更好的掌握带有哑元节点的双向循环链表，会利用双向循环链表实现诸如插入、删除、遍历、输出等功能。
2. 了解并掌握大整数四则运算、取模运算以及指数运算的算法。
3. 掌握文件的输入输出操作，实现内存与硬盘的有效结合。
4. 熟练地掌握基本的调试能力，掌握断点调试方法。
5. 独立完成大型实验并提高自身的编程能力。
## 题目分析
1. 本程序实现任意长度的加法、减法、乘法、除法、指数运算。以用户和计算机的实现方式，即由计算机终端显示提示信息之后，由用户在键盘上输入任意长度的长整数并进行相应的运算，然后程序执行运算并将结果输出至显示屏中。
2. 在本程序中数字字符限定在0—9，输入字符可任意长，通常长整数为300~500位的大整数。输入字符串过程以回车换行结束。
3. **利用双向循环链表实现长整数的存储**，每一个节点存储一个整型变量。本程序仅仅考虑均为正整数的情况。 
4. 加、减、乘、除、指数运算是在取余操作下的加减乘除指数运算。
5. 既可以从键盘读入大整数进行相应操作也可以直接从文件中读入大整数进行相应操作。既可以将内存中的运行结果显示在屏幕中，也可以实现和硬盘中文件的连接将文件中内容显示在屏幕中。
6. 本实验重在运行准确性和运行效率。以秒为单位计算各个算法所运行的相应时间，并将程序运行时间显示在屏幕上。
## 系统功能结构框图
<div align=center> 
  <img src="https://i.loli.net/2018/01/16/5a5d84bc897a2.png" alt="功能结构图" />
 ## 主要模块的功能说明
 - 主调程序模块：main_operation1()和main_operation2()为两个主调函数。main_operation1()不涉及文件，但有时间和取余操作；然而对于另一个主调函数main_operation2()而言，涉及文件并实现了硬盘文件和内存的输入输出操作。main()函数总揽全局，实现四则运算及指数运算功能。
 - 双向链表处理模块：create_linkedList1(int n）创建双向循环链表并初始化为0,create_linkedList2(int n)创建双向循环链表，size()用于获取链表长度，insert(int item, int pos)实现在pos位置后插入节点，将节点数据部分赋值为item, erase(int pos)用于删除pos处的节点， display(ostream & out)直接输出链表数据，将最后加减乘除指数运算所得结果输出至屏幕。
- 长整数运算模块：add_bigNum(linkedList & opr1,linkedList & opr2)实现长整数加法运算，sub_bigNum(linkedList & opr1,linkedList & opr2)实现长整数的减法运算mul_bigNum(linkedList & opr1,linkedList & opr2)实现长整数的乘法运算，div_bigNum(linkedList & opr1,linkedList & opr2)实现长整数的除法运算，mod_bigNum(linkedList & opr1,linkedList & opr2)实现长整数的取模运算，ind_bigNum(linkedList & opr1,linkedList & opr2)实现长整数的指数运算。
- 界面模块：welcome()用户欢迎界面，title()不涉及文件的标题界面。
## 数据结构的设计
1. 节点类
```c++
class node
{
    public:
      int data;     
      node *prev,*next;    
      node():prev(NULL),next(NULL){}	  
      node(const int&item,node *prevNode=NULL,node *nextNode=NULL):
      data(item), prev(prevNode),next(nextNode){ }
};
```
2. 链表类
```c++
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
```
3. 大整数类
```c++
class bigNum
{
    public:
      string translation(linkedList&opr);//将链表数据存储到字符串中
      void input_store(linkedList& opr1,linkedList &opr2);
      //输入两个字符串类型的操作数,并将其存储在链表中
      void finput_store(linkedList& opr1,linkedList &opr2);
      //将文件中的第n行数据存储在链表中
      void fout_put(string & s1);//将计算所得结果输出至文件的下一行
      void fdisplay();//将文件内容显示于屏幕
      int  compare(linkedList& opr1,linkedList &opr2);
      //比较两个长整数的大小
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
```
## 程序主要功能流程图
<div align=center> 
  <img src="https://i.loli.net/2018/01/18/5a60508e147eb.png" alt="功能结构图" />
 ## 主要函数的设计
1. add_bigNum加法函数的设计思路:
设计两次循环，并非两重循环。第一次循环循环位数少的大整数位次，第二次循环循环差位次。在此过程中主要设计了三个变量用于记录循环过程中的各个数据 。有sum记录每位相加的和，remainder记录对和取余的结果,quotient记录相加后的进位数。设计思想和整数的加法一致，即为满10进位。以下为加法运算过程举例：2583+796
<table>
    <thead>
        <tr>
        	<th></th>
            <th>sum</th>
            <th>remainder</th>
            <th>quotient</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>j=0</td>
            <td>9</td>
            <td>9</td>
            <td>0</td>
        </tr>
        <tr>
            <td>j=1</td>
            <td>17</td>
            <td>7</td>
            <td>1</td>
        </tr>
        <tr>
            <td>j=2</td>
            <td>13</td>
            <td>3</td>
            <td>1</td>
        </tr>
        <tr>
            <td>k=3</td>
            <td>3</td>
            <td>3</td>
            <td>0</td>
        </tr>
    </tbody>
</table>
2. sub_bigNum减法函数的设计思路：
同为设计两次循环，第一次循环循环位数少的大整数位数次，第二循环循环差位次。与加法所不同的是减法所分情况较多。总的来看，减法分三种情况：第一个大整数位数多于第二个大整数；第一个大整数位数小于第二个大整数；两个大整数的位数相等。然而在第三种情况中又被细分为另外三种情况：第一个长整数大于第二个长整数；第一个长整数小于第二个长整数；两个长整数大小相等。在循环过程中主要设计了连个变量用于记录循环过程中的各个数据。有sum记录每位相减的差以及sub记录借位或换句话来说退位数。设计思路大体来看符合整数减法设计思路，即为不足向前借位相减。以下为减法运算过程举例：1059-98
<table>
    <thead>
        <tr>
        	<th></th>
            <th>sum</th>
            <th>sub</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>i=1</td>
            <td>1</td>
            <td>0</td>
        </tr>
        <tr>
            <td>i=2</td>
            <td>6</td>
            <td>1</td>
        </tr>
        <tr>
            <td>k=2</td>
            <td>9</td>
            <td>1</td>
        </tr>
        <tr>
            <td>k=3</td>
            <td>0</td>
            <td>0</td>
        </tr>
    </tbody>
</table>
3. mul_bigNum乘法函数的设计思路：
乘法这里并未采用加法的连续相加，那样虽然思路清晰算法简单但是程序运行效率极其低下。与加减法不同的是乘法过程中运用了两重循环而并非两次循环。外层循环执行第二个因数的位数次，内层循环执行第一个因数的位数次。设计思路与整数乘法思路类似。即为从右边起依次用第二个因数的各位去乘第一个因数的各个数位，乘到哪一位，得数的末尾就和第二个因数的哪一位对齐，让后把几次相乘的结果相加。整数末尾有0的乘法大可不必担心，直接跳出本次双重循环，因为原链表已被初始化为全0链表。以下为乘法运算过程举例：128*46
<table>
    <thead>
        <tr>
        	<th>i\j</th>
            <th>0</th>
            <th>1</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td>temp=48	  temp=4</td>
            <td>temp=38   temp=3</td>
        </tr>
        <tr>
            <td>1</td>
            <td>temp=16   temp=1</td>
            <td>temp=8    temp=1</td>
        </tr>
        <tr>
            <td>2</td>
            <td>temp=7    temp=0</td>
            <td>temp=5    temp=0</td>
        </tr>
    </tbody>
</table>
4. div_bigNum除法函数mod_bigNum取模函数的设计思路：
二者的设计思路一脉相承,除法运算涉及到了连减运算，除数是几位，先看被除数的前几位，前几位不够除，多看一位，除到哪位，商就写在哪位上面，不够商一，0占位。余数要比除数小。在本程序的运行中，设置了双重循环。外层循环的循环次数正好为商的位数，而内层循环则负责连续做减法。在循环过程中，设计了两个变量来记录循环过程中的各个数据。链表对象c,将每次减法后得到的差赋给c，c再作为被减数继续做连减操作。整型变量cnt用于记录执行连减运算的次数，每一轮外层循环后得到的次数的值即为商的每一位，而最后得到的链表c即为余数。 故在计算商的过程中自然而然就将余数也一并计算得到了。以下为string类型的除法算法及代码：
```c++
string diving(string a,string b)
{
	string s,c;
	c=a.substr(0,b.length()-1);
	for(int i=b.length()-1;i<a.length();i++)
	{
		int cnt=0;
		for(c=(c=="0"?string():c)+a[i];!numLess(c,b);cnt++)
		c=subing(c,b);
		s+=char(cnt+'0');
	}
	return s[0]=='0'?s.substr(1):s;
}
```
5. ind_bigNum指数函数：
指数运算可以分解为多次乘法运算，其中用到了连乘操作。故运行速率较为缓慢。由于和乘法类似，故在此处不做多余赘述。
## 实验验证分析
- 输入的形式和输入值的范围；
- 输出的形式；
- 程序所能达到的功能；
- 测试数据：正确的输入及输出结果；
1. 输入的形式：以字符串形式从键盘上输入或以字符串形式从硬盘中文件中输入；输入值得范围在0~9的数字字符。大整数的长度可以不受限制，即大整数的十进制位数不受限制，可以为十几位的整数，也可以为500多位的整数，甚至更长；
2. 输出的形式：重载了输出函数，将储存在链表每一个节点中的整型数据从头到尾一个一个输出至显示屏中
3. 程序所能达到的功能：实现由键盘输入的大整数的加、减、乘、除、取余、指数运算以及从硬盘文件中导入的大整数的加、减、乘、除、取余、指数运算并把计算所得结果输出至文件中保存。还可以将指定文件中的全部内容显示在屏幕上。程序中设计了程序运行时间记录，可以将程序的运行时间以秒为单位输出在屏幕上。
4. 程序测试
（1）程序运行环境为DOS界面，执行文件为长整数加减乘除指数运算
（2）进入演示程序后即显示文本方式的用户欢迎界面
5. 演示略
## 调度分析
1.
(1)技术问题：采用何种数据结构来存储并实现大整数的各种运算。
  解决方法：采用带有哑元节点的双向循环链表存储数据，并实现大整数运算。链表的每一个节点中存放一个整型数据，无论是插入删除还是倒叙遍历链表， 双向循环链表都比较方便。
(2)技术问题：在类内定义友元函数重载输出流出现错误。
  解决方法：在类外重载输出函数，将display(ostream & out)函数定义为链链表类内的成员函数，并用重载的输出函数调用display()函数实现链表中数据的直接输出。
(3)技术问题：操作正确无误但就是无法实现与硬盘文件的关联。
  解决方法：将文件保存在C盘会出现错误，如果更改文件保存路径将文件保存到D盘即可实现与文件的关联。
2.
(1)在大整数减法运算中涉及情况颇多，过程较为繁琐。大体上分为三种情况:第一个长整数的长度大于第二个长整数；第一个长整数的长度小于第二个长整数；两个长整数的长度相等。而第三种情况又被分割为三种情况：第一个长整数大于第二个长整数；第一个长整数小于第二个长整数；两个长整数大小相等。
(2)在减法运算过程中的较小数减较大数的过程中，结果会出现负值。要知道我们设计的双向循环链表的每一个节点保存一个整型变量，故”—”号无法作为整型数据插入到链表中，我们只能简单的凭借输出时将负号直接输出。
(3)在除法运算过程中如果使用一味的连减操作来实现除法功能的话会使程序的运行速率大大降低，甚至如果是几百位的大整数的话就无法跑出程序结果而使程序崩溃。在这里采用我们平常的整数除法算法会使程序运行速率大大提高，外层循环次数就是商最后的位数。
3.
(1)调试错误：在调试过程中，当返回一个链表对象进入拷贝构造函数出现问题
   修正方法：当定义了除了默认的构造函数之外的构造函数时，譬如拷贝构造函数。当调用拷贝构造函数时，系统不会自动调用默认的构造函数。因为哑元节点实是在默认的构造函数中定义的，所以调用本程序原本设计的拷贝构造函数时不会创建哑元节点，故应该在拷贝构造函数中加入哑元节点的构建。
(2)调试错误：在调试过程中，当计算12321/1202的值时，结果会出现错误。与计算机计算出的真实结果有较大偏差。
   修正方法：经过断点调试发现，除法子函数即自定义的专门用于除法的减法函数做差之后的结果会出现0030诸如此类的状况。故针对此类错误，只需要在子函数尾部加上循环删除0即可，但循环进行条件应为ptr4->data==0&&d.size(）>1,否则跳出循环执行循环外的操作。但是要明确一点：因为此种删除操作并不是调用erase()函数实现的删除节点操作，删除完节点后它并不会将链表连接起来，故需要我们添加连接链表的操作。否则跳入拷贝构造函数时依然会报错。
(3)调试错误：在调试过程中，当做到除法实现和文件的连接时，系统会报错。
   修正方法：纵观程序代码会发现，当除数为0的时候，会输出0不能作为除数的字样，但此时并未返回值。然而本函数必须要返回一个链表对象，故当除数为0时，返回一个仅有哑元节点的空链表。还需要设置条件，如果链表长度为0的话便不会将链表内容输出至屏幕或输出至文件。
(4)调试错误：在调试过程中，当涉及ch=getchar()，getchar(）来读取操作命令时，总会出现请重新输入的字样。说明我们输入的命令数并非在0~9之间。然而我们确实输入了0~9之间二代任意数字。
   修正方法：经过上网查阅资料得知，getchar()会将回车符一并读入，故会出错误。这是只需要做fflush(stdin)操作即可清除缓存，问题也便迎刃而解了。
## 测试结果
略