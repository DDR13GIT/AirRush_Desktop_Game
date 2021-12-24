#include <iostream>
using namespace std;
#include "iGraphics.h"
#include <Windows.h>
#define screenWidth 1366
#define screenHeight 768
#define rcoinsNumber 1
#define scoinsNumber 2
#define gcoinsNumber 1
#define bird1Number 3
#define copterHeight 190
#define copterwidth 150
#define fireNumber 6
#define upperBGspeed 10
#define upperBGspeed2 16
#define lowerBGspeed 10
#define lowerBGspeed2 16
#define lifeNum 3
#define booms 3
#define booms2 3

#define diamondNumber 1
#define squareNumber 2
#define heartNumber 1
#define bird2Number 3
/*______________________________________GLOBAL VARIABLES LEVEL 1_____________________________________*/

int mposx, mposy;
int x = 0;
int y = 0;
int r = 255;
int g = 255;
int b = 255;
int dx = 10;
int dy = 10;
int fx = 1;

bool collision=false;
bool gotoTop=false;
bool gotoBottom=false;
bool gotoRight=false;
bool gotoLeft=false;
bool gameover=false;
bool music1=true;

int call = 1;
int call2 = 1;
int gamestate = -1;
int len;
int mode=0;
int copter_x, copter_y;
int copterIndex = 0;
int totalscore=0;
int rcoinscore=0;
int scoinscore=0;
int gcoinscore=0;
int diamondscore=0;
int squarescore=0;
int heartscore=0;
int flag=1;
int col=0;
int t=0;
int call3=1;
int upperBG_x, upperBg_y, bgImg, upperBG_x1, upperBg_y1, bgImg2,lowerBG_x, lowerBg_y, bgImg3, lowerBG_x1, lowerBg_y1, bgImg4;
int L2upperBG_x, L2upperBg_y, bgImg5, L2upperBG_x1, L2upperBg_y1, bgImg6,L2lowerBG_x, L2lowerBg_y, bgImg7, L2lowerBG_x1, L2lowerBg_y1, bgImg8;

char str2[100];
char str1[100];
char str[100], str3[100];

/*___________________________________________STRUCTURE OF BLAST1 _____________________________________*/
struct blast{
int blast_x;
int blast_y;
int blastIndex;
bool blastShow;
}boom[booms];

/*___________________________________________STRUCTURE OF BUTTON _____________________________________*/
struct buttonCo
{
	int x;
	int y;
} bCo[5];
/*___________________________________________STRUCTURE OF FIRE _____________________________________*/
struct fire
{
	int fire_x;
	int fire_y;
	int fireIndex;
	bool fireShow;
} fire1[fireNumber],fire2[fireNumber];
/*________________________________________STRUCTURE OF RED COIN _____________________________________*/
struct redcoins
{
	int redcoin_x;
	int redcoin_y;
	int redcoinIndex;
	bool redcoinShow;
} red[1];
/*______________________________________STRUCTURE OF SILVER COIN _____________________________________*/
struct silvercoins
{
	int silvercoin_x;
	int silvercoin_y;
	int silvercoinIndex;
	bool silvercoinShow;
} silver[2];
/*_______________________________________STRUCTURE OF GOLD COIN_______________________________________*/
struct goldcoins
{
	int goldcoin_x;
	int goldcoin_y;
	int goldcoinIndex;
	bool goldcoinShow;
} gold[1];

/*___________________________________________STRUCTURE OF BLAST _____________________________________*/

struct blast2{
int blast2_x;
int blast2_y;
int blast2Index;
bool blast2Show;
}boom2[booms2];
/*___________________________________________STRUCTURE OF BIRD_______________________________________*/
struct bird1s
{
	int bird1_x;
	int bird1_y;
	int bird1Index;
	bool bird1Show;
}enemy[bird1Number];
/*________________________________________STRUCTURE OF DIAMOND _____________________________________*/
struct Diamonds
{
	int diamond_x;
	int diamond_y;
	int diamondIndex;
	bool diamondShow;
} diamond[1];
/*______________________________________STRUCTURE OF SQUARE _____________________________________*/
struct Square
{
	int square_x;
	int square_y;
	int squareIndex;
	bool squareShow;
} square[2];
/*_______________________________________STRUCTURE OF HEART_______________________________________*/
struct Heart
{
	int heart_x;
	int heart_y;
	int heartIndex;
	bool heartShow;
} heart[1];
/*___________________________________________STRUCTURE OF BIRD_______________________________________*/
struct bird2s
{
	int bird2_x;
	int bird2_y;
	int bird2Index;
	bool bird2Show;
}enemy2[bird2Number];
/*___________________________________________STRUCTURE OF LIFE_______________________________________*/
struct forLife
{
   int life_x;
   int life_y;
   int lifeindex;
   bool lifeShow;
 
}life[lifeNum];
/*________________________________ALL IMAGE LOCATION SET FOR LEVEL 1_________________________________*/

char button[20][30] = {"menu\\play.bmp","menu\\score.bmp","menu\\instruction.bmp","menu\\about.bmp","menu\\quit.bmp"};
char homemenu[15] ={"menu\\bg.bmp"};
char play[15] ={"menu\\play.bmp"};
char score[25] ={"menu\\score.bmp"};
char instruction[25]={"menu\\instruction.bmp"};
char about[25]={"menu\\about_us.bmp"};
char quit[25] = {"menu\\quit.bmp"};

