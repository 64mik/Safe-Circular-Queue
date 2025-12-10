#ifndef VISUALIZER_H
#define VISUALIZER_H
#include "CircularQueue.h"
#include <vector>
class Visualizer {
	private:
		enum visualizerEnum {
			FRONT,
			REAR
		};
		int pointerIndex[2];
		int queueSize;

	public:
		enum Color {
			Black = 0,
			Blue = 1,
			Green = 2,
			Cyan = 3,
			Red = 4,
			Magenta = 5,
			Yellow = 6,
			White = 7
		}; 
		struct style {
			char filledChar = 'o';
			char emptyChar = 'x';

			int queueX = 0;
			int queueY = 0;
			int outputX = 0;
			int outputY = 0;
			int errX = 0;
			int errY = 2;

			int filledColor = Color::Green;
			int emptyColor = Color::Yellow;
			int errorColor = Color::Red;
			int defaultColor = Color::White;

		};

		style style;

		static Visualizer& getInstance() {
			static Visualizer instance;
			return instance;
		}
		Visualizer(int size=5, int x=0, int y=0);
		~Visualizer();
		void update(int front, int rear);
		void render();
		void setColor(char textColor, char bgColor = Color::Black);
		void gotoXY(int x, int y);
		void print(std::string message, int x = -1, int y = -1, char color = Color::White);
		void printErr(std::string errMsg);
		
};

#endif // !VISUALIZER_H