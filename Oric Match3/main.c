#include <lib.h>

#define INITTIMER 	65535
#define MAX_X		8
#define MAX_Y		8
#define MINIMAL 	3

//Fonctions externes
void AdvancedPrint(int,int,char*);
void APlot(int,int,char,int);
short rand124();
void delai(char i);
void CG_DEFCHAR();

//Variables
short grid[MAX_X][MAX_Y];
short grid2[MAX_X][MAX_Y];

short pos[2] = {0,0};		// x, y
char score[] = "00000000";

short px,py;

short k,moveok;
short selx,sely,difx,dify, perx,pery, temp0,select, permut;

int tpx, tpy;
int calc1, calc2;
int iwait;

unsigned int compteur=0;
char *aff  ="        ";
char *disp ="        ";
char *buf3 ="        ";
char *itoaptr;

void nop(){
	int fg=0;
}

void debug(char *s){
		compteur++;   
		aff = itoa(compteur); 
		AdvancedPrint(0,0,aff); 
		AdvancedPrint(5,0,s); 
}

//Affichage
void plout(int pltx,int plty,int gem,int inv)
{
	int ge4;
	tpx = 4+pltx*3; 
	tpy = 3+plty*3;
	if(gem==0)
	{
		APlot(tpx  ,tpy  ,0,1); AdvancedPrint(tpx+1,tpy  ,"  ");
		APlot(tpx  ,tpy+1,0,1); AdvancedPrint(tpx+1,tpy+1,"  ");
	} else if(gem>0 && gem<8)
	{
		ge4 = gem * 4 + 128 * inv;
		APlot(tpx  ,tpy  ,gem,1); APlot(tpx+1,tpy  ,90+ge4,1); APlot(tpx+2,tpy  ,91+ge4,1);
		APlot(tpx  ,tpy+1,gem,1); APlot(tpx+1,tpy+1,92+ge4,1); APlot(tpx+2,tpy+1,93+ge4,1);
	}
	nop();
}

void affcurs(int pltx,int plty)
{
	tpx = 4+pltx*3; 
	tpy = 2+plty*3;
	APlot(tpx   , tpy   , 43 ,1 ); 
	APlot(tpx   , tpy+3 , 43 ,1 ); 
	APlot(tpx+3 , tpy   , 43 ,1 ); 
	APlot(tpx+3 , tpy+3 , 43 ,1 ); 
	nop();
}

void effcurs(int pltx,int plty)
{
	tpx = 4+pltx*3; 
	tpy = 2+plty*3;
	APlot(tpx   , tpy   , 32 ,1 ); 
	APlot(tpx   , tpy+3 , 32 ,1 ); 
	APlot(tpx+3 , tpy+3 , 32 ,1 ); 
	APlot(tpx+3 , tpy   , 32 ,1 ); 
	nop();
}

void majscore(int sc)
{
	int l,m,n;
	int scrtmp;
	int retenue;
	char *sctmp;
	
	m=0;n=0;
	scrtmp = (sc*sc) ; //valeur ASC de 0 : 48
	sctmp = itoa(scrtmp);
	retenue = 0;
	l=7;
	for(n = strlen(sctmp)-1;n>=0;n--){
		score[l] = score[l] + *(sctmp+n)- 48 + retenue;
		if(score[l] > 57){
			retenue = 1;
			score[l] = score[l]-10;
		}else{
			retenue = 0;
		}
		l--;
	}
	while(retenue == 1 && l>=0){
		score[l] = score[l] + retenue;
		if(score[l] > 57){
			retenue = 1;
			score[l] = score[l]-10;
		}else{
			retenue = 0;
		}
		l--;
	}
		
	APlot(31,6,5,1);
	AdvancedPrint(32,6,"        ");
	AdvancedPrint(32,6,score);
	nop();
}
//Gestion de la grille
void checkplot(scr)
{
	short a, x, y, align;
	int scoretmp=0;
	
	for(x=0;x<8;x++)for(y=0;y<8;y++) grid2[x][y]=0;
	
	for(y=0;y<MAX_Y;y++)
	{
		align = 1;
		for(x=1;x<MAX_X;x++)
		{
			if (grid[x][y]==grid[x-1][y]){
				align = align + 1;
			} else {
				if(align>=MINIMAL){
					for(a=1;a<=align;a++){
						grid2[x-a][y]=1;
					}
					scoretmp += align;
				}
				align=1;
			}
		}

		if(align>=MINIMAL)
		{
			for(a=1;a<=align;a++)
				{grid2[x-a][y]=1;}
			scoretmp += align;
		}

	}
	
	for(x=0;x<MAX_X;x++) {
		align = 1;
		for(y=1;y<MAX_Y;y++)
		{
			if (grid[x][y]==grid[x][y-1]){
				align += 1;
			} else {
				if(align>=MINIMAL){
					for(a=1;a<=align;a++)
						{grid2[x][y-a]=1;}
					scoretmp += align;
				}
				align=1;
			}
		}

		if(align>=MINIMAL)
		{
			for(a=1;a<=align;a++)
				{grid2[x][y-a]=1;}
			scoretmp += align;
		}

	}
	if(scoretmp>0){
		if(select==1||permut==1){
			select=0;
			permut=0;
			plout( selx , sely  , grid[selx][sely] , 0 );
			plout( px , py  , grid[px][py] , 0 );
		}	
		moveok = 1;
		if(scr){
			majscore(scoretmp);
		}
		//clignotement
		for(x=0;x<MAX_X;x++){
			for(y=0;y<MAX_Y;y++){
				if(grid2[x][y]==1){
					plout(x,y,0,0);
				}
			}
		}
		delai(50);
		for(x=0;x<MAX_X;x++){
			for(y=0;y<MAX_Y;y++){
				if(grid2[x][y]==1){
					plout(x,y,grid[x][y],0);
				}
			}
		}
		delai(50);
		for(x=0;x<MAX_X;x++){
			for(y=0;y<MAX_Y;y++){
				if(grid2[x][y]==1){
					plout(x,y,0,0);
				}
			}
		}
		delai(50);
		for(x=0;x<MAX_X;x++){
			for(y=0;y<MAX_Y;y++){
				if(grid2[x][y]==1){
					plout(x,y,grid[x][y],0);
				}
			}
		}
		delai(50);
		for(x=0;x<MAX_X;x++){
			for(y=0;y<MAX_Y;y++){
				if(grid2[x][y]==1){
					grid[x][y]=0; 
					plout(x,y,0,0);
				}
			}
		}
	} else {
		if(permut==1){
			temp0 = grid[px][py];
			grid[px][py] = grid[selx][sely]; 
			plout( px , py  , grid[px][py] , 0 );
			grid[selx][sely] = temp0;
			plout( selx , sely  , grid[selx][sely] , 0 );
			moveok = 0;
			permut=0;
		}
		if(select==1){
			plout( selx , sely  , grid[selx][sely] , 1 );
		}
	}
	nop();
	
}

