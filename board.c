#define ALLEGRO_UNSTABLE
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

#define NONE 100
#define KING 1
#define PAWN 2
#define KNIGHT 3
#define BISHOP 4
#define ROOK 5
#define QUEEN 6
#define WHITE 8
#define BLACK 16
#define INDIC -1

int board[64];
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER* timer;
bool redraw;
int switcher = 0;
int selectedcell;
int xx;
int yy;

int drawpiece(int piecechoice,int x,int y);

int drawboard();

int pxtocell(int x,int y);

int boardupdate();

int calculatemoves(){
	int x,y;
	if (switcher == 0){
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | ROOK)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y)+(x+i)] == (BLACK | KING)) || (board[8*(y)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x+i)] == (BLACK | ROOK)) || (board[8*(y)+(x+i)] == (BLACK | PAWN))) || (x+i > 7)){
						break;
					}
					if ((board[8*(y)+(x+i)] == (WHITE | KING)) || (board[8*(y)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x+i)] == (WHITE | ROOK)) || (board[8*(y)+(x+i)] == (WHITE | PAWN)) || (x+i > 7)){
						board[8*(y)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y)+(x-i)] == (BLACK | KING)) || (board[8*(y)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x-i)] == (BLACK | ROOK)) || (board[8*(y)+(x-i)] == (BLACK | PAWN))) || (x-i < 0)){
						break;
					}
					if ((board[8*(y)+(x-i)] == (WHITE | KING)) || (board[8*(y)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x-i)] == (WHITE | ROOK)) || (board[8*(y)+(x-i)] == (WHITE | PAWN)) || (x-i < 0)){
						board[8*(y)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y+i)+(x)] == (BLACK | KING)) || (board[8*(y+i)+(x)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x)] == (BLACK | ROOK)) || (board[8*(y+i)+(x)] == (BLACK | PAWN))) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x)] == (WHITE | KING)) || (board[8*(y+i)+(x)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x)] == (WHITE | ROOK)) || (board[8*(y+i)+(x)] == (WHITE | PAWN)) || (y+i > 7)){
						board[8*(y+i)+(x)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x)] == (BLACK | KING)) || (board[8*(y-i)+(x)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x)] == (BLACK | ROOK)) || (board[8*(y-i)+(x)] == (BLACK | PAWN))) || (y-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x)] == (WHITE | KING)) || (board[8*(y-i)+(x)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x)] == (WHITE | ROOK)) || (board[8*(y-i)+(x)] == (WHITE | PAWN)) || (y-i < 0)){
						board[8*(y-i)+(x)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | BISHOP)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y+i)+(x+i)] == (BLACK | KING)) || (board[8*(y+i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x+i)] == (BLACK | PAWN))) || (x+i > 7) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x+i)] == (WHITE | KING)) || (board[8*(y+i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x+i)] == (WHITE | PAWN)) || (x+i > 7) || (y+i > 7)){
						board[8*(y+i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y+i)+(x-i)] == (BLACK | KING)) || (board[8*(y+i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x-i)] == (BLACK | PAWN))) || (x-i < 0) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x-i)] == (WHITE | KING)) || (board[8*(y+i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x-i)] == (WHITE | PAWN)) || (x-i < 0) || (y+i > 7)){
						board[8*(y+i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y-i)+(x+i)] == (BLACK | KING)) || (board[8*(y-i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x+i)] == (BLACK | PAWN))) || (y-i < 0) || (x+i>7)){
						break;
					}
					if ((board[8*(y-i)+(x+i)] == (WHITE | KING)) || (board[8*(y-i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x+i)] == (WHITE | PAWN)) || (y-i < 0) || (x+i > 7)){
						board[8*(y-i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x+i)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x-i)] == (BLACK | KING)) || (board[8*(y-i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x-i)] == (BLACK | PAWN))) || (y-i < 0) || (x-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x-i)] == (WHITE | KING)) || (board[8*(y-i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x-i)] == (WHITE | PAWN)) || (y-i < 0) || (x-i < 0)){
						board[8*(y-i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x-i)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | KNIGHT)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y+1)+(x+2)] == (BLACK | KING)) || (board[8*(y+1)+(x+2)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x+2)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x+2)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x+2)] == (BLACK | ROOK)) || (board[8*(y+1)+(x+2)] == (BLACK | PAWN))) || (x+2 > 7) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x+2)] *= INDIC;
		}
		if(((board[8*(y+1)+(x-2)] == (BLACK | KING)) || (board[8*(y+1)+(x-2)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x-2)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x-2)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x-2)] == (BLACK | ROOK)) || (board[8*(y+1)+(x-2)] == (BLACK | PAWN))) || (x-2 < 0) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x-2)] *= INDIC;
		}
		if(((board[8*(y+2)+(x+1)] == (BLACK | KING)) || (board[8*(y+2)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y+2)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y+2)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y+2)+(x+1)] == (BLACK | ROOK)) || (board[8*(y+2)+(x+1)] == (BLACK | PAWN))) || (x+1 > 7) || (y+2 > 7)){
		} else {
			board[8*(y+2)+(x+1)] *= INDIC;
		}
		if(((board[8*(y+2)+(x-1)] == (BLACK | KING)) || (board[8*(y+2)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y+2)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y+2)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y+2)+(x-1)] == (BLACK | ROOK)) || (board[8*(y+2)+(x-1)] == (BLACK | PAWN))) || (x-1 < 0) || (y+2 > 7)){
		} else {
			board[8*(y+2)+(x-1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x+2)] == (BLACK | KING)) || (board[8*(y-1)+(x+2)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x+2)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x+2)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x+2)] == (BLACK | ROOK)) || (board[8*(y-1)+(x+2)] == (BLACK | PAWN))) || (x+2 > 7) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x+2)] *= INDIC;
		}
		if(((board[8*(y-1)+(x-2)] == (BLACK | KING)) || (board[8*(y-1)+(x-2)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x-2)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x-2)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x-2)] == (BLACK | ROOK)) || (board[8*(y-1)+(x-2)] == (BLACK | PAWN))) || (x-2 < 0) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x-2)] *= INDIC;
		}
		if(((board[8*(y-2)+(x+1)] == (BLACK | KING)) || (board[8*(y-2)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y-2)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y-2)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y-2)+(x+1)] == (BLACK | ROOK)) || (board[8*(y-2)+(x+1)] == (BLACK | PAWN))) || (x+1 > 7) || (y-2 < 0)){
		} else {
			board[8*(y-2)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-2)+(x-1)] == (BLACK | KING)) || (board[8*(y-2)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y-2)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y-2)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y-2)+(x-1)] == (BLACK | ROOK)) || (board[8*(y-2)+(x-1)] == (BLACK | PAWN))) || (x-1 < 0) || (y-2 < 0)){
		} else {
			board[8*(y-2)+(x-1)] *= INDIC;
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | KING)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y+1)+(x)] == (BLACK | KING)) || (board[8*(y+1)+(x)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x)] == (BLACK | ROOK)) || (board[8*(y+1)+(x)] == (BLACK | PAWN))) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x)] *= INDIC;
		}
		if(((board[8*(y+1)+(x-1)] == (BLACK | KING)) || (board[8*(y+1)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x-1)] == (BLACK | ROOK)) || (board[8*(y+1)+(x-1)] == (BLACK | PAWN))) || (x-1 < 0) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x-1)] *= INDIC;
		}
		if(((board[8*(y+1)+(x+1)] == (BLACK | KING)) || (board[8*(y+1)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x+1)] == (BLACK | ROOK)) || (board[8*(y+1)+(x+1)] == (BLACK | PAWN))) || (x+1 > 7) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x+1)] *= INDIC;
		}
		if(((board[8*(y)+(x-1)] == (BLACK | KING)) || (board[8*(y)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y)+(x-1)] == (BLACK | ROOK)) || (board[8*(y)+(x-1)] == (BLACK | PAWN))) || (x-1 < 0)){
		} else {
			board[8*(y)+(x-1)] *= INDIC;
		}
		if(((board[8*(y)+(x+1)] == (BLACK | KING)) || (board[8*(y)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y)+(x+1)] == (BLACK | ROOK)) || (board[8*(y)+(x+1)] == (BLACK | PAWN))) || (x+1 > 7)){
		} else {
			board[8*(y)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x-1)] == (BLACK | KING)) || (board[8*(y-1)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x-1)] == (BLACK | ROOK)) || (board[8*(y-1)+(x-1)] == (BLACK | PAWN))) || (x-1 < 0) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x-1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x+1)] == (BLACK | KING)) || (board[8*(y-1)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x+1)] == (BLACK | ROOK)) || (board[8*(y-1)+(x+1)] == (BLACK | PAWN))) || (x+1 > 7) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x)] == (BLACK | KING)) || (board[8*(y-1)+(x)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x)] == (BLACK | ROOK)) || (board[8*(y-1)+(x)] == (BLACK | PAWN))) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x)] *= INDIC;
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | QUEEN)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y)+(x+i)] == (BLACK | KING)) || (board[8*(y)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x+i)] == (BLACK | ROOK)) || (board[8*(y)+(x+i)] == (BLACK | PAWN))) || (x+i > 7)){
						break;
					}
					if ((board[8*(y)+(x+i)] == (WHITE | KING)) || (board[8*(y)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x+i)] == (WHITE | ROOK)) || (board[8*(y)+(x+i)] == (WHITE | PAWN)) || (x+i > 7)){
						board[8*(y)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y)+(x-i)] == (BLACK | KING)) || (board[8*(y)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x-i)] == (BLACK | ROOK)) || (board[8*(y)+(x-i)] == (BLACK | PAWN))) || (x-i < 0)){
						break;
					}
					if ((board[8*(y)+(x-i)] == (WHITE | KING)) || (board[8*(y)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x-i)] == (WHITE | ROOK)) || (board[8*(y)+(x-i)] == (WHITE | PAWN)) || (x-i < 0)){
						board[8*(y)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y+i)+(x)] == (BLACK | KING)) || (board[8*(y+i)+(x)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x)] == (BLACK | ROOK)) || (board[8*(y+i)+(x)] == (BLACK | PAWN))) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x)] == (WHITE | KING)) || (board[8*(y+i)+(x)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x)] == (WHITE | ROOK)) || (board[8*(y+i)+(x)] == (WHITE | PAWN)) || (y+i > 7)){
						board[8*(y+i)+(x)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x)] == (BLACK | KING)) || (board[8*(y-i)+(x)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x)] == (BLACK | ROOK)) || (board[8*(y-i)+(x)] == (BLACK | PAWN))) || (y-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x)] == (WHITE | KING)) || (board[8*(y-i)+(x)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x)] == (WHITE | ROOK)) || (board[8*(y-i)+(x)] == (WHITE | PAWN)) || (y-i < 0)){
						board[8*(y-i)+(x)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x)] *= INDIC;
				}
			}
		}
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y+i)+(x+i)] == (BLACK | KING)) || (board[8*(y+i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x+i)] == (BLACK | PAWN))) || (x+i > 7) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x+i)] == (WHITE | KING)) || (board[8*(y+i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x+i)] == (WHITE | PAWN)) || (x+i > 7) || (y+i > 7)){
						board[8*(y+i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y+i)+(x-i)] == (BLACK | KING)) || (board[8*(y+i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x-i)] == (BLACK | PAWN))) || (x-i < 0) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x-i)] == (WHITE | KING)) || (board[8*(y+i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x-i)] == (WHITE | PAWN)) || (x-i < 0) || (y+i > 7)){
						board[8*(y+i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y-i)+(x+i)] == (BLACK | KING)) || (board[8*(y-i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x+i)] == (BLACK | PAWN))) || (y-i < 0) || (x+i>7)){
						break;
					}
					if ((board[8*(y-i)+(x+i)] == (WHITE | KING)) || (board[8*(y-i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x+i)] == (WHITE | PAWN)) || (y-i < 0) || (x+i > 7)){
						board[8*(y-i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x+i)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x-i)] == (BLACK | KING)) || (board[8*(y-i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x-i)] == (BLACK | PAWN))) || (y-i < 0) || (x-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x-i)] == (WHITE | KING)) || (board[8*(y-i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x-i)] == (WHITE | PAWN)) || (y-i < 0) || (x-i < 0)){
						board[8*(y-i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x-i)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | PAWN)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y+1)+(x-1)] == (WHITE | KING)) || (board[8*(y+1)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x-1)] == (WHITE | ROOK)) || (board[8*(y+1)+(x-1)] == (WHITE | PAWN))) && ((x-1 > 0) && (y+1 < 7))){
			board[8*(y+1)+(x-1)] *= INDIC;
		} else {
		}
		if(((board[8*(y+1)+(x+1)] == (WHITE | KING)) || (board[8*(y+1)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x+1)] == (WHITE | ROOK)) || (board[8*(y+1)+(x+1)] == (WHITE | PAWN))) && ((x+1 < 7) && (y+1 < 7))){
			board[8*(y+1)+(x+1)] *= INDIC;
		} else {
		}
		if(((board[8*(y+1)+(x)] == (WHITE | KING)) || (board[8*(y+1)+(x)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x)] == (WHITE | ROOK)) || (board[8*(y+1)+(x)] == (WHITE | PAWN))) || (y+1 > 7) || ((board[8*(y+1)+(x)] == (BLACK | KING)) || (board[8*(y+1)+(x)] == (BLACK | QUEEN)) || (board[8*(y+1)+(x)] == (BLACK | BISHOP)) || (board[8*(y+1)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+1)+(x)] == (BLACK | ROOK)) || (board[8*(y+1)+(x)] == (BLACK | PAWN)))){
		} else {
			board[8*(y+1)+(x)] *= INDIC;
			if(((board[8*(y+2)+(x)] == (WHITE | KING)) || (board[8*(y+2)+(x)] == (WHITE | QUEEN)) || (board[8*(y+2)+(x)] == (WHITE | BISHOP)) || (board[8*(y+2)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+2)+(x)] == (WHITE | ROOK)) || (board[8*(y+2)+(x)] == (WHITE | PAWN))) || (y+2 < 0) || ((board[8*(y+2)+(x)] == (BLACK | KING)) || (board[8*(y+2)+(x)] == (BLACK | QUEEN)) || (board[8*(y+2)+(x)] == (BLACK | BISHOP)) || (board[8*(y+2)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+2)+(x)] == (BLACK | ROOK)) || (board[8*(y+2)+(x)] == (BLACK | PAWN)))){
			} else {
				if(y == 1){
					board[8*(y+2)+(x)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | ROOK)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y)+(x+i)] == (WHITE | KING)) || (board[8*(y)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x+i)] == (WHITE | ROOK)) || (board[8*(y)+(x+i)] == (WHITE | PAWN))) || (x+i > 7)){
						break;
					}
					if ((board[8*(y)+(x+i)] == (BLACK | KING)) || (board[8*(y)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x+i)] == (BLACK | ROOK)) || (board[8*(y)+(x+i)] == (BLACK | PAWN)) || (x+i > 7)){
						board[8*(y)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y)+(x-i)] == (WHITE | KING)) || (board[8*(y)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x-i)] == (WHITE | ROOK)) || (board[8*(y)+(x-i)] == (WHITE | PAWN))) || (x-i < 0)){
						break;
					}
					if ((board[8*(y)+(x-i)] == (BLACK | KING)) || (board[8*(y)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x-i)] == (BLACK | ROOK)) || (board[8*(y)+(x-i)] == (BLACK | PAWN)) || (x-i < 0)){
						board[8*(y)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y+i)+(x)] == (WHITE | KING)) || (board[8*(y+i)+(x)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x)] == (WHITE | ROOK)) || (board[8*(y+i)+(x)] == (WHITE | PAWN))) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x)] == (BLACK | KING)) || (board[8*(y+i)+(x)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x)] == (BLACK | ROOK)) || (board[8*(y+i)+(x)] == (BLACK | PAWN)) || (y+i > 7)){
						board[8*(y+i)+(x)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x)] == (WHITE | KING)) || (board[8*(y-i)+(x)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x)] == (WHITE | ROOK)) || (board[8*(y-i)+(x)] == (WHITE | PAWN))) || (y-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x)] == (BLACK | KING)) || (board[8*(y-i)+(x)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x)] == (BLACK | ROOK)) || (board[8*(y-i)+(x)] == (BLACK | PAWN)) || (y-i < 0)){
						board[8*(y-i)+(x)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | BISHOP)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y+i)+(x+i)] == (WHITE | KING)) || (board[8*(y+i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x+i)] == (WHITE | PAWN))) || (x+i > 7) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x+i)] == (BLACK | KING)) || (board[8*(y+i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x+i)] == (BLACK | PAWN)) || (x+i > 7) || (y+i > 7)){
						board[8*(y+i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y+i)+(x-i)] == (WHITE | KING)) || (board[8*(y+i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x-i)] == (WHITE | PAWN))) || (x-i < 0) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x-i)] == (BLACK | KING)) || (board[8*(y+i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x-i)] == (BLACK | PAWN)) || (x-i < 0) || (y+i > 7)){
						board[8*(y+i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y-i)+(x+i)] == (WHITE | KING)) || (board[8*(y-i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x+i)] == (WHITE | PAWN))) || (y-i < 0) || (x+i>7)){
						break;
					}
					if ((board[8*(y-i)+(x+i)] == (BLACK | KING)) || (board[8*(y-i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x+i)] == (BLACK | PAWN)) || (y-i < 0) || (x+i > 7)){
						board[8*(y-i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x+i)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x-i)] == (WHITE | KING)) || (board[8*(y-i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x-i)] == (WHITE | PAWN))) || (y-i < 0) || (x-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x-i)] == (BLACK | KING)) || (board[8*(y-i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x-i)] == (BLACK | PAWN)) || (y-i < 0) || (x-i < 0)){
						board[8*(y-i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x-i)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | KNIGHT)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y+1)+(x+2)] == (WHITE | KING)) || (board[8*(y+1)+(x+2)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x+2)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x+2)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x+2)] == (WHITE | ROOK)) || (board[8*(y+1)+(x+2)] == (WHITE | PAWN))) || (x+2 > 7) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x+2)] *= INDIC;
		}
		if(((board[8*(y+1)+(x-2)] == (WHITE | KING)) || (board[8*(y+1)+(x-2)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x-2)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x-2)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x-2)] == (WHITE | ROOK)) || (board[8*(y+1)+(x-2)] == (WHITE | PAWN))) || (x-2 < 0) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x-2)] *= INDIC;
		}
		if(((board[8*(y+2)+(x+1)] == (WHITE | KING)) || (board[8*(y+2)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y+2)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y+2)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y+2)+(x+1)] == (WHITE | ROOK)) || (board[8*(y+2)+(x+1)] == (WHITE | PAWN))) || (x+1 > 7) || (y+2 > 7)){
		} else {
			board[8*(y+2)+(x+1)] *= INDIC;
		}
		if(((board[8*(y+2)+(x-1)] == (WHITE | KING)) || (board[8*(y+2)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y+2)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y+2)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y+2)+(x-1)] == (WHITE | ROOK)) || (board[8*(y+2)+(x-1)] == (WHITE | PAWN))) || (x-1 < 0) || (y+2 > 7)){
		} else {
			board[8*(y+2)+(x-1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x+2)] == (WHITE | KING)) || (board[8*(y-1)+(x+2)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x+2)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x+2)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x+2)] == (WHITE | ROOK)) || (board[8*(y-1)+(x+2)] == (WHITE | PAWN))) || (x+2 > 7) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x+2)] *= INDIC;
		}
		if(((board[8*(y-1)+(x-2)] == (WHITE | KING)) || (board[8*(y-1)+(x-2)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x-2)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x-2)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x-2)] == (WHITE | ROOK)) || (board[8*(y-1)+(x-2)] == (WHITE | PAWN))) || (x-2 < 0) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x-2)] *= INDIC;
		}
		if(((board[8*(y-2)+(x+1)] == (WHITE | KING)) || (board[8*(y-2)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y-2)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y-2)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y-2)+(x+1)] == (WHITE | ROOK)) || (board[8*(y-2)+(x+1)] == (WHITE | PAWN))) || (x+1 > 7) || (y-2 < 0)){
		} else {
			board[8*(y-2)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-2)+(x-1)] == (WHITE | KING)) || (board[8*(y-2)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y-2)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y-2)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y-2)+(x-1)] == (WHITE | ROOK)) || (board[8*(y-2)+(x-1)] == (WHITE | PAWN))) || (x-1 < 0) || (y-2 < 0)){
		} else {
			board[8*(y-2)+(x-1)] *= INDIC;
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | KING)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y+1)+(x)] == (WHITE | KING)) || (board[8*(y+1)+(x)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x)] == (WHITE | ROOK)) || (board[8*(y+1)+(x)] == (WHITE | PAWN))) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x)] *= INDIC;
		}
		if(((board[8*(y+1)+(x-1)] == (WHITE | KING)) || (board[8*(y+1)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x-1)] == (WHITE | ROOK)) || (board[8*(y+1)+(x-1)] == (WHITE | PAWN))) || (x-1 < 0) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x-1)] *= INDIC;
		}
		if(((board[8*(y+1)+(x+1)] == (WHITE | KING)) || (board[8*(y+1)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y+1)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y+1)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y+1)+(x+1)] == (WHITE | ROOK)) || (board[8*(y+1)+(x+1)] == (WHITE | PAWN))) || (x+1 > 7) || (y+1 > 7)){
		} else {
			board[8*(y+1)+(x+1)] *= INDIC;
		}
		if(((board[8*(y)+(x-1)] == (WHITE | KING)) || (board[8*(y)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y)+(x-1)] == (WHITE | ROOK)) || (board[8*(y)+(x-1)] == (WHITE | PAWN))) || (x-1 < 0)){
		} else {
			board[8*(y)+(x-1)] *= INDIC;
		}
		if(((board[8*(y)+(x+1)] == (WHITE | KING)) || (board[8*(y)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y)+(x+1)] == (WHITE | ROOK)) || (board[8*(y)+(x+1)] == (WHITE | PAWN))) || (x+1 > 7)){
		} else {
			board[8*(y)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x-1)] == (WHITE | KING)) || (board[8*(y-1)+(x-1)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x-1)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x-1)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x-1)] == (WHITE | ROOK)) || (board[8*(y-1)+(x-1)] == (WHITE | PAWN))) || (x-1 < 0) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x-1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x+1)] == (WHITE | KING)) || (board[8*(y-1)+(x+1)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x+1)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x+1)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x+1)] == (WHITE | ROOK)) || (board[8*(y-1)+(x+1)] == (WHITE | PAWN))) || (x+1 > 7) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x+1)] *= INDIC;
		}
		if(((board[8*(y-1)+(x)] == (WHITE | KING)) || (board[8*(y-1)+(x)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x)] == (WHITE | ROOK)) || (board[8*(y-1)+(x)] == (WHITE | PAWN))) || (y-1 < 0)){
		} else {
			board[8*(y-1)+(x)] *= INDIC;
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | QUEEN)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y)+(x+i)] == (WHITE | KING)) || (board[8*(y)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x+i)] == (WHITE | ROOK)) || (board[8*(y)+(x+i)] == (WHITE | PAWN))) || (x+i > 7)){
						break;
					}
					if ((board[8*(y)+(x+i)] == (BLACK | KING)) || (board[8*(y)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x+i)] == (BLACK | ROOK)) || (board[8*(y)+(x+i)] == (BLACK | PAWN)) || (x+i > 7)){
						board[8*(y)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y)+(x-i)] == (WHITE | KING)) || (board[8*(y)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y)+(x-i)] == (WHITE | ROOK)) || (board[8*(y)+(x-i)] == (WHITE | PAWN))) || (x-i < 0)){
						break;
					}
					if ((board[8*(y)+(x-i)] == (BLACK | KING)) || (board[8*(y)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y)+(x-i)] == (BLACK | ROOK)) || (board[8*(y)+(x-i)] == (BLACK | PAWN)) || (x-i < 0)){
						board[8*(y)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y+i)+(x)] == (WHITE | KING)) || (board[8*(y+i)+(x)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x)] == (WHITE | ROOK)) || (board[8*(y+i)+(x)] == (WHITE | PAWN))) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x)] == (BLACK | KING)) || (board[8*(y+i)+(x)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x)] == (BLACK | ROOK)) || (board[8*(y+i)+(x)] == (BLACK | PAWN)) || (y+i > 7)){
						board[8*(y+i)+(x)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x)] == (WHITE | KING)) || (board[8*(y-i)+(x)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x)] == (WHITE | ROOK)) || (board[8*(y-i)+(x)] == (WHITE | PAWN))) || (y-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x)] == (BLACK | KING)) || (board[8*(y-i)+(x)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x)] == (BLACK | ROOK)) || (board[8*(y-i)+(x)] == (BLACK | PAWN)) || (y-i < 0)){
						board[8*(y-i)+(x)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x)] *= INDIC;
				}
			}
		}
		for(int j = 0;j < 4;j++){
			for (int i = 1;i < 9;i++){
				if(j == 0){
					if(((board[8*(y+i)+(x+i)] == (WHITE | KING)) || (board[8*(y+i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x+i)] == (WHITE | PAWN))) || (x+i > 7) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x+i)] == (BLACK | KING)) || (board[8*(y+i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x+i)] == (BLACK | PAWN)) || (x+i > 7) || (y+i > 7)){
						board[8*(y+i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x+i)] *= INDIC;
				}
				if(j == 1){
					if(((board[8*(y+i)+(x-i)] == (WHITE | KING)) || (board[8*(y+i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y+i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y+i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y+i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y+i)+(x-i)] == (WHITE | PAWN))) || (x-i < 0) || (y+i > 7)){
						break;
					}
					if ((board[8*(y+i)+(x-i)] == (BLACK | KING)) || (board[8*(y+i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y+i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y+i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y+i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y+i)+(x-i)] == (BLACK | PAWN)) || (x-i < 0) || (y+i > 7)){
						board[8*(y+i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y+i)+(x-i)] *= INDIC;
				}
				if(j == 2){
					if(((board[8*(y-i)+(x+i)] == (WHITE | KING)) || (board[8*(y-i)+(x+i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x+i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x+i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x+i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x+i)] == (WHITE | PAWN))) || (y-i < 0) || (x+i>7)){
						break;
					}
					if ((board[8*(y-i)+(x+i)] == (BLACK | KING)) || (board[8*(y-i)+(x+i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x+i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x+i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x+i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x+i)] == (BLACK | PAWN)) || (y-i < 0) || (x+i > 7)){
						board[8*(y-i)+(x+i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x+i)] *= INDIC;
				}
				if(j == 3){
					if(((board[8*(y-i)+(x-i)] == (WHITE | KING)) || (board[8*(y-i)+(x-i)] == (WHITE | QUEEN)) || (board[8*(y-i)+(x-i)] == (WHITE | BISHOP)) || (board[8*(y-i)+(x-i)] == (WHITE | KNIGHT)) || (board[8*(y-i)+(x-i)] == (WHITE | ROOK)) || (board[8*(y-i)+(x-i)] == (WHITE | PAWN))) || (y-i < 0) || (x-i < 0)){
						break;
					}
					if ((board[8*(y-i)+(x-i)] == (BLACK | KING)) || (board[8*(y-i)+(x-i)] == (BLACK | QUEEN)) || (board[8*(y-i)+(x-i)] == (BLACK | BISHOP)) || (board[8*(y-i)+(x-i)] == (BLACK | KNIGHT)) || (board[8*(y-i)+(x-i)] == (BLACK | ROOK)) || (board[8*(y-i)+(x-i)] == (BLACK | PAWN)) || (y-i < 0) || (x-i < 0)){
						board[8*(y-i)+(x-i)] *= INDIC;
						break;
					}
					board[8*(y-i)+(x-i)] *= INDIC;
				}
			}
		}
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | PAWN)){
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		if(((board[8*(y-1)+(x-1)] == (BLACK | KING)) || (board[8*(y-1)+(x-1)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x-1)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x-1)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x-1)] == (BLACK | ROOK)) || (board[8*(y-1)+(x-1)] == (BLACK | PAWN))) && ((x-1 > 0) && (y-1 > 0))){
			board[8*(y-1)+(x-1)] *= INDIC;
		} else {
		}
		if(((board[8*(y-1)+(x+1)] == (BLACK | KING)) || (board[8*(y-1)+(x+1)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x+1)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x+1)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x+1)] == (BLACK | ROOK)) || (board[8*(y-1)+(x+1)] == (BLACK | PAWN))) && ((x+1 < 7) && (y-1 > 0))){
			board[8*(y-1)+(x+1)] *= INDIC;
		} else {
		}
		if(((board[8*(y-1)+(x)] == (WHITE | KING)) || (board[8*(y-1)+(x)] == (WHITE | QUEEN)) || (board[8*(y-1)+(x)] == (WHITE | BISHOP)) || (board[8*(y-1)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-1)+(x)] == (WHITE | ROOK)) || (board[8*(y-1)+(x)] == (WHITE | PAWN))) || (y-1 < 0) || ((board[8*(y-1)+(x)] == (BLACK | KING)) || (board[8*(y-1)+(x)] == (BLACK | QUEEN)) || (board[8*(y-1)+(x)] == (BLACK | BISHOP)) || (board[8*(y-1)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-1)+(x)] == (BLACK | ROOK)) || (board[8*(y-1)+(x)] == (BLACK | PAWN)))){
		} else {
			board[8*(y-1)+(x)] *= INDIC;
			if(((board[8*(y-2)+(x)] == (WHITE | KING)) || (board[8*(y-2)+(x)] == (WHITE | QUEEN)) || (board[8*(y-2)+(x)] == (WHITE | BISHOP)) || (board[8*(y-2)+(x)] == (WHITE | KNIGHT)) || (board[8*(y-2)+(x)] == (WHITE | ROOK)) || (board[8*(y-2)+(x)] == (WHITE | PAWN))) || (y-2 < 0) || ((board[8*(y-2)+(x)] == (BLACK | KING)) || (board[8*(y-2)+(x)] == (BLACK | QUEEN)) || (board[8*(y-2)+(x)] == (BLACK | BISHOP)) || (board[8*(y-2)+(x)] == (BLACK | KNIGHT)) || (board[8*(y-2)+(x)] == (BLACK | ROOK)) || (board[8*(y-2)+(x)] == (BLACK | PAWN)))){
			} else {
				if(y == 6){
					board[8*(y-2)+(x)] *= INDIC;
				}
			}
		}
	}
	selectedcell = 8*y + x;
	switcher = 1;
	} else {
		switcher = 0;
		for (int k = 0;k<64;k++){
			board[k] = abs(board[k]);
		}
	} 
	return 0;
}

