#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  const char keyboard[] = " `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  const int kblen = strlen(keyboard);
  char hash[256];
  string s;

  for(int i = 0 ; i < 256 ; ++i){
    hash[i] = i;
  }

  for( int i = 2 ; i < kblen ; ++i ){
    hash[keyboard[i]] = keyboard[i-1];
  }

  while(getline(cin, s)){
    for(int i = 0 ; i < s.length() ; i++){
      printf( "%c", hash[s[i]] );
    }
    printf( "\n" );
  }

  return 0;
}