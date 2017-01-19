#include"AndroidBot_Modeling.h"

#define RUN		1					
#define JAP		2							
#define ROCKET	3	
#define SKATE	4	
#define EXIT	6	

int flag = 0; // wireframe ���� solid rendering ��� ���� ����
int key = 0;  // ���� ���� ���� ���� ����

GLfloat R_Arm_x = 0; // ������ ���
GLfloat R_Arm_y = 0; // ������ ��
GLfloat L_Arm_x = 0; // ���� ���
GLfloat L_Arm_y = 0; // ���� ��
GLfloat R_Leg_x = 0; // ���� �����
GLfloat R_Leg_y = 0; // ���� ���Ƹ�
GLfloat L_Leg_x = 0; // �� �����
GLfloat L_Leg_y = 0; // �� ���Ƹ�
GLfloat R1 = 0;		 // ���� ���� ��ġ ������ ����
GLfloat R2 = 0;		// ������ ���� ��ġ ������ ����

static double time1 = 0; // Run_time ����
static double time2 = 0; // Jap_time ����
static double time3 = 0; // Rocket_time ����
static double time4 = 0; // ground_time ����
static double time5 = 0; // exit_time ����

GLUquadricObj* cyl;// �Ǹ��� ��ü ����

void glInit(void) {			 // ���� �ʱ�ȭ �Լ� 
	glEnable(GL_DEPTH_TEST); // ���� �׽��� ���
	glEnable(GL_NORMALIZE);  // ����ȭ
	glEnable(GL_SMOOTH);     // �� ������ ������ �ε巴�� �����Ͽ� ĥ��������  �ϹǷ�, �������� ����� ������ ȥ�յǾ� ����ȴ�. 
	glEnable(GL_LIGHTING);   // ���� ����. ���� �޴� ������ ���� �κ� ������ ��ȭ

							 /* ���� �޴� ������ ���� �κ� ������ ��ȭ�� ���� ���� */
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
	glMatrixMode(GL_PROJECTION);   // ��� ����
	glLoadIdentity();              // CTM �� �ʱ�ȭ 
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // ���� ���� ����
}

void Draw_Color(int i) { // ������ �׸��� �Լ�
	if (i == RUN) {
		glColor3f(0.7, 0.2, 0.3);	// ���ѻ���
	}
	else if (i == JAP) {
		glColor3f(0.8, 0.8, 0.3);	// �����
	}
	else if (i == ROCKET) {
		glColor3f(0.3, 0.7, 0.2);	// ���λ�
	}
	else if (i == SKATE) {
		glColor3f(0.4, 0.5, 0.8);	// �ϴû�
	}
	else if (i == EXIT) {
		glColor3f(0.2, 0.2, 0.2);
	}
}

void Change_Wire_Or_Solid(int i) {          // �ָ���, ���̾� ����
	if (flag == 1)
		gluQuadricDrawStyle(cyl, GLU_LINE); // ��Ÿ���� ���̾�� ����
}

/* �κ� ������ �׸��� �Լ� */
void DrawL_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				// �� ����
	cyl = gluNewQuadric();			// �Ǹ��� ��ü ����
	glRotatef(x, a, b, c);			// �Ķ���� ����ŭ ȸ��
	glRotatef(90.0, 1.0, 0.0, 0.0); // �Ǹ����� x�� �������� 90�� ȸ��(�Ǹ��� ���� �� ���� ������ ����)
	glTranslatef(0.25, 0.0, 0.0);   // ���� ��� ���������� �̵�
	glRotatef(15.0, 0.0, 1.0, 0.0); // ���� ����� y���� �������� 15�� ȸ��
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	// �Ǹ����� �׸�
}

/* �κ� ���� ���� �׸��� �Լ� */
void DrawL_Hand(int y, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				 // �� ����
	cyl = gluNewQuadric();			 // �Ǹ��� ��ü ����
	glTranslatef(0.0, 0.0, 0.22);	 // �޼� ������
	glRotatef(y, a, b, c);			 // �Ķ���� ����ŭ ȸ��
	Change_Wire_Or_Solid(flag);
	if (key == SKATE) gluCylinder(cyl, 0.05, 0.02, 0.2, 15, 1); // �򶧱� ��� �Ǹ����� �׸�
	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);
	glPopMatrix();
}

/* �κ� ���� ����*/
void DrawL_HandRocket() {
	glPushMatrix();
	glColor3f(0.9, 0.35, 0.35);		 // �� ����
	cyl = gluNewQuadric();			 // �Ǹ��� ��ü ����
	glTranslatef(0, 0, R1);			 // ���� �ָ� ��ġ�� �Ķ���͸�ŭ �̵�
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* �κ� �������� �׸��� �Լ� */
void DrawR_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);				 // �� ����
	cyl = gluNewQuadric();			 // �Ǹ��� ��ü ����
	glRotatef(x, a, b, c);			 // �Ķ���� ����ŭ ȸ��
	glRotatef(90.0, 1.0, 0.0, 0.0);	 // �Ǹ����� x���� �������� 90�� ȸ��(�Ǹ��� ���� �� ���� ������ ����)
	glTranslatef(-0.25, 0.0, 0.0);	 // ������ ���������� �̵�
	glRotatef(-15.0, 0.0, 1.0, 0.0); // ������ -15�� y����� ȸ��
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);

}

/* �κ� ������ ���� �׸��� �Լ�*/
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

/* �κ� ������ ����Ʈ �Լ� */
void DrawR_HandRocket() {
	glPushMatrix();
	glColor3f(0.9, 0.1, 0.1);
	cyl = gluNewQuadric();
	glTranslatef(0, 0, R2);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
	glPopMatrix();
}

