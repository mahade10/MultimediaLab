
#include<bits/stdc++.h>
using namespace std;

char str[1000000];
string en = "", en1 = "", decr = "";

string to_string(int cn){
    string tmp = "";
    while(cn){
        tmp += (char)(cn%10 + 48);
        cn /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}


int main(){

    int cn = 0, i, j;

    ifstream run_in, encoded_in;
    ofstream decoded,encoded;

    run_in.open("run_in.txt");
    encoded.open("run_encoded.txt");
    decoded.open("run_decoded.txt");


    run_in>>str;

    for(i = 0; str[i]; i++){
        cn = 0;
        for(j = i; str[j] && str[i]==str[j]; j++){
            cn++;
        }
        i = j - 1;
        en += str[i];
        en += '(' + to_string(cn) + ')';
    }

    encoded<<en<<endl;

    //cout<<en<<endl;


    // decryption section

    encoded_in.open("run_encoded.txt");
    encoded_in>>en1;

    for(i = 0; en1[i]; i++){
        if(en1[i] == '('){
            int cnt = 0;
            for(j = i+1; en1[j] && en1[j] != ')'; j++){
                cnt = cnt*10 + (int)(en1[j] - '0');
            }
            for(j = 0; j < cnt; j++){
                decr += en1[i-1];
            }
        }
    }
    //cout<<decr<<endl;
    decoded<<decr<<endl;

    run_in.close();
    encoded.close();
    decoded.close();

    return 0;
}

