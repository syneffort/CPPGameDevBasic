
#include <iostream>
#include <conio.h>

using namespace std;

/*
0: º®
1: ±æ
2 : ½ÃÀÛÁ¡
3 : µµÂøÁ¡
4 : ÆøÅº
5 : Æø¹ß È¿°ú
*/

struct _tagPoint
{
	int x;
	int y;
};

// Å¸ÀÔ ÀçÁ¤ÀÇ
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

	strcpy_s(Maze[0],	"21100000000000000000");
	strcpy_s(Maze[1],	"01111110010010101000");
	strcpy_s(Maze[2],	"01000101010101000100");
	strcpy_s(Maze[3],	"01100101000011011100");
	strcpy_s(Maze[4],	"11111111100101000100");
	strcpy_s(Maze[5],	"11100001000101000100");
	strcpy_s(Maze[6],	"01100110111111010110");
	strcpy_s(Maze[7],	"01100100011011000110");
	strcpy_s(Maze[8],	"11111111100101000100");
	strcpy_s(Maze[9],	"10100000010011111100");
	strcpy_s(Maze[10],	"01100000010011110100");
	strcpy_s(Maze[11],	"11111111100101000000");
	strcpy_s(Maze[12],	"01110111111111101000");
	strcpy_s(Maze[13],	"00110100010101101010");
	strcpy_s(Maze[14],	"00110100000100100010");
	strcpy_s(Maze[15],	"01110100100111110010");
	strcpy_s(Maze[16],	"00110111000101111010");
	strcpy_s(Maze[17],	"00110101111111110000");
	strcpy_s(Maze[18],	"01110011110101000000");
	strcpy_s(Maze[19],	"01111011011111111113");
}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Maze[i][j] == '4')
				cout << "¢Í";
			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "¡Ù";
			else
			{
				switch (Maze[i][j])
				{
				case '0':
					cout << "¡á";
					break;
				case '1':
					cout << " ";
					break;
				case '2':
					cout << "¡Ú";
					break;
				case '3':
					cout << "¡Ý";
					break;
				}
			}
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0'
			&& Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			pPlayerPos->y--;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 <= 19)
	{
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0'
			&& Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
		{
			pPlayerPos->y++;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0'
			&& Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			pPlayerPos->x--;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 <= 19)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'
			&& Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			pPlayerPos->x++;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->x == pBombArr[i].x
			&& pPlayer->y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = *pPlayer;
	(*pBombCount)++;

	Maze[pPlayer->y][pPlayer->x] = '4';
}

void ReturnPlayer(PPOINT pPlayer)
{
	pPlayer->x = 0;
	pPlayer->y = 0;
}

void Fire(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
			ReturnPlayer(pPlayer);

		if (pBombArr[i].y - 1 >= 0)
		{
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1)
				ReturnPlayer(pPlayer);
		}

		if (pBombArr[i].y + 1 <= 19)
		{
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1)
				ReturnPlayer(pPlayer);
		}

		if (pBombArr[i].x - 1 >= 0)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';

			if (pPlayer->x == pBombArr[i].x - 1 && pPlayer->y == pBombArr[i].y)
				ReturnPlayer(pPlayer);
		}

		if (pBombArr[i].x + 1 <= 19)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';

			if (pPlayer->x == pBombArr[i].x + 1 && pPlayer->y == pBombArr[i].y)
				ReturnPlayer(pPlayer);
		}
	}

	*pBombCount = 0;
}

int main()
{
	// 20 x 20 ¹Ì·Î »ý¼º
	char strMaze[21][21] = {};

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 5;
	int iAddBomb = 0;
	POINT tBombPos[5] = {};

	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		Output(strMaze, &tPlayerPos);
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.x)
		{
			cout << "µµÂøÇß½À´Ï´Ù." << endl;
			break;
		}

		cout << "t : ÆøÅº ¼³Ä¡ u : ÆøÅº ÅÍ¶ß¸®±â" << endl;
		cout << "w : À§ s : ¾Æ·¡ a : ÁÂ d : ¿ì q : Á¾·á >> ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iAddBomb);
		else if (cInput == 'u' || cInput == 'U')
			Fire(strMaze, &tPlayerPos, tBombPos, &iAddBomb);
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);
	}

	return 0;
}