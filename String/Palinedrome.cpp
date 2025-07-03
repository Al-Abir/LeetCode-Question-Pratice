#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
          
          if(s.length()==0) return true;
          int start=0;
          int end=s.size()-1;
           while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
        
    }
};


int main(){
       Solution sl;
        string s ;
        cin>>s; 
       bool ans = sl.isPalindrome(s);

       if(ans){
        cout<<"YES\n";
       }else{
        cout<<"No\n";
       }

}