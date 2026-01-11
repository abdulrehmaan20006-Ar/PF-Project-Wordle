#include "config_and_globals.h"

// ==================== MAIN MENU ====================
void showMainMenu(){
    cls(); drawAtmosphere();
    drawBox(20,5,70,20,LIGHTMAGENTA);
    printCentered("ULTIMATE WORDLE ARCADE",6,YELLOW,BLACK);
    printCentered("1. NEW PROFILE  2. LOAD PROFILE  3. PLAY WORDLE  4. EXIT",10,LIGHTCYAN,BLACK);
}

int main(){
    srand(time(0));
    initSystem();
    loadProfiles();
    bool running=true;
    while(running){
        showMainMenu();
        gotoxy(50,12); int choice; cin>>choice;
        switch(choice){
            case 1: createProfile(); break;
            case 2: 
                if(profileCount>0){ currentPlayerIndex=0; printCentered("LOADED PROFILE: "+profiles[0].gamertag,15,LIGHTGREEN,BLACK); Sleep(1000); } 
                else { printCentered("NO PROFILES FOUND",15,RED,BLACK); Sleep(1000); }
                break;
            case 3: 
                if(currentPlayerIndex==-1){ printCentered("CREATE OR LOAD PROFILE FIRST!",15,RED,BLACK); Sleep(1500); }
                else runGameRound(); 
                break;
            case 4: running=false; break;
            default: printCentered("INVALID OPTION!",15,RED,BLACK); Sleep(1000); break;
        }
    }
    cls();
    printCentered("THANKS FOR PLAYING!",15,LIGHTGREEN,BLACK);
    return 0;
}
