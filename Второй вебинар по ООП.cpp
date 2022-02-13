#include <iostream>
#include <string>


class Person
{
private:
    std::string name;
    int age;
    double weight;
    std::string sex;


public:
    Person(std::string name = "Иван", int age = 20, double weight = 55.6, std::string sex = "мужской")
        : name(name), age(age), weight(weight), sex(sex)
    {}
    friend class Student;
    
    void setName(std::string m_name)
    {
        name = m_name;
    }

    void setAge(int m_age)
    {
        age = m_age;
    }

    void setWeight(double m_weight)
    {
        weight = m_weight;
    }
    void setSex(std::string m_sex)
    {
        sex = m_sex;
    }

    void setPerson(std::string setname, int setage, double setweight, std::string setsex)
    {
        name = setname;
        age = setage;
        weight = setweight;
        sex = setsex;
    }
    void printPers()
    {
        std::cout << "Имя:" << name << " Возраст:" << age << " Вес:" << weight << " Пол:" << sex;
    }
};

class Student : public Person
{
private:
    int year;

public:
    static int count;
    Student(std::string name = "Иван", int age = 20, double weight = 55.6, std::string sex = "мужской", int setyear = 2020)
        : Person(name, age, weight, sex), year(setyear)

    {
        count++;
    }

    void setYear(int m_year)
    {
        year = m_year;
    }

    void setStud(std::string name, int age, double weight, std::string sex, int setyear)
    {
        setPerson(name, age, weight, sex);
        year = setyear;
    }

    void printStud()
    {
        printPers();
        std::cout << " Год обучения:" << year << std::endl;
        std::cout << "Количество студентов:" << count << std::endl;
    }
};

int Student::count = 0;

class Fruit
{
private:
    std::string name;
    std::string color;
public:
    Fruit(std::string name = "Fruit", std::string color = "Gray")
        : name(name), color(color)
    {}
    friend class Apple;
    friend class Banana;
    friend class GrannySmith;
};
class Apple : public Fruit
{
public:
    Apple(std::string color, std::string name = "Apple")
        : Fruit(name, color)
    {}
    
    std::string getColor()
    {
        return color;
    }
    std::string getName()
    {
        return name;
    }
};
class Banana : public Fruit
{
public:
    Banana(std::string name = "Banana", std::string color = "Yellow")
        : Fruit(name, color)
    {}
    std::string getColor()
    {
        return color;
    }
    std::string getName()
    {
        return name;
    }
};
class GrannySmith : public Apple
{
public:
    GrannySmith(std::string name = "Granny Smith apple", std::string color = "Green")
        : Apple(color, name)
    {}
    std::string getColor()
    {
        return color;
    }
    std::string getName()
    {
        return name;
    }
};

int main()
{
    //Первое задание
    //--------------------------------------------------------------------------------------
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    setlocale(LC_ALL, "Russian");
    std::cout << "Первое задание" << std::endl;
    Student first("Мансур", 26, 66.7, "мужской", 2023);
    first.setWeight(57.32);
    first.printStud();
    Student second("Владимир", 24, 55.7, "мужской", 2020);
    second.setAge(56);
    second.printStud();
    Student third("Светалана", 27, 52.7, "женский", 2015);
    third.setName("SvetOK");
    third.printStud();
    //Второе задание
   //--------------------------------------------------------------------------------------
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Второе задание" << std::endl;
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
    /*Комментарий к третьему заданию.
    * Необходимо создать родительский класс "Казино", в котором будет два поля: первая и вторая карты соответственно. Значения данных полей будет выбираться случайным образом 
    при помощи генератора случайных чисел с посевом в текущий момент времени, используя функцию srand.
    Класс "Казино" будет наследоваться классом "Игрок", в котором дополнительно будет поле ставок.
    * #include <ctime>
    * #include<cstdlib>
    * class Cazino
    * {
    * private:
        * int firsst_card;
        * int second_card;
    * public:
    *   void setCard(int card)
    * {
    *   srand(static_cast<unsigned int> (time(0)));
    *   card = rand % 14 + 2;
    *   first_card = card;
    *   card = rand % 14 + 2;
    *   second_card = card;
    * }
    * 
    * int getCard1 ()
    * {
    *   return first_card;
    * }
    * 
    * int getCard2 ()
    * {
    *   return second_card;
    * }
    *
    *   Cazino (int first_card, int second_card)
    *   : first_card (first_card), secon_card (second_card)
    *   {}
    *   friend class Player;
    * };
    * class Player : public Cazino
    * {
    * private:
    *   int bet;
    * public:
    *   Player (int bet = 0)
    * : Cazino (first_card, second_card), bet (bet)
    *   {}
    * 
    * int getCard1 ()
    * {
    *   return first_card;
    * }
    * 
    * int getCard2 ()
    * {
    *   return second_card;
    * }
    * 
    * };
    * Далее в функции int main() будет произведено сравнение очков на картах, в случае недобора до 21 очка игроку будет предложено взять дополнительную карту,
    * в соответствии с правилами игры. Данное предложение должно в виде цикла предлагаться игроку, либо пока он не откажется "добирать", либо пока не получит "перебор",
    * когда количество очков на картах превысит 21. Если "перебора" не произошло, производится подсчет отчков на картах Казино, в случае необходимости "добирается" и
    * сравнивается с количеством очков игрока. В случае победы игрока, его количество поставленных денег должно быть умножено на 1.5. Концом игры можно считать достижение
    * определенного количества очков.
    */
    
}