#include <iostream>

using namespace std;

inline void Rotate (int* list, int rotate, int length);

int main() {
    int time;  cin >> time;
    while (time --) {
        int length, rotate;  cin >> length >> rotate;
        int *list = new int [length];

        for (int i = 0; i < length; i ++) 
            cin >> list[i];

        Rotate(list, rotate, length);

        for (int i = 0; i < length; i ++) 
            cout << list[i] << " ";
        cout << "\n";
    }
}

inline void Rotate (int* list, int rotate, int length) {
    int round = length / rotate;
    for (int i = 0; i < round; i ++) {
        for (int j = 0; j < rotate / 2; j ++) {
            int tem = list[i * rotate + j];
            list[i * rotate + j] = list[(i +  1 ) * rotate - j - 1];
            list[(i + 1) * rotate - j - 1] = tem;
        }
    }
}