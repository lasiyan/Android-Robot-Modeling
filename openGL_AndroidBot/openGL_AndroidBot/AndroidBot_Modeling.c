#include"AndroidBot_Modeling.h"

#define RUN		1					
#define JAP		2							
#define ROCKET	3	
#define SKATE	4	
#define EXIT	6	

int flag = 0; // wireframe 모드와 solid rendering 모드 구분 변수
int key = 0;  // 동작 모드와 색상 변경 변수

GLfloat R_Arm_x = 0; // 오른쪽 어깨
GLfloat R_Arm_y = 0; // 오른쪽 팔
GLfloat L_Arm_x = 0; // 왼쪽 어깨
GLfloat L_Arm_y = 0; // 왼쪽 팔
GLfloat R_Leg_x = 0; // 오른 허벅지
GLfloat R_Leg_y = 0; // 오른 종아리
GLfloat L_Leg_x = 0; // 왼 허벅지
GLfloat L_Leg_y = 0; // 왼 종아리
GLfloat R1 = 0;		 // 왼쪽 로켓 펀치 움직임 변수
GLfloat R2 = 0;		// 오른쪽 로켓 펀치 움직임 변수

static double time1 = 0; // Run_time 변수
static double time2 = 0; // Jap_time 변수
static double time3 = 0; // Rocket_time 변수
static double time4 = 0; // ground_time 변수
static double time5 = 0; // exit_time 변수

GLUquadricObj* cyl;// 실린더 객체 선언

void glInit(void) {			 // 지엘 초기화 함수 
	glEnable(GL_DEPTH_TEST); // 깊이 테스팅 사용
	glEnable(GL_NORMALIZE);  // 정규화
	glEnable(GL_SMOOTH);     // 각 정점의 색상을 부드럽게 연결하여 칠해지도록  하므로, 각정점에 적용된 색상이 혼합되어 적용된다. 
	glEnable(GL_LIGHTING);   // 지엘 조명. 빛을 받는 각도에 따라 로봇 색상이 변화

							 /* 빛을 받는 각도에 따라 로봇 색깔의 변화를 위한 설정 */
	GLfloat ambientLight[] = { 0.3f,0.3f,0.3f,1.0f };
	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
	GLfloat specular[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat specref[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat position[] = { 400.0,300.0,-700.0,1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);   // 모드 설정
	glLoadIdentity();              // CTM 값 초기화 
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시 범위 설정
}

void Draw_Color(int i) { // 색상을 그리는 함수
	if (i == RUN) {
		glColor3f(0.7, 0.2, 0.3);	// 연한빨강
	}
	else if (i == JAP) {
		glColor3f(0.8, 0.8, 0.3);	// 노랑색
	}
	else if (i == ROCKET) {
		glColor3f(0.3, 0.7, 0.2);	// 연두색
	}
	else if (i == SKATE) {
		glColor3f(0.4, 0.5, 0.8);	// 하늘색
	}
	else if (i == EXIT) {
		glColor3f(0.2, 0.2, 0.2);
	}
}

void Change_Wire_Or_Solid(int i) {          // 솔리드, 와이어 선택
	if (flag == 1)
		gluQuadricDrawStyle(cyl, GLU_LINE); // 스타일을 와이어로 변경
}

/* 로봇 왼팔을 그리는 함수 */
void DrawL_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				// 색 설정
	cyl = gluNewQuadric();			// 실린더 객체 생성
	glRotatef(x, a, b, c);			// 파라미터 값만큼 회전
	glRotatef(90.0, 1.0, 0.0, 0.0); // 실린더를 x축 기준으로 90도 회전(실린더 생성 시 각도 변경을 위해)
	glTranslatef(0.25, 0.0, 0.0);   // 왼쪽 어깨 시작점으로 이동
	glRotatef(15.0, 0.0, 1.0, 0.0); // 왼쪽 어깨를 y축을 기준으로 15도 회전
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	// 실린더를 그림
}

/* 로봇 왼쪽 손을 그리는 함수 */
void DrawL_Hand(int y, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				 // 색 설정
	cyl = gluNewQuadric();			 // 실린더 객체 생성
	glTranslatef(0.0, 0.0, 0.22);	 // 왼손 시작점
	glRotatef(y, a, b, c);			 // 파라미터 값만큼 회전
	Change_Wire_Or_Solid(flag);
	if (key == SKATE) gluCylinder(cyl, 0.05, 0.02, 0.2, 15, 1); // 깔때기 모양 실린더를 그림
	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);
	glPopMatrix();
}

