#include <iostream>

int change(int money, int coin);

int main(){
    int money;

    std::cout<<"Enter amount to change: "<<std::endl;
    std::cin>>money;
    //money=50;
    int amount = change(money, 25);
    std::cout<<amount<<std::endl;



}

int change(int money, int coin){

    if(money==0){
        return 1;
    }

    if(money>=25 && coin >= 25){
      return change(money-25,25)+change(money-25,10)+change(money-25,5)+change(money-25,1);
    }
    else if(money>=10 && coin>=10){
        return change(money-10,25)+change(money-10,10)+change(money-10,5)+change(money-10,1);
    }
    else if(money>=5 && coin >= 5){
        return change(money-5,25)+change(money-5,10)+change(money-5,5)+change(money-5,1);
    }
    else if(money>=1 && coin >= 1){
        return change(money-1,25)+change(money-1,10)+change(money-1,5)+change(money-1,1);
    }
}

