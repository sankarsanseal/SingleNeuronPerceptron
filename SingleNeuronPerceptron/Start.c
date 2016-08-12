/*
 * Start.c
 *
 *  Created on: 12 আগস্ট, 2016
 *      Author: sankarsan
 */
#include <graphics.h>

int main()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"");
	circle(300,300,150);
	getch();
	closegraph();
	return 0;
}

