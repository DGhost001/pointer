#include <pebble.h>
#include "accelerometerHandler.h"
#include "filter.h"

/* Static variables for the accelerometer filter */
static IIRFilter accelFilter_x;
static IIRFilter accelFilter_y;
static IIRFilter accelFilter_z;

/** This function handles the callbacks from the accelerometer
    and puts the new data into the filter
**/
static void onNewData(AccelData *data, 
                      uint32_t num_samples)
{
  for(unsigned int i=0; i<num_samples; ++i)
  {
    IIR_addNewValue(&accelFilter_x, data[i].x);
    IIR_addNewValue(&accelFilter_y, data[i].y);
    IIR_addNewValue(&accelFilter_z, data[i].z);
  }
}

void  Accl_init( void )
{
    // We initiialy use a filter of 50
    IIR_createNewFilter(&accelFilter_x, 50);
    IIR_createNewFilter(&accelFilter_y, 50);
    IIR_createNewFilter(&accelFilter_z, 50);
  
    accel_service_set_sampling_rate(ACCEL_SAMPLING_100HZ);
    accel_data_service_subscribe(25, onNewData );
}

void Accl_getLatestVector(Vector *v)
{
    Vector_set(v, 
               IIR_getNewFilter(&accelFilter_x),
               IIR_getNewFilter(&accelFilter_y),
               IIR_getNewFilter(&accelFilter_z));
    Vector_Div(v, Vector_Norm(v)); // Normalize the vector to a length of one
}

void Accl_dtor( void )
{
  accel_data_service_unsubscribe();
}