/* �κ� ��ü�� �׸��� �Լ� */
void DrawBody(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);			// �Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
	glRotatef(x, a, b, c);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.2, 0.2, 0.45, 50, 1);
	glPopMatrix();
}

/* �κ� ���� ������� �׸��� �Լ� */
void DrawL_Legs(int x, int a, int b, int c) {
	glPushMatrix();
	Draw_Color(key);
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);			// �Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
	glTranslatef(0.1, 0.0, 0.42);
	glRotatef(x, a, b, c);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);

}

/* �κ� ���� ���Ƹ��� �׸��� �Լ� */
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

/* �κ� ������ ������� �׸��� �Լ� */
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

/* �κ� ������ ���Ƹ��� �׸��� �Լ� */
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

/* �κ� ���� �׸��� �Լ� */
void Drawneck() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);				 // ���
	cyl = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -0.045);
	Change_Wire_Or_Solid(flag);
	gluCylinder(cyl, 0.2, 0.2, 0.025, 100, 1);
	glPopMatrix();
}

/* ������ �׸��� �Լ�, �̴� Ŀ�ٶ� ���� �����Ͽ�����
������ �ð��� ���� ȸ���Ͽ� ��ġ �κ��� ������ �پ�� ������ �鵵�� �� */
void DrawGround() {
	Draw_Color(flag);						 // ���� ����
	glTranslatef(0.0, -2.73, 0.0);			 // �� ������
	glRotatef(45.0, 0, 1, 0);				 // 45����ŭ y�� �������� ȸ��
	glRotatef(0.0 + time4 - 15, 0.0, 0.0, 1);// z�� �������� time4��ŭ ���� ȸ�� 
	Change_Wire_Or_Solid(flag);
	gluSphere(cyl, 2.5, 30, 90);
}

/* ������Ʈ�� ��ο� �׶��� */
void Draw_Skate_Ground() {
	glColor3f(0.85, 0.85, 0.99);
	glTranslatef(0.0, -2.73, 0.0);			 // �� ������
	glRotatef(45.0, 0, 1, 0);				 // 45����ŭ y�� �������� ȸ��
	glRotatef(0.0 + time4 - 15, 0.0, 0.0, 1);// z�� �������� time4��ŭ ���� ȸ�� 
	Change_Wire_Or_Solid(flag);
	gluSphere(cyl, 2.5, 30, 90);
}

/* �κ� �Ӹ��� �׸��� �Լ�
�Ӹ��� �޷��ִ� �԰� �κ��� ���� �����Ͽ���. */
void DrawHead() {
	glTranslatef(0.0, 0.02, 0.0);
	glPushMatrix();							 // ó�� ���� ��ǥ �ٽ� ����
	cyl = gluNewQuadric();
	Change_Wire_Or_Solid(flag);
	Draw_Color(key);						 // ���� ����
	gluSphere(cyl, 0.20, 30, 10);			 // �Ӹ� �׸���

											 /*���� �� �׸���*/
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.16, 0.0, -0.22);
	glRotatef(35.0, 0.0, 1.0, 0.0);			  // 35�� y�� ���� ȸ��
	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);// �Ǹ��� �׸�
	glPopMatrix();							  // ó�� ���� ��ǥ�� ���� ����.
	glPushMatrix();							  // ó�� ���� ��ǥ �ٽ� ����

											  /*������ �� �׸���*/
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.16, 0.0, -0.22);
	glRotatef(-35.0, 0.0, 1.0, 0.0);		  // -35�� y�� ���� ȸ��
	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);// �Ǹ��� �׸�
	glPopMatrix();							  // ó�� ���� ��ǥ�� ���� ����.	
	glPushMatrix();							  // ó�� ���� ��ǥ �ٽ� ����

											  /*���� �� �׸���*/
	glTranslatef(-0.1, 0.1, 0.13);
	glColor3f(0.0, 0.0, 0.0);				  // �� �÷� ����(���)
	gluSphere(cyl, 0.03, 10, 10);

	glPopMatrix();							  // ó�� ���� ��ǥ�� ���� ����.
	glPushMatrix();							  // ó�� ���� ��ǥ �ٽ� ����

											  /*������ �� �׸���*/
	glTranslatef(0.1, 0.1, 0.13);
	gluSphere(cyl, 0.03, 10, 10);
	glPopMatrix();							  // ó�� ���� ��ǥ �ٽ� ����
}

/* �κ� ��ü ����� �׸��� �Լ� */
void DrawAndroid() {
	DrawBody(0, 0, 0, 0);					  // ���� �Լ� ȣ��
	Drawneck();								  // ���Լ� ȣ��
	DrawHead();								  // �Ӹ� ȣ��
	DrawR_Arm(R_Arm_x, 1, 0, 0);			  // ������
	if (key == ROCKET) DrawR_HandRocket();	  // ���ϸ���϶� ��������ȣ��
	else DrawR_Hand(R_Arm_y, 1, 0, 0);		  // ������
	DrawL_Arm(L_Arm_x, 1, 0, 0);			  // ����
	if (key == ROCKET) DrawL_HandRocket();	  // ���ϸ���϶� ��������ȣ��
	else DrawL_Hand(L_Arm_y, 1, 0, 0);		  // �� ��
	DrawL_Legs(L_Leg_x, 1, 0, 0);			  // ���� �ٸ�
	DrawL_foot(L_Leg_y, 1, 0, 0);			  // ���� ��		 
	DrawR_Legs(R_Leg_x, 1, 0, 0);			  // ������ �ٸ�
	DrawR_foot(R_Leg_y, 1, 0, 0);			  // ������ ��	
}