#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

class Key
{
public:
    int   mFrame;
    float mValue;

    // Double linked list for keys.  This is ok for simple animation.
    // If we need animation with a lot of keys, this should be changed
    // to a tree of keys.
    Key  *mPrev;
    Key  *mNext;

    Key(int frame, float value) :
        mFrame(frame),
        mValue(value),
        mPrev(NULL),
        mNext(NULL)
    {
    };
    
    void set(int frame, float value)
    {
        mFrame = frame;
        mValue = value;
    }

    void print() const
    {
        printf("fr %4.4d  val %g\n", mFrame, mValue);
    }
};

class Anim1d
{
public:

    Anim1d();
    ~Anim1d();

    void addKey(int frame, float value);
    void eraseKeys();
    void setFrame(int frame);
    void printAll();
    void evaluate() {/*dummy*/};


    float mValue;
    Key* mFirstKey;
    Key* mLastKey;
    int  mFrame;
    bool mNotFinished;
};

Anim1d::~Anim1d()
{
    eraseKeys();
}

Anim1d::Anim1d() :
    mValue(0.0f),
    mFirstKey(NULL),
    mLastKey(NULL),
    mFrame(0),
    mNotFinished(false)
{
}


void Anim1d::eraseKeys()
{
    while (mFirstKey != NULL)
    {
        Key* next = mFirstKey->mNext;
        delete mFirstKey;
        mFirstKey = next;
    }

    mLastKey = NULL;
    mNotFinished = false;
    mValue = 0.0f;
}



void Anim1d::addKey(int frame, float value)
{
    // if the list is empty

    if (mFirstKey == NULL)
    {
        mFirstKey = new Key(frame, value);
        mLastKey = mFirstKey;
        evaluate();
        return;
    }

    // if input key should go even before mFirstKey
    
    if (frame < mFirstKey->mFrame)
    {
        Key *key = new Key(frame, value);
        key->mPrev = NULL;
        key->mNext = mFirstKey;
        mFirstKey->mPrev = key;
        mFirstKey = key;
        evaluate();
        return;
    }

    // otherwise handle the general case

    Key *prev = mFirstKey;
    while (prev->mNext != NULL && prev->mNext->mFrame < frame)
    {
        prev = prev->mNext;
    }

    if (prev->mFrame == frame)
    {
        prev->set(frame, value);
        evaluate();
        return;
    }

    Key *key = new Key(frame, value);
    key->mPrev = prev;
    key->mNext = prev->mNext;
    if (prev->mNext != NULL)
        prev->mNext->mPrev = key;
    else
        mLastKey = key;
    prev->mNext = key;
    evaluate();
}



void Anim1d::printAll()
{
    Key* temp = mFirstKey;
    Key* expectedPrev = NULL;
    while(temp)
    {
        printf("%d\t%f\n",temp->mFrame, temp->mValue );
        assert(temp->mPrev == expectedPrev);

        expectedPrev = temp;
        temp = temp->mNext;

    }
}


int main(int argc, char const *argv[])
{
    Anim1d myAnim;
    for (int i = 1; i < argc; ++i)
    {
        int frm = atoi(argv[i]);
        myAnim.addKey(frm, (float)frm);

    }
    myAnim.printAll();
    return 0;
}