/* 로봇 왼쪽 로켓*/
void DrawL_HandRocket() {
	glPushMatrix();
	glColor3f(0.9, 0.35, 0.35);		 // 색 설정
	cyl = gluNewQuadric();			 // 실린더 객체 생성
	glTranslatef(0, 0, R1);			 // 왼쪽 주먹 위치를 파라미터만큼 이동
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* 로봇 오른팔을 그리는 함수 */
void DrawR_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				 // 색 설정
	cyl = gluNewQuadric();			 // 실린더 객체 생성
	glRotatef(x, a, b, c);			 // 파라미터 값만큼 회전
	glRotatef(90.0, 1.0, 0.0, 0.0);	 // 실린더를 x축을 기준으로 90도 회전(실린더 생성 시 각도 변경을 위해)
	glTranslatef(-0.25, 0.0, 0.0);	 // 오른팔 시작점으로 이동
	glRotatef(-15.0, 0.0, 1.0, 0.0); // 오른팔 -15도 y축기준 회전
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);

}

/* 로봇 오른쪽 손을 그리는 함수*/
void DrawR_Hand(int y, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.22);
	glRotatef(y, a, b, c);
	Change_Wire_Or_Solid(flag);
	if (key == SKATE) gluCylinder(cyl, 0.05, 0.02, 0.2, 50, 1);
	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* 로봇 오른쪽 로켓트 함수 */
void DrawR_HandRocket() {
	glPushMatrix();
	glColor3f(0.9, 0.1, 0.1);
	cyl = gluNewQuadric();
	glTranslatef(0, 0, R2);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* 로봇 몸체를 그리는 함수 */
void DrawBody(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);			// 실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
	glRotatef(x, a, b, c);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.2, 0.2, 0.45, 50, 1);
	glPopMatrix();
}

/* 로봇 왼쪽 허벅지를 그리는 함수 */
void DrawL_Legs(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);			// 실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
	glTranslatef(0.1, 0.0, 0.42);
	glRotatef(x, a, b, c);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);

}

/* 로봇 왼쪽 종아리를 그리는 함수 */
void DrawL_foot(int y, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef(y, a, b, c);
	Change_Wire_Or_Solid(flag);
	if (key == SKATE) gluCylinder(cyl, 0.05, 0.03, 0.2, 50, 1);
	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* 로봇 오른쪽 허벅지를 그리는 함수 */
void DrawR_Legs(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.1, 0.0, 0.42);
	glRotatef(x, a, b, c);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);

}

/* 로봇 오른쪽 종아리를 그리는 함수 */
void DrawR_foot(int y, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();

	glTranslatef(0.0, 0.0, 0.18);
	glRotatef(y, a, b, c);

	Change_Wire_Or_Solid(flag);
	if (key == SKATE) gluCylinder(cyl, 0.05, 0.03, 0.2, 15, 1);
	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);
	glPopMatrix();
}

/* 로봇 목을 그리는 함수 */
void Drawneck() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);				 // 흰색
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -0.045);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.2, 0.2, 0.025, 100, 1);
	glPopMatrix();
}

/* 지면을 그리는 함수, 이는 커다란 구로 설정하였으며
지면이 시간에 따라 회전하여 마치 로봇이 앞으로 뛰어가는 느낌이 들도록 함 */
void DrawGround() {
	Draw_Color(flag);						 // 색깔 설정
	glTranslatef(0.0, -2.73, 0.0);			 // 땅 시작점
	glRotatef(45.0, 0, 1, 0);				 // 45도만큼 y축 방향으로 회전
	glRotatef(0.0 + time4 - 15, 0.0, 0.0, 1);// z축 기준으로 time4만큼 땅이 회전 
	Change_Wire_Or_Solid(flag);
	gluSphere(cyl, 2.5, 30, 90);
}

