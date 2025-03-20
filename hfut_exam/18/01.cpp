# include <iostream>

int reverse(int a){
	int b=0;
	while(a!=0){
		b=b*10+a%10;
		a/=10;
	}
    return b;
}

int main(){
    int a,b;
    std::cin>>a>>b;
    a=reverse(a);
    b=reverse(b);
    std::cout<<reverse(a+b);
    return 0;
}