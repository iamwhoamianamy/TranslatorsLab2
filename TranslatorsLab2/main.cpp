#include <iostream>
#include <fstream>
#include "ConstTable.h"
#include "VarTable.h"

using namespace std;

int main()
{
   ConstTable alphbet, key_words, operators, numbers;
   VarTable var_table, const_table;

   alphbet.FillAplhabet();
   key_words.FillKeyWords();
   operators.FillOperators();
   numbers.FillNumbers();

   ifstream fin("test_2.txt");
   ofstream fout("tokens.txt");

   char c;
   string word = "", letter;
   bool is_word_number = false;

   while(fin.get(c))
   {
      letter = c;

      if(word == "" || word == " " || word == "\n"|| word == "ъ" || word == "\t")
      {
         int letter_numb_i = numbers.GetRowIndex(ConstTableRow(letter));

         // Если текущий символ - число
         if(letter_numb_i != -1)
            is_word_number = true;

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
               // Если идентификатор - константа
               if(is_word_number)
               {
                  int word_const_i = const_table.AddRow(VarTableRow(0, word, false));
                  fout << "(30," << word_const_i << ")";
                  is_word_number = false;
               }
               else
               {
                  int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
                  fout << "(30," << word_var_i << ")";
               }
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
               // Если идентификатор - константа
               if(is_word_number)
               {
                  int word_const_i = const_table.AddRow(VarTableRow(0, word, false));
                  fout << "(40," << word_const_i << ")";
                  word = letter;
                  is_word_number = false;
               }
               // Если идентификатор - имя
               else
               {
                  int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
                  fout << "(30," << word_var_i << ")";
                  word = letter;
               }
            }
         }

         continue;
      }

      // Если текущй символ - просто символ

      int letter_numb_i = numbers.GetRowIndex(ConstTableRow(letter));

      // Если текущий символ - число
      if(letter_numb_i != -1)
         is_word_number = true;

      word = word + letter;
   }

   fout.close();
   fin.close();

   alphbet.Output("aplhabet.txt");
   key_words.Output("keyWords.txt");
   operators.Output("operators.txt");
   numbers.Output("numbers.txt");
   var_table.Output("var.txt");
   const_table.Output("const.txt");
}