#include <cstdio>
#include <cmath>

/* 
코딩테스트 사이트인 온코더에서 점수 산정 방식에 따라 계산합니다.
시간을 입력하면 예상점수를 알 수 있고, 점수를 입력하면 걸린시간을 알 수 있습니다.
아직 정확도가 떨어집니다.
*/

double calcOnCoderPoint(int maxPoint, int submitCount, double testAllTime, double problemElapsedTime)
{
	int correctionValue = 4;
	double r1 = correctionValue * (double)maxPoint * (0.5*(0.5*(testAllTime*testAllTime) / (10.0 * (problemElapsedTime*problemElapsedTime) + (testAllTime * testAllTime)))*pow(0.95, submitCount - 1));
	double r2 = maxPoint * 0.5;
	return r1 > r2 ? r1 : r2;
}

double calcOnCoderTime(int maxPoint, int submitCount, double testAllTime, double point)
{
	if (point < maxPoint * 0.5 + 1e-6 && point > maxPoint * 0.5 - 1e-6)
		return 1e9 - 1;
	int correctionValue = 4;
	double r1 = sqrt(0.1 * ((((double)maxPoint * (0.5 * (0.5 * (testAllTime*testAllTime)) * pow(0.95, submitCount - 1))) / (point / correctionValue)) - (testAllTime * testAllTime)));
	return r1 / 60;
}

int main()
{
	int maxPoint, submitCount;
	double testAllTime, problemElapsedTime, point;

	int problemNumber = 0;
	puts("문제의 개수를 입력하세요.");
	scanf("%d", &problemNumber);
	while (problemNumber--)
	{
		
		puts("\'문제배점 제출횟수 시험전체시간(시간) 얻은점수\'를 입력하세요.");
		int exceptionCheck = scanf("%d %d %lf %lf", &maxPoint, &submitCount, &testAllTime, &point);
		if (exceptionCheck != 4)
		{
			puts("제대로 입력하세요.");
			continue;
		}

		double time = calcOnCoderTime(maxPoint, submitCount, testAllTime * 3600, point);
		if (time > 1e8)
			puts("최소 점수를 받으셨으므로 시간을 알 수 없습니다.");
		else
			printf("문제 풀이에 걸린 예상 시간 : %lf\n", time);
		

		/*
		puts("\'문제배점 제출횟수 시험전체시간(시간) 걸린시간(분)\'를 입력하세요.");
		int exceptionCheck = scanf("%d %d %lf %lf", &maxPoint, &submitCount, &testAllTime, &problemElapsedTime);
		if (exceptionCheck != 4)
		{
			puts("제대로 입력하세요.");
			continue;
		}

		double point = calcOnCoderPoint(maxPoint, submitCount, testAllTime * 3600, problemElapsedTime * 60);
		printf("해당 문제의 예상 점수 : %lf\n", point);
		*/
	}
}
