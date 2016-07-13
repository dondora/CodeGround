/*
 * solution.cpp
 *
 *  Created on: 2016. 7. 4.
 *      Author: don
 */




// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(index,init,max) for(int (index)=(init);(index)<(max);(index)++)

using namespace std;

int su[5000];
int cache[3000000];
bool check(int t[], int size, int target)
{
	FOR(i,0,size)
	{
		FOR(j,i,size)
		{
			FOR(k, j, size)
			{
//				printf("%d %d %d\n",t[i], t[j], t[k]);
				if((t[i]+t[j]+t[k])==target)
				{
					return true;
				}
			}
		}
	}

	return false;
}


int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("sample_input.txt", "r", stdin);

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

		scanf("%d", &N);
		FOR(i, 0, N)
		{
			scanf("%d ", &su[i]);
		}

		FOR(i, 1, N)
		{
			if (check(su, i, su[i])) {
				++cnt;
//				printf("----\n");
			}
		}





		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", cnt);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}

//
//
//
//#include <stdio.h>
//#include <string.h>
//
//int arr[5000];
//int arr_s[400001];
//
//int main()
//{
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	int TC, test_case ,T, i, j , num , a;
//	int good;
//	scanf("%d", &TC);
//
//	for (test_case = 0; test_case < TC; test_case++)
//	{
//        memset(arr_s,0,sizeof(arr_s));
//		good = 0;
//		scanf("%d", &T);
//		for (i = 0; i < T; i++)
//		{
//
//			scanf("%d", &arr[i]);
//			//���Ѽ� ���� üũ
//			// ù��°�� ��� ������ ���Ѽ��� �ƴϴ�. ������ i = 0 �϶� ã�� �ʰ� ����
//			// i ���� i - a , a-1>=0 �϶����� ���鼭 �ΰ� ���� ���� i - a �� ���� ã�´�.
//			for (j = i - 1; j >= 0; j--)
//			{
//					if (arr_s[arr[i] - arr[j] + 200000] == 1)
//					{
//						good++;
//						break;
//					}//if
//			}//for
//			//������ �տ� ��Ī �Ǵ� ���, �޸� ������ 1 ����
//			// ex arr_s[10 + 200000] = 1�̶�� ���� �� ���� ���� 10�� �Ǵ� �� ���� �����Ѵٴ� ��
//			for (j = 0; j <= i; j++)
//				arr_s[arr[i] + arr[j] + 200000] = 1;
//
//		}//for
//		printf("Case #%d\n%d\n", test_case + 1, good);
//	}//for
//    return 0;
//}