char blasts[7][20]={"blast\\1.bmp","blast\\2.bmp","blast\\3.bmp"};
char lifes[7][20]={"life\\life1.bmp","life\\life2.bmp","life\\life3.bmp"};
char copter[6][20] = {"copter\\0001.bmp", "copter\\0002.bmp", "copter\\0003.bmp", "copter\\0004.bmp"};
char redCoin[10][20] = {"redcoin\\1.bmp", "redcoin\\2.bmp", "redcoin\\3.bmp", "redcoin\\4.bmp", "redcoin\\5.bmp", "redcoin\\6.bmp", "redcoin\\7.bmp", "redcoin\\8.bmp", "redcoin\\9.bmp", "redcoin\\10.bmp"};
char silverCoin[10][20] = {"silvercoin\\1.bmp", "silvercoin\\2.bmp", "silvercoin\\3.bmp", "silvercoin\\4.bmp", "silvercoin\\5.bmp", "silvercoin\\6.bmp", "silvercoin\\7.bmp", "silvercoin\\8.bmp", "silvercoin\\9.bmp", "silvercoin\\10.bmp"};
char goldCoin[10][20] = {"goldcoin\\1.bmp", "goldcoin\\2.bmp", "goldcoin\\3.bmp", "goldcoin\\4.bmp", "goldcoin\\5.bmp", "goldcoin\\6.bmp", "goldcoin\\7.bmp", "goldcoin\\8.bmp", "goldcoin\\9.bmp", "goldcoin\\10.bmp"};
char fireimg[17][20]={"fire\\fire_01.bmp","fire\\fire_02.bmp","fire\\fire_03.bmp"};
char bird1Images[17][20] = {
	"level1bird\\1.bmp",
	"level1bird\\2.bmp",
	"level1bird\\3.bmp",
	"level1bird\\4.bmp",
	"level1bird\\5.bmp",
	"level1bird\\6.bmp",
	"level1bird\\7.bmp",
	"level1bird\\8.bmp",
	"level1bird\\9.bmp",
	"level1bird\\10.bmp",
	"level1bird\\11.bmp",
	"level1bird\\12.bmp",
	"level1bird\\13.bmp",
	"level1bird\\14.bmp",
	"level1bird\\15.bmp",
	"level1bird\\16.bmp",
	"level1bird\\17.bmp",
};
/*________________________________ALL IMAGE LOCATION SET FOR LEVEL 2_________________________________*/
char Diamond[12][20]={"diamond\\1.bmp","diamond\\2.bmp","diamond\\3.bmp","diamond\\4.bmp","diamond\\5.bmp","diamond\\6.bmp","diamond\\7.bmp","diamond\\8.bmp","diamond\\9.bmp","diamond\\10.bmp","diamond\\11.bmp","diamond\\12.bmp"};
char Square[12][20]={"square\\1.bmp","square\\2.bmp","square\\3.bmp","square\\4.bmp","square\\5.bmp","square\\6.bmp","square\\7.bmp","square\\8.bmp","square\\9.bmp","square\\10.bmp","square\\11.bmp","square\\12.bmp"};
char Heart[12][20]={"heart\\1.bmp","heart\\2.bmp","heart\\3.bmp","heart\\4.bmp","heart\\5.bmp","heart\\6.bmp","heart\\7.bmp","heart\\8.bmp","heart\\9.bmp","heart\\10.bmp","heart\\11.bmp","heart\\2.bmp"};
char bird2Images[10][20]={"level2bird\\1.bmp","level2bird\\2.bmp","level2bird\\3.bmp","level2bird\\4.bmp","level2bird\\5.bmp","level2bird\\6.bmp","level2bird\\7.bmp","level2bird\\8.bmp","level2bird\\9.bmp","level2bird\\10.bmp"};
/*_______________________________________ALL FUNCTIONS LEVEL 1_______________________________________*/
void change();
void collisioncheck1();
void collisioncheck2();
void collisioncheck3();
void collisioncheck4();
void storescore();
void Lstorescore();

void setbird1Variables();
void blastOn();
void showBlast();

void blast2On();
void show2Blast();
bool collision2=false;
void lifepic();
void lifeAll();
void showscore();
int totalhighscores;
int mod=-1;
void L2change();
void L2collisioncheck1();
void L2collisioncheck2();
void L2collisioncheck3();
void L2collisioncheck4();
void L2storescore();
void setbird2Variables();
void fireMovement2();
void firecollision2();
void Lstorescore();

void drawTextBox()
{
	iShowBMP2(50,360,"menu\\textbox - menu.bmp",0); 
}

