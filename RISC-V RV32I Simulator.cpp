#include <bits/stdc++.h> 
using namespace std;
long int PC = 0;
vector <string> registers(32,"0");


vector <string> mem;
string rd, rs, imm,off;
vector <string> staack(16,"0");
void lower(string& str) {
    for (int i = 0; i < str.length(); i++) {

        // convert str[i] to lowercase
        (str[i]) = tolower(str[i]);
    }
}
int reg_to_index(string in) {
    if (in == "zero")
        return 0;
    else if (in == "ra")
        return 1;
    else if (in == "sp")
        return 2;
    else if (in == "gp")
        return 3;
    else if (in == "tp")
        return 4;
    else if (in == "t0")
        return 5;
    else if (in == "t1")
        return 6;
    else if (in == "t2")
        return 7;
    else if (in == "s0")
        return 8;
    else if (in == "s1")
        return 9;
    else if (in == "a0")
        return 10;
    else if (in == "a1")
        return 11;
    else if (in == "a2")
        return 12;
    else if (in == "a3")
        return 13;
    else if (in == "a4")
        return 14;
    else if (in == "a5")
        return 15;
    else if (in == "a6")
        return 16;
    else if (in == "a7")
        return 17;
    else if (in == "s2")
        return 18;
    else if (in == "s3")
        return 19;
    else if (in == "s4")
        return 20;
    else if (in == "s5")
        return 21;
    else if (in == "s6")
        return 22;
    else if (in == "s7")
        return 23;
    else if (in == "s8")
        return 24;
    else if (in == "s9")
        return 25;
    else if (in == "s10")
        return 26;
    else if (in == "s11")
        return 27;
    else if (in == "t3")
        return 28;
    else if (in == "t4")
        return 29;
    else if (in == "t5")
        return 30;
    else if (in == "t6")
        return 31;
}
void parse(string& line, string& rd, string& rs, string& imm) {
    string word;
    stringstream s(line);
    getline(s, word, ' ');
    line = word;
    getline(s, word, ',');
    rd = word;
    getline(s, word, ',');
    rs = word.substr(1, word.size() - 1);
    getline(s, word, ',');
    imm = word.substr(1, word.size() - 1);
}
void parseOff(string& line, string& rd, string& rs, string& off) {
    string word;
    stringstream s(line);
    getline(s, word, ' ');
    line = word;
    getline(s, word, ',');
    rd = word;
    getline(s, word, '(');
    off = word.substr(1, word.size() - 1);
    getline(s, word, ')');
    rs = word;
}
string decimalToBinary20(int n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<20>(n).to_string();

    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<32>(n).to_string();

    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
void add(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
     return;
    signed int s1, s2, d;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    d = s1 + s2;
    registers[reg_to_index(rd)] = decimalToBinary(d);

    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, '0');
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void mul(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1, s2, d;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    d = s1 * s2;
    registers[reg_to_index(rd)] = decimalToBinary(d);

    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, '0');
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void div(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1, s2, d;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();

    if (s2 == 0)
        return;
    d = s1 / s2;
    registers[reg_to_index(rd)] = decimalToBinary(d);

    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, '0');
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void addi(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
        signed int s1, s2, d;
        if (rs == "sp" || rd == "sp")
        {
            s2 = stoi(rsOrimm) / (-4);
        }
        else
        { 
            s2 = stoi(rsOrimm); 
        }
        
        string src1;

        src1 = registers[reg_to_index(rs)];

        int len = src1.length();
        char last_bit = src1[0];
        int rem;

        if (len < 32)
        {
            reverse(src1.begin(), src1.end());
            rem = 32 - len;
            src1.append(rem, '0');
            reverse(src1.begin(), src1.end());
        }

        bitset<32> bits1(src1);
        s1 = bits1.to_ulong();

        d = s1 + s2;


        registers[reg_to_index(rd)] = decimalToBinary(d);

        len = registers[reg_to_index(rd)].length();
        last_bit = registers[reg_to_index(rd)][0];

        if (len < 32)
        {
            reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
            rem = 32 - len;
            registers[reg_to_index(rd)].append(rem, '0');
            reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        }    
}
void sub(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1, s2, d;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();

    d = s1 - s2;
    registers[reg_to_index(rd)] = bitset<32>(d).to_string();
}
void AND (string rd, string rs, string rsOrimm)
{
    if (rd == "zero")
        return;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }


    for (int i = 0; i < 32; i++)
    {
        if (src1[i] == '1' && src2[i] == '1')
            d = d + '1';
        else
            d = d + '0';
    }


    registers[reg_to_index(rd)] = d;
}
void OR(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    long int s1, s2;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }

    for (int i = 0; i < 32; i++)
    {
        if (src1[i] == '1' || src2[i] == '1')
            d = d + '1';
        else
            d = d + '0';
    }


    registers[reg_to_index(rd)] = d;
}
void XOR(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    long int s1, s2;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }


    for (int i = 0; i < 32; i++)
    {
        if ((src1[i] == '0' && src2[i] == '1') || (src1[i] == '1' && src2[i] == '0'))
            d = d + '1';
        else
            d = d + '0';
    }

    registers[reg_to_index(rd)] = d;

}
void andi(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }

    src2 = decimalToBinary(stoi(rsOrimm));

    len = src2.length();
    last_bit = src2[0];

    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        if (stoi(rsOrimm) < 0)
            src2.append(rem, last_bit);
        else
            src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }

    for (int i = 0; i < 32; i++)
    {
        if (src1[i] == '1' && src2[i] == '1')
            d = d + '1';
        else
            d = d + '0';
    }


    registers[reg_to_index(rd)] = d;

}
void ori(string rd, string rs, string rsOrimm)
{
    if (rd == "zero")
        return;
    signed int s1;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }

    src2 = decimalToBinary(stoi(rsOrimm));
    len = src2.length();
    last_bit = src2[0];

    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        if (stoi(rsOrimm) < 0)
            src2.append(rem, last_bit);
        else
            src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }

    for (int i = 0; i < 32; i++)
    {
        if (src1[i] == '1' || src2[i] == '1')
            d = d + '1';
        else
            d = d + '0';
    }

    registers[reg_to_index(rd)] = d;


}

