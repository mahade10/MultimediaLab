#include<bits/stdc++.h>
using namespace std;

void lzw_encoding(){

    int i,j,n,m,a,id = 0;

    vector<int>enc;
    string tmp,str;
    map<string , int> mp;
    char ch;

    ofstream enc_out;
    enc_out.open("lzw_encoded.txt");

    ifstream input;
    input.open("lzw_in.txt");
    getline(input, str);

    input>>n;

    for(i = 0; i < n; i++){
        input>>ch>>m;
        enc_out<<(int)ch<<" "<<m<<endl;
        cout<<ch<<" "<<m<<endl;
        tmp = "";
        tmp += ch;
        mp[tmp] = m;
        id = max(id, m);
    }
    enc_out<<-1<<" "<<-1<<endl;

    tmp = "";
    for(i = 0; i < str.size(); i++){

        a = mp[tmp];
        tmp += str[i];

        if(!mp[tmp]){
            // entry to the dictionary
            mp[tmp] = ++id;
            // storing prev match entry as output
            enc.push_back(a);
            // initializing string for next
            tmp = "";
            tmp += str[i];
        }
    }
    a = mp[tmp];
    enc.push_back(a);

    enc_out<<enc.size()<<endl;
    cout<<"Encoding : ";
    for(i = 0; i < enc.size(); i++){
        if(i+1 ==  enc.size()){
            cout<<enc[i]<<endl;
            enc_out<<enc[i]<<endl;
        }
        else{
            cout<<enc[i]<<" ";
            enc_out<<enc[i]<<" ";
        }
    }
    //enc_out<<endl;

    input.close();
    enc_out.close();
}

string lzw_deconding(){

    int i, j, in = 0, n, k ,m;
    map<int, string>mp;
    vector<int>code;
    string decd, tmp, str;
    char ch;

    ifstream enc_in;
    enc_in.open("lzw_encoded.txt");

    ofstream output;
    output.open("lzw_decoded.txt");

    for(i = 0; ; i++){
        enc_in>>k>>n;
        //cout<<k<<" "<<n<<endl;
        if(n==-1) break;
        tmp = "";
        tmp += (char)k;
        mp[n] = tmp;
        in++;
    }

    enc_in>>n;
    decd = "";
    for(i = 0; i < n; i++){
        enc_in>>m;
        //code.push_back(m);
        //cout<<m<<endl;
        decd += mp[m];

        if(i == 0){
            tmp = mp[m];
            continue;
        }

        tmp += mp[m][0];
        mp[++in] = tmp;

        tmp = mp[m];
    }

    cout<<"Decoded String : "<<decd<<endl;
    output<<decd<<endl;

    output.close();
    enc_in.close();

    return decd;
}


int main(){
    int i,j,n,m;
    char ch;
    string str, tmp;

    ofstream output;

    lzw_encoding();

    lzw_deconding();

    return 0;
}
