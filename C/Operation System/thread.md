這裡介紹如何在 C 語言中使用 `pthread` 開發多執行緒的平行化程式，用多顆 CPU 加速計算。

現在電腦的 CPU 都具備多顆核心，因此在使用 C 語言撰寫計算用的程式時，若能夠善用多核新的 CPU 進行平行運算，可以讓計算速度大幅提昇。

若要將 C 語言的程式平行化，最基本的方式就是使用 POSIX 執行緒（簡稱 pthread）來實做多執行緒的程式，以下是 `pthread` 函式庫的用法教學，以及實際的範例程式碼。

# Pthread 多執行緒
`pthread` 的 `pthread_create` 函數可以用來建立新的執行緒，並以函數指標指定子執行緒所要執行的函數，子執行緒在建立之後，就會以平行的方式執行，在子執行緒的執行期間，主執行緒還是可以正常執行自己的工作，最後主執行緒再以 `pthread_join` 函數等待子執行緒執行結束，處理後續收尾的動作。

以下是一個 `pthread` 的 hello world 範例程式碼：
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 子執行緒函數
void* child(void* data) {
  char *str = (char*) data; // 取得輸入資料
  for(int i = 0;i < 3;++i) {
    printf("%s\n", str); // 每秒輸出文字
    sleep(1);
  }
  pthread_exit(NULL); // 離開子執行緒
}

// 主程式
int main() {
  pthread_t t; // 宣告 pthread 變數
  pthread_create(&t, NULL, child, "Child"); // 建立子執行緒

  // 主執行緒工作
  for(int i = 0;i < 3;++i) {
    printf("Master\n"); // 每秒輸出文字
    sleep(1);
  }

  pthread_join(t, NULL); // 等待子執行緒執行完成
  return 0;
}
```
此程式在主執行緒中建立一個子執行緒，並將 `"Child"` 這個字串傳遞給子執行緒，然後讓兩個執行緒同時輸出文字。

使用 `gcc` 編譯時，要加上 `-lpthread` 參數：
```sh
gcc hello.c -lpthread -o hello
```
編譯好之後，執行之：
```sh
./hello
```
>Master <br>
>Child <br>
>Master <br>
>Child <br>
>Master <br>
>Child <br>

# 資料傳遞
在許多的平行化應用程式中，我們都會需要傳遞一些資料給子執行緒進行計算，而在計算完之後再將結果傳回來，而子執行緒在傳回資料時通常都會以 `malloc` 配置記憶體空間來存放傳回的資料，以下是一個典型的範例：
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 子執行緒函數
void *child(void *arg) {
   int *input = (int *) arg; // 取得資料
   int *result = malloc(sizeof(int) * 1); // 配置記憶體
   result[0] = input[0] + input[1]; // 進行計算
   pthread_exit((void *) result); // 傳回結果
}

// 主程式
int main() {
   pthread_t t;
   void *ret; // 子執行緒傳回值
   int input[2] = {1, 2}; // 輸入的資料

   // 建立子執行緒，傳入 input 進行計算
   pthread_create(&t, NULL, child, (void*) input);

   // 等待子執行緒計算完畢
   pthread_join(t, &ret);

   // 取得計算結果
   int *result = (int *) ret;

   // 輸出計算結果
   printf("%d + %d = %d\n", input[0], input[1], result[0]);

   // 釋放記憶體
   free(result);

   return 0;
}
```
執行的輸出為：
> 1 + 2 = 3
這個程式中，子執行緒呼叫 `malloc` 配置了記憶體空間，而主執行緒在使用完該記憶體空間之後，負責釋放掉不再使用的記憶體。

# 由主執行緒管理記憶體
多執行緒之間的記憶體管理其實很不方便，也很容易不小心寫錯，造成記憶體流失（memory leak）問題，若想避免這個問題，可以統一由主執行緒來管理記憶體，以下是一個範例：
```c
#include <stdio.h>
#include <pthread.h>

// 自己定義的資料結構
typedef struct my_data {
   int a;
   int b;
   int result;
} my_data;

// 子執行緒函數
void *child(void *arg) {
   my_data *data=(my_data *)arg; // 取得資料

   int a = data->a;
   int b = data->b;
   int result = a + b; // 進行計算

   data->result = result; // 將結果放進 data 中
   pthread_exit(NULL);
}

// 主程式
int main() {
   pthread_t t;
   my_data data;

   data.a = 1;
   data.b = 2;

   // 建立子執行緒，傳入 data 進行計算
   pthread_create(&t, NULL, child, (void*) &data);

   // 等待子執行緒計算完畢
   pthread_join(t, NULL);

   // 從 data.result 取回計算結果
   printf("%d + %d = %d\n", data.a, data.b, data.result);

   return 0;
}
```
這個例子中，我們使用自己定義的資料結構（struct），將所有的輸入資料與輸出結果欄位都包裝在一個 `my_data` 中，以指標的方式傳入子執行緒中，讓子執行緒在計算完成後，將結果直接寫入 `my_data` 的 `result` 欄位，這樣就不需要另外配置記憶體空間，而主執行緒也可以直接取得計算結果。

