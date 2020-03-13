// #include : 헤더파일을 여기에 포함시키는 기능.
# include <iostream>

using namespace std;

// C++의 시작점은 main 함수. main은 반드시 있어야 함.
int main()
{
	// C++ 표준 기능 대부분은 std 라는 namespace 안에 존재함. 이름 중복을 방지하기 위함.
	std::cout << "Test output" << std::endl;

	cout << "using namespace 사용" << endl;

	/*
	용량의 최소단위 bit
	1byte = 8bit
	1kbyte = 1024byte
	1mbyte = 1024kbyte
	1gbyte = 1024mbyte
	1tbyte = 1024gbyte

	문자를 표현하는 방법 : ASCII 코드표

	종류	|	용량	|	데이터	|	표현범위		|	unsigned		|
	char	|	1byte	|	문자	|	-128 ~ 127		|	0 ~ 255			|
	bool	|	1byte	|	참/거짓	|	true / false	|	true / false	|
	short	|	2byte	|	정수	|	-32768 ~ 32767	|	0 ~ 65535		|
	int		|	4byte	|	정수	|	약 -22억 ~ 21억	|	0 ~ 43억
	float	|	4byte	|	실수	|	
	double	|	8byte	|	실수	|
	*/

	int Number = 10;
	Number = 20;
	cout << Number << endl;

	bool bTest = true;
	bTest = false;
	cout << bTest << endl;

	// 영문이나 숫자는 1byte
	// 한글 등 문자는 2byte므로 char 저장 어려움
	char cTest = 't';
	cout << cTest << endl;

	float fNumber = 3.14f;
	cout << fNumber << endl;

	double dNumber = 123.456;
	cout << dNumber << endl;

	// 기본 연산자
	cout << "숫자를 입력하세요 : ";
	cin >> Number;
	cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;

	/*
	진수 : 2진수, 8진수, 10진수, 16진수
	2진수 : 0 ~ 1
	8진수 : 0 ~ 7
	10진수 : 0 ~ 9
	16진수 : 0 ~ 9 : a ~ f (10 ~ 15)
	진수들은 서로 다른 진수로 변환 가능함

	87을 2진수, 16진수로 변환
	87 / 2 = 43 --1
	43 / 2 = 21 -- 1
	21 / 2 = 10 -- 1
	10 / 2 = 5 -- 0
	5 / 2 == 2 -- 1
	2 / 2 == 1 -- 0
	가장 마지막 몫부터 역순으로 나머지값 읽음 => 2진수 1010111
	
	16진수로 변환은 2진수로 변환 후 16진수로 변환하는 것이 쉬움
	2진수를 오른쪽으로부터 4자리씩 끊어서 계산
	2진수가 1인 부분만 더함
	16진수 1자리는 2진수 4자리임
	1010111 => 101 0111
	0101 0111
	8421 8421
	5    7
	=> 16진수 57

	53 / 2 = 26 -- 1
	26 / 2 = 13 -- 0
	13 / 2 = 6 -- 1
	6 / 2 = 3 -- 0
	3 / 2 = 1 -- 1
	=> 110101

	비트단위 연산자 : 2진수 단위의 연산을 수행.
	종류 : AND(&), OR(|), NOT(~), XOR(^)
	A  B  XOR
	0  0  0
	0  1  1
	1  0  1
	1  1  0

	87 & 53 = 
	87 : 1010111
	53 : 110101
	각 자리별로 논리연산 수행
	 1010111
	&0110101
	 0010101
	10진수 => 21
	*/

	cout << "87 & 53 = " << (87 & 53) << endl;

	return 0;
}