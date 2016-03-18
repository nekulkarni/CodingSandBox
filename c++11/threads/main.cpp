#include <iostream>
#include <exception>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::vector;


// Here, in this excercise, we create 40 threads which collaborate. For the sake of example, they collaborate trivially.

void cbFunc(int& acc, std::mutex& mx, int i)
{
    // std::cout<<"inside thread "<< i <<std::endl;
    mx.lock();
    acc = acc + i;
    mx.unlock();
}


int main(int argc, char const *argv[])
{
    try
    {
        vector<std::thread> myThreads;
        int accum = 0;
        std::mutex mx;

        // create 40 threads on cbFunc() with different integer input
        // to each thread send a reference of accumulator and mutex variables

        for (int i = 0; i < 40; ++i)
        {
            myThreads.push_back(std::thread(cbFunc, std::ref(accum), std::ref(mx), i));
        }
        
        for (int i = 0; i < myThreads.size(); ++i)
        {
            myThreads[i].join();
            // cout << "thread " << i << "joined." << endl;
        }

        cout /*<< "Resulting accumulator: " */<< accum << endl;
    }
    catch(exception& e)
    {
        cout << "exception: " << e.what() << endl;
    }
    return 0;
}