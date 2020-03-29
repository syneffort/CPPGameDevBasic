
#include <iostream>

using namespace std;

int main()
{
	/*
	동적할당 : 메모리 생성을 원하는 시점에 수행 (new 키워드)
	힙 영역에 공간이 할당됨. 힙 특성 상 메모리 해제 전 계속 남아있음
	잘못 관리될 경우 메모리 리크 발생
	메모리 해제는 delete 키워드로 수행
	동적 할당은 힙에 메모리 공간을 할당하고 메모리 주소를 반환함
	*/

	// new 뒤 int 타입 크기만큼 힙에 공간 할당 (4바이트)
	// pNumber는 스택에 위 힙 메모리 주소가 반환됨
	int* pNumber = new int;

	*pNumber = 100;

	delete pNumber;

	/*
	동적배열 할당 : new 타입[개수] 형태로 사용
	*/

	// 아래의 경우 힙에 400바이트 할당 후 메모리 시작 주소를 pArray 스택에 반환
	// 동적 배열의 해제는 [] 표현하여 배열임을 명시해야함
	int* pArray = new int[100];

	delete[] pArray;

	return 0;
}