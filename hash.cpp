//#include <crypto++/md5.h>
#include <openssl/md5.h>
#include <string.h>
#include <iostream>
#include <unistd.h> //> getcwd
#include <fstream>

 
using namespace std;
 
int main()
{
	string line;
	char pas[1024],buff[1024];


    getcwd( buff, 1024 );
	string CWD(buff);


//-------------------------------------------------------------------------
// Read pas

	ifstream File(CWD + "/pas.dat");
    int i=1;
    while(getline(File, line))
    {
        strcpy( pas, line.c_str() );
        i++;
    }        
    File.close();


	//string pas=12345;
	//cin >> pas;


//-------------------------------------------------------------------------
// count hash


	//	  SHA256 sha256;
	//cout << sha256("Hello World");
	//SHA3.hexdigest("foo");
	string hash=MD5(pas);
	//cout << hash;
	
	
//-------------------------------------------------------------------------
// Write hash

	
	ofstream ofs(CWD + "/hash.dat");
	ofs << hash;
	ofs.close();

return 0;	
}
