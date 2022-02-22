#include <cassert>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//Функции для работы с вектором из второго задания:

//Первая функция для вывода вектора на экран
void printVec(vector <int> k) 

{
    vector <int> :: const_iterator iter;
    for (iter = k.begin(); iter != k.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
} 
//Вторая функция для подсчета количества различных элементов вектора и вывода итога на экран
void countDif(vector<int> k) 
{
    sort(k.begin(), k.end()); // В данном месте использую алгоритм для сортировки элементов вектора
    int count = 0;
    for (size_t i = 0; i < k.size() - 1; i++)
    {
        if (k[i] != k[i + 1])
        {
            count++;
        }
    }
    if (count == 0)
        cout << "Количество различных элементов: " << count << endl;
    else
        cout << "Количество различных элементов: " << count + 1 << endl;
}


//Первое задание
//-----------------------------------------------------------------------------------------------
class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }
 
    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }


        void resize(int newLength)
        {  
            if (newLength == m_length)
                return;

            if (newLength <= 0)
            {
                erase();
                return;
            }

            int* data = new int[newLength];
            if (m_length > 0)
            {
                int elementsToCopy = (newLength > m_length) ? m_length : newLength;
                for (int index = 0; index < elementsToCopy; ++index)
                    data[index] = m_data[index];
            }
            delete[] m_data;
            m_data = data;
            m_length = newLength;
        }

        void insertBefore(int value, int index)
        {
            assert(index >= 0 && index <= m_length);

            int* data = new int[m_length + 1];

            for (int before = 0; before < index; ++before)
                data[before] = m_data[before];

            data[m_length] = value;

            delete[] m_data;
            m_data = data;
            ++m_length;
        }
       
        void push_back(int value) { insertBefore(value, m_length); }
        //Первое задание.1:
        //Создание аналога функции pop_back в векторах

        void deleteLast(int index)
        {
            assert(index >= 0 && index <= m_length);

                int* pop = new int [m_length - 1];

                for (size_t i = 0; i < m_length - 1; i++)
                {
                    pop[i] = m_data[i];
                }

                delete[] m_data;
                m_data = pop;
                --m_length;
        }

        void pop_back() { deleteLast(m_length); }
        //Первое задание.2:
        //Создаем аналог операции pop_front

        void deleteFirst(int index)
        {
            assert(index >= 0 && index <= m_length);

            int* front = new int[m_length - 1];

            for (size_t i = 1; i < m_length; i++)
            {
                front[i-1] = m_data[i];
            }
            delete[] m_data;
            m_data = front;
            --m_length;
        }

        void pop_front() { deleteFirst(m_length); }
        //Первое задание.3:
        // Функция сортировки массива
        void sort()
        {
            for (size_t k = 0; k < m_length; k++)
            {
                for (size_t i = 0; i < m_length - 1; i++)
                {
                    if (m_data[i] > m_data[i + 1])
                    {
                        int tmp;
                        tmp = m_data[i];
                        m_data[i] = m_data[i + 1];
                        m_data[i + 1] = tmp;
                    }
                }
            }
         }
        //Первое задание.4:
        //Функция для вывода массива на экран
        void print()
        {
            for (size_t i = 0; i < m_length; i++)
            {
                cout << m_data[i] << " ";
            }
            cout << endl;
        }
};
//-----------------------------------------------------------------------------------------------
//Третье задание про класс Hand для игры Blackjack
class Card
{
protected:
    enum Suit { SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4 };
    enum Rank {
        ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5,
        SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10,
        VALET = 10, DAMA = 10, KOROL = 10
    };
    Rank m_rank;
    Suit m_suit;
    bool m_IsFaceUp;
public:
    Card(Rank rank, bool face)
        : m_rank(rank), m_IsFaceUp(face)
    {}
    void Flip(bool face_c)
    {
        if (face_c)
        {
            m_IsFaceUp = false;
        }
        else if (!face_c)
        {
            m_IsFaceUp = true;
        }
    }
    int getValue() const
    {
        return m_rank;
    }
};
class Hand
{
protected:
    vector<Card*> m_Cards;
public:
    Hand(int count)
        : m_Cards(count)
    {}
    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }
    void Clear()
    {
        m_Cards.clear();
    }
    int GetTotal()
    {
        int total = 0;
        for (size_t i = 0; i < m_Cards.size(); i++)
        {
            total += m_Cards[i]->getValue();
        }
        if (total > 21)
		{
			for (size_t i = 0; i < m_Cards.size(); i++)
			{
				if (m_Cards[i]->getValue() == 'ACE')
				{
					total -= 10;
				}
			}
		}
        return total;
    }
};
//-----------------------------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Первое задание" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    ArrayInt arr(5); 
    arr[0] = 9;
    arr[1] = 18;
    arr[2] = 6;
    arr[3] = 3;
    arr[4] = 2;
    arr.print();
    arr.sort();
    arr.print();
    arr.pop_back();
    arr.print();
    arr.pop_front();
    arr.print();
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Второе задание" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    vector <int> myvec = { 10, 10, 9 , 7, 7, 5};
    printVec(myvec); // вызов вышеописанной функции для вывода вектора на экран
    countDif(myvec); // вызов вышеописанной функции для вывода количества различных элементов
    cout << "--------------------------------------------------------------------" << endl;
    return 0;
}
