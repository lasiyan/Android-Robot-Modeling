#include"AndroidBot_Display.h"

/* 키보드 콜백. w를 누르면 wireframe 모드로, s를 누르면 solid rendering 모드로,
q를 누르면 종료 */
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

/* 장면별로 키 값이 부여되며 이에 따라 노래가 연주됨. 노래 재생은 sndPlaySound() 함수를 사용하였으며
이를 위해 별도의 음악 파일이 필요함. 경로 설정은 sndPlaySound(TEXT("음악 파일 경로")) */
void MyDisplay() {
	if (key == RUN) {			// 달릴 때
		Run();
		glPopMatrix();
	}
	else if (key == JAP) {		// 잽
		Jap();
		glPopMatrix();
	}
	else if (key == ROCKET) {	// 로켓
		Rocket();
		glPopMatrix();
	}
	else if (key == SKATE) {	// 스케이트
		Show();
		glPopMatrix();
	}
	else if (key == 5) {		// 중지
		sndPlaySound(NULL, SND_ASYNC);
	}
	else if (key == EXIT) {		// 종료
		ex();
		glPopMatrix();
	}
}


/* 마우스 오른쪽 클릭을 해서 메뉴를 선택하면 실행되는 함수
기본적으로 장면을 전환할땐 마우스 콜백을 이용하여 변환하도록 설정 */
void MyMainMenu(int entryID) {	//메뉴
	key = entryID;
}

