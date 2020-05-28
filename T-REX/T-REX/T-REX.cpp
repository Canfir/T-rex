#include <iostream>
#include <conio.h>

#pragma warning(disable:4996) // POSIX name deprecated

void run();
void initMap();
void changeDirection(char key);
void update();
void clearScreen();
void printMap();

bool running;

int direction;
const int mapwidth = 20;
const int mapheight = 20;
const int size = mapwidth * mapheight;
int map[size];
int main()
{
	run();
	return 0;
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

	std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << food;

	std::cin.ignore();
}

void changeDirection(char key) {
	switch (key) {
	case 'w':
		direction = 0;
		break;
	}
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