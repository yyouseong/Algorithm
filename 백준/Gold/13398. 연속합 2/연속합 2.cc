#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> L(n);
    vector<int> R(n);

    L[0] = a[0];
    int ans = L[0];
    
    for (int i = 1; i < n; i++) {
        L[i] = max(a[i], L[i-1] + a[i]);
        ans = max(ans, L[i]);
    }

    R[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--) {
        R[i] = max(a[i], R[i+1] + a[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        int temp = L[i-1] + R[i+1];
        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}