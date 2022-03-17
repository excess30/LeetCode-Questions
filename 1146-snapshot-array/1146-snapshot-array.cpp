//Store the values as index,snapid,val why because if we see the get function closely we need to return the value as index and snap id i.e. jo value uss particular index me stored hoga with the given snap id woh return karni hai hume. so hume 3 cheez track karni padegi index, snap_id aur value so humne map ke aandar map bana di. Get function me aagar index map me present hi na ho toh retirn 0 kar do warna uska upper bound leke prev element return kardo (Binary Search ka Concept).

class SnapshotArray {
public:
    
    int snaps=0;
    vector<int>v;
    map<int,map<int,int>>mp;       //index,snap_id,val
    SnapshotArray(int length)
    {
        for(int i=0;i<length;i++)
        {
            v.push_back(0);
        }
    }
    
    void set(int index, int val) 
    {
        v[index]=val;
        mp[index][snaps]=val;
    }
    
    int snap() 
    {
        snaps++;
        return snaps-1;
    }
    
    int get(int index, int snap_id) 
    {
        if(mp.find(index)==mp.end())
        {
            return 0;
        }
        auto it = mp[index].upper_bound(snap_id);
        if(it==mp[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */