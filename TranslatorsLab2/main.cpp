#include <iostream>
#include <fstream>
#include "ConstTable.h"
#include "VarTable.h"
#include "LexicalAnalyzer.h"

using namespace std;

int main()
{
   LexicalAnalyzer la = LexicalAnalyzer();

   la.MakeTokens("test_2.txt", "tokens.txt");
   la.PrintAllTables("tables");

      //symbol_n++;

      //int symbol_alph_i = alphabet.GetRowIndex(ConstTableRow(symbol));

      //if (symbol_alph_i == -1 && symbol != " " && symbol != "\n" && symbol != "\t")
      //{
      //   cout << "Error in " << line_n << " line, " << symbol_n << " symbol!" << endl;
      //   exit(2);
      //}

      //if(word == "" || word == " " || word == "\n" || word == "\t")
      //{
      //   int symbol_numb_i = numbers.GetRowIndex(ConstTableRow(symbol));

      //   // Если текущий символ - число
      //   if(symbol_numb_i != -1)
      //      is_word_number = true;

      //   word = symbol;
      //   continue;
      //}

      //// Если текущий символ - пробел или конец строки
      //if(symbol == " " || symbol == "\n" || symbol == "\t")
      //{
      //   int word_kw_i = key_words.GetRowIndex(ConstTableRow(word));

      //   // Если предыдущее слово - ключевое
      //   if(word_kw_i != -1)
      //      fout << "(10," << word_kw_i << ")";
      //   else
      //   {
      //      int word_op_i = operators.GetRowIndex(ConstTableRow(word));

      //      // Если предыдущее слово - оператор
      //      if(word_op_i != -1)
      //         fout << "(20," << word_op_i << ")";
      //      // Eсли предыдущее слово - идентификатор
      //      else
      //      {
      //         // Если идентификатор - константа
      //         if(is_word_number)
      //         {
      //            int word_const_i = const_table.AddRow(VarTableRow(0, word, false));
      //            fout << "(30," << word_const_i << ")";
      //            is_word_number = false;
      //         }
      //         else
      //         {
      //            int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
      //            fout << "(30," << word_var_i << ")";
      //         }
      //      }
      //   }
      //   word = "";

      //   if(symbol == "\n")
      //   {
      //      line_n++;
      //      symbol_n = 0;
      //      fout << endl;
      //   }

      //   continue;
      //}

      //int symbol_op_i = operators.GetRowIndex(ConstTableRow(symbol));

      //// Если текущий символ - оператор
      //if(symbol_op_i != -1)
      //{
      //   int word_kw_i = key_words.GetRowIndex(ConstTableRow(word));

      //   // Если предыдущее слово - ключевое
      //   if(word_kw_i != -1)
      //   {
      //      fout << "(10," << word_kw_i << ")";
      //      word = symbol;
      //   }
      //   else
      //   {
      //      int word_op_i = operators.GetRowIndex(ConstTableRow(word));

      //      // Если предыдущее слово - оператор
      //      if(word_op_i != -1)
      //      {
      //         if(symbol == "=")
      //         {
      //            if(word == "!")
      //               word = "!=";
      //            else if(word == "=")
      //               word = "==";
      //            else
      //            {
      //               fout << "(20," << word_op_i << ")";
      //               word = symbol;
      //            }
      //         }
      //         else
      //         {
      //            fout << "(20," << word_op_i << ")";
      //            word = symbol;
      //         }
      //      }
      //      // Eсли предыдущее слово - идентификатор
      //      else
      //      {
      //         // Если идентификатор - константа
      //         if(is_word_number)
      //         {
      //            int word_const_i = const_table.AddRow(VarTableRow(0, word, false));
      //            fout << "(40," << word_const_i << ")";
      //            word = symbol;
      //            is_word_number = false;
      //         }
      //         // Если идентификатор - имя
      //         else
      //         {
      //            int word_var_i = var_table.AddRow(VarTableRow(0, word, false));
      //            fout << "(30," << word_var_i << ")";
      //            word = symbol;
      //         }
      //      }
      //   }

      //   continue;
      //}

      //// Если текущй символ - просто символ

      //int symbol_numb_i = numbers.GetRowIndex(ConstTableRow(symbol));

      //// Если текущий символ - число
      //if(symbol_numb_i != -1)
      //   is_word_number = true;

      //word = word + symbol;
}