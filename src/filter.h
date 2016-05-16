#pragma once
/** This file implements a simple IIR Filiter
    for filtering the data received by the Compass and
    the accelerometer
 **/

#include <stdint.h>

struct IIRFilter_S
{
   int32_t filterData_[256];
   unsigned int filterLength_;
   unsigned int filterPos_;
   double filterSum_;
};

typedef struct IIRFilter_S IIRFilter;

/**
   This function creates a new Filter
   @param filter This is the filter to be created. The memory must be allocated
   @param length This is the length of the filter. Caped at 256
**/
void IIR_createNewFilter(IIRFilter* filter, unsigned int length);


/**
   This function adds a new value to the filter
   @param filter This is the filter where the value should be added to
   @param value This is the value that should be added to the filter
**/
void IIR_addNewValue(IIRFilter* filter, int32_t value);

/**
    This function returns a newly computed filter value
    @param filter This is the filter to be used to compute the new filter value
**/
double IIR_getNewFilter(IIRFilter *filter);

