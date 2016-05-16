#pragma once

#ifndef M_PI
 #define M_PI 3.14159265359
#endif

union Vector_U
{
   double elements[3];
   struct
   {
     double x_;
     double y_;
     double z_;     
   };
};

union Quaternion_U
{
  double elements[4];
  struct
  {
    double qs_;
    double q1_;
    double q2_;
    double q3_;
  };
};

typedef union Vector_U Vector;
typedef union Quaternion_U Quaternion;

/** This set new values to the vector **/
void Vector_set(Vector* v, double x, double y, double z);

inline void Vector_ex(Vector *v) { Vector_set(v, 1.0, 0.0, 0.0); }
inline void Vector_ey(Vector *v) { Vector_set(v, 0.0, 1.0, 0.0); }
inline void Vector_ez(Vector *v) { Vector_set(v, 0.0, 0.0, 1.0); }

/** This returns the Norm of the Vector **/
double Vector_Norm(Vector* v);

/** This multiplies a vector with a scalar **/
void Vector_Mul(Vector *v, double m);

/** This divides a vector by an scalar **/
void Vector_Div(Vector *v, double d);

void Quaternion_fromRot(Quaternion *q, Vector *v, double angle);
