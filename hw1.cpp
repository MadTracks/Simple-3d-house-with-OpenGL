#include<stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int mouse_down = 0;

double xrot = 15.0;
double yrot = 90.0;

double xdiff = 100.0;
double ydiff = 100.0;

double tra_x = 0.0;
double tra_y = 0.0;
double tra_z = 0.0;

double zoom = 75.0;

void draw(){
	glTranslatef(tra_x, tra_y, tra_z);
	//FLOOR
	glBegin(GL_QUADS);
	glColor4f(0.0, 0.5, 0.0, 1.0);
	glVertex3f(-4.5, -0.001, -4.5);
	glVertex3f(-4.5, -0.001, 5.5);
	glVertex3f(5.5, -0.001, 5.5);
	glVertex3f(5.5, -0.001, -4.5);
	glEnd();

	//HOUSE
	glBegin(GL_QUADS);		
	glColor4f(0.898, 0.867, 0.773, 1.0);
	//FRONT
	//glColor4f(0.898, 0.867, 0.773, 1.0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 1, 1);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	//BACK
	//glColor4f(0.898, 0.0, 0.773, 1.0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 0, 1);
	//LEFT
	//glColor4f(0.0, 0.867, 0.773, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);

	//RIGHT
	//glColor4f(0.898, 0.867, 0.0, 1.0);
	glVertex3f(0, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(0, 1, 1);

	//TOP
	glVertex3f(0, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	//BOTTOM
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1);
	
	// ROOF-FRONT
	glColor4f(1.0, 0.0, 0.0, 1.0);	
	glVertex3f(0, 1, 0);
	glVertex3f(0.25, 1.25, 0.5);
	glVertex3f(0.75, 1.25, 0.5);
	glVertex3f(1, 1, 0);

	// ROOF-BACK
	glVertex3f(0, 1, 1);
	glVertex3f(0.25, 1.25, 0.5);
	glVertex3f(0.75, 1.25, 0.5);
	glVertex3f(1, 1, 1);
	
	//FRONT-DOOR
	glColor4f(0.5, 0.35, 0.05, 1.0);
	glVertex3f(-0.0001, 0, 0.35);
	glVertex3f(-0.0001, 0, 0.65);
	glVertex3f(-0.0001, 0.5, 0.65);
	glVertex3f(-0.0001, 0.5, 0.35);

	//FRONT-WINDOW
	glColor4f(0.196078,0.6, 0.8, 1.0);
	glVertex3f(-0.0001, 0.60, 0.05);
	glVertex3f(-0.0001, 0.60, 0.95);
	glVertex3f(-0.0001, 0.90, 0.95);
	glVertex3f(-0.0001, 0.90, 0.05);

	glEnd();

	glBegin(GL_TRIANGLES);
	//ROOF-TRIANGLE-LEFT
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glVertex3f(0.25, 1.25, 0.5);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 1, 1);
	//ROOF-TRIANGLE-RIGHT
	glVertex3f(0.75, 1.25, 0.5);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1);

	glEnd();

	//LINE-BOTTOM
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1);
	glEnd();

	//LINE-TOP
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	//LINE-LEFT
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 1, 1);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	//LINE-RIGHT
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 0, 1);
	glEnd();

	//LINE-ROOF-LEFT
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0.25, 1.25, 0.5);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 1, 1);
	glEnd();

	//LINE-ROOF-RIGHT
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0.75, 1.25, 0.5);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1);
	glEnd();

	//LINE-ROOF-TOP
	glBegin(GL_LINES);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(0.25, 1.25, 0.5);
	glVertex3f(0.75, 1.25, 0.5);
	glEnd();

	//LINE-DOOR
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(-0.001, 0, 0.35);
	glVertex3f(-0.001, 0, 0.65);
	glVertex3f(-0.001, 0.5, 0.65);
	glVertex3f(-0.001, 0.5, 0.35);
	glEnd();

	//LINE-WINDOW
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(-0.001, 0.60, 0.05);
	glVertex3f(-0.001, 0.60, 0.95);
	glVertex3f(-0.001, 0.90, 0.95);
	glVertex3f(-0.001, 0.90, 0.05);
	glEnd();

	//LINE-WINDOW-MID
	glBegin(GL_LINES);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glVertex3f(-0.001, 0.75, 0.05);
	glVertex3f(-0.001, 0.75, 0.95);
	glVertex3f(-0.001, 0.60, 0.20);
	glVertex3f(-0.001, 0.90, 0.20);
	glVertex3f(-0.001, 0.60, 0.35);
	glVertex3f(-0.001, 0.90, 0.35);
	glVertex3f(-0.001, 0.60, 0.50);
	glVertex3f(-0.001, 0.90, 0.50);
	glVertex3f(-0.001, 0.60, 0.65);
	glVertex3f(-0.001, 0.90, 0.65);
	glVertex3f(-0.001, 0.60, 0.80);
	glVertex3f(-0.001, 0.90, 0.80);
	glEnd();
}

void display(void){

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(xrot, 1.0, 0.0, 0.0);
	glRotatef(yrot, 0.0, 1.0, 0.0);

	draw();

	glFlush();
	glutSwapBuffers();
}

void scale(int width, int height){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, width, height);
	gluPerspective(zoom, width/height, 1.0, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard_controller(unsigned char key, int x, int y){
	switch(key)
	{
		case 27: 
			exit(1); 
			break;
		case 'w':
		case 'W':
			tra_x -= 0.1;
			break;
		case 's':
		case 'S':
			tra_x += 0.1;
			break;
		case 'a':
		case 'A':
			tra_z += 0.1;
			break;
		case 'd':
		case 'D':
			tra_z -= 0.1;
			break;
		case 'g':
		case 'G':
			yrot += 1;
			break;
		case 'j':
		case 'J':
			yrot -= 1;
			break;
		case 'y':
		case 'Y':
			xrot += 1;
			break;
		case 'h':
		case 'H':
			xrot -= 1;
			break;
		case 'q':
		case 'Q':
			zoom--;
			scale(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));			
			break;
		case 'e':
		case 'E':
			zoom++;
			scale(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));			
			break;

	}	
	glutPostRedisplay();
}

void mouse_controller(int button, int state, int x, int y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON )
	{
		mouse_down = 1;
		xdiff = x - yrot;
		ydiff = xrot - y;
	}
	else{
		mouse_down = 0;
	}
}

void mouse_motion_controller(int x, int y){
	if (mouse_down)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("House of CSE461");
	glClearColor(0.5,0.5,0.5,0.5);
	glutKeyboardFunc(keyboard_controller);
	glutMouseFunc(mouse_controller);
	glutMotionFunc(mouse_motion_controller);
	glutDisplayFunc(display);
	glutReshapeFunc(scale);
	glutMainLoop();

	return 0;
}