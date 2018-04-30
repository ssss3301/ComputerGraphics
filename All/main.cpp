// #include "gl/freeglut.h"
// #include "gl/glut.h"
// 
// #include "Define.h"
// #include "Chapter3/Exercises/Ex3.1.h"
// #include "Chapter3/Exercises/Ex3.2.h"
// #include "Chapter3/Exercises/Ex3.3.h"
// #include "Chapter3/Exercises/Ex3.4.h"
// #include "Chapter5/Transform.h"
// #include "Chapter5/CompositeTransform.h"
// #include "Chapter5/GLTransform.h"
// 
// #include <iostream>
// 
// LinePoint p1 = { 30, 30};
// LinePoint p2 = { 100, 50};
// LinePoint p3 = { 200, 50};
// LinePoint p4 = { 100, 200};
// 
// CTransform trans;
// unsigned char op = 0;
// Point pt[4] = { { 0, 0 }, { 2.30, 0 }, { 2.30, 2.30 }, { 0.0, 2.30 } };
// Point pivot = { 0, 0 };
// Point fixedPoint = { 0, 0 };
// 
// CompositeTransform compositeTransform;
// CGLTransform  glTransform;
// 
// void init()
// {
// 	glClearColor(0.0, 0.0, 0.0, 1.0f);
// }
// 
// void reshape(int w, int h)
// {
// 	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluPerspective(60.0, 1.0, 1.0, 20.0);
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
// 	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
// }
// 
// void display()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glColor3f(1.0, 0.0, 0.0);
// 
// 	GLint viewPort[4] = { 0 };
// 	glGetIntegerv(GL_VIEWPORT, viewPort);
// 	std::cout << "viewport[" << viewPort[0] << ", " << viewPort[1] << ", " << viewPort[2] << ", " << viewPort[3] << "]" << std::endl;
// 
// 	glPushMatrix();
// 	//glTransform.translate(0.5, 0.5, 0);
// 	//glTransform.rotate(60.0, 0.0, 0.0, 1.0);
// 	glBegin(GL_QUADS);
// 	glVertex3f(pt[0].x, pt[0].y, 1.0);
// 	glVertex3f(pt[1].x, pt[1].y, 1.0);
// 	glVertex3f(pt[2].x, pt[2].y, -5.0);
// 	glVertex3f(pt[3].x, pt[3].y, -5.0);
// 	glEnd();
// 	glPopMatrix();
// 	glFlush();
// }
// 
// void display1()
// {
// 
// }
// 
// void keyboard(unsigned char ch, int x, int y)
// {
// 	op = ch;
// 	switch (ch)
// 	{
// 	case 'T':
// 	case 't':
// 	case 'R':
// 	case 'r':
// 	case 'S':
// 	case 's':
// 	case 'B':
// 	case 'b':
// 	case 'Q':
// 	case 'q':
// 		glutPostRedisplay();
// 		break;
// 
// 	default:
// 		break;
// 	}
// }
// 
// int main(int argc, char** argv)
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
// 	glutInitWindowSize(500, 500);
// 	glutInitWindowPosition(100, 100);
// 	glutCreateWindow(argv[0]);
// 	//glutFullScreen();
// 	glutIconifyWindow();//最小化
// 	glutSetIconTitle("最小化名字");
// 	glutShowWindow();//显示窗口
// 	glutSetCursor(GLUT_CURSOR_DESTROY); //光标
// 	init();
// 	glutDisplayFunc(display);
// 	glutKeyboardFunc(keyboard);
// 	glutReshapeFunc(reshape);
// 
// // 	glutCreateWindow("Second");
// // 	glutDisplayFunc(display1);
// 
// 	glutMainLoop();
// 	return 0;
// }