#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include<string.h>

int grid[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} ;
int temp[4][4] = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} ;
class high_score
{       public :
	char name[50] ;
	double hscore ;
	int grid[4][4];


}    ;
class box
{
	public:
	int num , point[8];
}a[16];

double score ;

void sound()
{
	sound(500) ;
	delay(50) ;
	nosound() ;
}
void dis(int x )
	{ //450 , 200
	int y =getmaxx() - 100 ;
	int k ;

	settextstyle(0,0,3);
	setfillstyle(1,BLACK) ;
	bar(450,250,getmaxx(),getmaxy());
	int t=0 ;

	while(x>0)
		{t++;
		if(t>10)
		break ;
		 k=x%10;

		if(k==0)
			{
			outtextxy(y , 300 , "0");
			}
		else if ( k == 1 )
			{
			outtextxy(y,300,"1");
			}
		else if ( k == 2 )
			{
			outtextxy(y, 300 , "2");
			}
		else if ( k == 3 )
			{
			outtextxy(y,300 , "3");
			}
		else if ( k == 4 )
			{
			outtextxy(y, 300 , "4");
			}
		else if ( k == 5 )
			{
			outtextxy(y, 300 , "5");
			}
		else if ( k == 6 )
			{
			outtextxy(y, 300 , "6");
			}
		else if ( k == 7 )
			{
			outtextxy(y, 300 , "7");
			}
		else if ( k == 8 )
			{
			outtextxy(y,300 , "8");
			}
		else if ( k == 9 )
			{
			outtextxy(y,300 , "9");
			}
		y=y-50;
		x=x/10 ;
	      }
	}

void refresh(int x[4][4], int score )
	{
	cleardevice();
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1.5) ;
	int k=-1;
	for(int i=0;i<4;i++)
	       {
		for(int j=0;j<4;j++)
			{ k++;
				if(x[i][j]==0)
					{
					setfillstyle(1,1);
					fillpoly(4,a[k].point);
					}
				else if(x[i][j]==2)
					{
					setfillstyle(1,12);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"2");
					}
				else if(x[i][j]==4)
					{
					setfillstyle(1,8);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"4");
					}
				else if(x[i][j]==8)
					{
					setfillstyle(1,3);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"8");
					}
				else if(x[i][j]==16)
					{
					setfillstyle(1,4);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"16");
					}
				else if(x[i][j]==32)
					{
					setfillstyle(1,5);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"32");
					}
				else if(x[i][j]==64)
					{
					setfillstyle(1,6);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2),((a[k].point[3]+a[k].point[5])/2)-10,"64");
					}
				else if(x[i][j]==128)
					{
					setfillstyle(1,13);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2)-20 ,((a[k].point[3]+a[k].point[5])/2)-10,"128");
					}
				else if(x[i][j]==256)
					{
					setfillstyle(1,2);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2)-20,((a[k].point[3]+a[k].point[5])/2)-10,"256");
					}
				else if(x[i][j]==512)
					{
					setfillstyle(1,9);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2)-20,((a[k].point[3]+a[k].point[5])/2)-10,"512");
					}
				else if(x[i][j]==1024)
					{
					setfillstyle(1,10);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2)-30,((a[k].point[3]+a[k].point[5])/2)-10,"1024");
					}
				else if(x[i][j]==2048)
					{
					setfillstyle(1,11);
					fillpoly(4,a[k].point);
					outtextxy(((a[k].point[0]+a[k].point[2])/2)-30,((a[k].point[3]+a[k].point[5])/2)-10,"2048");
					}
			}

		}
		settextstyle(0,0,10);
		int a , b , c , d ;
		int y = getmaxy()/10 * 2;
		a=getmaxx()/6;
		b=2*a -10; ;
		c=3*a -10;
		d=4*a -10;
		a-=10;

		outtextxy(a-20,y/2,"2");
		outtextxy(b-10,y/2,"0");
		outtextxy(c+10,y/2,"4");
		outtextxy(d+20,y/2,"8");
		settextstyle(0,0,3);
		setcolor(GREEN);
		outtextxy(450,200,"SCORE");
		setcolor(WHITE);
		dis(score);
}

