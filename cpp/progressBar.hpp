#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <iostream>

#include "lightWeightModular.hpp"

typedef unsigned int uint;

class ProgressBar
{
    private:
        int mBarWidth;
        uint mCharWidth;
        bool mClearOutputWhenComplete;
        std::ostream& mOutStream;
        int mProgress;
        int mProgressWhenComplete;
        LightWeightModular mSpinCharIndex;
        bool mStopped;
        
        static const char M_SPIN_CHARS[4];
        
        void ClearProgressBar();
        void WriteProgressBar();
    
    public:
        ProgressBar(
            std::ostream& outStream,
            int progressWhenComplete,
            uint charWidth,
            bool clearOutputWhenComplete);
        
        void AddProgress(int progressIncrement); // allowed to be negative
        void Start();
        void Stop(bool clearOutput);
};

#endif // PROGRESS_BAR_HPP
