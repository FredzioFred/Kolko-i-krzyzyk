/*
Gracz 1 - 'O'
Gracz 2 - 'X'

Zaczynamy gre. Zaczyna gracz 1 - 'O'

Początek:

Aktualny gracz - 'O'

   1  2  3
1 [ ][ ][ ]
2 [ ][ ][ ]
3 [ ][ ][ ]

Po pierwszym ruchu:

Aktualny gracz - 'X'

   1  2  3
1 [3][6][9]
2 [ ][ ][O]
3 [ ][ ][ ]

Po drugim ruchu:

Aktualny gracz - 'O'

   1  2  3
1 [ ][ ][X]
2 [ ][O][ ]
3 [ ][ ][ ]

Po którymś ruchu:

Aktualny gracz - 'O'

   1  2  3
1 [X][X][X]
2 [ ][O][O]
3 [ ][O][ ]

Wygrywa gracz 2 - 'X'.
Czy chcesz rozpocząć jeszcze raz?

Wczytujemy od gracza miejsce w którym chce postawić swój znak
Podaj kolumnę: 2
Podaj rząd: 3
Sprawdzamy czy w tym miejscu można postawić jakikolwiek znak
 Jeżeli możemy to - plansza[2][10] = graczZnak;
 Jeżeli nie to prosimy gracza o podanie nowej pozycji aż do skutku.
Po każdym ruchu ma się odbyć sprawdzenie, czy ktoś wygrał.
Jeżeli ktoś wygrał wypisujemy zwycięzcę i pytamy czy gracze chcą grać ponownie.

Uwagi:
głowne funkcjonalności gry powinny być osobnymi funkcjami
funkcje powinny nazywać się intuicyjnie
główna pętla gry powinna znajdować się w funkcji main()

*/

#include <iostream>

void wypiszPlansze(char plansza[4][11], int& aktualnyGracz)
{

    std::cout << "Aktualny gracz : ";
    if(aktualnyGracz % 2 == 0)
    {
        std::cout << "X\n";
    } else {
        std::cout << "O\n";
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            std::cout << plansza[i][j];
        }
        std::cout << std::endl;
    }
}

void menuGlowne()
{
    std::cout<<"Witaj w grze!\n";
    std::cout<<"Gracz 1 - 'O'\n";
    std::cout<<"Gracz 2 - 'X'\n";
    std::cout<<"Zaczynamy gre. Zaczyna gracz 1 - 'O'\n";
}

void pobieranieMiejsca(int& kolumna, int& rzad)
{
    std::cout << "Podaj kolumne(1, 2, 3) : ";
    while(true)
    {
        std::cin >> kolumna;
        if(kolumna <= 3)
        {
            break;
        } else {
            std::cout << "Podaj kolumne od 1 do 3 ";
        }
    }
    std::cout << "Podaj rzad(1, 2, 3) : ";
    while(true)
    {
        std::cin >> rzad;
        if(rzad <= 3)
        {
            break;
        } else {
            std::cout << "Podaj rzad od 1 do 3 ";
        }
    }
    kolumna = kolumna*3;
}


void aktalizujPlansze(char plansza[4][11], int& aktualnyGracz)
{
    aktualnyGracz++;
    int kolumna = 0;
    int rzad = 0;
    pobieranieMiejsca(kolumna, rzad);
    while(true)
    {
        if(plansza[rzad][kolumna] != ' ')
        {
            std::cout << "Miejsce jest juz zajete!\n";
            pobieranieMiejsca(kolumna, rzad);
        } else {break;}
    }
    if(aktualnyGracz % 2 == 0)
    {
        plansza[rzad][kolumna] = 'O';
    } else {
        plansza[rzad][kolumna] = 'X';
    }
}

void ruch(char plansza[4][11], int& aktualnyGracz)
{
    aktalizujPlansze(plansza, aktualnyGracz);
    wypiszPlansze(plansza, aktualnyGracz);
}