void copy(int x[4][4] , int y[4][4])
{
	for (int i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			y[i][j] = x[i][j] ;
		}
	}
}

int compare (int x[4][4] , int y[4][4])
{
	int c = 0 ;
	for (int i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if (y[i][j] != x[i][j])
				c = 1 ;
		}
	}
	return c ;
}

int check (int x[4][4])
{


	for (int  i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if ((x[i][j] == x[i+1][j] || x[i+1][j]==0 ))
			{	return 0 ;

			}
			if((x[i][j] == x[i-1][j] || x[i-1][j]==0 ) )
			{	return 0 ;

			}
			if((x[i][j] == x[i][j+1] || x[i][j+1]==0 ))
			{	return 0 ;

			}
			if((x[i][j] == x[i][j-1] || x[i][j-1]==0 ))
			{	return 0 ;

			}
		}
	}
	return 1 ;
}
void menu();

void end (char ch)
{
	int y = getmaxy()/2;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3) ;
	high_score aa;
	ofstream file("high.DAT" , ios::binary ) ;
	for( int qq= 0 ; qq<4 ; qq++ )
		for (int ww = 0 ; ww<4 ; ww ++ )
		 aa.grid[qq][ww] = grid[qq][ww] ;
	strcpy(aa.name , "MUNISH " ) ;
	aa.hscore = score  ;
	file.write((char*)&aa , sizeof(aa) ) ;
	if (ch == 'e')
	{
		cleardevice() ;
		outtextxy(200,y, "GOODBYE!") ;
		delay(2000) ;
		menu();
	}
	else
	{
		getch() ;
		outtextxy(200,y, "GAME OVER!") ;
		delay(2000) ;
		menu();
	}
}
void menu();
void play();
void about()
	{
	cleardevice();
	setbkcolor(BLACK) ;
	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(10,10,"This is a game developed as a computer ") ;
	outtextxy(10,30," project for grade 12 CBSE board ");
	outtextxy(10,50,"project. This is a beta verison created") ;
	outtextxy(10,70,"for fun" ) ;
	delay(2500) ;
	menu();
	}
void instructions()
	{
	cleardevice();
	setbkcolor(BLACK) ;
	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(10,10,"1> MOVEMENTS ") ;
	outtextxy(10,50,"Use the arrow keys to move the tiles  ") ;
	outtextxy(10,70,"across the grid . ") ;
	outtextxy(10,300,"press any key to continue");
	getch();
	cleardevice();
	outtextxy(10,10,"2> How does it work? ") ;
	outtextxy(10,50,"when a box with teh same number is ");
	outtextxy(10,70,"present is adjecent boxes, ");
	outtextxy(10,90,"both boxes join to become one box which" ) ;
	outtextxy(10, 200 ,"is the numerical sum of both boxes." ) ;
	outtextxy(10,300 ,"press any key to continue.");
	setfillstyle(1,12);
	int qq[8]={20,110,100,110,100,190,20,190};
					fillpoly(4,qq);
					settextstyle(0,0,3);
					outtextxy(((qq[0]+qq[2])/2)-10,((qq[3]+qq[5])/2)-10,"2");
	int yy[8]={100,110,180,110,180,190,100,190};
					fillpoly(4,yy);
					settextstyle(0,0,3);
					outtextxy(((yy[0]+yy[2])/2)-10,((yy[3]+yy[5])/2)-10,"2");
	settextstyle(0,0,2);
	getch();
	cleardevice() ;
	outtextxy(10,10,"3> OBJECTIVE" ) ;
	outtextxy(10,50,"The game ends when the grid is full") ;
	outtextxy(10,70, "Or if you obtain the 2048 box." );
	int zz[8]={100,110,180,110,180,190,100,190};
					fillpoly(4,zz);
					settextstyle(0,0,2);
					outtextxy(((zz[0]+zz[2])/2)-30,((zz[3]+zz[5])/2)-10,"2048");
	getch();



	menu () ;
	}
