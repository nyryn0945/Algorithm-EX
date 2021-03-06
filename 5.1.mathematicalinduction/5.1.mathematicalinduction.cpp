// 5.1.mathematicalinduction.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
/*
수학적 귀납법: 단계 나누기 / 첫 단계 증명 / 귀납 증명
귀류법: 반대상황을 가정하고 논리를 전개한다
비둘기집의 원리: 10마리의 비둘기가 9개의 비둘기집에 모두 들어갔다면 2마리 이상이 들어간 비둘기집이 반드시 하나는 존재
동전 뒤집기: 100개의 동전이 바닥에 깔려 있을때 한번 뒤집을 때 반드시 X개의 동전을 한번에 뒤집어야 한다. 뒤집는 동전의 최소개수는? 100
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void printDecimal(int a, int b);

int main()
{
	printDecimal(10, 3);
	return 0;
}

// 1. 이진탐색 알고리즘
// 결과: A[i-1] < x <= A[i]
// A[-1] = 음의 무한대, A[n] = 양의 무한대
int binsearch(const vector<int>& A, int x) {
	int n = A.size();
	int lo = -1, hi = n;
	// 반복문 불변식 1: lo < hi
	// 반복문 불변식 2: A[lo] < x <= A[hi]
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] < x)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

// 2. 삽입정렬 알고리즘
// 이동했을때 이전 값들이 모두 A[j]보다 크다
// 나머지 값들은 모두 상대적으로 정렬되어 있다
void insertionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		// 불변식 A: [0, .., i-1]은 이미 정의되어 있다
		// A[0, ..., i-1]에 A[i]를 끼워넣는다
		int j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			// 불변식 b: A[j+1...i]의  모든 원소는 A[j]보다 크다
			// 불변식 C: A[0...i] 구간은 A[j]를 제외하면 정의되어 있다.
			swap(A[j - 1], A[j]);
			--j;
		}
	}
}

// 순환 소수 찾기
// 분수 a/b의 소수 표현을 출력한다.
// a >= 0, b > 0
void printDecimal(int a, int b) {
	int iter = 0;
	while (a > 0) {
		// 첫 번째와 두 번째 사이에 소수점을 찍는다
		if (iter++ == 1) cout << '.';
		cout << a / b;
		a = (a % b) * 10;
	}
}

// n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
// n : 전체 원소의 수
// picked : 지금까지 고른 원소들의 번호
// toPick : 더 고를 원소의 수
void pick(int n, vector<int>& picked, int toPick) {
	// 기저사례: 더 고를 원소가 없을때 고른 원소들을 출력한다.
	if (toPick == 0) {
		printPicked(picked);
		return;
	}

	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	// 이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}