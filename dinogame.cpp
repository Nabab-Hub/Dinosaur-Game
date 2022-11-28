#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
void dino(int);   //body of dinosaur
void tree(int);   //body of tree
void cactus(int,int);  //body of cactus
int gameOver(void);    //game over logic
void score(void);      //count score
int structure[]={85,320,85,295,90,290,125,290,130,295,130,310,110,310,125,
310,125,318,106,318,106,330,118,330,118,340,110,340,110,335,110,350,105,350,
105,360,105,359,100,359,100,365,95,365,95,385,100,385,102,392,88,392,88,375,
83,375,83,370,80,370,80,375,75,375,75,380,70,380,70,385,78,385,78,392,62,392
,62,370,57,370,57,365,52,365,52,360,47,360,47,355,42,355,42,350,37,350,37,315
,45,315,45,330,50,330,50,335,55,335,55,340,65,340,65,335,65,335,70,335,70,330
,75,330,75,325,80,325,80,320,85,320}; //structure of dino using polygon
int structureJump[]={85,320,85,295,90,290,125,290,130,295,130,310,110,310,125,
310,125,318,106,318,106,330,118,330,118,340,110,340,110,335,110,350,105,350,
105,360,105,359,100,359,100,365,95,365,95,385,100,385,102,392,88,392,88,375,
83,375,83,370,80,370,80,375,75,375,75,380,70,380,70,385,78,385,78,392,62,392
,62,370,57,370,57,365,52,365,52,360,47,360,47,355,42,355,42,350,37,350,37,315
,45,315,45,330,50,330,50,335,55,335,55,340,65,340,65,335,65,335,70,335,70,330
,75,330,75,325,80,325,80,320,85,320};
int tree1[]={670,395,670,375,690,375,675,350,685,350,670,335,665,330,660,335,645,350,655,350,640,375,660,375,660,395,670,395};
int draw[]={490,395,490,365,510,365,510,360,515,360,515,355,515,325,510
     ,325,510,320,505,320,505,325,500,325,500,350,490,350,490,310,485,310,485
     ,305,480,305,480,310,475,310,475,330,465,330,465,300,460,300,460,295,455
     ,295,455,300,450,300,450,340,460,340,460,345,475,345,475,395,490,395};