void high( )
	{ high_score aa;
	ifstream file("high.DAT" , ios::binary ) ;
	file.read((char*)&aa, sizeof(aa));
	file.close();
	cleardevice() ;
	refresh(aa.grid,aa.hscore ) ;
	getch();
	cleardevice () ;

	menu () ;
	}
	/*ofstream g ;
	if ( aa.hscore < score )
		{
		g.open("high.DAT" , ios::binary || ios::trunc) ;



		}
		  */



void select()
	{int x=1 ;
	int a , b , c , d ;
	a=getmaxx()/6;
	b=2*a -10; ;
	c=3*a -10;
	d=4*a -10;
	a-=10;
	char aa;

	while(x!=6)
		{
		 aa=getch();
		 if(x==1)
			{

			if(aa==80)
				{setcolor(WHITE);
				 outtextxy(a ,200 ,"Play Game") ;
				 setcolor(RED);
				 outtextxy(a ,250  ,"Instructions") ;
				 x=2;
				}
			else if ( aa == 13 )
				{
				play () ;
				}


			}
		 else if(x==2)
			{
			if(aa==80)
				{
				setcolor(WHITE);
				outtextxy(a ,250  ,"Instructions") ;
				setcolor(RED);
				outtextxy(a ,300  ,"High scrores");
				x=3;
				}
			else if (aa==72)
				{
				setcolor(RED) ;
				outtextxy(a ,200 ,"Play Game") ;
				 setcolor(WHITE);
				 outtextxy(a ,250  ,"Instructions") ;
				 x=1;
				 }
			else if ( aa == 13 )
				{
				instructions () ;
				}
			}
		 else if(x==3)
			{
			if(aa==72)
				{
				x=2;
				setcolor(RED);
				outtextxy(a ,250  ,"Instructions") ;
				setcolor(WHITE);
				outtextxy(a ,300  ,"High scrores");
				}
			else if ( aa == 80 )
				{
				x = 4 ;
				setcolor( WHITE ) ;
				outtextxy(a ,300  ,"High scrores");
				setcolor(RED) ;
				outtextxy(a ,350  ,"About");
				}
			else if( aa == 13 )
				{
				high() ;
				}
			}
		 else if(x==4)
			{
			if ( aa == 72)
				{
				x= 3 ;
				setcolor(RED);
				outtextxy(a ,300  ,"High scrores");
				setcolor(WHITE) ;
				outtextxy(a ,350  ,"About");
				}
			else if( aa == 80 )
				 {
				 setcolor ( WHITE  ) ;
				 outtextxy(a ,350  ,"About");
				 setcolor(RED) ;
				 outtextxy(a ,400  , "Quit" ) ;
				 x = 5 ;
				 }
			else if(aa==13)
				{
				about();
				}

			}
		 else if(x==5)
			{
			if ( aa == 72)
				{
				x =4  ;
				setcolor ( RED  ) ;
				outtextxy(a ,350  ,"About");
				setcolor(WHITE ) ;
				outtextxy(a ,400  , "Quit" ) ;
				}
			else if(aa==13)
				{
				exit(0);
				x=6;
				}
			}
		}

	}

