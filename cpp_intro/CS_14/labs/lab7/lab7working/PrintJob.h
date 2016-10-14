#ifndef __PRINTJOB_H
#define __PRINTJOB_H

using namespace std;

class PrintJob {
private:
  int priority;
  int jobNumber;
  int numPages;

public:
  PrintJob ( int setP, int setJ, int numP);
  int getPriority ( );
  int getJobNumber ( );
  int getPages ( );
  //You can add additional functions here
  void setPriority (int val);
  void setJobNumber (int val);
  void setPages (int val);
};
#endif
