#include <windows.h>
#include <GL/glut.h> 

float x = 1, y = 1;

float k=2, a=1;
void Initialize()
{
	glClearColor(0.4, 0.9, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800, 0.0, 500);
}
void DrawRectangle()
{
	float Rx = -0.2,Ry=-0.5;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4);
	glEnable(GL_LINE_SMOOTH);
	glColor3f(1, 0.1, 0.1);	
	glBegin(GL_QUADS);
	glVertex2f(Rx, Ry+0.3);
	glVertex2f(Rx+0.2, Ry+0.3);
	glVertex2f(Rx+0.2, Ry);
	glVertex2f(Rx, Ry);
	glEnd();
	glLineWidth(1);
	glColor3f(0.0, 0.0, 0.0);
	
}
float scale=1.1, scaleTemp= 0.1;
void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glLoadIdentity();
	y = a*x*x;
		glPushMatrix();	
	glTranslated(x,y,1);
	if (scale > k) {
		scaleTemp = -0.1;
	};
	if (scale < 1) {
		scaleTemp = 0.1;
	};
	scale += scaleTemp;
	glScaled(scale, scale, scale);
	DrawRectangle();
	glPopMatrix();
	glFlush();
}
int sign = -1;
void winReshapeFcn(GLint width, GLint height)
{

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, GLdouble(width), 0.0, GLdouble(height));

	glClear(GL_COLOR_BUFFER_BIT);    // ќчищенн¤ в≥кна

}
void timerFunc(int param)
{
	if ( a*x*x > 1) sign *= -1;
		x += 0.1*sign;
	Draw();
	glutTimerFunc(100, timerFunc, 0);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(100, 143);
	glutCreateWindow("Lab3");
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 0.0, 0.0,0.0, -0.0, 0.0);
	glutDisplayFunc(Draw);
	glutTimerFunc(1, timerFunc, 1);
	glutMainLoop();
}



