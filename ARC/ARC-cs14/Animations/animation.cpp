#include "animation.h"

void Animator::animate() {
    vector<string> animation; //Each item should be a frame of the animation
    get_animation(animation);
    //Send the animation over one character at a time, encoding by multiplying 5
    // and subtracting 3 to each character
    //Don't forget to call hold between animation frames
}

void Animator::get_animation(vector<string> & animation) {
    ifstream fhand;
    int frame_lines, frames;
    
    switch(anim) {
        case Gymnast:
            fhand.open("gymnast.anim"); 
            frame_lines = 5, frames = 11;
            break;
        case Movie:
            fhand.open("movie.anim"); 
            frame_lines = 13, frames = 43;
            break;
        case Waving:
            fhand.open("waving.anim"); 
            frame_lines = 66, frames = 10;
            break;
        case Eyes:
            fhand.open("eyes.anim");
            frame_lines = 3; frames = 4;
    }
    
    //Read in frames number of frames, each having frame_lines number of lines
    //Don't forget to add newlines to the strings!
}

void Animator::hold() {
    switch(anim) {
        case Gymnast:
            usleep(250000); break;
        case Movie:
            usleep(75000); break;
        case Waving:
            usleep(200000); break;
        case Eyes:
            usleep(250000); break;
    }
}