
#include <iostream>
#include <functional>

using namespace std;

/*
함수 포인터 : 함수의 메모리 주소를 저장하기 위함 포인터 변수를 선언할 수 있음
전역함수의 경우 함수명이 곧 함수의 메모리 주소
함수포인터 선언 : 반환타입(*포인터변수명)(인자타입);
*/

int Sum(int a, int b)
{
	return a + b;
}

int OutSum(int a, int b)
{
	cout << "a - b = " << a - b << endl;
	return a + b;
}

void Output()
{
	cout << "Outout Function" << endl;
}

float TestFunc(float a)
{
	cout << a << endl;
	return a;
}

class CHanzo
{
public:
	CHanzo()
	{
		m_iTest = 10;
	}

	~CHanzo()
	{

	}

public:
	int m_iTest;

public:
	void Output()
	{
		cout << "Hanzo" << endl;
		cout << "Test : " << m_iTest << endl; // this->m_iTest 와 동일
	}
};

typedef struct _tagPoint
{
	int x;
	int y;
	_tagPoint() :
		x(0),
		y(0)
	{

	}
	
	_tagPoint(int _x, int _y) : 
		x(_x),
		y(_y)
	{

	}

	_tagPoint(const _tagPoint& pt)
	{
		// 얕은 복사 (this를 역참조)
		*this = pt;
	}

	// 오퍼레이터
	_tagPoint operator +(const _tagPoint& pt)
	{
		_tagPoint result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	_tagPoint operator +(int a)
	{
		_tagPoint result;
		result.x = x + a;
		result.y = y + a;
		return result;
	}

	void operator +=(int a)
	{
		x += a;
		y += a;
	}

	void operator <<(const _tagPoint& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	void operator >>(_tagPoint& pt)
	{
		pt.x = x;
		pt.y = y;
	}

}POINT, *PPOINT;

int main()
{
	int(*pFunc)(int, int) = Sum;
	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;
	cout << pFunc(10, 20) << endl;

	void(*pFunc1)() = Output;
	pFunc1();

	CHanzo hanzo1, hanzo2;

	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	// this 포인터 : 클래스 내부에서 this 사용 시 자기 자신의 포인터가 됨
	// 멤보함수를 호출할 때 this를 호출자로 생성한다
	hanzo1.Output();
	hanzo2.Output();

	// 멤버함수 포인터 선언 시 포인터 변수 이름 앞 클래스명에 :: 를 붙여줌 (범위지정 연산자)
	void(CHanzo::*pFunc2)() = &CHanzo::Output;
	(hanzo1.*pFunc2)();

	cout << "================" << endl;

	// 선언방법 : function<반환타입(인자타입)>변수명;
	// bind 
	function<void()> func;
	function<void()> func1;

	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo1);
	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;

	// 함수에 인자가 있을 경우, placeholders를 이용해서 인자의 순서를 정의 가능
	func3 = bind(OutSum, placeholders::_1, placeholders::_2);
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14f);

	cout << "=====================================" << endl;

	POINT pt1(10, 20), pt2(30, 40), pt3;

	pt3 = pt1 + pt2;
	pt3 << pt1;
	pt2 >> pt3;
	pt3 = pt3 + 100;
	pt3 += 1000;
	cout << "pt3 : " << "x : " << pt3.x << "\ty : " << pt3.y << endl;
	cout << "pt1 : " << "x : " << pt1.x << "\ty : " << pt1.y << endl;

	system("pause");

	return 0;
}