/*___________________________________COPTER COLLISION WITH GOLD COIN________________________________*/
void collisioncheck1()
{
	for(int i=0;i<gcoinsNumber;i++)
	{
		if(copter_x+190>=gold[i].goldcoin_x && copter_x<=gold[i].goldcoin_x +49 && copter_y+150>gold[i].goldcoin_y&&  copter_y<gold[i].goldcoin_y+50)
			{
				if(gold[i].goldcoinShow=true)
				{
				gold[i].goldcoinShow=false;
				}
				gold[i].goldcoin_x = rand() % screenWidth;
		        gold[i].goldcoin_y = rand() % (screenHeight-300);
		        gold[i].goldcoinIndex = rand() % 10;
		        gold[i].goldcoinShow = true;
		        gcoinscore=gcoinscore+10;

			}
	}
}
/*___________________________________COPTER COLLISION WITH SILVER COIN________________________________*/
void collisioncheck2()
{
	for(int i=0;i<scoinsNumber;i++)
	{
		if(copter_x+190>=silver[i].silvercoin_x && copter_x<=silver[i].silvercoin_x+50&& copter_y+150>silver[i].silvercoin_y&&copter_y<silver[i].silvercoin_y+50)
			{
				if(silver[i].silvercoinShow=true)
				{
				silver[i].silvercoinShow=false;
				}
				silver[i].silvercoin_x = rand() % screenWidth;
		        silver[i].silvercoin_y = rand() % 200;
		        silver[i].silvercoinIndex = rand() % 10;
		        silver[i].silvercoinShow = true;
		        scoinscore=scoinscore+5;
			}
	}
}
/*___________________________________COPTER COLLISION WITH RED COIN________________________________*/
void collisioncheck3()
{
	for(int i=0;i<rcoinsNumber;i++)
	{
		if(copter_x+190>=red[i].redcoin_x && copter_x<=red[i].redcoin_x+50 && copter_y+150>red[i].redcoin_y && copter_y<red[i].redcoin_y+50)
		   {
			   if(red[i].redcoinShow=true){
			    red[i].redcoinShow=false;
			   }
				red[i].redcoin_x =  screenWidth;
		        red[i].redcoin_y = rand() % (screenHeight-100);
		        red[i].redcoinIndex = rand() % 10;
		        red[i].redcoinShow = true;
		        rcoinscore=rcoinscore+15;
		   }
	}
}
/*___________________________________COPTER COLLISION WITH BIRD LEVEL 1________________________________*/
void collisioncheck4()
{
	for(int i=0;i< bird1Number; i++)
    {
	if(copter_x+190>=enemy[i].bird1_x&&copter_x<=enemy[i].bird1_x+99 && copter_y+150>=enemy[i].bird1_y&&copter_y<=enemy[i].bird1_y+99)
		 {
			if(enemy[i].bird1Show && life[col].lifeShow==true)	
				{life[col].lifeShow=false;
			
					col++;
			 
			enemy[i].bird1Show = false;
			collision=true; //for blast
			enemy[i].bird1_x = screenWidth;
			enemy[i].bird1_y = rand()% 600;
			enemy[i].bird1Index = rand() % 17;
			enemy[i].bird1Show = true;            
         }
         }
     }
   
}
/*___________________________________COPTER COLLISION WITH SQUARE________________________________*/
void L2collisioncheck1()
{
	for(int i=0;i<squareNumber;i++)
	{
		if(copter_x+190>=square[i].square_x && copter_x<=square[i].square_x +49 && copter_y+150>square[i].square_y &&  copter_y<square[i].square_y+50)
			{
				square[i].squareShow=false;
				square[i].square_x = rand() % screenWidth;
		        square[i].square_y = rand() % (screenHeight-300);
		        square[i].squareIndex = rand() % 12;
		        square[i].squareShow = true;
		        squarescore=squarescore+10;

			}
	}
}
/*___________________________________COPTER COLLISION WITH HEART________________________________*/
void L2collisioncheck2()
{
	for(int i=0;i<heartNumber;i++)
	{
		if(copter_x+190>=heart[i].heart_x && copter_x<=heart[i].heart_x+50&& copter_y+150>heart[i].heart_y&&copter_y<heart[i].heart_y+50)
			{
				heart[i].heartShow=false;
				heart[i].heart_x = rand() % screenWidth;
		        heart[i].heart_y = rand() % 200;
		        heart[i].heartIndex = rand() % 12;
		        heart[i].heartShow = true;
		        heartscore=heartscore+5;
			}
	}
}
/*___________________________________COPTER COLLISION WITH DIAMOND________________________________*/
void L2collisioncheck3()
{
	for(int i=0;i<diamondNumber;i++)
	{
		if(copter_x+190>=diamond[i].diamond_x && copter_x<=diamond[i].diamond_x+50 && copter_y+150>diamond[i].diamond_y && copter_y<diamond[i].diamond_y+50)
		   {

			    diamond[i].diamondShow=false;
				diamond[i].diamond_x =  screenWidth;
		        diamond[i].diamond_y = rand() % (screenHeight-100);
		        diamond[i].diamondIndex = rand() % 12;
		        diamond[i].diamondShow = true;
		        diamondscore=diamondscore+15;
		   }
	}
}
/*___________________________________COPTER COLLISION WITH BIRD LEVEL 2________________________________*/
void L2collisioncheck4()
{
	for(int i=0;i< bird2Number; i++)
    {
	if(copter_x+190>=enemy2[i].bird2_x&&copter_x<=enemy2[i].bird2_x+99 && copter_y+150>=enemy2[i].bird2_y&&copter_y<=enemy2[i].bird2_y+99)
		 {
			if(enemy2[i].bird2Show && life[col].lifeShow==true )	
			 {life[col].lifeShow=false;col++;
			 
			 enemy2[i].bird2Show = false;
			collision2=true;
				enemy2[i].bird2_x = screenWidth;
		enemy2[i].bird2_y = rand()% 600;
		enemy2[i].bird2Index = rand() % 17;
		enemy2[i].bird2Show = true; 
         }
     }
   }
}
/*___________________________________FIRE COLLISION WITH BIRD LEVEL 1________________________________*/
void firecollision()
{
	for(int i=0;i< bird1Number; i++)
	{
		if( fire1[i].fire_x+100>=enemy[i].bird1_x&&fire1[i].fire_x<=enemy[i].bird1_x+110 && fire1[i].fire_y+50>enemy[i].bird1_y&&fire1[i].fire_y<=enemy[i].bird1_y+99)
			if(enemy[i].bird1Show){
			enemy[i].bird1Show = false;
		enemy[i].bird1_x = screenWidth;
		enemy[i].bird1_y = rand()% 600;
		enemy[i].bird1Index = rand() % 17;
		enemy[i].bird1Show = true;}
	}
}
/*___________________________________FIRE COLLISION WITH BIRD LEVEL 2________________________________*/
void firecollision2()
{
	for(int i=0;i< bird1Number; i++)
	{
		if( fire2[i].fire_x+100>=enemy2[i].bird2_x&&fire2[i].fire_x<=enemy2[i].bird2_x+110 && fire2[i].fire_y+50>enemy2[i].bird2_y&&fire2[i].fire_y<=enemy2[i].bird2_y+99)
			if(enemy2[i].bird2Show){
			enemy2[i].bird2Show = false;
		enemy2[i].bird2_x = screenWidth;
		enemy2[i].bird2_y = rand()% 600;
		enemy2[i].bird2Index = rand() % 17;
		enemy2[i].bird2Show = true;}
	}	
    }
/*_________________________________________BLAST SHOW FUNCTION_______________________________________*/
void showBlast(){
for(int i=0;i<booms;i++)
  {
	if(boom[i].blastShow)
	{
		iShowBMP2(boom[i].blast_x,boom[i].blast_y,blasts[i],0);
	}
  }
}

