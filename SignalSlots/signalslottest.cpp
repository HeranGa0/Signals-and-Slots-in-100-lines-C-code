#include "signalslot.h"

struct Object
{
	void numChanged(int a,int b, int c)
	{
		cout << "emit num Signal!" << endl<<a<<b<<c<<endl;


	}
	void setNum(int a, int b, int c)
	{   //Emit signal
		emitWithParam(numChanged,(a,b,c),(a,b,c));
	}
	int slot(int a,int b,int c) {
		cout << "parent num slot recieved!" << endl << a << b << c << endl;
		return 0;
	}

	void stringChanged(std::string s)
	{
		cout <<s<< " emit string Signal!" << endl;
	}

	void setString(std::string s)
	{
		//emit signal2
		emitWithParam(stringChanged,(s),(s));
	}
};

struct Child : public Object
{
	int childSlot(std::string str)
	{
		cout << "child slot recieved! " << str << endl;
		return 0;
	}
};


int main()
{
	Object obj1;
	Object obj2;
	Child c1;
	
	connect(&obj1, &Object::numChanged, &obj2, &Object::slot);
	connect(&obj2, &Object::stringChanged, &c1, &Child::childSlot);
	obj1.setNum(1,3,4);
	obj2.setString("whereamI");
	return 0;
}
