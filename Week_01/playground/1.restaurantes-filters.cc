class Solution {
  public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, vector<int>& filters) {
    vector<vector<int>> candidates;
    if (filters.empty()) {
      candidates = restaurants;
    } else {
      for (auto res : restaurants) {
        if (filters[0] == res[2] && filters[1] >= res[3] && filters[2] >= res[4]) {
          candidates.push_back(res);
        }
      }
    }
    sort(candidates.begin(), candidates.end(), [](vector<int>& i, vector<int>& j) {
      return i[0] < j[0];
    });
    sort(candidates.begin(), candidates.end(), [](vector<int>& i, vector<int>& j) {
      return i[1] < j[1];
    });
    vector<int> result;
    for (auto& res : candidates) {
      result.push_back(res[0]);
    }
    return result;
  }
};