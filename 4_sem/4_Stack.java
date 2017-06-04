// Infix to postfix conversion of expression

import java.util.*;
import java.util.Scanner;

public class Stack
{
	int size;
	char[] array;
	int top;
	static String infix;
	public Stack(int s)
	{
		size = s;
		array = new char[size];
		top = -1;
	}
	
	public void push (char a)
	{
		top++;
		array[top] = a;
	}

	public char pop ()
	{
		char temp = array[top];
		top--;
		return temp;
	}
	
	public char top ()
	{
		return array[top]; 
	}
	public boolean empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	public static void main(String[] args)
	{
		char affirm;
		do
		{
			Stack stack = new Stack(1000);
			Scanner scanner = new Scanner(System.in);
			System.out.print("\nEnter the infix string: ");
			infix = scanner.nextLine();
			int i;
			String postfix = "";
			char x, y;
			for (i = 0; i < infix.length(); i++)
			{
				x = infix.charAt(i);
				
				if (operand(x))
				{
					postfix += x;
				}
				
				else if (x == '(')
				{
			 		stack.push(x);
			 	}
			 	
			 	else if (x=='+'||x=='-'||x=='*'||x=='/')
			 	{
			 		while (!stack.empty() && (precedence(x) >= precedence(stack.top())))
			 		{
			 			y = stack.pop();
			 			if (y != '(')
			 			postfix += y;
			 		}
			 		stack.push(x);
			 	}
			 	
			 	else if (x == ')')
			 	{
			 		while (!stack.empty())
			 		{
			 			y = stack.pop();
						if (y == '(')
							break;
						else postfix += y;
					}
				}
			}
		
			while (!stack.empty())
			{
				y = stack.pop();
				postfix += y; 
			}
			System.out.println("Current postfix expression: " +postfix);
			System.out.print("\nDo you want to enter another expression? ");
			affirm = scanner.next().charAt(0);
		}
	while (affirm == 'y' || affirm == 'Y');
	}
	
	static public boolean operand(char d)
	{
		if ((d>='a'&&d<='z')||(d>='0'&&d<='9')||(d>='A'&&d<='Z'))
			return true;
		else
			return false;
	}

	static public int precedence(char o)
	{
		else if (o == '*' || o == '/')
			return 2;
		else if (o == '+' || o == '-')
			return 1;
		else
			return 0;
	}
}
