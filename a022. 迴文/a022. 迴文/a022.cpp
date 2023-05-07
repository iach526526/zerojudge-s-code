#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	string st_input;
	cin >> st_input;
	int head = 0, trailer = st_input.length() - 1;
	bool flag = true;
	while (head !=st_input.length() - 1 && trailer>0)
	{
		if (st_input[head] != st_input[trailer])
		{
			flag = false;
			break;
		}
		head++;
		trailer--;

	}
	if (flag)
	{
		cout << "yes";
	}
	else{
		cout << "no";
	}
	
}