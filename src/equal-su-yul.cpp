/*
 * su-yul.cpp
 *
 *  Created on: 2016. 7. 5.
 *      Author: don
 */

#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int N;
unsigned long long suyoul[100000];
std::set<unsigned long long> diff;

/* Recursive Standard C Function: Greatest Common Divisor */
int
gcdr ( int a, int b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}

int suoul(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
#if 0
	printf("start\n");
	unsigned long long  su = 1000000000000;
	printf("%llu \n", su);

#else
	freopen("suyoul_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	   C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   ���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

		scanf("%d", &N);
		for(int i=0;i<N;i++)
		{
			scanf("%llu ", &suyoul[i]);
		}

		int cnt=0;
		diff.clear();
		for(int i=N-1;i>=1;i--)
		{
			diff.insert(suyoul[i]-suyoul[i-1]);
		}

		unsigned long long tmp = *(diff.begin());
		if(tmp==0 && diff.size()==1)
		{
			cnt=1;
		}
		else if(tmp==0 && diff.size()!=1)
		{
			cnt=0;
		}
		else
		{
			for(unsigned long long  i=1;i<=tmp;i++)
			{
				if(tmp%i==0) cnt++;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", cnt);

	}
#endif
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}


