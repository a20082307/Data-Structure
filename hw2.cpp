#include <iostream>
using namespace std;

class Pair {
public: 
    int first, second;

    Pair(int f = 0, int s = 0) {
        this -> first = f;
        this -> second = s;
    }
};

template <class T> 
class stack {
public:
    stack() {
        memory = new T[4];
        this -> size = -1;
        this -> capacity = 4;
    }

    inline void push(T aim) {
        memory[++ size] = aim;
        if (size == capacity - 1) {
            capacity *= 2;
            T* tem_memory = new T [capacity];

            for (int i = 0; i <= size; i ++) 
                tem_memory[i] = memory[i];

            delete [] memory;
            memory = tem_memory;
        }
    }

    inline T pop() {
        if (size >= 0) {
            T ans = memory[size --];
            return ans;
        }
        else {
            throw "Stack is empty now";
        }
    }

    inline T peak() {
        if (size >= 0) {
            return memory[size];
        }
        else {
            throw "Stack is empty now";
        }
    }

private:
    int size;
    int capacity;
    T* memory;
};

int main() {
    stack<Pair> trend;  trend.push(Pair(-1, 0));
    int money, day = 0;
    while (cin >> money) {
        day ++;
        
        while (money <= trend.peak().first) {
            trend.pop();
        }

        cout << day - trend.peak().second << " ";
        trend.push(Pair(money, day));
    }

    cout << "\n";
}