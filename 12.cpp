
class RandomizedSet {
public:
    map<int, int> mapp;
    vector<int> arr;

    RandomizedSet() {
        mapp.clear();
        arr.clear();
    }

    bool insert(int val) {
        if (mapp.contains(val)) {
            return false;
        }
        mapp[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!mapp.contains(val)) {
            return false;
        }
        int idx = mapp[val];

        if (idx != arr.size()-1) {
            swap(arr[idx], arr.back());
        }

        arr.pop_back();
        mapp.erase(val);
        return true;
    }

    int getRandom() {
        
        int randomidx = rand()%arr.size();

        return arr[randomidx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */