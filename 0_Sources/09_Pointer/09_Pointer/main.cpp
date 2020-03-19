
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
	/*
	포인터 : 가리키다.
	일반 변수는 일반적인 값을.
	모든 변수 타입은 포인터 타입을 선언할 수 있음.
	int 변수의 주소는 int 포인터 변수에 저장해야한다.
	포인터는 메모리 주소를 담아놓는 변수이기 때문에
	x86으로 개발할 때는 4byte, x64로 개발할 때는 8byte 가 나온다.

	포인터는 자기 스스로 아무런 처리도 할 수 없다.
	반드시 다른 변수의 메모리 주소를 가지고 있어야하며,
	그 메모리 주소에 접근해서 값을 제어할 수 있다.

	형태 : 변수타입 *변수명;
	*/

	int iNumber = 100;
	// 변수 앞에 &를 붙여주면 해당 변수의 메모리 주소가 된다.
	int *pNum = &iNumber;

	// 역참조를 이용해서 값을 얻어오거나 변경
	// 역참조는 포인터 변수 앞에 *를 붙이게되면 역참조가 됨
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
	포인터와 배열의 관계 : 배열명은 포인터다.
	배열명 자체가 해당 배열의 메모리 시작점 주소를 의미함
	*/

	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray << endl;

	int *pArray = iArray;

	cout << pArray[2] << endl;

	/*
	포인터 연산 : +, - 연산을 제공한다.
	++, -- 연산도 가능한데, 1을 증가하게 되면 단순히 메모리 주소값이 1 증가하는것이 아님
	int 포인터의 경우, 1 증가 시 가르키는 해당 포인터 타입의 변수 크기만큼 증가하게 됨 (ex, int일 경우 4 만큼 증가)
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *(pArray + 100) << endl;

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

	// void 포인터
	// *void 변수를 선언하게 되면 이 변수는 모든 타입의 메모리 주소를 저장할 수 있음
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << pVoid << endl;
	//*pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 101010;
	cout << iNumber << endl;

	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;
	

	return 0;
}