int piecemove(){
	int x,y;
	x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
	y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
	fflush(stdout);
	if(switcher == 1 && board[8*y+(x)] < 0){
		board[(8*y)+x] = board[selectedcell];
		board[selectedcell] = NONE;
		for (int k = 0;k<64;k++){
			board[k] = abs(board[k]);
		}
	}
	return 0;
}

// PERFECT FUNCTIONS

int boardupdate(){
	int x = 0;
	int y = 0;
	drawboard();
	for(int i = 0;i < 64;i++){
		drawpiece(board[i],x,y);
		x = x + 1;
		if(x >= 8){
			x = 0;
			y = y + 1;
		}
	}
	return 0;
}


int pxtocell(int x,int y){
	if(x < 44 && x > 0){
		xx = 0;
	}
	if(x < 88 && x > 44){
		xx = 1;
	}
	if(x < 132 && x > 88){
		xx = 2;
	}
	if(x < 176 && x > 132){
		xx = 3;
	}
	if(x < 220 && x > 176){
		xx = 4;
	}
	if(x < 264 && x > 220){
		xx = 5;
	}
	if(x < 308 && x > 264){
		xx = 6;
	}
	if(x < 352 && x > 308){
		xx = 7;
	}
	if(y < 44 && y > 0){
		yy = 0;
	}
	if(y < 88 && y > 44){
		yy = 1;
	}
	if(y < 132 && y > 88){
		yy = 2;
	}
	if(y < 176 && y > 132){
		yy = 3;
	}
	if(y < 220 && y > 176){
		yy = 4;
	}
	if(y < 264 && y > 220){
		yy = 5;
	}
	if(y < 308 && y > 264){
		yy = 6;
	}
	if(y < 352 && y > 308){
		yy = 7;
	}
	return ((yy*8)+xx);
}

