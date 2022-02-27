#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    enum Rank {
        ACE = 11, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5,
        SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10,
        JACK = 10, QUEEN = 10, KING = 10
    };
    Card(Rank rank = ACE, Suit s = SPADES, bool face = true)
        : m_Rank(rank), m_Suit (s), m_IsFaceUp(face)
    {}
    void Flip()
    {
        m_IsFaceUp = !(m_IsFaceUp);
    }
    int getValue() const
    {
        int value = 0;
        if (m_IsFaceUp)
        {
            value = m_Rank;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }
    friend ostream& operator<<(ostream& os, const Card& aCard);
protected:
    Rank m_Rank;
    Suit m_Suit;
    bool m_IsFaceUp;
};

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "C", "D", "H", "S" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

class Hand
{
protected:
    vector<Card*> m_Cards;
public:
    Hand()
    {
        m_Cards.reserve(7);
    }
    virtual ~Hand()
    {
        Clear();
    }
    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }
    void Clear()
    {
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete* iter;
            *iter = 0;
        }

        m_Cards.clear();
    }
    int GetTotal() const
    {
        if (m_Cards.empty())
        {
            return 0;
        }

        if (m_Cards[0]->getValue() == 0)
        {
            return 0;
        }

        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
        {
            total += (*iter)->getValue();
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




class GenericPlayer : public Hand
{
protected:
	string m_Name;
public:
    GenericPlayer(const string& name = "")
        :m_Name(name)
    {}

    virtual ~GenericPlayer();

	virtual bool isHitting() const = 0;

	bool isBusted() const
	{
        return (GetTotal() > 21);
	}
	void Bust() const
	{
			cout << "The player " << m_Name << " is busted!" << endl;
	}
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
    friend class House;
};

ostream& operator<< (ostream& out, const GenericPlayer& gener)
{
    out << gener.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!gener.m_Cards.empty())
    {
        for (pCard = gener.m_Cards.begin();pCard != gener.m_Cards.end();pCard++)
        {
            out << *pCard << "\t";
        }


        if (gener.GetTotal() != 0)
        {
            cout << "(" << gener.GetTotal() << ")";
        }
    }
    else
    {
        out << "<empty>";
    }

    return out;
}


class Player : public GenericPlayer
{
public:
    Player (const string&name = "");
    virtual ~Player();
    virtual bool IsHitting () const
    {
        char ans;
        cout << "Do you need a hit?" << endl;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
            return true;
        else
            return false;
    }
    void Win() const
    {
            cout << m_Name << "has won!" << endl;
    }
    void Lose() const
    {
            cout << m_Name << "has lost!" << endl;
    }
    void Push() const
    {
            cout << m_Name << "played a tie!" << endl;
    }

};

class House : public GenericPlayer
{
public:
    House(const string& name = "House");
    virtual ~House();
    virtual bool IsHitting() const
    {
        if (GetTotal() <= 16)
        {
            return true;
        }
    }
    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
        {
            m_Cards[0]->Flip();
        }
        else
        {
            cout << "No card to flip!" << endl;
        }
    }


};


ostream& endll(ostream& out)
{
    out << endl << endl;
    return out;
}

int main()
{   
    cout << "The first task" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    string a;
    cout << "Enter number: ";
    int check = 0;
    do
    {
        cin >> a;
        for (unsigned int i = 0; i < a.size(); i++)
        {
            if (isdigit(a[i]))
            {
                check = 1;
            }
            else if (!isdigit(a[i]))
            {
                cout << "Error! You entered wrong number! Enter number again!" << endl;
                check = 0;
                break;
            }
        }
    } while (check == 0);
    cout << "Your number is: " << a << endl;
    
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "The second task" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "Just a simple text" << endl;
    cout << "Using endl" << endl;
    cout << "Just a simple text No2" << endl;
    cout << endll << "Text after using endll" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    return 0;
}
