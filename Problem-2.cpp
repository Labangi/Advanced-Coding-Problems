#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long k;
    cin >> k;

    sort(a.begin(), a.end());

    long long median = a[n / 2];

    long long operations = 0;

    for(int i = 0; i < n; i++) {

        long long diff = abs(a[i] - median);

        // Impossible case
        if(diff % k != 0) {
            cout << -1 << endl;
            return 0;
        }

        operations += diff / k;
    }

    cout << operations << endl;

    return 0;
}
