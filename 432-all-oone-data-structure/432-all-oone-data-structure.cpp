/*We have Design a data structure such that we easily find max and min occurence of string
So,I have to use map for counting frequency and set for updating max and min of the element.

Logic:

Every time when we encounter a new element we create a place in map and also insert in the set.

When we the element already found in map then we delete from set and increse the map value and then reinsert the same element in set withnew increment value this help to update the new count in set.

Same thing can be done with the remove functionBut one thing take care that when map elemt count is zero then we delete from map and aldo delete from set .

Now in get max and get min functionwe directly extract dataon O(logn) time.*/

class AllOne {
public:
   //Map for updating frequncy of element
     unordered_map<string,int>mp;
	 //Set for keep track of max and min element
    set<pair<int,string>>s;
    
    AllOne() {
        
    }
    //In  this function Refer point 2
    void inc(string key) {
        //If element not found add it to the map and also insert to the set with increment value
        if(mp.find(key)==mp.end())
        {
            mp[key]++;     
        }
		//If elemt already present to the map we first delete  from the set and update map and resinsert the same 
        else
        {
		//Erasing already present elemt
            s.erase({mp[key],key});
			//increse value
            mp[key]++;
     
        }
          s.insert({mp[key],key});
        
    }
    //Refer point->3
    void dec(string key) {
	//Erase the existing elemt in set as we have to delete
        s.erase({mp[key],key});
		//Decrease the map elemt
        mp[key]--;
		//Reinsert the set with updated value
        s.insert({mp[key],key});
		//If elemet is  empty in map we delete the elemt from map and also from set
        if(mp[key]==0)
        {
            mp.erase(key);
            s.erase({mp[key],key});
        }
        
    
        
    }
    //Refer point 4
    string getMaxKey() {
        if(s.size()==0)
        {
            return "";
        }
        
        auto it=s.rbegin();
        return it->second;
        
    }
    
    string getMinKey() {
        if(s.size()==0){
            return "";
        }
        
        auto it=s.begin();
        return it->second;
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */