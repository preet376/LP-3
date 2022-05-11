#include<iostream>
#include<math.h>
#include<string>
using namespace std;

    string key1 = "";
    string key2 = "";
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
int P4[4] = {2, 4, 3, 1};

int IP[8] = {2, 6, 3, 1, 4, 8, 5, 7};
int IPi[8] = {4, 1, 3, 5, 7, 2, 8, 6};

int EP[8] = {4, 1, 2, 3, 2, 3, 4, 1};

string S0[4][4] = {
        {"01", "00", "11", "10"},
        {"11", "10", "01", "00"},
        {"00", "10", "01", "11"},
        {"11", "01", "11", "10"}
};

string S1[4][4] = {
        {"00", "01", "10", "11"},
        {"10", "00", "01", "11"},
        {"11", "00", "01", "00"},
        {"10", "01", "00", "11"}
};

string permutation(string key,int* type,int len){
    string permuted = "";
    for(int i=0;i<len;i++)
    {
        permuted += key[type[i]-1];
    }
    return permuted;
}

string shift(string key){
    string l = key.substr(0,5);
    string r = key.substr(5,5);
    return l.substr(1,4) + l.substr(0,1) + r.substr(1,4) + r.substr(0,1);
}

string Sbox(string s){
    int r=0,c=0;
    if(s[0] == '0' && s[3] == '0')
        r = 0;
    else if(s[0] == '0' && s[3] == '1')
        r = 1;
    else if(s[0] == '1' && s[3] == '0')
        r = 2;
    else
        r = 3;
    if(s[1] == '0' & s[2] == '0')
        c = 0;
    else if(s[1] == '0' & s[2] == '1')
        c = 1;
    else if(s[1] == '1' & s[2] == '0')
        c = 2;
    else
        c = 3;
    int r1 = 0, c1 = 0; 
    if(s[0+4] == '0' && s[3+4] == '0')
        r1 = 0;
    else if(s[0+4] == '0' && s[3+4] == '1')
        r1 = 1;
    else if(s[0+4] == '1' && s[3+4] == '0')
        r1 = 2;
    else
        r1 = 3;
    if(s[1+4] == '0' & s[2+4] == '0')
        c1 = 0;
    else if(s[1+4] == '0' & s[2+4] == '1')
        c1 = 1;
    else if(s[1+4] == '1' & s[2+4] == '0')
        c1 = 2;
    else
        c1 = 3;
    return S0[r][c]+S1[r1][c1];
}

string XOR(string s1,string s2){
    int size = s1.length();
    string temp;
    for(int i=0;i<size;i++){
        if(s1[i] == '0' & s2[i] == '0')
            temp += '0';
        else if(s1[i] == '0' & s2[i] == '1')
            temp += '1';
        else if(s1[i] == '1' & s2[i] == '0')
            temp += '1';
        else
            temp += '0';
    }
    return temp;
}

void key_generation(string key){
    key1 = permutation(key,P10,10);
    //cout<<key1<<endl;
    key1 = shift(key1);
    //cout<<key1<<endl;
    key1 = permutation(key1,P8,8);
    //cout<<key1<<endl;
    key2 = permutation(key,P10,10);
    //cout<<key2<<endl;
    key2 = shift(shift(shift(key2)));
    //cout<<key2<<endl;
    key2 = permutation(key2,P8,8);
    //cout<<key2<<endl;
}

string encrypt(string pt, string key1,string key2){
    pt = permutation(pt,IP,8);
    //Round 1
    string l = pt.substr(0,4);
    string r = pt.substr(4,4);
    pt = permutation(r,EP,8);
    pt = XOR(pt,key1);
    pt = Sbox(pt);
    pt = permutation(pt,P4,4);
    l = XOR(pt,l);
    //round 1 ended
    pt = r + l;
    //round 2
    l = pt.substr(0,4);
    r = pt.substr(4,4);
    pt = permutation(r,EP,8);
    pt = XOR(pt,key2);
    pt = Sbox(pt);
    pt = permutation(pt,P4,4);
    l = XOR(pt,l);
    //round 2 ended
    pt = l+r;
    string ct = permutation(pt,IPi,8);
    return ct;
}

int main(){
    string pt = "10101011";
    string key = "1100010010";
    //key generation
    key_generation(key);
    cout<<"key1 "<<key1<<endl;
    cout<<"key2 "<<key2<<endl;
    //Encryption 
    string ct = encrypt(pt,key1,key2);
    cout<<"ct "<<ct<<endl;
    string plaintext = encrypt(ct,key2,key1);
    cout<<"pt "<<plaintext<<endl;
    return 0;
}
