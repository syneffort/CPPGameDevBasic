
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/*
0: º®
1: ±æ
2 : ½ÃÀÛÁ¡
3 : µµÂøÁ¡
4 : ÆøÅº
5 : ÆÄ¿ö ¾ÆÀÌÅÛ
6 : º®¹Ð±â ¾ÆÀÌÅÛ
7 : Åõ¸í ¾ÆÀÌÅÛ
8 : ¿úÈ¦

*/

struct _tagPoint
{
	int x;
	int y;
};

// Å¸ÀÔ ÀçÁ¤ÀÇ
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallPush;
	bool bTransparency;
	int iBombPower;
}PLAYER, *PPLAYER;

void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayer->tPos = *pStartPos;

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

void Output(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Maze[i][j] == '4')
				cout << "¢Í";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "¡Ù";
			else if (Maze[i][j] == '0')
				cout << "¡á";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "¡Ú";
			else if (Maze[i][j] == '3')
				cout << "¡Ý";
			else if (Maze[i][j] == '5')
				cout << "¡×";
			else if (Maze[i][j] == '6')
				cout << "¡ê";
			else if (Maze[i][j] == '7')
				cout << "¢¹";
		}
		cout << endl;
	}

	cout << "ÆøÅº ÆÄ¿ö : " << pPlayer->iBombPower << endl;
	cout << "º® Åë°ú : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "º® ¹Ð±â : ";
	if (pPlayer->bWallPush)
		cout << "ON" << endl;
	else
		cout << "OFF" << endl;
}

bool AddItem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if (pPlayer->iBombPower < 5)
			pPlayer->iBombPower++;

		return true;
	}
	else if (cItemType == '6')
	{
		pPlayer->bWallPush = true;
		return true;
	}
	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y - 1 >= 0)
	{
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}
		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;
		
		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 <= 19)
	{
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 <= 19)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;
	}
}

void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->tPos.x == pBombArr[i].x
			&& pPlayer->tPos.y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = pPlayer->tPos;
	(*pBombCount)++;

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
		{
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= pPlayer->iBombPower; j++)
		{
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBombArr[i].y + j <= 19)
			{
				if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}
					

				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBombArr[i].x - j >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBombArr[i].x + j <= 19)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0')
				{
					int iPercent = rand() % 100;

					if (iPercent < 70)
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
					else if (iPercent < 80)
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}

	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));

	// 20 x 20 ¹Ì·Î »ý¼º
	char strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;
	POINT tBombPos[5] = {};

	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		Output(strMaze, &tPlayer);
		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.x)
		{
			cout << "µµÂøÇß½À´Ï´Ù." << endl;
			break;
		}

		cout << "t : ÆøÅº ¼³Ä¡ u : ÆøÅº ÅÍ¶ß¸®±â i : º® ¹Ð±â" << endl;
		cout << "w : À§ s : ¾Æ·¡ a : ÁÂ d : ¿ì q : Á¾·á >> ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		else if (cInput == 'u' || cInput == 'U')
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);
		else
			MovePlayer(strMaze, &tPlayer, cInput);
	}

	return 0;
}