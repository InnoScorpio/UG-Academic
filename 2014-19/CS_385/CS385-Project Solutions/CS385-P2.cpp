#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;



char alphabet{ 'a', 'b' }
char stack_elements = {'A', 'B', 'Z'}

char stack;
int tape;
char input, pop, push;

void q0(char input, char pop, char push)
{

	if (input == b && pop == Z && push == B && push == Z)
		push(BZ);
	pop(Z);
	stack[3] = stack[i] + 1;

	else if (input b && pop == Z && push == A && push == Z)
		push(AZ);
	pop(Z);
	stack[2] = stack[i] + 1;
		
}

void q1(char input, char pop, char push)
{
	if (input == a && pop == A && push == A && push == A)
		push(A);
	push(A);
	pop(A);
	stack[1] = stack[i] + 1;
	else if (input == a && pop == B && push == Ep)
		pop(B);
	push(Ep);
	else if (input == b && pop == A && push == Ep)
		pop(A);
	push(Ep);
	else if (input == b && pop == B && push == B && push == B)
		pop(B);
	push(B); push(B);
	else if (input == Ep && pop == B && push == Ep)
		pop(B);
	push(Ep);
	stack[1] = stack[i] + 1;

	
}

void q2(char input, char pop, char push)
{
	if (input == Ep && pop == B && push == Ep)
		pop(B);

	else if (input == Ep && pop == Z && push == Z)
		pop(Z); push(Z);
	stack[0] = stack[i] + 1;

void Acc(q2)

{
		if (tape > state[3] = stack[0] + stack[1] + stack[2])
		stack[3] =
			stack[0] + stack[1] + stack[2];
		cout << tape << Stack[3] << "is accepted" << endl;
}

void Rej(q2)
{
	if (state[3] != stack[0] + stack[1] + stack[2])
		stack[3] =
		stack[0] + stack[1] + stack[2];
	cout << tape << Stack[3] << "is rejected" << endl;
}

int main()
{
	q0();
	q1();
	q2();
	Acc(q2);
	Rej(q2);
}
