#include <iostream>
#include <cmath>
//The first task
//-----------------------------------------------------------
class Figure
{
public:
    double pi = 3.1415926535;
    virtual double getArea() = 0;
    virtual void Area() = 0;
};
class Parallelogram : public Figure
{
private:
    int a;
    int b;
    double ugol;
public:
    Parallelogram(int dlina, int shirina, double ugol)
        : a (dlina), b(shirina), ugol (ugol)
    {}
    double getArea ()
    {
        return (a * b * (sin(ugol * pi / 180)));
    };
    void Area()
    {
        std::cout << "Your parallelogram is:" << a << "/" << b << "/" << ugol << std::endl;
        std::cout << "Your parallelogram's area is:" << getArea() << " sm" << std::endl;
    };
    friend class Rectangle;
    friend class Square;
    friend class Rhombus;
};
class Circle : public Figure
{
private:
    int r;
public:
    Circle(int radius)
        : r (radius)
    {}
    double getArea()
    {
        return (pi * r * r);
    }
    void Area()
    {
        std::cout << "Your circle has the radius of:" << r  << std::endl;
        std::cout << "Your circle's area is:" << getArea() << " sm" << std::endl;
    };
};
class Rectangle : public Parallelogram
{
public:
    Rectangle(int dlina = 3, int shirina = 6, double ugol = 90)
        : Parallelogram(dlina, shirina, ugol)
    {}
    double getArea()
    {
        return a * b;
    };
    void Area()
    {
        std::cout << "Your rectangle is:" << a << "/" << b << "/" << ugol << std::endl;
        std::cout << "Your rectangle's area is:" << getArea() << " sm" << std::endl;
    };
};
class Square : public Parallelogram
{
public:
    Square(int dlina = 5, int shirina = 5, double ugol = 90)
        : Parallelogram(dlina, shirina, ugol)
    {}
    double getArea()
    {
        return a * b;
    };
    void Area()
    {
        std::cout << "Your Square is:" << a << "/" << b << "/" << ugol << std::endl;
        std::cout << "Your square's area is:" << getArea() << " sm" << std::endl;
    };
};
class Rhombus : public Parallelogram
{
public:
    Rhombus(int dlina, int shirina, double ugol = 30)
        : Parallelogram(dlina, shirina, ugol)
    {}
    double getArea()
    {
        return (a * a * (sin(ugol * pi / 180)));
    };
    void Area()
    {
        std::cout << "Your rhombus is:" << a << "/" << b << "/" << ugol << std::endl;
        std::cout << "Your rhombus's area is:" << getArea() << " sm" << std::endl;
    };
};
//The second task
//-----------------------------------------------------------
class Car
{
private:
    std::string company;
    std::string model;
public:
    Car(std::string company_name = "Hundai", std::string model_name = "Solaris")
        : company(company_name), model(model_name)
    { 
        std::cout << "Your car was made by: " << company << " and it's name is: " << model << std::endl;
    }
};
class PassengerCar :  virtual  public Car
{
public:
    PassengerCar(std::string company_name = "Lada", std::string model_name = "Priora")
        : Car(company_name, model_name)
    {
        std::cout << "Your PassengerCar was made by: " << company_name << " and it's name is: " << model_name << std::endl;
    }
};
class Bus :  virtual public Car
{
public:
    Bus(std::string company_name = "Avtovaz", std::string model_name = "Pazik")
        : Car(company_name, model_name)
    {
        std::cout << "Your Bus was made by: " << company_name << " and it's name is: " << model_name << std::endl;
    }
};
class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string company_name = "BMW", std::string model_name = "X95")
        : Bus(company_name, model_name), PassengerCar(company_name, model_name), Car(company_name, model_name)
    {
        std::cout << "Your Minivan was made by: " << company_name << " and it's name is: " << model_name << std::endl;
    }
};
//The third task
//-----------------------------------------------------------
class Fraction
{
private:
    int up;
    int down;
public:
    Fraction(int upper, int downer = 1)
        : up(upper), down(downer)
    {}
    int getUp() const
    {
        return up;
    }
    int getDown() const
    {
        return down;
    }
    void print()
    {
        std::cout << "your fract is:" << getUp() << "/" << getDown() << std::endl;
    }
    friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
    friend Fraction operator- (const Fraction& f1, const Fraction& f2);
    friend Fraction operator* (const Fraction& f1, const Fraction& f2);
    friend Fraction operator/ (const Fraction& f1, const Fraction& f2);
    friend Fraction operator- (const Fraction& f1);
    friend void operator== (const Fraction& f1, const Fraction& f2);
    friend void operator!= (const Fraction& f1, const Fraction& f2);
    friend void operator< (const Fraction& f1, const Fraction& f2);
    friend void operator> (const Fraction& f1, const Fraction& f2);
    friend void operator<= (const Fraction& f1, const Fraction& f2);
    friend void operator>= (const Fraction& f1, const Fraction& f2);
};
    Fraction operator+ (const Fraction& f1, const Fraction& f2)
    {
        int upper = (f1.up * f2.down) + (f2.up * f1.down);
        int downer = f1.down * f2.down;
        return Fraction(upper, downer);
    }
    Fraction operator- (const Fraction& f1, const Fraction& f2)
    {
        int upper = (f1.up * f2.down) - (f2.up * f1.down);
        int downer = f1.down * f2.down;
        return Fraction(upper, downer);
    }
    Fraction operator- (const Fraction& f1)
    {
        int upper = -f1.up;
        int downer = -f1.down;
        return Fraction(upper, downer);
    }
    Fraction operator* (const Fraction& f1, const Fraction& f2)
    {
        int upper = f1.up * f2.up;
        int downer = f1.down * f2.down;
        return Fraction(upper, downer);
    }
    Fraction operator/ (const Fraction& f1, const Fraction& f2)
    {
        int upper = f1.up * f2.down;
        int downer = f1.down * f2.up;
        return Fraction(upper, downer);
    }
    void operator== (const Fraction& f1, const Fraction& f2)
    {
        if ((f1.up == f2.up) && (f1.down == f2.down))
        {
            std::cout << "Fractions are equal (YES)" << std::endl;
        }
        else
        {
            std::cout << "Fractions are not equal (NO)" << std::endl;
        }
    }
    void operator!= (const Fraction& f1, const Fraction& f2)
    {
        if ((f1.up != f2.up) || (f1.down != f2.down))
        {
            std::cout << "Fractions are not equal (YES)" << std::endl;
        }
        else
        {
            std::cout << "Fractions are equal (NO)" << std::endl;
        }
    }
    void operator< (const Fraction& f1, const Fraction& f2)
    {
        int upper1 = f1.up * f2.down;
        int upper2 = f2.up * f1.down;
        if (upper1 < upper2)
        {
            std::cout << "The first is smaller!" << std::endl;
        }
        else
        {
            std::cout << "The first isn't smaller!" << std::endl;
        }
    }
    void operator> (const Fraction& f1, const Fraction& f2)
    {
        int upper1 = f1.up * f2.down;
        int upper2 = f2.up * f1.down;
        if (upper1 > upper2)
        {
            std::cout << "The first is bigger!" << std::endl;
        }
        else 
        {
            std::cout << "The first isn't bigger!" << std::endl;
        }
    }
    void operator<= (const Fraction& f1, const Fraction& f2)
    {
        int upper1 = f1.up * f2.down;
        int upper2 = f2.up * f1.down;
        if (upper1 <= upper2)
        {
            std::cout << "The first is smaller or equal!" << std::endl;
        }
        else
        {
            std::cout << "The first isn't smaller or equal!" << std::endl;
        }

    }
    void operator>= (const Fraction& f1, const Fraction& f2)
    {
        int upper1 = f1.up * f2.down;
        int upper2 = f2.up * f1.down;
        if (upper1 >= upper2)
        {
            std::cout << "The first is bigger or equal!" << std::endl;
        }
        else
        {
            std::cout << "The first isn't bigger or equal!" << std::endl;
        }

    }
 //The fourth task
