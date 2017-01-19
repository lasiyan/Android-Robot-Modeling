#pragma once
#include "AndroidBot_Main.h"

extern GLfloat R_Arm_x; // 오른쪽 어깨
extern GLfloat R_Arm_y; // 오른쪽 팔
extern GLfloat L_Arm_x; // 왼쪽 어깨
extern GLfloat L_Arm_y; // 왼쪽 팔
extern GLfloat R_Leg_x; // 오른 허벅지
extern GLfloat R_Leg_y; // 오른 종아리
extern GLfloat L_Leg_x; // 왼 허벅지
extern GLfloat L_Leg_y; // 왼 종아리
extern GLfloat R1;		 // 왼쪽 로켓 펀치 움직임 변수
extern GLfloat R2;		// 오른쪽 로켓 펀치 움직임 변수

extern double time1; // Run_time 변수
extern double time2; // Jap_time 변수
extern double time3; // Rocket_time 변수
extern double time4; // ground_time 변수
extern double time5; // exit_time 변수

extern GLUquadricObj* cyl;// 실린더 객체 선언

void Run();
void Jap();
void ex();
void Show();
void Rocket();
void MyTimer(int);