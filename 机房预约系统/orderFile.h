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

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void upateOrder();

	//��ȡ����
	//void cut(string inf);

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������   key��¼����  value  �����¼��ֵ����Ϣ 
	map<int, map<string, string>> m_order;
};