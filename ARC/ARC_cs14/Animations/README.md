How to get the code
------------------

In your C9 terminal, run:

    git clone https://github.com/scohe001/Animations

How to compile
--------------

Since we're using C++11 features and threading to make the animation possible,
you'll have to compile with the following flags:

    g++ -std=c++11 -pthread -Wall main.cpp animation.o
    
To compile solely the animation class, use:

    g++ -std=c++11 -pthread -c animation.cpp