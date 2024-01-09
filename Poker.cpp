#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int buff, data[51], srand(time(0)), deck[100], total_card = 52, total_num, PC, card_played, computer_card, round = 0;
    string add_min, requires_1="add", requires_2="min", PC_A="Last", PC_B="Front", PC_C="Next", appoint;

    for(int i=1;i<14;i++)
    {
        data[i] = i;
    }

    cout << "Choose the number of your opponent(Maximum) ";
    cin >> PC;
    switch (PC){
        case 1:
            cout << "You'll face an opponent." << "\n";
            break;
        case 2: case 3:
            cout << "You will face " << PC << " opponents" << "\n";
            break;
        default:
            cout << "Please Input A Valid Value!" << "\n";
            abort();
    }

    for(int i = 0; i < 52; i++){
        
    }

    for(int i = 1;i<5;i++)
    {
        buff = rand() % 52 + 1;
        if(deck[buff]!=0)
        {
            cout << deck[buff] << " ";
            deck[52+i]=deck[buff];
            deck[buff] = 0;
            total_card--;
        }
        else
        {
            i--;
        }
    }

    for(int k=1;k<PC;k++)
    {
        for(int i=1;i<5;i++)
        {
            if(deck[ rand() % 52 + 1 ] != 0)
            {
                deck[57+i+5*(k-1)]=deck[rand()%52+1];
                deck[rand()%52+1] = 0;
                total_card--;
            }
            else
            {
                i--;
            }
        }
    }
    while(true)
    {
        if(total_card=0)
        {
            int A=deck[1];
            deck[1]=A;
            deck[4]=4;
            deck[5]=5;
            deck[10]=10;
            deck[11]=J;
            deck[12]=Q;
            deck[13]=K;
            for(int i=2;i<3;i++)
            {
                deck[i] = i;
            }
            for(int i=6;i<9;i++)
            {
                deck[i] = i;
            }
            for(int i=1;i<=13;i++)
            {
                deck[i]=deck[i+13];
                deck[i]=deck[i+26];
                deck[i]=deck[i+39];
                deck[1]=A;
            }
        }
        cout << "Your card is now" << "\n";
        for(int i=1;i<5;i++)
        {
            cout << deck[52+i] << " ";
        }
        cout << "Please choose a card to play." << "\n";
        cin >> card_played;
        for(int i=1;i<5;i++)
        {
            if(deck[52+i]==A)
            {
                if(card_played == A)
                {
                    round++;
                    total_num=0;
                    cout << "The total nuber for now is 0" << "\n";
                    while(true)
                    {
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[52+i]=deck[rand()%52+1];
                                deck[rand()%52+1]=0;
                                total_card--;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << deck[52+i] << " ";
                                    break;
                                }
                            }
                            else
                            {
                                j--;
                            }
                        }
                    }
                }
            }
            else if( card_played==deck[52+i] )
            {
                if(deck[52+i]==4)
                {
                    cout << "You reverse the order!" << "\n";
                    round++;
                    while(true)
                    {
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[52+i]=deck[rand()%52+1];
                                deck[rand()%52+1]=0;
                                total_card--;
                                break;
                                cout << "The total number for now is " << total_num << "\n";
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << deck[52+i] << " ";
                                }
                            }
                            else
                            {
                                i--;
                            }
                        }
                    }
                }
                else if(deck[52+i]==5)
                {
                    if(PC==1)
                    {
                        round++;
                        break;
                    }
                    else if(PC==2)
                    {
                        cout << "Appoint a person to play a card, last or next." << "\n";
                        round++;
                        cin  >> appoint;
                        if(appoint== PC_A )
                        {

                        }
                    }

                }
                else if(deck[52+i]==10)
                {
                    cout << "Add 10 or Minus 10" << "\n";
                    cin >> add_min;
                    transform(add_min.begin(), add_min.end(), add_min.begin(), ::tolower);
                    if(add_min == requires_1)
                    {
                        total_num=total_num+10;
                        cout << "The total number for now is" << total_num << "\n";
                        while(true)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(deck[ rand() % 52 + 1 ] != 0)
                                {
                                    deck[52+i]=0;
                                    deck[52+i]=deck[rand()%52+1];
                                    deck[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << deck[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i--;
                                }
                            }
                        }
                        total_card--;
                        break;
                    }
                    else if(add_min == requires_2)
                    {
                        total_num=total_num-10;
                        cout << "The total number for now is" << total_num << "\n";
                        while(true)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(deck[ rand() % 52 + 1 ] != 0)
                                {
                                    deck[52+i]=0;
                                    deck[52+i]=deck[rand()%52+1];
                                    deck[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << deck[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i--;
                                }
                            }
                        }
                        total_card--;
                        break;
                    }
                    total_card--;
                }
                else if(deck[52+i]==J)
                {
                    cout << "You passed" << "\n";
                    while(true)
                    {
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[52+i]=0;
                                deck[52+i]=deck[rand()%52+1];
                                deck[rand()%52+1]=0;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << deck[52+i] << " ";
                                }
                            }
                            else
                            {
                                i--;
                            }
                        }
                    }
                    total_card--;
                    break;

                }
                else if(deck[52+i]==Q)
                {
                    cout << "Add 20 or Minus 20" << "\n";
                    cin >> add_min;
                    transform(add_min.begin(),add_min.end(),add_min.begin(), ::tolower);
                    if(add_min == requires_1)
                    {
                        total_num=total_num+20;
                        cout << "The total number for now is" << total_num << "\n";
                        while(true)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(deck[ rand() % 52 + 1 ] != 0)
                                {
                                    deck[52+i]=0;
                                    deck[52+i]=deck[rand()%52+1];
                                    deck[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << deck[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i--;
                                }
                            }
                        }
                        total_card--;
                        break;
                    }
                    else if(add_min == requires_2)
                    {
                        total_num=total_num-20;
                        cout << "The total number for now is" << total_num << "\n";
                        while(true)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(deck[ rand() % 52 + 1 ] != 0)
                                {
                                    deck[52+i]=0;
                                    deck[52+i]=deck[rand()%52+1];
                                    deck[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << deck[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i--;
                                }
                            }
                        }
                        total_card--;
                        break;
                    }
                }
                else if(deck[52+i]==K)
                {
                    total_num=99;
                    cout << "The total nuber for now is 99" << "\n";
                    while(true)
                    {
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[52+i]=0;
                                deck[52+i]=deck[rand()%52+1];
                                deck[rand()%52+1]=0;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << deck[52+i] << " ";
                                }
                            }
                            else
                            {
                                i--;
                            }
                        }
                    }
                    total_card--;
                    break;
                }
                else if(total_num>99)
                {
                    break;
                }
                else
                {
                    total_num=total_num+deck[52+i];
                    while(true)
                    {
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[52+i]=0;
                                deck[52+i]=deck[rand()%52+1];
                                deck[rand()%52+1]=0;
                                total_card--;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << deck[52+i] << " ";
                                }
                            }
                            else
                            {
                                i--;
                            }
                        }
                    }
                    cout << "The total number for now is" << total_num << "\n";
                    break;
                }
            }
            else
            {
                cout << "Wrong card!!" << "\n";
                cin >> card_played;
            }
        }
        for(int k=1;k<PC;k++)
        {
            for(int i=58+5*(k-1);i<62+5*(k-1);i++)
            {
                if(deck[i]==2 || deck[i] ==3 || deck[i] ==6 || deck[i] ==7 || deck[i] ==8 || deck[i] ==9 && deck[i]+total_num<=99)
                {
                    cout << "The total number for now is "<< total_num+deck[i] << "\n";
                    for(int j=1;j<2;j++)
                    {
                        if(deck[ rand() % 52 + 1 ] != 0)
                        {
                            deck[i]=deck[rand()%52+1];
                            total_card--;
                        }
                        else
                        {
                            j--;
                        }
                    }
                    break;
                }
                else if(deck[i]==4)
                {
                    for(int j=1;j<2;j++)
                    {
                        if(deck[ rand() % 52 + 1 ] != 0)
                        {
                            deck[i]=deck[rand()%52+1];
                            total_card--;
                        }
                        else
                        {
                            j--;
                        }
                    }
                    break;
                }
                else if(deck[i]==5)
                {
                    for(int j=1;j<2;j++)
                    {
                        if(deck[ rand() % 52 + 1 ] != 0)
                        {
                            deck[i]=deck[rand()%52+1];
                            total_card--;
                        }
                        else
                        {
                            j--;
                        }
                    }
                    break;
                }
                else if(deck[i]==10)
                {
                    if(rand()%2 == 1 && total_num+10<=99)
                    {
                        total_num=total_num+10;
                        cout << "The total number for now is" << total_num << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[i]=deck[rand()%52+1];
                                total_card--;
                            }
                            else
                            {
                                j--;
                            }
                        }
                        break;
                    }
                    else
                    {
                        total_num=total_num-10;
                        cout << "The total number for now is" << total_num << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(deck[ rand() % 52 + 1 ] != 0)
                            {
                                deck[i]=deck[rand()%52+1];
                                total_card--;
                            }
                            else
                            {
                                j--;
                            }
                        }
                        break;
                    }
                }
                else if(deck[i]==Q)
                {
                    if(rand()%2 == 1 && total_num+20<=99)
                    {
                        total_num=total_num+20;
                        cout << "The total number for now is" << total_num << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(deck[rand()%57+1!=0])
                            {
                                deck[i]=0;
                                deck[i]=deck[rand()%52+1];
                                total_card--;
                            }
                            else
                            {
                                j--;
                            }
                        }
                        break;
                    }
                    else
                    {
                        total_num=total_num-20;
                        cout << "The total number for now is" << total_num << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(deck[rand()%57+1!=0])
                            {
                                deck[i]=deck[rand()%52+1];
                                total_card--;
                            }
                            else
                            {
                                j--;
                            }
                        }
                        break;
                    }
                }
            }
        }
        if(total_num>99)
        {
            break;
        }
        cout << "The winner of this game is" <<"\n";
        return 0;
    }
}
