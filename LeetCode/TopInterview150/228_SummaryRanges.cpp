class Solution {
public:
    string makeString(int startN, int LastN)
    {
        if(startN != LastN)
            return to_string(startN) + "->" + to_string(LastN);
        else
            return to_string(startN);
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> stringResult;
        int startN;
        if(nums.size() >= 1)
            startN = nums[0];
        else
            return stringResult;
        bool isContinue = true;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1] != nums[i] + 1)
            {
                isContinue = false;
            }else
            {
                isContinue = true;
            }
            if(i+1 == nums.size()-1)
            {
                if(isContinue)
                    stringResult.push_back(makeString(startN, nums[i+1]));
                else{
                    stringResult.push_back(makeString(startN, nums[i]));
                    stringResult.push_back(makeString(nums[i+1], nums[i+1]));
                }
            }else
            {
                if(!isContinue){
                    stringResult.push_back(makeString(startN, nums[i]));
                    startN = nums[i+1];
                }
            }           
        }
        if(nums.size() == 1)
        {
            stringResult.push_back(to_string(nums[0]));
            return stringResult;
        }
        return stringResult;
    }
};

/*
Another Best Solution

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string output = "";
        int end=0,start=0;
        while(end<nums.size()){
            if(output.length()==0) output+=to_string(nums[end]);
            else if(nums[end]!=nums[end-1]+1){
                if(start!=end-1) output+= "->" + to_string(nums[end-1]);
                ans.push_back(output);
                output="";
                start = end;
                continue;
            }
            end++;
        }
        if(start!=end-1 && start!=end) output+= "->" + to_string(nums[end-1]);
        if(output.length()!=0) ans.push_back(output);
        return ans;
    }
};
*/