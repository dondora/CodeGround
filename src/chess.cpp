/*
 * chess.cpp
 *
 *  Created on: 2016. 7. 6.
 *      Author: don
 */

// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <stack>
#define FOR(index, init , max) for(int (index)=(init);(index)<(max);++(index))

int Y, X, boomNum;
int boom[2000][2000];
typedef struct _POINT
{
public:
	int y;
	int x;
	_POINT(int yy, int xx){y=yy;x=xx;}

}POINT;
std::stack<POINT> s;

unsigned long long check()
{
	unsigned long long cnt=0;
	s.push(POINT(1,0));
	s.push(POINT(0,1));
	while(false==s.empty())
	{
		POINT p = s.top();
		s.pop();

		if(boom[p.y][p.x]==1 || p.y>=Y || p.x>=X)
			continue;
		if(p.y==Y-1 && p.x==X-1)
			++cnt;
		s.push(POINT(p.y+1,p.x));
		s.push(POINT(p.y,p.x+1));
	}
	return cnt;
}


int main(void) {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
#if 0
	printf("%lld\n", ((1<<32)-1));
	printf("%d\r\n", -18%14);
#else
	freopen("chess_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		//init
		FOR(i,0,2000)
				FOR(j,0,2000) boom[i][j]=0;

		scanf("%d %d %d", &Y, &X, &boomNum);

		FOR(b, 0, boomNum)
		{
			int bx, by;
			scanf("%d %d",  &by, &bx);
			boom[by-1][bx-1]=1;
		}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%llu\n", check());

	}
#endif
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
