#pragma once
#include <vector>
#include <string>
#include "VarTableRow.h"

using namespace std;

class VarTable
{
public:
   vector<VarTableRow> table;

   // �������� ������ �������
   VarTable()
   {
      table = vector<VarTableRow>(0);
   }

   // ������� ������ ������ ������ ������� �� ��������������,
   // ��������� -1 � ������ ���������� ������ � ����� ��������������� � �������
   int GetRowIndex(const VarTableRow& t_row)
   {
      for(size_t i = 0; i < table.size(); i++)
         if(table[i] == t_row)
            return i;

      return -1;
   }

   // ������� ���������� ������ � �������, ���� ������ ��������� ���,
   // ���������� ����� ������
   int AddRow(const VarTableRow& t_row)
   {
      int index = GetRowIndex(t_row);
      if(index == -1)
      {
         table.push_back(t_row);
         return table.size();
      }
      else
         return index;
   }

   // �������, ������������ 
   VarTableRow GetRow(const int& t_index)
   {
      if(t_index < table.size())
         return table[t_index];
      else
         printf_s("Error!");
   }

   // ��������� �������� ���������
   int    GetValue(const int& t_index) { return table[t_index].value; }
   string GetName(const int& t_index)  { return table[t_index].name; }
   bool   GetIsSet(const int& t_index) { return table[t_index].is_set; }

   // ������������ �������� ���������
   void SetValue(const int& t_index, const int& t_value)   { table[t_index].value = t_value; }
   void SetName(const int& t_index, const string& t_name)  { table[t_index].name = t_name; }
   void SetIsSet(const int& t_index, const bool t_is_set) { table[t_index].is_set = t_is_set; }
};