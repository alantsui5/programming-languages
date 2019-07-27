import 'dart:convert';
import 'dart:io';

import 'package:Anagram/Anagram.dart' as Anagram;

main(List<String> arguments) {
  anagram2();
}
String reverse(String str){
    return str.split('').reversed.join('');
}

void anagram(){
  print('Enter a string of text: ');
  var str = stdin.readLineSync();
  print("(${reverse(str)})");
}

void anagram2(){
  print('Enter the name of the file: ');
  //
  var file_name = stdin.readLineSync();
  final myFile = File(file_name);
  Stream<List<int>> inputStream = myFile.openRead();

  inputStream
  .transform(utf8.decoder)
  .transform(LineSplitter())
    .listen((String line){
      print(line);
      print("(${reverse(line)})");
    },
  onDone: (){print('File is closed');},
  onError: (e) {print(e.toString());});

}

