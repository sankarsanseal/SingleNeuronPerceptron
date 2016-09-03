#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nnstruct.h"

void showme(void);

int n;
twoDem * pc;
float w[NO_OF_PARAMETER];

const int width=640;
const int height=640;
const float eta=0.3f;

int signum(int i)
{
	int j;
	float sum=0;
	for(j=0;j<NO_OF_PARAMETER;j++)
	{
		sum+=w[j]*(pc[i].x[j]);
	}

	if(sum >= 0.0f)
		return 1;
	else if (sum < 0.0f)
		return -1;
}

void updateW(int i)
{
	int j;
	int result=signum(i);
	for(j=0;j<NO_OF_PARAMETER;j++)
	{
		//fprintf(stdout,"%d : x[%d]:%f  w[%d]:%f , signum: %d, result : %d, ylabel: %d\n"
		//		,i,j,pc[i].x[j],j,w[j], signum(i),result,pc[i].ylabel);
		//fprintf(stdout,"%f\n",eta*((float)((pc[i].ylabel)-result))*(pc[i].x[j]));
		w[j]+=eta*((float)((pc[i].ylabel)-result))*(pc[i].x[j]);
		//fprintf(stdout,"%d : x[%d]:%f  w[%d]:%f , signum: %d, result : %d, ylabel: %d\n"
		//				,i,j,pc[i].x[j],j,w[j], signum(i),result,pc[i].ylabel);
	}

}

int main(int argc, char **argv)
{


	int i, j;
	fprintf(stdout, "Enter the number of points:");
	fscanf(stdin, "%d", &n);

	pc = (twoDem *) malloc(sizeof(twoDem) * n);

	for (i = 0; i < n; i++)
	{
		fprintf(stdout,"Enter details of pattern %d:\n",i+1);
		pc[i].x[0] = 1;
		for (j = 1; j < NO_OF_PARAMETER; j++)
		{

			fprintf(stdout, "Enter the x%d:", j);
			fscanf(stdin, "%f%*c", &(pc[i].x[j]));
			if(j==1)
				pc[i].x[j]/=width;
			else if(j==2)
				pc[i].x[j]/=height;
		}
		fprintf(stdout,"Enter the target label:");
		fscanf(stdin,"%d%*c",&(pc[i].ylabel));
	}

	srand(time(NULL));
	for(j=0;j<NO_OF_PARAMETER;j++)
	{
		w[j]=rand()%width;
		w[j]/=width;
	}



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
//glViewport(0,0,640,640);
	glOrtho(-1, 1, -1, 1, -1, 1);
	glutCreateWindow("Single Layer Perceptron");
	glutDisplayFunc(showme);
	glClearColor(1, 1, 1, 0.2);
	glutMainLoop();
	return 0;
}
//--- showme
void showme(void)
{
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen

	glPointSize(3.0);

	for(i=0;i<n;i++)
	{
		glClear(GL_COLOR_BUFFER_BIT); // clear the screen
		glBegin(GL_LINES);
		glColor3f(0,0,1);
		glVertex2f(0,-1);
		glVertex2f(0,1);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0,0,1);
		glVertex2f(-1,0);
		glVertex2f(1,0);

		glEnd();

		for(j=0;j<=i;j++)
		{
		glBegin(GL_POINTS);
		if(pc[j].ylabel==1)
			glColor3f(0,1,0);
		else if(pc[j].ylabel==-1)
			glColor3f(1,0,0);
		glVertex2f(pc[j].x[1],pc[j].x[2]);

		glEnd();

		}

		updateW(i);

		glBegin(GL_LINES);
		glColor3f(0.5,0.5,0.5);
		glVertex2f(0,-w[0]/w[2]);
		glVertex2f(width,-(w[1]/w[2])*width-w[0]/w[2]);
		glEnd();
		glFlush();

		sleep(2);
	}

	glFlush();
}
