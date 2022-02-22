#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// Первое задание
//-------------------------------------------------------
template <class T>
class Pair1
{
private:
	T m_first;
	T m_second;
public:
	Pair1(T first, T second)
		: m_first(first), m_second(second)
	{}
	T first() const
	{
		return m_first;
	}
	T second() const
	{
		return m_second;
	}
};

// Второе задание
//-------------------------------------------------------
template <class T, class U>
class Pair2
{
protected:
	T m_fir;
	U m_sec;
public:
	Pair2(T first, U second)
		: m_fir(first), m_sec(second)
	{}
	T first() 
	{
		return m_fir;
	}
	U second() 
	{
		return m_sec;
	}
};

// Третье задание
//-------------------------------------------------------
template <class T>
class Pair
{
protected:
	string t_first;
	T t_second;
public:
	Pair(string first = " ", T second = 0)
		: t_first(first), t_second(second)
	{}
	string first() const
	{
		return t_first;
	}
	T second() const
	{
		return t_second;
	}
};

template <class T>
class StringValuePair : public Pair<T>
{
public:
	StringValuePair(string first, T second) 
	: Pair<T>::Pair(first, second)
	{}
};

//Четвертое задание про Блэкджэк
//-------------------------------------------------------
//class GenericPlayer : public Hand
//{
//protected:
//	string m_name;
//public:
//	GenericPlayer(string name)
//		: Hand(), m_name(name)
//	{}
//	virtual bool isHitting() const = 0;
//	bool isBusted() const
//	{
//		if (GetTotal() > 21)
//			return true;
//		else
//			return false;
//	}
//	void Bust() const
//	{
//		if (isBusted())
//		{
//			cout << "The player " << m_name << " is busted!" << endl;
//		}
//	}
//};

int main()
{
	cout << "The first task" << endl;
	cout << "------------------------------------------------------------" << endl;
	Pair1 <int> p1(6, 9);
	cout << p1.first() << " " << p1.second();
	cout << endl;
	Pair1 <double> p2(3.4, 7.8);
	cout << p2.first() << " " << p2.second();
	cout << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "The second task" << endl;
	cout << "------------------------------------------------------------" << endl;
	Pair2 <int, double> p(6, 7.8);
	cout << p.first() << " " << p.second();
	cout << endl;
	Pair2 <double, int> a(3.4, 5);
	cout << a.first() << " " << a.second() << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "The third task" << endl;
	cout << "------------------------------------------------------------" << endl;
	StringValuePair <int> svp("Amazing", 7);
	cout << svp.first() << " " << svp.second() << endl;
	cout << "------------------------------------------------------------" << endl;
	return 0;
}
