#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

// Note: Compile with -pthread, since std::async() uses multithreading, otherwise runtime error.


// std::future allows you to write asynchronous code. In asynchronous programming, main thread doesn't wait for any task to finished, rather it hand over the task to workers and move on. One way of aynchronous processing is using callback methods. Future is another way to write asynchronous code.


int solveBigProblem(int input)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int answerAfterBigCalculation = 100*input;
    return answerAfterBigCalculation;
}


int main(int argc, char const *argv[])
{
    cout<<"Calling async function:"<<endl;
    std::future<int> answer = std::async(std::launch::async, solveBigProblem, 25);
    // In addition to the target function, std::async takes a launch policy which specifies whether to start a new thread or create a "deferred function" which is only run when you wait for it. They are represented by std::launch::async and std::launch::sync respectively. The default launch policy for std::async is std::launch::any, which means that the implementation gets to choose for you. If you really want to ensure that your function is run on its own thread then you need to specify the std::launch::async policy.
    // In most cases it makes sense to let the library choose. That way you'll avoid creating too many threads and overloading the machine, whilst taking advantage of the available hardware threads. If you need fine control, you're probably better off managing your own threads.
    cout<<"And the answer is: "<< answer.get()<<endl;
    return 0;
}