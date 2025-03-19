# include <iostream>
using namespace std;
/*  
简单线代题
*/
void test() {
   int T;
   cin >> T;
   int a[T];
   for(int i = 0; i < T; i++) {
      int m,n;
      cin >> m >> n;
      if((9*m-n)%80!=0) 
         a[i] = -1;
      else
         a[i] = (9*m-n)/80;
   }
   for(int i = 0; i < T; i++) {
      cout << a[i] << " "; 
   }
}
int main() {
    test();
    return 0;
}