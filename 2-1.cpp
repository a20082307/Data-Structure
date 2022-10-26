#include <iostream>
#include <climits>
using namespace std;

int element[200005];

int main() {
    int size = 1;

    while (cin >> element[size])
        size ++;
    element[0] = element[size] = INT_MIN;


    for (int i = 1; i < size; i ++) {
        int left, right, ans = 0;
        left = i - 1;
        right = size - 1;

        bool find = false;
        while (left) {
            if (element[left] > element[i]) {
                find = true;
                ans = left - i;
                break;
            }
            left --;
        }

        while (!find && right > i) {
            if (element[right] > element[i]) {
                ans = right - i;
                break;
            }
            right --;
        }

        cout << ans << " ";
    }
    cout << "\n";
}