#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"


//学生类
class Student :public Identity 
{
public:
	//默认构造
	Student();
	//有参构造  参数：学号、姓名、密码
	Student(int id, string name,string pwd);

	//菜单界面
	virtual void operMenu();//子类重写父类纯虚函数，否则子类为抽象类 无法实例化对象

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//机房容器
	vector<ComputerRoom> vCom;

	//学生学号
	int m_Id;

};