void xori(string rd, string rs, string rsOrimm)
{
    if (rd == "zero")
        return;
    signed int s1;
    string src1, src2, d;
    d = "";
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }

    src2 = decimalToBinary(stoi(rsOrimm));

    len = src2.length();
    last_bit = src2[0];

    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        if (stoi(rsOrimm) < 0)
            src2.append(rem, last_bit);
        else
            src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }

    for (int i = 0; i < 32; i++)
    {
        if ((src1[i] == '0' && src2[i] == '1') || (src1[i] == '1' && src2[i] == '0'))
            d = d + '1';
        else
            d = d + '0';
    }


    registers[reg_to_index(rd)] = d;
    }
    
void slt(string rd, string rs, string rsOrimm)
    {
        if (rd == "zero")
            return;
        signed int s1, s2;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();

    if (s1 < s2)
        registers[reg_to_index(rd)] = "00000000000000000000000000000001"; //32 bit 1
    else
    registers[reg_to_index(rd)] = "00000000000000000000000000000000"; // 32 bit 0

    cout << s1 << "  s1   " << endl;
    cout << s2 << "   s2  " << endl;
    cout << registers[reg_to_index(rd)] << endl; 
    }
void slti(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1, s2;
    s2 = stoi(rsOrimm);
    string src1;
    src1 = registers[reg_to_index(rs)];


    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }





    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();

    if (s1 < s2)
        registers[reg_to_index(rd)] = "00000000000000000000000000000001"; //32 bit 1
    else
        registers[reg_to_index(rd)] = "00000000000000000000000000000000"; // 32 bit 0

}
void sltu(string rd, string rs, string rsOrimm){
    if (rd == "zero")
        return;
    unsigned int s1, s2;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];

    int len = src1.length();
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, '0');
        reverse(src1.begin(), src1.end());

    }

    len = src2.length();


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, '0');
        reverse(src2.begin(), src2.end());

    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    if (s1 < s2)
        registers[reg_to_index(rd)] = "00000000000000000000000000000001"; //32 bit 1
    else
        registers[reg_to_index(rd)] = "00000000000000000000000000000000"; // 32 bit 0
}
void sltiu(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    unsigned int s1;
    signed long int s2;
    s2 = stoi(rsOrimm);

    string src1;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, '0');
        reverse(src1.begin(), src1.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();



    if (s1 < s2)
        registers[reg_to_index(rd)] = "00000000000000000000000000000001"; //32 bit 1
    else
        registers[reg_to_index(rd)] = "00000000000000000000000000000000"; // 32 bit 0

}
void sll(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];
    unsigned int s1, s2, d;


    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }


    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    d = s1 << s2;

    registers[reg_to_index(rd)] = decimalToBinary(d);


    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, last_bit);
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void slli(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    unsigned int s1, s2, d;
    s2 = stoi(rsOrimm);
    string src1;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();

    d = s1 << s2;

    registers[reg_to_index(rd)] = decimalToBinary(d);


    len = registers[reg_to_index(rd)].length();
   // last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, last_bit);
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }

}
void srl(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];
    unsigned int s1, s2, d;


    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();

    d = s1 >> s2;

    registers[reg_to_index(rd)] = decimalToBinary(d);


    len = registers[reg_to_index(rd)].length();

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, '0');
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }

}
void srli(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    unsigned int s1, s2, d;
    s2 = stoi (rsOrimm);
    string src1;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();


    registers[reg_to_index(rd)] = decimalToBinary(s1 >> s2);


    len = registers[reg_to_index(rd)].length();

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, '0');
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void sra(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    src2 = registers[reg_to_index(rsOrimm)];
    signed int s1, s2, d;


    int len = src1.length();
    char last_bit = src1[0];
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    d = s1 >> s2;

    registers[reg_to_index(rd)] = decimalToBinary(d);


    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, last_bit);
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void srai(string rd, string rs, string rsOrimm) {
    if (rd == "zero")
        return;
    string src1, src2;
    src1 = registers[reg_to_index(rs)];
    signed int s1, s2, d;
    s2 = stoi(rsOrimm);

    int len = src1.length();
    char last_bit = src1[0];
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }

    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();

    d = s1 >> s2;

    registers[reg_to_index(rd)] = decimalToBinary(d);

    len = registers[reg_to_index(rd)].length();
    last_bit = registers[reg_to_index(rd)][0];

    if (len < 32)
    {
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
        rem = 32 - len;
        registers[reg_to_index(rd)].append(rem, last_bit);
        reverse(registers[reg_to_index(rd)].begin(), registers[reg_to_index(rd)].end());
    }
}
void beq(string rd, string rs, string rsOrimm) {
    
    string src1, src2;
    src1 = registers[reg_to_index(rd)];
    src2 = registers[reg_to_index(rs)];
    
    if (stoi(src1) == stoi(src2))
        PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label
}
void bne(string rd, string rs, string rsOrimm) {
    
    string src1, src2;
    src1 = registers[reg_to_index(rd)];
    src2 = registers[reg_to_index(rs)];

    if (stoi(src1) != stoi(src2))
        PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label
}
void blt(string rd, string rs, string rsOrimm) {
    signed int s1, s2;
    
    string src1, src2;
    src1 = registers[reg_to_index(rd)];
    src2 = registers[reg_to_index(rs)];


    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();
    last_bit = src2[0];


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, last_bit);
        reverse(src2.begin(), src2.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();



    if (s1 < s2)
        PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label

}
void bltu(string rd, string rs, string rsOrimm) {
    signed int s1, s2;
    
    string src1, src2;
    src1 = registers[reg_to_index(rd)];
    src2 = registers[reg_to_index(rs)];


    int len = src1.length();
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, '0');
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    if (s1 < s2)
        PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label
}
void bge(string rd, string rs, string rsOrimm)
{
    signed int s1, s2;
      
        string src1, src2;
        src1 = registers[reg_to_index(rd)];
        src2 = registers[reg_to_index(rs)];


        int len = src1.length();
        char last_bit = src1[0];
        int rem;


        if (len < 32)
        {
            reverse(src1.begin(), src1.end());
            rem = 32 - len;
            src1.append(rem, last_bit);
            reverse(src1.begin(), src1.end());
        }


        len = src2.length();
        last_bit = src2[0];


        if (len < 32)
        {
            reverse(src2.begin(), src2.end());
            rem = 32 - len;
            src2.append(rem, last_bit);
            reverse(src2.begin(), src2.end());
        }



        bitset<32> bits1(src1);
        s1 = bits1.to_ulong();
        bitset<32> bits2(src2);
        s2 = bits2.to_ulong();



        if (s1 >= s2)
            PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label

}
void bgeu(string rd, string rs, string rsOrimm) {
    signed int s1, s2;
    
    string src1, src2;
    src1 = registers[reg_to_index(rd)];
    src2 = registers[reg_to_index(rs)];


    int len = src1.length();
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, '0');
        reverse(src1.begin(), src1.end());
    }


    len = src2.length();


    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }



    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();


    if (s1 >= s2)
        PC = stoi(rsOrimm) - 4; //PC will go to the address stored in the label

}
void lui(string rd, int rsOrimm) {
    if (rd == "zero")
        return;
    signed int s1, s2;
    s2 = rsOrimm;
    string src1, src2, d;
    src1 = registers[reg_to_index(rs)];

    d = decimalToBinary20(s2);

    int len = d.length();
    char last_bit = d[0];
    int rem;
    if (len < 20)
    {
        reverse(d.begin(), d.end());
        rem = 20 - len;
        if (s2 < 0)
            d.append(rem, last_bit);
        else
            d.append(rem, '0');
        reverse(d.begin(), d.end());
    }


    for (int i = 0; i < 12; i++)
    {
        d = d + '0';
    }

    registers[reg_to_index(rd)] = d;
}
void auipc(string rd, int rsOrimm) {
    signed int s1, s2;
    s2 = rsOrimm;
    string src1, src2, d;

    d = decimalToBinary20(s2);

    int len = d.length();
    char last_bit = d[0];
    int rem;
    if (len < 20)
    {
        reverse(d.begin(), d.end());
        rem = 20 - len;
        if (s2 < 0)
            d.append(rem, last_bit);
        else
            d.append(rem, '0');
        reverse(d.begin(), d.end());
    }
    for (int i = 0; i < 12; i++)
    {
        d = d + '0';
    }

    src1 = d;
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();

    src2 = decimalToBinary(s1 + PC);

    len = src2.length();
    last_bit = src2[0];
    if (len < 32)
    {
        reverse(src2.begin(), src2.end());
        rem = 32 - len;
        src2.append(rem, '0');
        reverse(src2.begin(), src2.end());
    }
    registers[reg_to_index(rd)] = src2;

}

