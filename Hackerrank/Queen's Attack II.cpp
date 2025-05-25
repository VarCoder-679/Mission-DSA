#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>>& obstacles) {
    int up = n - r_q;
    int down = r_q - 1;
    int left = c_q - 1;
    int right = n - c_q;
    int up_left = min(up, left);
    int up_right = min(up, right);
    int down_left = min(down, left);
    int down_right = min(down, right);

    for (const auto& obs : obstacles) {
        int r_o = obs[0];
        int c_o = obs[1];

        if (r_o == r_q) {
            if (c_o < c_q) {
                left = min(left, c_q - c_o - 1);
            } else {
                right = min(right, c_o - c_q - 1);
            }
        } else if (c_o == c_q) {
            if (r_o < r_q) {
                down = min(down, r_q - r_o - 1);
            } else {
                up = min(up, r_o - r_q - 1);
            }
        } else if (abs(r_o - r_q) == abs(c_o - c_q)) {
            if (r_o < r_q && c_o < c_q) {
                down_left = min(down_left, r_q - r_o - 1);
            } else if (r_o < r_q && c_o > c_q) {
                down_right = min(down_right, r_q - r_o - 1);
            } else if (r_o > r_q && c_o < c_q) {
                up_left = min(up_left, r_o - r_q - 1);
            } else {
                up_right = min(up_right, r_o - r_q - 1);
            }
        }
    }

    return up + down + left + right + up_left + up_right + down_left + down_right;
}

int main() {
    int n, k, r_q, c_q;
    cin >> n >> k >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; ++i) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;

    return 0;
}
