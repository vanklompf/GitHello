#include <thread>
#include <iostream>
#include <vector>
#include <random>
#include <cstdio>
#include <functional>
#include <mutex>
#include <algorithm>

#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


static const size_t TG_NUMBER = 1000000;
static const size_t TG_RANGE = 1000000;

struct talkgroup_t
{
    uint32_t ssi;
    char name[20];
};

std::vector<talkgroup_t> tg_database(TG_NUMBER);
std::mutex mutex;

void handler(int sig)
{
	void *array[10];
	size_t size;

	// get void*'s for all entries on the stack
	size = backtrace(array, 10);

	// print out all the frames to stderr
	printf("XXXX\n");
	fprintf(stderr, "Error: signal %d:\n", sig);
	backtrace_symbols_fd(array, size, STDERR_FILENO);
	exit(1);
}

void fill_tg_database()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, TG_RANGE);

    for (auto it = tg_database.begin(); it != tg_database.end(); ++it)
    {
    	it->ssi = distribution(generator);
    	std::sprintf(it->name, "TG: %d", it->ssi);
    }
}

void working_thread()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,TG_NUMBER);
	auto randomize_tg = std::bind( distribution, generator );

	while(true)
	{
		//mutex.lock();
		tg_database.at(randomize_tg()-1).ssi = 0xabcdef;
		//mutex.unlock();
	}
}

void checking_thread()
{
	int counter = 0;
	while (true)
	{
		counter++;
		auto it=tg_database.begin();
		for(; it!=tg_database.end(); ++it)
		{
			if (it->ssi != 0xabcdef)
			{
//				printf("break\n");
				break;
			}
		}

		if (it==tg_database.end())
		{
			printf("end: %d\n", counter);
			return;
		}
		printf("\r%d / %d", it-tg_database.begin(), TG_NUMBER);
	}

}

int main()
{
	signal(SIGSEGV, handler);
	fill_tg_database();

    std::vector<std::thread> worker_threads;
    for(int i = 0; i < 5; ++i)
    {
    	worker_threads.push_back(std::thread(working_thread));
    }
    std::thread checker_thread(checking_thread);
    checker_thread.join();

    std::for_each(worker_threads.begin(), worker_threads.end(),
      []
      (std::thread& thread)
      {
          thread.detach();
      });
    return 0;
}
