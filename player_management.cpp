#include "config_and_globals.h"

// ==================== GLOBAL ARRAYS ====================
Player profiles[MAX_PLAYERS]; 
int profileCount=0;       
int currentPlayerIndex=-1; 

string easyWords[MAX_WORDS_PER_LIST] = {"APPLE","HOUSE","TRAIN","WATER","SHOES","BREAD","CHAIR","TABLE","MOUSE","SMILE"};
string mediumWords[MAX_WORDS_PER_LIST] = {"BEACH","BRAIN","BRUSH","CHEST","CHORD","CLICK","CLOCK","DANCE","DREAM","GHOST"};
string hardWords[MAX_WORDS_PER_LIST] = {"CRYPT","DWARF","FLASK","HYPER","IVORY","QUICK","VORTEX","ABYSS","FJORD","WALTZ"};
string impossibleWords[MAX_WORDS_PER_LIST] = {"XYLEM","QANAT","JAZZY","UNZIP","HACK","PIGMY","ZEPHYR","SPHINX","MYRRH","QOPH"};

string successQuotes[MAX_QUOTES] = {
"\"Greatness is not measured by what a man or woman accomplishes, but by the opposition they have overcome.\"",
"\"The only way to do great work is to love what you do.\"",
"\"Believe you can and you're halfway there.\"",
"\"Quality is not an act, it is a habit.\"",
"\"Victory belongs to the most persevering.\""
};

string motivationQuotes[MAX_QUOTES] = {
"\"Fall seven times, stand up eight.\" - Japanese Proverb",
"\"I have not failed. I've just found 10,000 ways that won't work.\" - Edison",
"\"Mistakes are the portals of discovery.\"",
"\"Failure is simply the opportunity to begin again, this time more intelligently.\"",
"\"It always seems impossible until it's done.\""
};

string winRoasts[MAX_ROASTS] = {
"GAME: \"Okay, I admit... that was impressive.\"",
"GAME: \"My processor is overheating from your genius.\"",
"GAME: \"Are you a robot? Because you play like one.\"",
"GAME: \"Finally, someone worthy of my time.\""
};

string loseRoasts[MAX_ROASTS] = {
"GAME: \"I've seen goldfish with better memory.\"",
"GAME: \"Did you lean on the keyboard?\"",
"GAME: \"My grandma plays better, and she's 90.\"",
"GAME: \"Maybe try coloring books instead?\""
};

// ==================== PROFILE FUNCTIONS ====================
string generateGamertag(string name){ 
    string tag=name,cleanTag="";
    for(int i=0;i<tag.length();i++) if(tag[i]!=' ') cleanTag+=tag[i];
    return cleanTag+intToString(rand()%99);
}

void loadProfiles(){ 
    ifstream file(SAVE_FILE.c_str()); 
    if(!file) return;
    profileCount=0; Player p;
    while(file>>p.name>>p.age>>p.experience>>p.gamertag>>p.totalScore>>p.gamesPlayed>>p.currentStreak>>p.highestStreak){
        if(profileCount<MAX_PLAYERS){profiles[profileCount]=p;profileCount++;}
    }
    file.close();
}

void saveProfiles(){ 
    ofstream file(SAVE_FILE.c_str()); 
    for(int i=0;i<profileCount;i++){
        file<<profiles[i].name<<" "<<profiles[i].age<<" "<<profiles[i].experience<<" "
            <<profiles[i].gamertag<<" "<<profiles[i].totalScore<<" "<<profiles[i].gamesPlayed<<" "
            <<profiles[i].currentStreak<<" "<<profiles[i].highestStreak<<endl;
    } file.close();
}

void createProfile(){ 
    cls(); drawAtmosphere(); drawBox(30,8,50,20,LIGHTBLUE); printCentered("NEW AGENT REGISTRATION",10,WHITE,BLACK);
    if(profileCount>=MAX_PLAYERS){printCentered("MAX PROFILES REACHED",15,RED,BLACK); Sleep(2000); return;}
    Player p; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    setColor(LIGHTCYAN,BLACK); gotoxy(35,13); cout<<"ENTER NAME: "; setColor(WHITE,BLACK); cin>>p.name;
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    setColor(LIGHTCYAN,BLACK); gotoxy(35,15); cout<<"ENTER AGE:  "; setColor(WHITE,BLACK); cin>>p.age;
    setColor(LIGHTCYAN,BLACK); gotoxy(35,17); cout<<"PLAYED BEFORE? (y/n): "; char c; cin>>c;
    if(c=='y'||c=='Y'){gotoxy(35,19);cout<<"EXPERIENCE LEVEL:";gotoxy(35,20);cout<<"1. CASUAL";gotoxy(35,21);cout<<"2. GAMER";gotoxy(35,22);cout<<"3. PRO";char e;cin>>e;if(e=='1')p.experience="CASUAL"; else if(e=='2')p.experience="GAMER"; else p.experience="PRO";}
    else p.experience="NEWBIE";
    p.gamertag=generateGamertag(p.name); p.totalScore=0; p.gamesPlayed=0; p.currentStreak=0; p.highestStreak=0;
    profiles[profileCount]=p; currentPlayerIndex=profileCount; profileCount++;
    saveProfiles(); printCentered("PROFILE CREATED: "+p.gamertag,25,YELLOW,BLACK); playSound("WIN"); Sleep(1000);
}