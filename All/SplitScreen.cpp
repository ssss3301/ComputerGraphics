// #include "GL\freeglut.h"
// #include "GL\glut.h"
// 
// typedef struct wcPt2D
// {
// 	GLfloat x;
// 	GLfloat y;
// };
// 
// void init()
// {
// 	glClearColor(0.0, 0.0, 0.0, 0.0);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluOrtho2D(-100, 100, -100, 100);
// 	glMatrixMode(GL_MODELVIEW);
// }
// 
// void triangle(wcPt2D* vertices)
// {
// 	glBegin(GL_TRIANGLES);
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		glVertex2f(vertices[i].x, vertices[i].y);
// 	}
// 	glEnd();
// }
// 
// void display()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glColor3f(1.0, 0.0, 0.0);
// 
// 	wcPt2D vertices[3] = { {-50,  -25}, {50.0, -25.0}, {0.0, 50.0} };
// 	glViewport(0, 0, 300, 300);
// 	triangle(vertices);
// 
// 	glColor3f(1.0, 1.0, 0.0);
// 	glViewport(300, 0, 300, 300);
// 	glPushMatrix();
// 	glRotatef(90.0, 0.0, 0.0, 1.0);
// 	triangle(vertices);
// 	glPopMatrix();
// 
// 	glFlush();
// }
// 
// int main(int argc, char** argv)
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
// 	glutInitWindowSize(600, 600);
// 	glutInitWindowPosition(50, 50);
// 	glutCreateWindow("Split Screen Window");
// 	init();
// 	glutDisplayFunc(display);
// 	glutMainLoop();
// 	return 0;
// }