/*_________________________________________LIFE SHOW FUNCTION_______________________________________*/
void lifepic(){
	for(int i=0;i<lifeNum;i++)
	{ if(life[i].lifeShow)
	   {
		   iShowBMP2(life[i].life_x,life[i].life_y,lifes[i],0);
	   }
	}
}
/*____________________________________________RED COIN MOVEMENT______________________________________*/
void rcoinsMovement() ///for animation
{
	for (int i = 0; i < rcoinsNumber; i++)
	{
		if (red[i].redcoinShow)
		{
			iShowBMP2(red[i].redcoin_x, red[i].redcoin_y, redCoin[red[i].redcoinIndex], 0);
		}
	}
}
/*____________________________________________SILVER COIN MOVEMENT____________________________________*/
void scoinsMovement()
{
	for (int i = 0; i < scoinsNumber; i++)
	{
		if (silver[i].silvercoinShow)
		{
			iShowBMP2(silver[i].silvercoin_x, silver[i].silvercoin_y, silverCoin[silver[i].silvercoinIndex], 0);
		}
	}
}
/*___________________________________________GOLD COIN MOVEMENT______________________________________*/
void gcoinsMovement()
{
	for (int i = 0; i < gcoinsNumber; i++)
	{
		if (gold[i].goldcoinShow)
		{
			iShowBMP2(gold[i].goldcoin_x, gold[i].goldcoin_y, goldCoin[gold[i].goldcoinIndex], 0);
		}
	}
}
/*_________________________________________LEVEL 1 BIRD MOVEMENT_____________________________________*/
void bird1Movement()
{
	for (int i = 0; i < bird1Number; i++)
	{
		if (enemy[i].bird1Show)
		{
			iShowBMP2(enemy[i].bird1_x, enemy[i].bird1_y, bird1Images[enemy[i].bird1Index], 0);
		}
	}
}
/*____________________________________________DIAMOND MOVEMENT______________________________________*/
void diamondMovement()
{
	for (int i = 0; i < diamondNumber; i++)
	{
		if (diamond[i].diamondShow)
		{
			iShowBMP2(diamond[i].diamond_x,diamond[i].diamond_y, Diamond[diamond[i].diamondIndex], 0);
		}
	}
}
/*____________________________________________SQUARE MOVEMENT____________________________________*/
void squareMovement()
{
	for (int i = 0; i < squareNumber; i++)
	{
		if (square[i].squareShow)
		{
			iShowBMP2(square[i].square_x, square[i].square_y, Square[square[i].squareIndex], 0);
		}
	}
}
/*___________________________________________HEART MOVEMENT______________________________________*/
void heartMovement()
{
	for (int i = 0; i < heartNumber; i++)
	{
		if (heart[i].heartShow)
		{
			iShowBMP2(heart[i].heart_x, heart[i].heart_y, Heart[heart[i].heartIndex], 0);
		}
	}
}
/*_________________________________________BLAST 2 SHOW FUNCTION_______________________________________*/

