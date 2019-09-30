/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elkay
 *
 * Created on 17 October, 2018, 10:26 PM
 */

#include <bits/stdc++.h> 

using namespace std;

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r){
    int i;
    if(l == r){
        cout<<a<<endl;
    }else{
       for(int i = l; i<=r; i++){
        swap((a+l),(a+i));
        permute(a,l+1, r);
        swap((a+l),(a+i));
       } 
    }
    
}
int main() {

    string s;
    cin>>s;
    int n = s.length();
    
    char str[n+1];
    strcpy(str,s.c_str());
    permute(str,0,n-1);
    return 0;
}

