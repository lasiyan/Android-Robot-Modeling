#include"AndroidBot_Main.h"
#include"AndroidBot_Activity.h"
#include"AndroidBot_Display.h"
#include"AndroidBot_Modeling.h"

int main(int argc, char** argv) {
	glutInit(&argc, argv);		// 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	// 디스플레이 모드 설정
	glutInitWindowSize(800, 800);								// 윈도우 크기 설정
	glutInitWindowPosition(0, 0);								// 윈도우 초기 위치 설정
	glutCreateWindow("First Project");							// 윈도우 생성
	HWND winHandle = FindWindow(NULL, argv[0]);				// 인트로 팝업
	MessageBox(winHandle, "Reading README.md", "Notice", MB_OK);
	MessageBox(winHandle, "Click ok and mouse right button in window", "Notice", MB_OK);
	glInit();					// 조명 초기화
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);			// 메뉴추가
	glutAddMenuEntry("Run", 1);			// 로봇이 달리는 동작 메뉴 추가
	glutAddMenuEntry("Jap", 2);			// 로봇이 잽날리는 동작 메뉴 추가
	glutAddMenuEntry("Shoot", 3);		// 로봇이 로켓펀치를 날리는 동작 메뉴 추가
	glutAddMenuEntry("Skate", 4);		// 로봇이 피겨스케이팅하는 동작 메뉴 추가
	glutAddMenuEntry("Stop", 5);		// 로봇이 하는 일을 멈추게 하는 메뉴 추가
	glutAttachMenu(GLUT_RIGHT_BUTTON);	// 마우스 오른쪽 버튼을 클릭하면 메뉴 팝업
	glutKeyboardFunc(MyKeyboard);		// 키보드 콜백
	glutTimerFunc(40, MyTimer, 1);		// 타이머 함수
	glutDisplayFunc(MyDisplay);			// 디스플레이

	glutMainLoop();
	
	return 0;
}
