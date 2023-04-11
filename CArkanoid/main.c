#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void gotoxy(int x, int y);
int tus_kontrol(void);

int main(void) {
	int hiz=300,yem_x=40,yem_y=1,kutu_x=40,kutu_y=22,kutu_durum;
	int level=0,hak=0,seviye=1,a=5,hizz;
	char yon;
	while(yem_y<24 && hak!=5)
	{
	if(!kbhit()){
		gotoxy(yem_x,yem_y);
		Sleep(hiz);
		if(yem_y<18){
		  yem_y++; yem_x+=rand()%9-4; }
		  else yem_y++; 
		if(yem_x>65) yem_x=64;
		
		printf("+"); gotoxy(0,yem_y-2); printf("                                                                                                 ");
		
		 gotoxy(0,kutu_y); printf("                                                                                                             ");
		 gotoxy(kutu_x,kutu_y); printf("|_____|");
		 if(yem_y==22)
		{
		    if(fabs(yem_x-kutu_x)<5){
				gotoxy(kutu_x,kutu_y); printf("|+ + +|"); level++; seviye=1+(level/5); }
				else {gotoxy(kutu_x,kutu_y); printf("|- - -|"); hak++; a--;} ;
		}
    hiz=300-(seviye*10); hizz=seviye*10;
		if(yem_y==23)
		{
			yem_y=1; yem_x+=rand()%9-4;
		}
	   }
	   else 
	   {
	   yon=getch();
	   kutu_durum=tus_kontrol();
            if (kutu_durum==-1)
                break;
	   else if(kutu_durum==75)
	   {
	   	    kutu_x-=4;
	   }
	   else if(kutu_durum==77)
	   {
	   	    kutu_x+=4;
	   	    
	   }}
	  gotoxy(1,24); printf("___________________________________________________");	
	   gotoxy(1,25);
	printf("yem konumu:%2d  seviye:%d  hiz:%d  kalan hakkiniz:%d |",yem_y,seviye,hizz,a);
	gotoxy(1,26); printf("___________________________________________________");	
	}
	    	
		gotoxy(40,10); printf("Y E N I L D Y N I Z ! ! !");	
	return 0;
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

int tus_kontrol(void){
    int ch = getch();
    if (ch==27)
       return(-1);
    else if (ch == 0 || ch == 224)
       return ch;
    else;}
