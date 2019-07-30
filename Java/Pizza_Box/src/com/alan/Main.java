package com.alan;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//https://dev.to/chrisvasqm/introduction-to-unit-testing-with-java-2544
public class Main {

    public static void main(String[] args) {
	// write your code here
        double tax = 0.02;
        double cost=0;
        Map<String, Pizza> pizzas = new HashMap<>();
        pizzas.put("A",new Pizza("Pizza A",34.33));
        pizzas.put("B",new Pizza("Pizza B",12.88));
        pizzas.put("C",new Pizza("Pizza C",45.11));

        Scanner input = new Scanner(System.in);
        int choice = input.nextInt();
        switch(choice){
            case 1:
                cost+= pizzas.get("A").getPrice();
                pizzas.get("A").order();
                break;
            case 2:
                cost += pizzas.get("B").getPrice();
                pizzas.get("B").order();
                break;
            case 3:
                cost += pizzas.get("C").getPrice();
                pizzas.get("C").order();
                break;
            case 0:
                System.out.println("Terminating...");
                exit(0);
            default:
                System.out.println("You inserted wrong choice.");

        }
        cost = taxed_cost(cost,tax);
        System.out.println(cost);
        System.out.println(pizzas.get("A").getCost());
        System.out.println(pizzas.get("B").getCost());
        System.out.println(pizzas.get("C").getCost());

    }

    private static double taxed_cost(double cost, double tax){
        return tax * cost;
    }
}

class Pizza {
    private double price;
    private String name;
    private double cost = 0;
    private int number = 0;

    Pizza(String name, double price){
        this.price = price;
        this.name = name;
    }

    public void editPizza(String name, double price){
        this.name = name;
        this.price = price;
    }
    public void editPizza(double price){
        this.price = price;
    }
    public void editPizza(String name){
        this.name = name;
    }

    void order(){
        this.number += 1;
        this.cost+=price;
    }
    double getCost(){
        return this.cost;
    }
    String getName(){
        return this.name;
    }
    double getPrice(){ return this.price; }
}
