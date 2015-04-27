#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size <= 1) return 0;
        int s = 0,e = size -1,area=0;

        while(s <= e){
            area = max(area,min(height[s],height[e])*(e-s));
            if(height[e] > height[s]) s++;
            else e--;
        }

        return area;
    }
};

int main(){

    return 0;
}