void fil()
{
	short x, y, r, z;
	for(x=0;x<MAX_X;x++)
	{
		for(y=7;y>0;y--)
		{
			if(grid[x][0]==0)
			{
				grid[x][0]=rand124(); 
				plout(x,0,grid[x][0],0);
				moveok = 1;
			}
			if(grid[x][y]==0)
			{
				moveok = 1;
				z=y-1;
				while (grid[x][z]==0) z--;
				grid[x][y] = grid[x][z];
				plout( x , y  , grid[x][y] , 0 );
				grid[x][z]=0;
			}
		}
	}
	if(moveok ==1){
		plout( selx , sely  , grid[selx][sely] , 0 );
		plout( px , py  , grid[px][py] , 0 );
	}
	nop();
}

void control(){
	affcurs(px,py);
	k=get();
	effcurs(px,py);
	if( k == 11 ) { 
		py = py - 1;
		if( py < 0 ) py = MAX_Y - 1 ;
	} else 	if( k == 10 ) { 
		py = py + 1;
		if( py >= MAX_Y ) py=0;
	} else 	if( k == 8 ) { 
		px = px - 1; 
		if( px < 0 ) px = MAX_X - 1 ;
	} else 	if( k == 9 ) { 
		px = px + 1; 
		if( px >= MAX_X ) px = 0 ;
	} else 	if( k== 32 ) {
		if( select == 0){
			select = 1;
			selx = px;
			sely = py;
			plout( px , py  , grid[px][py] , 1 );
			
		} else {
			select = 0;
			difx = px-selx ; 
			dify = py-sely ;
			if(difx<0) difx= -difx;
			if(dify<0) dify= -dify;
			if( (difx == 0 && dify == 1) || (difx == 1 && dify == 0) ){
				permut = 1;
				temp0 = grid[px][py];
				grid[px][py] = grid[selx][sely]; 
				grid[selx][sely] = temp0;
				plout( px , py  , 0 , 0 );
				plout( selx , sely  , 0 , 0 );
				delai(80);
				plout( px , py  , grid[px][py] , 0 );
				plout( selx , sely  , grid[selx][sely] , 0 );
				delai(80);
				plout( px , py  , grid[selx][sely] , 0 );
				plout( selx , sely  , grid[px][py] , 0 );
				delai(80);
				plout( px , py  , grid[px][py] , 0 );
				plout( selx , sely  , grid[selx][sely] , 0 );
			} else {
				plout( selx , sely  , grid[selx][sely] , 0 );
			}
		}
	}
	nop();
} 


//Main
void main()
{
	int x, y, p, r;
	unsigned short i;
	int ticks;
	
	cls();
	AdvancedPrint(2,10,"Appuyez sur une touche");
	get();
	
	CG_DEFCHAR();
	poke(0x26A,10);
	ticks = deek(0x276);
	srandom(ticks);
	cls();
	px=0;py=0;
	
	memset(grid,0,64);
	p=0xBB80;
	for(y=0;y<28;y++)
	{
		poke(p,16); poke(p+1,7);
		p=p+40;
	}
	fil();
	while(1){
		do{
			moveok=0;
			checkplot(1);
			fil();
		}while(moveok);
		control();
		nop();
	}
}