void jal(string rd, string rsOrimm) {
    if (rd != "zero")
        registers[reg_to_index(rd)] = decimalToBinary(PC + 4); //save the address that it will return to when done with the label
    PC = stoi(rsOrimm)-4; //PC will go to the address stored in the label
}

void jalr(string rd, string rs, string rsOrimm) {
   signed int s1;
    string src1;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, '0');
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    if (rd == "zero")
        registers[reg_to_index(rd)] = decimalToBinary(PC + 4); //save the address that it will return to when done with the label
    PC = stoi(rsOrimm) - 4 + s1;
}






void lw(string rd, string rs, int off) { 
   string src1,d;
    
    unsigned int s1;
    src1 = registers[reg_to_index(rs)];
    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();

    if (rs == "sp")
    {
        off = off / (-4);
        registers[reg_to_index(rd)] = decimalToBinary(stoi(staack[s1 + off]));

    }
    else
    {
        registers[reg_to_index(rd)] = decimalToBinary(stoi(mem[s1 + off]));
    }
    

}
void lh(string rd, string rs, int off) {
    unsigned int s1;
    string src1, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    //t2sm s1 into 2 or 4 b substr mn LSB
    src1 = src1.substr(16, 31);
    last_bit = src1[0];
    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    registers[reg_to_index(rd)] = decimalToBinary(stoi(mem[s1 + off]));

}
void lb(string rd, string rs, int off) {
    unsigned int s1;
    string src1, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    //t2sm s1 into 2 or 4 b substr mn LSB
    src1 = src1.substr(24, 31);
     last_bit = src1[0];
    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    registers[reg_to_index(rd)] = decimalToBinary(stoi(mem[s1 + off]));

}
void lhu(string rd, string rs, int off) {
    unsigned int s1;
    string src1, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    //t2sm s1 into 2 or 4 b substr mn LSB
    src1 = src1.substr(16, 31);
     last_bit = '0';
    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    registers[reg_to_index(rd)] = decimalToBinary(stoi(mem[s1 + off]));

}
void lbu(string rd, string rs, int off) {
    unsigned int s1;
    string src1, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;


    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    //t2sm s1 into 2 or 4 b substr mn LSB
    src1 = src1.substr(24, 31);
    last_bit = '0';
    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    registers[reg_to_index(rd)] = decimalToBinary(stoi(mem[s1 + off]));

}
void sw(string rs, string rd, int off) {
    
    if (rd == "sp")
    {
        off = off / (-4);
        string src1, src2, d;
        unsigned int s1, s2;
        src1 = registers[reg_to_index(rs)];

        int len = src1.length();
        char last_bit = src1[0];
        int rem;

        if (len < 32)
        {
            reverse(src1.begin(), src1.end());
            rem = 32 - len;
            src1.append(rem, last_bit);
            reverse(src1.begin(), src1.end());
        }

        src2 = registers[reg_to_index(rd)];
        bitset<32> bits2(src2);
        s2 = bits2.to_ulong();

        staack[s2 + off] = src1;
    }
    else
    {
        string src1, src2, d;
        unsigned int s1, s2;
        src1 = registers[reg_to_index(rs)];

        int len = src1.length();
        char last_bit = src1[0];
        int rem;

        if (len < 32)
        {
            reverse(src1.begin(), src1.end());
            rem = 32 - len;
            src1.append(rem, last_bit);
            reverse(src1.begin(), src1.end());
        }
        bitset<32> bits1(src1);
        s1 = bits1.to_ulong();
        d = to_string(s1);
        src2 = registers[reg_to_index(rd)];
        bitset<32> bits2(src2);
        s2 = bits2.to_ulong();


        mem[s2 + off] = d;

    }
}
void sh(string rs, string rd, int off) {


    unsigned int s1, s2;
    string src1, src2, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    d = to_string(s1);
    // t2sm d into 2 or 4 b substr mn LSB
    d = d.substr(16, 31);
    last_bit = src1[0];
    if (len < 32)
    {
        reverse(d.begin(), d.end());
        rem = 32 - len;
        d.append(rem, last_bit);
        reverse(d.begin(), d.end());
    }
    src2 = registers[reg_to_index(rd)];
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();
    mem[s2 + off] = d;
}
void sb(string rs, string rd, int off) {


    unsigned int s1, s2;
    string src1, src2, d;
    src1 = registers[reg_to_index(rs)];

    int len = src1.length();
    char last_bit = src1[0];
    int rem;

    if (len < 32)
    {
        reverse(src1.begin(), src1.end());
        rem = 32 - len;
        src1.append(rem, last_bit);
        reverse(src1.begin(), src1.end());
    }
    src1 = src1.substr(24, 31);
    bitset<32> bits1(src1);
    s1 = bits1.to_ulong();
    d = to_string(s1);
    last_bit = src1[0];
    if (len < 32)
    {
        reverse(d.begin(), d.end());
        rem = 32 - len;
        d.append(rem, last_bit);
        reverse(d.begin(), d.end());
    }
    src2 = registers[reg_to_index(rd)];
    bitset<32> bits2(src2);
    s2 = bits2.to_ulong();
    mem[s2 + off] = d;
}

