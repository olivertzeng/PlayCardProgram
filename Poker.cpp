#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void cards(){
    for(int i=1;i<14;i++){
        data[i] = i;
    }
    return;
}

int main() {
    int data[100],card_played,PC,total_card = 52,srand(time(0)),total_num;
    string PC_C="Next",PC_B="Front",PC_A="Last",requires_2="min",add_min,requires_1="add";
    for(int i=1;i<=13;i++)
    {
        data[i] = data[i+13];
        data[i] = data[i+26];
        data[i] = data[i+39];
    }
    cout << "Choose the number of your opponent, 1 to 3: " << "\n";
    cin >> PC;
    switch (PC) {
        case 1:
            cout << "You will face an opponent."<< "\n";
            break;
        case 2: case 3:
            cout << "You will face " << PC << " opponents" << "\n";
        default:
            cout << "Please insert a valid value!";
            abort();
            break;
    }
    for(int i=1;i<5;i++){
        if(data[rand()%52+1!=0]){
            cout << data[rand()%52+1] << " ";
            data[52+i]=data[rand()%52+1];
            data[rand()%52+1] = 0;
            total_card -= 1;
        }else{
            i -= 1;
        }
    }
    for(int k=1;k<PC;k++){
        for(int i=1;i<5;i++){
            if(data[rand()%52+1!=0]){
                data[57+i+5*(k-1)] = data[rand()%52+1];
                data[rand()%52+1] = 0;
                total_card -= 1;
            }else{
                i -= 1;
            }
        }
    }
    {
        if(true)
        {
            if(total_card=0)
            {
                int A=data[1];
                data[1]=A;
                data[4]=4;
                data[5]=5;
                data[10]=10;
                data[11]=J;
                data[12]=Q;
                data[13]=K;
                for(int i=2;i<3;i++)
                {
                    data[i] = i;
                }
                for(int i=6;i<9;i++)
                {
                    data[i] = i;
                }
                for(int i=1;i<=13;i++)
                {
                    data[i]=data[i+13];
                    data[i]=data[i+26];
                    data[i]=data[i+39];
                    data[1]=A;
                }
            }
            cout << "Your card is now" << "\n";
            for(int i=1;i<5;i++)
            {
                cout << data[52+i] << " ";
            }
            cout << "Please choose a card to play." << "\n";
            cin >> card_played;
            for(int i=1;i<5;i++)
            {
                if(data[52+i]==A)
                {
                    if(card_played == A)
                    {
                        round++;
                        total_num=0;
                        cout << "The total nuber for now is 0" << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(data[rand()%52+1!=0])
                            {
                                data[52+i]=data[rand()%52+1];
                                data[rand()%52+1]=0;
                                total_card=total_card-1;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << data[52+i] << " ";
                                    break;
                                }
                            }
                            else
                            {
                                j=j-1;
                            }
                        }
                    }
                }
                else if( card_played==data[52+i] )
                {
                    if(data[52+i]==4)
                    {
                        cout << "You reverse the order!" << "\n";
                        round++;
                        for(int j=1;j<2;j++)
                        {
                            if(data[rand()%52+1!=0])
                            {
                                data[52+i]=data[rand()%52+1];
                                data[rand()%52+1]=0;
                                total_card=total_card-1;
                                break;
                                cout << "The total number for now is " << total_num << "\n";
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << data[52+i] << " ";
                                }
                            }
                            else
                            {
                                i=i-1;
                            }
                        }
                    }
                    else if(data[52+i]==5)
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
                    else if(data[52+i]==10)
                    {
                        cout << "Add 10 or Minus 10" << "\n";
                        cin >> add_min;
                        transform(add_min.begin(), add_min.end(), add_min.begin(), ::tolower);
                        if(add_min == requires_1)
                        {
                            total_num=total_num+10;
                            cout << "The total number for now is" << total_num << "\n";
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[52+i]=0;
                                    data[52+i]=data[rand()%52+1];
                                    data[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << data[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i=i-1;
                                }
                            }
                            total_card=total_card-1;
                            break;
                        }
                        else if(add_min == requires_2)
                        {
                            total_num=total_num-10;
                            cout << "The total number for now is" << total_num << "\n";
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[52+i]=0;
                                    data[52+i]=data[rand()%52+1];
                                    data[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << data[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i=i-1;
                                }
                            }
                            total_card=total_card-1;
                            break;
                        }
                        total_card=total_card-1;
                    }
                    else if(data[52+i]==J)
                    {
                        cout << "You passed" << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(data[rand()%52+1!=0])
                            {
                                data[52+i]=0;
                                data[52+i]=data[rand()%52+1];
                                data[rand()%52+1]=0;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << data[52+i] << " ";
                                }
                            }
                            else
                            {
                                i=i-1;
                            }
                        }
                        total_card=total_card-1;
                        break;

                    }
                    else if(data[52+i]==Q)
                    {
                        cout << "Add 20 or Minus 20" << "\n";
                        cin >> add_min;
                        transform(add_min.begin(),add_min.end(),add_min.begin(), ::tolower);
                        if(add_min == requires_1)
                        {
                            total_num=total_num+20;
                            cout << "The total number for now is" << total_num << "\n";
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[52+i]=0;
                                    data[52+i]=data[rand()%52+1];
                                    data[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << data[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i=i-1;
                                }
                            }
                            total_card=total_card-1;
                            break;
                        }
                        else if(add_min == requires_2)
                        {
                            total_num=total_num-20;
                            cout << "The total number for now is" << total_num << "\n";
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[52+i]=0;
                                    data[52+i]=data[rand()%52+1];
                                    data[rand()%52+1]=0;
                                    cout << "Your card is now" << "\n";
                                    for(int i=1;i<5;i++)
                                    {
                                        cout << data[52+i] << " ";
                                    }
                                }
                                else
                                {
                                    i=i-1;
                                }
                            }
                            total_card=total_card-1;
                            break;
                        }
                    }
                    else if(data[52+i]==K)
                    {
                        total_num=99;
                        cout << "The total nuber for now is 99" << "\n";
                        for(int j=1;j<2;j++)
                        {
                            if(data[rand()%52+1!=0])
                            {
                                data[52+i]=0;
                                data[52+i]=data[rand()%52+1];
                                data[rand()%52+1]=0;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << data[52+i] << " ";
                                }
                            }
                            else
                            {
                                i=i-1;
                            }
                        }
                        total_card=total_card-1;
                        break;
                    }
                    else if(total_num>99)
                    {
                        break;
                    }
                    else
                    {
                        total_num=total_num+data[52+i];
                        for(int j=1;j<2;j++)
                        {
                            if(data[rand()%52+1!=0])
                            {
                                data[52+i]=0;
                                data[52+i]=data[rand()%52+1];
                                data[rand()%52+1]=0;
                                total_card=total_card-1;
                                cout << "Your card is now" << "\n";
                                for(int i=1;i<5;i++)
                                {
                                    cout << data[52+i] << " ";
                                }
                            }
                            else
                            {
                                i=i-1;
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
                if(true)
                {
                    for(int i=58+5*(k-1);i<62+5*(k-1);i++)
                    {
                        if(data[i]==2 || data[i] ==3 || data[i] ==6 || data[i] ==7 || data[i] ==8 || data[i] ==9 && data[i]+total_num<=99)
                        {
                            cout << "The total number for now is "<< total_num+data[i] << "\n";
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[i]=data[rand()%52+1];
                                    total_card=total_card-1;
                                }
                                else
                                {
                                    j=j-1;
                                }
                            }
                            break;
                        }
                        else if(data[i]==4)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[i]=data[rand()%52+1];
                                    total_card=total_card-1;
                                }
                                else
                                {
                                    j=j-1;
                                }
                            }
                            break;
                        }
                        else if(data[i]==5)
                        {
                            for(int j=1;j<2;j++)
                            {
                                if(data[rand()%52+1!=0])
                                {
                                    data[i]=data[rand()%52+1];
                                    total_card=total_card-1;
                                }
                                else
                                {
                                    j=j-1;
                                }
                            }
                            break;
                        }
                        else if(data[i]==10)
                        {
                            if(rand()%2 == 1 && total_num+10<=99)
                            {
                                total_num=total_num+10;
                                cout << "The total number for now is" << total_num << "\n";
                                for(int j=1;j<2;j++)
                                {
                                    if(data[rand()%52+1!=0])
                                    {
                                        data[i]=data[rand()%52+1];
                                        total_card=total_card-1;
                                    }
                                    else
                                    {
                                        j=j-1;
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
                                    if(data[rand()%52+1!=0])
                                    {
                                        data[i]=data[rand()%52+1];
                                        total_card=total_card-1;
                                    }
                                    else
                                    {
                                        j=j-1;
                                    }
                                }
                                break;
                            }
                        }
                        else if(data[i]==Q)
                        {
                            if(rand()%2 == 1 && total_num+20<=99)
                            {
                                total_num=total_num+20;
                                cout << "The total number for now is" << total_num << "\n";
                                for(int j=1;j<2;j++)
                                {
                                    if(data[rand()%57+1!=0])
                                    {
                                        data[i]=0;
                                        data[i]=data[rand()%52+1];
                                        total_card=total_card-1;
                                    }
                                    else
                                    {
                                        j=j-1;
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
                                    if(data[rand()%57+1!=0])
                                    {
                                        data[i]=data[rand()%52+1];
                                        total_card=total_card-1;
                                    }
                                    else
                                    {
                                        j=j-1;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
            if(total_num>99)
            {
                break;
            }
        }
        cout << "The winner of this game is" <<"\n";
        return 0;
    }
