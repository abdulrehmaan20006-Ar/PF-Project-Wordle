#include "config_and_globals.h"

// ==================== WORDLE LOGIC ====================
string pickWord(string difficulty) {
    int idx;
    if(difficulty=="EASY") idx=rand()%MAX_WORDS_PER_LIST; 
    else if(difficulty=="MEDIUM") idx=rand()%MAX_WORDS_PER_LIST; 
    else if(difficulty=="HARD") idx=rand()%MAX_WORDS_PER_LIST; 
    else idx=rand()%MAX_WORDS_PER_LIST; 

    if(difficulty=="EASY") return easyWords[idx];
    else if(difficulty=="MEDIUM") return mediumWords[idx];
    else if(difficulty=="HARD") return hardWords[idx];
    else return impossibleWords[idx];
}

void printCentered(string text,int y,int color,int bg){
    setColor(color,bg); gotoxy((SCREEN_WIDTH-text.length())/2,y); cout<<text; setColor(WHITE,BLACK);
}

bool playWordleRound(string word) {
    cls(); drawBox(20,5,70,20,LIGHTGREEN);
    printCentered("WORDLE CHALLENGE!",6,YELLOW,BLACK);
    int attempts=6; string guess;
    for(int i=1;i<=attempts;i++){
        setColor(LIGHTCYAN,BLACK); gotoxy(25,7+i); cout<<"Attempt "<<i<<": "; setColor(WHITE,BLACK); cin>>guess;
        guess=toUpper(guess);
        if(guess==word){
            printCentered("YOU GOT IT! :)",15,LIGHTGREEN,BLACK);
            playSound("WIN"); return true;
        } else {
            for(int j=0;j<word.length();j++){
                gotoxy(40+j,7+i);
                if(j<guess.length()){
                    if(guess[j]==word[j]) setColor(GREEN,BLACK);
                    else if(word.find(guess[j])!=string::npos) setColor(YELLOW,BLACK);
                    else setColor(RED,BLACK);
                    cout<<guess[j];
                    setColor(WHITE,BLACK);
                }
            }
        }
    }
    printCentered("GAME OVER! WORD WAS: "+word,18,RED,BLACK);
    playSound("LOSE");
    return false;
}

void runGameRound(){
    cls(); drawAtmosphere();
    printCentered("CHOOSE DIFFICULTY",6,YELLOW,BLACK);
    printCentered("1. EASY  2. MEDIUM  3. HARD  4. IMPOSSIBLE",8,LIGHTCYAN,BLACK);
    int choice; gotoxy(50,10); cin>>choice;
    string word;
    if(choice==1) word=pickWord("EASY");
    else if(choice==2) word=pickWord("MEDIUM");
    else if(choice==3) word=pickWord("HARD");
    else word=pickWord("IMPOSSIBLE");
    bool result=playWordleRound(word);
    if(currentPlayerIndex>=0){
        Player &p=profiles[currentPlayerIndex];
        p.gamesPlayed++;
        if(result){ p.totalScore+=10; p.currentStreak++; if(p.currentStreak>p.highestStreak)p.highestStreak=p.currentStreak;}
        else p.currentStreak=0;
        saveProfiles();
    }
}