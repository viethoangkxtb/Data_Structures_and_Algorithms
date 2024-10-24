#include <bits//stdc++.h>
using namespace std;

int main() {

    // Nhập dữ liệu
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    // Trừ chỉ số
    r--;
    c--; 

    // Mảng 3 chiều, na ná 2 cái bảng ghép vào, bảng bên trên lưu mê cung, bảng bên dưới lưu số bậc
    int maze[n][m][2]; 

    const int N = 1e9+513;
    
    // Cho tất cả chỉ số bảng bên dưới là N;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            maze[i][j][1] = N;
        }
    }

    // Nhập dữ liệu bảng bên trên
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j][0];
        }
    }
    
    // Cho bậc của vị trí xuất phát là 1
    maze[r][c][1] = 1;

    // Tạo 2 hàng đợi, 1 hàng đợi lưu chỉ số của hàng, 1 hàng lưu chỉ số của cột
    queue <int> a;
    queue <int> b;

    // Thêm điểm xuất phát vào hàng đợi
    a.push(r);
    b.push(c);

    // Đoạn này để đỡ phải thêm biến mới thôi
    r = n;
    c = m;

    // Biến kiểm tra
    int check = 0;

    // BFS
    while (a.empty() == 0) {

        // Lấy ra điểm ở đầu hàng đợi
        n = a.front();
        m = b.front();
        if (n == 0 || m == 0 || n == r - 1 || m == c - 1) {
            check = 1;
            break;
        }
        
        /* Kiểm tra điểm xung quanh xem có thỏa mãn 3 điều kiện không:
        1. Điểm đó có đi được không (Có bằng 0 hay không)
        2. Điểm đó đã đi qua chưa (Chưa nếu có bậc là N)
        3. Điểm đó có tồn tại không (Nếu điểm lấy ra từ hàng đợi là điểm ở rìa thì sẽ có 1 hướng không có điểm nào) */

        // Kiểm tra điểm bên trên
        if (maze[n + 1][m][0] == 0 && maze[n + 1][m][1] == N) {
            a.push(n + 1);
            b.push(m);
            maze[n + 1][m][1] = maze[n][m][1] + 1;
        }

        // Kiểm tra điểm bên dưới
        if (maze[n - 1][m][0] == 0 && maze[n - 1][m][1] == N) {
            a.push(n - 1);
            b.push(m);
            maze[n - 1][m][1] = maze[n][m][1] + 1;
        }
         
        // Kiểm tra điểm bên trái
        if (maze[n][m - 1][0] == 0 && maze[n][m - 1][1] == N) {
            a.push(n);
            b.push(m - 1);
            maze[n][m - 1][1] = maze[n][m][1] + 1;
        }

        // Kiểm tra điểm bên phải
        if (maze[n][m + 1][0] == 0 && maze[n][m + 1][1] == N) {
            a.push(n);
            b.push(m + 1);
            maze[n][m + 1][1] = maze[n][m][1] + 1;
        }

        // Xóa điểm ở đầu hàng đợi
        a.pop();
        b.pop();
    }

    // Kiểm tra và in ra kết quả
    if (check == 1) {
        cout << maze[n][m][1];
    }
    else {
        cout << -1;
    }
    return 0;
}
