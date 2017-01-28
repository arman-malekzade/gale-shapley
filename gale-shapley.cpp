//
//  gale-shapley.cpp
//  Algorithms
//
//  Created by Arman Malekzade on 1/28/17.
//  Copyright © 2017 GraCk. All rights reserved.
//

#include <iostream>
#define independent_set_size 5
using namespace std;
int* inverse_array(int* arr,int arr_size){
    int* inverse=new int(arr_size);
    for(int i=0;i<arr_size;i++){
        inverse[(*(arr+i))-1]=i+1;
    }
    return inverse;
}
void print_array(int* arr){
    cout<<"Printing started: \n";
    int i=0;
    while(i<independent_set_size){
        cout<<*(arr+i)<<"\n";
        i++;
    }
    cout<<"Printing finished \n";
}
int main(){
    int men_prefer_list[independent_set_size][independent_set_size]={
        {5,2,4,3,1},
        {5,1,4,3,2},
        {4,1,5,2,3},
        {2,1,3,5,4},
        {1,3,4,2,5}
    };
    int women_prefer_list[independent_set_size][independent_set_size]={
        {2,4,3,5,1},
        {1,5,2,4,3},
        {5,4,3,2,1},
        {3,4,5,1,2},
        {1,5,4,3,2}
    };
    int men_engaged[]={0,0,0,0,0};
    int women_engaged[]={0,0,0,0,0};
    for(int i=0;i<independent_set_size;i++){
        cout<<"Trying to find a good partner for Man #"<<i+1<<"\n";
        for(int j=0;j<independent_set_size;j++){
            if(women_engaged[men_prefer_list[i][j]-1]==0){
                cout<<"Man #"<<i+1<<" likes to be with Woman #"<<men_prefer_list[i][j]<<"\n";
                cout<<"Woman #"<<men_prefer_list[i][j]<<" isn\'t engaged to anybody.\nSo Man #"<<i+1<<" became engaged with Woman #"<<men_prefer_list[i][j]<<".\n";
                men_engaged[i]=men_prefer_list[i][j];
                women_engaged[men_prefer_list[i][j]-1]=i+1;
                break;
            }else{
                cout<<"Man #"<<i+1<<" likes Woman #"<<men_prefer_list[i][j]<<".\n";
                cout<<"But Woman #"<<men_prefer_list[i][j]<<" is already engaged."<<"\n";
                int woman=men_prefer_list[i][j];
                int fiance=women_engaged[men_prefer_list[i][j]-1];
                int new_proposer=i+1;
                int accepted=0;
                int* inverse=inverse_array(women_prefer_list[j],5);
                cout<<"Woman #"<<men_prefer_list[i][j]<<" has to choose between Man #"<<i+1<<" and Man #"<<
                fiance<<"\n";
                cout<<"Here is the list of woman #"<<men_prefer_list[i][j]<<"\'s preferences\n";
                print_array(women_prefer_list[men_prefer_list[i][j]-1]);
                if(*(inverse+i)<*(inverse+fiance)) {
                    cout<<"Woman #"<<men_prefer_list[i][j]<<" prefers to be with Man #"<<i+1<<"\n";
                    accepted=1;
                }
                if(accepted==1){
                    men_engaged[fiance-1]=0;
                    women_engaged[woman-1]=new_proposer;
                    men_engaged[new_proposer-1]=woman;
                    break;
                }else{
                    cout<<"Woman #"<<men_prefer_list[i][j]<<" prefers to be with Man #"<<fiance<<"\n";
                    cout<<"So, The proposal was rejected!\n";
                    continue;
                }
            }
        }
    }
    cout<<"-------------------------------------------------------\n";
    for(int a=0;a<independent_set_size;a++){
        if(men_engaged[a]!=0) cout<<"Man #"<<a+1<<" is engaged to Woman #"<<men_engaged[a]<<"\n";
        else cout<<"Man #"<<a+1<<" is not engaged!\n";
    }
    for(int b=0;b<independent_set_size;b++){
        if(women_engaged[b]!=0) cout<<"Woman #"<<b+1<<" is engaged to Man #"<<women_engaged[b]<<"\n";
        else cout<<"Woman #"<<b+1<<" is not engaged!\n";
    }
    cout<<"-------------------------------------------------------\n";
    return 0;
}
