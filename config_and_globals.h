#pragma once
#define _WIN32_WINNT 0x0500

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

// ==================== CONSTANTS ====================
const int SCREEN_WIDTH = 110; 
const int SCREEN_HEIGHT = 35; 
const string SAVE_FILE = "wordle_platinum_data.txt"; 

const int MAX_PLAYERS = 100;       
const int MAX_WORDS_PER_LIST = 10; 
const int MAX_QUOTES = 5;          
const int MAX_ROASTS = 4;          

// ==================== COLORS ====================
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

// ==================== STRUCTS ====================
struct Player { 
    string name;           
    int age;               
    string experience;     
    string gamertag;       
    int totalScore;        
    int gamesPlayed;       
    int currentStreak;     
    int highestStreak;     
}; 

// ==================== GLOBALS ====================
extern Player profiles[MAX_PLAYERS]; 
extern int profileCount;       
extern int currentPlayerIndex;

extern string easyWords[MAX_WORDS_PER_LIST]; 
extern string mediumWords[MAX_WORDS_PER_LIST]; 
extern string hardWords[MAX_WORDS_PER_LIST]; 
extern string impossibleWords[MAX_WORDS_PER_LIST]; 

extern string successQuotes[MAX_QUOTES]; 
extern string motivationQuotes[MAX_QUOTES]; 
extern string winRoasts[MAX_ROASTS]; 
extern string loseRoasts[MAX_ROASTS];
