#include<iostream>
using namespace std;

// Третье, четвертое и пятое задания:
//class Deck : public Hand
//{
//public:
//    Deck()
//    {
//        m_Cards.reserve(52);
//    }
//    void Populate()
//    {
//        Clear();
//        for (size_t i = Card::CLUBS; i <= Card::SPADES; i++)
//        {
//            for (size_t k = Card::TWO; k <= Card::ACE; k++)
//            {
//                Add(new Card(static_cast<Card::Rank> (k),
//                    static_cast<Card::Suit> (i)));
//            }
//        }
//    }
//    void Shuffle()
//    {
//        random_shuffle(m_Cards.begin(), m_Cards.end());
//    }
//    void Deal(Hand& aHand)
//    {
//        if (!m_Cards.empty())
//        {
//            aHand.Add(m_Cards.back());
//            m_Cards.pop_back();
//        }
//        else
//        {
//            cout << "Out of cards. Can't deal :(";
//        }
//    }
//    void AdditionalCards(GenericPlayer& gener)
//    {
//        cout << endl;
//        while (!gener.isBusted() && gener.isHitting())
//        {
//            Deal(gener);
//            cout << gener << endl;
//
//            if (gener.isBusted())
//            {
//                gener.Bust();
//            }
//        }
//    }
//
//};
//
//class Game
//{
//protected:
//    Deck m_Deck;
//    House m_House;
//    vector<Player> m_Players;
//public:
//    Game(const vector<string>& names)
//    {
//        vector<string>::const_iterator pName;
//        for (pName = names.begin(); pName != names.end(); pName++)
//        {
//            m_Players.push_back(Player(*pName));
//        }
//        srand(static_cast<unsigned int>(time(0)));
//        m_Deck.Populate();
//        m_Deck.Shuffle();
//    }
//
//    ~Game();
//    void Play()
//    {
//        vector<Player>::iterator pPlayer;
//        for (size_t i = 0; i < 2; i++)
//        {
//            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//            {
//                m_Deck.Deal(*pPlayer);
//            }
//            m_Deck.Deal(m_House);
//        }
//
//        m_House.FlipFirstCard();
//
//        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//        {
//            cout << *pPlayer << endl;
//        }
//        cout << m_House << endl;
//
//        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//        {
//            m_Deck.AdditionalCards(*pPlayer);
//        }
//
//        m_House.FlipFirstCard();
//        cout << endl << m_House;
//
//        m_Deck.AdditionalCards(m_House);
//
//        if (m_House.isBusted())
//        {
//            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//            {
//                if (!(pPlayer->isBusted()))
//                {
//                    pPlayer->Win();
//                }
//            }
//        }
//        else
//        {
//            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//            {
//                if (!(pPlayer->isBusted()))
//                {
//                    if (pPlayer->GetTotal() > m_House.GetTotal())
//                    {
//                        pPlayer->Win();
//                    }
//                    else if (pPlayer->GetTotal() < m_House.GetTotal())
//                    {
//                        pPlayer->Lose();
//                    }
//                    else
//                    {
//                        pPlayer->Push();
//                    }
//                }
//            }
//        }
//        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
//        {
//            pPlayer->Clear();
//        }
//        m_House.Clear();
//    }
//
//};
//int main()
//{
//    cout << "\t\tWelcome to Blackjack!\n\n";
//    int numPlayers = 0;
//    while (numPlayers < 1 || numPlayers > 7)
//    {
//        cout << "How many players? (1 - 7): ";
//        cin >> numPlayers;
//    }
//    vector<string> names;
//    string name;
//    for (int i = 0; i < numPlayers; ++i)
//    {
//        cout << "Enter player name: ";
//        cin >> name;
//        names.push_back(name);
//    }
//    cout << endl;
//
//    Game aGame(names);
//    char again = 'y';
//    while (again != 'n' && again != 'N')
//    {
//        aGame.Play();
//        cout << "\nDo you want to play again? (Y/N): ";
//        cin >> again;
//    }
//    return 0;
//}

// Первое и второе задания:

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int m_day = 0, int m_month = 0, int m_year = 0)
		: day(m_day), month(m_month), year(m_year)
	{}

	void setDay(int m_day)
	{
		day = m_day;
	}
	void setMonth(int m_month)
	{
		month = m_month;
	}
	void setYear(int m_year)
	{
		year = m_year;
	}
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}

	friend ostream& operator<< (ostream& out, const Date& date);
	friend void compareDate(Date* d1, Date* d2);
};

ostream& operator<< (ostream& out,const Date& date)
{
	out << "Date:" << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
	return out;
}

void compareDate(Date* d1, Date* d2)
{
	if (d1->getYear() > d2->getYear())
	{
		cout << *d1 << " is bigger!" << endl;
	}
	else if (d2->getYear() > d1->getYear())
	{
		cout << *d2 << " is bigger!" << endl;
	}
	else if (d1->getYear() == d2->getYear())
	{
		if (d1->getMonth() > d2->getMonth())
		{
			cout << *d1 << " is bigger!" << endl;
		}
		else if (d2->getMonth() > d1->getMonth())
		{
			cout << *d2 << " is bigger!" << endl;
		}
		else if (d1->getMonth() == d2->getMonth())
		{
			if (d1->getDay() > d2->getDay())
			{
				cout << *d1 << " is bigger!" << endl;
			}
			else if (d2->getDay() > d1->getDay())
			{
				cout << *d2 << " is bigger!" << endl;
			}
			else if (d1->getDay() == d2->getDay())
			{
				cout << "Dates are equal" << endl;
			}
		}
	}
}

void exchange(Date* d1, Date* d2)
{
	Date* tmp;
	Date temp;
	tmp = &temp;
	tmp->setDay(d1->getDay());
	tmp->setMonth(d1->getMonth());
	tmp->setYear(d1->getYear());

	d1->setDay(d2->getDay());
	d1->setMonth(d2->getMonth());
	d1->setYear(d2->getYear());

	d2->setDay(tmp->getDay());
	d2->setMonth(tmp->getMonth());
	d2->setYear(tmp->getYear());

}

int main()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "The first task" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	Date date2;
	Date* today =  &date2;
	today->setDay(28);
	today->setMonth(02);
	today->setYear(2022);
	cout << *today << endl;
	Date* date;
	date = today;
	cout << *date << endl;
	if (date != nullptr || today != nullptr)
	{
		cout << "Your pointers are not nulls!" << endl;
	}
	else
	{
		cout << "nullptr";
	}
	cout << "-----------------------------------------------------------------" << endl;
	cout << "The second task" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	today->setDay(1);
	today->setMonth(1);
	today->setYear(1);
	cout << *today << endl;
	Date* date1;
	Date null;
	date1 = &null;
	date1->setDay(1);
	date1->setMonth(2);
	date1->setYear(3);
	cout << *date1 << endl;
	compareDate(today, date1);
	exchange(today, date1);
	cout << *today << endl<< *date1 << endl; 

	return 0;
}



