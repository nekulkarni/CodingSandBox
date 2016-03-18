#include <iostream>
#include <vector>
#include <functional>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

// This example implements the Observer design pattern.

class AbstractMessageListener
{
public:
    virtual void onNewMessage(const string& message) = 0;
};


class MessageBroadcaster
{
private:
    vector<AbstractMessageListener*> mListeners;
public:
    MessageBroadcaster() {}
    void registerNewListener(AbstractMessageListener* newListener)
    {
        if (newListener)
        {
            mListeners.push_back(newListener);
            cout<<"New listener added."<<endl;
        }
    }

    void broadcastMessage(string message)
    {
        for(auto ptr : mListeners) {
            ptr->onNewMessage(message);
        }
    }   
};


class MyListener : public AbstractMessageListener
{
private:
     string mName;
public:
    MyListener(const string& _name) : mName(_name) {}
    virtual void onNewMessage(const string& message)
    {
        cout<<"MyListener '"<< mName <<"' received and processed message: "<< message<<endl;
    }
};




int main(int argc, char const *argv[])
{
    MessageBroadcaster broadcaster;
    MyListener listener0("Aai"), listener1("Baba"), listener2("Amri");

    broadcaster.registerNewListener(&listener0);
    broadcaster.registerNewListener(&listener1);
    broadcaster.registerNewListener(&listener2);

    broadcaster.broadcastMessage("Me Alo!!");

    return 0;
}