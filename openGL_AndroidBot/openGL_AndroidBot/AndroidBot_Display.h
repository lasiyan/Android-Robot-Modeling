#pragma once
#include "AndroidBot_Main.h"

void MyKeyboard(unsigned char, int, int);
void MyDisplay();
void MyMainMenu(int);

extern int flag; // wireframe ���� solid rendering ��� ���� ����
extern int key;  // ���� ���� ���� ���� ����

#define RUN		1					
#define JAP		2							
#define ROCKET	3	
#define SKATE	4	
#define EXIT	6	