void show2Blast(){
for(int i=0;i<booms2;i++)
  {
	if(boom2[i].blast2Show)
	{
		iShowBMP2(boom2[i].blast2_x,boom2[i].blast2_y,blasts[i],0);
	}
  }
}       
/*_________________________________________LEVEL 2 BIRD MOVEMENT_____________________________________*/
void bird2Movement()
{
	for (int i = 0; i < bird2Number; i++)
	{
		if (enemy2[i].bird2Show)
		{
			iShowBMP2(enemy2[i].bird2_x, enemy2[i].bird2_y, bird2Images[enemy2[i].bird2Index],0);
		}
	}
}
/*___________________________________________LEVEL 1 FIRE MOVEMENT___________________________________*/
void fireMovement()
{
	for (int i = 0; i < fireNumber; i++)
	{
		if (fire1[i].fireShow)
		{
			iShowBMP2(fire1[i].fire_x, fire1[i].fire_y, fireimg[fire1[i].fireIndex], 0);
		}
	}
}
/*___________________________________________LEVEL 2 FIRE MOVEMENT___________________________________*/
void fireMovement2()
{
	for (int i = 0; i < fireNumber; i++)
	{
		if (fire2[i].fireShow)
		{
			iShowBMP2(fire2[i].fire_x, fire2[i].fire_y, fireimg[fire2[i].fireIndex], 0);
		}
	}
}
/*___________________________________________iDRAW FUNCTION______________________________________*/
void iDraw()
{
	iClear();
/*______________________________________GAME STATE -1 FOR MENU PAGE___________________________________*/
	if (gamestate == -1)
	{
		if (call == 1)
		{	
			PlaySound("music\\menu_new.wav", NULL, SND_LOOP | SND_ASYNC);
			call = 0;
		}
		
		iShowBMP(0, 0, homemenu);
		for (int i = 0; i < 5; i++)
		{
			iShowBMP2(bCo[i].x, bCo[i].y, button[i], 0);
		}
		
		drawTextBox();
	    if(mode == 1)
	      {
		    iText(65, 380, str, GLUT_BITMAP_TIMES_ROMAN_24);
	      }
	    iText(500, 695, "Click to activate the box, enter to finish.",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(500, 720, "Press enter to finish & minus(-) to delete",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(500, 745, "Enter Your Name : (Max 10 Characters)", GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
/*______________________________________GAME STATE 0 FOR PLAY PAGE___________________________________*/
	else if (gamestate == 0)
	{
		iShowBMP(0,0,homemenu);
		iShowBMP2(500, 350,"menu\\easy.bmp", 0);
		iShowBMP2(500, 280, "menu\\hard.bmp", 0);
		iShowBMP2(1255,710, "arrow1.bmp", 0);
		
	if (mod == 0)
	{
		
		if (call2 == 1)
		{	
			PlaySound("music\\demon.wav", NULL, SND_LOOP | SND_ASYNC);
			call2 = 0;
		}
		
		iSetColor(r, g, b);

		iShowImage(upperBG_x, upperBg_y, 1360, 768, bgImg);
		iShowImage(upperBG_x1, upperBg_y1, 1360, 768, bgImg2);
		iShowImage(lowerBG_x, lowerBg_y, 1360, 768, bgImg3);
		iShowImage(lowerBG_x1, lowerBg_y1, 1360, 768, bgImg4);

        iShowBMP2(copter_x, copter_y, copter[copterIndex], 0);
		
		if(copter_x<=0)
		{
			copter_x=0;
			gotoLeft=false;
		}	
		if(copter_x + copterwidth >= screenWidth)
		{
			 copter_x = screenWidth-copterwidth;
			 gotoRight = false;
		}	
		if(copter_y<=0)
		{
			copter_y=0;
			gotoBottom=false;
		}
		if(copter_y + copterHeight >= screenHeight)
		{
			 copter_y = screenHeight-copterHeight;
			 gotoTop = false;
		}		
		iShowBMP2(1120, 720, "resume_n.bmp", 0);
		iShowBMP2(1160, 720, "pause_n.bmp", 0);
		iShowBMP2(1200, 715, "re.bmp", 0);
		iShowBMP2(1255,710, "arrow1.bmp", 0);
		iText(10,735, "Life", GLUT_BITMAP_TIMES_ROMAN_24);

		if(collision==true){
			

		 showBlast();
		 collision=false;
		}

		lifepic();
		bird1Movement();
        rcoinsMovement();
		gcoinsMovement();
		scoinsMovement();
		fireMovement();

		collisioncheck1();
		collisioncheck2();
		collisioncheck3();
		collisioncheck4();
		firecollision();
	if(col==3)
	  { 
		  gameover=true;
		 
	  }
	if(gameover==true)
	  {
		 if(call3==1){
				PlaySound("music\\gameover.wav", NULL,  SND_ASYNC);
				call3=0;
		  }
		    if(flag==1){
		totalscore=rcoinscore+scoinscore+gcoinscore;
		flag=0;
			}
	
		  	iPauseTimer(0);
			
		

		 iShowBMP(0, 0, "menu\\gameover.bmp");
		iShowBMP2(1255,710, "arrow1.bmp", 0);

	   storescore();
		
	  }

	}
	else if (mod == 1)
	{
	if (call2 == 1)
		{	
			PlaySound("music\\demon.wav", NULL, SND_LOOP | SND_ASYNC);
			call2 = 0;
		}
		
		iSetColor(r, g, b);

		iShowImage(L2upperBG_x, L2upperBg_y, 1360, 768, bgImg5);
		iShowImage(L2upperBG_x1, L2upperBg_y1, 1360, 768, bgImg6);
		iShowImage(L2lowerBG_x, L2lowerBg_y, 1360, 768, bgImg7);
		iShowImage(L2lowerBG_x1, L2lowerBg_y1, 1360, 768, bgImg8);

        iShowBMP2(copter_x, copter_y, copter[copterIndex], 0);
		
		if(copter_x<=0)
		{
			copter_x=0;
			gotoLeft=false;
		}	
		if(copter_x + copterwidth >= screenWidth)
		{
			 copter_x = screenWidth-copterwidth;
			 gotoRight = false;
		}	
		if(copter_y<=0)
		{
			copter_y=0;
			gotoBottom=false;
		}
		if(copter_y + copterHeight >= screenHeight)
		{
			 copter_y = screenHeight-copterHeight;
			 gotoTop = false;
		}		
		iShowBMP2(1120, 720, "resume_n.bmp", 0);
		iShowBMP2(1160, 720, "pause_n.bmp", 0);
		iShowBMP2(1200, 715, "re.bmp", 0);
		iShowBMP2(1255,710, "arrow1.bmp", 0);
		iText(10,735, "Life", GLUT_BITMAP_TIMES_ROMAN_24);

		if(collision2==true){

		 show2Blast();
		 collision2=false;
		}
		lifepic();
		bird2Movement();
        diamondMovement();
		squareMovement();
		heartMovement();
		fireMovement2();

		L2collisioncheck1();
		L2collisioncheck2();
		L2collisioncheck3();
		L2collisioncheck4();
		firecollision2();

			
	if(col==3)
	  { 
		  gameover=true;
		  
		 
	  }
	if(gameover==true)
	  {
		  if(call3==1){
				PlaySound("music\\gameover.wav", NULL,  SND_ASYNC);
				call3=0;
		  }
			
		    if(flag==1)
			{
		totalscore=diamondscore+squarescore+heartscore;
		flag=0;
			}
				
			
		  	iPauseTimer(0);

		 iShowBMP(0, 0, "menu\\gameover.bmp");
		iShowBMP2(1255,710, "arrow1.bmp", 0);
		
	   storescore();
		
	  }
	
	}
	}
	
			
	
  
/*______________________________________GAME STATE 1 FOR SCORE PAGE___________________________________*/
	else if (gamestate == 1)
	{
		iShowBMP(0, 0, "menu\\score_img.bmp");
		iShowBMP2(10, 668, "arrow.bmp", 0);
		iText(500,400,"NAME",GLUT_BITMAP_TIMES_ROMAN_24);
	 	iText(800,400,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		
		showscore();
	}
/*__________________________________GAME STATE 2 FOR INSTRUCTION PAG_________________________________*/
	else if (gamestate == 2)
	{
		iShowBMP(0,0, "menu\\instruction_img.bmp");
		iShowBMP2(10, 668, "arrow.bmp", 0);
	}
/*______________________________________GAME STATE 3 FOR ABOUT PAGE__________________________________*/
	else if (gamestate == 3)
	{
        iShowBMP(0,0, "menu\\about_us.bmp");
		iShowBMP2(10, 668, "arrow.bmp", 0);
	}
/*______________________________________GAME STATE 4 FOR QUIT PAGE___________________________________*/
	else if (gamestate == 4)
	{
       exit(0);
		
	}
}

void iPassiveMouse(int x, int y)
{
}
void iMouseMove(int mx, int my)
{
}
/*_________________________________iMOUSE FOR CONTROLLING ALL BUTTON_________________________________*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 5; i++)
		{
			if (mx >= bCo[i].x && mx <= bCo[i].x + 220 && my >= bCo[i].y && my <= bCo[i].y + 60)
				gamestate = i;
		}
	}
/*___________________________________CLICK NAME INPUT BOX TO ACTIVATE________________________________*/
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx >= 50 && mx <= 270 && my >= 360 && my <= 410 &&  mode == 0)
		{
			mode = 1;
		}
	}
/*_____________________________________USE RETURN FROM PLAY TO MENU_________________________________*/	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0)
		{
			if (mx >= 1255 && mx <= 1353 && my >= 710 && my <=757)
				{
					gamestate = -1;
				  call=1;
					mod = -1;
					
			    }
		}
	}
/*________________________________________PAUSE BUTTON IN PLAY PAGE_________________________________*/	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0)
		{
			if (mx >= 1160 && mx <= 1195 && my >= 720 && my <= 755)
				iPauseTimer(0);
			
		}
	}
