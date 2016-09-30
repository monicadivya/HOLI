#include<stdio.h>
#include<conio.h>
class string {
public:
vector<string> restoreIpAddresses(string s) {
vector<string> result;
solve(0,result,s,4,"");
return result;
}
void solve(int start, vector<string> &result,string &s,int n, string ip){
if(start > s.length())
return;
if(n == 0 && start == s.length()){ 
result.push_back(ip.substr(0,ip.length()-1));
}
if(n == 0 && start < s.length())
return;
for(int i = 1;i < 4;i++){
string temp = s.substr(start,i);
if(temp[0] == '0' && i > 1)
continue;
string value = "255";
if(i == 3 && temp > "255")
continue;
solve(start+i, result, s, n-1, ip + s.substr(start,i)+"."); 
}
}
};
