
#include<bits/stdc++.h>
using namespace std;

string en = "", decr = "",str;

string to_string(int cn){
    string tmp = "";
    while(cn){
        tmp += (char)(cn%10 + 48);
        cn /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

void write(string text, char input_f[] = "binary.encd" , bool check = true){

    //string text = "Nadim";

    ofstream outfile(input_f, ofstream::binary);
    unsigned int size1 = text.size();
    outfile.write(reinterpret_cast<char *>(&size1), sizeof(size1)  );
    outfile.write( text.c_str(), text.size() );
    outfile.close();
}



string read(char input_f[] = "binary.encd", bool check = true){

    ifstream infile(input_f, ifstream::binary);

    unsigned int size1 = 0;
    infile.read(reinterpret_cast<char *>(&size1), sizeof(size1)  );

    string buffer;
    buffer.resize(size1);

    infile.read(&buffer[0],  buffer.size() );
    infile.close();

    //cout << "buffer = \n" << buffer << '\n';
    return buffer;
}

int main(){

    int cn = 0, i, j;
    char ch;

    ifstream run_in;
    ofstream re_dec;

    run_in.open("run_in.txt");
    //run_in.open("run.png");
    //re_dec.open("run2.png");
    re_dec.open("re_dec.txt");

    run_in>>str;

    for(i = 0; i<str.size(); i++){
        cn = 0;
        ch = 0;
        for(j = i; j<str.size() && str[i]==str[j] && (cn+1) < 256; j++){
            cn++;
            ch++;
        }
        i = j - 1;
        en += str[i];
        en += ch;
    }

    //cout<<"Encrypted text : "<<en<<endl;

    write(en);
    en = read();

    // decryption section
    for(i = 0; en[i]; i++){
        if(isalpha(en[i])){
            cn = (int)en[i+1];
            for(j = 0; j < cn; j++){
                decr += en[i];
            }
            i++;
        }
    }

    cout<<"After decryption : "<<decr<<endl;
    re_dec<<decr;

    return 0;
}


