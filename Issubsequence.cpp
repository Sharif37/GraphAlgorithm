#include<bits/stdc++.h>
using namespace std ;



int main()
{
    string s,t ;
    cin>>s>>t ;
    int l=t.size();


   string subsequence[1>>l];// there are 2^n subsequences
   string str ;
   for(int i=0 ;i<=l ;i++)
   {
       str="";
       for(int j=0;j<i;j++)
       {
           str+=t[j];
       }
       subsequence[i]
   }


}
