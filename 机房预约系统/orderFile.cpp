#include"orderFile.h"


//截取时间段
void cut(const string inf,map<string, string>&m)//引用传递 每次调用cut函数时都会更新同一个map对象
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

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

	this->m_Size = 0;//记录条数
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

	//测试最大map容器
	/*for (map<int, map<string, string>>::iterator it = m_order.begin(); it != m_order.end();it++)
	{
		cout << "记录条数为： " << it->first << " value = " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key = " << mit->first << " " <<" value = "<< mit->second << " ";
		}
		cout << endl;
	}*/

}


//更新预约记录
void OrderFile::upateOrder()
{
	if (this->m_Size == 0)
	{
		return;//预约记录0条 直接return
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//写入模式打开文件，并且如果文件已存在则清空原有内容

	for (int i = 0; i < this->m_Size; i++) 
	{
		ofs << "date:" << this->m_order[i]["date"] << " "; //date 为 map<string, string>键值key
		ofs << "interval:" << this->m_order[i]["interval"] << " ";
		ofs << "stuId:" << this->m_order[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_order[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_order[i]["roomId"] << " ";
		ofs << "status:" << this->m_order[i]["status"] << endl;
	}
	ofs.close();

}