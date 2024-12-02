#pragma once
#include<iostream>
using namespace std;


//身份抽象基类
class Identity 
{
public:

	//操作菜单  纯虚函数
	virtual void operMenu() = 0;//子类重写父类纯虚函数，否则子类为抽象类 无法实例化对象
	

	//用户名
	string m_Name;
	//密码
	string m_Pwd;


};//多态