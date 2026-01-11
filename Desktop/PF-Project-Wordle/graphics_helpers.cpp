#include "config_and_globals.h"

// ==================== GRAPHICS & HELPERS ====================
void gotoxy(int x, int y) { 
    COORD coord; coord.X = x; coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
} 

void setColor(int text, int background) { 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) | text); 
} 

void cls() { setColor(WHITE, BLACK); system("cls"); }

string intToString(int v) { stringstream ss; ss << v; return ss.str(); }

string toUpper(string s) { 
    for (int i = 0; i < s.length(); i++) {
        if(s[i]>='a' && s[i]<='z') s[i]-=('a'-'A');
    } return s; 
}

void drawBox(int x, int y, int width, int height, int color) { 
    setColor(color, BLACK); 
    gotoxy(x, y); cout << (char)201; for(int i=0;i<width-2;i++) cout<<(char)205; cout<<(char)187;
    for(int i=1;i<height-1;i++){ gotoxy(x,y+i);cout<<(char)186; gotoxy(x+width-1,y+i);cout<<(char)186; }
    gotoxy(x,y+height-1); cout<<(char)200; for(int i=0;i<width-2;i++) cout<<(char)205; cout<<(char)188;
}

void drawAtmosphere() { 
    char symbols[]={3,4,5,6,13,14,15,42,43,(char)248,1};  
    int numSymbols=11;
    for(int i=0;i<80;i++){ 
        int x=rand()%SCREEN_WIDTH; int y=rand()%SCREEN_HEIGHT;
        if(x>15 && x<SCREEN_WIDTH-15 && y>3 && y<32) continue;
        int color=(rand()%2==0)?DARKGRAY:BLUE; if(rand()%10==0) color=CYAN;
        setColor(color,BLACK); gotoxy(x,y); cout<<symbols[rand()%numSymbols];
    }
}

void initSystem() { 
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx=new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize=sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hStdOut,0,lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X=0; lpConsoleCurrentFontEx->dwFontSize.Y=24; 
    lpConsoleCurrentFontEx->FontWeight=FW_BOLD;
    wcscpy(lpConsoleCurrentFontEx->FaceName,L"Consolas");
    SetCurrentConsoleFontEx(hStdOut,0,lpConsoleCurrentFontEx);
    CONSOLE_CURSOR_INFO info; info.dwSize=100; info.bVisible=FALSE;
    SetConsoleCursorInfo(hStdOut,&info);
    SetConsoleTitle("ULTIMATE ARCADE WORDLE");
}

void playSound(string type){ 
    if(type=="INTRO"){Beep(523,100);Beep(659,100);Beep(784,100);}
    else if(type=="WIN"){Beep(523,100);Beep(659,100);Beep(784,100);Beep(1046,300);}
    else if(type=="LOSE"){Beep(300,200);Beep(200,400);}
    else if(type=="TYPE"){Beep(800,10);}
    else if(type=="ERROR"){MessageBeep(MB_ICONHAND);}
}