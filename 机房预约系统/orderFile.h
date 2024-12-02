#pragma once
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include<algorithm>
#include<fstream>
#include<map>

class OrderFile 
{
public:

	//构造函数
	OrderFile();

	//更新预约记录
	void upateOrder();

	//截取函数
	//void cut(string inf);

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器   key记录条数  value  具体记录键值对信息 
	map<int, map<string, string>> m_order;
};