void menu()
{       settextstyle(0,0,10) ;
	setcolor(WHITE);
	cleardevice();
	int a , b , c , d ;
	int y = getmaxy()/10 * 2;
	a=getmaxx()/6;
	b=2*a -10; ;
	c=3*a -10;
	d=4*a -10;
	a-=10;
	outtextxy(a-20,y/2,"2");
	outtextxy(b-10,y/2,"0");
	outtextxy(c+10,y/2,"4");
	outtextxy(d+20,y/2,"8");
	delay(500);
	settextstyle(0,0,5) ;
	setcolor(RED);
	outtextxy(a ,200 ,"Play Game") ;
	setcolor(WHITE);
	outtextxy(a ,250  ,"Instructions") ;
	outtextxy(a ,300  ,"High scrores");
	outtextxy(a ,350  ,"About");
	outtextxy(a ,400  , "Quit" ) ;

	select();

}
void intro()
{
	cleardevice();
	settextstyle(0,0,50) ;
	int y=getmaxy()/2-100 ;
	setcolor(YELLOW);
	cleardevice();
	int a , b , c , d ;
	a=getmaxx()/6;
	b=2*a -10; ;
	c=3*a -10;
	d=4*a -10;
	a-=10;
	outtextxy(a,y,"2");
	delay(1000);
	cleardevice();
	outtextxy(b,y,"0");
	delay(1000);
	cleardevice();
	outtextxy(c,y,"4");
	delay(1000);
	cleardevice();
	outtextxy(d,y,"8");
	delay(1000);
	setbkcolor(RED);
	setcolor(GREEN);
	cleardevice();
	outtextxy(a,y,"2");
	delay(500);
	cleardevice();
	outtextxy(b,y,"0");
	delay(500);
	cleardevice();
	outtextxy(c,y,"4");
	delay(500);
	cleardevice();
	outtextxy(d,y,"8");
	setcolor(YELLOW);
	setbkcolor(GREEN);
	delay(500);
	cleardevice();
	outtextxy(a,y,"2");
	delay(250);
	cleardevice();
	outtextxy(b,y,"0");
	delay(250);
	cleardevice();
	outtextxy(c,y,"4");
	delay(250);
	cleardevice();
	outtextxy(d,y,"8");
	delay(250);
	cleardevice();
	setcolor(BLUE);
	setbkcolor(13);
	delay(125);
	outtextxy(a,y,"2");
	delay(125);
	cleardevice();
	outtextxy(b,y,"0");
	delay(125);
	cleardevice();
	outtextxy(c,y,"4");
	delay(125);
	cleardevice();
	outtextxy(d,y,"8");
	delay(125);
	setcolor(GREEN);
	setbkcolor(WHITE);
	delay(100);
	cleardevice();
	outtextxy(a,y,"2");
	delay(100);
	cleardevice();
	outtextxy(b,y,"0");
	delay(100);
	cleardevice();
	outtextxy(c,y,"4");
	delay(100);
	cleardevice();
	outtextxy(d,y,"8");
	delay(100);
	setcolor(WHITE);
	setbkcolor(BLACK);
	delay(60);
	cleardevice();
	outtextxy(a-20,y,"2");
	outtextxy(b-10,y,"0");
	outtextxy(c+10,y,"4");
	outtextxy(d+20,y,"8");
	delay(2500);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3) ;
	int z = getmaxy()/2;
	outtextxy(200,z+50, "Loading") ;
	for (int i = 0 ; i < 5 ; i++)
	{
		delay(500) ;
		outtextxy(370+(i*10),z+50, ".") ;
	}
	setcolor(RED);
	for ( i = 0 ; i < 5 ; i++)
	{
		delay(250) ;
		outtextxy(370+(i*10),z+50, ".") ;
	}
	setcolor(BLUE);
	for ( i = 0 ; i < 5 ; i++)
	{
		delay(125) ;
		outtextxy(370+(i*10),z+50, ".") ;
	}
	setcolor(GREEN);
	for ( i = 0 ; i < 5 ; i++)
	{
		delay(50) ;
		outtextxy(370+(i*10),z+50, ".") ;
	}
	cleardevice();

	menu();
}


void up(int x[4][4])
{
	for (int i = 0 ; i < 4 ; i ++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if (x[j][i] == 0)
				continue ;
			for (int k = j+1 ; k < 4 ; k++)
			{
				if (x[j][i] == x[k][i])
				{
					x[j][i] *= 2 ;
					x[k][i] = 0 ;
					score += x[j][i] ;
					break ;
				}
				if (x[k][i] != 0)
					break ;
			}

		}
	}
	for (i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if (x[j][i] == 0)
			{
				for (int k = j+1 ; k < 4 ; k++)
				{
					if (x[k][i] != 0)
					{
						x[j][i] = x[k][i] ;
						x[k][i] = 0 ;
						break ;
					}
				}
			}
		}
	}
}

