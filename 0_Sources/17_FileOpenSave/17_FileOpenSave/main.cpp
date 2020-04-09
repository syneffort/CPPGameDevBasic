
#include <iostream>

using namespace std;

int main()
{
	FILE* pFile = NULL;

	// 모드 : 일기, 쓰기, 추가
	// 형태 : 텍스트파일, 바이너리파일
	// r, w, a  t, b
	fopen_s(&pFile, "hot.txt", "wt");
	if (pFile != NULL)
	{
		char* pText = "abcd";
		fwrite(pText, 1, 4, pFile);

		fclose(pFile);
	}

	fopen_s(&pFile, "hot.txt", "rt");
	if (pFile != NULL)
	{
		char strText[5] = {};
		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);
	}

	return 0;
}