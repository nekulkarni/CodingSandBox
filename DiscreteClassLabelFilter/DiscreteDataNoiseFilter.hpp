
#ifndef DISCRETE_DATA_NOISE_FILTER_HPP
#define DISCRETE_DATA_NOISE_FILTER_HPP


// The following filter can be used for to filter a stream of discrete (integer) data.
// For example, say {1, 1, 1, 2, 3, 2, 2, 3, 3, 3, 3, 3, 2, 2, 3, 2, 2, 2 } is your 
// input stream and your maximum expected noise frequency is 2, then you accept a 
// change only if it consistently stays for more than 2 times. Then your expected 
// filtered stream is {1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2 }. 

class DiscreteDataNoiseFilter
{

private:
    
    // parameters
    int mMaxExpectedNoiseSize;

    // state variables
    bool mIsFirstSample;
    int mCurFilteredValue;
    int mLastSeenSample;
    int mLastSeenSampleConsistencyCount;

public:

    DiscreteDataNoiseFilter()
    {
        setEstimatedNoise(0);
        reset();
    }

    // Resets the filter.
    // This should be called before a new stream of data

    void reset()
    {
        mIsFirstSample = true;
        mCurFilteredValue = 0;
        mLastSeenSample = -1;
        mLastSeenSampleConsistencyCount = 0;
    }


    // Sets the new estimated noise level

    void setEstimatedNoise(const int noiseSizeEstimate)
    {
        mMaxExpectedNoiseSize = noiseSizeEstimate;
    }

    
    // Filters the new incoming value and returns it

    int filter(const int newSample)
    {
        // First sample gets accepted as-is.

        if(mIsFirstSample || mMaxExpectedNoiseSize == 0)
        {
            mCurFilteredValue = newSample;
            mIsFirstSample = false;
            mLastSeenSample = newSample;
            mLastSeenSampleConsistencyCount = 1;
        }
        else
        {
            // Same as last sample, increment consistency

            if (newSample == mLastSeenSample)
            {
                ++mLastSeenSampleConsistencyCount;
            }
            // different sample, reset consistency
            else
            {
                mLastSeenSample = newSample;
                mLastSeenSampleConsistencyCount = 1;
            }

            // new value is consistent enough, accept it.

            if (mLastSeenSampleConsistencyCount > mMaxExpectedNoiseSize)
            {
                mCurFilteredValue = mLastSeenSample;
            }
        }

        return mCurFilteredValue;
    }

};


#endif /* DISCRETE_DATA_NOISE_FILTER_HPP */