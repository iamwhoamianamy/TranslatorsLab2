#include <iostream>
#include <fstream>
#include "ConstTable.h"
#include "VarTable.h"

using namespace std;

int main()
{
   ConstTable alphbet, key_words, operators;
   VarTable var_table;

   alphbet.FillAplhabet();
   key_words.FillKeyWords();
   operators.FillOperators();

   ifstream fin("test_2.txt");
   ofstream fout("tokens.txt");

   char c;
   string word = "", letter;

   while(fin.get(c))
   {
      letter = c;

      if(word == "" || word == " " || word == "\n"|| word == "ъ" || word == "\t")
      {
         word = letter;
         continue;
      }

      // Если текущий символ - пробел или конец строки
      if(letter == " " || letter == "\n" || letter == "ъ" || letter == "\t")
      {
         int word_kw_i = key_words.GetRowIndex(ConstTableRow(word));

         // Если предыдущее слово - ключевое
         if(word_kw_i != -1)
            fout << "(10," << word_kw_i << ")";
         else
         {
            int word_op_i = operators.GetRowIndex(ConstTableRow(word));

            // Если предыдущее слово - оператор
            if(word_op_i != -1)
               fout << "(20," << word_op_i << ")";
            // Eсли предыдущее слово - идентификатор
            else
            {
               int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
               fout << "(30," << word_var_i << ")";
            }
         }
         word = "";

         if(letter == "\n")
            fout << endl;

         continue;
      }

      int letter_op_i = operators.GetRowIndex(ConstTableRow(letter));

      // Если текущий символ - оператор
      if(letter_op_i != -1)
      {
         int word_kw_i = key_words.GetRowIndex(ConstTableRow(word));

         // Если предыдущее слово - ключевое
         if(word_kw_i != -1)
         {
            fout << "(10," << word_kw_i << ")";
            word = letter;
         }
         else
         {
            int word_op_i = operators.GetRowIndex(ConstTableRow(word));

            // Если предыдущее слово - оператор
            if(word_op_i != -1)
            {
               if(letter == "=")
               {
                  if(word == "!")
                     word = "!=";
                  else if(word == "=")
                     word = "==";
                  else
                  {
                     fout << "(20," << word_op_i << ")";
                     word = letter;
                  }
               }
               else
               {
                  fout << "(20," << word_op_i << ")";
                  word = letter;
               }
            }
            // Eсли предыдущее слово - идентификатор
            else
            {
               int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
               fout << "(30," << word_var_i << ")";
               word = letter;
            }
         }

         continue;
      }

      // Если текущй символ - просто символ
      word = word + letter;
   }

   fout.close();
   fin.close();
}