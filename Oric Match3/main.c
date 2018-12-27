#include <lib.h>

#define INITTIMER 	65535
#define MAX_X		8
#define MAX_Y		8
#define MINIMAL 	3

#define x0   9
#define y0  2

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
char score[] = "0000000";

short px,py;

short k,moveok;
short selx,sely,difx,dify, perx,pery, temp0,select, permut;

int tpx, tpy;
int calc1, calc2;
int iwait,contpartie,newgame;
char kr;

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
		get();
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

void accueil()
{
	int p,y,qsd;
	cls();
	
	p=0xBB80;
	for(y=0;y<14;y++)
	{
		poke(p,16); poke(p+1,7);poke(p+2,9);
		p=p+40;
	}
	for(y=14;y<28;y++)
	{
		poke(p,16); poke(p+1,7);
		p=p+40;
	}
	
	 AdvancedPrint(3+x0,1+y0,"AaB EaB DYC AaB GHI");APlot(18+x0,1+y0,6,1);
	 AdvancedPrint(3+x0,2+y0,"b b UdJ  b  b   QRS");APlot(18+x0,2+y0,6,1);
	 AdvancedPrint(3+x0,3+y0,"b b  eT  b  b   [ ]");APlot(7 +x0,3+y0,95,1);APlot(18+x0,3+y0,6,1);APlot(20+x0,3+y0,92,1);
	 AdvancedPrint(3+x0,4+y0,"KcL W W NZM KcL  f ");APlot(18+x0,4+y0,6,1);
	 AdvancedPrint(3+x0,5+y0,"  X EaC X X EaC X  ");
	 AdvancedPrint(3+x0,6+y0,"  b Ud^ b b Ud^ b  ");
	 AdvancedPrint(3+x0,7+y0,"  b  eh bXb  eh b  ");APlot(7+x0,7+y0,95,1);APlot(15+x0,7+y0,95,1);
	 AdvancedPrint(3+x0,8+y0,"KcL OcM OZP OcM OcM");
	for(qsd = 3;qsd<40;qsd++){
		APlot(qsd,14 ,'"',1);
	}
	AdvancedPrint(3,16,"UTILISER LES FLECHES POUR SE DEPLACER");
	AdvancedPrint(3,18,"       ESPACE POUR PERMUTER");
	AdvancedPrint(3,20,"   ESCAPE SI PAS DE SOLUTION : FIN ");
	AdvancedPrint(3,22,"  APPUYEZ SUR UNE TOUCHE POUR JOUER");
	AdvancedPrint(3,24,"     Q POUR QUITTER MAINTENANT");
		
	kr=get();
	if(kr=='Q'){
		newgame=0;
	} else {
		newgame=1;
	}
	nop();
	
}

