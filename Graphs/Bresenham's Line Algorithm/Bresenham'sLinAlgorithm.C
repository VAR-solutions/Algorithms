#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
		int gd=DETECT,gm,i,s1;
		float x,y,x1,y1,x2,y2,pk,dx,dy;
		clrscr();
		initgraph(&gd,&gm,"C:/TURBOC3/BGI");
		printf("enter the coordinates");
		scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1;
		y=y1;
		putpixel(x,y,03);
		pk=(2*dy)-dx;
		i=1;
		do{
			if( pk < 0)
			{
				x=x+1;
				y=y;
				putpixel(x,y,04);
				pk=pk+2*dy;

				}

			else

				{
				x= x + 1;
				y= y + 1;
				putpixel(x,y,05);
				pk=pk+2*dy-2*dx;
				}
			i++;

		}while(i<=dx);
		getch();
		closegraph();

}