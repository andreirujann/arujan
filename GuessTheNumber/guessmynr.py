import argparse
import random
import datetime

mini=0
maxi=0
players=0

def define_min_max():
    parser = argparse.ArgumentParser()
    parser.add_argument("minim", help="display a minim number",type=int)
    parser.add_argument("maxim", help="display a maxim number",type=int)
    parser.add_argument("count_players", help="display number of players",type=int)
    args = parser.parse_args()
    if args.minim>args.maxim:
        raise ValueError("Eroare, nu se poate ca minimul sa fie mai mare decat maximul")
    else:
        return(args.minim,args.maxim, args.count_players)
    


def define_hints(guess, generate_nr):
    hint=random.randint(1,2)
    if hint==1:
        if int(guess)<generate_nr:
            print("Numarul cautat este mai mare")
        else:
            print("Numarul este mai mic")
    else:
        if generate_nr%2==0:
            print("Numarul este par")
        elif not generate_nr%2==0:
            print("Numarul este impar")
        elif generate_nr%3==0:
            print("Numarul este divizibil cu 3")
        elif generate_nr%5==0:
            print("numarul este divizibil cu 5")
        else:
            print("Numar par sau impar nedivizibil cu 3 sau 5")



def game_loop(mini, maxi):
    generate_nr=random.randint(mini,maxi)
    greseli=0
    scor=maxi/2
    scor=int(scor)
    while scor>0:
        print("_______________________")
        print("Introduceti un  numar ")
        guess=input()
        if int(guess)==generate_nr:
            print("Felicitari, jocul s-a incheiat pentru tine")
            break
        else:
            define_hints(guess, generate_nr) 
            greseli=greseli+1
            scor=scor-greseli*2
            print(f"Scorul este {scor}")
            print(f"Numarul greselilor tale este: {greseli}")
            continue

    if scor<=0:
        print("Jocul s-a terminat, ai pierdut")
        print("Numarul pe care trebuia sa il gasesti era:")
        print(generate_nr)
    else:
        print(f"scorul tau este: {scor}")
    

    

def multiplayer_loop(mini, maxi, players):
    count=0
    mini, maxi, players=define_min_max()
    for contor in range(players):
        print("La rand este jucatorul:")
        print(contor+1)
        print("------------")
        game_loop(mini, maxi)
        count+=count
        if count<contor:
            print("\n")
            print("\n")
        


        
if __name__=="__main__":
    multiplayer_loop(mini, maxi, players)