int drawpiece(int piecechoice,int x,int y){
	ALLEGRO_BITMAP *piece = NULL;
	if(piecechoice < 0){
        piece = al_load_bitmap("sprites/indicator.jpg");
        al_draw_bitmap(piece,(x*44),(y*44),0);
        al_destroy_bitmap(piece);
        }
	if(abs(piecechoice) == (WHITE | QUEEN)){
		piece = al_load_bitmap("sprites/whitequeen.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (WHITE | KING)){
		piece = al_load_bitmap("sprites/whiteking.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (WHITE | ROOK)){
		piece = al_load_bitmap("sprites/whiterook.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (WHITE | KNIGHT)){
		piece = al_load_bitmap("sprites/whiteknight.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (WHITE | BISHOP)){
		piece = al_load_bitmap("sprites/whitebishop.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (WHITE | PAWN)){
		piece = al_load_bitmap("sprites/whitepawn.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | PAWN)){
		piece = al_load_bitmap("sprites/blackpawn.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | QUEEN)){
		piece = al_load_bitmap("sprites/blackqueen.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | KING)){
		piece = al_load_bitmap("sprites/blackking.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | KNIGHT)){
		piece = al_load_bitmap("sprites/blackknight.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | BISHOP)){
		piece = al_load_bitmap("sprites/blackbishop.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(abs(piecechoice) == (BLACK | ROOK)){
		piece = al_load_bitmap("sprites/blackrook.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	return 0;
}

int drawboard(){
	ALLEGRO_BITMAP *background = NULL;
	background = al_load_bitmap("chessboard-empty.png");
	al_draw_bitmap(background,0,0,0);
	al_destroy_bitmap(background);
	return 0;
}

int allegroinit(){
	if(!al_init()) {
        	fprintf(stderr, "failed to initialize allegro!\n");
        	return -1;
	}
	al_init_image_addon();
	al_install_mouse();
	display = al_create_display(352,352);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	drawboard();
	for(int i = 0;i < 64;i++){
		board[i] = (NONE);
	}
	return 0;
}

int fenparser(char *fenstring){
	int i = 0;
	int x = 0;
	int y = 0;
	while(1){
		if(fenstring[i] == '\0'){
			return 0;
		}
		if(fenstring[i] == '1'){
			x = x + 1;
		}
		if(fenstring[i] == '2'){
			x = x + 2;
		}
		if(fenstring[i] == '3'){
			x = x + 3;
		}
		if(fenstring[i] == '4'){
			x = x + 4;
		}
		if(fenstring[i] == '5'){
			x = x + 5;
		}
		if(fenstring[i] == '6'){
			x = x + 6;
		}
		if(fenstring[i] == '7'){
			x = x + 7;
		}
		if(fenstring[i] == '8'){
			x = 0;
		}
		if(fenstring[i] == '/'){
			y = y + 1;
			x = 0;
		}
		if(fenstring[i] == 'k'){
			drawpiece((BLACK | KING),x,y);
			board[(y*8)+x] = (BLACK | KING);
			x = x + 1;
		}
		if(fenstring[i] == 'q'){
			drawpiece((BLACK | QUEEN),x,y);
			board[(y*8)+x] = (BLACK | QUEEN);
			x = x + 1;
		}
		if(fenstring[i] == 'r'){
			drawpiece((BLACK | ROOK),x,y);
			board[(y*8)+x] = (BLACK | ROOK);
			x = x + 1;
		}
		if(fenstring[i] == 'n'){
			drawpiece((BLACK | KNIGHT),x,y);
			board[(y*8)+x] = (BLACK | KNIGHT);
			x = x + 1;
		}
		if(fenstring[i] == 'b'){
			drawpiece((BLACK | BISHOP),x,y);
			board[(y*8)+x] = (BLACK | BISHOP);
			x = x + 1;
		}
		if(fenstring[i] == 'p'){
			drawpiece((BLACK | PAWN),x,y);
			board[(y*8)+x] = (BLACK | PAWN);
			x = x + 1;
		}
		if(fenstring[i] == 'K'){
			drawpiece((WHITE | KING),x,y);
			board[(y*8)+x] = (WHITE | KING);
			x = x + 1;
		}
		if(fenstring[i] == 'Q'){
			drawpiece((WHITE | QUEEN),x,y);
			board[(y*8)+x] = (WHITE | QUEEN);
			x = x + 1;
		}
		if(fenstring[i] == 'R'){
			drawpiece((WHITE | ROOK),x,y);
			board[(y*8)+x] = (WHITE | ROOK);
			x = x + 1;
		}
		if(fenstring[i] == 'N'){
			drawpiece((WHITE | KNIGHT),x,y);
			board[(y*8)+x] = (WHITE | KNIGHT);
			x = x + 1;
		}
		if(fenstring[i] == 'B'){
			drawpiece((WHITE | BISHOP),x,y);
			board[(y*8)+x] = (WHITE | BISHOP);
			x = x + 1;
		}
		if(fenstring[i] == 'P'){
			drawpiece((WHITE | PAWN),x,y);
			board[(y*8)+x] = (WHITE | PAWN);
			x = x + 1;
		}
		i++;
	}
	return 0;
}