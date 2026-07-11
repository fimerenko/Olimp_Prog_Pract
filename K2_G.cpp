#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    priority_queue<int> max_heap; // меньшая половина
    priority_queue<int, vector<int>, greater<int>> min_heap; // большая половина
 
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
 
        // Добавляем элемент
        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }
 
        // Балансируем: max_heap должен содержать на 1 элемент больше или столько же
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
 
        // Медиана — верхушка max_heap
        cout << max_heap.top() << '\n';
    }
 
    return 0;
}
