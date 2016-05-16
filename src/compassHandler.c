#include <pebble.h>
#include <math.h>
#include "compassHandler.h"
#include "filter.h"
  
static IIRFilter compassFilter;

static void onData(CompassHeadingData heading)
{
  IIR_addNewValue(&compassFilter,heading.magnetic_heading);
}

void Compass_Init( void )
{
  IIR_createNewFilter(&compassFilter, 16);  
  compass_service_set_heading_filter(0); // Get every change
  compass_service_subscribe(onData);    
}

void Compass_dtor( void )
{
  compass_service_unsubscribe();
}

void Compass_getQuaternion(Quaternion *q)
{
   Vector v;
   Vector_ez(&v); //Init the vector to be ez
   const double scaleFactor = ( TRIG_MAX_ANGLE ) * 2.0 * M_PI;  
    
   Quaternion_fromRot(q, 
                      &v, 
                      IIR_getNewFilter(&compassFilter) /  scaleFactor 
                     );
  
}
