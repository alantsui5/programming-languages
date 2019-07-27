package com.alan;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        // write your code here
        anagram2();
    }

    private static void anagram1() {
        System.out.println("Enter a string of test: ");

        Scanner input = new Scanner(System.in);
        String anagram = input.nextLine();

        System.out.print("(" + reverse(anagram) + ")");
    }

    static String reverse(String str) {
        StringBuilder str_new = new StringBuilder();
        str_new = str_new.append(str).reverse();
        return str_new.toString();


    }

    private static void anagram2() throws IOException {
        System.out.print("Enter the name of file: ");

        Scanner input = new Scanner(System.in);
        String file_name = input.nextLine();

        BufferedReader reader = new BufferedReader(new FileReader(file_name));
        String anagram = reader.readLine();
        while (anagram != null) {
            System.out.println(anagram);
            System.out.println("(" + reverse(anagram) + ")");

            anagram = reader.readLine();
        }

    }
}
