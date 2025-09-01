#include <bits/stdc++.h>
using namespace std;

class NStack {
    int* arr;
    int* top;
    int* next;
    int n, s;
    int freeSpot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for (int i = 0; i < n; i++)
            top[i] = -1;

        for (int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        next[s - 1] = -1;

        freeSpot = 0;
    }

    bool push(int x, int m) {
        if (freeSpot == -1)
            return false;

        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

// 🧪 Sample main() function
int main() {
    // Create 3 stacks in an array of size 10
    NStack st(3, 10);

    // Push elements into different stacks
    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);

    cout << "Pop from Stack 1: " << st.pop(1) << endl; // Should return 20
    cout << "Pop from Stack 2: " << st.pop(2) << endl; // Should return 30
    cout << "Pop from Stack 3: " << st.pop(3) << endl; // Should return 40
    cout << "Pop from Stack 1: " << st.pop(1) << endl; // Should return 10
    cout << "Pop from Stack 1: " << st.pop(1) << endl; // Should return -1 (empty)

    // Push more to test reuse of freed space
    st.push(50, 2);
    st.push(60, 2);

    cout << "Pop from Stack 2: " << st.pop(2) << endl; // Should return 60

    return 0;
}
