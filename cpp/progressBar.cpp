#include <cassert>
#include <cmath>
#include <iomanip>
#include "progressBar.hpp"

const char ProgressBar::M_SPIN_CHARS[4] = {'/', '-', '\\', '|'};

ProgressBar::ProgressBar(
    std::ostream& outStream,
    int progressWhenComplete,
    uint charWidth,
    bool clearOutputWhenComplete)
:
    mBarWidth(charWidth - 7),
    mCharWidth(charWidth),
    mClearOutputWhenComplete(clearOutputWhenComplete),
    mOutStream(outStream),
    mProgress(0),
    mProgressWhenComplete(progressWhenComplete),
    mSpinCharIndex(0, 4),
    mStopped(false)
{
    WriteProgressBar();
}

void ProgressBar::AddProgress(int progressIncrement)
{
    int thousandthsBefore = 1000 * mProgress / mProgressWhenComplete;
    mProgress += progressIncrement;
    int thousandthsAfter = 1000 * mProgress / mProgressWhenComplete;
    
    if (thousandthsBefore != thousandthsAfter && !mStopped)
    {
        ClearProgressBar();
        WriteProgressBar();
    }
}

void ProgressBar::Start()
{
    if (mStopped)
    {
        mStopped = false;
        WriteProgressBar();
    }
}

void ProgressBar::Stop(bool clearOutput)
{
    if (clearOutput)
        ClearProgressBar();
    else
        mOutStream << std::endl;
    
    mStopped = true;
}

void ProgressBar::ClearProgressBar()
{
    for (uint i = 0; i < mCharWidth; ++i)
        mOutStream << '\b';
    
    mOutStream.flush();
}

void ProgressBar::WriteProgressBar()
{
    double progressProportion = static_cast<double>(mProgress) / mProgressWhenComplete;
    
    mOutStream << std::setw(3) << floor(progressProportion * 100);
    mOutStream << "% [";
    
    int barChars = 0;
    int charsOfProgress = static_cast<int>(floor(progressProportion * mBarWidth));
    
    for (; barChars < charsOfProgress; ++barChars)
        mOutStream << '=';
    
    assert(mProgress <= mProgressWhenComplete);
    if (mProgress != mProgressWhenComplete)
    {
        mOutStream << M_SPIN_CHARS[mSpinCharIndex++];
        ++barChars;
    }
    
    for (; barChars < mBarWidth; ++barChars)
        mOutStream << ' ';
    
    mOutStream << ']';
    
    mOutStream.flush();
}
