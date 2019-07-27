import 'package:Anagram/Anagram.dart';
import 'package:test/test.dart';

String reverse(String str){
  return str.split('').reversed.join('');
}

void main() {
  test('Reverse char',(){
    expect(reverse('haha'),equals('ahah'));
  });
  test('Reverse char',(){
    expect(reverse('BJKLHU%*&(%^%'),equals('%^%(&*%UHLKJB'));
  });

}
