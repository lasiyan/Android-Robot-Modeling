#include"AndroidBot_Display.h"

/* Ű���� �ݹ�. w�� ������ wireframe ����, s�� ������ solid rendering ����,
q�� ������ ���� */
void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'w':
	case 'W':
		flag = 1;
		break;
	case 's':
	case 'S':
		flag = 0;
		break;
	case 'q':
	case 'Q':
		key = 6;
		break;
	}
}

/* ��麰�� Ű ���� �ο��Ǹ� �̿� ���� �뷡�� ���ֵ�. �뷡 ����� sndPlaySound() �Լ��� ����Ͽ�����
�̸� ���� ������ ���� ������ �ʿ���. ��� ������ sndPlaySound(TEXT("���� ���� ���")) */
void MyDisplay() {
	if (key == RUN) {			// �޸� ��
		Run();
		glPopMatrix();
	}
	else if (key == JAP) {		// ��
		Jap();
		glPopMatrix();
	}
	else if (key == ROCKET) {	// ����
		Rocket();
		glPopMatrix();
	}
	else if (key == SKATE) {	// ������Ʈ
		Show();
		glPopMatrix();
	}
	else if (key == 5) {		// ����
		sndPlaySound(NULL, SND_ASYNC);
	}
	else if (key == EXIT) {		// ����
		ex();
		glPopMatrix();
	}
}


/* ���콺 ������ Ŭ���� �ؼ� �޴��� �����ϸ� ����Ǵ� �Լ�
�⺻������ ����� ��ȯ�Ҷ� ���콺 �ݹ��� �̿��Ͽ� ��ȯ�ϵ��� ���� */
void MyMainMenu(int entryID) {	//�޴�
	key = entryID;
}

