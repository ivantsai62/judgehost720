#include <iostream>
#include <cstring>
#include <string>
#define Base 100000000	//基底 
#define Len 8	//基底數字長度 
using namespace std;
struct BigN{
  int dig[1000];	//存放數字 
  int len;	//存放dig[]的長度 
  BigN();	//建構子 
  BigN(const char *);	//數字字串建構子
  BigN(const int);	//整數數字建構子
  BigN(const BigN &);	//大數建構子
  friend ostream& operator<<(ostream&,BigN&);	//輸出運算重載
  bool operator<(const BigN&)const;	//小於運算子重載
  bool operator<=(const BigN&)const;	//小於等於運算子重載
  bool operator>(const BigN&)const;	//大於運算子重載
  bool operator>=(const BigN&)const;	//大於等於運算子重載 
  BigN &operator=(const BigN&);	//指定運算子重載 
  BigN operator+(const BigN&)const;	//加號運算子重載 
  BigN operator*(const BigN&)const;	//乘號運算子重載 
};
BigN::BigN(){	//預設建構子
  memset(dig,0,sizeof(dig));
  len=1;
}
BigN::BigN(const int x){	//整數建構子 
  len=0;
  int y=x;
  while (y%Base > 0) {
    dig[len++]=y%Base;
    y=y/Base;
  }
}
BigN::BigN(const BigN &x){	//大數建構子
  len=x.len;
  memset(dig,0,sizeof(dig));
  for(int i=0;i<x.len;i++){
    dig[i]=x.dig[i];
  }
}
BigN::BigN(const char *x){	//數字字串建構子，可以使用數字字串初始化大數，例如：BigN a("12345678987"); 
  int L=strlen(x),num,j,k;
  len=L/Len;	//重字串右邊開始切割數字字串，長度為len 
  if (L%Len) len++;	//若無法整除，len加1 
  j=L;
  for(int i=0;i<len;i++){//將x字串8個切割成一個數字，儲存到num 
    num=0;
    if (j>=Len) k=j-Len; else k=0;//8個數字的左邊界為k，右邊界為j 
    for(int p=k;p<j;p++){
      num=num*10+(x[p]-'0');//還原為數字 
    }
    dig[i]=num;
    j=j-8;
  }
}
bool BigN::operator<(const BigN& rhs) const{//小於運算子重載，(*this)在小於左邊，輸入參數rhs在小於右邊 
  if (len < rhs.len) return true;//左邊數字長度小於右邊數字長度，左邊小於右邊 
  else if (len == rhs.len){//左邊數字長度等於右邊數字長度
    for(int i=len-1;i>=0;i--){//比較裡面的數字大小，從最高位數字開始 
      if (dig[i]<rhs.dig[i]) return true;//左邊數字小於右邊數字，左邊小於右邊
      else if (dig[i]>rhs.dig[i]) return false;//左邊數字大於右邊數字，左邊沒有小於右邊
    }
    return false;//左右兩邊相等，左邊沒有小於右邊 
  }else{
    return false;//左邊數字長度大於右邊數字長度，左邊沒有小於右邊 
  }
}
bool BigN::operator>(const BigN& rhs) const{//大於運算子重載，(*this)在大於左邊，輸入參數rhs在大於右邊
  if (len > rhs.len) return true;//左邊數字長度大於右邊數字長度，左邊大於右邊 
  else if (len == rhs.len){//左邊數字長度等於右邊數字長度
    for(int i=len-1;i>=0;i--){//比較裡面的數字大小，從最高位數字開始 
      if (dig[i]>rhs.dig[i]) return true;//左邊數字大於右邊數字，左邊大於右邊
      else if (dig[i]<rhs.dig[i]) return false;//左邊數字小於右邊數字，左邊沒有大於右邊
    }
    return false;//左右兩邊相等，左邊沒有大於右邊
  }else{
    return false;//左邊數字長度小於右邊數字長度，左邊沒有大於右邊
  }
}
bool BigN::operator<=(const BigN& rhs) const{//小於等於運算子重載，是大於運算子的相反 
  if ((*this)>rhs) return false;//左邊數字大於右邊數字，左邊沒有小於等於右邊
  else return true;//否則，左邊小於等於右邊
}
bool BigN::operator>=(const BigN& rhs) const{//大於等於運算子重載，是小於運算子的相反 
  if ((*this)<rhs) return false;//左邊數字小於右邊數字，左邊沒有大於等於右邊
  else return true;//否則，左邊大於等於右邊
}
ostream& operator<<(ostream& out,BigN& x){//輸出運算子重載 
  cout << x.dig[x.len-1];//輸出最高位 
  for(int i=x.len-2;i>=0;i--){//輸出最二位以後，左側補0，長度為8 
    cout.width(Len);
    cout.fill('0');
    cout << x.dig[i];
  }
  return out;
}
BigN & BigN::operator=(const BigN &x){//指定運算子重載，將x複製到(*this)，就是x複製給自己 
  len=x.len;
  memset(dig,0,sizeof(dig));
  for(int i=0;i<x.len;i++){
    dig[i]=x.dig[i];
  }
  return *this;
} 
BigN BigN::operator+(const BigN& rhs)const{//加號運算子重載，計算(*this+rhs) 
	BigN x(*this);//x初始化為*this 
  int max;
  if (x.len>rhs.len) max=x.len; //x與rhs長度較大放到max 
  else max=rhs.len;
  for(int i=0;i<max;i++){
    x.dig[i]+=rhs.dig[i];//加總rhs.dig[]到x.dig[] 
    if (x.dig[i]>=Base){//超過基底，有進位 
      x.dig[i]=x.dig[i]%Base;
      x.dig[i+1]++;//進位1，加到x.dig[i+1] 
    }
  }
  if (x.dig[max]>0){//進位到最高位的再高一位，dig[max]是沒有用到的，表示相加過程進位到dig[max] 
    x.len=max+1;//長度加1 
  }else{
    x.len=max;
  }
  return x;
}
BigN BigN::operator*(const BigN& rhs)const{//乘法運算子重載，計算x=((*this)*rhs) 
  BigN x;
  long long int tmp;
  int r,i,j;
  for(i=0;i<len;i++){//(*this)
    r=0;
    tmp=0;
    for(j=0;j<rhs.len;j++){//rhs
      tmp=(long long)dig[i]*rhs.dig[j]+x.dig[i+j]+r;//dig[i+j]之前的暫存，r為上一次相乘的進位 
      if (tmp>=Base){//需要進位 
        x.dig[i+j]=tmp%Base;//儲存到x.dig[i+j] 
        r=tmp/Base;//進位加到更高的下一位 
      }else{//不需要進位
        x.dig[i+j]=tmp;
        r=0;//進位為0 
      }
    }
    if (r>0) x.dig[i+j]=r;
  }
  x.len=i+j;//更新長度，長度最大為i+j 
  while((x.dig[x.len-1]==0)&&(x.len>1)){//x.dig[x.len-1]若等於0表示沒用到，x.len減1 
    x.len--;
  }
  return x;
}
int main(){
  string sa,sb;
  while(cin>>sa>>sb){
    BigN a(sa.c_str()),b(sb.c_str()),c;
    c=a*b;
    cout <<c <<endl;
  }
}