class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp1,mp2;
        stringstream str1(s1);
        stringstream str2(s2);
        string word;
        while(str1>>word)
        mp1[word]++;
        word="";
        while(str2>>word)
        mp2[word]++;
        vector<string>ans;
        for(auto x:mp1)
        if(!mp2[x.first] && x.second<2)ans.push_back(x.first);
        for(auto x:mp2)
        if(!mp1[x.first] && x.second<2)ans.push_back(x.first);
        return ans;
        

        
    }
};