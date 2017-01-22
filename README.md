# Android-Robot-Modeling

Android Robot Modeling and Action implement using OpenGL and native language in VisualStudio 2015

본 프로젝트는 openGL을 활용한 안드로이드 로봇을 모델링하고 그것을 바탕으로 달리기, 권투, 스케이팅, 로켓펀치, 종료 이펙트를 구현한다.

## 개발 환경

* OS : Windows 10 Pro 64bit
* CPU : Intel(R) Core(TM) i5-4590 CPU @ 3.30GHz 3.30 GHz
* RAM : 8.00GB
* IDE : Microsoft Visual Studio Community 2015

## 사용 기술

C++, OpenGL API

## 부가 설명

 먼저 코드를 모듈화하여 실행을 수행할 AndroidBot_Main, 로봇의 모델링을 담당할 AndroidBot_Modeling, 로봇의 수행 모션(action)를 담당할 AndroidBot_Activity, 마지막으로 키보드 입력처리와 각 액션에 따른 BGM출력, 팝업 메뉴를 출력할 AndroidBot_Display로 분리하였다

Modeling에서는 로봇을 총 8단계로 나누고 각각의 부분에 해당하는 함수를 분할한 후 모델링을 수행하며 모델링 과정에서 GlInit() 함수를 통해 OpenGL을 초기화 한 후 깊이 테스팅, 정규화, 각 지점에 따른 색상 연결, 조명 각도, 매트릭스모드, 가시 범위 등을 설정하여 모델링을 수행한다.

Activity에서는 로봇의 행동(달리기, 잽, 스케이팅, 로켓펀치, 종료)을 각각 함수화하여 구현하고 움직임을 제어하기 위해 time 변수를 각각 설정하여 별도로 제어하였으며, 로봇 움직임의 가속도는 sin함수를 통해 표현하였다. 또한 관절의 움직임 범위가 제한되어야 하는 점을 고려하여 abs 절대값 함수를 통해 관절 움직임을 제한하였다.

마지막으로 Display부분에서 키보드 콜백 함수를 통해 wireframe모드와 solid rendering 모드의 전환을 구현하고, q버튼 입력 시 로봇의 종료 이펙트가 출력되도록 설정하였다. 또한 각각의 액션에 따른 BGM을 출력하였으며 이를 실행하기 위해서 첨부된 별도의 음악 파일이 존재하여야 한다. 마지막으로 마우스 오른쪽 클릭 시 출력되는 팝업 메뉴를 구현하여 로봇의 액션 전환을 선택적으로 수행할 수 있도록 하였다.

## 실행 과정

1. https://drive.google.com/file/d/0B3wz4RsRRCj8WVZMMlJRckhxVTA/view 위 주소로 이동해 openGL API download
 * Windows Visual 2015를 기준으로 .h 헤더 파일은 
 * C:\Program Files (x86)\Windows Kits\8.1\Include\um\gl 에 복사
 * lib 파일은
 * C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x86 에 복사
 * .dll 파일은 C:\Windows\System32 에 복사
 * 64bit OS의 경우 C:\Windows\SysWOW64 에도 복사해준다
2. 프로젝트 속성 -> 링커 -> 입력 -> 추가종속 에
 * glu32.lib
 * glut32.lib
 * opengl32.lib
 * glaux.lib 를 입력
3. 파일 실행

## 실행 결과

[![Demo Doccou alpha](https://j.gifs.com/oYK2qX.gif)](https://youtu.be/9gQibic_L6Q)
