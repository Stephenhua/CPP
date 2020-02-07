//=======================================
//解法一：
//========================================

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }
};

//=======================================
//解法二：采用双指针的形式，将数组的起始位置和终止位置加入到不同的数组中，然后分别进行排序；
// 然后分别进行排序，之后用两个指针i和j，初始化时分别指向 starts 和 ends 数组的首位置，
//然后如果i指向 starts 数组中的最后一个位置，或者当 starts 数组上 i+1 位置上的数字大于 ends 数组的i位置上的数时，
//此时说明区间已经不连续了
//========================================

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts,ends;

        for(int i=0;i<n;i++){
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        for(int i=0;j=0;i<n;++i){
            if(i==n-1;||starts[i+1]>ends[i]){
                res.push_back({starts[j],ends[i]});
                j=i+1；
            }
        }
        return res;
    }

};
//=======================================
//解法三：采用先进性判断符加载的过程，然后进行比较的过程
// 时间复杂度：O(n)
// 空间复杂度：O(n^2)
//========================================
class Solution {
private:
    static bool my_sort(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    
    bool in_range(vector<int> &r1, vector<int> &r2) {
        
        if (r1[0] < r2[0] && r1[0] < r2[1] && r1[1] < r2[0] && r1[1] < r2[1])
            return false;

        if (r1[0] > r2[0] && r1[0] > r2[1] && r1[1] > r2[0] && r1[1] > r2[1])
            return false;
        
        return true;
    }
    
    void merge_ranges(vector<int> &r1, vector<int> &r2) {
        
        r1[0] = r1[0] < r2[0] ? r1[0] : r2[0];
        r1[1] = r1[1] > r2[1] ? r1[1] : r2[1];
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        if (!intervals.size())
            return result;
        
        sort(intervals.begin(), intervals.end(), my_sort);
        
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (in_range(result[result.size() -1], intervals[i])) {
                merge_ranges(result[result.size() - 1], intervals[i]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};