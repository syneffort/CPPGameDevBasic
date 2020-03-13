// #include : 헤더파일을 여기에 포함시키는 기능.
# include <iostream>

using namespace std;

// C++의 시작점은 main 함수. main은 반드시 있어야 함.
int main()
{
	// C++ 표준 기능 대부분은 std 라는 namespace 안에 존재함. 이름 중복을 방지하기 위함.
	std::cout << "Test output" << std::endl;

	cout << "using namespace 사용" << endl;

	return 0;
}