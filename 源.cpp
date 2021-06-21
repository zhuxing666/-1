#include<iostream>
using namespace std;
#include<string>
#define MAX  500
struct Person
{
	string m_Name;
	int m_Age;
	int m_Sex;
	int m_Phone;
	string m_Addr;

};

struct Addressbooks
{
	struct Person  PersonArray[MAX];
	int  m_Size;
};

void showMenu()      
{
	cout << "           ͨѶ¼          " << endl;
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks*abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "��������Ҫ��ӵ���ϵ�ˣ�" << endl;
		string name;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex== 1 || sex== 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "���������������룡" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		cout << "�������ֻ��ţ�" << endl;
		int phone=0;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");

		
	}

}

void showPerson(Addressbooks*abs)
{
	if (abs->m_Size == 0)
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->PersonArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->PersonArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int  isExist(Addressbooks*abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->PersonArray[i].m_Name == name)

		{
			return i;
		}
		return -1;
	}
}

void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

void findPerson(Addressbooks*abs)
{
	cout << "��������Ҫ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
		if (ret != -1)
		{
			cout << "������" << abs->PersonArray[ret].m_Name << "\t";
			cout << "�Ա�" << abs->PersonArray[ret].m_Sex << "\t";
			cout << "���䣺" << abs->PersonArray[ret].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[ret].m_Phone << "\t";
			cout << "סַ��" << abs->PersonArray[ret].m_Addr << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");

}

void modifyPerson(Addressbooks* abs)
{

	cout << "��������Ҫ�޸���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		//�Ա�
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[ret].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		int phone = 0;
		cin >> phone;
		abs->PersonArray[ret].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

int  cleanPerson(Addressbooks*abs)
{
	cout << "�Ƿ�Ҫ���" << endl;
	int select = 0;
	cout << "1---yes" << endl;
	cout << "2����no" << endl;
	while (true)

	{
		cin >> select;
		if (select == 1)
		{
			abs->m_Size = 0;
			cout << "������" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "�´�����" << endl;
			system("pause");
			return 0;
		}
	}
	
}



int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		showMenu();
	
		cout << "���������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;


		default:
			break;
		}
		
	}
	system("pause");
	return 0;
}