void afftour()
{
	int qsd;
	APlot(2  , 1  , '!' ,1 ); 
	APlot(2  , 27 , '%' ,1 ); 
	APlot(30 , 1  , '#' ,1 ); 
	APlot(30 , 27 , '&' ,1 ); 
	APlot(29 , 1  , 7   ,1 ); 
	APlot(29 , 27 , 7   ,1 ); 
	for(qsd = 2;qsd<27;qsd++){
		APlot(2 ,qsd,'$',1);
		APlot(29 , qsd  , 7   ,1 ); 
		APlot(30,qsd,'$',1);
	}
	for(qsd = 3;qsd<30;qsd++){
		APlot(qsd,1 ,'"',1);
		APlot(qsd,27,'"',1);
	}

	nop();
}
void affcurs(int pltx,int plty)
{
	tpx = 4+pltx*3; 
	tpy = 2+plty*3;
	APlot(tpx   , tpy   , '!' ,1 ); 
	APlot(tpx   , tpy+3 , '%' ,1 ); 
	APlot(tpx+3 , tpy   , '#' ,1 ); 
	APlot(tpx+3 , tpy+3 , '&' ,1 ); 
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

void afftheend(int zto)
{
	tpx = 4+10*3; 
	tpy = 2+6*3;
	APlot(tpx  ,tpy  ,zto,1); AdvancedPrint(tpx+1,tpy  ,"*+,");
	APlot(tpx  ,tpy+1,zto,1); AdvancedPrint(tpx+1,tpy+1,"-./");
	APlot(tpx  ,tpy+2,zto,1); AdvancedPrint(tpx+1,tpy+2,"<=>");
	APlot(31  ,tpy+4,7,1); AdvancedPrint(34,tpy+4,"ESC O");
	nop();
}

void afftitre()
{
	APlot(31  ,4  ,7,1); /*APlot(32  ,2  ,10,1); */ AdvancedPrint(33,4  ," ORIC"); APlot(38  ,4  ,6,1); APlot(39  ,4  ,126,1);
//	APlot(31  ,3  ,7,1); APlot(32  ,3  ,10,1); AdvancedPrint(33,3  ," ORIC"); APlot(38  ,3  ,6,1); APlot(39  ,3  ,126,1);
	APlot(31  ,5  ,7,1); /*APlot(32  ,4  ,10,1); */ AdvancedPrint(33,5  ," JEWEL ");
//	APlot(31  ,5  ,7,1); APlot(32  ,5  ,10,1); AdvancedPrint(33,5  ," JEWEL ");
	nop();
}

void music1(){
	music(1,2,12,0);
	music(2,4,4,0);
	music(3,4,7,0);
	play(7,0,1,1024);
	nop();
}

void music2(){
	music(1,3,12,0);
	music(2,5,4,0);
	music(3,5,7,0);
	play(7,0,1,1024);
	nop();
}

void music3(){
	music(1,4,12,0);
	music(2,6,4,0);
	music(3,5,7,0);
	play(7,0,1,1024);
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
	l=6;
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
		
	APlot(31,8,5,1);
	AdvancedPrint(33,8," SCORE  ");		
	APlot(31,11,5,1);
//	APlot(31,10,5,1);
//	APlot(31,11,5,1);	
//	APlot(32,10,10,1);
//	APlot(32,11,10,1);
	AdvancedPrint(33,11,"       ");
//	AdvancedPrint(33,10,"       ");
//	AdvancedPrint(33,11,"       ");
	AdvancedPrint(33,11,score);
//	AdvancedPrint(33,10,score);
//	AdvancedPrint(33,11,score);
	nop();
}
//Gestion de la grille
void checkplot(scr)
{
	short a, x, y, align;
	int scoretmp;
	
	scoretmp = 0;
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
		if(scoretmp<5) {music1();} else if(scoretmp <8) {music2() ;} else if(scoretmp <10){music3() ;} else {explode();}
		
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
				while(grid[x][0] == 0){
					grid[x][0]=rand124(); 
				}
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
	} else 	if( k == 27 ) { 
		afftheend(1);
		k=get();
		while( k!=27 && k!='O' && k!='N' ){
			k=get();
		}
		if( k == 27 || k=='N' ){
			afftheend(7);
		} else {
			contpartie = 0;
		}
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
	short sauv1,sauv2,sauv3;
	int x, y, p, r;
	unsigned short i;
	int ticks;
	
	sauv1 = peek(0x24E);
	sauv2 = peek(0x24F);
	sauv3 = peek(0xBB80+35);
	poke(0x26A,10);
	poke(0x24E,8);
	poke(0x24F,6);
	poke(0xBB80+35,0);
	cls();	
	CG_DEFCHAR();
	accueil();

	ticks = deek(0x276);
	srandom(ticks);

	while(newgame){	
		cls();
		px=0;py=0;
		
		for(i=0;i<7;i++)score[i]='0';
		memset(grid,0,64);
		p=0xBB80;
		for(y=0;y<28;y++)
		{
			poke(p,16); poke(p+1,7);
			p=p+40;
		}
		afftitre();
		afftour();
		afftheend(7);
		fil();
		contpartie = 1;
		while(contpartie){
			do{
				moveok=0;
				checkplot(1);
				fil();
			}while(moveok);
			control();
			nop();
		}
		APlot(31,8,3,1);APlot(31,9,3,1);APlot(31,10,3,1);APlot(31,11,3,1);
		AdvancedPrint(32,9, "  FINAL  ");	
		AdvancedPrint(32,15," APPUYEZ ");	
		AdvancedPrint(32,16," SUR UNE ");	
		AdvancedPrint(32,17,"  TOUCHE ");	
		get();
		accueil();
	}
	cls();
	poke(0x26A,3);
	poke(0x24E,sauv1);
	poke(0x24F,sauv2);
	poke(0xBB80+35,sauv3);
}
