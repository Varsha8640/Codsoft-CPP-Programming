#include <iostream>
using namespace std;

int main() {
  char operation;
  double num1, num2;

  cout << "Enter first number: ";
  cin >> num1;

  cout << "Enter second number: ";
  cin >> num2;

  cout << "Enter operator (+, -, *, /): ";
  cin >> operation;

  switch (operation) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 << " - " << num2 <<