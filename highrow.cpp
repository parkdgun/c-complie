#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

struct Card
{
    int nNumber;
    const char* pShape;
};

void InitializeCards(Card* pCardDeck);
void ShuffleCards(Card* pCardDeck);
void SwapCard(Card& c0, Card& c1);
void PrintCard(Card card);
void PrintHiddenCard();
void Betting(Card hiddendCard, int* pMoney);

const char SHAPE_SPADE[3] = "♠";
const char SHAPE_DIAMOND[3] = "◆";
const char SHAPE_HEART[3] = "♥";
const char SHAPE_CLUB[3] = "♣";

void main()
{
    Card cardDeck[52] = {};

    InitializeCards(cardDeck);
    ShuffleCards(cardDeck);

    int nMoney = 10000;
    int nIndex = 0;

    while(nMoney > 100 && nIndex < 48)
    {
        system("cls");

        cout << "=======< 하이로우세븐 >=======" << endl;
        cout << " 남은 카드수 : " << 48 - nIndex << endl;
        cout << " 소지금 : " << nMoney << endl;

        Card card1 = cardDeck[nIndex];
        Card card2 = cardDeck[nIndex + 1];
        Card card3 = cardDeck[nIndex + 2];
        Card card4 = cardDeck[nIndex + 3];
        Card hiddenCard = cardDeck[nIndex + 4];

        PrintCard(card1);
        PrintCard(card2);
        PrintCard(card3);
        PrintCard(card4);
        PrintHiddenCard();

        Betting(hiddenCard, &nMoney);
        nIndex += 1;
    }
}

void InitializeCards(Card* pCardDeck)
{
    for(int i = 0; i < 52; i++)
    {
        switch(i / 13)
        {
            case 0: pCardDeck[i].pShape = SHAPE_SPADE; break;
            case 1: pCardDeck[i].pShape = SHAPE_DIAMOND; break;
            case 2: pCardDeck[i].pShape = SHAPE_HEART; break;
            case 3: pCardDeck[i].pShape = SHAPE_CLUB; break;
        }

        pCardDeck[i].nNumber = i % 13 + 1;
    }
}

void ShuffleCards(Card* pCardDeck)
{
    srand(time(NULL));

    for(int i = 0; i < 100; i++)
    {
        int nFirst = rand() % 52;
        int nSecond = rand() % 52;

        SwapCard(pCardDeck[nFirst], pCardDeck[nSecond]);
    }
}

void SwapCard(Card& c0, Card& c1)
{
    Card temp = c0;
    c0 = c1;
    c1 = temp;
}

void PrintCard(Card card)
{
    cout << " [" << card.pShape;
    if(card.nNumber > 1 && card.nNumber < 11)
    {
        cout << card.nNumber;
    }
    else 
    {
        switch (card.nNumber)
        {
            case 1: cout << 'A'; break;
            case 2: cout << 'J'; break;
            case 3: cout << 'Q'; break;
            case 4: cout << 'K'; break;
        }
    }

    cout << "] " << endl;
}

void PrintHiddenCard() { cout << " [ ? ] " << endl; }

void Betting(Card HiddenCard, int* pMoney)
{
    cout << endl;
    cout << "1.High 2.Low 3.Seven" << endl;

    int multiplier = 0;
    switch(getch())
    {
        case '1': multiplier = (hiddenCard.nNumber > 7) ? 1 : -1; break;
        case '2': multiplier = (hiddenCard.nNumber < 7) ? 1 : -1; break;
        case '3': multiplier = (hiddenCard.nNumber == 7) ?13 : -1; break;
    }

    int betting = 0;
    while(betting < 100 || betting > *pMoney)
    {
        cout << "베팅금을 입력하세요(100~" << *pMoney << "): ";
        cin >> betting;
    }

    cout << endl;
    PrintCard(hiddenCard);
    cout << endl;

    int addedMoney = betting * multiplier;
    cout << addedMoney << "만큼의 돈을 " << (addedMoney > 0 ? "땄습니다!" : "잃었습니다!") << endl;
    *pMoney += addedMoney;

    system("pause");
}