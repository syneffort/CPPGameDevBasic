
# include <iostream>

using namespace std;

#define NAME_SIZE 32

enum MAP_TYPE
{
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_EXIT
};

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');

		return INT_MAX;
	}

	return iInput;
}

void AddMonster(_tagMonster* pMonster)
{
	int iMap = 0;
	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "�߰��� ���̵��� �����ϼ��� : ";
		iMap = InputInt();

		if (iMap == 4)
			return;
		else if (iMap < 1 || iMap > 4)
			continue;

		iMap--;
		break;
	}

	
}

int main()
{
	_tagMonster tMonster[MT_END] = {};
	while (true)
	{
		system("cls");
		cout << "1. ���� �߰�" << endl;
		cout << "2. �о����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu = InputInt();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_ADD:
			AddMonster(tMonster);
			break;
		case MM_LOAD:
			break;
		case MM_SAVE:
			break;
		}
	}

	return 0;
}