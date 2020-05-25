using namespace std;
#include <iostream>
#include <conio.h>
#include <ctime>

bool GameOver;
int width = 40;
int height = 20;
int x, y, FruitX, FruitY;
int score = 1;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
	int a;
	cin >> a;
	if (a == 3) {
		width = 30;
		height = 15;
	}
	if (a == 2) {
		width = 40;
		height = 20;
	}
	if (a == 1) {
		width = 50;
		height = 25;
	}
	GameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	FruitX = rand() % width;
	FruitY = rand() % height;
	score = 0;

}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << 'O';
			else if (i == FruitY && j == FruitX)
				cout << 'F';
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "РАЗМЕР ЗМЕЙКИ-" << score << "\nНажмите - z - чтобы выйти из игры\n";
}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT)
				dir = LEFT;
			break;
		case 's':
			if (dir != UP)
				dir = DOWN;
			break;
		case 'd':
			if (dir != LEFT)
				dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN)
				dir = UP;
			break;
		case 'z':
			GameOver = true;
			break;
		case 'x':
			dir = STOP;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x > width || x < 0 || y > height || y < 0) {
		GameOver = true;
		cout << endl << "ВЫ ПРОИГРАЛИ!!!" << endl;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}
	if (x == FruitX && y == FruitY) {
		score += 1;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++;
	}
}


int main()
{
	system ("color 70");
	setlocale(LC_ALL, "rus");
	cout << "Выберите уровень сложности\n1-ЛЕГКИЙ\n2-СРЕДНИЙ\n3-СЛОЖНЫЙ\n";
	Setup();
	while (!GameOver) {
		srand(time(0));
		Draw();
		Input();
		Logic();
	}
}