/*_____________________________________RESUME BUTTON IN PLAY PAGE___________________________________*/
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		   if (gamestate == 0)
		    {
			   if (mx >= 1120 && mx <= 1155 && my >= 720 && my <= 755)
				 { 
				    iResumeTimer(0);
			        call2=1;

				 }
		    }
	}
/*_____________________________________USE RETURN FROM SCORE TO MENU_________________________________*/
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 1)
		{
			if (mx >= 10 && mx <= 150 && my >= 668 && my <= 668 + 97)
				gamestate = -1;
		}
	}

/*_________________________________USE RETURN FROM INSTRUCTION TO MENU_______________________________*/
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 2)
		{
			if (mx >= 10 && mx <= 150 && my >= 668 && my <= 668 + 97)
				gamestate = -1;
		}
	}
/*_____________________________________USE RETURN FROM ABOUT TO MENU_________________________________*/
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 3)
		{
			if (mx >= 10 && mx <= 150 && my >= 668 && my <= 668 + 97)
				gamestate = -1;
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0)
		{
			if (mx >= 500 && mx <= 720 && my >= 350 && my <= 400)
				mod = 0;
				}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0)
		{
			if (mx >= 500 && mx <= 720 && my >= 280 && my <= 330)
				mod = 1;
		}
	}
}

void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str3, str);
			printf("%s\n", str3);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else if(key == '-')
			{
				if(len != 0)
				{
					str[len - 1] = '\0';
					len--;
				}
		}
				else
		{
			str[len] = key;
			len++;
		}
	
	}
}
void iSpecialKeyboard(unsigned char key)
{
	int n=-25, m=25;
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if(key == GLUT_KEY_UP)
	{
		gotoTop=true;
		gotoBottom=false;
		gotoRight=false;
		gotoLeft=false;
		copter_y+=25;
		fireMovement();
		
	}
	else if(key==GLUT_KEY_DOWN)
	{
		gotoTop=false;
		gotoBottom=true;
		gotoRight=false;
		gotoLeft=false;
		copter_y-=25;
		fireMovement();
	
	}
	else if(key==GLUT_KEY_RIGHT)
	{
		copter_x+=10;
		gotoRight=true;
		gotoLeft=false;
		gotoTop=false;
		gotoBottom=false;
	}
	else if(key==GLUT_KEY_LEFT)
	{
		copter_x-=10;
		gotoRight=false;
		gotoLeft=true;
		gotoTop=false;
		gotoBottom=false;
	}
}
void change()
{
/*__________________________________________RED COIN LOOP____________________________________________*/	
	for (int i = 0; i < rcoinsNumber; i++)
	{
		red[i].redcoin_x -= 25;

		if (red[i].redcoin_x <= 0)
		{
			red[i].redcoin_x = (screenWidth + 10);
			red[i].redcoin_y = rand() % (screenHeight - 100);
		}
		red[i].redcoinIndex++;

		if (red[i].redcoinIndex >= 10)
		{
			red[i].redcoinIndex = 0;
		}
	}
/*_________________________________________SILVER COIN LOOP__________________________________________*/	
	for (int i = 0; i < scoinsNumber; i++)
	{
		silver[i].silvercoin_x -= 20;

		if (silver[i].silvercoin_x <= 0)
		{
			silver[i].silvercoin_x = screenWidth + 14;
			silver[i].silvercoin_y = rand() % (screenHeight - 100);
		}
		silver[i].silvercoinIndex++;

		if (silver[i].silvercoinIndex >= 10)
		{
			silver[i].silvercoinIndex = 0;
		}
	}
/*____________________________________________GOLD COIN LOOP_________________________________________*/	
	for (int i = 0; i < gcoinsNumber; i++)
	{
		gold[i].goldcoin_x -= 15;

		if (gold[i].goldcoin_x <= 0)
		{
			gold[i].goldcoin_x = screenWidth + 20;
			gold[i].goldcoin_y = rand() % (screenHeight - 100);
		}
		gold[i].goldcoinIndex++;

		if (gold[i].goldcoinIndex >= 10)
		{
			gold[i].goldcoinIndex = 0;
		}
	}
/*_______________________________________________BIRD LOOP____________________________________________*/	
	for (int i = 0; i < bird1Number; i++)
	{
		enemy[i].bird1_x -= 15;

		if (enemy[i].bird1_x <= 0)
		{
			enemy[i].bird1_x = screenWidth + 5;
			enemy[i].bird1_y = rand() % (screenHeight-100);
		}
		enemy[i].bird1Index++;

		if (enemy[i].bird1Index >= 17)
		{
			enemy[i].bird1Index = 0;
		}
	}
	
/*______________________________________________FIRE LOOP____________________________________________*/	
	for (int i = 0; i < fireNumber; i++)
	{
		fire1[i].fire_x += 30;  //speed alter

		if (fire1[i].fire_x >= screenWidth)
		{
			fire1[i].fire_x = 190 + copter_x ;
			fire1[i].fire_y = 70 + copter_y ;//
			
		}
		fire1[i].fireIndex++;

		if (fire1[i].fireIndex >= 3)
		{
			fire1[i].fireIndex = 0;
		}
	}
/*__________________________________________BACKGROUND CHANGE____________________________________________*/		
		if(upperBG_x >=-1360) upperBG_x -= upperBGspeed;
		if(upperBG_x <=-1360) upperBG_x = 1360;
		if(upperBG_x1 >=-1360) upperBG_x1 -= upperBGspeed;
		if(upperBG_x1 <=-1360) upperBG_x1 = 1360;

		if(lowerBG_x >=-1360) lowerBG_x -= lowerBGspeed;
		if(lowerBG_x <=-1360) lowerBG_x = 1360;
		if(lowerBG_x1 >=-1360) lowerBG_x1 -= lowerBGspeed;
		if(lowerBG_x1 <=-1360) lowerBG_x1 = 1360;
	
	    copterIndex++;
	    if (copterIndex >= 4)
		copterIndex = 0;	
}
void L2change()
{
/*__________________________________________DIAMOND LOOP____________________________________________*/	
	for (int i = 0; i < diamondNumber; i++)
	{
		diamond[i].diamond_x -= 35;

		if (diamond[i].diamond_x <= 0)
		{
			diamond[i].diamond_x = (screenWidth + 10);
			diamond[i].diamond_y = rand() % (screenHeight - 100);
		}
		diamond[i].diamondIndex++;

		if (diamond[i].diamondIndex >= 12)
		{
			diamond[i].diamondIndex = 0;
		}
	}
/*_________________________________________SQUARE LOOP__________________________________________*/	
	for (int i = 0; i < squareNumber; i++)
	{
		square[i].square_x -= 25;

		if (square[i].square_x <= 0)
		{
			square[i].square_x = screenWidth + 14;
			square[i].square_y = rand() % (screenHeight - 100);
		}
		square[i].squareIndex++;

		if (square[i].squareIndex >= 12)
		{
			square[i].squareIndex = 0;
		}
	}
/*____________________________________________HEART LOOP_________________________________________*/	
	for (int i = 0; i < heartNumber; i++)
	{
		heart[i].heart_x -= 25;

		if (heart[i].heart_x <= 0)
		{
			heart[i].heart_x = screenWidth + 20;
			heart[i].heart_y = rand() % (screenHeight - 100);
		}
		heart[i].heartIndex++;

		if (heart[i].heartIndex >= 12)
		{
			heart[i].heartIndex = 0;
		}
	}
/*_______________________________________________BIRD LOOP level 2____________________________________________*/	
	for (int i = 0; i < bird2Number; i++)
	{
		enemy2[i].bird2_x -= 25;

		if (enemy2[i].bird2_x <= 0)
		{
			enemy2[i].bird2_x = screenWidth + 5;
			enemy2[i].bird2_y = rand() % (screenHeight-100);
		}
		enemy2[i].bird2Index++;

		if (enemy2[i].bird2Index >= 10)
		{
			enemy2[i].bird2Index = 0;
		}
	}
/*______________________________________________FIRE LOOP____________________________________________*/	
	for (int i = 0; i < fireNumber; i++)
	{
		fire2[i].fire_x += 30;  //speed alter

		if (fire2[i].fire_x >= screenWidth)
		{
			fire2[i].fire_x = 190 + copter_x ;
			fire2[i].fire_y = 70 + copter_y ;//
			
		}
		fire2[i].fireIndex++;

		if (fire2[i].fireIndex >= 3)
		{
			fire2[i].fireIndex = 0;
		}
	}
/*__________________________________________BACKGROUND CHANGE____________________________________________*/		
		if(L2upperBG_x >=-1360) 
			L2upperBG_x -= upperBGspeed2;
		if(L2upperBG_x <=-1360) 
			L2upperBG_x = 1360;
		if(L2upperBG_x1 >=-1360) 
			L2upperBG_x1 -= upperBGspeed2;
		if(L2upperBG_x1 <=-1360) 
			L2upperBG_x1 = 1360;

		if(L2lowerBG_x >=-1360) L2lowerBG_x -= lowerBGspeed2;
		if(L2lowerBG_x <=-1360) L2lowerBG_x = 1360;
		if(L2lowerBG_x1 >=-1360) L2lowerBG_x1 -= lowerBGspeed2;
		if(L2lowerBG_x1 <=-1360) L2lowerBG_x1 = 1360;
	
	    copterIndex++;
	    if (copterIndex >= 4)
		copterIndex = 0;	
}
/*________________________________________BLAST1  VARIABLES______________________________________*/	

