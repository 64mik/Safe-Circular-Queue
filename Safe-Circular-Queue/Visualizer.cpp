#include "Visualizer.h"
#include "CircularQueue.h"
#include <iostream>
#include <windows.h>

Visualizer::Visualizer(int size, int x, int y) {
	queueSize = size;
	style.queueX = x;
	style.queueY = y;
	pointerIndex[FRONT] = -1;
	pointerIndex[REAR] = -1;

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible =	false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
Visualizer::~Visualizer(){}
void Visualizer::update(int front, int rear) {
	pointerIndex[FRONT] = front;
	pointerIndex[REAR] = rear;
}
void Visualizer::render() {
	int front = pointerIndex[FRONT];
	int rear = pointerIndex[REAR];
	gotoXY(style.queueX, style.queueY);
	std::cout << '[';

	//is Full
	if (front == -1 && rear == -1){
		setColor(style.emptyColor, Color::Black);
		for (int i = 0; i < queueSize; i++)
			std::cout << style.emptyChar;
	}
	//is Empty
	else if (((rear + 1) % queueSize) == front) {
		setColor(style.filledColor, Color::Black);
		for (int i = 0; i < queueSize; i++) {
			if (i == front) {
				setColor(Color::Cyan);
				std::cout << ">";
				continue;
			}
			else if (i == rear) {
				setColor(Color::Red);
				std::cout << "<";
				continue;
			}
			setColor(style.filledColor);
			std::cout << style.filledChar;
			
		}
	}
	//rendering
	else {
		for (int index = 0; index < queueSize; index++) {
			gotoXY(style.queueX + index + 1, style.queueY);

			//bucket rendering
			if (queueSize < rear) {
				int f = (front + queueSize) % queueSize;
				int r = (rear + queueSize) % queueSize;

				if (index == f) {
					setColor(Color::Cyan);
					std::cout << ">";
					continue;
				}
				else if (index == r) {
					setColor(Color::Red);
					std::cout << "<";
					continue;
				}

				// > < 老 锭
				if (f <= r) {	
					if (index >= f && index <= r) {
						setColor(style.filledColor);
						std::cout << style.filledChar;
					}
					else {
						setColor(style.emptyColor);
						std::cout << style.emptyChar;
					}
				}
				// < > 老锭
				else {	
					if (index >= f || index <= r) {
						setColor(style.filledColor);
						std::cout << style.filledChar;
					}
					else {
						setColor(style.emptyColor);
						std::cout << style.emptyChar;
					}
				}
			}
			//normal rendering
			else {
				if (index == front) {
					setColor(Color::Cyan);
					std::cout << ">";
					continue;
				}
				else if (index == rear) {
					setColor(Color::Red);
					std::cout << "<";
					continue;
				}
				
				// > < 老 锭
				if (front <= rear) {
					if (index >= front && index <= rear) {
						setColor(style.filledColor);
						std::cout << style.filledChar;
					}
					else {
						setColor(style.emptyColor);
						std::cout << style.emptyChar;
					}
					continue;
				}
				// < > 老 锭
				else {
					if (index >= front || index <= rear) {
						setColor(style.filledColor);
						std::cout << style.filledChar;
					}
					else {
						setColor(style.emptyColor);
						std::cout << style.emptyChar;
					}
					continue;
				}
			}
		}
		if (queueSize < rear) {
			setColor(style.defaultColor);
			std::cout << "| *" << rear - front;
		}
	}

	setColor(style.defaultColor, Color::Black);
	std::cout << "]      ";
	gotoXY(0, 0);
}
void Visualizer::gotoXY(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Visualizer::setColor(char textColor, char bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attributes = (bgColor << 4) | textColor;
	SetConsoleTextAttribute(hConsole, attributes);
}
void Visualizer::print(std::string message, int x, int y, char color) {
	if (x == -1 || y == -1) {
		gotoXY(style.outputX, style.outputY);
	}
	else{
		gotoXY(x, y);
	}
	setColor(color);
	std::cout << message;
}
void Visualizer::printErr(std::string errMsg) {
	gotoXY(style.errX,style.errY);
	setColor(style.errorColor);
	std::cerr << errMsg;
	setColor(style.defaultColor);
}