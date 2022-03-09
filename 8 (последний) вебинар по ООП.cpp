#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
using namespace std;
//Первое задание
template <typename T>
T div(T a, T b)
{
	if (b == 0)
		throw "Division by zero!";
	return a / b;
}
//Второе задание
class Ex
{
private:
	float x;
public:
	Ex(float chislo)
		: x(chislo)
	{}
	float getX()
	{
		return x;
	}
};

Ex p(9);

class Bar
{
private:
	float y;
public:
	Bar(float chislo = 0)
		: y(chislo)
	{}
	float getY()
	{
		return y;
	}
	void set(float a)
	{
		if ((y + a) > 100)
			throw p = a * getY();
		else
			y = a;
	}
};
// Третье задание
class OffTheField
{
private:
	string m_error;
public:
	OffTheField(string error = "Your robot has gone off the field")
		:m_error(error)
	{}
	const char* getError()
	{
		return m_error.c_str();
	}
};

class IllegalCommand
{
private:
	string m_err;
public:
	IllegalCommand(string err = "You have entered an illegal command")
		: m_err(err)
	{}
	const char* getErr()
	{
		return m_err.c_str();
	}
};

class Robot
{
private:
	int m_x;
	int m_y;
public:
	Robot(int x = 0, int y = 0)
		: m_x(x), m_y(y)
	{}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
	void setX(int x)
	{
		m_x = x;
	}
	void setY(int y)
	{
		m_y = y;
	}
	void show()
	{
		cout << "Your robot is at: x = " << getX() << " y = " << getY() << endl;
	}
	void move(string s)
	{
		if (s == "up")
			setY(getY() + 1);
		else if (s == "down")
			setY(getY() - 1);
		else if (s == "left")
			setX(getX() - 1);
		else if (s == "right")
			setX(getX() + 1);
		else
			throw IllegalCommand();

		if (getX() > 10 || getX() < 0 || getY() < 0 || getY() > 10)
			throw OffTheField();
	}
};
int main()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "The first task" << endl;
	cout << "------------------------------------------------------------------" << endl;
	try
	{
		double a, b;
		cin >> a >> b;
		cout << div(a, b) << endl;
	}
	catch (const char* ex)
	{
		cout << "Error: " << ex << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	cout << "The second task" << endl;
	cout << "------------------------------------------------------------------" << endl;
	Bar k(5);
	int n;
	try
	{
		do
		{
			cin >> n;
			k.set(n);
		} while (n);
	}
	catch (Ex exception)
	{
		cout << "Your n = " << n << " and it is too big!" << endl;
		cout << "p = " << p.getX() << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	cout << "The third task" << endl;
	cout << "------------------------------------------------------------------" << endl;
	Robot alf;
	try
	{
		alf.move("right");
		alf.move("up");
		alf.move("right");
		alf.move("up");
		alf.move("up");
		alf.move("up");
		alf.move("left");
		alf.move("up");
		alf.move("left");
		alf.move("up");
		alf.show();
	}
	catch (IllegalCommand& e)
	{
		cout << "Error: " << e.getErr() << endl;
	}
	catch (OffTheField& exs)
	{
		cout << "Error: " << exs.getError() << endl;
	}
	return 0;
}



