#ifndef __ANIMATION__
#define __ANIMATION__

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

enum Animation {Gymnast, Movie, Waving, Eyes};

class Animator {
    public:
        //The class will push to display so main can pop and cout
        //Should really be encapsulated, but for the sake of Q practice...
        queue<long long int> display;
        Animator(Animation anim) : anim(anim) { }
        void animate(); //Infinite loop populating display
        void clear_screen() { system("clear"); } //Call the linux clear screen
    private:
        Animation anim;
        void hold(); //Wait for some time depending on the animation
        void get_animation(vector<string> &); //Pull animation from file into vector
};

#endif //__ANIMATION__
