#include<iostream>
#include<string>
#include<fstream>

#define MAX 1000
using namespace std;

//联系人结构体
typedef struct Person
{
	string m_name;
	string m_sex;
	int m_age;
	string m_phone;
	string m_adddress;
}Preson;
//通讯录结构体
typedef struct AddressBook
{
	struct Person PersonArrary[MAX];
	int Size;
}AddressBook;

//菜单
void ShowMenu()
{
	cout << "******************" << endl;
	cout << "***1.添加联系人***" << endl;
	cout << "***2.显示联系人***" << endl;
	cout << "***3.删除联系人***" << endl;
	cout << "***4.查找联系人***" << endl;
	cout << "***5.修改联系人***" << endl;
	cout << "***6.清空联系人***" << endl;
	cout << "***0.退出通讯录***" << endl;
	cout << "******************" << endl;
}
//添加联系人
void AddPreson(AddressBook* abs)
{
	//判断
	if (abs->Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->PersonArrary[abs->Size].m_name = name;
		//性别
		string sex;
		string s1 = "男";
		string s2 = "女";
		while (true)
		{
			cout << "请输入性别:" << endl;
			cin >> sex;
			if (sex.compare(s1) == 0 || sex.compare(s2) == 0)
			{
				abs->PersonArrary[abs->Size].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入不合法，请重新输入！" << endl;
			}
		}
		//年龄
		cout << "请输入年龄:" << endl;
		int age;
		cin >> age;
		abs->PersonArrary[abs->Size].m_age = age;
		//电话
		cout << "请输入电话号码:" << endl;
		string phone;
		cin >> phone;
		abs->PersonArrary[abs->Size].m_phone = phone;
		//地址
		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->PersonArrary[abs->Size].m_adddress = address;
		//更新
		abs->Size++;
		cout << "添加成功!" << endl;
		system("pause");  //按任意键继续
 		system("cls");  //清屏操作
   	}
}
//显示所有联系人
void ShowPerson(AddressBook* abs)
{
	//判断
	if (abs->Size == 0)
	{
		cout << "当前联系人为空！" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "姓名：" << abs->PersonArrary[i].m_name << "\t";
			cout << "性别：" << abs->PersonArrary[i].m_sex << "\t";
			cout << "年龄：" << abs->PersonArrary[i].m_age << "\t";
			cout << "联系方式：" << abs->PersonArrary[i].m_phone << "\t";
			cout << "地址：" << abs->PersonArrary[i].m_adddress << endl;
		}
		system("pause");  //按任意键继续
		system("cls");  //清屏操作
	}
}
//检查联系人是否存在
int Exit(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->Size; i++)
	{
		if (abs->PersonArrary[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void DeletePerson(AddressBook* abs)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		for (int i = t; i < abs->Size; i++)
		{
			abs->PersonArrary[i] = abs->PersonArrary[i + 1];
		}
		cout << "删除成功！" << endl;
		abs->Size--;
	}
	else
	{
		cout << "该联系人不存在！" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void FindPerson(AddressBook* abs)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		cout << "姓名：" << abs->PersonArrary[t].m_name << "\t";
		cout << "性别：" << abs->PersonArrary[t].m_sex << "\t";
		cout << "年龄：" << abs->PersonArrary[t].m_age << "\t";
		cout << "联系方式：" << abs->PersonArrary[t].m_phone << "\t";
		cout << "地址：" << abs->PersonArrary[t].m_adddress << endl;
	}
	else
	{
		cout << "联系人不存在！" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void ModifyPerson(AddressBook* abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		while (true)
		{
			cout << "请选择要修改的项目：" << endl;
			cout << "1.姓名" << endl;
			cout << "2.性别" << endl;
			cout << "3.年龄" << endl;
			cout << "4.联系方式" << endl;
			cout << "5.地址" << endl;
			cout << "0.退出" << endl;
			int i;
			cin >> i;
			switch (i)
			{
			case 1:
			{cout << "请输入新的姓名：" << endl;
			string name;
			cin >> name;
			abs->PersonArrary[t].m_name = name;
			cout << "修改成功！" << endl;
			break;
			}
			case 2:
			{
				while (true)
				{
					cout << "请输入新的姓别：" << endl;
					string sex;
					cin >> sex;
					string s1 = "男";
					string s2 = "女";
					if (sex.compare(s1) == 0 || sex.compare(s2) == 0)
					{
						abs->PersonArrary[t].m_sex = sex;
						cout << "修改成功！" << endl;
						break;
					}
					else
					{
						cout << "输入不合法请重新输入!" << endl;
					}
				}
				break;
			}
			case 3:
			{
				cout << "请输入新的年龄：" << endl;
				int age;
				cin >> age;
				abs->PersonArrary[t].m_age = age;
				cout << "修改成功！" << endl;
				break;
			}
			case 4:
			{
				cout << "请输入新的联系方式：" << endl;
				string phone;
				cin >> phone;
				abs->PersonArrary[t].m_phone = phone;
				cout << "修改成功！" << endl;
				break;
			}
			case 5:
			{
				cout << "请输入新地址：" << endl;
				string address;
				cin >> address;
				abs->PersonArrary[t].m_adddress = address;
				cout << "修改成功！" << endl;
				break;
			}
			case 0:
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else
	{
		cout << "联系人不存在!" << endl;
		system("pause");
		system("cls");
		return;
	}
}
//清空联系人
void ClearPerson(AddressBook* abs)
{
	cout << "请确认是否清空，是？ 否？" << endl;
	string choice;
	cin >> choice;
	string s1 = "是";
	if (choice.compare(s1) == 0)
	{
		abs->Size = 0;
		cout << "联系人已清空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "未清空，已退出。" << endl;
		return;
	}
}
// 从文件中读取联系人信息
void LoadFromFile(AddressBook* abs)
{
	ifstream inFile("contacts.txt");
	if (!inFile)
	{
		cout << "无法打开文件contacts.txt" << endl;
		return;
	}

	abs->Size = 0;
	while (inFile >> abs->PersonArrary[abs->Size].m_name
		>> abs->PersonArrary[abs->Size].m_sex
		>> abs->PersonArrary[abs->Size].m_age
		>> abs->PersonArrary[abs->Size].m_phone
		>> abs->PersonArrary[abs->Size].m_adddress)
	{
		abs->Size++;
	}

	inFile.close();
}

// 将联系人信息保存到文件
void SaveToFile(AddressBook* abs)
{
	ofstream outFile("contacts.txt");
	if (!outFile)
	{
		cout << "无法打开文件contacts.txt" << endl;
		return;
	}

	for (int i = 0; i < abs->Size; i++)
	{
		outFile << abs->PersonArrary[i].m_name << " "
			<< abs->PersonArrary[i].m_sex << " "
			<< abs->PersonArrary[i].m_age << " "
			<< abs->PersonArrary[i].m_phone << " "
			<< abs->PersonArrary[i].m_adddress << endl;
	}

	outFile.close();
}

int main() 
{
	int select;                       
	//创建通讯录
	AddressBook abs;
	//通讯录初始化
	abs.Size = 0;
	LoadFromFile(&abs);
	while (true)
	{
		//菜单调用
		ShowMenu();
		cout << "请选择操作:" << endl;
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			AddPreson(&abs);
			break;
		case 2://显示联系人
			ShowPerson(&abs);
			break;
		case 3://删除联系人
			DeletePerson(&abs);
			break;
		case 4://查找联系人
			FindPerson(&abs);
			break;
		case 5://修改联系人
			ModifyPerson(&abs);
			break;
		case 6://清空联系人
			ClearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default :
			break;
		}
	}
	system("pause");
	return 0;
}