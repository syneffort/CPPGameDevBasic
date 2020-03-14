
#include <iostream>

using namespace std;

#define NAME_SIZE 32

struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	tStudent.iKor = 100;
	
	// 문자열을 배열에 복사
	strcpy_s(tStudent.strName, "Springfield");
	// 문자열을 붙이기
	strcat_s(tStudent.strName, " William");
	// 문자열 비교
	strcpy_s(tStudent.strName, "홍길동");
	cout << "비교할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0) // 0일 때 같은 문자열
	{
		cout << "학생을 찾았습니다." << endl;
	}
	else
		cout << "찾는 학생이 없습니다." << endl;

	cout << "이름 길이" << strlen(tStudent.strName) << endl;

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}