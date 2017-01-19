#include"AndroidBot_Main.h"
#include"AndroidBot_Activity.h"
#include"AndroidBot_Display.h"
#include"AndroidBot_Modeling.h"

int main(int argc, char** argv) {
	glutInit(&argc, argv);		// �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	// ���÷��� ��� ����
	glutInitWindowSize(800, 800);								// ������ ũ�� ����
	glutInitWindowPosition(0, 0);								// ������ �ʱ� ��ġ ����
	glutCreateWindow("First Project");							// ������ ����
	HWND winHandle = FindWindow(NULL, argv[0]);				// ��Ʈ�� �˾�
	MessageBox(winHandle, "Reading README.md", "Notice", MB_OK);
	MessageBox(winHandle, "Click ok and mouse right button in window", "Notice", MB_OK);
	glInit();					// ���� �ʱ�ȭ
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);			// �޴��߰�
	glutAddMenuEntry("Run", 1);			// �κ��� �޸��� ���� �޴� �߰�
	glutAddMenuEntry("Jap", 2);			// �κ��� �쳯���� ���� �޴� �߰�
	glutAddMenuEntry("Shoot", 3);		// �κ��� ������ġ�� ������ ���� �޴� �߰�
	glutAddMenuEntry("Skate", 4);		// �κ��� �ǰܽ��������ϴ� ���� �޴� �߰�
	glutAddMenuEntry("Stop", 5);		// �κ��� �ϴ� ���� ���߰� �ϴ� �޴� �߰�
	glutAttachMenu(GLUT_RIGHT_BUTTON);	// ���콺 ������ ��ư�� Ŭ���ϸ� �޴� �˾�
	glutKeyboardFunc(MyKeyboard);		// Ű���� �ݹ�
	glutTimerFunc(40, MyTimer, 1);		// Ÿ�̸� �Լ�
	glutDisplayFunc(MyDisplay);			// ���÷���

	glutMainLoop();
	
	return 0;
}