//-----------------------------------------------------------
    class Card
    {
    private:
        enum Mast {SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4};
        enum Znach {ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, 
                    SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, 
                    VALET = 10, DAMA = 10, KOROL = 10};
        Znach card;
        bool face_c = true; // rubashka = false
    public:
        Card (const Znach card, bool face)
            : card(card), face_c(face)
        {}
        void Flip(bool face_c)
        {
            if (face_c)
            {
                face_c == false;
            }
            else if (!face_c)
            {
                face_c = true;
            }
        }
        Znach getValue() const
        {
            return card;
        }
};


int main()
{
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "The first task" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    Parallelogram parallelogram(5, 6, 30);
    parallelogram.Area();
    Circle krug(5);
    krug.Area();
    Rectangle pryamougolnik (4,5);
    pryamougolnik.Area();
    Square kvadrat (4,4);
    kvadrat.Area();
    Rhombus romb(6,6);
    romb.Area();
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "The second task" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    Car a;
    PassengerCar b;
    Bus c;
    Minivan d;
    setlocale(LC_ALL, "Russain");
    //В цепочке наследования у меня постоянно выводится конструктор класса Car, что в принципе не противоречит условию задания, где написано только:
    //"Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти»".
    //Проблему алмаза смерти в коде я избежал.
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "The third task" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    Fraction one(7, 8);
    Fraction two(9, 8);
    Fraction sum = one + two;
    Fraction razn = one - two;
    Fraction pow = one * two;
    Fraction del = one / two;
    Fraction minus = -one;
    sum.print();
    razn.print();
    pow.print();
    del.print();
    minus.print();
    one == two;
    one != two;
    Fraction t(2, 3);
    Fraction w(4, 5);
    t < w;
    t > w;
    t <= w;
    t >= w;
    std::cout << "-----------------------------------------------------------" << std::endl;
    return 0;
}