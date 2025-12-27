#include <iostream>
#include"Screen Classes/clsLogin.h"
#include"Core Classes/clsGlobal.h"
using namespace std;



int main()
{
	while (Run && Trials != 0)
	{
		clsLogin::ShowLoginScreen();
	}


	return 0;
}
