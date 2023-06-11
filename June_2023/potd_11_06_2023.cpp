#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class SnapshotArray {
private:
    std::vector<std::map<int, int>> array;
    int snapId;

public:
    SnapshotArray(int length) {
        array.resize(length);
        for (auto& history : array) {
            history[0] = 0;
        }
        snapId = 0;
    }

    void set(int index, int val) {
        array[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snapId) {
        auto& history = array[index];
        auto it = history.upper_bound(snapId);
        return (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */