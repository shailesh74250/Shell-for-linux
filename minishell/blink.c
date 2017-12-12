#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
#define ALL_NORMAL "\033[0m"
#define BG_BLACK   "\033[40m"
#define BLACKBACK BG_BLACK " " ALL_NORMAL
#define REVERSE "\033[7m"
 
#define FG_RED         "\033[1;31;40m"           // bright red black bg
#define FG_MAROON      "\033[2;31;40m"        // dark red black bg
#define FG_YELLOW    "\033[1;33;40m"           // bright yellow black bg
#define FG_DYELLOW      "\033[2;33;40m"        // dark yellow black bg
 
#define BRIGHT_RED_M FG_RED "M" ALL_NORMAL
#define DIM_RED_M FG_MAROON "M" ALL_NORMAL
#define BRIGHT_YELLOW_R FG_YELLOW "R" ALL_NORMAL
#define DIM_YELLOW_R FG_DYELLOW "R" ALL_NORMAL
 
void set_coord(int x, int y);
void plot_char(int x,int y,char *char_string);
 
int main(void)
{
    int x,y,timer;
     
    system("clear");
     
     
    for(x=0;x<80;x++)                    //set background black 
    {
        for(y=0;y<25;y++)
        {
            plot_char(x,y,BLACKBACK);
                                     
        }
    }
     
     
    while(1)
    {    
        plot_char(20,10,BRIGHT_RED_M);
        plot_char(22,10,BRIGHT_YELLOW_R);
         
        timer = 0;
        while(timer < 10000000)
        {
            timer++;
        }
         
        plot_char(20,10,DIM_RED_M);
        plot_char(22,10,DIM_YELLOW_R);
         
        timer = 0;
        while(timer < 1000000)
        {
            timer++;
        }        
    }    
    return 0;
}
 
void set_coord(int x, int y)
{    
    printf("\033[%d;%dH",y,x);    // move cursor (row x, col y) 
}
 
void plot_char(int x,int y,char *char_string)
{
    set_coord(x,y);
    fputs(char_string,stdout);
    //printf("%s",char_string);
}
