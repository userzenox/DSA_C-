#include <iostream>
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        // Flip and invert the row using a for loop
        for (int j = 0; j < (n + 1) / 2; ++j) {
            // Swap and invert the elements
            int temp = matrix[i][j] ^ 1;
            matrix[i][j] = matrix[i][n - 1 - j] ^ 1;
            matrix[i][n - 1 - j] = temp;
        }
    }
    return matrix;
}

int main() {
    std::vector<std::vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    std::vector<std::vector<int>> result = flipAndInvertImage(image);

    for (const auto& row : result) {
        for (int bit : row) {
            std::cout << bit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
