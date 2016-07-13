/*
 * solution.cpp
 *
 *  Created on: 2016. 7. 4.
 *      Author: don
 */




// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>

#define FOR(index,init,max) for(int (index)=(init);(index)<(max);(index)++)

using namespace std;

int su[5000];
char cache[600001];


bool check(int t[], int size, int target)
{
	if( cache[target+300000]==1)
		return true;
	FOR(i,0,size)
	{
		FOR(j,i,size)
		{
			FOR(k, j, size)
			{
				if((t[i]+t[j]+t[k])==target)
				{
					cache[target+300000]=1;
					return true;
				}
			}
		}
	}
	return false;
}


int goodnumber(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("goodnumber_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int N;
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.

		//init
		N=0;
		FOR(i,0,5000) su[i]=0;
		int cnt=0;
		//FOR(i,0,300001) cache[i]=0;

		scanf("%d", &N);
		FOR(i, 0, N)
		{
			scanf("%d ", &su[i]);
		}

		FOR(i, 1, N)
			if(check(su, i, su[i])) ++cnt;




		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", cnt);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
