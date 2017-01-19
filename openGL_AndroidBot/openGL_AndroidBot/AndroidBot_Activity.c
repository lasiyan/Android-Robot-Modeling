#include"AndroidBot_Activity.h"

/* �κ��� �޸��� ���� ǥ���� �Լ�. �κ��� ������ �����̴� ���� ǥ���߰�,
�κ��� �޸��鼭 ��,��,��,��� �����̴� ����� ǥ����. �⺻���� �κ� �������� ���ӵ���
sin()�Լ��� ���ؼ� ǥ���Ͽ�����, ���� �������� ���� ������ �����Ͽ�
abs()�Լ�(= ���밪 ���)�� ���� ������ �������� ������ */

double time1; // Run_time ����
double time2; // Jap_time ����
double time3; // Rocket_time ����
double time4; // ground_time ����
double time5; // exit_time ����

void Run() {
	sndPlaySound(TEXT("Run.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();//CTM �ʱ�ȭ
	L_Arm_x = sin(time1) * 40;				// ������ 40�� �������� �����̵� sin()�Լ��� ����Ͽ� �ֱ����� ������ ����
	R_Arm_x = -L_Arm_x;						// �������� ���ȹݴ�� 40����������
	R_Arm_y = -abs(sin(time1) * 60 + 50);	// ������ ��������
	L_Arm_y = -abs(-sin(time1) * 60 + 50);	// ���� ��������
	R_Leg_y = abs(-sin(time1) * 30 - 30);	// ������ ���Ƹ� ��������
	L_Leg_y = abs(sin(time1) * 30 - 30);    // ���� ���Ƹ� ��������
	R_Leg_x = sin(time1) * 50;				// ������ �ٸ��� 50�� ��������
	L_Leg_x = -R_Leg_x;						// ���� �ٸ��� �����ٸ��ݴ��

	cyl = gluNewQuadric();								// �Ǹ��� ��ü ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �ʱ�ȭ
	glMatrixMode(GL_MODELVIEW);							// ��� ����

	DrawGround();										// ���� ȣ��
	glLoadIdentity();									// CTM �ʱ�ȭ

														/* �κ��� �޸��鼭 ��,�ڷ� �ڶװŸ��� ���� Ʋ������ ���� ǥ��	*/
	glRotatef(-230.0, 0, 1, 0);					// y���� �������� ȸ��
	glRotatef(abs(sin(time1) * 16), 1, 0, 0);	// x���� �������� 16������ ������ Ʋ����
	glRotatef(sin(time1) * 16, 0, 1, 0);		// y���� �������� 16�� ���� ����Ʋ����. sin()

												/* �κ��� �޸��鼭 ��,�Ϸ� �����̴� ���� ǥ�� */
	float i = 0;
	i = abs(sin(time1)*0.08);					// i������ ����
	glPushMatrix();								// ���� ���� ��ǥ�� �ٽ� ����
	glTranslatef(0.0, i, 0);					// �κ��� ��ü�� y�� �������� ���� i��ŭ �̵�
	glTranslatef(0.0, 0.5, 0.0);				// ���� ��ġ 
	DrawAndroid();
	glutSwapBuffers();
}

/* �κ��� ���� ������ ���� ǥ���� �Լ� */
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
	glMatrixMode(GL_MODELVIEW); //��� ����

	DrawGround();
	glLoadIdentity();
	glRotatef(-230.0, 0, 1, 0);
	glRotatef(sin(time1) * 10, 0, 0, 1);

	/* �κ��� ���� �����鼭 ��,�Ϸ� �����̴� ���� ǥ�� */
	float j = 0;
	j = abs(sin(time2)*0.085);						// j�� ����
	glPushMatrix();									// ���� ���� ��ǥ�� �ٽ� ����
	glTranslatef(0.0, j, 0);						// ���� j��ŭ �κ��� ��ü�� Y��������� ������.
	glTranslatef(0.0, 0.5, 0.0);					// ���� ��ġ 
	DrawAndroid();
	glutSwapBuffers();
}

/* �κ��� �����Ҷ� ũ�� ��ȯ�� ǥ���� �Լ� */
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
	glRotatef(time5, 0, 0, 1);						// time5 ������ŭ z��������� ȸ��

	glScalef(0.4 / (sin(time3)), 0.4 / (sin(time3)), 0.4 / (sin(time3)));
	// 0.4�� ũ�⿡�� sin()�� ����Ͽ� ũ�������� �ֱ������� ����
	glPushMatrix();									// ó�� ���� ��ǥ �ٽ� ����
													// �־����� ��������µ��� ������ ǥ��
	glTranslatef(0.0, 0.5, 0.0);					// ���� ��ġ 
	DrawAndroid();
	glutSwapBuffers();
}

