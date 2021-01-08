#include<bits/stdc++.h>
using namespace std;
string keys[] = {"kp","loli","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    if(num==0){
        output[0] = "";
        return 1;
    }
    int curr = num%10;
    int smalloutput = keypad(num/10,output);
    for(int i =0;i<smalloutput*keys[curr].size();i++){
        output[i+smalloutput] = output[i%smalloutput];
    }
    int i =0 ;
    for(int j =0; j< keys[curr].size();j++){
        for(;i<smalloutput*(j+1);i++){
            output[i] = output[i] + keys[curr][j]; 
        }
    }
    return smalloutput*keys[curr].size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
