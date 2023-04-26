#include<fstream>
#include<time.h>
#include<string>
using std::string, std::ofstream;

void logtime(string filename){
    time_t current_time = time(NULL);
    char *dt = ctime(&current_time);
    ofstream fout(filename, std::ios::app);
    fout.write(dt, sizeof(dt));
    fout.close();
}

void logwindowname(string filename){
    
}