int i,j,k,moveTree=10;
int eye=300;
char choice;
int shift=680,move=1;
int over=0;
int point=0;
char str[20];
void main()
{
    int gd=0,gm;
    int fLeg=0,sLeg=0;
    int i=0,j,up=125,start=1;
    char choose;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setbkcolor(8);
    first:
    cleardevice();
    setfillstyle(1,14);
    bar(200,100,400,250);
    setfillstyle(1,4);
    bar(250,up,350,up+50);
    settextstyle(0,0,2);
    setcolor(GREEN);
    outtextxy(260,140,"START");
    outtextxy(270,200,"HELP");
    while(1)           //dialogue box of start and help
    {
	  choose=getch();
	  switch(choose)
	  {
	     case 'U':up=125;start=1;break;
	     case 'D':up=175;start=0;break;
	     case 'E':goto bye;break;
	     case 'O':if(start==1)
		      goto START;
		      else if(start==0)
		      goto help; break;
	     default:break;
	  }
	  cleardevice();
	  setfillstyle(1,14);
	  bar(200,100,400,250);
	  setfillstyle(1,4);
	  bar(250,up,350,up+50);
	  settextstyle(0,0,2);
	  setcolor(GREEN);
	  outtextxy(260,140,"START");
	  outtextxy(270,190,"HELP");
    }

    START:
    cleardevice();
    
   while(1)       //Game start
    {
     score();
      over=gameOver();
      if(over==1)
      goto out;
    switch(move)
    {
       case 1:tree(0);break;
       case 2:cactus(shift,0);shift-=20;break;
       case 3:cactus(shift,1);shift-=20;break;
       default:break;
    }
    structure[65]=380-sLeg;
    structure[67]=380-sLeg;
    structure[69]=385-sLeg;
    structure[71]=385-sLeg;
    structure[73]=392-sLeg;
    structure[75]=392-sLeg;

    structure[45]=385-fLeg;
    structure[47]=385-fLeg;
    structure[49]=392-fLeg;
    structure[51]=392-fLeg;
    dino(0);

    if(kbhit())
     {
	choice=getch();
	switch(choice)
	 {
	    case 'E':goto bye;break;
	    case 'J':dino(1);break;
	    default: break;
	 }
     }
    if(i%2==0)
    {sLeg=5;fLeg=0;}
    else
    {sLeg=0;fLeg=5;}
    delay(100);
    cleardevice();
    i++;
    if(tree1[0]<-10||shift<-20)
     {
       if(move==1)
       {
	for(k=0;k<=28;k+=2)
	{
	tree1[k]+=670;
	}
       }
       else
	shift=680;
	srand(time(NULL));
	switch(rand()%3)
	{
	   case 0:move=1;break;
	   case 1:move=2;break;
	   case 2:move=3;break;
	   default:move=1;
	}
     }
    }
    
    
    out:
    if(over==1)
    {
      i=0;
	while(1)
	{
	if(i%2==0)
	{
	cleardevice();
	settextstyle(0,0,5);
	setcolor(RED);
	outtextxy(140,100,"GAME OVER");
	setcolor(YELLOW);
	outtextxy(120,200,"YOUR FINAL");
	outtextxy(120,250,str);
	delay(600);
	}
	if(kbhit())
	goto bye;
	cleardevice();
	delay(600);
	}
    }


    bye:
    cleardevice();
    outtextxy(200,100,"GAME QUIT");
    outtextxy(80,200,"ENTER ANY KEY TO EXIT");
    //HELP BOX
    help:
    if(start==0)
    { while(1)
     {
      cleardevice();
      settextstyle(0,0,3);
      setcolor(MAGENTA);
      outtextxy(80,50,"UP = U , DOWN = D ");
      outtextxy(80,100,"O = OK , E = EXIT");
      outtextxy(80,150,"J = JUMP");
      outtextxy(80,250,"MAIN MENU = M");
      choose=getch();
      if(choose=='M')
      goto first;
      else if(choose=='E')
      break;
     }
    }
    cleardevice();
    getch();
    closegraph();
}
void dino(int jump)
{
    int i,j;
    setcolor(15);
    setlinestyle(0,0,3);
    //line(0,390,getmaxx(),390);
    setcolor(4);
    setfillstyle(1,15);
    fillpoly(65,structure);
    rectangle(95,eye,100,eye+5);


    if(jump)
    {
      cleardevice();
      setcolor(15);
      setlinestyle(0,0,3);
      //line(0,390,getmaxx(),390);
      setcolor(4);
      setfillstyle(1,15);
      fillpoly(65,structureJump);
      rectangle(95,eye,100,eye+5);
      for(i=1;i<=30;i++)
       {
	 cleardevice();
	 for(j=1;j<131;j+=2)
	  {
	     structureJump[j]-=5;
	  }
	  eye-=5;
	  if(i%3==0)
	  {
	     if(move==1)
	     tree(0);
	     else if(move==2)
	     {
	       cactus(shift,0);
	       shift-=30;
	     }
	     else if(move==3)
	     {
	       cactus(shift,1);
	       shift-=30;
	     }
	  }
	  else
	  {
	     if(move==1)
	     tree(1);
	     else if(move==2)
	     {
	       cactus(shift,0);
	     }
	     else if(move==3)
	     {
	       cactus(shift,1);
	     }
	  }
	  score();
	  setcolor(15);
	  line(0,390,getmaxx(),390);
	  setcolor(4);
	  fillpoly(65,structureJump);
	  rectangle(95,eye,100,eye+5);
	  delay(10);
       }

       for(i=1;i<=30;i++)
       {
	 cleardevice();
	 for(j=1;j<131;j+=2)
	  {
	     structureJump[j]+=5;
	  }
	  eye+=5;
	  if(i%3==0)
	  {
	     if(move==1)
	     tree(0);
	     else if(move==2)
	     {
	       cactus(shift,0);
	       shift-=30;
	     }
	     else if(move==3)
	     {
	       cactus(shift,1);
	       shift-=30;
	     }
	  }
	  else
	  {
	     if(move==1)
	     tree(1);
	     else if(move==2)
	     {
	       cactus(shift,0);
	     }
	     else if(move==3)
	     {
	       cactus(shift,1);
	     }
	  }
	  score();
	  setcolor(15);
	  line(0,390,getmaxx(),390);
	  setcolor(4);
	  fillpoly(65,structureJump);
	  rectangle(95,eye,100,eye+5);
	  delay(10);
       }
    }

}

