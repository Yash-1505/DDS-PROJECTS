#include <iostream>
using namespace std;

int towers[3][20];
int heights[3];

void printTowers(int n) {
    cout << "\n";
    for (int level = n - 1; level >= 0; --level) {
        for (int t = 0; t < 3; ++t) {
            if (level < heights[t]) {
                int sz = towers[t][level];
                for(int s = 0; s < n - sz; ++s) cout << " ";
                for(int s = 0; s < 2*sz-1; ++s) cout << "*";
                for(int s = 0; s < n - sz; ++s) cout << " ";
            } else {
                for(int s = 0; s < n-1; ++s) cout << " ";
                cout << "|";
                for(int s = 0; s < n-1; ++s) cout << " ";
            }
            cout << "  ";
        }
        cout << "\n";
    }
    cout << "\n A";
    for(int s = 0; s < n*2-3; ++s) cout << " ";
    cout << "B";
    for(int s = 0; s < n*2-3; ++s) cout << " ";
    cout << "C\n\n";
}

void move(int from, int to, int n) {
    int disk = towers[from][--heights[from]];
    towers[to][heights[to]++] = disk;
    cout << "Move disk ";
    for(int s = 0; s < disk; ++s) cout << "*";
    cout << " from " << char('A'+from) << " to " << char('A'+to) << endl;
    printTowers(n);
}

void hanoi(int n, int from, int to, int aux, int total) {
    if (n == 1) {
        move(from, to, total);
        return;
    }
    hanoi(n-1, from, aux, to, total);
    move(from, to, total);
    hanoi(n-1, aux, to, from, total);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    for(int i = 0; i < 3; ++i) heights[i] = 0;
    for(int i = n; i >= 1; --i) towers[0][heights[0]++] = i;

    printTowers(n);
    hanoi(n, 0, 2, 1, n);
    cout << "Solved!\n";
    return 0;
}
