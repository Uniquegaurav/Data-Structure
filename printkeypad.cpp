#include<bits/stdc++.h>
using namespace std;
string keys[] = {"kp","loli","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void PrintKey(int num ,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    for(int j = 0;j < keys[num%10].size();j++){
        PrintKey(num/10,keys[num%10][j]+output);
    }
}
void printKeypad(int num){
   string output  = "";
   PrintKey(num,output);
}
int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}
