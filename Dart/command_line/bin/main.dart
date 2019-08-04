import 'package:command_line/command_line.dart' as command_line;
import 'dart:io';

main() {
  println("The Universal Download Manager")
  Process.run('aria2c',['-x16','http://mirrors.uni-plovdiv.net/archlinux/iso/2019.08.01/archlinux-2019.08.01-x86_64.iso']).then((ProcessResult results){
    print(results.stdout);
  });
  Process.run('aria2c',['-x16','http://br.mirror.archlinux-br.org/iso/2019.08.01/archlinux-2019.08.01-x86_64.iso']).then((ProcessResult results){
    print(results.stdout);
  });
}
