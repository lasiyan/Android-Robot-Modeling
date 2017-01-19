#include"AndroidBot_Activity.h"

/* 로봇이 달리는 것을 표현한 함수. 로봇의 관절이 움직이는 것을 표현했고,
로봇이 달리면서 상,하,좌,우로 움직이는 모습을 표현함. 기본적인 로봇 움직임의 가속도는
sin()함수를 통해서 표현하였으며, 관절 움직임의 제한 범위를 생각하여
abs()함수(= 절대값 계산)를 통해 관절의 움직임을 제한함 */

double time1; // Run_time 변수
double time2; // Jap_time 변수
double time3; // Rocket_time 변수
double time4; // ground_time 변수
double time5; // exit_time 변수

void Run() {
	sndPlaySound(TEXT("Run.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();//CTM 초기화
	L_Arm_x = sin(time1) * 40;				// 왼팔은 40도 각도까지 움직이되 sin()함수를 사용하여 주기적인 움직임 설정
	R_Arm_x = -L_Arm_x;						// 오른팔은 왼팔반대로 40도각도까지
	R_Arm_y = -abs(sin(time1) * 60 + 50);	// 오른팔 각도조절
	L_Arm_y = -abs(-sin(time1) * 60 + 50);	// 왼팔 각도조절
	R_Leg_y = abs(-sin(time1) * 30 - 30);	// 오른쪽 종아리 각도조절
	L_Leg_y = abs(sin(time1) * 30 - 30);    // 왼쪽 종아리 각도조절
	R_Leg_x = sin(time1) * 50;				// 오른쪽 다리는 50도 각도까지
	L_Leg_x = -R_Leg_x;						// 왼쪽 다리는 우측다리반대로

	cyl = gluNewQuadric();								// 실린더 객체 생성
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 초기화
	glMatrixMode(GL_MODELVIEW);							// 모드 설정

	DrawGround();										// 지면 호출
	glLoadIdentity();									// CTM 초기화

														/* 로봇이 달리면서 앞,뒤로 뒤뚱거리고 몸이 틀어지는 것을 표현	*/
	glRotatef(-230.0, 0, 1, 0);					// y축을 기준으로 회전
	glRotatef(abs(sin(time1) * 16), 1, 0, 0);	// x축을 기준으로 16도까지 각도가 틀어짐
	glRotatef(sin(time1) * 16, 0, 1, 0);		// y축을 기준으로 16도 까지 각도틀어짐. sin()

												/* 로봇이 달리면서 상,하로 움직이는 것을 표현 */
	float i = 0;
	i = abs(sin(time1)*0.08);					// i변수값 설정
	glPushMatrix();								// 최초 저장 좌표계 다시 저장
	glTranslatef(0.0, i, 0);					// 로봇의 몸체가 y축 방향으로 변수 i만큼 이동
	glTranslatef(0.0, 0.5, 0.0);				// 최초 위치 
	DrawAndroid();
	glutSwapBuffers();
}

/* 로봇이 잽을 날리는 것을 표현한 함수 */
void Jap() {
	sndPlaySound(TEXT("Jap.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();
	L_Arm_x = (-40) + sin(time2) * 60;
	R_Arm_x = (-80) - L_Arm_x;
	R_Arm_y = -abs(cos(time2) * 80);
	L_Arm_y = -abs(-cos(time2) * 80);
	R_Leg_y = abs(-sin(time1) * 30 - 20);
	L_Leg_y = abs(sin(time1) * 30 - 20);
	R_Leg_x = sin(time1) * 30;
	L_Leg_x = -R_Leg_x;

	cyl = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //모드 설정

	DrawGround();
	glLoadIdentity();
	glRotatef(-230.0, 0, 1, 0);
	glRotatef(sin(time1) * 10, 0, 0, 1);

	/* 로봇이 잽을 날리면서 상,하로 움직이는 것을 표현 */
	float j = 0;
	j = abs(sin(time2)*0.085);						// j값 설정
	glPushMatrix();									// 최초 저장 좌표계 다시 저장
	glTranslatef(0.0, j, 0);						// 변수 j만큼 로봇의 몸체가 Y축기준으로 움직임.
	glTranslatef(0.0, 0.5, 0.0);					// 최초 위치 
	DrawAndroid();
	glutSwapBuffers();
}

/* 로봇이 퇴장할때 크기 변환을 표현한 함수 */
void ex()
{
	sndPlaySound(TEXT("exit.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();

	L_Arm_x = (-40) + sin(time2) * 60;
	R_Arm_x = (-80) - L_Arm_x;
	R_Arm_y = -abs(cos(time2) * 10);
	L_Arm_y = -abs(-cos(time2) * 10);
	R_Leg_y = abs(-sin(time1) * 30 - 30);
	L_Leg_y = abs(sin(time1) * 30 - 30);
	R_Leg_x = sin(time1) * 60;
	L_Leg_x = -R_Leg_x;

	cyl = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glRotatef(-180, 0, 1, 0);
	glRotatef(time5, 0, 0, 1);						// time5 변수만큼 z축기준으로 회전

	glScalef(0.4 / (sin(time3)), 0.4 / (sin(time3)), 0.4 / (sin(time3)));
	// 0.4의 크기에서 sin()를 사용하여 크기조절을 주기적으로 가함
	glPushMatrix();									// 처음 저장 좌표 다시 저장
													// 멀어지고 가까워지는듯한 느낌을 표현
	glTranslatef(0.0, 0.5, 0.0);					// 최초 위치 
	DrawAndroid();
	glutSwapBuffers();
}

/* 스케이팅 동작을 표현한 함수 */
void Show()
{
	sndPlaySound(TEXT("Skate.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();
	L_Arm_x = (-40) + sin(time2) * 60;
	R_Arm_x = (-80) - L_Arm_x;
	R_Arm_y = -abs(cos(time2) * 10);
	L_Arm_y = -abs(-cos(time2) * 10);
	R_Leg_y = abs(-sin(time1) * 30 - 30);
	L_Leg_y = abs(sin(time1) * 30 - 30);
	R_Leg_x = sin(time1) * 60;
	L_Leg_x = -R_Leg_x;

	cyl = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	Draw_Skate_Ground();							// 스케이트용 지면 호출 (빙판 색깔)
	glLoadIdentity();
	glRotatef(-230.0, 0, 1, 0);

	/* 몸통. 로봇이 피겨동작시 몸이 틀어지는 것을 표현 */
	glRotatef(sin(time1) * 5, 0, 0, 1);				// z축기준으로 5도 까지 각도틀어짐
	glRotatef(sin(time1) * 5, 0, 1, 0);				// y축으로 5도 까지 각도틀어짐

	glTranslatef(0.0, 0.18, 0.0);
	glRotatef(80, 1, 0, 0);
	glTranslatef(0.0, 0.5, 0.0);
	glPushMatrix();
	DrawBody(0, 0, 0, 0);							// 몸통 함수 호출
	glPopMatrix();
	glPushMatrix();

	Drawneck();										// 목함수 호출
	glPopMatrix();
	glPushMatrix();

	glRotatef(-75, 1, 0, 0);						// 머리
	glTranslatef(0.0, -0.02, 0.0);
	DrawHead();
	glPopMatrix();
	glPushMatrix();

	DrawR_Arm((R_Arm_y + 30), 1, 0, 0);				// 오른팔 그림
	DrawR_Hand(-(R_Arm_y - 15), 1, 0, 0);			// 오른손 그림
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.16, -0.04);
	glRotatef(40, 0, 0, 1);
	DrawL_Arm((L_Arm_y + 30), 1, 0, 0);				// 왼팔 그림
	DrawL_Hand(-(L_Arm_y - 15), 1, 0, 0);			// 왼손 그림
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.45, -0.25);
	glRotatef(-90, 1, 0, 0);
	DrawL_Legs(-15, 1, 0, 0);						// 왼쪽 다리
	DrawL_foot(5, 1, 0, 0);							// 왼쪽 종아리		 
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.5, -0.5);
	glRotatef(-90, 1, 0, 0);
	DrawR_Legs(160, 1, 0, 0);						// 오른쪽 다리
	DrawR_foot(R_Leg_y, 1, 0, 0);					// 오른쪽 종아리		
	glPopMatrix();
	glutSwapBuffers();								// 더블 버퍼링
}

/* 로봇이 로켓을 발사하는 모습을 표현한 함수 */
void Rocket() {
	sndPlaySound(TEXT("shoot.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();
	L_Arm_x = -90;									// 90도 각도로 팔을 앞으로 내민다
	R_Arm_x = -90;
	R1 = 2 * abs(-sin(time1) * 2 - 0.2) + 0.7;
	/*(위) 오른쪽 로켓 움직임 설정. 절대값을 사용해 로켓이 앞쪽으로 나가게 설정.
	+0.2를 통해 로켓의 최초 위치 조절. 2*를 통해 로켓이 나가는 거리 조절
	sin()함수를 통해 주기적인 움직임 설정*/

	R2 = 2 * abs(sin(time1) * 2 - 0.2) + 0.6;
	R_Leg_y = abs(-sin(time1) * 30 - 30);
	L_Leg_y = abs(sin(time1) * 30 - 30);
	R_Leg_x = sin(time1) * 60;
	L_Leg_x = -R_Leg_x;

	cyl = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	DrawGround();
	glLoadIdentity();
	glPushMatrix();
	glRotatef(-230.0, 0, 1, 0);

	/* 로봇이 로켓을 쏠 때 상,하,좌,우로 몸을 트는 모습을 설정 */
	glRotatef(-abs(sin(time1) * 10), 1, 0, 0);
	glRotatef(sin(time1) * 7, 0, 0, 1);

	/* 로봇이 로켓을 날리며 몸을 튕기는 모습을 표현 */
	float i = 0;
	i = abs(sin(time1)*0.08);
	glTranslatef(0.0, i, 0);
	glTranslatef(0.0, 0.5, 0.0);
	DrawAndroid();
	glutSwapBuffers();
}

/* 타이머 함수. 각 장면마다 상태 표현을 다르게 하기 위해 별도의 시간 변수를 사용함. */
void MyTimer(int Value) {
	time1 += 0.1;				// 달릴때 쓰인 타이머 변수
	time2 += 0.5;				// 잽을 날릴때 쓰인 타이머 변수
	time3 += 0.01;				// 로켓을 날릴때 쓰인 타이머 번수, 종료시 로봇이 뱅글뱅글 돌아가게 하기 위해 쓰인 타이머 변수
	time4 += 1.0;				// 피겨 동작을 취할 때 쓰인 타이머 변수
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}