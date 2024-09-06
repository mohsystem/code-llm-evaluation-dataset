#include <stdio.h>
char* is_integer(char * str);
void filter_list(void *[], int , int);
int main() {
   void *list1[] = { (void *)1, (void *)2, (void *)"a", (void *)"b"};
   void *list2[] = { (void *)1, (void *)"a", (void *)"b", (void *)0, (void *)15 };
   void *list3[] = { (void *)1, (void *)2, (void *)"a", (void *)"b", (void *)"aasf", (void *)"1", (void *)"123",  (void *)123};
   filter_list(list1, sizeof(list1)/sizeof(list1[0]), 'i');
   filter_list(list2, sizeof(list2)/sizeof(list2[0]), 'i');
   filter_list(list3, sizeof(list3)/sizeof(list3[0]), 'i');
   return 0;
}
void filter_list(void *list[], int sz, int ) {
   for (int i = 0; i < sz; i++) printf("%d ", ((int)(size_t)list[i] == (int)list[i]) ?  (int)(size_t)list[i]: NULL  );
   printf("\n");
}
char* is_integer(char *str){
   return (str[0] == '-' || str[0] == '+') &&str[1] != '\0';
}