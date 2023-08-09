#include<iostream>
#include<string>
#include<fstream>

#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
typedef struct Person
{
	string m_name;
	string m_sex;
	int m_age;
	string m_phone;
	string m_adddress;
}Preson;
//ͨѶ¼�ṹ��
typedef struct AddressBook
{
	struct Person PersonArrary[MAX];
	int Size;
}AddressBook;

//�˵�
void ShowMenu()
{
	cout << "******************" << endl;
	cout << "***1.�����ϵ��***" << endl;
	cout << "***2.��ʾ��ϵ��***" << endl;
	cout << "***3.ɾ����ϵ��***" << endl;
	cout << "***4.������ϵ��***" << endl;
	cout << "***5.�޸���ϵ��***" << endl;
	cout << "***6.�����ϵ��***" << endl;
	cout << "***0.�˳�ͨѶ¼***" << endl;
	cout << "******************" << endl;
}
//�����ϵ��
void AddPreson(AddressBook* abs)
{
	//�ж�
	if (abs->Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//�������
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->PersonArrary[abs->Size].m_name = name;
		//�Ա�
		string sex;
		string s1 = "��";
		string s2 = "Ů";
		while (true)
		{
			cout << "�������Ա�:" << endl;
			cin >> sex;
			if (sex.compare(s1) == 0 || sex.compare(s2) == 0)
			{
				abs->PersonArrary[abs->Size].m_sex = sex;
				break;
			}
			else
			{
				cout << "���벻�Ϸ������������룡" << endl;
			}
		}
		//����
		cout << "����������:" << endl;
		int age;
		cin >> age;
		abs->PersonArrary[abs->Size].m_age = age;
		//�绰
		cout << "������绰����:" << endl;
		string phone;
		cin >> phone;
		abs->PersonArrary[abs->Size].m_phone = phone;
		//��ַ
		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArrary[abs->Size].m_adddress = address;
		//����
		abs->Size++;
		cout << "��ӳɹ�!" << endl;
		system("pause");  //�����������
 		system("cls");  //��������
   	}
}
//��ʾ������ϵ��
void ShowPerson(AddressBook* abs)
{
	//�ж�
	if (abs->Size == 0)
	{
		cout << "��ǰ��ϵ��Ϊ�գ�" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "������" << abs->PersonArrary[i].m_name << "\t";
			cout << "�Ա�" << abs->PersonArrary[i].m_sex << "\t";
			cout << "���䣺" << abs->PersonArrary[i].m_age << "\t";
			cout << "��ϵ��ʽ��" << abs->PersonArrary[i].m_phone << "\t";
			cout << "��ַ��" << abs->PersonArrary[i].m_adddress << endl;
		}
		system("pause");  //�����������
		system("cls");  //��������
	}
}
//�����ϵ���Ƿ����
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
//ɾ����ϵ��
void DeletePerson(AddressBook* abs)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		for (int i = t; i < abs->Size; i++)
		{
			abs->PersonArrary[i] = abs->PersonArrary[i + 1];
		}
		cout << "ɾ���ɹ���" << endl;
		abs->Size--;
	}
	else
	{
		cout << "����ϵ�˲����ڣ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void FindPerson(AddressBook* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		cout << "������" << abs->PersonArrary[t].m_name << "\t";
		cout << "�Ա�" << abs->PersonArrary[t].m_sex << "\t";
		cout << "���䣺" << abs->PersonArrary[t].m_age << "\t";
		cout << "��ϵ��ʽ��" << abs->PersonArrary[t].m_phone << "\t";
		cout << "��ַ��" << abs->PersonArrary[t].m_adddress << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void ModifyPerson(AddressBook* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int t = Exit(abs, name);
	if (t != -1)
	{
		while (true)
		{
			cout << "��ѡ��Ҫ�޸ĵ���Ŀ��" << endl;
			cout << "1.����" << endl;
			cout << "2.�Ա�" << endl;
			cout << "3.����" << endl;
			cout << "4.��ϵ��ʽ" << endl;
			cout << "5.��ַ" << endl;
			cout << "0.�˳�" << endl;
			int i;
			cin >> i;
			switch (i)
			{
			case 1:
			{cout << "�������µ�������" << endl;
			string name;
			cin >> name;
			abs->PersonArrary[t].m_name = name;
			cout << "�޸ĳɹ���" << endl;
			break;
			}
			case 2:
			{
				while (true)
				{
					cout << "�������µ��ձ�" << endl;
					string sex;
					cin >> sex;
					string s1 = "��";
					string s2 = "Ů";
					if (sex.compare(s1) == 0 || sex.compare(s2) == 0)
					{
						abs->PersonArrary[t].m_sex = sex;
						cout << "�޸ĳɹ���" << endl;
						break;
					}
					else
					{
						cout << "���벻�Ϸ�����������!" << endl;
					}
				}
				break;
			}
			case 3:
			{
				cout << "�������µ����䣺" << endl;
				int age;
				cin >> age;
				abs->PersonArrary[t].m_age = age;
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			case 4:
			{
				cout << "�������µ���ϵ��ʽ��" << endl;
				string phone;
				cin >> phone;
				abs->PersonArrary[t].m_phone = phone;
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			case 5:
			{
				cout << "�������µ�ַ��" << endl;
				string address;
				cin >> address;
				abs->PersonArrary[t].m_adddress = address;
				cout << "�޸ĳɹ���" << endl;
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
		cout << "��ϵ�˲�����!" << endl;
		system("pause");
		system("cls");
		return;
	}
}
//�����ϵ��
void ClearPerson(AddressBook* abs)
{
	cout << "��ȷ���Ƿ���գ��ǣ� ��" << endl;
	string choice;
	cin >> choice;
	string s1 = "��";
	if (choice.compare(s1) == 0)
	{
		abs->Size = 0;
		cout << "��ϵ������գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "δ��գ����˳���" << endl;
		return;
	}
}
// ���ļ��ж�ȡ��ϵ����Ϣ
void LoadFromFile(AddressBook* abs)
{
	ifstream inFile("contacts.txt");
	if (!inFile)
	{
		cout << "�޷����ļ�contacts.txt" << endl;
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

// ����ϵ����Ϣ���浽�ļ�
void SaveToFile(AddressBook* abs)
{
	ofstream outFile("contacts.txt");
	if (!outFile)
	{
		cout << "�޷����ļ�contacts.txt" << endl;
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
	//����ͨѶ¼
	AddressBook abs;
	//ͨѶ¼��ʼ��
	abs.Size = 0;
	LoadFromFile(&abs);
	while (true)
	{
		//�˵�����
		ShowMenu();
		cout << "��ѡ�����:" << endl;
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			AddPreson(&abs);
			break;
		case 2://��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			DeletePerson(&abs);
			break;
		case 4://������ϵ��
			FindPerson(&abs);
			break;
		case 5://�޸���ϵ��
			ModifyPerson(&abs);
			break;
		case 6://�����ϵ��
			ClearPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��!" << endl;
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