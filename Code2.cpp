class Solution {
public:
    void merge(vector<int>& a, int p, int mid, int r) {
        int n1, n2;
        n1 = mid - p + 1;
        n2 = r - mid;
        int l[n1], m[n2];
        int i, j, k;
        for (i = 0; i < n1; i++) {
            l[i] = a[p + i];
        }
        for (j = 0; j < n2; j++) {
            m[j] = a[mid + 1 + j];
        }
        i = 0, j = 0, k = p;
        while (i < n1 && j < n2) {
            if (l[i] <= m[j]) {
                a[k] = l[i];
                i++;
            } else {
                a[k] = m[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            a[k] = l[i];
            i++;
            k++;
        }
        while (j < n2) {
            a[k] = m[j];
            j++;
            k++;
        }
    }
    void mergesort(vector<int>& a, int p, int r) {
        if (p < r) {
            int mid = (p + r) / 2;
            mergesort(a, p, mid);
            mergesort(a, mid + 1, r);
            merge(a, p, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
