cmake_minimum_required(VERSION 3.12)

add_executable(pony-run ex00/main.cpp ex00/Pony.cpp)
target_include_directories(pony-run PRIVATE ex00)

add_executable(free-me ex01/ex01.cpp)
target_include_directories(free-me PRIVATE ex01)

add_executable(plunk ex02/main.cpp ex02/Zombie.cpp ex02/ZombieEvent.cpp)
target_include_directories(plunk PRIVATE ex02)

add_executable(walk ex03/main.cpp ex03/Zombie.cpp ex03/ZombieHorde.cpp)
target_include_directories(walk PRIVATE ex03)

add_executable(ex04 ex04/ex04.cpp)
target_include_directories(ex04 PRIVATE ex04)

add_executable(ex05 ex05/main.cpp ex05/Brain.cpp ex05/Human.cpp)
target_include_directories(ex05 PRIVATE ex05)

add_executable(ex06 ex06/main.cpp ex06/Weapon.cpp ex06/HumanA.cpp ex06/HumanB.cpp)
target_include_directories(ex06 PRIVATE ex06)
