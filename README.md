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
  <img src="https://i.loli.net/2018/01/16/5a5d84bc897a2.png" width = "300" height = "200" alt="图片名称" />
