// 3.5.variable.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	/*
	3.5. 정수자료형의 이해

	a + b : int
	(a + b) * c : int
	(a + b) * c + d : unsigned ing : 부호 없는 정수형 + 부호 있는 정수형 = 부호 없는 정수형
	-2에서 오버플로우 발생하여 강제로 부호 없는 정수형으로 전환됨
	vector<int>& seq 의 seq.size()도 주의해야 함 -> size_t라는 부호 없는 정수형이므로 -1하면 오류난다
	*/
	unsigned char a = 17;
	short b = -18;
	int c = 2;
	unsigned int d = 0;
	cout << (a + b) * c + d << endl;

	/*
	3.6. 실수 자료형의 이해

	- 부동 소수점 표기
	32비트 실수형 : 부호 1, 지수 8, 가수 23, 지수범위 -2^7 + 2 ~ 2^7 - 1
	64비트 실수형 : 부호 1, 지수 11, 가수 52, 지수범위 -2^10 + 2 ~ 2^10 - 1
	80비트 실수형 : 부호 1, 지수 15, 가수 64, 지수범위 -2^14 + 2 ~ 2^14 -1

	- 실수 비교시 오차한도 설정 필요
	- 상대오차를 이용한다
	*/

    return 0;
}

