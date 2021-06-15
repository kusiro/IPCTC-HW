#include <stdlib.h>
#include <stdio.h>
typedef struct
{
  int index;
  char name[50];
  int grade;
} student;

student students[100005];

int compare(const void * a, const void * b){
  student sA = *(student*) a;
  student sB = *(student*) b;
  if(sA.grade != sB.grade){
    return sB.grade - sA.grade;
  } else {
    return sA.index - sB.index;
  }
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    students[i].index = i;
    scanf("%s %d", &students[i].name, &students[i].grade);
  }
  qsort(students, n, sizeof(student), compare);
  for(int i = 0; i < n; i++){
    printf("%s\n", students[i].name);
  }
}