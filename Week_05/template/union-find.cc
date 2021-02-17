#include <iostream>
#include <vector>

using namespace std;

class union_find {
 public:
  union_find(int n) : cap_(n), count_(n) {
    parent_.resize(n);
    for (int i = 0; i < n; ++i) {
       parent_[i] = i;
    }
  }

  int find(int node) {
    if (node < 0 || node >= cap_) return -1;
    while (node != parent_[node]) {
      parent_[node] = parent_[parent_[node]];
      node = parent_[node];
    }
    return node;
  }

  void merge(int p, int q) {
    if (p < 0 || p >= cap_ || q < 0 || q >= cap_) return;
    int root_p = find(p); 
    int root_q = find(q);
    if (root_p == root_q) return;
    parent_[root_q] = root_p;
    count_--;
  }

  int count() const {
    return count_;
  }

 private:
  int cap_;
  int count_;
  vector<int> parent_;
};

int main(int argc, const char* argv[]) {
  union_find uf(10);
  vector<vector<int>> nums({{0, 1}, {2, 3, 5, 7}, {4, 6, 8, 9}});
  for (auto& v: nums) {
    for (int i = 1; i < v.size(); ++i) {
      uf.merge(v[i-1], v[i]);
    }
  }
  for (int i = 9; i >= 0; --i) {
    cout << i << "'s parent is " << uf.find(i) << endl;
  }
  cout << "uf.count() = " << uf.count() << endl; 
  return 0;
}
