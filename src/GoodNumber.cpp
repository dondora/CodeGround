/*
 * solution.cpp
 *
 *  Created on: 2016. 7. 4.
 *      Author: don
 */




// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int N;
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

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





		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", cnt);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
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
//			//착한수 인지 체크
//			// 첫번째의 경우 무조껀 착한수가 아니다. 때문에 i = 0 일때 찾지 않게 수정
//			// i 에서 i - a , a-1>=0 일때까지 빼면서 두개 수의 합이 i - a 인 값을 찾는다.
//			for (j = i - 1; j >= 0; j--)
//			{
//					if (arr_s[arr[i] - arr[j] + 200000] == 1)
//					{
//						good++;
//						break;
//					}//if
//			}//for
//			//숫자의 합에 대칭 되는 행렬, 메모리 공간에 1 대입
//			// ex arr_s[10 + 200000] = 1이라는 말은 두 수의 합이 10이 되는 두 수가 존재한다는 뜻
//			for (j = 0; j <= i; j++)
//				arr_s[arr[i] + arr[j] + 200000] = 1;
//
//		}//for
//		printf("Case #%d\n%d\n", test_case + 1, good);
//	}//for
//    return 0;
//}
