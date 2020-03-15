
# include <iostream>

using namespace std;

#define NAME_SIZE		32
#define PHONE_SIZE		14
#define ADDRESS_SIZE	128
#define STUDENT_MAX		10

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	int iStudentCount = 0;
	int iStudentNumber = 1;

	char strName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");

		//�޴� ���
		cout << "1. �л� ���" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� ã��" << endl;
		cout << "4. �л� ���" << endl;

		int iMenu;
		cout << "�޴��� �Է��ϼ��� : ";
		cin >> iMenu;
		if (cin.fail())
		{
			// ���� ���� �����
			cin.clear();
			
			// �Է� ���ۿ��� /n ����
			cin.ignore(1024, '\n');
		}


		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			
			cin.ignore(1024, '\n');

			cout << "============ �л� �߰� ============" << endl;

			if (iStudentCount == STUDENT_MAX)
				break;
			
			cout << "�̸� : ";
			cin.getline(tStudentArr[iStudentCount].strName, NAME_SIZE);
			
			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);
			
			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor
				+ tStudentArr[iStudentCount].iEng
				+ tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.0f;

			tStudentArr[iStudentCount].iNumber = iStudentCount;

			iStudentCount++;
			iStudentNumber++;

			cout << "�л� �߰� �Ϸ�" << endl;
			
			break;
		case MENU_DELETE:
			system("cls");
			cout << "============ �л� ���� ============" << endl;

			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; j++)
					{
						tStudentArr[j] = tStudentArr[j + 1];
					}

					iStudentCount--;

					cout << "�л��� �����Ͽ����ϴ�." << endl;
					break;
				}
			}

			break;
		case MENU_SEARCH:
			system("cls");
			cout << "============ �л� Ž�� ============" << endl;
			
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "���� : " << tStudentArr[i].iKor << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
					
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "============ �л� ��� ============" << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "�߸��� �޴��� �����߽��ϴ�." << endl;
			break;
		}

		system("pause");

	}

	return 0;
}