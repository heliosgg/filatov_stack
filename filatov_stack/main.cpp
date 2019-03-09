#include "IncludeSystem.h"

using namespace std;
using namespace stack;

int main()
{
   C_Stack<int>* st = new C_Stack<int>();

   srand(time(NULL));

   int temp;

   for (int i = 0; i < 20; i++)
   {
      temp = rand() % 20;
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