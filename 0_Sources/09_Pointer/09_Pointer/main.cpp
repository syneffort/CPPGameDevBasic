
#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	// 문자 포인터
	char *pText = "테스트 문자열";

	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "문자열";
	cout << pText << " : " << (int*)pText << endl;

	pText = "문자열2";
	cout << pText << " : " << (int*)pText << endl;

	pText = "문자열2";
	cout << pText << " : " << (int*)pText << endl;

	char *pText2 = "문자열2";
	cout << pText2 << " : " << (int*)pText2 << endl;

	char str[8] = "문자열2";
	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	// 구조체 포인터
	// 연산자 우선순위로 인해 * 보다 . 이 우선임
	_tagStudent tStudent = {};
	tStudent.iKor = 100;

	_tagStudent *pStudent = &tStudent;
	(*pStudent).iKor = 50;
	// 메모리 주소 -> 를 이용해 멤버에 접근 가능
	pStudent -> iKor = 80; 
	cout << tStudent.iKor << endl;

	return 0;
}