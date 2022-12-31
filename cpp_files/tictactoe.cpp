#include<iostream>
#include<string.h>

using namespace std;

string tabla[3][3]={ {"1","2","3"}, {"4","5","6"}, {"7","8","9"}};
int chose;
int linie,coloana;
string turn= "x";// else "0"


void Header()
{
    cout<<"\nTIC TAC TOE GAME\n";
    cout<<"\nplayer 1: x     player 2: 0\n";
    cout<<endl;
    cout<<endl;
}

void Init()
{
    cout<<tabla[0][0]<<" | "<<tabla[0][1]<<" | "<<tabla[0][2];
    cout<<"\n_________\n";
    cout<<"\n";
    cout<<tabla[1][0]<<" | "<<tabla[1][1]<<" | "<<tabla[1][2];
    cout<<"\n_________\n";
    cout<<"\n";
    cout<<tabla[2][0]<<" | "<<tabla[2][1]<<" | "<<tabla[2][2];
}

bool Fill()
{
    int i,j;
    int contor=0;

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(tabla[i][j]=="x" || tabla[i][j]=="0")
            {
                contor++;
            }
        }
    }
    if(contor==9)
    {
        return true;
    }
    return false;
}


void Check()
{
    //bool ok=false;
    int i,j;

    //pe latime
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(tabla[i][0]==tabla[i][1] && tabla[i][0]==tabla[i][2])
            {
                if(tabla[i][0]=="x")
                {
                    cout<<"\nCastigatorul este player 1!!!!\n";
                    exit(0);
                }
                else if(tabla[i][0]=="0")
                {
                    cout<<"\nCastigatorul este player 2!!!!\n";
                    exit(0);
                }
                else
                {
                    continue;
                }
            }

            //pe inaltime
            else if(tabla[0][j]==tabla[1][j] && tabla[0][j]==tabla[2][j])
            {
                if(tabla[0][j]=="x")
                {
                    cout<<"\nCastigatorul este player 1!!!!\n";
                    exit(0);
                }
                else if(tabla[0][j]=="0")
                {
                    cout<<"\nCastigatorul este player 2!!!!\n";
                    exit(0);
                }
                else
                {
                    continue;
                }
            }

            //pe diagonale
            else if((tabla[0][0]==tabla[1][1] && tabla[1][1]==tabla[2][2]) || (tabla[0][2]==tabla[1][1]&& tabla[1][1]==tabla[2][0]))
            {
                if(tabla[0][0]=="x" || tabla[0][2]=="x")
                {
                    cout<<"\nCastigatorul este player 1!!!\n";
                    exit(0);
                }
                else
                {
                    cout<<"\nCastigatorul este player 2!!!\n";
                    exit(0);
                }
            }

            else
            {
                
                if(Fill())
                {
                    cout<<"\nREMIZA!!!\n";
                    exit(0);
                }
            }

        }
    }
}


void Game()
{
    if(turn=="x")
    {
        cout<<"\neste randul lui player 1\n";
    }
    else
    {
        cout<<"\neste randul lui player 2\n";
    }

    cout<<endl;
    cout<<"alege pozitia: ";
    cin>>chose;

    switch(chose)
    {
        case 1: linie=0; coloana=0; break;
        case 2: linie=0; coloana=1; break;
        case 3: linie=0; coloana=2; break;
        case 4: linie=1; coloana=0; break;
        case 5: linie=1; coloana=1; break;
        case 6: linie=1; coloana=2; break;
        case 7: linie=2; coloana=0; break;
        case 8: linie=2; coloana=1; break;
        case 9: linie=2; coloana=2; break;
        default:cout<<"\npozitie invalida\n";
    }

    if(turn=="x" && (tabla[linie][coloana]!= "x" && tabla[linie][coloana]!="0"))
    {
        tabla[linie][coloana]="x";
        turn ="0";
        //Check();
    }

    else if(turn=="0" && (tabla[linie][coloana]!= "x" && tabla[linie][coloana]!="0"))
    {
        tabla[linie][coloana]="0";
        turn ="x";
        //Check();
    }

    else
    {
        cout<<"\npozitia este ocupata\n";
        Game();
    }
    Check();
    Init();
    Game();
}


int main()
{
    Header();
    Init();
    Game();
    cout<<"\n";
    return 0;

}