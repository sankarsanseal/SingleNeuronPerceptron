/*
 * Start.c
 *
 *  Created on: 12 আগস্ট, 2016
 *      Author: sankarsan
 */
//#include<graphics.h>
#include "nnstruct.h"
#include <stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
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
			printf("Enter the input values and label for observation %i:",i+1);
			for(j=1;j<NO_OF_PARAMETER;j++)
				scanf("%f",&(temp[i].x[j]));
			scanf("%d",&(temp[i].ylabel));
		}
	}
	else
	{
		printf("Problem with memory allocation problem.: %s",strerror(errno));
	}
return temp;
}

int sigmoid(float input)
{
	return (int) 1/(1+exp(-input));
}

int main()
{

	int i,j;
	twoDem * dataset=NULL;
	dataset=readData();
	float w[NO_OF_PARAMETER];
	float hx=0.0F;
	int actual;
	float eta=0.3F; //learning rate
	if(dataset!=NULL)
	{
		srand(time(NULL));
		w[0]=rand()%10;
		w[1]=rand()%10;
		w[2]=rand()%10;

		for(j=0;j<NO_OF_PARAMETER;j++)
				fprintf(stdout,"w[%d]: %f\t",j,w[j]);
				fprintf(stdout,"\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<NO_OF_PARAMETER;j++)
			{
				hx+=w[j]*dataset[i].x[j];
			}
			actual=sigmoid(hx);

			for(j=0;j<NO_OF_PARAMETER;j++)
			{
				w[i]+=eta*(float)(actual-dataset[i].ylabel)*dataset[i].x[j];
			}
		}

		for(j=0;j<NO_OF_PARAMETER;j++)
		fprintf(stdout,"w[%d]: %f\t",j,w[j]);
		fprintf(stdout,"\n");

		free(dataset);
	}
	return 0;
}
