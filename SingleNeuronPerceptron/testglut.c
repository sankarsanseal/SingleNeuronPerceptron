#include <GL/glut.h>

void showme(void);
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
glutInitWindowPosition(100,100);
glutInitWindowSize(320,320);
glOrtho(-1.2, 1.2, -1.2, 1.2, -1.2, 1.2);
glutCreateWindow("Teapot");
glutDisplayFunc(showme);
glClearColor(0.2,0.5,0.2,0.2);
glutMainLoop();
return 0;
}
//--- showme
void showme(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2f(-0.4, -0.4);
glColor3f(0,1,1);
glVertex2f(0.5,0.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(0,0);
glVertex2f(3,2);
glEnd();
glFlush();
}