bool remis(char plansza[4][11])
{
    int licznik = 0;
    for(int i = 1; i<4; i++)
    {
        for(int j = 3; j<11; j++)
        {
            if(plansza[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void zakonczenieGry(char znak)
{
    if(znak == 'X' || znak == 'O')
    {
        std::cout << "Gre wygral gracz " << znak;
    }
    if(znak == 'Q')
    {
        std::cout << "Remis";
    }
    exit(0);
}

bool sprawdzWynik(char plansza[4][11])
{
    //Poziomo O
    if(plansza[1][3] == 'O' && plansza[1][6] == 'O' && plansza[1][9] == 'O')
    {
        zakonczenieGry('O');
    }
    if(plansza[2][3] == 'O' && plansza[2][6] == 'O' && plansza[2][9] == 'O')
    {
        zakonczenieGry('O');
    }
    if(plansza[3][3] == 'O' && plansza[3][6] == 'O' && plansza[3][9] == 'O')
    {
        zakonczenieGry('O');
    }

    //Poziomo X

    if(plansza[1][3] == 'X' && plansza[1][6] == 'X' && plansza[1][9] == 'X')
    {
        zakonczenieGry('X');
    }
    if(plansza[2][3] == 'X' && plansza[2][6] == 'X' && plansza[2][9] == 'X')
    {
        zakonczenieGry('X');
    }
    if(plansza[3][3] == 'X' && plansza[3][6] == 'X' && plansza[3][9] == 'X')
    {
        zakonczenieGry('X');
    }

    //Pionowo O

    if(plansza[1][3] == 'O' && plansza[2][3] == 'O' && plansza[3][3] == 'O')
    {
        zakonczenieGry('O');
    }
    if(plansza[1][6] == 'O' && plansza[2][6] == 'O' && plansza[3][6] == 'O')
    {
        zakonczenieGry('O');
    }
    if(plansza[1][9] == 'O' && plansza[2][9] == 'O' && plansza[3][9] == 'O')
    {
        zakonczenieGry('O');    }

    //Pionowo X

    if(plansza[1][3] == 'X' && plansza[2][3] == 'X' && plansza[3][3] == 'X')
    {
        zakonczenieGry('X');
    }
    if(plansza[1][6] == 'X' && plansza[2][6] == 'X' && plansza[3][6] == 'X')
    {
        zakonczenieGry('X');
    }
    if(plansza[1][9] == 'X' && plansza[2][9] == 'X' && plansza[3][9] == 'X')
    {
        zakonczenieGry('X');
    }

    //Przekatna O

    if(plansza[1][3] == 'O' && plansza[2][6] == 'O' && plansza[3][9] == 'O'){
        zakonczenieGry('O'); 
    }
    if(plansza[1][9] == 'O' && plansza[2][6] == 'O' && plansza[3][3] == 'O'){
        zakonczenieGry('O');
    }

    //Przekatna X

    if(plansza[1][3] == 'X' && plansza[2][6] == 'X' && plansza[3][9] == 'X'){
        zakonczenieGry('X');
    }
    if(plansza[1][9] == 'X' && plansza[2][6] == 'X' && plansza[3][3] == 'X'){
        zakonczenieGry('X');
    }

    if(remis(plansza) == true)
    {
        zakonczenieGry('Q');
    }

    return false;
}







int main()
{
    char plansza[4][11] = 
    {
        {' ', ' ', ' ', '1', ' ', ' ', '2', ' ', ' ', '3', ' ',},
        {'1', ' ', '[', ' ', ']', '[', ' ', ']', '[', ' ', ']',},
        {'2', ' ', '[', ' ', ']', '[', ' ', ']', '[', ' ', ']',},
        {'3', ' ', '[', ' ', ']', '[', ' ', ']', '[', ' ', ']',},
    };
    int aktualnyGracz = 0;
    menuGlowne();
    wypiszPlansze(plansza, aktualnyGracz);
    while(true)
    {
        sprawdzWynik(plansza);
        ruch(plansza, aktualnyGracz);
    }
    getchar();
    return 0;
}


