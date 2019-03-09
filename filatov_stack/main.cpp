#include "IncludeSystem.h"

using namespace std;
using namespace stack;

#define N 20

int main()
{
   C_Stack<int>* st = new C_Stack<int>();

   srand(time(NULL));

   int temp;

   for (int i = 0; i < N; i++)
   {
      temp = rand() % N;
      cout << temp << " ";

      st->Push(temp);
   }
   cout << endl;

   st->HoareSort([](int a, int b) -> bool {return a > b; });

   while (!st->IsEmpty())
   {
      cout << st->Pop() << " ";
   }
   cout << endl;

   delete st;

   return 0;
}