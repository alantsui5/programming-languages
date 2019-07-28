# Why we need cross platform development toolkits
1. Speed up development cycle.
2. Increase app consistency.
3. Increase efficiency.

# Why use dart?
1. Dart is the default language of [Flutter framework]() -- the cross platform mobile toolkit.
2. Dart is easy to learn than java and kotlin.
3. This is developed by Google, this will make more confidence on the community

# Setup
## Installing Compiler ```Dart SDK```
Sicne we only use dart for command line in our scope, so we will install Dart SDK but not Flutter SDK.
If you are interested to flutter, please follow this [link](https://flutter.dev/get-started).
### For Windows
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
choco install dart-sdk
```
### For macOS
```sh
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew tap dart-lang/dart
brew install dart
```
### For Linux
#### Debian Based
```sh
sudo apt-get update
sudo apt-get install apt-transport-https
sudo sh -c 'curl https://dl-ssl.google.com/linux/linux_signing_key.pub | apt-key add -'
sudo sh -c 'curl https://storage.googleapis.com/download.dartlang.org/linux/debian/dart_stable.list > /etc/apt/sources.list.d/dart_stable.list'
sudo apt-get update
sudo apt-get install dart
sudo sh -c 'curl https://storage.googleapis.com/download.dartlang.org/linux/debian/dart_unstable.list > /etc/apt/sources.list.d/dart_unstable.list'
sudo apt-get update
sudo apt-get install dart
echo 'export PATH="$PATH:/usr/lib/dart/bin"' >> ~/.profile
```
#### Arch based
```sh
pacman -S yaourt
yaourt -Syy
yaourt dart-sdk-dev
echo 'export PATH="$PATH:/opt/dart-sdk-dev/bin/"' >> ~/.profile
```
#### RHEL based
This type of distro is not officially supported by google
,but you can go and build it with the [link](https://github.com/dart-lang/sdk/wiki/Building-Dart-on-CentOS,-Red-Hat,-Fedora-and-Amazon-Linux-AMI).

## Recommend IDE/Editer
Please use Visual Studio Code and install dart extension.

## How to run the code
1. Open a empty folder as new project.
2. make ```main.dart```.
3. compile ```main.dart``` in shell using ```dart main.dart``` in shell.


# Let's really get started
## 1. Commenting
1. Single Line commenting using ```//```
	> For example: ```//Hello world```.
2. Multi-Line commenting using ```/* */```
	> For example: ```/* Hello World*/```.

3. Documental Commenting using ```/** **/``` or ```///``` for packages.
	> It can be used as documentation with ```dartdoc``` command.

    > For example: ```/** Hello World **/``` or ```///Hello World```.

## 2. Variable Type
### 2.1 Declare main function
1. Declare a main function for system call when  running this dart program.
	> the code will be executed inside.
  ```dart
  void main(){

  }
  ```
### 2.2 Declaring variables
1. ```var``` variables, dart will automatically determine type of the variable.
  > Note: Types can't be changed after init.
```dart
var name = 'Alice';
```
2. You can specify the types of variable with ```string, int, float``` etc.
> Note: Types can't be changed after init.
```dart
string name = 'Tom';
int ha = 1;
```
3. ```Object``` and ```dynamic```
> Note: Types can be changed after init.
```dart
dynamic name = 'Alice';
name = 1; //valid
Object name2 = 'Sam';
name2 = 4;
```

### 2.3 Default value
> All uninitialised value in dart language are set to ```null```

```dart
//Test the default value of double in dart
double doubleDefault;
// If the condition below is false, then the program will stop
assert(doubleDefault == null);
print(doubleDefault);
```
### 2.4 ```final``` and ```const```
1. ```final``` constant
```dart
final pet = 'cat';
pet = 'rabbit'; //ERROR: A final variable, can only be set once
```
2. ```const``` constant
```dart
const pet = 'dog';
pet = 'rabbit'; //ERROR: Constant variables can't be assigned a value
```
3. If the variable is of type ```Object```, use ```static const```
```dart
static const animals = 'pets';
```
4. ```const``` is a pre-compiled constant

5. You can also create a immutable list/tuple with ```const []```
```dart
var emptyTuples = const [];
var numberTuples = const [1,2,3,4,5];
```
## 3. Types in dart

### 3.1 Numbers type

#### 3.1.1 ```int``` type
  1. ```print()``` in dart = ```printf()``` in c
  2. ```${}``` is string formatting method to print variable
  3. ```num1.bitLength``` is the no. of bit consumed by num1
```dart
int num1 = 10 ;
print(num1);
print('${num1.bitLength}');//Output: 4
```
#### 3.1.2 ```double``` type
  > ```1.38e3``` in dart = ```1.38*10^3```
```dart
double num1 = 1.1 ;
print(num1);
double num2 = 1.38e3;
print(num2);// Output: 1380.0
```
#### 3.1.3 Numbers Conversion
1. ```int``` to ```double```
```dart
int test = 23;
print(test.toDouble()); // Output： 23.0
```
2. ```double``` to ```int```
```dart
int test = 23.343242;
print(test.toDouble()); // Output： 23
```

### 3.2 String Type
#### 3.2.1 String representation
String in dart is a **UTF-16** char series.
And can be enclosed with ```' '``` or ```" "```
```dart
String str1 = 'I am str1';
String str2 = "I am str2";
```
#### 3.2.2 String Concatenation
```dart
//First method
String str1 = 'hello'' ''world';//Output: hello world
String str2 = 'hello''_''world';//Output: hello_world
String str3 = 'hello''abcdefg''world';//Output: helloabcdefgworld
String str4 = 'hello''''world'; //Error
```
```dart
//Second method
String str5 =  'hello'+ 'world'+ 'haha';//Output: helloworldhaha
String str6 =  'hello'+ ' '+ 'world';//Output: hello world
String str7 =  'hello'+ '_'+ 'world';//Output: hello_world
```

#### 3.2.3 show ```"``` or ```'``` in String
```dart
String str1 = 'hello""""world';//Output: hello""""world
String str2 = 'he"llo"""world';//Output: he"llo"""world
String str3 = "hello''''world";//Output: hello''''world
String str4 = "he'llow'orl'd";//Output: he'llow'orl'd
```

#### 3.2.4 Multi-line string
```dart
//Double quote
String multiLine1 = """
dfdsfdsf
cvdvfdf
dcdvdsc
""";
//Single Quote
String multiLine2 = '''
dfdsfdf
fgdsfdsf
gdsfgdf
''';
```

#### 3.2.5 The Format specifier ```$your_variable```
Unlike ```C```,  dart uses   ```${variable_name}``` for any  type of variable in string
```dart
var height = 48.0;
print('Your height is ${height}'); //Output: Your height is 48
String name = 'Amy';
print('${name}'+' is my girl friend');//Output: Amy is my girl friend
```
PS: cases Functions
```dart
${"cuhk".toUpperCase()} //Output: CUHK
${"CSCI".toLowerCase()} //Output: csci
```

### 3.3 Boolean
```bool``` type involve  ```true``` and ```false``` value, like  ```C```  with  ```stdbool```

### 3.4 ```List``` in dart
```dart
//List with type int
List list = [10, 7, 23];
print(List); //Output: [10,7,23]
//Tuple init
List list2 = const[10,3,15];
print(List); //Output: [10,3,15]
//You can also specify the type of List using <>
List<int> list3 = [1,2,3];
```

#### 3.4.1 some important functions
1. Insertion
``` list1.add(1);```  add 1 at the end of list.
2. Removal
```list1.remove(1);``` remove the nunber `1` in the list.
3. Find the index of a value, eg: ```10```
```int value = list.indexOf(10);```
4. Determine whether an element exist
```bool result = list.contains(5);```
5. Insertion at specified index
```dart
//insert 5 at index 0
list.insert(0, 5);
```

### 3.5 ```Map``` in dart
1. ```Map``` = hash table/dictionary
```dart
//Direct init
Map num = {'1e':'one', '2e':second, '3e':third};
//create then init
Map num1 = new Map;
num['1e']='one';
num['2e']='two';
num['3e']='third';
num[3]="three;
```

## 4. Control Flow
### 4.1 typical ```if, while, for```
The syntax of  ```if, while, for``` is the same with  ```C```
### 4.2 Iterating lists
#### 4.2.1  ```forEach```
```forEach```  is used to iterate every element in a list, and used to
```dart
