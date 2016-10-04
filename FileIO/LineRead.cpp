#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
  std::cout << "Please enter a line:\n";
  std::string s;
  getline(std::cin,s);
  std::cout << "You entered " << s << '\n';
  return EXIT_SUCCESS;
}