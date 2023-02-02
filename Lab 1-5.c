#include <stdio.h>

//Calculate the number of moves 
int calMoveNum(int n,int m){
  if(m>n){
    m = n;
  }
  if(m%2==0 || m==1){
    return m*2;
  }
  else{
    return m*2-1;
  }
}

void spiralOrder(int n,int m,int arr[n][m]){
  
  // Edge & Direction 
  //
  //        E1 ->
  //       ______
  //    ^  |    |  E2
  //    |  |    |  |
  //   E4  |    |  v
  //       ------
  //        <- E3
  
  // Initilize Edges Margin 
  int E1=0,E2=0,E3=0,E4=0;
  int limit = calMoveNum(n,m), t=0;
  while(1){
    //shift to the right (Along E1)
    if(t>=limit){break;}
    for(int j=E4;j<m-E2;j++){
      printf("%d ",arr[E1][j]);
    }
    E1++; 
    t++;
    
  
    //shift to the bottom (Along E2)
    if(t>=limit){break;}
    for(int i=E1;i<n-E3; i++){
      printf("%d ",arr[i][m-E2-1]);
    }
    E2++; 
    t++;
   

    //shift to the left (Along E3)
    if(t>=limit){break;}
    for(int j=m-E2-1; j>=E4; j--){
      printf("%d ",arr[n-E3-1][j]);
    }
    E3++; 
    t++;
    
  
    //shift to to the top (Along E4)
    if(t>=limit){break;}
    for(int i=n-E3-1; i>=E1; i--){
      printf("%d ",arr[i][E4]);
    }
    E4++; 
    t++;
    
 
  }

}

int main(void) {
  int n,m;
  scanf("%d %d",&n,&m);
  int nums[n][m];
  for(int i=0; i<n;i++){
    for(int j=0; j<m; j++){
      scanf("%d",&nums[i][j]);
    }
  }
  spiralOrder(n,m,nums);
  return 0;
}