void blastOn(){
	
for(int i=0;i<booms;i++)
{
boom[i].blast_x=copter_x+400;	
boom[i].blast_y=copter_y+300;	
boom[i].blastIndex=rand() %3;	
boom[i].blastShow=true;	
}
}

/*________________________________________SET RED COIN VARIABLES______________________________________*/	
void rsetcoinsVariables()
{
	for (int i = 0; i < rcoinsNumber; i++)
	{
		red[i].redcoin_x = rand() % screenWidth;
		red[i].redcoin_y = rand() % 100;
		red[i].redcoinIndex = rand() % 10;
		red[i].redcoinShow = true;
	}
}
/*______________________________________SET SILVER COIN VARIABLES___________________________________*/
void ssetcoinsVariables()
{
	for (int i = 0; i < scoinsNumber; i++)
	{
		silver[i].silvercoin_x = rand() % screenWidth;
		silver[i].silvercoin_y = rand() % 200;
		silver[i].silvercoinIndex = rand() % 10;
		silver[i].silvercoinShow = true;
	}
}
/*_____________________________________SET GOLD COIN VARIABLES______________________________________*/
void gsetcoinsVariables()
{
	for (int i = 0; i < gcoinsNumber; i++)
	{
		gold[i].goldcoin_x = rand() % screenWidth;
		gold[i].goldcoin_y = rand() % 300;
		gold[i].goldcoinIndex = rand() % 10;
		gold[i].goldcoinShow = true;
	}
}
/*______________________________________SET LEVEL 1 BIRD VARIABLES___________________________________*/
void setbird1Variables()
{
	for (int i = 0; i < bird1Number; i++)
	{
		enemy[i].bird1_x = screenWidth;
		enemy[i].bird1_y = rand()% 600;
		enemy[i].bird1Index = rand() % 17;
		enemy[i].bird1Show = true;
	}
}
/*________________________________________SET DIAMONDS VARIABLES______________________________________*/	
void setDiamondVariables()
{
	for (int i = 0; i < diamondNumber; i++)
	{
		diamond[i].diamond_x = rand() % screenWidth;
		diamond[i].diamond_y = rand() % 100;
		diamond[i].diamondIndex = rand() % 12;
		diamond[i].diamondShow = true;
	}
}
/*______________________________________SET SQUARE VARIABLES___________________________________*/
void setSquareVariables()
{
	for (int i = 0; i < squareNumber; i++)
	{
		square[i].square_x = rand() % screenWidth;
		square[i].square_y = rand() % 200;
		square[i].squareIndex = rand() % 12;
		square[i].squareShow = true;
	}
}
/*_____________________________________SET HEART VARIABLES______________________________________*/
void setHeartVariables()
{
	for (int i = 0; i < heartNumber; i++)
	{
		heart[i].heart_x = rand() % screenWidth;
		heart[i].heart_y = rand() % 300;
		heart[i].heartIndex = rand() % 12;
		heart[i].heartShow = true;
	}
}
/*_____________________________________BLAST2 VARIABLES______________________________________*/
void blast2On(){
	
for(int i=0;i<booms2;i++)
{
boom2[i].blast2_x=copter_x+400;	
boom2[i].blast2_y=copter_y+300;	
boom2[i].blast2Index=rand() %3;	
boom2[i].blast2Show=true;	
}
}

