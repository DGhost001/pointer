#include "filter.h"
#include <string.h>

#define NUM_ELEMENTS(X) sizeof(X)/sizeof(X[0])

void IIR_createNewFilter(IIRFilter* filter, unsigned int length)
{
    memset(filter,0,sizeof(IIRFilter)); //Clear the filter struct
    
    //Limit the length to the length of the filter data
    length = length>NUM_ELEMENTS(filter->filterData_)?
            NUM_ELEMENTS(filter->filterData_):
            length;
  
    filter->filterLength_ = length;
}

void IIR_addNewValue(IIRFilter* filter, int32_t value)
{
  const uint32_t oldValue = filter->filterData_[filter->filterPos_]; //Save the old value for later
  filter->filterData_[filter->filterPos_] = value; //Add the value to our filter
  filter->filterPos_ = (filter->filterPos_+1) % filter->filterLength_; //move the filter pos
  filter->filterSum_ = filter->filterSum_ - oldValue + value; //Update the sum
}

double IIR_getNewFilter(IIRFilter *filter)
{
  return filter->filterSum_ / (double)(filter->filterLength_);
}
