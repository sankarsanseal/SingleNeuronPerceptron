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

twoDem * readData()
{
	int n;
	int i;
	twoDem * temp=NULL;
	printf("Enter the number of training samples:");
	scanf("%d",&n);
	temp=(twoDem *)malloc(sizeof(twoDem)*n);
	if(temp)
	{
		for(i=0;i<n;i++)
		{

		}
	}
	else
	{
		printf("Problem with memory allocation problem.: %s",strerror(errno));
	}
return temp;
}

int main()
{

	twoDem * dataset=NULL;
	dataset=readData();
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"");

	setcolor(WHITE);
	line(getmaxx()/10,0,getmaxx()/10,getmaxy());

	line(0,getmaxy()-getmaxy()/10,getmaxx(),getmaxy()-getmaxy()/10);


	outtextxy(400,400,"+");
	setcolor(RED);

	outtextxy(300,150,"-");

	getch();
	closegraph();

	return 0;
}
