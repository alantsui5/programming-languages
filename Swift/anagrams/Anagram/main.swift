//
//  main.swift
//  Anagram
//
//  Created by Alan on 28/7/2019.
//  Copyright © 2019 Alan Tsui. All rights reserved.
//

import Foundation

//var str = "Hello, playground"


//For int: let number = Int(readLine(strippingNewline: true)!)!
// let stringArray = readLine(strippingNewline: true)!.characters.split {$0 == ” “}.map (String.init)
//?: allow nil, ! assert null


func Anagram1(){
    print("Enter a String to reverse: ")
    let str = readLine(strippingNewline: true)!
    print("("+String((str.reversed()))+")")
}
func Anagram2(){
    let str:String = "Hello World"
    print("("+String((str.reversed()))+")")
}
Anagram1()
