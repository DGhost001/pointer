#include <pebble.h>
#include <math.h>
#include "vMath.h"

#define NUM_ELEMENTS(X) sizeof(X)/sizeof(X[0])

void Vector_set(Vector* v, double x, double y, double z)
{
  v->x_ = x;
  v->y_ = y;
  v->z_ = z;
}

double Vector_Norm(Vector* v)
{
  double sum = 0;
  for(unsigned int i=0; i<NUM_ELEMENTS(v->elements); ++i)
  {
    sum += v->elements[i]*v->elements[i];
  } 
  
  return sqrt(sum);
}

void Vector_Mul(Vector *v, double m)
{
  for(unsigned int i=0; i<NUM_ELEMENTS(v->elements); ++i)
  {
    v->elements[i] = v->elements[i]*m;
  }
}

void Vector_Div(Vector *v, double d)
{
  for(unsigned int i=0; i<NUM_ELEMENTS(v->elements); ++i)
  {
    v->elements[i] = v->elements[i]/d;
  }  
}

void Quaternion_fromRot(Quaternion *q, Vector *v, double angle)
{
   const double sinh = sin( angle / 2.0 );
   const double cosh = cos( angle / 2.0 );
   
   q->qs_ = cosh;
   q->q1_ = v->x_ * sinh;
   q->q2_ = v->y_ * sinh;
   q->q3_ = v->z_ * sinh;
}
