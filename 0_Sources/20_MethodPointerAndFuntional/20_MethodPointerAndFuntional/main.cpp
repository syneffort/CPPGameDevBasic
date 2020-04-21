
#include <iostream>
#include <functional>

using namespace std;

/*
�Լ� ������ : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� ����
�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ�
�Լ������� ���� : ��ȯŸ��(*�����ͺ�����)(����Ÿ��);
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
		cout << "Test : " << m_iTest << endl; // this->m_iTest �� ����
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
		// ���� ���� (this�� ������)
		*this = pt;
	}

	// ���۷�����
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

	// this ������ : Ŭ���� ���ο��� this ��� �� �ڱ� �ڽ��� �����Ͱ� ��
	// �⺸�Լ��� ȣ���� �� this�� ȣ���ڷ� �����Ѵ�
	hanzo1.Output();
	hanzo2.Output();

	// ����Լ� ������ ���� �� ������ ���� �̸� �� Ŭ������ :: �� �ٿ��� (�������� ������)
	void(CHanzo::*pFunc2)() = &CHanzo::Output;
	(hanzo1.*pFunc2)();

	cout << "================" << endl;

	// ������ : function<��ȯŸ��(����Ÿ��)>������;
	// bind 
	function<void()> func;
	function<void()> func1;

	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo1);
	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;

	// �Լ��� ���ڰ� ���� ���, placeholders�� �̿��ؼ� ������ ������ ���� ����
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
