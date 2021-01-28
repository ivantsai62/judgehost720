#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
  string s;
  int ascii[256], maxnum;
  while( getline( cin, s ) ){
    memset( ascii, 0, sizeof(ascii) );
    maxnum = 0;
    for( int i = 0 ; i < s.length() ; i++ ){
      if( !isalpha(s[i]) ) continue;
      ascii[s[i]]++;
      if( ascii[s[i]] > maxnum ) maxnum = ascii[s[i]];
    }

    for( int i = 'A' ; i <= 'Z' ; i++ )
      if( ascii[i] == maxnum ) printf( "%c", i );
    for( int i = 'a' ; i <= 'z' ; i++ )
      if( ascii[i] == maxnum ) printf( "%c", i );
    printf( " %d\n", maxnum );
  }
  return 0;
}