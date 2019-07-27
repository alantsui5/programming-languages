package com.alan;

import java.util.HashMap;
import java.util.Map;
//https://dev.to/chrisvasqm/introduction-to-unit-testing-with-java-2544
public class Main {

    public static void main(String[] args) {
	// write your code here
        Map<String, Pizza> pizzas = new HashMap<>();
        pizzas.put("A",new Pizza("Pizza A",34.33));
        pizzas.put("B",new Pizza("Pizza B",12.88));
        pizzas.put("C",new Pizza("Pizza C",45.11));
        System.out.println("get: " + pizzas.get("A").get_name());
        System.out.println("get: " + pizzas.get("B").get_name());
        System.out.println("get: " + pizzas.get("C").get_name());
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

    public void edit_pizza(String name, double price){
        this.name = name;
        this.price = price;
    }
    public void edit_pizza(double price){
        this.price = price;
    }
    public void edit_pizza(String name){
        this.name = name;
    }

    public void order(){
        this.number += 1;
        this.cost+=price;
    }
    public double get_cost(){
        return cost;
    }
    String get_name(){
        return this.name;
    }
}