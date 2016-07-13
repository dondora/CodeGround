/*
 * chess.cpp
 *
 *  Created on: 2016. 7. 6.
 *      Author: don
 */

// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

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
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%llu\n", check());

	}
#endif
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
