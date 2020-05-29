#include <iostream>
#include <conio.h>

#pragma warning(disable:4996) // POSIX name deprecated

void run();
void initMap();
void changeDirection(char key);
void update();
void clearScreen();
void printMap();
void generateFood();

bool running;

int direction;
const int mapwidth = 20;
const int mapheight = 20;
const int size = mapwidth * mapheight;
int map[size];
int s;
int headxpos;
int headypos;
int main()
{
	run();
	return 0;
}
void clearScreen() {
	// Clear the screen
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
	// Generate random x and y values within the map
	xe = mapwidth - 3;
	ye = mapheight - 2;

	// If location is not free try again

// Place new food
	map[xe + ye * mapwidth] = -2;
}
void changeDirection(char key) {
	switch (key) {
	case 'w':
		direction = 0;
		break;
	}
}
void initMap()
{
	// Places the initual head location in middle of map
	headxpos = mapwidth - 2;
	headypos = mapheight / 2;
	map[headxpos + headypos * mapwidth] = 1;

	// Places top and bottom walls
	for (int x = 0; x < mapwidth; ++x) {
		map[x] = -1;
		map[x + (mapheight - 1) * mapwidth] = -1;
	}

	// Places left and right walls
	for (int y = 0; y < mapheight; y++) {
		map[0 + y * mapwidth] = -1;
		map[(mapwidth - 1) + y * mapwidth] = -1;
	}

	// Generates first food
	generateFood();
}
char getMapValue(int value)
{
	// Returns a part of snake body
	if (value > 0) return 'o';

	switch (value) {
		// Return wall
	case -1: return 'X';
		// Return food
	case -2: return 'O';
	}

	return ' ';
}
void printMap()
{
	for (int x = 0; x < mapwidth; ++x) {
		for (int y = 0; y < mapheight; ++y) {
			// Prints the value at current x,y location
			std::cout << getMapValue(map[x + y * mapwidth]);
		}
		// Ends the line for next x value
		std::cout << std::endl;
	}
	std::cout << "Vas schet:" << s;
}

char getMapValue(int value)
{
	// Returns a part of snake body
	if (value > 0) return 'o';

	switch (value) {
		// Return wall
	case -1: return 'X';
		// Return food
	case -2: return 'O';
	}

	return ' ';
}