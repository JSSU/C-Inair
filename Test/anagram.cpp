#include <iostream>
#include <vector>
using namespace std;
        int map[26]={};
    bool isAnagram(string s, string t) {

        int slen=s.size();
        int tlen=t.size();
        if(slen!=tlen) return false;
        
        for(int i=0; i<slen;i++)
        {
            map[s[i]-'a']++;
        }
        for(int i=0; i<tlen; i++)
        {
            map[t[i]-'a']--;
            if(map[t[i]-'a']<0)
             return false;
        }
        return true;
    }
    
int main()
{
   cout<<isAnagram("asdfas","sadfsa")<<endl;
   cout<<map[26];
                             
}