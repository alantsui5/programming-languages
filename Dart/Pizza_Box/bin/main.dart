import 'dart:io';

import 'package:Pizza_Box/Pizza_Box.dart' as Pizza_Box;

main(List<String> arguments) {
  double tax = 0.2;
  double cost =0;
  //
  var pizzas = <String,Pizza>{
    "A":Pizza("Pizza A",24.55),
    "B":Pizza("Pizza B",15.55),
    "C":Pizza("Pizza C",78.55)
  };

  print("Enter your choice: ");
  var choice = int.parse(stdin.readLineSync());
  switch(choice){
    case 1:
      cost+= pizzas['A'].get_price();
      pizzas["A"].order();
      break;
    case 2:
      cost += pizzas["B"].get_price();
      pizzas["B"].order();
      break;
    case 3:
      cost += pizzas["C"].get_price();
      pizzas["C"].order();
      break;
    case 0:
      print("Terminating...");
      exit(0);
      break;
    default:
      print("You inserted wrong choice.");
  }
  cost = taxed_cost(cost,tax);
  print(cost);
  print(pizzas['A'].get_cost());
  print(pizzas['B'].get_cost());
  print(pizzas['C'].get_cost());
}

double taxed_cost(double cost, double tax){
  return tax * cost;
}

class Pizza {
  double price;
  String name;
  double cost = 0;
  int number = 0;

  Pizza(String name, double price){
    this.name = name;
    this.price = price;
  }

  void edit_pizza({String name, double price}){
    this.name = name;
    this.price = price;
  }

  void order(){
    this.number += 1;
    this.cost+=price;
  }
  double get_cost(){
    return this.cost;
  }
  String get_name(){
    return this.name;
  }
  double get_price(){ return this.price; }
}