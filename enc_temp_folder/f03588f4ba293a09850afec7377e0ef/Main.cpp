#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h>
#include <vector>
#include <cmath>

#define PI 3.14159265358979323846
#define WHITE 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0

using namespace std;
const float width = 640.0;
const float height = 480.0;
const float deltat = .10f;
const int fps = 40;
bool showPolygon = true;
struct RectPoint;
void borderRadius(RectPoint rect, float radius);
struct RectPoint {
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	RectPoint(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) {
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;
		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
		this->y4 = y4;
	}
	RectPoint() {}
};

class LinePattern {
public:
	struct RectPoint rect;
	LinePattern(float x, float y, bool isHorizontal=false) {
		rect.x1 = x;
		rect.x2 = x + 100;
		rect.x3 = x + 100;
		rect.x4 = x;

		rect.y1 = y;
		rect.y2 = y;
		rect.y3 = y - 15;
		rect.y4 = y - 15;

		if (isHorizontal) {
			rect.x1 = x;
			rect.x2 = x + 15;
			rect.x3 = x + 15;
			rect.x4 = x;

			rect.y1 = y; 
			rect.y2 = y;
			rect.y3 = y - 100;
			rect.y4 = y - 100;
		}
	}

	void draw() {
		borderRadius(this->rect, 10.0);
	}
};

void circle(float x, float y, float size) {
	RectPoint rect = RectPoint(x+0.0, x+size, x+size, x+0.0, y+0.0, y+0.0, y+-size, y+-size);
	borderRadius(rect, size);
}

void fourDots(float x, float y) {
	circle(x, y, 10.0);
	circle(x+30, y, 10.0);
	circle(x+30, y-30, 10.0);
	circle(x, y-30, 10.0);
}

void redCore(float x, float y) {
	glLineWidth(10.0);
	for (int i = 1; i <= 3; i++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(x, y+25 * i);
		glVertex2f(x-25 * i, y);
		glVertex2f(x, y-25 * i);
		glVertex2f(x+25 * i, y);
		glEnd();
	}
	glBegin(GL_QUADS);
		glVertex2f(x, y + 25 * 3);
		glVertex2f(x+25, y + (25 * 3)+25);
		glVertex2f(x, y + (25 * 3) + 50);
		glVertex2f(x - 25, y + (25 * 3) + 25);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(x, y - 25 * 3);
		glVertex2f(x - 25, y - (25 * 3) - 25);
		glVertex2f(x, y + (-25 * 3) - 50);
		glVertex2f(x + 25, y - (25 * 3) - 25);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2f(x + 25 * 3, y);
	glVertex2f(x + (25 * 3) + 25, y +25);
	glVertex2f(x + (25 * 3) + 50, y );
	glVertex2f(x + (25 * 3) + 25, y -25);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(x - 25 * 3, y);
	glVertex2f(x - (25 * 3) - 25, y + 25);
	glVertex2f(x - (25 * 3) - 50, y);
	glVertex2f(x - (25 * 3) - 25, y - 25);
	glEnd();

}


void display() {
	glPointSize(5.0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	glColor3f(RED);
	redCore(150.0, 0.0);
	redCore(-305.0, 500);
	redCore(-305.0, -500);
	redCore(615.0, 500);
	redCore(615.0, -500);

	glColor3f(WHITE);

	fourDots(-440.0, 125.0);
	fourDots(-210.0, 125.0);
	fourDots(-440.0, -105.0);
	fourDots(-210.0, -105.0);

	fourDots(700.0, 125.0);
	fourDots(470.0, 125.0);
	fourDots(700.0, -105.0);
	fourDots(470.0, -105.0);


	fourDots(-440.0, 425.0);
	fourDots(-210.0, 425.0);
	fourDots(-440.0, -390.0);
	fourDots(-210.0, -390.0);

	fourDots(700.0, -390.0);
	fourDots(470.0, -390.0);

	fourDots(700.0, 425.0);
	fourDots(470.0, 425.0);

	LinePattern(-580.0, 50.0).draw();
	LinePattern(-500.0, 0.0).draw();
	LinePattern(-580.0, -50.0).draw();

	LinePattern(-120.0, 50.0).draw();
	LinePattern(-200.0, 0.0).draw();
	LinePattern(-120.0, -50.0).draw();



	LinePattern(320.0, 50.0).draw();
	LinePattern(400.0, 0.0).draw();
	LinePattern(320.0, -50.0).draw();

	LinePattern(-260.0, 300.0, true).draw();
	LinePattern(-310.0, 220.0, true).draw();
	LinePattern(-360.0, 300.0, true).draw();

	LinePattern(-260.0, -200.0, true).draw();
	LinePattern(-310.0, -120.0, true).draw();
	LinePattern(-360.0, -200.0, true).draw();

	LinePattern(560.0, -200.0, true).draw();
	LinePattern(610.0, -120.0, true).draw();
	LinePattern(660.0, -200.0, true).draw();

	LinePattern(560.0, 300.0, true).draw();
	LinePattern(610.0, 220.0, true).draw();
	LinePattern(660.0, 300.0, true).draw();

	LinePattern(200.0, -200.0, true).draw();
	LinePattern(150.0, -280.0, true).draw();
	LinePattern(100.0, -200.0, true).draw();

	LinePattern(200.0, 300.0, true).draw();
	LinePattern(150.0, 380.0, true).draw();
	LinePattern(100.0, 300.0, true).draw();

	

	glutSwapBuffers();
}



void myinit() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640, -480, 480);

}

void onLeftMouseClicked(int x, int y) {
	cout << "mouse diklik pada (" << x << "," << y << ")" << endl;
}

void mouseHandler(int button, int state, int x, int y) {
	if (!button && !state) {
		onLeftMouseClicked(x, y);
	}
}

void keyboardHandler(unsigned char key, int x, int y) {
	cout << "Tombol " << key << " Ditekan" << endl;
	if (key == ' ') {
		showPolygon = !showPolygon;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Animasi Epic");
	glutDisplayFunc(display);

	glutMouseFunc(mouseHandler);
	glutKeyboardFunc(keyboardHandler);
	myinit();
	glutMainLoop();
	return 0;
}


void borderRadius(RectPoint rect, float radius) {
	glPointSize(radius);
	glDisable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.5);

	glBegin(GL_POINTS);
	glVertex2f(rect.x1, rect.y1);
	glVertex2f(rect.x2, rect.y2);
	glVertex2f(rect.x3, rect.y3);
	glVertex2f(rect.x4, rect.y4);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glLineWidth(radius);
	glBegin(GL_LINES);
	glVertex2f(rect.x1, rect.y1);
	glVertex2f(rect.x2, rect.y2);
	glVertex2f(rect.x3, rect.y3);
	glVertex2f(rect.x4, rect.y4);

	glVertex2f(rect.x1, rect.y1);
	glVertex2f(rect.x2, rect.y2);
	glVertex2f(rect.x3, rect.y3);
	glVertex2f(rect.x4, rect.y4);

	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(rect.x1 - radius, rect.y1);
	glVertex2f(rect.x2 + radius, rect.y2);
	glVertex2f(rect.x3 + radius, rect.y3);
	glVertex2f(rect.x4 - radius, rect.y4);
	glEnd();

	glDisable(GL_ALPHA_TEST);
	glDisable(GL_POINT_SMOOTH);
}



