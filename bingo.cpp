#include <iostream.h>
#include <time.h>

using namespace std;

void Initialize();
void Shuffle(int count);
void ShowNumbers();
int GetInput();
void SetMarking(int nInput);
void CountBingo();

const int MARKING = 'x';
int nNumbers[25] = {};
int nBingoCount = 0;

void main()
{
    Initialize();
    Shuffle(100);

    while(true)
    {
        ShowNumbers();
        SetMarking(GetInput());
        CountBingo();

        if(nBingoCount >= 5) break;
    }

    ShowNumbers();
    cout << "!!!!빙고!!!!" << endl;
}

void Initialize()
{
    for(int i = 0; i < 25; i++)
    {
        nNumbers[i] = i + 1;
    }
}

void Shuffle(int count)
{
    srand(time(NULL));

    for(int i = 0; i < count; i++) 
    {
        int nRandom0 = rand() % 25;
        int nRandom1 = rand() % 25;
        int temp = nNumbers[nRandom0];
        nNumbers[nRandom0] = nNumbers[nRandom1];
        nNumbers[nRandom1] = temp;
    }
}

void ShowNumbers()
{
    system("cls");

    for(int i = 0; i < 25; i++)
    {
        if(i % 5 == 0) cout << endl;

        if(nNumbers[i] == MARKING)
        {
            cout << (char)nNumbers[i] << '\t';
        }
        else
        {
            cout << (int)nNumbers[i] << '\t';
        }
    }

    cout << end;;
    cout << "빙고 개수 : " << nBingoCount << endl;
}

int GetInput()
{
    int nInput = 0;
    cout << "숫자를 입력하세요 : ";
    cin >> nInput;
    return nInput;
}

void SetMarking(int nInput)
{
    for(int i = 0; i < 25; i++)
    {
        if(nNumbers[i] == nInput)
        {
            nNumbers[i] = MARKING;
            break;
        }
    }
}

void CountBingo()
{
    nBingoCount = 0;

    for(int i = 0; i < 5; i++)
    {
        if(nNumbers[i * 5] == MARKING && nNumbers[i * 5 + 1] == MARKING && nNumbers[i * 5 + 2] == MARKING && nNumbers[i * 5 + 3] == MARKING && nNumbers[i * 5 + 4] == MARKING)
        {
            nBingoCount++;
        }

        if(nNumbers[i] == MARKING && nNumbers[i + 5 * 1] == MARKING && nNumbers[i + 5 * 2] == MARKING && nNumbers[i + 5 * 3] == MARKING && nNumbers[i + 5 * 4] == MARKING)
        {
            nBingoCount++;
        }
        
        if(nNumbers[0] == MARKING && nNumbers[6] == MARKING && nNumbers[12] == MARKING && nNumbers[18] == MARKING && nNumbers[24] == MARKING)
        {
            nBingoCount++;
        }

        if(nNumbers[4] == MARKING && nNumbers[8] == MARKING && nNumbers[12] == MARKING && nNumbers[16] == MARKING && nNumbers[20] == MARKING)
        {
            nBingoCount++;
        }
    }
}