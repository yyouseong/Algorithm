트리 DP

현재 노드가 0인 경우와 1인 경우를 둘 다 저장
0인 경우 : 무조건 직전 자식노드들이 1이어야 함
1인 경우 : 자식 노드의 0과1 중 더 작은 것을 선택 ( 0, 1 아무거나 관계 없음 )


dp[1][currentNode] = 1;
dp[0][currentNode] = 0; 

최하위 노드 저장 상태



dp[0][currentNode] += dp[1][tree[currentNode][i]];
dp[1][currentNode] += min(dp[1][tree[currentNode][i]], dp[0][tree[currentNode][i]]);

점화식


참고자료 : 
https://hqjang.tistory.com/104
