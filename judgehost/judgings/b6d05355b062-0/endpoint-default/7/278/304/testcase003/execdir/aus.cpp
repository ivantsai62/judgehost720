#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
typedef struct _candidate{
  string name;
  int vote;//得票數
  bool eliminate;//是否要被刪除
}Cand;
Cand candidate[20];//候選人
vector<int> ballot[1000];//選票
int numCandidate,numBollot,numBChoice;
void compVote(){//計算得票數
  for(int i=0;i<numCandidate;i++){
	 candidate[i].vote=0;
  }
  for(int i=0;i<numBollot;i++){
    candidate[ballot[i][0]-1].vote++;
  }
}
void elimMin(int min){
  numBChoice=ballot[0].size();//目前選票還剩下的候選人個數
  for(int i=0;i<numBollot;i++){
	for(int j=numBChoice-1;j>=0;j--){//從後面刪除才不會超出vector範圍
      if (ballot[i][j]==min){
        ballot[i].erase(ballot[i].begin()+j);//刪除選票中ballot[i][j]候選人
		break;//找到一個就可以中斷，因為只有一個
	  }
	}
  }
}
int main(){
  int cases,k,choice,max,maxIndex,min,minIndex;
  string s;
  cin>> cases;
  for(int i=0;i<cases;i++){
    cin >> numCandidate;//輸入候選人個數
	cin.ignore();
	for(int j=0;j<numCandidate;j++){
      getline(cin,s);//輸入姓名
	  candidate[j].name=s;
	  candidate[j].vote=0;
	  candidate[j].eliminate=false;
	}
	k=0;
	while(getline(cin,s)){//輸入選票結果
	  if (s=="") break;
      istringstream iss(s);
	  ballot[k].resize(numCandidate);
	  for(int j=0;j<numCandidate;j++){
		iss >> choice;
	    ballot[k][j]=choice;
	  }
	  k++;
	}
	numBollot=k;
	if (i>0) cout << endl;
	while(1){
      compVote();
	  max=0;//找選票最多的票數
	  min=1001;
	  for(int j=0;j<numCandidate;j++){//找出最多選票的第一位
        if ((candidate[j].eliminate==false)&&(candidate[j].vote>max)){
          max=candidate[j].vote;
		  maxIndex=j;
	    }
	  }
	  if (max>(numBollot/2)) {  //過半
		cout << candidate[maxIndex].name<<endl;
		break;
	  }
	  for(int j=0;j<numCandidate;j++){ //找最少選票的個數
        if ((candidate[j].eliminate==false)&&(candidate[j].vote<min)){
          min=candidate[j].vote;
		  minIndex=j;
	    }
	  }
	  if (max==min) {//tie，剩餘候選人每個得票數相同
 	    for(int j=0;j<numCandidate;j++){ //輸出剩餘還未刪除的候選人
          if (candidate[j].eliminate==false){
            cout << candidate[j].name << endl;		    
	      }
	    }
		break;
	  }else{//有較少票數的候選人從選票中刪除
 	    for(int j=0;j<numCandidate;j++){ //找最少選票
          if ((candidate[j].eliminate==false)&&(candidate[j].vote==min)){
            elimMin(j+1);//選票編號與候選人陣列索引值差1	
			candidate[j].eliminate=true;
	      }		  
	    }        
	  }
	}
  }
}
