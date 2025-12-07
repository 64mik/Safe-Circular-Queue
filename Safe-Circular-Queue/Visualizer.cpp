#include "Visualizer.h"
#include "CircularQueue.h"
#include <iostream>
#include <Windows.h>
Visualizer::Visualizer(int size, int x, int y) {
	queueSize = size;
	style.queueX = x;
	style.queueY = y;
	pointerIndex[FRONT] = -1;
	pointerIndex[REAR] = -1;
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
	if (front == -1) {
		setColor(style.emptyColor, Color::Black);
		for (int i = 0; i < queueSize; i++)
			std::cout << style.emptyChar;
	}
	else if (((rear + 1) % queueSize) == front) {
		setColor(style.filledColor, Color::Black);
		for (int i = 0; i < queueSize; i++)
			std::cout << style.filledChar;
	}
	else {
		for (int index = 0; index < queueSize; index++) {
			gotoXY(style.queueX + index + 1, style.queueY);

			if (front <= rear) {
				if (index >= front && index <= rear){
					setColor(style.filledColor);
					std::cout << style.filledChar;
				}
				else {
					setColor(style.emptyColor);
					std::cout << style.emptyChar;
				}
			}
			else {
				// 랩어라운드된 경우
				if (index >= front || index <= rear){
					setColor(style.filledColor);
					std::cout << style.filledChar;
				}
				else{
					setColor(style.emptyColor);
					std::cout << style.emptyChar;
				}
			}
		}
	}	
	setColor(style.defaultColor, Color::Black);
	std::cout << ']';
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
void Visualizer::print(std::string message, char color) {
	gotoXY(style.outputX, style.outputY);
	setColor(style.defaultColor);
	std::cout << message;
}
void Visualizer::printErr(std::string errMsg) {
	gotoXY(style.errX,style.errY);
	setColor(style.errorColor);
	std::cerr << errMsg;
	setColor(style.defaultColor);
}