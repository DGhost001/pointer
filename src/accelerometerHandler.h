#pragma once

#include "vMath.h"

/*** This function initializes the accelerometer ***/
void Accl_init( void );

void Accl_dtor( void );

/** This returns the latest acceleration vector **/
void Accl_getLatestVector(Vector *v);
