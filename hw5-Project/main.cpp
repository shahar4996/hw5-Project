#include <exception>
#include <string>
#include "ChatNet.h"
#include "MySharedPtr.h"
//using namespace std;
#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;


int main() {
    MySharedPtr<int> p1(new int);
    *p1 = 0;
    cout << *p1 << endl;
    cout << (*(p1.get())) << endl;
    MySharedPtr<int> p2(p1); // p1/p2 counter=2
    MySharedPtr<int> p3(new int); // p3 counter =1
    p3 = p1;
    MySharedPtr<int> p4(new int);
    p2 = p4;
    p1 = p2;
    
    
    /*
    string line;
	ChatNet MamatChat("MamatChat", "Admin", "1234");
	while (!cin.eof())
	{
		try
		{
			getline(cin, line);
			MamatChat.Do(line);
		}
		catch (BackSignal&) // Exit
		{
			break;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unexpected Error" << endl;
			return 1;
		}
	}
     */
	return 0;
};
