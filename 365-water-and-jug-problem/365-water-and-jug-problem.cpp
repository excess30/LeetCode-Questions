class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) 
    {
         return targetCapacity == 0 || targetCapacity <= (long long)jug1Capacity + jug2Capacity && targetCapacity % __gcd(jug1Capacity, jug2Capacity) == 0;
    }
};