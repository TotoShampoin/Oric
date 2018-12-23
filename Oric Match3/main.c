#include <lib.h>

#define INITTIMER 	65535
#define MAX_X		8
#define MAX_Y		8
#define MINIMAL 	3

//Fonctions externes
void AdvancedPrint(int,int,char*);
void APlot(int,int,char,int);
short rand124();

//Variables
short grid[MAX_X][MAX_Y];
short pos[2] = {0,0};		// x, y
int score;


unsigned int compteur=0;
char *aff = "           ";

void debug(char *s){
		compteur++;   
		aff = itoa(compteur);   
		AdvancedPrint(0,0,aff); 
		AdvancedPrint(5,0,s); 
}

//Affichage
void plout(x,y,gem)
{
	int px, py;
	px = 2+x*3; py = 3+y*3;
	if(gem==0)			//void
	{
		APlot(px  ,py  ,0,1); AdvancedPrint(px+1,py  ,"  ");
		APlot(px  ,py+1,0,1); AdvancedPrint(px+1,py+1,"  ");
		APlot(px  ,py+2,0,1); AdvancedPrint(px+1,py+2,"  ");
	}
	if(gem>0 && gem<8)
	{
		APlot(px  ,py  ,gem,1); APlot(px+1,py  ,90+gem*4,1); APlot(px+2,py  ,91+gem*4,1);
		APlot(px  ,py+1,gem,1); APlot(px+1,py+1,92+gem*4,1); APlot(px+2,py+1,93+gem*4,1);
		APlot(px  ,py+2,0,1); AdvancedPrint(px+1,py+2,"  ");
	}
}

//Gestion de la grille
void checkplot(scr)
{
	short grid2[MAX_X][MAX_Y];
	short a, x, y, align;
	
	for(x=0;x<MAX_X;x++)
	{
		for(y=0;y<MAX_Y;y++)
			{grid2[x][y]=0;}
	}
	
	for(y=0;y<MAX_Y;y++)
	{
		align = 1;
		for(x=1;x<MAX_X;x++)
		{
			if (grid[x][y]==grid[x-1][y])
				{align += 1;}
			else if(align>=MINIMAL)
			{
				for(a=1;a<align;a++)
					{grid2[x-a][y]=1;}
				if(scr==1)
					{score += align;}
				align=1;
			}
		}
		if(align>=MINIMAL)
		{
			for(a=1;a<align;a++)
				{grid2[x-a][y]=1;}
			if(scr==1)
				{score += align;}
		}
	}
	
	debug("Y OK");
	for(x=0;x<MAX_X;x++)
	{
		align = 1;
		for(y=1;y<MAX_Y;y++)
		{
			if (grid[x][y]==grid[x][y-1])
				{align += 1;}
			else if(align>=MINIMAL)
			{
				for(a=1;a<align;a++)
					{grid2[x][y-a]=1;}
				if(scr==1)
					{score += align;}
				align=1;
			}
		}
		if(align>=MINIMAL)
		{
			for(a=1;a<align;a++)
				{grid2[x][y-a]=1;}
			if(scr==1)
				{score += align;}
		}
	}

	debug("X BOUCLE 1 OK");
	for(x=0;x<MAX_X;x++)
	{
		for(y=0;y<MAX_Y;y++)
		{
			if(grid2[x][y]==1)
			{
				grid[x][y]=0; 
				plout(x,y,0);
			}
		}
	}
	
	debug("X BOUCLE 2 OK");
}

void fil()
{
	short x, y, r;
	debug("ENTRE DANS FIL");
	for(x=0;x<MAX_X;x++)
	{
		if(grid[x][0]==0)
		{
			grid[x][0]=rand124(); 
			debug("APPEL RAND OK");
			plout(x,y,grid[x][0]);
		}
		for(y=7;y>0;y--)
		{
			if(grid[x][y]==0)
			{
				grid[x][y]=grid[x][y-1]; plout(x,y,grid[x][y]);
				grid[x][y-1]=0; plout(x,y-1,grid[x][y-1]);
			}
		}
		debug("BOUCLE FIL Y OK");
	}
	debug("BOUCLE FIL X OK");
}

//Main
void main()
{
	int x, y, p, r;
	unsigned short i;
	
	for(x=0;x<MAX_X;x++)
		for(y=0;y<MAX_Y;y++)
		{
			grid[x][y]=0;
			plout(x,y,grid[x][y]);
		}
		
	for(y=0;y<28;y++)
	{
		p=0xBB80+y*40;
		poke(p,7); poke(p+1,7);
	}
	while(1)
	{
		checkplot(0);
		debug("RETOUR CHKP OK");
		fil();
		debug("RETOUR FIL OK");
		debug("");
	}
}
