#include <stdio.h>
#include <stdlib.h>
#include "boost/date_time/posix_time/posix_time.hpp"
// super slim test to check how fast structures can be transfered
// using plain C code

struct payload {
  int address;
  int length;
  char *data;
};

class memory
{
public:
  memory ()
  {
    printf ("constructing memory\n");
    sum = 0;
    m_memory = new char[0x10000];
  };
  ~memory ()
  {
    printf( "reached the following sum %d\n", sum );
  };
  void set_pl(payload* pl)
  {
    sum += pl->length;
    m_memory[pl->address] = *(pl->data);
    // printf( "got the following payload [%d %d %d]\n", pl->address, pl->length, sum );
  };
  unsigned long long int get_sum()
  {
    return sum;
  };
private:
  unsigned long long int sum;
  char *m_memory;
};

class init
{
public:
  init ()
  {
    printf ("constructing init\n");
    m_local_pl = new payload;
    m_local_pl->address = 0;
    m_local_pl->length  = 4;
    m_local_pl->data    = new char[m_local_pl->length];
  };
  ~init()
  {
    delete [] m_local_pl->data;
    delete m_local_pl;
  };
  payload* get_pl()
  {
    //m_local_pl->length  = rand() % 8;
    m_local_pl->length  = 4;
    m_local_pl->address = rand() % 0x10000;
    return m_local_pl;
  };
private:
  payload *m_local_pl;
};

int main (int argc, char *argv[])
{
  long long unsigned int NumberOfTransfers;
  long long unsigned int sum = 0;
  if (argc>1) {
    NumberOfTransfers = atoi(argv[1]);
  }
  else
    NumberOfTransfers = 1;

  init*   master = new init();
  memory* slave  = new memory();
  boost::posix_time::ptime  	sim_master_start_time, sim_master_end_time;
  sim_master_start_time = boost::posix_time::microsec_clock::universal_time();

  printf ("starting run for %d M transfers\n", NumberOfTransfers);
  for (unsigned long long i=0; i<NumberOfTransfers; ++i) {
    for (unsigned long long j=0; j<1000000; ++j) {
      slave->set_pl(master->get_pl());
      sum = slave->get_sum();
      //printf ("finished run %d transfers with sum %d\n", j, sum);
    };
    //printf ("finished run %d M transfers\n", i);
  };
  printf ("finished run for %d M transfers %d\n", NumberOfTransfers, sum);
  sim_master_end_time = boost::posix_time::microsec_clock::universal_time();
  boost::posix_time::time_duration master_elapsed_time = sim_master_end_time
    - sim_master_start_time;
  std::cout << "Total execution time is "
	    << boost::posix_time::to_simple_string(master_elapsed_time) << std::endl;

  delete master;
  delete slave;
  return 0;
}