/* �������� ������ ǥ���� �Լ� */
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

	Draw_Skate_Ground();							// ������Ʈ�� ���� ȣ�� (���� ����)
	glLoadIdentity();
	glRotatef(-230.0, 0, 1, 0);

	/* ����. �κ��� �ǰܵ��۽� ���� Ʋ������ ���� ǥ�� */
	glRotatef(sin(time1) * 5, 0, 0, 1);				// z��������� 5�� ���� ����Ʋ����
	glRotatef(sin(time1) * 5, 0, 1, 0);				// y������ 5�� ���� ����Ʋ����

	glTranslatef(0.0, 0.18, 0.0);
	glRotatef(80, 1, 0, 0);
	glTranslatef(0.0, 0.5, 0.0);
	glPushMatrix();
	DrawBody(0, 0, 0, 0);							// ���� �Լ� ȣ��
	glPopMatrix();
	glPushMatrix();

	Drawneck();										// ���Լ� ȣ��
	glPopMatrix();
	glPushMatrix();

	glRotatef(-75, 1, 0, 0);						// �Ӹ�
	glTranslatef(0.0, -0.02, 0.0);
	DrawHead();
	glPopMatrix();
	glPushMatrix();

	DrawR_Arm((R_Arm_y + 30), 1, 0, 0);				// ������ �׸�
	DrawR_Hand(-(R_Arm_y - 15), 1, 0, 0);			// ������ �׸�
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.16, -0.04);
	glRotatef(40, 0, 0, 1);
	DrawL_Arm((L_Arm_y + 30), 1, 0, 0);				// ���� �׸�
	DrawL_Hand(-(L_Arm_y - 15), 1, 0, 0);			// �޼� �׸�
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.45, -0.25);
	glRotatef(-90, 1, 0, 0);
	DrawL_Legs(-15, 1, 0, 0);						// ���� �ٸ�
	DrawL_foot(5, 1, 0, 0);							// ���� ���Ƹ�		 
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -0.5, -0.5);
	glRotatef(-90, 1, 0, 0);
	DrawR_Legs(160, 1, 0, 0);						// ������ �ٸ�
	DrawR_foot(R_Leg_y, 1, 0, 0);					// ������ ���Ƹ�		
	glPopMatrix();
	glutSwapBuffers();								// ���� ���۸�
}

/* �κ��� ������ �߻��ϴ� ����� ǥ���� �Լ� */
void Rocket() {
	sndPlaySound(TEXT("shoot.wav"), SND_ASYNC | SND_NOSTOP);
	glLoadIdentity();
	L_Arm_x = -90;									// 90�� ������ ���� ������ ���δ�
	R_Arm_x = -90;
	R1 = 2 * abs(-sin(time1) * 2 - 0.2) + 0.7;
	/*(��) ������ ���� ������ ����. ���밪�� ����� ������ �������� ������ ����.
	+0.2�� ���� ������ ���� ��ġ ����. 2*�� ���� ������ ������ �Ÿ� ����
	sin()�Լ��� ���� �ֱ����� ������ ����*/

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

	/* �κ��� ������ �� �� ��,��,��,��� ���� Ʈ�� ����� ���� */
	glRotatef(-abs(sin(time1) * 10), 1, 0, 0);
	glRotatef(sin(time1) * 7, 0, 0, 1);

	/* �κ��� ������ ������ ���� ƨ��� ����� ǥ�� */
	float i = 0;
	i = abs(sin(time1)*0.08);
	glTranslatef(0.0, i, 0);
	glTranslatef(0.0, 0.5, 0.0);
	DrawAndroid();
	glutSwapBuffers();
}

/* Ÿ�̸� �Լ�. �� ��鸶�� ���� ǥ���� �ٸ��� �ϱ� ���� ������ �ð� ������ �����. */
void MyTimer(int Value) {
	time1 += 0.1;				// �޸��� ���� Ÿ�̸� ����
	time2 += 0.5;				// ���� ������ ���� Ÿ�̸� ����
	time3 += 0.01;				// ������ ������ ���� Ÿ�̸� ����, ����� �κ��� ��۹�� ���ư��� �ϱ� ���� ���� Ÿ�̸� ����
	time4 += 1.0;				// �ǰ� ������ ���� �� ���� Ÿ�̸� ����
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}