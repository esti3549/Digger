#pragma once
const auto EPSILON = 1;
const auto WIDTH_OF_WINDOW = 1200;
const auto HEIGHT_OF_WINDOW = 800;
const auto WIDTH_OF_BOARD = 1000;
const auto HEIGHT_OF_INRORMATION_LIST = 250;
const auto DIAMOND = 'D';
const auto MONSTER = '!';
const auto DIGGER = '/';
const auto STONE = '@';
const auto WALL = '#';
const auto SPACE = ' ';
const auto GIFT = '+';
const auto TOTAL_LIVE = 3;
const auto MONSTER_SPEED = 50;
const auto DIGGER_SPEED = 90;
const auto NUM_OF_DIRECTION = 4;

enum  Objects
{ 
	diamond,
	digger,
	exitButton,
	gameBackGround,
	gameOver,
	stone,
	menuPicture,
	monster1,
	monster2,
	scoreGift,
	startButton,
	stoneGift,
	timeGift,
	wall,
	winner,
	
};
enum Directions
{
    Left,
	Right,
	Up,
	Down,
	Default,
};