void printer() {
    cout << "PC value is: " << PC;
    cout << endl << "Memory content: "<<endl;
    for (int i = 0; i < mem.size(); i++) {
        cout << 4 * i << '.';
        if (mem[i].empty())
            cout << "Empty";
        else
            cout << mem[i];
        cout << endl;
    }
    cout << endl;
    cout << "Registers' Content: " << endl;
    for (int i = 0; i < registers.size(); i++) {
        cout << i << '.';
        if (registers[i].empty())
            cout << "Empty";
        else
            cout << registers[i];
        cout << endl;
    }

}
int main()
{
    int count = 0;
    ifstream datar("data.txt");
    string line;
    int max=-1;
    
    while (getline(datar, line, ','))
    {
        if (stoi(line) > max)
            max = stoi(line);
    }
    int init_size = (max / 4)+1;
    mem.resize(init_size);
    datar.close();
    datar.open("data.txt");
    
    string word1,word2;
    vector <pair<string, string>> dat_add;
    if (datar.is_open())
    {
        int i = 0;
        while (getline(datar, line))
        {
            stringstream s(line);
            getline(s, word1, ',');
            if (word1 != "") {
                getline(s, word2, '\n');
                dat_add.push_back(make_pair(word1, word2));
                i++;
            }
        }
    }
    else cout << "Unable to open file";
    for (int i = 0; i < dat_add.size(); i++) {
        mem[stoi(dat_add[i].second)/4] = dat_add[i].first;
    }
    datar.close();
    cout << endl;
    ifstream coder("fibo.txt");
    getline(coder, line);
    long int start_address = stoi(line);
   mem.resize(start_address/4);
   PC = start_address;

    if (coder.is_open())
    {
        while (getline(coder, line))
        {
            lower(line);
            mem.push_back(line);
        }
        coder.close();
    }
    else cout << "Unable to open file";     
    cout << endl << "test:" << endl;
    printer();
    int insts = PC / 4;
    int num_insts = mem.size() - (start_address / 4);
    string word;
    // registers.at(8) = "00000000000000000000000000001111";
    // registers.at(5) = "00000000000000000000000000000001";
    // registers.at(6) = "00000000000000000000000000000001";
    // registers.at(9) = "00000000000000000000000000000001";
    for (PC;(PC/4) < mem.size(); PC+=4) {
        word = mem.at(PC / 4);
        cout << endl <<"current ins: " <<word << endl;
        stringstream s(word);
        getline(s, line, ' ');
        if (line == "fence" || line == "ecall" || line == "ebreak")
        {
        printer();
        break;
        }
        else if (line == "lui" || line == "auipc" || line == "jal") {
            string wword,rrd,iimm;
            stringstream s(word);
            getline(s, word1, ' ');
            wword = word1;
            getline(s, word1, ',');
            rrd = word1;
            getline(s, word1, ',');
            iimm = word1.substr(1, word1.size() - 1);
        if (wword == "lui")
            lui(rrd,stoi(iimm));
        else if (wword == "auipc")
            auipc(rrd,stoi(iimm));
        else if (wword == "jal")
            jal(rrd,(iimm));
        }
        else if (line == "lb" || line == "lh" || line == "lw" || line == "lbu" || line == "lhu" || line == "sb" || line == "sh" || line == "sw") {
            parseOff(word, rd, rs, off);
            if (rd == "zero")
                continue;
            if (word=="lb")
                lb(rd,rs,stoi(off));
            else if(word == "lh")
                lh(rd,rs,stoi(off));
            else if (word == "lw")
                lw(rd,rs,stoi(off));
            else if (word == "lbu")
                lbu(rd,rs,stoi(off));
            else if (word == "lhu")
                lhu(rd,rs,stoi(off));
            else if (word == "sb")
                sb(rd,rs,stoi(off));
            else if (word == "sh")
                sh(rd,rs,stoi(off));
            else if (word == "sw")
                sw(rd,rs,stoi(off));
        }
        else {
            parse(word, rd, rs, imm);
            if (word == "add")
                add(rd, rs, imm);
            else if (word == "addi")
                addi(rd, rs, imm);
            else if (word == "mul")
                mul(rd, rs, imm);
            else if (word == "div")
                div(rd, rs, imm);
            else if (word == "sub")
                sub(rd, rs, imm);
            else if (word == "sll")
                sll(rd, rs, imm);
            else if (word == "slli")
                slli(rd, rs, imm);
            else if (word == "srl")
                srl(rd, rs, imm);
            else if (word == "srli")
                srli(rd, rs, imm);
            else if (word == "sra")
                srai(rd, rs, imm);
            else if (word == "srai")
                srai(rd, rs, imm);
            else if (word == "xor")
                XOR(rd, rs, imm);
            else if (word == "xori")
                xori(rd, rs, imm);
            else if (word == "or")
                OR(rd, rs, imm);
            else if (word == "ori")
                ori(rd, rs, imm);
            else if (word == "and")
                AND(rd, rs, imm);
            else if (word == "andi")
                andi(rd, rs, imm);
            else if (word == "slt")
                slt(rd, rs, imm);
            else if (word == "slti")
                slti(rd, rs, imm);
            else if (word == "sltu")
                sltu(rd, rs, imm);
            else if (word == "sltiu")
                sltiu(rd, rs, imm);
            else if (word == "beq")
                beq(rd, rs, imm);
            else if (word == "bne")
                bne(rd, rs, imm);
            else if (word == "blt")
                blt(rd, rs, imm);
            else if (word == "bge")
                bge(rd, rs, imm);
            else if (word == "bltu")
                bltu(rd, rs, imm);
            else if (word == "bgeu")
                bgeu(rd, rs, imm);
            else if (word == "jalr")
                jalr(rd, rs, imm);
        }
        count++;
        printer();
    }
    cout << endl << endl << count;
    return 0;
}