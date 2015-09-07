#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

  struct{

    char c;
    int next[4];
}GRAPH[MAX*MAX];


int n = 5, esp, s[MAX*MAX], flag;
int renzoku[MAX*MAX], color[MAX*MAX];
int stack[10];
char ans[5] = {'M', 'E', 'N', 'M', 'A'};



int bfs(int start, int depth){
int i;

 color[start] = 1;
  for(i = 0; i < 4; i++){
    if(GRAPH[start].next[i] != -1 &&  GRAPH[GRAPH[start].next[i]].c == ans[depth+1] && color[GRAPH[start].next[i]] == 0){

        if(depth != 3){
         bfs(GRAPH[start].next[i], depth+1);
        }
        if(depth == 3){
         flag = 1;
        }

     }
     if(flag == 1){
      return 1;
     }
   }

  color[start] = 0;
  return 0;

}

int main(){
int count, count2, i = 0; char moji[100];

 scanf("%d", &n);

  for(count = 0; count < n*n; count++){
    GRAPH[count].next[0] = -1;
    GRAPH[count].next[1] = -1;
    GRAPH[count].next[2] = -1;
    GRAPH[count].next[3] = -1;
 }

 for(count = 0; count < n; count++){
  scanf("%s", moji);
  n = strlen(moji);
   for(count2 = 0; count2 < n; count2++){
      GRAPH[n*count+count2].c = moji[count2];
       if(moji[count2] == 'M'){
         s[i] = n*count+count2;
         i++;
       }
       if(count2 != 0)
         GRAPH[n*count+count2].next[0] = n*count + (count2-1);
       if(count != 0)
         GRAPH[n*count + count2].next[1] = n*(count - 1) + count2;
       if(count != n-1)
         GRAPH[n*count + count2].next[2] = n*(count+1)+count2;
       if(count2 != n-1)
         GRAPH[n*count + count2].next[3] = n*count + count2 + 1;

  }
  }

  for(count = 0; count < i; count++){
     if(bfs(s[count], 0)){
      printf("yes\n");
      break;
     }
  }
  if(count == i)
    printf("no\n");

 return 0;
}

