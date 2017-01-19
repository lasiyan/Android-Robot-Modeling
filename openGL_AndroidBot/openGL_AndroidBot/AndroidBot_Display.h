#pragma once
#include "AndroidBot_Main.h"

void MyKeyboard(unsigned char, int, int);
void MyDisplay();
void MyMainMenu(int);

extern int flag; // wireframe 모드와 solid rendering 모드 구분 변수
extern int key;  // 동작 모드와 색상 변경 변수

#define RUN		1					
#define JAP		2							
#define ROCKET	3	
#define SKATE	4	
#define EXIT	6	
