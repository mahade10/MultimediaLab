#include <bits/stdc++.h>
using namespace std;

// Perform Run–length encoding (RLE) data compression algorithm
// on string `str`
string encode(string str)
{
    // stores output string
    string encoding = "";
    int count;

    for (int i = 0; str[i]; i++)
    {
        // count occurrences of character at index `i`
        count = 1;
        while (str[i] == str[i + 1]) {
            count++, i++;
        }

        // append current character and its count to the result
        encoding += to_string(count) + str[i];
    }

    return encoding;
}
int str_to_int(string block){
    int n = 0;
    int d = 1;
    for(int i=block.size()-1; i>=0; i--)
    {
        n += (block[i]-'0')*d;
        //cout<<n<<" ";
        d *= 10;
    }
    return n;

}
string Decrypt(string enc){
    string decrypt="", block="";
    int n;
    for(int i=0;i<enc.size();i++){
        block="";
        while(enc[i]>='0' && enc[i]<'9'){
            block+=enc[i];
            i++;
       }
       n=str_to_int(block);
       while(n--){
           decrypt+=enc[i];
       }
    }
    return decrypt;
}

int main()
{
    string msg,enc;
    ifstream fin;
    fin.open("input.txt");
    getline(fin,msg);
    fin.close();
    enc= encode(msg);
    ofstream fout;
    fout.open("output.txt");
    fout<<"Original: "<<msg<<endl;
    fout<<"Encoded: " << enc<<endl;
    fout<<"Decoded: " <<Decrypt(enc)<<endl;
    fout.close();
    double ratio = msg.size()/(double)enc.size();
    //cout<<"Compression Ratio: "<<ratio<<endl;

    return 0;
}
