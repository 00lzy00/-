#pragma once
#include<iostream>
using namespace std;


//��ݳ������
class Identity 
{
public:

	//�����˵�  ���麯��
	virtual void operMenu() = 0;//������д���ി�麯������������Ϊ������ �޷�ʵ��������
	

	//�û���
	string m_Name;
	//����
	string m_Pwd;


};//��̬