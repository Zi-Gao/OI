#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int total = 0;
	//考虑小旗放置位置
	cout << "一. 考虑小旗放置位置："<< endl;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
		  	if(i != j){
		  		for(int k = 1; k <= 5; k++){
		  			if(i != k && j != k){
		  				total++;
		  				cout << total << ": ";
		  			  	for(int p = 1; p <= 3; p++){
		  			  		int m;
					  		if(p == 1) m = i;
					  		if(p == 2) m = j;
					  		if(p == 3) m = k;
					  	    if(m == 1) cout << "red ";
					  	    if(m == 2) cout << "orange ";
					  	    if(m == 3) cout << "yellow ";
					  	    if(m == 4) cout << "green ";
					  	    if(m == 5) cout << "blue ";					  	   
				  		} 					  
					  	cout << endl;
					  }
		  		}
		  	}
	    }
	}  	
	cout << "共计：" << total << endl << endl;
	
	//不考虑小旗放置位置
	cout << "二. 不考虑小旗放置位置："<< endl;
	total = 0;
	for(int i = 1; i <= 5; i++){
		for(int j = i + 1; j <= 5; j++){		  
		  	for(int k = j + 1; k <= 5; k++){		  			
  				total++;
  				cout << total << ": ";
  			  	for(int p = 1; p <= 3; p++){
  			  		int m;
			  		if(p == 1) m = i;
			  		if(p == 2) m = j;
			  		if(p == 3) m = k;
			  	    if(m == 1) cout << "red ";
			  	    if(m == 2) cout << "orange ";
			  	    if(m == 3) cout << "yellow ";
			  	    if(m == 4) cout << "green ";
			  	    if(m == 5) cout << "blue ";					  	   
		  		} 					  
			  	cout << endl;					  
		  	}		  	
	    }
	}  	
	cout << "共计：" << total << endl;
		
	return 0;
}
