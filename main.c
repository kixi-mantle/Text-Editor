#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


struct termios orig_termios;

void disableRawMode(){
    tcsetattr(STDIN_FILENO , TCSAFLUSH , &orig_termios);
}



void enableRawMOde(){
     struct termios raw;


     tcgetattr(STDIN_FILENO , &orig_termios);

     raw = orig_termios;
     
     raw.c_lflag &= ~(ECHO | ICANON);
     
     tcsetattr(STDIN_FILENO , TCSAFLUSH ,&raw );



}






int main(){

    enableRawMOde();

    char c;
    while(read(STDIN_FILENO , &c, 1) == 1 && c!= 'q'){
        if(iscntrl(c)){
            printf("%d\n" , c);
        }else {
            printf("%d ('%c')\n" , c , c);
        }
    }
    return 0 ;
}