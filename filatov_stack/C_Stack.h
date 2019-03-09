#pragma once

namespace stack
{
   template<class A>
   class node_t
   {
   public:
      node_t() : prev(nullptr) {}
      node_t(A val) : prev(nullptr), value(val) {}
      node_t(node_t<A>* p) : prev(p) {}
      node_t(A val, node_t<A>* p) : prev(p), value(val) {}

      node_t* prev;
      A value;
   };

   template<class T>
   class C_Stack
   {
   private:
      node_t<T>* pTop;
   public:
      C_Stack() : pTop(nullptr) {}
      ~C_Stack()
      {
         Clear();
      }

      void Push(T value)
      {
         node_t<T>* pTemp = new node_t<T>(value, pTop);
         pTop = pTemp;
      }

      T Pop()
      {
         node_t<T>* pTemp = pTop;
         T toRet;

         if (pTemp)
         {
            pTop = pTemp->prev;
            toRet = pTemp->value;

            delete pTemp;
         }
         else
         {
            toRet = (T)0;
         }

         return toRet;
      }

      bool IsEmpty()
      {
         return pTop == nullptr;
      }

      void Clear()
      {
         while (pTop)
         {
            Pop();
         }
      }

      void Reverse()
      {
         C_Stack<T> First;
         C_Stack<T> Second;

         while (!IsEmpty())
         {
            First.Push(Pop());
         }

         while (!First.IsEmpty())
         {
            Second.Push(First.Pop());
         }

         while (!Second.IsEmpty())
         {
            Push(Second.Pop());
         }
      }

      void HoareSort(bool(*compare)(T, T))
      {
         if (this->IsEmpty())
         {
            return;
         }

         T CenterValue = this->Pop();
         T TempValue;

         C_Stack<T> Right;
         C_Stack<T> Left;

         while (!this->IsEmpty())
         {
            TempValue = this->Pop();

            if (compare(TempValue, CenterValue))
            {
               Right.Push(TempValue);
            }
            else
            {
               Left.Push(TempValue);
            }
         }

         Right.HoareSort(compare);
         Left.HoareSort(compare);

         Right.Reverse();
         while (!Right.IsEmpty())
         {
            this->Push(Right.Pop());
         }

         this->Push(CenterValue);

         Left.Reverse();
         while (!Left.IsEmpty())
         {
            this->Push(Left.Pop());
         }
      }
   };
}