#include<iostream>
using namespace std;
#include<string >
#define MAX 1000
struct Person//��ϵ�˽ṹ
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};

struct Addressbooks  //ͨѶ¼
{
	struct Person PersonArray[MAX];//ͨѶ¼�������ϵ������

	int m_Size; //��ǰͨѶ��ϵ�˸���
};

void showMenu()
{
	cout << "*******************" << endl;
	cout << "***1�������ϵ��***" << endl;
	cout << "***2����ʾ��ϵ��***" << endl;
	cout << "***3��ɾ����ϵ��***"<< endl;
	cout << "***4��������ϵ��***" << endl;
	cout << "***5���޸���ϵ��***" << endl;
	cout << "***6�������ϵ��***" << endl;
	cout << "***0���˳�ͨѶ¼***" << endl;
	cout << "*******************" << endl;
}

void addPerson(Addressbooks*abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		cout << "�������Ա� " << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}

		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;


		cout << "������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//��������
		cout << "����ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbooks*abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼����Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->PersonArray[i].m_Name << "\t";
			cout << "�Ա�" <<( abs->PersonArray[i].m_Sex==1?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->PersonArray[i].m_Addr << endl;
			
		}
		system("pause");
		system("cls");
	}
}


//�����ϵ��Ů���ڷ�
int IsExist(Addressbooks*abs,string name)
{
	for (int i = 0;i < abs->m_Size; i++)
	{
		if (abs->PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	IsExist(abs, name);
	int ret = IsExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//����ǰ��
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "δ�ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
		if (ret != 1)
		{
			cout << "������" << abs->PersonArray[ret].m_Name << "\t";
			cout << "�Ա�" << (abs->PersonArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->PersonArray[ret].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[ret].m_Phone << "\t";
			cout << "סַ��" << abs->PersonArray[ret].m_Addr << endl;
			
		}
		else
		{
			cout << "δ�ҵ�" << endl;
		}
		system("pause");
		system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret != -1)
	{
		cout << "�������޸ĵ�������" << endl;
		string name;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;

		cout << "�������Ա� " << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
	
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
		{
			abs->PersonArray[ret].m_Sex = sex;
			break;
		}
		cout << "����������������" << endl;
	}

	cout << "���������䣺 " << endl;
	int age = 0;
	cin >> age;
	abs->PersonArray[ret].m_Age = age;


	cout << "������ϵ�绰��" << endl;
	string phone;
	cin >> phone;
	abs->PersonArray[ret].m_Phone = phone;

	cout << "�������ͥסַ��" << endl;
	string address;
	cin >> address;
	abs->PersonArray[ret].m_Addr = address;

	cout << "�޸ĳɹ���" << endl;
	system("pause");
	system("cls");
}
	else
	{
	cout << "���޴���" << endl;
	}
}

//�����ϵ��
void cleanPerson(Addressbooks*abs)
{
	cout << "��ȷ��Ҫ��գ�" << endl;
	cout << "1====yes" << endl;
	cout << "2====no" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{

			abs->m_Size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else
		{
			cout << "��ʱ������" << endl;
			system("pause");
		}
	}
	    system("pause");
	    system("cls");
}


int main()
{
	Addressbooks abs;        //��ʼ��
	abs.m_Size = 0;

	int select = 0;//����ѡ��
	while (true)
	{
		//���ò˵�
		showMenu();
		cout << "���������ѡ�� " << endl;
		cin >> select;
		switch (select)
		{
		case 1: //1�������ϵ��
			addPerson(&abs);//����ʵ��
			break;
		case 2:                         //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:                        //3��ɾ����ϵ��
		/*{	cout << "������ɾ����ϵ��������" << endl;
		string name;
		cin >> name;
		if (IsExist(&abs, name) == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "�ҵ�����" << endl;
		}
		}*/
			deletePerson(&abs);
			break;
		case 4:                       //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:                        //5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:                        //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;  //0���˳�ͨѶ¼
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