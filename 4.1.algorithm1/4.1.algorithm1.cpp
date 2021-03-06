// 4.1.algorithm1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*
	알고리즘을 지배하는 것 : 반복문
	N번 수행되는 반복문 중복 : N^2
	N번 1개, 100번 한개 : N + 100 => N
	*/

	/*
	4.2. 선형 시간 알고리즘 O(N)
	4.3. 선형 이하 시간 알고리즘 O(lgN) => 이진 탐색
	4.4. 지수 시간 알고리즘 O(2^N)
	4.5. 시간복잡도
	1) O(N^2) 정렬 중 삽입 정렬이 가장 빠르다
	2) 삽입정렬은 O(N) ~ O(N^2)
	
	4.6. 수행시간 어림짐작하기
	1초당 반복문 수행횟수가 1억을 넘어가면 시간제한 초과할 가능성이 높다
	*/
    return 0;
}

const int MIN = numeric_limits<int>::min();

// A[]의 연속된 부분 구간의 최대 합을 구한다.
// 1. 모든 구간합을 계산함. 시간 복잡도: O(N^3)
int inefficientMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			// 구간 합을 구한다
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += A[k];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// 2. 이동평균 알고리즘 사용, 시간복잡도: O(N^2)
int betterMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			sum += A[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// 3. 분할정복 알고리즘: A[lo...hi]의 연속된 부분 구간의 최대 합을 구한다, 시간복잡도: O(NlgN)
int fastMaxSum(const vector<int>& A, int lo, int hi) {
	// 기저 사례: 구간의 길이가 1인 경우
	if (lo == hi) return A[lo];
	
	// 배열을 A[lo...mid], A[mid+1...hi]의 두 조각으로 나눈다
	int mid = (lo + hi) / 2;

	// 두 부분에 모두 걸쳐있는 최대 합 구간을 찾는다.
	// 이 구간은 A[i...mid]와 A[mid+1...j] 형태를 갖는 구간의 합으로 이루어진다.
	// A[i...mid] 형태를 갖는 최대 구간을 찾는다.
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
		left = max(left, sum);
	}

	// A[mid+1...j] 형태를 갖는 최대 구간을 찾는다
	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += A[j];
		right = max(right, sum);
	}

	// 최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
	int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

	return max(left + right, single);
}

// 4. 동적 계획법. 시간복잡도: O(n)
// A[i]를 오른쪽 끝으로 갖는 구간의 최대 합을 반환하는 함수 maxAt(i)가 있다고 가정
// maxAt(i) = max(0, maxAt(i-1)) + A[i]
int fastestMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; ++i) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}