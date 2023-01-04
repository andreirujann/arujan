#include<iostream>
#include<string.h>

using namespace std;

string tabla[3][3]={ {"1","2","3"}, {"4","5","6"}, {"7","8","9"}};
int chose;
int linie,coloana;
string turn= "x";// else "0"
int scor1;
int scor2;

void Board()
{
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            tabla[i][j]=(i+1)*(j+1);
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<tabla[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Header()
{
    cout<<"\nTIC TAC TOE GAME\n";
    cout<<"\nplayer 1: x     player 2: 0\n";
    cout<<endl;
    cout<<endl;
}

void Scor()
{
    cout<<"\nScorul celor 2 jucatori este:\n";
    cout<<"\nplayer1-----"<<scor1<<"    player2-----"<<scor2<<endl;
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

bool IsEmpty()
{
    int i,j;
    int contor=0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
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
    int i,j,ok;
    bool finish=false;

    //verificare linii
    for(i=0;i<3;i++)
    {
        ok=0;
        for(j=0;j<3;j++)
        {
            if(tabla[i][j]=="x")
            {
                ok++;
            }
        }
        if(ok==3)
        {
            cout<<"\ncastiga player 1\n";
            scor1+=1;
            finish=true;
        }
    }
    for(i=0;i<3;i++)
    {
        ok=0;
        for(j=0;j<3;j++)
        {
            if(tabla[i][j]=="0")
            {
                ok++;
            }
        }
        if(ok==3)
        {
            cout<<"\ncastiga player 2\n";
            scor2+=1;
            finish=true;
        }
    }


    // verificare coloane
    for(i=0;i<3;i++)
    {
        ok=0;
        for(j=0;j<3;j++)
        {
            if(tabla[j][i]=="x")
            {
                ok++;
            }
        }
        if(ok==3)
        {
            cout<<"\ncastiga player 1\n";
            scor1+=1;
            finish=true;
        }
    }
    for(i=0;i<3;i++)
    {
        ok=0;
        for(j=0;j<3;j++)
        {
            if(tabla[j][i]=="0")
            {
                ok++;
            }
        }
        if(ok==3)
        {
            cout<<"\ncastiga player 2\n";
            scor2+=1;
            finish=true;
        }
    }


    //verificare diagonale

    if( (tabla[0][0]==tabla[1][1] && tabla[0][0]==tabla[2][2]) || (tabla[0][2]==tabla[1][1] && tabla[0][2]==tabla[2][0]) )
    {
        if(tabla[0][0]=="x" || tabla[2][0]=="x")
        {
            cout<<"\ncatiga player 1\n";
            scor1+=1;
            finish=true;
        }
    }
    if( (tabla[0][0]==tabla[1][1] && tabla[0][0]==tabla[2][2]) || (tabla[0][2]==tabla[1][1] && tabla[0][2]==tabla[2][0]) )
    {
        if(tabla[0][0]=="0" || tabla[2][0]=="0")
        {
            cout<<"\ncatiga player 2\n";
            scor2+=1;
            finish=true;
        }
    }

    if(finish)
    {
        cout<<"\nAvem un castigator!!!\n";
        Scor();
        if(scor1==2 || scor2==2)
        {
            cout<<endl;
            if(scor1>scor2)
            {
                cout<<"\nCel mai mare scor il are player 1!!!\n";
            }
            else
            {
                cout<<"\nCel mai mare scor il are player 2!!!\n";
            }
            cout<<endl;
            cout<<"\nJOCUL S-A INCHEIAT!!\n";
            cout<<endl;
            exit(1);
        }
        else
        {
            Board();
        }
        
    }
    else
    {
        if(IsEmpty())
        {
            cout<<"\nREMIZA!!\n";
            Scor();
            if(scor1==2 || scor2==2)
            {
                cout<<endl;
                if(scor1>scor2)
                {
                    cout<<"\nCel mai mare scor il are player 1!!!\n";
                }
                else
                {
                    cout<<"\nCel mai mare scor il are player 2!!!\n";
                }
                cout<<endl;
                cout<<"\nJOCUL S-A INCHEIAT!!\n";
                cout<<endl;
                exit(1);
            }
            else
            {
                Board();
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
        Check();
        if(!IsEmpty())
        {
            Init();
            Game();
        }
    }

    else if(turn=="0" && (tabla[linie][coloana]!= "x" && tabla[linie][coloana]!="0"))
    {
        tabla[linie][coloana]="0";
        turn ="x";
        Check();
        if(!IsEmpty())
        {
            Init();
            Game();
        }
    }

    else
    {
        cout<<"\npozitia este ocupata\n";
        if(!IsEmpty())
        {
            Init();
            Check();
            Game();
        }
    }
}



int main()
{
    
    Header();
    Scor();
    Init();
    Game();
    
    cout<<"\n";
    return 0;
}