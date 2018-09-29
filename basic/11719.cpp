#include <stdio.h>
using namespace std;

char c;
int main(){
    while((c=getchar())&&c!=EOF){
        printf("%c",c);
    }
    return 0;
}