
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

		//메뉴 출력
		cout << "1. 학생 등록" << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 찾기" << endl;
		cout << "4. 학생 출력" << endl;

		int iMenu;
		cout << "메뉴를 입력하세요 : ";
		cin >> iMenu;
		if (cin.fail())
		{
			// 에러 버퍼 지우기
			cin.clear();
			
			// 입력 버퍼에서 /n 삭제
			cin.ignore(1024, '\n');
		}


		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			
			cin.ignore(1024, '\n');

			cout << "============ 학생 추가 ============" << endl;

			if (iStudentCount == STUDENT_MAX)
				break;
			
			cout << "이름 : ";
			cin.getline(tStudentArr[iStudentCount].strName, NAME_SIZE);
			
			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);
			
			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor
				+ tStudentArr[iStudentCount].iEng
				+ tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.0f;

			tStudentArr[iStudentCount].iNumber = iStudentCount;

			iStudentCount++;
			iStudentNumber++;

			cout << "학생 추가 완료" << endl;
			
			break;
		case MENU_DELETE:
			system("cls");
			cout << "============ 학생 삭제 ============" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
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

					cout << "학생을 삭제하였습니다." << endl;
					break;
				}
			}

			break;
		case MENU_SEARCH:
			system("cls");
			cout << "============ 학생 탐색 ============" << endl;
			
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "============ 학생 출력 ============" << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "잘못된 메뉴를 선택했습니다." << endl;
			break;
		}

		system("pause");

	}

	return 0;
}