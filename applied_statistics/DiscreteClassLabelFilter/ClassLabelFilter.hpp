
#ifndef CLASS_LABEL_FILTER_HPP
#define CLASS_LABEL_FILTER_HPP


// The Class Label Filter module is controlled through two parameters: 
// the minimum count value and buffer size value. The minimum count
// sets the minimum number of class label values that must be present
// in the class labels buffer for that class label value to be output
// by the Class Label Filter. The size of the class labels buffer is
// set by the buffer size parameter. If there is more than one type of
// class label in the buffer then the class label with the maximum
// number of instances will be output. If the maximum number of
// instances for any class label in the buffer is less than the minimum
// count parameter then the Class Label Filter will output the default
// null rejection class label.

class ClassLabelFilter
{

private:
    
    int *mBuffer;
    int mBufferSize;
    int mMinimumCount;
    int mNullClassVal;


public:

    ClassLabelFilter()
    {
        mBufferSize = 0;
        mMinimumCount = 0;
        mBuffer = NULL;
    }

    ClassLabelFilter(const int _size, const int _minCount, const int noClassVal)
    {
        if (_size <= 0)
        {
            return;
        }

        mBufferSize = _size;
        mMinimumCount = _minCount;
        mBuffer = new int [mBufferSize];
        for (int i = 0; i < mBufferSize; ++i)
        {
            mBuffer[i] = noClassVal;
        }
    }


    // Resets the filter.
    // This should be called before a new stream of data

    void reset(const int resetVal)
    {
        for (int i = 0; i < mBufferSize; ++i)
        {
            mBuffer[i] = resetVal;
        }
    }


    void setMinimumCount(const int _minCount)
    {
        mMinimumCount = _minCount;
    }

    
    // Filters the new incoming value and returns it

    int filter(const int predictedClass)
    {

    }

};


#endif /* CLASS_LABEL_FILTER_HPP */