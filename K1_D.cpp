#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    // Определяем границы прямоугольников
    int minX1 = min(x1, x2), maxX1 = max(x1, x2);
    int minY1 = min(y1, y2), maxY1 = max(y1, y2);
    int minX2 = min(x3, x4), maxX2 = max(x3, x4);
    int minY2 = min(y3, y4), maxY2 = max(y3, y4);
    
    // Площади прямоугольников
    int S1 = (maxX1 - minX1) * (maxY1 - minY1);
    int S2 = (maxX2 - minX2) * (maxY2 - minY2);
    
    // Координаты пересечения
    int interX1 = max(minX1, minX2);
    int interX2 = min(maxX1, maxX2);
    int interY1 = max(minY1, minY2);
    int interY2 = min(maxY1, maxY2);
    
    // Площадь пересечения
    int Sinter = 0;
    if (interX1 < interX2 && interY1 < interY2) {
        Sinter = (interX2 - interX1) * (interY2 - interY1);
    }
    
    // Площадь объединения
    int Sunion = S1 + S2 - Sinter;
    
    cout << Sunion << endl;
    
    return 0;
}
