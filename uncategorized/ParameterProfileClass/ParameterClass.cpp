//
//  AtheerTouchParameterProfile.hpp
//  AtheerTouch
//
//  Created by Neeraj Kulkarni on 07/10/15.
//  Copyright (c) 2015 Atheer Labs. All rights reserved.
//

#ifndef __AtheerTouch__AtheerTouchParameterProfile__
#define __AtheerTouch__AtheerTouchParameterProfile__

#include <stdio.h>
#include <stdlib.h>



class AtheerTouchParameterProfile
{


public:

    enum ParameterName {    DEPTH_CONTINUITY_PARAMETER,
                            DEPTHMAP_NOISE_BUFFER_OFFSET, 
                            
                            /* Add new parameters above this comment
                               block, before PARAMETERNAME_ENUM_COUNT.
                            */
                            PARAMETERNAME_ENUM_COUNT /* mandatory last, to know number */
                        };


    ~AtheerTouchParameterProfile() = default;
    AtheerTouchParameterProfile()
    {
        // Assign default values of parameters

        for (int i = 0; i < PARAMETERNAME_ENUM_COUNT; ++i)
        {
            mParamValues[i] = 0;
        }
    }

    void loadDefaultValues()
    {
        // Explicit default value assignement

        mParamValues[DEPTHMAP_NOISE_BUFFER_OFFSET] = 3;     // pixels
    }


    void setParam(enum ParameterName name, const float value)
    {
        mParamValues[name] = value;
    }


    float getParam(enum ParameterName name)
    {
        return mParamValues[name];
    }

    outputTemplateFile()

private:
    float mParamValues[PARAMETERNAME_ENUM_COUNT];
};


int main(int argc, char const *argv[])
{
    AtheerTouchParameterProfile myProfile;
    myProfile.setParam(AtheerTouchParameterProfile::DEPTH_CONTINUITY_PARAMETER, 0.04f);

    printf("depth continuity parameter: %.2f\n", myProfile.getParam(AtheerTouchParameterProfile::DEPTH_CONTINUITY_PARAMETER));
    printf("buffer offset parameter: %.2f\n", myProfile.getParam(AtheerTouchParameterProfile::DEPTHMAP_NOISE_BUFFER_OFFSET));
    return 0;
}


#endif // __AtheerTouch__AtheerTouchParameterProfile__