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