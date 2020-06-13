// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void read_function(vector<string>& input, int& check)
{
	string copy_str;
	cout << "Введите функцию" << endl;
	cin >> copy_str;

	for (int i = 0; i < copy_str.size(); i++)
	{
		if ((copy_str[i] >= 'a' && copy_str[i] <= 'z') || copy_str[i] == '!' || copy_str[i] == '^' || copy_str[i] == 'v' || copy_str[i] == 'f' || copy_str[i] == '+' || copy_str[i] == '~' || copy_str[i] == '>' || copy_str[i] == '(' || copy_str[i] == ')' || copy_str[i] == '0' || copy_str[i] == '1') {}
		else
		{
			cout << "В строке присутствует некорректный символ." << endl;
			return;
		}
	}


	int open = 0;
	int end = 0;
	for (int i = 0; i < copy_str.size(); i++) {
		if (copy_str[i] == '(')open++;
		if (copy_str[i] == ')')end++;
	}
	if (open != end) {
		cout << "Неверный ввод. Количество открытых скобок, не совпадает с количеством закрытых." << endl;
		return;
	}


	if ((copy_str[0] >= 'a' && copy_str[0] <= 'z') || copy_str[0] == '1' || copy_str[0] == '0' || copy_str[0] == '!' || copy_str[0] == '(') {}
	else
	{
		cout << "Неверный ввод. Некорректное начало строки." << endl;
		return;
	}
	for (int i = 0; i < copy_str.size() - 1; i++) {
		if ((((copy_str[i] >= 'a' && copy_str[i] <= 'z') && copy_str[i] != 'v') || copy_str[i] == '1' || copy_str[i] == '0') && (((copy_str[i + 1] >= 'a' && copy_str[i + 1] <= 'z') && copy_str[i + 1] != 'v') || copy_str[i + 1] == '1' || copy_str[i + 1] == '0'))
		{
			cout << "Ошибка. Несколько операндов подряд." << endl;
			return;
		}

	}

	for (int i = 0; i < copy_str.size() - 1; i++) {
		if ((copy_str[i] == '!' || copy_str[i] == '^' || copy_str[i] == 'v' || copy_str[i] == '+' || copy_str[i] == '~' || copy_str[i] == '>') && (copy_str[i + 1] == '^' || copy_str[i + 1] == 'v' || copy_str[i + 1] == '+' || copy_str[i + 1] == '~' || copy_str[i + 1] == '>'))
		{
			cout << "Ошибка. Несколько опреаторов подряд." << endl;
			return;
		}

	}

	int last = copy_str.size() - 1;
	if (((copy_str[last] >= 'a' && copy_str[last] <= 'z') && copy_str[last] != 'v') || copy_str[last] == '1' || copy_str[last] == '0' || copy_str[last] == ')') {}
	else
	{
		cout << "Неверный ввод. Некорректный конец строки." << endl;
		return;
	}

	for (int i = 0; i < copy_str.size() - 1; i++) {
		if ((copy_str[i] == ')') && (((copy_str[i + 1] >= 'a' && copy_str[i + 1] <= 'z') && copy_str[i + 1] != 'v') || copy_str[i + 1] == '1' || copy_str[i + 1] == '0'))
		{
			cout << "Ошибка. После скобок присутствует операнд." << endl;
			return;
		}
	}

	for (int i = 0; i < copy_str.size() - 1; i++) {
		if ((copy_str[i + 1] == '(') && (((copy_str[i] >= 'a' && copy_str[i] <= 'z') && copy_str[i] != 'v') || copy_str[i] == '1' || copy_str[i] == '0'))
		{
			cout << "Ошибка. Перед скобками присутствует операнд." << endl;
			return;
		}

	}

	for (int i = 0; i < copy_str.size() - 1; i++) {
		if ((copy_str[i] == '(') && (copy_str[i + 1] == ')'))
		{
			cout << "Ошибка. Пустые скобки." << endl;
			return;
		}

	}

	///////////////////////////////
	input.push_back(copy_str);
	check++;

}

void countingsort(char* array, int size)
{
	char* sortingarray = new char[255];
	for (int i = 0; i < 255; i++)
		sortingarray[i] = 0;
	int temp;
	for (int i = 0; i < size; i++)
	{
		temp = array[i];
		sortingarray[temp]++;
	}
	int j = 0;
	char c;
	for (int i = 0; i < 127; i++)
		while (sortingarray[i] != 0)
		{
			c = i;
			array[j] = c;
			j++;
			sortingarray[i]--;
		}
}

void counting(string str, int* n)
{
	char* oldoldvalues = new char[100];
	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '!' && str[i] != '^' && str[i] != 'v' && str[i] != '+' && str[i] != '~' && str[i] != '>' && str[i] != '(' && str[i] != ')' && str[i] != '0' && str[i] != '1')
		{
			oldoldvalues[j] = str[i];
			j++;
		}
	}
	char* oldvalues = new char[j];
	for (int i = 0; i < j; i++)
		oldvalues[i] = oldoldvalues[i];
	countingsort(oldvalues, j);
	char c = '2';
	*n = 0;
	for (int i = 0; i < j; i++)
	{
		if (oldvalues[i] != c)
		{
			(*n)++;
			c = oldvalues[i];
		}
	}
}

void creating_values(string str, char* newvalues)
{
	char* oldoldvalues = new char[100];
	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '!' && str[i] != '^' && str[i] != 'v' && str[i] != '+' && str[i] != '~' && str[i] != '>' && str[i] != '(' && str[i] != ')' && str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != 'f' && str[i] != ',')
		{
			oldoldvalues[j] = str[i];
			j++;
		}
	}
	char* oldvalues = new char[j];
	for (int i = 0; i < j; i++)
		oldvalues[i] = oldoldvalues[i];
	countingsort(oldvalues, j);
	char c = '2';
	int n = 0;
	c = '2';
	int k = 0;
	for (int i = 0; i < j; i++)
	{
		if (oldvalues[i] != c)
		{
			newvalues[k] = oldvalues[i];
			k++;
			c = oldvalues[i];
		}
	}
}

void creating_values1(string str, char* newvalues)
{
	char* oldoldvalues = new char[100];
	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '!' && str[i] != '^' && str[i] != 'v' && str[i] != '+' && str[i] != '~' && str[i] != '>' && str[i] != '(' && str[i] != ')' && str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != 'f' && str[i] != ',' && str[i] != 'a' && str[i] != 'b')
		{
			oldoldvalues[j] = str[i];
			j++;
		}
	}
	char* oldvalues = new char[j];
	for (int i = 0; i < j; i++)
		oldvalues[i] = oldoldvalues[i];
	countingsort(oldvalues, j);
	char c = '2';
	int n = 0;
	c = '2';
	int k = 0;
	for (int i = 0; i < j; i++)
	{
		if (oldvalues[i] != c)
		{
			newvalues[k] = oldvalues[i];
			k++;
			c = oldvalues[i];
		}
	}
}

