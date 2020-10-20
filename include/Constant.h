#pragma once

const unsigned BUTTON_SIZE = 100;
const int MARGE = 45;
const unsigned HEIGHT = 140; 
const float CELL = 45; // dimension of each "cell"

const int PRESENTSIZE = 30;
const int LEVEL_ACCOMPLIED = 20; // level passed
const int DIAMONDS_SCORE = 15; // score
const int NO_LIMIT = -1; // no limit in time
const int EXITBTN_SIZE = 35; //size of exit button into databar

const int NUM_OF_LIFE = 3; // for digger
const float LEVEL_SPACE = 60; // for position of level icon
const float SCORE_SPACE = 260; // for position of score icon
const float ROCKS_SPACE = 460; // for position of rocks icon
const float LIVES_SPACE = 660; //for position of heart icon
const float CLOCK_SPACE = 860; //for position of level icon

const float X_AXE = 1100; //for x pos of end msg
const float X_AXE_ORI = 410; //for x pos of end msg

const int TEXT_SIZE = 50;
const unsigned int FONTSIZE = 20;

const std::string LEVELPASSEDMSG = "LEVEL PASSED";
const std::string LEVELSTART = "BE READY, LEVEL STARTS IN";
const std::string SCOREMSG = "SCORE: ";

enum Obj_t
{
	O_EMPTY = ' ', O_DIGGER = '/', O_WALL = '#', O_DIAMONDS = 'D', O_MONSTER = '!', O_ROCK = '@', O_PRESENT = '+', O_ROCK_PRESENT = '*'
};


enum Texture_t //all the textures
{
	T_BACKGROUND, T_MENUBTN, T_EXIT, T_DIGGER, T_WALL, T_ROCK, T_DIAMOND,
	T_TILE, T_CLOCK, T_INFINITY, T_LIFE, T_MONSTER, T_LEVEL, T_SCORE, T_SMART_MONSTER,
	T_ROCK_COUNTER, T_OVER, T_EXIT_BTN, T_LOCITION, T_MAP ,T_SOUND,T_MUTE, T_COIN,
	T_HEART,T_PRES_SCORE,T_PRES_TIME,T_PRES_ROCK,  T_WINNER, T_LOSER, T_BACK_END

};

const size_t NUM_OF_TEXTURES = 31;