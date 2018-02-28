/*
Daniel Pebbles
Lab 08
CPSC 2121 Section 002
3/16/2017
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//function that returns the priority of the parameter passed to it
int priority(string a)
{
    int temp;
    //multiplication and division have higher priority than + and -
    if(a == "*" || a=="/"){
	temp = 1;
    }

    else if(a=="+" || a=="-"){
	   temp = 2;
    }
    return temp;
}

//returns true if the string passed to it is an operator
bool isOperator(string token){
	if(token == "+" || token == "-" || token == "*" || token == "/"){
		return true;
	}
	else return false;
}

int main(int argc, char * argv[]){
	string token;	//string being read in
	vector<string> expression;	//vector that will hold the values and operators
	string infix = argv[1];		//sets infix as argv[1]
	stringstream ss(infix);		
	stack <string> o_stack;		//Stack for the operators
	stack<float> post;	//stack of floats for the postfix
	
	//while there are strings to get
	while( getline(ss, token, ' ') ){
		//if the token is an operator
		if(isOperator(token)){
			//while the stack isn't empty and priority of the top < token
			while(!o_stack.empty() && priority(o_stack.top()) <= priority(token)){
				//push the value end of the expression vector
				expression.push_back(o_stack.top());
				
				//pops operator
				o_stack.pop();
			}
			//pushes next token
			o_stack.push(token);
		}
	
		//if the token is a starting parenthesis
		else if(token == "("){
			//pushes parenthesis onto operator stack
			o_stack.push(token);
		}
		
		//if token is an ending parenthesis
		else if(token == ")"){
			//while inside current paranthesis
			while(o_stack.top() != "("){
				expression.push_back(o_stack.top());
				o_stack.pop();
			}
			o_stack.pop();

		}
		//else is a value
		else{
			expression.push_back(token);
		}

	}
	
	//while the stack isn't empty
	while(!o_stack.empty()){
		//if the top of the stack isn't a parenthesis
		if(o_stack.top() != ")" && o_stack.top() != "("){
			//push the value or operator onto the stack
			expression.push_back(o_stack.top());
		}
		//gets rid of the parenthesis
		o_stack.pop();
	}
	
	//prints all of the expressions
	cout << "Postfix Expression: ";
	for(unsigned n = 0; n < expression.size(); n++){
		cout << expression.at(n) << " ";
	}
	cout << endl;

	//for all of the expressions in the stack
	for(unsigned h = 0; h < expression.size(); h++){

		//if the string is not an operator
		if(expression[h] != "+" && expression[h] != "-" && expression[h] != "*" && expression[h] != "/"){
			string::size_type sz;	//size type of the string
			float value = stof(expression[h], &sz);		//string to float
			post.push(value);	//pushes the float to the top of the stack
		}
		
		//else it is an operator
		else{
			float operand1 = post.top();	//takes the top operator
			post.pop();	//pops the previously assigned operator
			float operand2 = post.top();	//takes the bottom operator
			post.pop();
			
			//if the next operator is multiplicaion
			if(expression[h] == "*"){post.push(operand1 * operand2);}
			//if the operator is division
			else if(expression[h] == "/"){post.push(operand2 / operand1);}
			//if the operator is addition
			else if(expression[h] == "+"){post.push(operand2 + operand1);}
			//if the operator is subtraction
			else if(expression[h] == "-"){post.push(operand2 - operand1);}
		}
	}
	//prints the only value left on the stack
	cout << "Postfix Evaluation: " << post.top() << endl;
	post.pop();

return 0;
}



