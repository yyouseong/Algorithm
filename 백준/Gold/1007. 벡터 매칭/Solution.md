벡터의 합을 구하는 식이
```
v1 + v2
= ( (x1-x2) + (x3-x4) , (y1-y2) + (y3-y4) ) = ( (x1+x3) - (x2+x4) , (y1+y3) - (y2+y4) )
```
이런 식으로 바뀌는 것을 알면 풀 수 있는 문제

+ vector를 함수로 넘길 때
double Vec_sum(vector<vector<int> >VEC,int n)

call by value로 넘기면 시간이 추가로 더 걸려 TLE가 난다.
따라서 call by reference로 넘겨야 한다. 배열 이름 앞에 "&" 추가

double Vec_sum(vector<vector<int> >&VEC,int n)
