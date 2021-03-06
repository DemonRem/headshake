#ifndef GROUNDROLLCAMERACOMMAND_H
#define GROUNDROLLCAMERACOMMAND_H

#include <vector>

#include <CHeaders/XPLM/XPLMDataAccess.h>

#include "cameracommands/cameracommand.h"
#include "cameraposition.h"

class GroundRollCameraCommand : public CameraCommand
{
    public:
        /** Default constructor */
        GroundRollCameraCommand();
        /** Default destructor */
        virtual ~GroundRollCameraCommand();
        void execute(CameraPosition&);
        void accept(IVisitor&);
        /** Implementation methods */
        void set_response(float);
        float get_response();
    protected:
    private:
        std::vector<float> mPitchFilter;
        std::vector<float> mYawFilter;
        float mLastPitch;
        float mResponse;
        float mLastX;
        float mLastRoll;
        XPLMDataRef mGNormalDataRef;
        XPLMDataRef mOnGroundDataRef;
        XPLMDataRef mGSideDataRef;
};

#endif // GROUNDROLLCAMERACOMMAND_H
