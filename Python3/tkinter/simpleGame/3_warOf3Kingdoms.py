import tkinter as tk

from functools import partial

class country:
    def __init__(self,name):
        self.name = name
        self.army = 1000
        self.money = 1000
    def trade(self):
        self.money+=100
    def hire(self,noArm):
        self.army+=noArm
        self.money-=noArm
    def attack(self,attackee,noArm):
        self.army-=noArm
        attackee.army-=noArm*0.8

    def armyDetail(self):
        return self.army
    def moneyDetail(self):
        return self.money

#Logics
def clearScene():
    listbox.delete('0','end')

def moneyArmyIsEmpty(country):
     return country.army <= 0 or country.money <= 0

#Interactions and AI
def selections(country):
    value = listbox.get(listbox.curselection())
    if value is 'hire':
        country.hire()
    elif value is 'trade':
        country.trade()
    else:
        listBoxCountryScene()
        nextButton.configure(command=partial(attackScene,country))

def attackScene(country):
    value = listbox.get(listbox.curselection)
    if value is country:
        dsfds

 
#Scene
def listBoxActionScene():
    clearScene(listbox)
    actions=['trade','hire','attack']
    for action in actions:
        listbox.insert('end',item)
    listbox.pack()
def listBoxCountryScene(countries):
    clearScene(listbox)
    for country in countries:
        if moneyArmyIsEmpty(country) is False:
            listbox.insert('end',f'Name: {country.name} Army: {country.army} Money: {country.money}')


# Tk GUI 
window=tk.Tk()
window.geometry('200x200')
window.title('3 Kingdoms')

l = tk.Label(window,text='The war of 3 Kingdoms',bg='yellow',width=4,font=('Arial',12))
l.pack()

listbox = tk.Listbox(window)
listbox.pack()


def main():
    

if __name__ == "__main__":
    main()