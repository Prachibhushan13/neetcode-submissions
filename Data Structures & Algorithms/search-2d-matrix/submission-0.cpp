class Solution {
public:
    bool SearchinRows(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int stR = 0, eR = m - 1;
        while (stR <= eR) {
            int mR = stR + (eR - stR) / 2;
            if (target >= matrix[mR][0] && target <= matrix[mR][n - 1]) {
                return SearchinRows(matrix, target, mR);
            } else if (target >= matrix[mR][n - 1]) {
                stR = mR + 1;
            } else {
                eR = mR - 1;
            }
        }
        return false;
    }
};