#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> left(N), right(N);
    stack<int> st;
    
    // Находим для каждого элемента индекс ближайшего слева строго большего
    for (int i = 0; i < N; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    // Очищаем стек
    while (!st.empty()) st.pop();
    
    // Находим для каждого элемента индекс ближайшего справа большего или равного
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        right[i] = st.empty() ? N : st.top();
        st.push(i);
    }
    
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long left_count = i - left[i];
        long long right_count = right[i] - i;
        sum += a[i] * left_count * right_count;
    }
    
    cout << sum << '\n';
    
    return 0;
}
