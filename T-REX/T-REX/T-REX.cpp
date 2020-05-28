#include <iostream>
#include <conio.h>

#pragma warning(disable:4996) 

void run();
void initMap();
void changeDirection(char key);
void update();
void clearScreen();
void printMap();
void generateFood();
void move(int dx, int dy);
char getMapValue(int value);

bool running;

int direction;
const int mapwidth = 20;
const int mapheight = 20;
const int size = mapwidth * mapheight;
int map[size];
int s;
int headxpos;
int headypos;
int food = 1;

int main()
{
	run();
	return 0;
}
void clearScreen() {
	system("cls");
}
void run()
{
	initMap();
	running = true;
	while (running) {
		if (kbhit()) {
			changeDirection(getch());
		}
		update();

		clearScreen();

		printMap();

		_sleep(500);
	}

	std::cin.ignore();
}
int xe = 0;
int ye = 0;
void generateFood() {
	xe = 0;
	ye = 0;
	xe = mapwidth - 3;
	ye = mapheight - 2;
	map[xe + ye * mapwidth] = -2;
}
void changeDirection(char key) {
	switch (key) {
	case 'w':
		direction = 0;
		break;
	}
}
void move(int dx, int dy) {
	int newx = headxpos + dx;
	int newy = headypos + dy;
	if (map[newx + newy * mapwidth] == -2) {
		s++;
		generateFood();
	}
	headxpos = newx;
	headypos = newy;
	map[headxpos + headypos * mapwidth] = food + 1;
}
void initMap()
{
	headxpos = mapwidth - 2;
	headypos = mapheight / 2;
	map[headxpos + headypos * mapwidth] = 1;
	for (int x = 0; x < mapwidth; ++x) {
		map[x] = -1;
		map[x + (mapheight - 1) * mapwidth] = -1;
	}
	for (int y = 0; y < mapheight; y++) {
		map[0 + y * mapwidth] = -1;
		map[(mapwidth - 1) + y * mapwidth] = -1;
	}
	generateFood();
}
char getMapValue(int value)
{

	if (value > 0) return 'o';

	switch (value) {

	case -1: return 'X';

	case -2: return 'O';
	}

	return ' ';
}
void update() {
	switch (direction) {
	case 0: move(-1, 0);
		direction = 1;
		break;
	case 1: move(1, 0);
		direction = 2;
		break;
	case 2: move(0, 0);
		break;
	}
	map[xe + ye * mapwidth] = -3;
	xe = xe;
	ye = ye - 1;
	if (ye > 0) map[xe + ye * mapwidth] = -2;
	else
		generateFood();
	for (int i = 0; i < size; i++) {
		if (map[i] > 0) map[i]--;
	}
}
void printMap()
{
	for (int x = 0; x < mapwidth; ++x) {
		for (int y = 0; y < mapheight; ++y) {
			std::cout << getMapValue(map[x + y * mapwidth]);
		}
		std::cout << std::endl;
	}
	std::cout << "Vas schet:" << s;
}

char getMapValue(int value)
{
	if (value > 0) return 'o';
	switch (value) {
	case -1: return 'X';
	case -2: return 'O';
	}
	return ' ';
}