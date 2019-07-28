import sys

class pizza:
    number = 0
    def __init__(self,name,price):
        self.price = price
        self.name = name
    def order(self,nums):
        self.number+=nums
    def cost(self):
        return self.price*self.number
    def get_num(self):
        if self.number>0:
            return True
        else:
            return False
    def get_name(self):
        return self.name
    def get_price(self):
        return self.price
    
if __name__=='__main__':
    tax = 0.3
    total_cost = 0
    
    pizzas = { }
    pizzas['A'] = pizza('pizza A',34.55)
    pizzas['B'] = pizza('pizza B',18.28)
    pizzas['C'] = pizza('pizza C',55.46)
    
    while True:
        print("\nBasket --------\n")
        if pizzas['A'].get_num()>0:
            print(f"{pizzas['A'].get_name()}  {pizzas['A'].cost()}")
        if pizzas['B'].get_num()>0:
            print(f"{pizzas['B'].get_name()}  {pizzas['B'].cost()}")
        if pizzas['C'].get_num()>0:
            print(f"{pizzas['C'].get_name()}  {pizzas['C'].cost()}")
        print(f"Total Cost {total_cost}\n---------------\n")

        print("Please select a pizza to add to your basket:")
        print(f"1: {pizzas['A'].get_name()} price: {pizzas['A'].get_price()}")
        print(f"2: {pizzas['B'].get_name()} price: {pizzas['B'].get_price()}")
        print(f"3: {pizzas['C'].get_name()} price: {pizzas['C'].get_price()}")

        choice = input("Enter your choice here >> ")
        choice = int(choice)

        if choice is 1:
            total_cost += pizzas['A'].get_price()*(1+tax)
            pizzas['A'].order(1)
        elif choice is 2:
            total_cost += pizzas['B'].get_price()*(1+tax)
            pizzas['B'].order(1)
        elif choice is 3:
            total_cost += pizzas['C'].get_price()*(1+tax)
            pizzas['C'].order(1)
        elif choice is 0:
            print("Terminating ...")
            sys.exit()
        else:
            print("You inserted incorrect number")
    
    