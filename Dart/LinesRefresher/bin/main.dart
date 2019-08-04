import 'dart:io';
import 'dart:async';

main(){
  new Future(()=>refresher('Loading',0));
  new Future(()=>refresher('Pending',1));
}
/*
Future<void> asyncLoader(message,line) async {
  await refresher(message,line);
}
*/


void refresher(message,line){
  stdout.write('\n'*line);
  while(true){
    for (int i=0;i<4;i++){     
      stdout.write('\r'+message+'.'*i+'   ');
      sleep(const Duration(seconds:1));
    }
  }  
}
