#include<iostream>
#include<sstream>
#include <iomanip>
using namespace std;


void encrypt()
{
	string sec_key;
	cout << "enter the secret key" << endl;
	cin >> sec_key;

	string msg;
	cout << "enter the message to encrypt it" << endl;
	cin >> msg;

	int num_in_dec;
	int z = 0;
	string encrypt_as_dec = "";
	string encrypt_as_text = "";
	string encrypt_as_hex = "";

	for (int i = 0; i < msg.length(); i++)
	{
		num_in_dec = int(msg[i]) ^ int(sec_key[z]);
		encrypt_as_dec += to_string(num_in_dec);
		encrypt_as_text += char(num_in_dec);
		
		ostringstream num_in_hex;
		num_in_hex<<setfill('0')<<setw(2)<<hex<<num_in_dec;
		encrypt_as_hex += num_in_hex.str();
		
	}
	cout << "message as decimal: " << encrypt_as_dec << endl;
	cout << "message as text: " << encrypt_as_text << endl;
	cout << "message as hex: " << encrypt_as_hex << endl;
}

void decrypt()
{
	string sec_key2;
	cout << "enter the secret key" << endl;
	cin >> sec_key2;

	string msg2;
	cout << "enter hex to decipher to text" << endl;
	cin >> msg2;

	int conv_to_dec, num_in_dec_after_xor;
	int w = 0;
	string decrypt = "";

	for (int q = 0; q < msg2.length(); q += 2)
	{	
		string part = msg2.substr(q, 2);
		int ch = stoul(part, nullptr, 16);
		num_in_dec_after_xor = (int(ch) ^ int(sec_key2[w]));
		decrypt += char(num_in_dec_after_xor);
	}
	cout << decrypt << endl;
}


int main()
{	
	int userinput;

	cout<<"what do u like to do ?"<<endl;
    cout<<"1-Cipher a message"<<endl;
    cout<<"2-Decipher a message"<<endl;
    cout<<"3-End"<<endl;
	
	cin>>userinput;

    if(userinput == 1)
	{
		encrypt();
	}
	else if(userinput == 2)
	{
		decrypt();
	}
	else if(userinput == 3)
	{
		cout << "end" << endl;
	}
}