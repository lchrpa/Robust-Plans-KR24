CC=g++-11
FLAGS=-Wall -Wextra -pedantic -pthread -std=gnu++17 -O3
INCLUDE=-Iinclude/ -I SAS/include/

default:
	$(CC) $(FLAGS) $(INCLUDE) -o robust_plans main.cpp utility.cpp downward_driver.cpp RPG.cpp DTG.cpp relax.cpp SAS/src/*.cpp