/*______________________________________SET LEVEL 2 BIRD VARIABLES___________________________________*/
void setbird2Variables()
{
	for (int i = 0; i < bird2Number; i++)
	{
		enemy2[i].bird2_x =screenWidth;
		enemy2[i].bird2_y = (rand()% screenHeight)+300;
		enemy2[i].bird2Index = rand() % 10;
		enemy2[i].bird2Show = true;
	
		
	}
}
/*_____________________________________SET LEVEL 1 FIRE  VARIABLES____________________________________*/
void setfireVariables()
{
	for (int i = 0; i < fireNumber; i++)
	{
		fire1[i].fire_x = copter_x +190;
		fire1[i].fire_y = copter_y+ 150;
		fire1[i].fireIndex = 0;
		fire1[i].fireShow = true;
	}
}
/*_____________________________________SET LEVEL 2 FIRE  VARIABLES____________________________________*/
void setfireVariables2()
{
	for (int i = 0; i < fireNumber; i++)
	{
		fire2[i].fire_x = copter_x +190;
		fire2[i].fire_y = copter_y+ 150;
		fire2[i].fireIndex = 0;
		fire2[i].fireShow = true;
	}
}
/*______________________________________SET BACKGROUND VARIABLES____________________________________*/
void setBackgroundVariables()
{ 	
	    upperBg_y= 0;
		upperBG_x= 0;
		upperBg_y1= 0;
		upperBG_x1= 1360;
		lowerBg_y= 0;
		lowerBG_x= 0;
		lowerBg_y1= 0;
		lowerBG_x1= 1360;
}
/*______________________________________SET BACKGROUND VARIABLES level 2____________________________________*/
void setBackgroundVariables2()
{ 	
	    L2upperBg_y= 0;
		L2upperBG_x= 0;
		L2upperBg_y1= 0;
		L2upperBG_x1= 1360;
		L2lowerBg_y= 0;
		L2lowerBG_x= 0;
		L2lowerBg_y1= 0;
		L2lowerBG_x1= 1360;
}
/*________________________________________SET LIFE VARIABLES______________________________________*/
void lifeAll()
{
	for(int i=0;i<lifeNum;i++)
	{
	  life[i].life_x=220-(i*75);
	  life[i].life_y=725;
	  life[i].lifeShow=true;
	}
}
void showscore(){
	FILE *fp= fopen("score.txt","r");
	if(fp!=NULL)
	{
	while(fscanf(fp, "%s\t%s", &str3, &str1) != EOF)
	{
		iText(500,350,str1,GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(800,350,str3,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	}
	fclose(fp);
	


}

/*________________________________________STORE SCORE IN FILE______________________________________*/
void storescore()
{
	FILE *fp=fopen("score.txt","w");
	if(fp!=NULL)
	{
		fprintf(fp,"%d ",totalscore);
		fprintf(fp,"%s ",str3);
		iShowBMP2(30,500,"ishow.bmp",0);
		iText(90,680,"HI!",GLUT_BITMAP_TIMES_ROMAN_24);
		
		iText(130,680,str3,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(90,630,"YOUR SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
		 sprintf(str1,"%d",totalscore);
		 iText(130,580,str1,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	fclose(fp);
}
void Lstorescore()
{
	FILE *fp=fopen("score.txt","w");
	if(fp!=NULL)
	{
		fprintf(fp,"%d ",totalscore);
		fprintf(fp,"%s ",str3);
		iShowBMP2(30,500,"ishow.bmp",0);
		iText(90,680,"HI!",GLUT_BITMAP_TIMES_ROMAN_24);
		
		iText(130,680,str3,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(90,630,"YOUR SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
		 sprintf(str1,"%d",totalscore);
		 iText(130,580,str1,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	fclose(fp);
}

int main()
{
	setBackgroundVariables();
	setbird1Variables();
	rsetcoinsVariables();
	ssetcoinsVariables();
	gsetcoinsVariables();
	blastOn();
	///////////////////level 2 //////////////
	setBackgroundVariables2();
	setbird2Variables();
	setDiamondVariables();
	setSquareVariables();
	setHeartVariables();
	setfireVariables();
	setfireVariables2();
	lifeAll();
	blast2On();
	
	len = 0;
	mode = 0;
	str[0]= 0;

	iSetTimer(25, change);
	iSetTimer(20, L2change);
	
	iInitialize(screenWidth, screenHeight, "Air Rush");
	bgImg = iLoadImage("level1bg\\upperBG.jpg");
	bgImg2 = iLoadImage("level1bg\\upperBG.jpg");
	bgImg3 = iLoadImage("level1bg\\lowerBG.png");
	bgImg4 = iLoadImage("level1bg\\lowerBG2.png");
	bgImg5 = iLoadImage("level1bg\\L2upperBG.jpg");
	bgImg6 = iLoadImage("level1bg\\L2upperBG2.jpg");
	bgImg7 = iLoadImage("level1bg\\lowerBG.png");
	bgImg8 = iLoadImage("level1bg\\lowerBG2.png");
/*_______________________________________BUTTON SEQUENCE______________________________________*/
	int sum = 60;
	for (int i = 4; i >= 0; i--)
	{
		bCo[i].x = 50;
		bCo[i].y = sum;
		sum += 60;
}	
    iStart();
	return 0;
}
