YES가 되는 겨우 : bi의 값이 이전 값과 같거나 +1 인 값만 가능, bi 값이 나머지의 종류의 갯 수와 같거나 작아야함
그리고 bi 값이 같으 숫자가 최대 반복횟수보다 작아야 함
그 외에는 전부 "NO"


    vector<int> limit(n / p + 2, p);
    limit.front() = 0; limit.back() = n % p;
    
            if (t != bef)
            {
                limit[t] += limit[bef];
                bef = t;
            }

위 조건에서 최대 반복 횟수가 이전됨

비둘기집 원리?
