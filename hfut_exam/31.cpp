#include <iostream>

using namespace std;

void findNumbers(){
    for(int i=10;i<1000;i++){
        int a=i/100;
        int b=i/10%10;
        int c=i%10;
        if(a<b&&b<c){
            cout<<i<<endl;
        }
    }
}
void findPrimeFactors(int n){
    cout << "The prime factors of " << n << " are: ";
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
}

// 递归
int  findFibo(int n){
    if(n==1||n==2){
        return 1;
    }
    return findFibo(n-1)+findFibo(n-2);
}
//迭代
int findFibo2(int n){
    int a=1,b=1,c;
    for(int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

void showOdds(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<2*j-1<<" ";
        }
        for(int j=i-1;j>=1;j--){
            cout<<2*j-1<<" ";
        }
        cout<<endl;
    }
}

void showAlph(int n){
    char ch[n]={0};
    for(int i=0;i<n;i++){
        ch[i]='A'+i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ch[(j+i)%n]<<" ";
        }
        cout<<endl;
    }
}


bool isCircleNum_10(int n){
    int sum=0;
    int temp=n;
    while(n){
        sum=sum*10+n%10;
        n/=10;
    }
    return sum==temp;
}

bool isCircleNum_2(int n){
    int sum=0;
    int temp=n;
    while(n){
        sum=sum*2+n%2;
        n/=2;
    }
    return sum==temp;
}

void showCircleNum(int max_num){
    for(int i=1;i<=max_num;i++){
        if(isCircleNum_10(i)&&isCircleNum_2(i)){
            cout<<i<<endl;
        }
    }
}

void int2str(int number) {
    // 处理负数的情况
    if (number < 0) {
        cout << "-"; // 输出负号
        int2str(-number); // 递归处理正数部分
        return;
    } 
    // 基本情况：数字是 0-9 之间
    if (number < 10) {
        // 直接输出对应字符
        cout << char(number + '0');
        return;
    }
    // 递归情况：处理多位数
    // 先处理除最后一位以外的部分
    int2str(number / 10);
    // 然后处理最后一位
    cout << char(number % 10 + '0');
}

int hex2dec(string hex){
    int dec=0;
    for(int i=0;i<hex.size();i++){
        if(hex[i]>='0'&&hex[i]<='9'){
            dec=dec*16+hex[i]-'0';
        }else if(hex[i]>='A'&&hex[i]<='F'){
            dec=dec*16+hex[i]-'A'+10;
        }else if(hex[i]>='a'&&hex[i]<='f'){
            dec=dec*16+hex[i]-'a'+10;
        }else{
            cout<<"Invalid hex number!"<<endl;
            return -1;
        }
    }
    return dec;
}

string dec2hex(int dec){
    string hex;
    while(dec!=0){
        int temp=dec%16;
        if(temp<10){
            hex=char(temp+'0')+hex;
        }else{
            hex=char(temp-10+'A')+hex;
        }
        dec/=16;
    }
    return hex;
}

bool isPrime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void findPrime(int n){
    int count=0;
    for(int i=2;i<n;i++){
        if(!isPrime(i)){
            count++;
        }else{
            count=0;
        }
        if(count>10&&isPrime(i+1)){
            cout<<i-count+1<<"~"<<i<<endl;
        }
    }
}

void countChars(){
    cout<<"Please input a string:"<<endl;
    string str;
    getline(cin,str);
    int ccount[26]={0},i=0;
    while(str[i]!='\0'){
        if(str[i]>='a'&&str[i]<='z'){
            ccount[str[i]-'a']++;
        }
        i++;
    }
    for(int i=0;i<26;i++){
        if(ccount[i]!=0){
            cout<<char(i+'a')<<":"<<ccount[i]<<endl;
        }
    }
}

int main(){
    //findNumbers();
    //findPrimeFactors(16);
    //cout<<findFibo(10)<<endl;
    //cout<<findFibo2(11)<<endl;
    //showOdds(11);
    //showAlph(5);
    //showCircleNum(1000);
    //int2str(-12345);
    //cout<<hex2dec("A2")<<endl;
    //cout<<dec2hex(162)<<endl;
    //findPrime(2000);
    countChars();
    return 0;
}