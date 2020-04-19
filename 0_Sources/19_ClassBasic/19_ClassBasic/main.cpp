
#include <iostream>

using namespace std;

/*
* Ŭ������ 4���� �Ӽ�
- ĸ��ȭ : Ŭ���� �ȿ� ���ϴ� ���� ���� �Ǵ� �Լ��� �ϳ��� Ŭ������ �����ִ� ���
- ����ȭ : Ŭ���� �ȿ� ���ϴ� ���� �Ǵ� �Լ��� ���� ���ϴ� �κи� �ܺο� �����ϰų� ���� ���� �� ����
(public, protected, private)
- ��Ӽ� : Ŭ������ Ŭ���� ���� �θ�-�ڽ� ���踦 ������ �� ����
- ������ : �θ�-�ڽ� ����� ��Ӱ��谡 �����Ǿ� �ִ� Ŭ������ �� ��ȯ�� ������

* �����ڿ� �Ҹ���
- ������ : � Ŭ������ �̿��ؼ� ��ü�� ������ ��� �ڵ����� ȣ��Ǵ� �Լ�
- �Ҹ��� : � Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
*/

class CTracer
{
public:
	CTracer()
	{
		cout << "Tracer ������" << endl;
		strcpy_s(m_strName, "Ʈ���̼�");
	}

	CTracer(char* pName)
	{
		cout << "Tracer Name ������" << endl;
		strcpy_s(m_strName, pName);
	}

	CTracer(char* pName, int iFlash, int iBack) :
		m_iFlash(iFlash),
		m_iBack(iBack)
	{
		cout << "Tracer Name, Flash, Back ������" << endl;
		strcpy_s(m_strName, pName);
	}

	~CTracer()
	{
		cout << "Tracer �Ҹ���" << endl;
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
	//CTracer tr1("���̸�");
	CTracer tr1("���̸�", 3, 1);
	tr1.Output();

	system("pause");
	return 0;
}