int calculating(int* values, string str, char* charvalues)
{
	char stack1[100];
	int stack_size1 = 0;
	int stack2[100];
	int stack_size2 = 0;
	int j = 0;
	int stackmark;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stack1[stack_size1] = '(';
			stack_size1++;
		}
		else if (str[i] == '!' || str[i] == '^' || str[i] == 'v' || str[i] == '+' || str[i] == '~' || str[i] == '>')
		{
			if (str[i] == '!')
			{
				if ((stack_size1 == 0) || (stack1[stack_size1 - 1] != '!'))
				{
					stack1[stack_size1] = '!';
					stack_size1++;
				}
				else
				{
					while ((stack_size1 > 0) && (stack1[stack_size1 - 1] == '!'))
					{
						if (stack2[stack_size2 - 1] == 1)
							stack2[stack_size2 - 1] = 0;
						else
							stack2[stack_size2 - 1] = 1;
						stack1[stack_size1 - 1] = '0';
						stack_size1--;
					}
					stack1[stack_size1] = '!';
					stack_size1++;
				}
			}
			else if (str[i] == '^')
			{
				if ((stack_size1 == 0) || ((stack1[stack_size1 - 1] != '!') && (stack1[stack_size1 - 1] != '^')))
				{
					stack1[stack_size1] = '^';
					stack_size1++;
				}
				else
				{
					while ((stack_size1 > 0) && ((stack1[stack_size1 - 1] == '!') || (stack1[stack_size1 - 1] == '^')))
					{
						if (stack1[stack_size1 - 1] == '!')
						{
							if (stack2[stack_size2 - 1] == 1)
								stack2[stack_size2 - 1] = 0;
							else
								stack2[stack_size2 - 1] = 1;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '^')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
					}
					stack1[stack_size1] = '^';
					stack_size1++;
				}
			}
			else if (str[i] == 'v')
			{
				if ((stack_size1 == 0) || ((stack1[stack_size1 - 1] != '!') && (stack1[stack_size1 - 1] != '^') && (stack1[stack_size1 - 1] != 'v')))
				{
					stack1[stack_size1] = 'v';
					stack_size1++;
				}
				else
				{
					while ((stack_size1 > 0) && ((stack1[stack_size1 - 1] == '!') || (stack1[stack_size1 - 1] == '^') || (stack1[stack_size1 - 1] == 'v')))
					{
						if (stack1[stack_size1 - 1] == '!')
						{
							if (stack2[stack_size2 - 1] == 1)
								stack2[stack_size2 - 1] = 0;
							else
								stack2[stack_size2 - 1] = 1;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '^')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == 'v')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 1;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
					}
					stack1[stack_size1] = 'v';
					stack_size1++;
				}
			}
			else if (str[i] == '+' || str[i] == '~')
			{
				if ((stack_size1 == 0) || ((stack1[stack_size1 - 1] != '!') && (stack1[stack_size1 - 1] != '^') && (stack1[stack_size1 - 1] != 'v') && (stack1[stack_size1 - 1] != '+') && (stack1[stack_size1 - 1] != '~')))
				{
					stack1[stack_size1] = str[i];
					stack_size1++;
				}
				else
				{
					while ((stack_size1 > 0) && ((stack1[stack_size1 - 1] == '!') || (stack1[stack_size1 - 1] == '^') || (stack1[stack_size1 - 1] == 'v') || (stack1[stack_size1 - 1] == '+') || (stack1[stack_size1 - 1] == '~')))
					{
						if (stack1[stack_size1 - 1] == '!')
						{
							if (stack2[stack_size2 - 1] == 1)
								stack2[stack_size2 - 1] = 0;
							else
								stack2[stack_size2 - 1] = 1;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '^')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == 'v')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 1;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '+')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 0;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '~')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 0)
								stack2[stack_size2 - 2] = 1;
							else if (stack2[stack_size2 - 2] == 1)
								stack2[stack_size2 - 2] = 0;
							else if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 1;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
					}
					stack1[stack_size1] = str[i];
					stack_size1++;
				}
			}
			else if (str[i] == '>')
			{
				if ((stack_size1 == 0) || ((stack1[stack_size1 - 1] != '!') && (stack1[stack_size1 - 1] != '^') && (stack1[stack_size1 - 1] != 'v') && (stack1[stack_size1 - 1] != '+') && (stack1[stack_size1 - 1] != '~') && (stack1[stack_size1 - 1] != '>')))
				{
					stack1[stack_size1] = str[i];
					stack_size1++;
				}
				else
				{
					while ((stack_size1 > 0) && ((stack1[stack_size1 - 1] == '!') || (stack1[stack_size1 - 1] == '^') || (stack1[stack_size1 - 1] == 'v') || (stack1[stack_size1 - 1] == '+') || (stack1[stack_size1 - 1] == '~') || (stack1[stack_size1 - 1] == '>')))
					{

						if (stack1[stack_size1 - 1] == '!')
						{
							if (stack2[stack_size2 - 1] == 1)
								stack2[stack_size2 - 1] = 0;
							else
								stack2[stack_size2 - 1] = 1;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '^')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == 'v')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 1;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '+')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 0;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '~')
						{
							stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
							if (stack2[stack_size2 - 2] == 0)
								stack2[stack_size2 - 2] = 1;
							else if (stack2[stack_size2 - 2] == 1)
								stack2[stack_size2 - 2] = 0;
							else if (stack2[stack_size2 - 2] == 2)
								stack2[stack_size2 - 2] = 1;
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
						else if (stack1[stack_size1 - 1] == '>')
						{
							if ((stack2[stack_size2 - 2] == 1) && (stack2[stack_size2 - 1] == 0))
								(stack2[stack_size2 - 2] = 0);
							else
								(stack2[stack_size2 - 2] = 1);
							stack2[stack_size2 - 1] = -1;
							stack_size2--;
							stack1[stack_size1 - 1] = '0';
							stack_size1--;
						}
					}
					stack1[stack_size1] = '>';
					stack_size1++;
				}
			}
		}
		else if (str[i] == ')')
		{
			while (stack1[stack_size1 - 1] != '(')
			{
				if (stack1[stack_size1 - 1] == '!')
				{
					if (stack2[stack_size2 - 1] == 1)
						stack2[stack_size2 - 1] = 0;
					else
						stack2[stack_size2 - 1] = 1;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
				else if (stack1[stack_size1 - 1] == '^')
				{
					stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
					stack2[stack_size2 - 1] = -1;
					stack_size2--;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
				else if (stack1[stack_size1 - 1] == 'v')
				{
					stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
					if (stack2[stack_size2 - 2] == 2)
						stack2[stack_size2 - 2] = 1;
					stack2[stack_size2 - 1] = -1;
					stack_size2--;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
				else if (stack1[stack_size1 - 1] == '+')
				{
					stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
					if (stack2[stack_size2 - 2] == 2)
						stack2[stack_size2 - 2] = 0;
					stack2[stack_size2 - 1] = -1;
					stack_size2--;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
				else if (stack1[stack_size1 - 1] == '~')
				{
					stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
					if (stack2[stack_size2 - 2] == 0)
						stack2[stack_size2 - 2] = 1;
					else if (stack2[stack_size2 - 2] == 1)
						stack2[stack_size2 - 2] = 0;
					else if (stack2[stack_size2 - 2] == 2)
						stack2[stack_size2 - 2] = 1;
					stack2[stack_size2 - 1] = -1;
					stack_size2--;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
				else if (stack1[stack_size1 - 1] == '>')
				{
					if ((stack2[stack_size2 - 2] == 1) && (stack2[stack_size2 - 1] == 0))
						(stack2[stack_size2 - 2] = 0);
					else
						(stack2[stack_size2 - 2] = 1);
					stack2[stack_size2 - 1] = -1;
					stack_size2--;
					stack1[stack_size1 - 1] = '0';
					stack_size1--;
				}
			}
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (str[i] == '1')
		{
			stack2[stack_size2] = 1;
			stack_size2++;
		}
		else if (str[i] == '0')
		{
			stack2[stack_size2] = 0;
			stack_size2++;
		}
		else
		{
			j = 0;
			while (charvalues[j] != str[i])
				j++;
			stack2[stack_size2] = values[j];
			stack_size2++;
		}
	}
	while (stack_size1 > 0)
	{
		if (stack1[stack_size1 - 1] == '!')
		{
			if (stack2[stack_size2 - 1] == 1)
				stack2[stack_size2 - 1] = 0;
			else
				stack2[stack_size2 - 1] = 1;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (stack1[stack_size1 - 1] == '^')
		{
			stack2[stack_size2 - 2] = stack2[stack_size2 - 2] * stack2[stack_size2 - 1];
			stack2[stack_size2 - 1] = -1;
			stack_size2--;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (stack1[stack_size1 - 1] == 'v')
		{
			stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
			if (stack2[stack_size2 - 2] == 2)
				stack2[stack_size2 - 2] = 1;
			stack2[stack_size2 - 1] = -1;
			stack_size2--;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (stack1[stack_size1 - 1] == '+')
		{
			stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
			if (stack2[stack_size2 - 2] == 2)
				stack2[stack_size2 - 2] = 0;
			stack2[stack_size2 - 1] = -1;
			stack_size2--;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (stack1[stack_size1 - 1] == '~')
		{
			stack2[stack_size2 - 2] = stack2[stack_size2 - 2] + stack2[stack_size2 - 1];
			if (stack2[stack_size2 - 2] == 0)
				stack2[stack_size2 - 2] = 1;
			else if (stack2[stack_size2 - 2] == 1)
				stack2[stack_size2 - 2] = 0;
			else if (stack2[stack_size2 - 2] == 2)
				stack2[stack_size2 - 2] = 1;
			stack2[stack_size2 - 1] = -1;
			stack_size2--;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
		else if (stack1[stack_size1 - 1] == '>')
		{
			if ((stack2[stack_size2 - 2] == 1) && (stack2[stack_size2 - 1] == 0))
				(stack2[stack_size2 - 2] = 0);
			else
				(stack2[stack_size2 - 2] = 1);
			stack2[stack_size2 - 1] = -1;
			stack_size2--;
			stack1[stack_size1 - 1] = '0';
			stack_size1--;
		}
	}
	if (stack2[0] == 0)
		return 0;
	else
		return 1;
}

void substitution(int* values, int* j, int n, string str, char* charvalues, int* result, int* resultnumb)
{
	(*j)++;
	for (int i = 0; i < 2; i++)
	{
		values[*j] = i;
		if ((n - (*j)) > 1)
			substitution(values, j, n, str, charvalues, result, resultnumb);
		else
		{
			result[*resultnumb] = calculating(values, str, charvalues);
			(*resultnumb)++;
		}
	}
	(*j)--;
}

void plus_one(int* values, int n)
{
	int state = 1;
	int i = n - 1;
	while (state == 1)
	{
		if (values[i] == 0)
		{
			values[i] = 1;
			state = 0;
		}
		else
		{
			values[i] = 0;
			i--;
		}
	}
}

void plus_subs(string* str)
{
	int state = 1;
	int i = (*str).length() - 1;
	while (state == 1)
	{
		if ((*str)[i] == '1')
		{
			(*str)[i] = '0';
			state = 0;
		}
		else if ((*str)[i] == '0')
		{
			(*str)[i] = 'a';
			state = 0;
		}
		else if ((*str)[i] == 'a')
		{
			(*str)[i] = 'b';
			state = 0;
		}
		else if ((*str)[i] == 'b')
		{
			(*str)[i] = 'A';
			state = 0;
		}
		else if ((*str)[i] == 'A')
		{
			(*str)[i] = 'B';
			state = 0;
		}
		else
		{
			(*str)[i] = '1';
			i--;
			if (i == -1)
				state = 0;
		}
	}
}


void minus_one(int* values, int n)
{
	int state = 1;
	int i = n - 1;
	while (state == 1)
	{
		if (values[i] == 1)
		{
			values[i] = 0;
			state = 0;
		}
		else
		{
			values[i] = 1;
			i--;
		}
	}
}

int for_c(int* values, int n)
{
	int j = 0;
	int k;
	int result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (values[i] == 1)
		{
			k = 1;
			for (int l = 0; l < j; l++)
				k = k * 2;
			result += k;
		}
		j++;
	}
	return result;
}
int for_c2(int* values, int n, int j)
{
	int result = 1;
	int i = 0;
	int k = j;
	int* between = new int[n];
	for (int l = 0; l < n; l++)
		between[l] = 0;
	i = n - 1;
	while (k > 0)
	{
		between[i] = k % 2;
		k = (k - (k % 2)) / 2;
		i--;
	}
	for (int l = 0; l < n; l++)
	{
		if (between[l] == 1)
			result *= values[l];
	}
	return result;
}

bool is_t0(string str)
{
	int result;
	int n;
	counting(str, &n);
	int* values = new int[n];
	for (int i = 0; i < n; i++)
		values[i] = 0;
	char* charvalues = new char[n];
	creating_values(str, charvalues);
	result = calculating(values, str, charvalues);
	if (result == 0)
		return true;
	else
		return false;
}

bool is_t1(string str)
{
	int result;
	int n;
	counting(str, &n);
	int* values = new int[n];
	for (int i = 0; i < n; i++)
		values[i] = 1;
	char* charvalues = new char[n];
	creating_values(str, charvalues);
	result = calculating(values, str, charvalues);
	if (result == 1)
		return true;
	else
		return false;
}

bool is_l(string str)
{
	int n = 0;
	counting(str, &n);
	char* newvalues = new char[n];
	creating_values(str, newvalues);
	int* values = new int[n];
	int m = 1;
	for (int i = 0; i < n; i++)
		m = m * 2;
	int* result = new int[m];
	int resultnumb = 0;
	int j = -1;
	substitution(values, &j, n, str, newvalues, result, &resultnumb);
	int* c = new int[m];
	for (int i = 0; i < m; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		values[i] = 0;
	for (int i = 0; i < m; i++)
	{
		c[i] = result[i];
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				c[i] = (c[i] - c[j] * for_c2(values, n, j)) % 2;
				if (c[i] < 0)
					c[i] += 2;
			}
		}
		plus_one(values, n);
	}
	for (int i = 0; i < m; i++)
	{
		if ((c[i] == 1) && (i != 0) && (i != 1) && (i != 2) && (i != 4) && (i != 8) && (i != 32) && (i != 64) && (i != 128))
			return false;
	}
	return true;
}

bool is_m_recurs(int* values, int n)
{
	if (n == 1)
		return true;
	int m = n / 2;
	int* values1 = new int[m];
	for (int i = 0; i < m; i++)
	{
		values1[i] = values[i];
	}
	int* values2 = new int[m];
	for (int i = 0; i < m; i++)
	{
		values2[i] = values[m + i];
	}
	if (((for_c(values1, m)) <= (for_c(values2, m))) && (is_m_recurs(values1, m) == true) && (is_m_recurs(values2, m) == true))
		return true;
	return false;
}

bool is_m(string str)
{
	int n = 0;
	counting(str, &n);
	char* newvalues = new char[n];
	creating_values(str, newvalues);
	int* values = new int[n];
	int m = 1;
	for (int i = 0; i < n; i++)
		m = m * 2;
	int* result = new int[m];
	int resultnumb = 0;
	int j = -1;
	substitution(values, &j, n, str, newvalues, result, &resultnumb);
	if (is_m_recurs(result, m) == true)
		return true;
	return false;
}

bool is_s(string str)
{
	int n = 0;
	counting(str, &n);
	char* newvalues = new char[n];
	creating_values(str, newvalues);
	int* values = new int[n];
	int m = 1;
	for (int i = 0; i < n; i++)
		m = m * 2;
	int* result = new int[m];
	int resultnumb = 0;
	int j = -1;
	substitution(values, &j, n, str, newvalues, result, &resultnumb);
	int* result1 = new int[m];
	for (int i = 0; i < m; i++)
		result1[i] = result[m - 1 - i];
	for (int i = 0; i < m; i++)
	{
		if (result1[i] == 0)
			result1[i] = 1;
		else
			result1[i] = 0;
	}
	for (int i = 0; i < m; i++)
		if (result[i] != result1[i])
			return false;
	return true;
}

bool cheking_post_theorem(vector<string>& input)
{
	char* classes = new char[5];
	for (int i = 0; i < 5; i++)
		classes[i] = '+';
	for (int i = 0; i < input.size(); i++)
	{
		if (is_t0(input[i]) == false)
			classes[0] = '-';
		if (is_t1(input[i]) == false)
			classes[1] = '-';
		if (is_l(input[i]) == false)
			classes[2] = '-';
		if (is_m(input[i]) == false)
			classes[3] = '-';
		if (is_s(input[i]) == false)
			classes[4] = '-';
	}
	for (int i = 0; i < 5; i++)
		if (classes[i] == '+')
			return false;
	return true;
}

int how_many_one(int* values, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
		if (values[i] == 1)
			j++;
	return j;
}

bool for_m(int* value1, int* value2, int n)
{
	for (int i = 0; i < n; i++)
		if (value1[i] == 1)
			if (value2[i] != 1)
				return false;
	return true;
}

void do_function(vector<string>& input)
{
	int i1, i2, i4, il, i6, i7, im, is0, is1, i8, i9, i11, i12, i13, i14, i15, i16, is10, is11, is20, is21, i17;
	i13 = -1;
	is10 = 0;
	is11 = 0;
	is20 = 0;
	is21 = 0;
	im = -1;
	i16 = 0;
	i14 = -1;
	i9 = -1;
	i4 = -1;
	i6 = -1;
	i1 = 0;
	i11 = -1;
	int n;
	char* newvalues = new char;
	int* values;
	int m;
	int* result;
	int resultnumb;
	int j;
	int* c;
	int l = 0;
	int check = 0;
	l = 0;
	i7 = -1;
	int* values1;
	int* valuesmin = new int[1];
	int* valuesmax = new int[1];
	valuesmin[0] = 0;
	valuesmax[0] = 0;
	i9 = -1;
	is0 = -1;
	is1 = -1;
	int n10;
	int n11;
	int n20;
	int n21;
	string const0, const1, otric, konunk, help, konunkhelp;
	for (int i = 0; i < input.size(); i++)
	{
		if ((is_t0(input[i]) == false) && (is_t1(input[i]) == true))
		{
			n = 0;
			counting(input[i], &n);
			if ((i11 < 0) || ((i11 > 0) && (n < i11)))
			{
				i11 = n;
				is1 = i;
			}
		}
	}
	if (is1 >= 0)
	{
		is11++;
		cout << "1=";
		const1 = "f";
		const1 += to_string(is1);
		const1 += "(";
		counting(input[is1], &i16);
		for (int i = 0; i < i16; i++)
		{
			const1 += "a";
			if ((i16 - i) > 1)
				const1 += ",";
		}
		const1 += ")";
		cout << const1 << "\n";
	}
	i11 = -1;
	for (int i = 0; i < input.size(); i++)
	{
		if ((is_t1(input[i]) == false) && (is_t0(input[i]) == true))
		{
			n = 0;
			counting(input[i], &n);
			if ((i11 < 0) || ((i11 > 0) && (n < i11)))
			{
				i11 = n;
				is0 = i;
			}
		}
	}
	i16 = 0;
	if (is0 >= 0)
	{
		is10++;
		cout << "0=";
		const0 = "f";
		const0 += to_string(is0);
		const0 += "(";
		counting(input[is0], &i16);
		for (int i = 0; i < i16; i++)
		{
			const0 += "a";
			if ((i16 - i) > 1)
				const0 += ",";
		}
		const0 += ")";
		cout << const0 << "\n";
	}
	if (im < 0)
	{
		i11 = -1;
		i16 = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if ((is_t1(input[i]) == false) && (is_t0(input[i]) == false))
			{
				n = 0;
				counting(input[i], &n);
				if ((i11 < 0) || ((i11 > 0) && (n < i11)))
				{
					i11 = n;
					im = i;
				}
			}
		}
		if (im >= 0)
		{
			cout << "!a=";
			otric = "f";
			otric += to_string(im);
			otric += "(";
			counting(input[im], &i16);
			for (int i = 0; i < i16; i++)
			{
				otric += "a";
				if ((i16 - i) > 1)
					otric += ",";
			}
			otric += ")";
			cout << otric << "\n";
		}
	}
	l = 0;
	if (im < 0)
	{
		while (l < input.size())
		{
			i1 = l;
			while ((i1 < input.size()) && (is_m(input[i1]) != false))
				i1++;
			if (i1 < input.size())
			{
				if (is_m(input[i1]) == false)
				{
					n = 0;
					counting(input[i1], &n);
					newvalues = new char[n];
					creating_values(input[i1], newvalues);
					values = new int[n];
					m = 1;
					for (int i = 0; i < n; i++)
						m = m * 2;
					result = new int[m];
					resultnumb = 0;
					j = -1;
					substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
					values1 = new int[n];
					for (int i3 = 0; i3 < (m - 1); i3++)
					{
						for (int i = 0; i < n; i++)
							values[i] = 0;
						for (int i = 0; i < i3; i++)
							plus_one(values, n);
						for (int i = 0; i < n; i++)
							values1[i] = values[i];
						plus_one(values1, n);
						for (int i = i3 + 1; i < m; i++)
						{
							if (for_m(values, values1, n) == true)
							{
								if (result[i3] > result[i])
								{
									if (((i9 < 0) || ((i9 > 0) && (n <= i9))) || (i7 > 0))
									{
										if (((n - (how_many_one(values1, n) - how_many_one(values, n))) <= i7) && (i7 >= 0) || (i7 < 0))
										{
											valuesmin = new int[n];
											valuesmax = new int[n];
											for (int i10 = 0; i10 < n; i10++)
											{
												valuesmin[i10] = values[i10];
												valuesmax[i10] = values1[i10];
											}
											i7 = n - (how_many_one(values1, n) - how_many_one(values, n));
											im = i1;
											i9 = n;
										}
									}
								}
							}
							plus_one(values1, n);
						}
					}
				}
			}
			l = i1;
			l++;
		}
		cout << "!a=";
		otric = "f";
		otric += to_string(im);
		otric += "(";
		for (int i = 0; i < i9; i++)
		{
			if (valuesmin[i] == valuesmax[i])
			{
				if (valuesmin[i] == 0)
					otric += const0;
				else
					otric += const1;
			}
			else
				otric += "a";
			if ((i9 - i) > 1)
				otric += ",";
		}
		otric += ")";
		cout << otric << "\n";
	}
	l = 0;
	i8 = -1;
	i12 = -1;
	values = new int[n];
	for (int i = 0; i < n; i++)
		values[i] = 1;
	if (is0 < 0)
	{
		while (l < input.size())
		{
			i1 = l;
			while ((i1 < input.size()) && (is_s(input[i1]) != false))
				i1++;
			if (i1 < input.size())
			{
				if (is_s(input[i1]) == false)
				{
					n = 0;
					counting(input[i1], &n);
					newvalues = new char[n];
					creating_values(input[i1], newvalues);
					values = new int[n];
					m = 1;
					for (int i = 0; i < n; i++)
						m = m * 2;
					result = new int[m];
					resultnumb = 0;
					j = -1;
					substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
					for (int i = 0; i < n; i++)
						values[i] = 1;
					for (int i = (m - 1); i >= (m / 2); i--)
					{
						if ((result[i] == result[m - 1 - i]) && (result[i] == 0))
							if ((i12 < 0) || ((i12 > 0) && (n <= i12)))
								if ((i8 < 0) || ((n - (how_many_one(values, n) <= i8)) && (i8 >= 0)))
								{
									i13 = m - 1 - i;
									i12 = n;
									i8 = n - how_many_one(values, n);
									is0 = i1;
								}
					}
				}
			}
			l = i1;
			l++;
		}
		if (is0 >= 0)
		{
			is20++;
			values = new int[n];
			for (int i = 0; i < n; i++)
				values[i] = 0;
			for (int i = 0; i < i13; i++)
				plus_one(values, n);
			n10 = n;
			cout << "0=";
			const0 = "f";
			const0 += to_string(is0);
			const0 += "(";
			for (int i = 0; i < i12; i++)
			{
				if (values[i] == 0)
					const0 += otric;
				else
					const0 += "a";
				if ((i12 - i) > 1)
					const0 += ",";
			}
			const0 += ")";
			cout << const0 << "\n";
		}
	}
	l = 0;
	i8 = -1;
	i12 = -1;
	if (is1 < 0)
	{
		while (l < input.size())
		{
			i1 = l;
			while ((i1 < input.size()) && (is_s(input[i1]) != false))
				i1++;
			if (i1 < input.size())
			{
				if (is_s(input[i1]) == false)
				{
					n = 0;
					counting(input[i1], &n);
					newvalues = new char[n];
					creating_values(input[i1], newvalues);
					values = new int[n];
					m = 1;
					for (int i = 0; i < n; i++)
						m = m * 2;
					result = new int[m];
					resultnumb = 0;
					j = -1;
					substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
					for (int i = 0; i < n; i++)
						values[i] = 1;
					values1 = new int[n];
					for (int i = 0; i < n; i++)
						values1[i] = 0;
					for (int i = (m - 1); i >= (m / 2); i--)
					{
						if ((result[i] == result[m - 1 - i]) && (result[i] == 1))
							if ((i12 < 0) || ((i12 > 0) && (n <= i12)))
								if ((i8 < 0) || ((n - (how_many_one(values, n) <= i8)) && (i8 >= 0)))
								{
									i13 = m - 1 - i;
									i8 = n - how_many_one(values, n);
									is1 = i1;
									i12 = n;
								}
					}
				}
			}
			l = i1;
			l++;
		}
		if (is1 >= 0)
		{
			is21++;
			values = new int[n];
			for (int i = 0; i < n; i++)
				values[i] = 0;
			for (int i = 0; i < i13; i++)
				plus_one(values, n);
			n11 = n;
			cout << "1=";
			const1 = "f";
			const1 += to_string(is1);
			const1 += "(";
			for (int i = 0; i < i12; i++)
			{
				if (values[i] == 0)
					const1 += otric;
				else
					const1 += "a";
				if ((i12 - i) > 1)
					const1 += ",";
			}
			const1 += ")";
			cout << const1 << "\n";
		}
	}
	if (is0 < 0)
	{
		cout << "0=";
		help = otric;
		for (int i = 0; i < help.length(); i++)
			if (help[i] == 'a')
				help[i] = '#';
		for (int i = 0; i < help.length(); i++)
			if (help[i] != '#')
				const0 += help[i];
			else
				const0 += const1;
		cout << const0 << "\n";
	}
	if (is1 < 0)
	{
		cout << "1=";
		help = otric;
		for (int i = 0; i < help.length(); i++)
			if (help[i] == 'a')
				help[i] = '#';
		for (int i = 0; i < help.length(); i++)
			if (help[i] != '#')
				const1 += help[i];
			else
				const1 += const0;
		cout << const1 << "\n";
	}
	l = 0;
	i9 = -1;
	vector<string> vars;
	vector<string> varsfuncks;
	char a, b;
	int* indexes;
	int iindexes;
	int newn;
	int newm;
	string forsub;
	string help2;
	int counter, newcounter;
	int state;
	int i;
	int acounter, bcounter;
	char symb;
	int iac;
	int ibc;
	while (l < input.size())
	{
		if (is_l(input[l]) == false)
		{
			n = 0;
			counting(input[l], &n);
			if (n > 2)
			{
				newvalues = new char[n];
				creating_values(input[l], newvalues);
				values = new int[n];
				m = 1;
				for (int i = 0; i < n; i++)
					m = m * 2;
				result = new int[m];
				resultnumb = 0;
				j = -1;
				substitution(values, &j, n, input[l], newvalues, result, &resultnumb);
				c = new int[m];
				for (int i = 0; i < m; i++)
					c[i] = 0;
				for (int i = 0; i < n; i++)
					values[i] = 0;
				for (int i = 0; i < m; i++)
				{
					c[i] = result[i];
					for (int j = 0; j < m; j++)
					{
						if (i != j)
						{
							c[i] = (c[i] - c[j] * for_c2(values, n, j)) % 2;
							if (c[i] < 0)
								c[i] += 2;
						}
					}
					plus_one(values, n);
				}
				for (int i = 0; i < n; i++)
					values[i] = 0;
				for (int i = 0; i < m; i++)
				{
					if ((c[i] == 1) && (how_many_one(values, n) >= 2))
					{
						iindexes = 0;
						indexes = new int[how_many_one(values, n)];
						for (int i = 0; i < n; i++)
							if (values[i] == 1)
							{
								indexes[iindexes] = i;
								iindexes++;
							}
						for (int ia = 0; ia < (how_many_one(values, n) - 1); ia++)
							for (int ib = ia + 1; ib < (how_many_one(values, n)); ib++)
							{
								a = newvalues[indexes[ia]];
								b = newvalues[indexes[ib]];
								acounter = indexes[ia];
								bcounter = indexes[ib];
								newn = n - 2;
								newm = 1;
								for (int i = 0; i < newn; i++)
									newm *= 4;
								for (int i = 0; i < newn; i++)
									forsub += '1';
								for (int i = 0; i < newm; i++)
								{
									help = input[l];
									newcounter = 0;
									while (newcounter < help.length())
									{
										if ((help[newcounter] != a) && (help[newcounter] != b) && (help[newcounter] != '(') && (help[newcounter] != ')') && (help[newcounter] != '!') && (help[newcounter] != '^') && (help[newcounter] != 'v') && (help[newcounter] != '+') && (help[newcounter] != '~') && (help[newcounter] != '>') && (help[newcounter] != '1') && (help[newcounter] != '0'))
										{
											counter = 0;
											while (help[newcounter] != newvalues[counter])
												counter++;
											if (counter >= acounter)
												counter--;
											if (counter >= bcounter)
												counter--;
											if (forsub[counter] == '1')
											{
												help[newcounter] = '1';
											}
											else if (forsub[counter] == '0')
											{
												help[newcounter] = '0';
											}
											else if (forsub[counter] == 'a')
											{
												help[newcounter] = a;
											}
											else if (forsub[counter] == 'b')
											{
												help[newcounter] = b;
											}
											else if (forsub[counter] == 'A')
											{
												help2.clear();
												for (int i = 0; i < newcounter; i++)
													help2 += help[i];
												help2 += '!';
												help2 += a;
												for (int i = newcounter + 1; i < help.length(); i++)
													help2 += help[i];
												help = help2;
											}
											else if (forsub[counter] == 'B')
											{
												help2.clear();
												for (int i = 0; i < newcounter; i++)
													help2 += help[i];
												help2 += '!';
												help2 += b;
												for (int i = newcounter + 1; i < help.length(); i++)
													help2 += help[i];
												help = help2;
											}
										}
										newcounter++;
									}
									vars.push_back(help);
									help2.clear();
									help2 = "f";
									help2 += to_string(l);
									help2 += "(";
									iac = 0;
									ibc = 0;
									for (int i = 0; i < n; i++)
									{
										if (newvalues[i] == a)
										{
											help2 += a;
											iac++;
										}
										else if (newvalues[i] == b)
										{
											ibc++;
											help2 += b;
										}
										else
										{
											if (forsub[i - iac - ibc] == '1')
												help2 += "1";
											else if (forsub[i - iac - ibc] == '0')
												help2 += "0";
											if (forsub[i - iac - ibc] == 'a')
												help2 += a;
											if (forsub[i - iac - ibc] == 'b')
												help2 += b;
											if (forsub[i - iac - ibc] == 'A')
											{
												help2 += "!";
												help2 += a;
											}
											if (forsub[i - iac - ibc] == 'B')
											{
												help2 += "!";
												help2 += b;
											}
										}
										if (n - i > 1)
											help2 += ',';
									}
									help2 += ')';
									varsfuncks.push_back(help2);
									plus_subs(&forsub);
								}
								forsub.clear();
							}
					}
					plus_one(values, n);
				}
			}
			else
			{
				vars.push_back(input[l]);
				help.clear();
				help += 'f';
				help += to_string(l);
				help += '(';
				n = 2;
				newvalues = new char[2];
				creating_values(input[l], newvalues);
				help += newvalues[0];
				help += ',';
				help += newvalues[1];
				help += ')';
				varsfuncks.push_back(help);
			}
		}
		l++;
	}
	n = 2;
	m = 4;
	for (int i = 0; i < vars.size(); i++)
	{
		l = 0;
		while (l < (vars[i].length() - 1))
		{
			if ((vars[i][l] == '!') && (vars[i][l + 1] == '!'))
			{
				help.clear();
				for (int j = 0; j < l; j++)
					help += vars[i][j];
				l++;
				l++;
				for (int j = l; j < vars[i].length(); j++)
					help += vars[i][j];
				vars[i] = help;
				l--;
			}
			l++;
		}
	}
	newvalues = new char[n];
	values = new int[n];
	result = new int[m];
	vector<string> konunks;
	vector<string> konunksfuncks;
	for (int i = 0; i < vars.size(); i++)
	{
		creating_values(vars[i], newvalues);
		resultnumb = 0;
		j = -1;
		substitution(values, &j, n, vars[i], newvalues, result, &resultnumb);
		if (result[0] == 0)
		{
			if (result[1] == 0)
			{
				if ((result[2] == 0) && (result[3] == 1))
				{
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						help += varsfuncks[i][l];
						l++;
					}
					konunksfuncks.push_back(help);
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						help += vars[i][l];
						l++;
					}
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 0))
				{
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
			}
			else if (result[1] == 1)
			{
				if ((result[2] == 0) && (result[3] == 0))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 1))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					varsfuncks[i] = help;
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					vars[i] = help;
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
			}
		}
		else if (result[0] == 1)
		{
			if (result[1] == 0)
			{
				if ((result[2] == 0) && (result[3] == 0))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					varsfuncks[i] = help;
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					vars[i] = help;
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 1))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
			}
			else if (result[1] == 1)
			{
				if ((result[2] == 0) && (result[3] == 1))
				{
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
				else if ((result[2] == 1) && (result[3] == 0))
				{
					help.clear();
					help += '!';
					help += varsfuncks[i];
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					help.clear();
					help += '!';
					help2 += '(';
					help += vars[i];
					help2 += ')';
					vars[i] = help;
					konunks.push_back(help);
				}
			}
		}
	}
	string helphelp;
	for (int i = 0; i < konunksfuncks.size(); i++)
		if (konunksfuncks[i][0] == '!')
		{
			helphelp.clear();
			for (int inewi = 1; inewi < konunksfuncks[i].length(); inewi++)
				helphelp += konunksfuncks[i][inewi];
			help.clear();
			help = otric;
			for (int i = 0; i < help.length(); i++)
				if (help[i] == 'a')
					help[i] = '#';
			help2.clear();
			for (int inewi = 0; inewi < help.length(); inewi++)
				if (help[inewi] == '#')
					help2 += helphelp;
				else
					help2 += help[inewi];
			konunksfuncks[i] = help2;
		}
	//for (int i = 0; i < konunksfuncks.size(); i++)
	//	cout << konunksfuncks[i] << "\n";
	for (int i = 0; i < konunksfuncks.size(); i++)
	{
		l = 0;
		help.clear();
		while (l < konunksfuncks[i].size())
		{
			if (((konunksfuncks[i][l] != '0') && (konunksfuncks[i][l] != '1')) || (konunksfuncks[i][l - 1] == 'f'))
				help += konunksfuncks[i][l];
			else if (konunksfuncks[i][l] == '0')
				help += const0;
			else if (konunksfuncks[i][l] == '1')
				help += const1;
			l++;
		}
		konunksfuncks[i] = help;
	}
	string help3;
	help2 = otric;
	for (int i = 0; i < help2.size(); i++)
		if (help2[i] == 'a')
			help2[i] = '#';
	for (int i = 0; i < konunksfuncks.size(); i++)
	{
		l = 0;
		help.clear();
		while (l < konunksfuncks[i].size())
		{
			if (konunksfuncks[i][l] != '!')
				help += konunksfuncks[i][l];
			else
			{
				help3 = help2;
				for (int inewi = 0; inewi < help3.size(); inewi++)
					if (help3[inewi] == '#')
						help3[inewi] = konunksfuncks[i][l + 1];
				help += help3;
				l++;
			}
			l++;
		}
		konunksfuncks[i] = help;
	}
	int f = -1;
	int f1;
	for (int i = 0; i < konunksfuncks.size(); i++)
	{
		f1 = 0;
		for (int inewi = 0; inewi < konunksfuncks[i].length(); inewi++)
			if (konunksfuncks[i][inewi] == 'f')
				f1++;
		if ((f < 0) || ((f > 0) && (f1 < f)))
		{
			f = f1;
			konunk = konunksfuncks[i];
		}
	}
	newvalues = new char[2];
	creating_values1(konunk, newvalues);
	for (int i = 0; i < konunk.length(); i++)
	{
		if (konunk[i] == newvalues[0])
			konunk[i] = 'a';
		if (konunk[i] == newvalues[1])
			konunk[i] = 'b';
	}
	cout << "a^b=" << konunk << "\n";
}

void punkt3(vector<string>& input)
{
	int current = 0;
	int i1, i2, i4, il, i6, i7, im, is0, is1, i8, i9, i11, i12, i13, i14, i15, i16, is10, is11, is20, is21;
	i13 = -1;
	is10 = 0;
	is11 = 0;
	is20 = 0;
	is21 = 0;
	im = -1;
	int* il12 = new int[2];
	i16 = 0;
	il12[0] = -1;
	il12[1] = -1;
	i14 = -1;
	i9 = -1;
	i4 = -1;
	i6 = -1;
	i1 = 0;
	i11 = -1;
	int n;
	char* newvalues;
	int* values;
	int m;
	int* result;
	int resultnumb;
	int j;
	int* c;
	int l = 0;
	int newl = 0;
	int check = 0;
	l = 0;
	i7 = -1;
	int* values1;
	int* valuesmin = new int[1];
	int* valuesmax = new int[1];
	valuesmin[0] = 0;
	valuesmax[0] = 0;
	i9 = -1;
	is0 = -1;
	is1 = -1;
	int* values10 = new int[1];
	values10[0] = 0;
	int* values11 = new int[1];
	values11[0] = 0;
	int n10;
	int n11;
	int* values20 = new int[1];
	values20[0] = 0;
	int* values21 = new int[1];
	values21[0] = 0;
	int n20;
	int n21;
	int i1check, i0check, iotrcheck, ipereb;
	int ib = 0;
	string const0, const1, otric, konunk, help, konunkhelp;
	vector<int> itwas;
	vector<string> konunkvars;
	int usl = 0;
	int usl2;
	int forusl = itwas.size();
	int* pows;
	int imcheck = 0;
	is0 = -1;
	is1 = -1;
	for (int i = 0; i < input.size(); i++)
	{
		if ((is_t0(input[i]) == false) && (is_t1(input[i]) == true))
		{
			n = 0;
			counting(input[i], &n);
			if ((i11 < 0) || ((i11 > 0) && (n < i11)))
			{
				i11 = n;
				is1 = i;
			}
		}
	}
	if (is1 >= 0)
	{
		is11++;
		cout << "Через данный набор можно выразить единицу:\n";
		cout << "1=";
		const1 = "f";
		const1 += to_string(is1);
		const1 += "(";
		counting(input[is1], &i16);
		for (int i = 0; i < i16; i++)
		{
			const1 += "a";
			if ((i16 - i) > 1)
				const1 += ",";
		}
		const1 += ")";
		cout << const1 << "\n";
	}
	i11 = -1;
	for (int i = 0; i < input.size(); i++)
	{
		if ((is_t1(input[i]) == false) && (is_t0(input[i]) == true))
		{
			n = 0;
			counting(input[i], &n);
			if ((i11 < 0) || ((i11 > 0) && (n < i11)))
			{
				i11 = n;
				is0 = i;
			}
		}
	}
	i16 = 0;
	if (is0 >= 0)
	{
		is10++;
		cout << "Через данный набор можно выразить ноль:\n";
		cout << "0=";
		const0 = "f";
		const0 += to_string(is0);
		const0 += "(";
		counting(input[is0], &i16);
		for (int i = 0; i < i16; i++)
		{
			const0 += "a";
			if ((i16 - i) > 1)
				const0 += ",";
		}
		const0 += ")";
		cout << const0 << "\n";
	}
	if (im < 0)
	{
		i11 = -1;
		i16 = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if ((is_t1(input[i]) == false) && (is_t0(input[i]) == false))
			{
				n = 0;
				counting(input[i], &n);
				if ((i11 < 0) || ((i11 > 0) && (n < i11)))
				{
					i11 = n;
					im = i;
				}
			}
		}
		if (im >= 0)
		{
			cout << "Через данный набор можно выразить отрицание:\n";
			cout << "!a=";
			otric = "f";
			otric += to_string(im);
			otric += "(";
			counting(input[im], &i16);
			for (int i = 0; i < i16; i++)
			{
				otric += "a";
				if ((i16 - i) > 1)
					otric += ",";
			}
			otric += ")";
			cout << otric << "\n";
		}
	}
	l = 0;
	int otrcheck;
	if (im < 0)
	{
		current = 0;
		while (current < input.size())
		{
			l = 0;
			i7 = -1;
			i9 = -1;
			usl2 = 0;
			while (l < input.size())
			{
				i1 = l;
				while ((i1 < input.size()) && (is_m(input[i1]) != false))
					i1++;
				if (i1 < input.size())
				{
					if (is_m(input[i1]) == false)
					{
						n = 0;
						counting(input[i1], &n);
						newvalues = new char[n];
						creating_values(input[i1], newvalues);
						values = new int[n];
						m = 1;
						for (int i = 0; i < n; i++)
							m = m * 2;
						result = new int[m];
						resultnumb = 0;
						j = -1;
						substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
						values1 = new int[n];
						for (int i3 = 0; i3 < (m - 1); i3++)
						{
							for (int i = 0; i < n; i++)
								values[i] = 0;
							for (int i = 0; i < i3; i++)
								plus_one(values, n);
							for (int i = 0; i < n; i++)
								values1[i] = values[i];
							plus_one(values1, n);
							for (int i = i3 + 1; i < m; i++)
							{
								if (for_m(values, values1, n) == true)
								{
									if (result[i3] > result[i])
									{
										if (((i9 < 0) || ((i9 > 0) && (n <= i9))) || (i7 > 0))
										{
											if (((n - (how_many_one(values1, n) - how_many_one(values, n))) <= i7) && (i7 >= 0) || (i7 < 0))
											{
												usl = 0;
												for (int i = 0; i < itwas.size(); i++)
													if (itwas[i] == i1)
														usl++;
												if (usl == 0)
												{
													valuesmin = new int[n];
													valuesmax = new int[n];
													for (int i10 = 0; i10 < n; i10++)
													{
														valuesmin[i10] = values[i10];
														valuesmax[i10] = values1[i10];
													}
													i7 = n - (how_many_one(values1, n) - how_many_one(values, n));
													im = i1;
													i9 = n;
												}
											}
										}
									}
								}
								plus_one(values1, n);
							}
						}
					}
				}
				l = i1;
				l++;
			}
			if (im >= 0)
			{
				usl2++;
				itwas.push_back(im);
				otrcheck = 0;
				for (int i = 0; i < i9; i++)
					if (valuesmin[i] == 0)
						otrcheck++;
				if ((otrcheck == 0) || (is0 >= 0))
				{
					otrcheck = 0;
					for (int i = 0; i < i9; i++)
						if (valuesmin[i] == 1)
							otrcheck++;
					if ((otrcheck == 0) || (is1 >= 0))
					{
						usl2 = -1;
						cout << "Через данный набор можно выразить отрицание:\n";
						cout << "!a=";
						otric = "f";
						otric += to_string(im);
						otric += "(";
						for (int i = 0; i < i9; i++)
						{
							if (valuesmin[i] == valuesmax[i])
							{
								if (valuesmin[i] == 0)
									otric += const0;
								else
									otric += const1;
							}
							else
								otric += "a";
							if ((i9 - i) > 1)
								otric += ",";
						}
						otric += ")";
						cout << otric << "\n";
					}
					else
						im = -1;
				}
				else
					im = -1;
			}
			if (usl2 == 0)
			{
				current++;
			}
			if (usl2 > 0)
			{
				current = 0;
			}
			if (usl2 < 0)
			{
				current = input.size();
			}
		}
	}
	l = 0;
	i8 = -1;
	i12 = -1;
	if (is0 < 0)
	{
		while (l < input.size())
		{
			i1 = l;
			while ((i1 < input.size()) && (is_s(input[i1]) != false))
				i1++;
			if (i1 < input.size())
			{
				if (is_s(input[i1]) == false)
				{
					n = 0;
					counting(input[i1], &n);
					newvalues = new char[n];
					creating_values(input[i1], newvalues);
					values = new int[n];
					m = 1;
					for (int i = 0; i < n; i++)
						m = m * 2;
					result = new int[m];
					resultnumb = 0;
					j = -1;
					substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
					for (int i = 0; i < n; i++)
						values[i] = 1;
					for (int i = (m - 1); i >= (m / 2); i--)
					{
						if ((result[i] == result[m - 1 - i]) && (result[i] == 0))
							if ((i12 < 0) || ((i12 > 0) && (n <= i12)))
								if ((i8 < 0) || ((n - (how_many_one(values, n) <= i8)) && (i8 >= 0)))
								{
									i13 = m - 1 - i;
									i12 = n;
									i8 = n - how_many_one(values, n);
									is0 = i1;
								}
					}
				}
			}
			l = i1;
			l++;
		}
		if (is0 >= 0)
		{
			is20++;
			values = new int[n];
			for (int i = 0; i < n; i++)
				values[i] = 0;
			for (int i = 0; i < i13; i++)
				plus_one(values, n);
			values10 = new int[n];
			for (int i = 0; i < n; i++)
				values10[i] = values[i];
			n10 = n;
			otrcheck = 0;
			for (int i = 0; i < n; i++)
				if (values[i] == 0)
					otrcheck++;
			if ((otrcheck == 0) || (im >= 0))
			{
				cout << "Через данный набор можно выразить ноль:\n";
				cout << "0=";
				const0 = "f";
				const0 += to_string(is0);
				const0 += "(";
				for (int i = 0; i < i12; i++)
				{
					if (values[i] == 0)
						const0 += otric;
					else
						const0 += "a";
					if ((i12 - i) > 1)
						const0 += ",";
				}
				const0 += ")";
				cout << const0 << "\n";
			}
			else
				is0 = -1;
		}
	}
	l = 0;
	i8 = -1;
	i12 = -1;
	if (is1 < 0)
	{
		while (l < input.size())
		{
			i1 = l;
			while ((i1 < input.size()) && (is_s(input[i1]) != false))
				i1++;
			if (i1 < input.size())
			{
				if (is_s(input[i1]) == false)
				{
					n = 0;
					counting(input[i1], &n);
					newvalues = new char[n];
					creating_values(input[i1], newvalues);
					values = new int[n];
					m = 1;
					for (int i = 0; i < n; i++)
						m = m * 2;
					result = new int[m];
					resultnumb = 0;
					j = -1;
					substitution(values, &j, n, input[i1], newvalues, result, &resultnumb);
					for (int i = 0; i < n; i++)
						values[i] = 1;
					values1 = new int[n];
					for (int i = 0; i < n; i++)
						values1[i] = 0;
					for (int i = (m - 1); i >= (m / 2); i--)
					{
						if ((result[i] == result[m - 1 - i]) && (result[i] == 1))
							if ((i12 < 0) || ((i12 > 0) && (n <= i12)))
								if ((i8 < 0) || ((n - (how_many_one(values, n) <= i8)) && (i8 >= 0)))
								{
									i13 = m - 1 - i;
									i8 = n - how_many_one(values, n);
									is1 = i1;
									i12 = n;
								}
					}
				}
			}
			l = i1;
			l++;
		}
		if (is1 >= 0)
		{
			is21++;
			values = new int[n];
			for (int i = 0; i < n; i++)
				values[i] = 0;
			for (int i = 0; i < i13; i++)
				plus_one(values, n);
			values11 = new int[n];
			for (int i = 0; i < n; i++)
				values11[i] = values[i];
			otrcheck = 0;
			for (int i = 0; i < n; i++)
				if (values[i] == 0)
					otrcheck++;
			if ((otrcheck == 0) || (im >= 0))
			{
				n11 = n;
				cout << "Через данный набор можно выразить единицу:\n";
				cout << "1=";
				const1 = "f";
				const1 += to_string(is1);
				const1 += "(";
				for (int i = 0; i < i12; i++)
				{
					if (values[i] == 0)
						const1 += otric;
					else
						const1 += "a";
					if ((i12 - i) > 1)
						const1 += ",";
				}
				const1 += ")";
				cout << const1 << "\n";
			}
			else
				is1 = -1;
		}
	}
	if ((is0 < 0) && (im >= 0) && (is1 >= 0))
	{
		cout << "Через данный набор можно выразить ноль:\n";
		cout << "0=";
		help = otric;
		for (int i = 0; i < help.length(); i++)
			if (help[i] == 'a')
				help[i] = '#';
		for (int i = 0; i < help.length(); i++)
			if (help[i] != '#')
				const0 += help[i];
			else
				const0 += const1;
		cout << const0 << "\n";
		is0 = is1;
	}
	if ((is1 < 0) && (im >= 0) && (is0 >= 0))
	{
		cout << "Через данный набор можно выразить единицу:\n";
		cout << "1=";
		help = otric;
		for (int i = 0; i < help.length(); i++)
			if (help[i] == 'a')
				help[i] = '#';
		for (int i = 0; i < help.length(); i++)
			if (help[i] != '#')
				const1 += help[i];
			else
				const1 += const0;
		cout << const1 << "\n";
		is1 = is0;
	}
	if (im < 0)
		cout << "Через данный набор нельзя выразить отрицание.\n";
	if (is0 < 0)
		cout << "Через данный набор нельзя выразить ноль.\n";
	if (is1 < 0)
		cout << "Через данный набор нельзя выразить единицу.\n";
	itwas.clear();
	current = 0;
	l = 0;
	i9 = -1;
	vector<string> vars;
	vector<string> varsfuncks;
	char a, b;
	int* indexes;
	int iindexes;
	int newn;
	int newm;
	string forsub;
	string help2;
	int counter, newcounter;
	int state;
	int i;
	int acounter, bcounter;
	char symb;
	int iac;
	int ibc;
	while (l < input.size())
	{
		if (is_l(input[l]) == false)
		{
			n = 0;
			counting(input[l], &n);
			if (n > 2)
			{
				newvalues = new char[n];
				creating_values(input[l], newvalues);
				values = new int[n];
				m = 1;
				for (int i = 0; i < n; i++)
					m = m * 2;
				result = new int[m];
				resultnumb = 0;
				j = -1;
				substitution(values, &j, n, input[l], newvalues, result, &resultnumb);
				c = new int[m];
				for (int i = 0; i < m; i++)
					c[i] = 0;
				for (int i = 0; i < n; i++)
					values[i] = 0;
				for (int i = 0; i < m; i++)
				{
					c[i] = result[i];
					for (int j = 0; j < m; j++)
					{
						if (i != j)
						{
							c[i] = (c[i] - c[j] * for_c2(values, n, j)) % 2;
							if (c[i] < 0)
								c[i] += 2;
						}
					}
					plus_one(values, n);
				}
				for (int i = 0; i < n; i++)
					values[i] = 0;
				for (int i = 0; i < m; i++)
				{
					if ((c[i] == 1) && (how_many_one(values, n) >= 2))
					{
						iindexes = 0;
						indexes = new int[how_many_one(values, n)];
						for (int i = 0; i < n; i++)
							if (values[i] == 1)
							{
								indexes[iindexes] = i;
								iindexes++;
							}
						for (int ia = 0; ia < (how_many_one(values, n) - 1); ia++)
							for (int ib = ia + 1; ib < (how_many_one(values, n)); ib++)
							{
								a = newvalues[indexes[ia]];
								b = newvalues[indexes[ib]];
								acounter = indexes[ia];
								bcounter = indexes[ib];
								newn = n - 2;
								newm = 1;
								for (int i = 0; i < newn; i++)
									newm *= 6;
								for (int i = 0; i < newn; i++)
									forsub += '1';
								for (int i = 0; i < newm; i++)
								{
									help = input[l];
									newcounter = 0;
									while (newcounter < help.length())
									{
										if ((help[newcounter] != a) && (help[newcounter] != b) && (help[newcounter] != '(') && (help[newcounter] != ')') && (help[newcounter] != '!') && (help[newcounter] != '^') && (help[newcounter] != 'v') && (help[newcounter] != '+') && (help[newcounter] != '~') && (help[newcounter] != '>') && (help[newcounter] != '1') && (help[newcounter] != '0'))
										{
											counter = 0;
											while (help[newcounter] != newvalues[counter])
												counter++;
											if (counter >= acounter)
												counter--;
											if (counter >= bcounter)
												counter--;
											if (forsub[counter] == '1')
											{
												help[newcounter] = '1';
											}
											else if (forsub[counter] == '0')
											{
												help[newcounter] = '0';
											}
											else if (forsub[counter] == 'a')
											{
												help[newcounter] = a;
											}
											else if (forsub[counter] == 'b')
											{
												help[newcounter] = b;
											}
											else if (forsub[counter] == 'A')
											{
												help2.clear();
												for (int i = 0; i < newcounter; i++)
													help2 += help[i];
												help2 += '!';
												help2 += a;
												for (int i = newcounter + 1; i < help.length(); i++)
													help2 += help[i];
												help = help2;
											}
											else if (forsub[counter] == 'B')
											{
												help2.clear();
												for (int i = 0; i < newcounter; i++)
													help2 += help[i];
												help2 += '!';
												help2 += b;
												for (int i = newcounter + 1; i < help.length(); i++)
													help2 += help[i];
												help = help2;
											}
										}
										newcounter++;
									}
									vars.push_back(help);
									help2.clear();
									help2 = "f";
									help2 += to_string(l);
									help2 += "(";
									iac = 0;
									ibc = 0;
									for (int i = 0; i < n; i++)
									{
										if (newvalues[i] == a)
										{
											help2 += a;
											iac++;
										}
										else if (newvalues[i] == b)
										{
											ibc++;
											help2 += b;
										}
										else
										{
											if (forsub[i - iac - ibc] == '1')
												help2 += "1";
											else if (forsub[i - iac - ibc] == '0')
												help2 += "0";
											if (forsub[i - iac - ibc] == 'a')
												help2 += a;
											if (forsub[i - iac - ibc] == 'b')
												help2 += b;
											if (forsub[i - iac - ibc] == 'A')
											{
												help2 += "!";
												help2 += a;
											}
											if (forsub[i - iac - ibc] == 'B')
											{
												help2 += "!";
												help2 += b;
											}
										}
										if (n - i > 1)
											help2 += ',';
									}
									help2 += ')';
									varsfuncks.push_back(help2);
									plus_subs(&forsub);
								}
								forsub.clear();
							}
					}
					plus_one(values, n);
				}
			}
			else
			{
				vars.push_back(input[l]);
				help.clear();
				help += 'f';
				help += to_string(l);
				help += '(';
				n = 2;
				newvalues = new char[2];
				creating_values(input[l], newvalues);
				help += newvalues[0];
				help += ',';
				help += newvalues[1];
				help += ')';
				varsfuncks.push_back(help);
			}
		}
		l++;
	}
	n = 2;
	m = 4;
	for (int i = 0; i < vars.size(); i++)
	{
		l = 0;
		while (l < (vars[i].length() - 1))
		{
			if ((vars[i][l] == '!') && (vars[i][l + 1] == '!'))
			{
				help.clear();
				for (int j = 0; j < l; j++)
					help += vars[i][j];
				l++;
				l++;
				for (int j = l; j < vars[i].length(); j++)
					help += vars[i][j];
				vars[i] = help;
				l--;
			}
			l++;
		}
	}
	newvalues = new char[n];
	values = new int[n];
	result = new int[m];
	vector<string> konunks;
	vector<string> konunksfuncks;
	for (int i = 0; i < vars.size(); i++)
	{
		creating_values(vars[i], newvalues);
		resultnumb = 0;
		j = -1;
		substitution(values, &j, n, vars[i], newvalues, result, &resultnumb);
		if (result[0] == 0)
		{
			if (result[1] == 0)
			{
				if ((result[2] == 0) && (result[3] == 1))
				{
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						help += varsfuncks[i][l];
						l++;
					}
					konunksfuncks.push_back(help);
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						help += vars[i][l];
						l++;
					}
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 0))
				{
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
			}
			else if (result[1] == 1)
			{
				if ((result[2] == 0) && (result[3] == 0))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 1))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					varsfuncks[i] = help;
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					vars[i] = help;
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
			}
		}
		else if (result[0] == 1)
		{
			if (result[1] == 0)
			{
				if ((result[2] == 0) && (result[3] == 0))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					varsfuncks[i] = help;
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					symb = newvalues[1];
					vars[i] = help;
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					vars[i] = help;
					konunks.push_back(help);
				}
				else if ((result[2] == 1) && (result[3] == 1))
				{
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[0];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
			}
			else if (result[1] == 1)
			{
				if ((result[2] == 0) && (result[3] == 1))
				{
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < varsfuncks[i].length())
					{
						if ((varsfuncks[i][l] != symb) && (varsfuncks[i][l] != '!'))
							help += varsfuncks[i][l];
						else if (varsfuncks[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (varsfuncks[i][l] == '!')
							if (varsfuncks[i][l + 1] != symb)
								help += varsfuncks[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += help;
					varsfuncks[i] = help2;
					konunksfuncks.push_back(help2);
					symb = newvalues[1];
					help.clear();
					l = 0;
					while (l < vars[i].length())
					{
						if ((vars[i][l] != symb) && (vars[i][l] != '!'))
							help += vars[i][l];
						else if (vars[i][l] == symb)
						{
							help += '!';
							help += symb;
						}
						else if (vars[i][l] == '!')
							if (vars[i][l + 1] != symb)
								help += vars[i][l];
							else
							{
								help += symb;
								l++;
							}
						l++;
					}
					help2.clear();
					help2 += '!';
					help2 += '(';
					help2 += help;
					help2 += ')';
					vars[i] = help2;
					konunks.push_back(help2);
				}
				else if ((result[2] == 1) && (result[3] == 0))
				{
					help.clear();
					help += '!';
					help += varsfuncks[i];
					varsfuncks[i] = help;
					konunksfuncks.push_back(help);
					help.clear();
					help += '!';
					help2 += '(';
					help += vars[i];
					help2 += ')';
					vars[i] = help;
					konunks.push_back(help);
				}
			}
		}
	}
	if (im >= 0)
	{
		string helphelp;
		for (int i = 0; i < konunksfuncks.size(); i++)
			if (konunksfuncks[i][0] == '!')
			{
				helphelp.clear();
				for (int inewi = 1; inewi < konunksfuncks[i].length(); inewi++)
					helphelp += konunksfuncks[i][inewi];
				help.clear();
				help = otric;
				for (int i = 0; i < help.length(); i++)
					if (help[i] == 'a')
						help[i] = '#';
				help2.clear();
				for (int inewi = 0; inewi < help.length(); inewi++)
					if (help[inewi] == '#')
						help2 += helphelp;
					else
						help2 += help[inewi];
				konunksfuncks[i] = help2;
			}
	}
	if (is1 >= 0)
	{
		for (int i = 0; i < konunksfuncks.size(); i++)
		{
			l = 0;
			help.clear();
			while (l < konunksfuncks[i].size())
			{
				if ((konunksfuncks[i][l] != '1') || (konunksfuncks[i][l - 1] == 'f'))
					help += konunksfuncks[i][l];
				else
					help += const1;
				l++;
			}
			konunksfuncks[i] = help;
		}
	}
	if (is0 >= 0)
	{
		for (int i = 0; i < konunksfuncks.size(); i++)
		{
			l = 0;
			help.clear();
			while (l < konunksfuncks[i].size())
			{
				if ((konunksfuncks[i][l] != '0') || (konunksfuncks[i][l - 1] == 'f'))
					help += konunksfuncks[i][l];
				else
					help += const0;
				l++;
			}
			konunksfuncks[i] = help;
		}
	}
	string help3;
	if (im >= 0)
	{
		help2 = otric;
		for (int i = 0; i < help2.size(); i++)
			if (help2[i] == 'a')
				help2[i] = '#';
		for (int i = 0; i < konunksfuncks.size(); i++)
		{
			l = 0;
			help.clear();
			while (l < konunksfuncks[i].size())
			{
				if (konunksfuncks[i][l] != '!')
					help += konunksfuncks[i][l];
				else
				{
					help3 = help2;
					for (int inewi = 0; inewi < help3.size(); inewi++)
						if (help3[inewi] == '#')
							help3[inewi] = konunksfuncks[i][l + 1];
					help += help3;
					l++;
				}
				l++;
			}
			konunksfuncks[i] = help;
		}
	}
	vector<string> konunksfuncksp3;
	for (int i = 0; i < konunksfuncks.size(); i++)
	{
		counter = 0;
		for (int inewi = 0; inewi < konunksfuncks[i].length(); inewi++)
			if ((konunksfuncks[i][inewi] == '!') || ((konunksfuncks[i][inewi] == '1') && (konunksfuncks[i][inewi - 1] != 'f')) || ((konunksfuncks[i][inewi] == '0') && (konunksfuncks[i][inewi - 1] != 'f')))
				counter++;
		if (counter == 0)
			konunksfuncksp3.push_back(konunksfuncks[i]);
	}
	if (konunksfuncksp3.size() == 0)
		cout << "Через данный набор невозможно выразить конъюнкцию.\n";
	else
	{
		int f = -1;
		int f1;
		for (int i = 0; i < konunksfuncksp3.size(); i++)
		{
			f1 = 0;
			for (int inewi = 0; inewi < konunksfuncksp3[i].length(); inewi++)
				if (konunksfuncksp3[i][inewi] == 'f')
					f1++;
			if ((f < 0) || ((f > 0) && (f1 < f)))
			{
				f = f1;
				konunk = konunksfuncksp3[i];
			}
		}
		newvalues = new char[2];
		creating_values1(konunk, newvalues);
		for (int i = 0; i < konunk.length(); i++)
		{
			if (konunk[i] == newvalues[0])
				konunk[i] = 'a';
			if (konunk[i] == newvalues[1])
				konunk[i] = 'b';
		}
		cout << "a^b=" << konunk << "\n";
	}
}

void info_to_console()
{
	cout << "Инструкция по вводу функции:" << endl;
	cout << "1. Выберите номер операции (1, 2, 3 или 4)." << endl;
	cout << "2. При выборе 1 - введите функцию." << endl;
	cout << "2.1. При вводе функции используйте только строчные буквы английского алфавита (кроме букв v, f)." << endl;
	cout << "2.2. Между каждыми переменными ставьте знак операции." << endl;
	cout << "2.3. Строка считывается без пробелов." << endl;
	cout << "3. После ввода функции, необходимо выбрать номер следующей операции." << endl << endl;
	cout << "Операции, используемые при вводе:" << endl << endl;
	cout << "! - отрицание " << "		" << "> - следование" << endl;
	cout << "^ - конъюнкция" << "		" << "~ - эквивалентность" << endl;
	cout << "v - дизъюнкция" << "		" << "+ - сложение по модулю два" << endl << endl;

}

void rand_gen()
{
	char* values = new char[10];
	values[0] = 'a';
	values[1] = 'b';
	values[2] = 'c';
	values[3] = 'd';
	values[4] = 'e';
	values[5] = 'i';
	values[6] = 'g';
	values[7] = 'h';
	values[8] = '1';
	values[9] = '0';
	char* operations = new char[10];
	operations[0] = '!';
	operations[1] = '^';
	operations[2] = 'v';
	operations[3] = '+';
	operations[4] = '~';
	operations[5] = '>';
	operations[6] = '(';
	operations[7] = ')';
	string str, help;
	vector<string> input;
	int n;
	int i;
	int bracketsmark;
	int otrmark;
	int l;
	int m = rand() % 10 + 1;
	for (int k = 0; k < m; k++)
	{
		str.clear();
		n = rand() % 15 + 1;
		bracketsmark = 0;
		for (int j = 0; j < n; j++)
		{
			if ((str.length() == 0) || (str[str.length() - 1] == operations[0]) || (str[str.length() - 1] == operations[1]) || (str[str.length() - 1] == operations[2]) || (str[str.length() - 1] == operations[3]) || (str[str.length() - 1] == operations[4]) || (str[str.length() - 1] == operations[5]) || (str[str.length() - 1] == operations[6]))
			{
				i = rand() % 12 + 0;
				if (i == 12)
					i = 11;
				if (i == 10)
					str += operations[0];
				else if (i == 11)
				{
					str += operations[6];
					bracketsmark++;
				}
				else
					str += values[i];
			}
			else
			{
				if (bracketsmark > 0)
					i = rand() % 6 + 1;
				else
					i = rand() % 5 + 1;
				if (i == 6)
				{
					str += operations[7];
					bracketsmark--;
				}
				else
					str += operations[i];
			}
		}
		if ((str[str.length() - 1] == operations[0]) || (str[str.length() - 1] == operations[1]) || (str[str.length() - 1] == operations[2]) || (str[str.length() - 1] == operations[3]) || (str[str.length() - 1] == operations[4]) || (str[str.length() - 1] == operations[5]))
		{
			i = rand() % 10 + 0;
			if (i < 9)
				str += values[i];
			else
			{
				str += operations[0];
				i = rand() % 9 + 0;
				str += values[i];
			}
		}
		while (bracketsmark > 0)
		{
			str += operations[7];
			bracketsmark--;
		}
		otrmark = 0;
		l = 0;
		while (l < (str.length() - 1))
		{
			if ((str[l] == '!') && (str[l + 1] == '!'))
			{
				help.clear();
				for (int j = 0; j < l; j++)
					help += str[j];
				l++;
				l++;
				for (int j = l; j < str.length(); j++)
					help += str[j];
				str = help;
				l--;
			}
			l++;
		}
		otrmark = 0;
		l = 0;
		while (l < (str.length() - 1))
		{
			if ((str[l] == '(') && (str[l + 1] == ')'))
			{
				help.clear();
				for (int j = 0; j < l; j++)
					help += str[j];
				l++;
				l++;
				for (int j = l; j < str.length(); j++)
					help += str[j];
				str = help;
				l--;
			}
			l++;
		}
		if ((str[str.length() - 1] == operations[0]) || (str[str.length() - 1] == operations[1]) || (str[str.length() - 1] == operations[2]) || (str[str.length() - 1] == operations[3]) || (str[str.length() - 1] == operations[4]) || (str[str.length() - 1] == operations[5]))
		{
			i = rand() % 10 + 0;
			if (i < 9)
				str += values[i];
			else
			{
				str += operations[0];
				i = rand() % 9 + 0;
				str += values[i];
			}
		}
		cout << str << "\n";
		input.push_back(str);
	}
	for (int i = 0; i < input.size(); i++)
	{
		if (i == 0) cout << endl;
		cout << "Проверка функции (" << input[i] << ") на принадлежность к классам замкнутости:" << endl;
		if (is_t0(input[i])) { cout << "T0 +     "; }
		else cout << "T0 -     ";
		if (is_t1(input[i])) { cout << "T1 +     "; }
		else cout << "T1 -     ";
		if (is_l(input[i])) { cout << "L +     "; }
		else cout << "L -     ";
		if (is_m(input[i])) { cout << "M +     "; }
		else cout << "M -     ";
		if (is_s(input[i])) { cout << "S +     "; }
		else cout << "S -     ";
		cout << endl << endl;
	}
	if (cheking_post_theorem(input) == true)
	{
		cout << "Данный набор удовлетворяет теореме Поста." << endl;
		do_function(input);
	}
	else {
		cout << "Данный набор не удовлетворяет теореме Поста." << endl;
		punkt3(input);
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<string> input;
	int activity;
	int check = 0;
	cout << "Добро поаловать." << endl << "Программа предназначена для выражения конъюнкции через конечный набор булевых функций." << endl;
	cout << "Введите номер желаемой функции:" << endl 
		<< "1. Добавить функцию в набор" << endl 
		<< "2. Обработать введенный набор" << endl 
		<< "3. Получить справку" << endl 
		<< "4. Проверка на случайно сгенерированном наборе." << endl;
	bool in_cickle = true;
	while (in_cickle)
	{
		cout << "Выберите пункт: ";
		cin >> activity;
		switch (activity)
		{
		case 1:
			check++;
			read_function(input, check);
			break;
		case 2:
			if (check == 0)
			{
				cout << "Набор пустой... Завершение программы.\n";
				system("pause");
				exit(0);
			}
			for (int i = 0; i < input.size(); i++)
			{
				if (i == 0) cout << endl;
				cout << "Проверка функции (" << input[i] << ") на принадлежность к классам замкнутости:" << endl;
				if (is_t0(input[i])) { cout << "T0 +     "; }
				else cout << "T0 -     ";
				if (is_t1(input[i])) { cout << "T1 +     "; }
				else cout << "T1 -     ";
				if (is_l(input[i])) { cout << "L +     "; }
				else cout << "L -     ";
				if (is_m(input[i])) { cout << "M +     "; }
				else cout << "M -     ";
				if (is_s(input[i])) { cout << "S +     "; }
				else cout << "S -     ";
				cout << endl << endl;
			}
			if (cheking_post_theorem(input) == true)
			{
				cout << "Данный набор удовлетворяет теореме Поста." << endl;
				do_function(input);
			}
			else {
				cout << "Данный набор не удовлетворяет теореме Поста." << endl;
				punkt3(input);
			}


			in_cickle = false;
			break;
		case 3:
			system("cls");
			info_to_console();
			system("pause");
			system("cls");
			cout << "Введите номер желаемой функции:" << endl 
				<< "1. Добавить функцию в набор" << endl 
				<< "2. Обработать введенный набор" << endl 
				<< "3. Получить справку" << endl 
				<< "4. Проверка на случайно сгенерированном наборе." << endl;
			break;
		case 4:
			rand_gen();
			break;
		default:
			cout << "Некорректный ввод, попробуйте еще раз" << endl;
		}
	}
	cout << endl;
	system("pause");
}

