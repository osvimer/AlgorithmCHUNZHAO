// 机器人在一个无限大小的 XY 网格平面上行走，从点 (0, 0)
// 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 commands ：
//
// -2 ：向左转 90 度;  -1 ：向右转 90 度
// 1 <= x <= 9 ：向前移动 x 个单位长度
//
// 在网格上有一些格子被视为障碍物 obstacles 。
// 第 i 个障碍物位于网格点  obstacles[i] = (xi, yi) 。
//
// 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，
// 但仍然可以继续尝试进行该路线的其余部分。
//
// 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。
// （即，如果距离为 5 ，则返回 25 ）
//
// 注意：
//    北表示 +Y 方向。
//    东表示 +X 方向。
//    南表示 -Y 方向。
//    西表示 -X 方向。
//
// https://leetcode-cn.com/problems/walking-robot-simulation


// 思路: 迭代操作指令，逐步更新机器人的状态(位置，方向）和最大距离
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        if (commands.empty()) return 0;
        for (vector<int>& v : obstacles) {
            obstacle_set.insert({v[0], v[1]});
        }
        int max_distance = 0;
        for (int i = 0; i < commands.size(); ++i) {
            getNextPostion(obstacles, commands[i]);
            max_distance = max(max_distance, getDistance());
        }
        return max_distance;
    }

    void getNextDirections(int cmd) {
        if (-2 == cmd) direction = (direction + 3) % 4;
        if (-1 == cmd) direction = (direction + 1) % 4;
    }

    void getNextPostion(vector<vector<int>>& obstacles, int cmd) {
        if (cmd < 0) {
            getNextDirections(cmd);
            return;
        }
        pair<int, int> movation = movation_table[direction_table[direction]];
        for (int step = 0; step < cmd; ++step) {
            position.first += movation.first;
            position.second += movation.second;
            if (isObstacle()) {
                position.first -= movation.first;
                position.second -= movation.second;
                return;
            }
        }
    }

    bool isObstacle() {
        return obstacle_set.find(position) != obstacle_set.end();
    }

    int getDistance() {
        return position.first * position.first + position.second * position.second;
    }

private:
    set<pair<int, int>> obstacle_set;
    pair<int, int> position = {0, 0};
    int direction = 0;
    vector<char> direction_table = {'N', 'E', 'S', 'W'};
    map<char, pair<int, int>> movation_table = {
            {'N', {0, 1}},
            {'E', {1, 0}},
            {'S', {0, -1}},
            {'W', {-1, 0}}
    };
};
