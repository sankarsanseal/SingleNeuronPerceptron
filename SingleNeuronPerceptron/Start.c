/*
 * Start.c
 *
 *  Created on: 12 আগস্ট, 2016
 *      Author: sankarsan
 */
#include<graphics.h>
#include "nnstruct.h"
#include <stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define CIRRAD 4


int n;
twoDem * readData()
{

	int i,j;
	twoDem * temp=NULL;
	printf("Enter the number of training samples:");
	scanf("%d",&n);
	temp=(twoDem *)malloc(sizeof(twoDem)*n);
	if(temp)
	{
		for(i=0;i<n;i++)
		{
			temp[i].x[0]=1;
			printf("Enter the  parameter values, actual value and label for observation %i:",i+1);
			for(j=1;j<NO_OF_PARAMETER;j++)
				scanf("%d",&(temp[i].x[j]));
			scanf("%d",&(temp[i].ylabel));
		}
	}
	else
	{
		printf("Problem with memory allocation problem.: %s",strerror(errno));
	}
return temp;
}

float sigmoid(float input)
{
	return 1/(1+exp(-input));
}

int main()
{

	int i,j;
	twoDem * dataset=NULL;
	dataset=readData();
	int originx, originy;
	float w[NO_OF_PARAMETER];
	int temp_w[NO_OF_PARAMETER];
	int x_inter,y_inter;
	const int learning_rate=0.3;
	float observed_value;
	float slope;
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"");

	originx=getmaxx()/10;
	originy=getmaxy()-getmaxy()/10;

	outtextxy(originx-15,originy+2,"O");
	//outtextxy(getmaxx()-20,originy+20,"X");
	//outtextxy(originx,getmaxy(),"Y");
	setcolor(GREEN);
	line(originx,0,originx,getmaxy());

	line(0,originy,getmaxx(),originy);

	for(i=0;i<n;i++)
	{
		if(dataset[i].ylabel==1)
		{
			setcolor(BLUE);
			circle(originx+dataset[i].x[1],originy-dataset[i].x[2],CIRRAD);
		}
		else if(dataset[i].ylabel==-1)
		{
			setcolor(RED);
			circle(originx+dataset[i].x[1],originy-dataset[i].x[2],CIRRAD);
		}
	}

	srand(time(NULL));
	w[0]=-rand()%(getmaxx()> getmaxy()?getmaxy():getmaxx());
	w[1]=rand()%getmaxx();
	w[2]=rand()%getmaxy();

	fprintf(stdout,"w0:%d w1:%d \n",w[0],w[1]);


	for(i=0;i<n;i++)
	{
		observed_value=0;
		for(j=0;j<NO_OF_PARAMETER;j++)
		{
			observed_value+=w[j]*dataset[i].x[j];
		}

		fprintf(stdout,"Sigmoid value %f\n", sigmoid(observed_value));

/*		for(j=0;j<NO_OF_PARAMETER;j++)
		temp_w[i]=w[i];

		for(j=0;j<NO_OF_PARAMETER;j++)
		{
				w[j]=temp_w[j] + learning_rate*(observed_value - dataset->x[NO_OF_PARAMETER-1])*dataset->x[j];
		}

*/
	}

	/*for(j=0;j<NO_OF_PARAMETER-1;j++)
		fprintf(stdout,"w[%d]:%d\n",j,w[j]);
*/

	getch();
	closegraph();
	free(dataset);
	return 0;
}
