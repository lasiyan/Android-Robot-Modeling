#pragma once
#include "AndroidBot_Main.h"

extern GLfloat R_Arm_x; // ������ ���
extern GLfloat R_Arm_y; // ������ ��
extern GLfloat L_Arm_x; // ���� ���
extern GLfloat L_Arm_y; // ���� ��
extern GLfloat R_Leg_x; // ���� �����
extern GLfloat R_Leg_y; // ���� ���Ƹ�
extern GLfloat L_Leg_x; // �� �����
extern GLfloat L_Leg_y; // �� ���Ƹ�
extern GLfloat R1;		 // ���� ���� ��ġ ������ ����
extern GLfloat R2;		// ������ ���� ��ġ ������ ����

extern double time1; // Run_time ����
extern double time2; // Jap_time ����
extern double time3; // Rocket_time ����
extern double time4; // ground_time ����
extern double time5; // exit_time ����

extern GLUquadricObj* cyl;// �Ǹ��� ��ü ����

void Run();
void Jap();
void ex();
void Show();
void Rocket();
void MyTimer(int);