void left(int x[4][4])
{
	for (int i = 0 ; i < 4 ; i ++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if (x[i][j] == 0)
				continue ;
			for (int k = j+1 ; k < 4 ; k++)
			{
				if (x[i][j] == x[i][k])
				{
					x[i][j] *= 2 ;
					x[i][k] = 0 ;
					score += x[i][j] ;
					break ;
				}
				if (x[i][k] != 0)
					break ;
			}

		}
	}
	for (i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			if (x[i][j] == 0)
			{
				for (int k = j+1 ; k < 4 ; k++)
				{
					if (x[i][k] != 0)
					{
						x[i][j] = x[i][k] ;
						x[i][k] = 0 ;
						break ;
					}
				}
			}
		}
	}
}

void down(int x[4][4])
{
	for (int i = 0 ; i < 4 ; i ++)
	{
		for (int j = 3 ; j >= 0 ; j--)
		{
			if (x[j][i] == 0)
				continue ;
			for (int k = j-1 ; k >= 0 ; k--)
			{
				if (x[j][i] == x[k][i])
				{
					x[j][i] *= 2 ;
					x[k][i] = 0 ;
					score += x[j][i] ;
					break ;
				}
				if (x[k][i] != 0)
					break ;
			}

		}
	}
	for (i = 0 ; i < 4 ; i++)
	{
		for (int j = 3 ; j >= 0 ; j--)
		{
			if (x[j][i] == 0)
			{
				for (int k = j-1 ; k >= 0 ; k--)
				{
					if (x[k][i] != 0)
					{
						x[j][i] = x[k][i] ;
						x[k][i] = 0 ;
						break ;
					}
				}
			}
		}
	}
}

void right(int x[4][4])
{
	for (int i = 0 ; i < 4 ; i ++)
	{
		for (int j = 3 ; j >= 0 ; j--)
		{
			if (x[i][j] == 0)
				continue ;
			for (int k = j-1 ; k >= 0 ; k--)
			{
				if (x[i][j] == x[i][k])
				{
					x[i][j] *= 2 ;
					x[i][k] = 0 ;
					score += x[i][j] ;
					break ;
				}
				if (x[i][k] != 0)
					break ;
			}

		}
	}
	for (i = 0 ; i < 4 ; i++)
	{
		for (int j = 3 ; j >= 0 ; j--)
		{
			if (x[i][j] == 0)
			{
				for (int k = j-1 ; k >= 0 ; k--)
				{
					if (x[i][k] != 0)
					{
						x[i][j] = x[i][k] ;
						x[i][k] = 0 ;
						break ;
					}
				}
			}
		}
	}
}


void change(box a[16])
{
	int c = 100,b=100 ;
	for (int i = 0 ; i <  16 ; i++ , c += 50)
	{
		if(i%4 == 0)
		{
			c = 100 ;
			b += 50 ;
		}
		a[i].point[0] = c ;
		a[i].point[1] = b ;
		a[i].point[2] = c+50 ;
		a[i].point[3] = b ;
		a[i].point[4] = c+50 ;
		a[i].point[5] = b+50 ;
		a[i].point[6] = c ;
		a[i].point[7] = b + 50 ;
	}
}
void play()
	{
	setfillstyle(1,2);

	int c=0,r=0,i,ck,exit ;
	char ch ;
	srand(NULL) ;

	while (ch != 'e')
	{
		exit = 0 ;

		if (compare(temp,grid) == 1)
		{
		sound() ;
		do{
		c = rand() % 4 ; r = rand() % 4 ;
		i = rand() % 2 + 1 ; i *= 2 ;
		if (grid[r][c] != 0)
		{	exit = 1 ; continue ;}
		else
		{       exit = 0 ; }
		grid[r][c] = i ;
		}while(exit == 1) ;
		}
		refresh(grid, score );
		ch = getch() ;
		copy(grid,temp) ;
		ck = check(grid) ;

		if (ck == 1)
			break ;
		else
		{
		if (ck == 1)
			break ;
		if (ch == 72)
			up(grid) ;
		if (ch == 75)
			left(grid) ;
		if (ch == 80)
			down(grid) ;
		if (ch == 77)
			right(grid) ;
		}
	}
	end(ch) ;
	}
void main()
	{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	setbkcolor(BLACK);
	change(a) ;
	intro();





}