# 互斥鎖（Mutex）
在平行化的程式中，如果發生多個執行緒需要同時存取同一個位置的資料時，就有可能會因為同時存取而產生錯誤，在下面這個例子中，我們定義一個全域變數 `counter`，用來紀錄某個量的總和，而我們希望在多個執行緒中同時計算，然後統一將加總的結果放在其中。
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 計數器
int counter = 0;

// 子執行緒函數
void* child() {
  for(int i = 0;i < 3;++i) {
    int tmp = counter;
    sleep(1); // 故意讓它延遲一下
    counter = tmp + 1;
    printf("Counter = %d\n", counter);
  }
  pthread_exit(NULL);
}

// 主程式
int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, child, NULL);
  pthread_create(&t2, NULL, child, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
```
在這段程式碼中，我們放了兩個子執行緒，每個子執行緒用迴圈跑了三次計算，所以最後的 `counter` 預期應該是 `6`，但由於我們將 `counter` 的值取出來，計算出新的值之後在放回去，兩個子執行緒同時都這樣做的話，計算結果就會不如預期：
> Counter = 1 <br>
> Counter = 1 <br>
> Counter = 2<br>
> Counter = 2<br>
> Counter = 3<br>
> Counter = 3<br>
這個問題的解決方法就是加入一個互斥鎖（mutex），將那些不可以被多個執行緒同時執行的程式碼片段，用互斥鎖包起來，當一個執行緒執行到該處時，就會先上鎖，避免其他的執行緒進入，若其他的執行緒同時也要執行該處的程式碼時，就必須等待先前的執行緒執行完之後，才能接著進入（也就是排隊輪流使用的概念），這樣就可以避免多個執行緒混雜執行，讓結果出錯的問題。
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 計數器
int counter = 0;

// 加入 Mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// 子執行緒函數
void* child() {
  for(int i = 0;i < 3;++i) {
    pthread_mutex_lock( &mutex1 ); // 上鎖
    int tmp = counter;
    sleep(1);
    counter = tmp + 1;
    pthread_mutex_unlock( &mutex1 ); // 解鎖
    printf("Counter = %d\n", counter);
  }
  pthread_exit(NULL);
}

// 主程式
int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, child, NULL);
  pthread_create(&t2, NULL, child, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
```
> Counter = 1 <br>
> Counter = 2 <br>
> Counter = 3 <br>
> Counter = 4 <br>
> Counter = 5 <br>
> Counter = 6 <br>
在 `pthread_mutex_lock` 與 `pthread_mutex_unlock` 之間的程式碼就是一次只容許一個執行緒執行的部份，也就是說雖然是平行化的程式，但是被包住的這部份只能以單一執行緒來執行，所以在設計程式時，要盡可能減少被互斥鎖包住的程式碼，才能讓程式執行效能更好。
# 旗標（Semaphore）
如果我們現在有兩個執行緒，分別負責一份工作的前半段與後半段，也就是說第一個執行緒會把它處理好的資料，發包給第二個執行緒繼續處理，而兩個執行緒的處理速度有可能不同，這種狀況我們就可以使用旗標（Semaphore）的方式來串接。

旗標本身就是一個計數器，也就是紀錄目前尚未處理的工作數量，我們可以使用 `sem_wait` 來判斷是否有尚未處理的工作，當工作數量大於 0 時，`sem_wait` 就會讓執行緒進入處理，並且把工作數量遞減 1，而如果工作數量為 0 的時候，則會讓執行緒等待，直到有新的工作來臨時，才讓執行緒進入。

另外在產生工作的執行緒中，可以使用 sem_post 放入新的工作（也就讓將計數器遞增 1），這樣就可以將多個執行緒串接起來處理大型的工作流程。

以下是一個簡單的範例：