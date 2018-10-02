#include <iostream>

int main(int ac, char *av[]) {
  if (ac == 1)
    return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl), 0;
  for (++av; *av; ++av) {
    for (char *s = *av; *s; ++s) *s = ::toupper(*s);
    std::cout << *av;
  }
  std::cout << std::endl;
  return 0;
}
