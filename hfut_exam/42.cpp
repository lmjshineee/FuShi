#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Bubble(int data[],int length){
    for(int i=0;i<length-1;i++){
        bool flag=false;
        for(int j=length-1;j>i;j--){
            if(data[j-1]>data[j]){
                swap(data[j-1],data[j]);
                flag=true;
            }
        }
        if(!flag) break;
    }
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void Reverse(int A[],int n){
    for(int i=0;i<n/2;i++){
        swap(A[i],A[n-i-1]);
    }
}

void swapNum(int A[],int m,int n){
    Reverse(A,m);
    Reverse(A,m+n);
    Reverse(A,n);
    for(int i=0;i<m+n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// ģ����Ŀ������ɸѡ����
void sievePrimes(int n) {
    cout << "\nʹ����Ŀ������ɸѡ����" << endl;
    // ��ʼ�����飬�洢 2 �� n ��������
    vector<int> numbers;
    for (int i = 2; i <= n; i++) {
        numbers.push_back(i);
    }
    vector<int> primes; // �洢�ҵ�������
    // ʵ��ɸѡ����
    while (!numbers.empty()) {
        // a. �ҳ���С�� K����Ϊ������
        int k = numbers[0];
        primes.push_back(k);
        
        // b. ��������ɾ�� K ���䱶��
        vector<int> temp;
        for (int num : numbers) {
            if (num % k != 0) { // ���� K �ı�������
                temp.push_back(num);
            }
        }
        numbers = temp;
    }
    // ������
    cout << "���ҵ�" << primes.size() << "��������" << endl;
    const int PRIMES_PER_LINE = 10;
    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i];
        if ((i + 1) % PRIMES_PER_LINE == 0 || i == primes.size() - 1) {
            cout << endl;
        } else {
            cout << "\t";
        }
    }
}

// ���ֲ��� ����
void BinarySearch(int data[],int low,int high,int key){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(data[mid]==key){
            cout<<mid+1<<endl;
            return;
        }else if(data[mid]<key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"Not found!"<<endl;
}

void findMartix(){
    int n,m;
    cout<<"Please input the size of the matrix:"<<endl;
    cin>>n>>m;
    int data[n][m];
    cout<<"Please input the matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>data[i][j];
        }
    }
    int max=data[0][0],temp1,temp2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(data[i][j]>max){
                max=data[i][j];
                temp1=i;
                temp2=j;
            }
        }
    }
    cout<<"("<<temp1+1<<" "<<temp2+1<<"): "<<max<<endl;
}


int main(){
    //int data[]={3,1,4,1,5,9,2,6,5,3,5};
    //Bubble(data,11);
    //swapNum(data,5,6);
    //sievePrimes(100);
    //int data[]={100,90,80,70,60,50,40,30,20,10};
    //BinarySearch(data,0,9,50);
    findMartix();
    return 0;
}