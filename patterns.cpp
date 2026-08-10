/*pattern 1:
***
***
***

pattern 2:
*
**
***

pattern 3:
***
**
*

pattern 4:
1
12
123

pattern 5:
1
22
333

pattern 6:
123
12
1

pattern 7:
  *      2space,1star,1space 
 ***     1space,3star,1space
*****    0space,5star,0space

pattern 8:
*****    0space,5star,0space
 ***     1space,3star,1space
  *      2space,1star,2space

pattern 9: combination of pattern 7 and pattern 8
  *
 ***
*****
*****
 ***
 *

pattern 10: even row start with 1 
1
01
101
0101
10101

pattern 11: 
1    1
12  21
123321

pattern 12:
1
23
456

pattern 13:
A
AB
ABC

pattern 14:
ABC
AB
A

pattern 15:
A
BB
CCC

pattern 16:
C
BC
ABC

pattern 17:
******
**  **
*    *
*    *
**  **
******

pattern 18:
***
* *
*** 

*/

#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern5(int n){
   for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern10(int n){
    int start;
   for(int i=0;i<n;i++){
       if(i%2==0) start=1;
       else start=0;
       for(int j=0;j<=i;j++){
           cout<<start;
           start=1-start;
       }
       cout<<endl;
   }
}

void pattern11(int n){
    int space=2*(n-1);
    for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++){
           cout<<j;
       }
       for(int j=1;j<=space;j++){
           cout<<" ";
       }
       for(int j=i;j>=1;j--){
           cout<<j;
       }
       space-=2;
       cout<<endl;
   }
}

void pattern12(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num;
            num++;
        }
        cout<<endl;
    }
}

void pattern13(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+n-i-1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for(int i=0;i<n;i++){
        char ch ='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void pattern16(int n){
    for(int i=0;i<n;i++){
        char ch ='A'+n-i-1;
        for(int j=0;j<=i;j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}

void pattern17(int n){
    int first_space=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<first_space;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        first_space+=2;
        cout<<endl;
    }
    
    int second_space = 2*n-4;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<second_space;j++){
            cout<<" ";
        }
        for(int j=i+1;j>=0;j--){
            cout<<"*";
        }
        cout<<endl;
        second_space-=2;
    }
}

void pattern18(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n=3;
  //pattern1(n);
  //pattern2(n);
  //pattern3(n);
  //pattern4(n);
  //pattern5(n);  
  //pattern6(n);
  //pattern7(n);
  //pattern8(n);
  //pattern9(n);
  //pattern10(n);
  //pattern11(n);
  //pattern12(n);
  //pattern13(n);
  //pattern14(n);
  //pattern15(n);
  //pattern16(n);
  pattern17(n);
  //pattern18(n);
  return 0;
}