/* 스케이트용 드로우 그라운드 */
void Draw_Skate_Ground() {
	glColor3f(0.85, 0.85, 0.99);
	glTranslatef(0.0, -2.73, 0.0);			 // 땅 시작점
	glRotatef(45.0, 0, 1, 0);				 // 45도만큼 y축 방향으로 회전
	glRotatef(0.0 + time4 - 15, 0.0, 0.0, 1);// z축 기준으로 time4만큼 땅이 회전 
	Change_Wire_Or_Solid(flag);
	gluSphere(cyl, 2.5, 30, 90);
}

/* 로봇 머리를 그리는 함수
머리에 달려있는 뿔과 로봇의 눈을 설정하였다. */
void DrawHead() {
	glTranslatef(0.0, 0.02, 0.0);
	glPushMatrix();							 // 처음 저장 좌표 다시 저장
	cyl = gluNewQuadric();
	Change_Wire_Or_Solid(flag);
	Draw_Color(key);						 // 색깔 설정
	gluSphere(cyl, 0.20, 30, 10);			 // 머리 그리기

											 /*왼쪽 뿔 그리기*/
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.16, 0.0, -0.22);
	glRotatef(35.0, 0.0, 1.0, 0.0);			  // 35도 y축 기준 회전
	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);// 실린더 그림
	glPopMatrix();							  // 처음 저장 좌표로 돌아 간다.
	glPushMatrix();							  // 처음 저장 좌표 다시 저장

											  /*오른쪽 뿔 그리기*/
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.16, 0.0, -0.22);
	glRotatef(-35.0, 0.0, 1.0, 0.0);		  // -35도 y축 기준 회전
	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);// 실린더 그림
	glPopMatrix();							  // 처음 저장 좌표로 돌아 간다.	
	glPushMatrix();							  // 처음 저장 좌표 다시 저장

											  /*왼쪽 눈 그리기*/
	glTranslatef(-0.1, 0.1, 0.13);
	glColor3f(0.0, 0.0, 0.0);				  // 눈 컬러 설정(흑색)
	gluSphere(cyl, 0.03, 10, 10);

	glPopMatrix();							  // 처음 저장 좌표로 돌아 간다.
	glPushMatrix();							  // 처음 저장 좌표 다시 저장

											  /*오른쪽 눈 그리기*/
	glTranslatef(0.1, 0.1, 0.13);
	gluSphere(cyl, 0.03, 10, 10);
	glPopMatrix();							  // 처음 저장 좌표 다시 저장
}

/* 로봇 전체 모습을 그리는 함수 */
void DrawAndroid() {
	DrawBody(0, 0, 0, 0);					  // 몸통 함수 호출
	Drawneck();								  // 목함수 호출
	DrawHead();								  // 머리 호출
	DrawR_Arm(R_Arm_x, 1, 0, 0);			  // 오른팔
	if (key == ROCKET) DrawR_HandRocket();	  // 로켓모드일때 우측로켓호출
	else DrawR_Hand(R_Arm_y, 1, 0, 0);		  // 오른손
	DrawL_Arm(L_Arm_x, 1, 0, 0);			  // 왼팔
	if (key == ROCKET) DrawL_HandRocket();	  // 로켓모드일때 우측로켓호출
	else DrawL_Hand(L_Arm_y, 1, 0, 0);		  // 왼 손
	DrawL_Legs(L_Leg_x, 1, 0, 0);			  // 왼쪽 다리
	DrawL_foot(L_Leg_y, 1, 0, 0);			  // 왼쪽 발		 
	DrawR_Legs(R_Leg_x, 1, 0, 0);			  // 오른쪽 다리
	DrawR_foot(R_Leg_y, 1, 0, 0);			  // 오른쪽 발	
}