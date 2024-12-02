#include"orderFile.h"


//��ȡʱ���
void cut(const string inf,map<string, string>&m)//���ô��� ÿ�ε���cut����ʱ�������ͬһ��map����
{
	string key;
	string value;
	//map<string, string>m;
	int pos = inf.find(":");//4
	if (pos != -1)
	{
		key = inf.substr(0, pos);
		value = inf.substr(pos + 1, inf.size() - pos - 1); //size=9 pos=4 size-pos=5 - 1 =4
		m.insert(make_pair(key, value));
	}
	/*cout << "key=" << key << endl;
	cout << "value=" << value << endl;*/

}

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

	this->m_Size = 0;//��¼����
	while (ifs >> date && ifs >> interval && 
		ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//date:1111
		//string key;
		//string value;
		map<string, string>m;

		//int pos=date.find(":");//4
		//if (pos != -1)
		//{
		//	key = date.substr(0, pos);
		//	value = date.substr(pos + 1, date.size() - pos - 1); //size=9 pos=4 size-pos=5 - 1 =4
		//	m.insert(make_pair(key, value));
		//}
		cut(date,m);
		cut(interval,m);
		cut(stuId, m);
		cut(stuName, m);
		cut(roomId, m);
		cut(status, m);
		this->m_order.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//�������map����
	/*for (map<int, map<string, string>>::iterator it = m_order.begin(); it != m_order.end();it++)
	{
		cout << "��¼����Ϊ�� " << it->first << " value = " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key = " << mit->first << " " <<" value = "<< mit->second << " ";
		}
		cout << endl;
	}*/

}


//����ԤԼ��¼
void OrderFile::upateOrder()
{
	if (this->m_Size == 0)
	{
		return;//ԤԼ��¼0�� ֱ��return
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//д��ģʽ���ļ�����������ļ��Ѵ��������ԭ������

	for (int i = 0; i < this->m_Size; i++) 
	{
		ofs << "date:" << this->m_order[i]["date"] << " "; //date Ϊ map<string, string>��ֵkey
		ofs << "interval:" << this->m_order[i]["interval"] << " ";
		ofs << "stuId:" << this->m_order[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_order[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_order[i]["roomId"] << " ";
		ofs << "status:" << this->m_order[i]["status"] << endl;
	}
	ofs.close();

}