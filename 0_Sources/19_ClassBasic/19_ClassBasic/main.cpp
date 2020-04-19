
#include <iostream>

using namespace std;

/*
* 클래스의 4가지 속성
- 캡슐화 : 클래스 안에 속하는 여러 변수 또는 함수를 하나의 클래스로 묶어주는 기능
- 은닉화 : 클래스 안에 속하는 변수 또는 함수를 내가 원하는 부분만 외부에 공개하거나 하지 않을 수 있음
(public, protected, private)
- 상속성 : 클래스는 클래스 간에 부모-자식 관계를 형성할 수 있음
- 다형성 : 부모-자식 관계로 상속관계가 형성되어 있는 클래스간 형 변환이 가능함

* 생성자와 소멸자
- 생성자 : 어떤 클래스를 이용해서 객체를 생성할 경우 자동으로 호출되는 함수
- 소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될 때 자동으로 호출되는 함수
*/

class CTracer
{
public:
	CTracer()
	{
		cout << "Tracer 생성자" << endl;
		strcpy_s(m_strName, "트레이서");
	}

	CTracer(char* pName)
	{
		cout << "Tracer Name 생성자" << endl;
		strcpy_s(m_strName, pName);
	}

	CTracer(char* pName, int iFlash, int iBack) :
		m_iFlash(iFlash),
		m_iBack(iBack)
	{
		cout << "Tracer Name, Flash, Back 생성자" << endl;
		strcpy_s(m_strName, pName);
	}

	~CTracer()
	{
		cout << "Tracer 소멸자" << endl;
	}

	char m_strName[32];

public:
	int m_iAttack;
	int m_iHP;

private:
	int m_iFlash;
	int m_iBack;

public:
	void Output()
	{
		cout << "Tracer output" << endl;
		cout << "Name : " << m_strName << endl;
		cout << "iFlash : " << m_iFlash << endl;
		cout << "iBack : " << m_iBack << endl;
	}

};

int main()
{
	//CTracer tr1;
	//CTracer tr1("새이름");
	CTracer tr1("새이름", 3, 1);
	tr1.Output();

	system("pause");
	return 0;
}