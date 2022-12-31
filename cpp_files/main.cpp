#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


bool set(bool ok)
{
    return ok=true;
}

bool reset(bool ok)
{
    return ok=false;
}

int main()
{
    ofstream f("fisier.txt");
    int opt;
    bool ok;
    int capacity=0;
    string nume;
    string parola;
    string vec[10];
    int i=0;

    cout<<"\nLogin page\n";
    cout<<"\nCe doriti sa faceti ?(2-login 1-singup  0-iesire)\n";cin>>opt;
    while(opt)
    {
        reset(ok);
        if(opt==1)
        {
            cout<<"introduceti un nume de utilizator: ";cin>>nume;
            vec[++i]=nume;
            cout<<"introduceti o parola:";cin>>parola;
            vec[++i]=parola;
            capacity=i;
            cout<<"\nva salvam datele in baza de date\n";
            for(i=1;i<=capacity;i++)
            {
                f<<vec[i]<<"\n";
            }
        }

        else if(opt==2)
        {
            cout<<"introduceti un nume de utilizator: ";cin>>nume;
            cout<<"introduceti parola: ";cin>>parola;
            cout<<"se proceseaza datele....\n";
            if(capacity==0)cout<<"\nnu avem informatii desre nimeni in baza de date\n";

            for(i=1;i<=capacity;i=i+2)
            {
                if(vec[i]==nume)
                {
                    if(vec[i+1]==parola)
                    {
                        cout<<"datele sunt corecte, va puteri conecta la main application\n";
                        set(ok);
                    }
                    else
                    {
                        reset(ok);
                        string cast;
                        cout<<"parola nu este in regula, doriti sa o resetati?(y/n)";cin>>cast;
                        if(cast=="n")
                        {
                            continue;
                        }
                        else
                        {
                            cout<<"introduceti noua parola:";cin>>parola;
                            vec[i+1]=parola;
                            f<<parola;
                        }

                    }
                }
                else
                {
                    reset(ok);
                    cout<<"\nnu sunteti inregistrat, selactati optiunera de singup\n";
                }


                if(set(ok))
                {
                    cout<<"\nrun main application .....\n";
                }

            }
            
        }

        else
        {
            exit(0);
        }
        cout<<"\nCe doriti sa faceti ?(2-login 1-singup  0-iesire)\n";cin>>opt;

    
    }
}