void tree(int tree)
{
   int k=0;
   if(tree==0)
    {
       setlinestyle(0,0,3);
       setcolor(15);
       line(0,390,getmaxx(),390);
       setcolor(GREEN);
       setfillstyle(8,2);
       fillpoly(14,tree1);
       setfillstyle(1,15);
       for(k=0;k<=28;k+=2)
       {
	  tree1[k]-=moveTree;
       }
    }
   if(tree==1)
    {
       setlinestyle(0,0,3);
       setcolor(15);
       line(0,390,getmaxx(),390);
       setcolor(GREEN);
       setfillstyle(8,2);
       fillpoly(14,tree1);
       setfillstyle(1,15);

    }
}
void cactus(int shift,int on)
{    int shift1;
     setlinestyle(0,0,3);
     setcolor(15);
     line(0,390,getmaxx(),390);
     setcolor(2);
     setfillstyle(8,2);
     draw[0]=shift;draw[2]=shift;draw[4]=shift+20;draw[6]=shift+20;
     draw[8]=shift+25;draw[10]=shift+25;draw[12]=shift+25;draw[14]=shift+20;
     draw[16]=shift+20;draw[18]=shift+15;draw[20]=shift+15;draw[22]=shift+10;
     draw[24]=shift+10;draw[26]=shift;draw[28]=shift;draw[30]=shift-5;
     draw[32]=shift-5;draw[34]=shift-10;draw[36]=shift-10;draw[38]=shift-15;
     draw[40]=shift-15;draw[42]=shift-25;draw[44]=shift-25;draw[46]=shift-30;
     draw[48]=shift-30;draw[50]=shift-35;draw[52]=shift-35;draw[54]=shift-40;
     draw[56]=shift-40;draw[58]=shift-30;draw[60]=shift-30;draw[62]=shift-15;
     draw[64]=shift-15;draw[66]=shift;
     fillpoly(34,draw);
     if(on)
     {
     shift1=shift+70;
     draw[0]=shift1;draw[2]=shift1;draw[4]=shift1+20;draw[6]=shift1+20;
     draw[8]=shift1+25;draw[10]=shift1+25;draw[12]=shift1+25;draw[14]=shift1+20;
     draw[16]=shift1+20;draw[18]=shift1+15;draw[20]=shift1+15;draw[22]=shift1+10;
     draw[24]=shift1+10;draw[26]=shift1;draw[28]=shift1;draw[30]=shift1-5;
     draw[32]=shift1-5;draw[34]=shift1-10;draw[36]=shift1-10;draw[38]=shift1-15;
     draw[40]=shift1-15;draw[42]=shift1-25;draw[44]=shift1-25;draw[46]=shift1-30;
     draw[48]=shift1-30;draw[50]=shift1-35;draw[52]=shift1-35;draw[54]=shift1-40;
     draw[56]=shift1-40;draw[58]=shift1-30;draw[60]=shift1-30;draw[62]=shift1-15;
     draw[64]=shift1-15;draw[66]=shift1;
     fillpoly(34,draw);
     }
     setfillstyle(1,15);
}
int gameOver()
{
   int i;
   for(i=0;i<130;i+=2)
    {
       if((structure[i]>tree1[i]&&tree1[i]>50&&move==1)||(draw[i]>50&&structure[i]>draw[i]&&move==2||draw[i]>50&&structure[i]>draw[i]&&move==3))
       return 1;
       else
       return 0;
    }
}
void score()
{
    point+=1;
    settextstyle(0,0,3);
    sprintf(str,"SCORE = %d",point);
    setcolor(14);
    outtextxy(300,100,str);
    setcolor(15);

}
