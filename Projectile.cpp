//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits> 
#include <cmath> 
#include <math.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

// float projectile(const float h, const float v, const float m, 
//                 const float theta, const float d, 
//                 const float t, const float b, const float w, 
//                 float& destX, float& destY); 

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//


// float convert(const float theta, float theta_radian){
//   theta_radian = (180/3.1415926) * theta; 
//   return theta_radian; 
// }

// float projectile(const float h, const float v, const float m, 
//                const float theta, const float d, 
//                const float t, const float b, const float w, 
//                float& destX, float& destY) {
  //part one (going up stops)


bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
  // Your code here ...
  if (v<0 || h<0 || m<0 || w< 0 || t<0 || theta<-90 || theta>270 || b<0) //invalid parameters
  return false;
  
  if (theta == 90 || v == 0 || theta == 270 || theta == -90){
    destX = 0; 
    destY = h;
    return true;
  }

//part one 
  float v_y_i= v* sin((M_PI/180) * theta);
  float v_x = v* cos((M_PI/180) * theta); 
  float accleration = 9.8; 
  float distance_up = v_y_i/(2*accleration); 
  float time_one = v_y_i / accleration; 
//part two
  float distance_vertical = h+distance_up; 
  float time_two= sqrt(2*distance_vertical/(accleration)); 
  float time_total = time_one + time_two; //actual time to floor 
  float dest_x = time_total * v_x; 
  float t_max = (b+w)/v_x; 
  float t_min = b/v_x; 
  float dest_y = v_y_i * t_min - 4.9*(pow(t_min,2));
  float height = h+dest_y;
  float distance_without_block = distance_vertical - t; 
  float time_without_block = sqrt(distance_without_block/accleration); 
  float time_total_without_block = time_without_block + time_one; 

  if(theta > 90){ //Obtuse angle firing
    float tground = (v_y_i + sqrt(pow(v_y_i,2) - 4*4.9*(-h)))/accleration;
    destX = tground * v_x;
    destY = 0;
    return true;
}

  if (height < t && height > 0){//when it hits the wall
  destX = b;
  destY = height;
  return true;
}
  
  if ((dest_x >= b) && (dest_x <= b+w)) {
    if (dest_x == b) {
      destX = b; 
      destY=t; 
    } else if (dest_x == b+w) {
      destX = b+w; 
      destY=t; 
    } else {
      destX= time_total_without_block * v_x; 
      destY=t;
    } 
  }

  if (dest_x > b+w || dest_x < b) {
    float tground = (v_y_i + sqrt(pow(v_y_i,2) - 4*4.9*(-h)))/accleration;
    destX = tground * v_x; 
    destY = 0; 
  } 
return true; 
}





  // if (time_total > time_total_without_block) {
  //   destX = dest_x; 
  //   destY = 0; 
  // } else if (time_total < t_min) {
  //   destX= dest_x; 
  //   destY = 0; 
  // } else if ((dest_x > b) && (dest_x < b+w)) {
  //   destX= time_total_without_block * v_x; 
  //   destY=t;
  // } else {
  //   destX = dest_x; 
  //   destY = 0; 



  // cout << "v_y_i: " << v_y_i << endl; 
  // cout << "v_x: " << v_x << endl;
  // cout << "distance_up: " << distance_up <<endl; 
  // cout << "distance_vertical: "<< distance_vertical << endl; 
  // cout << "distance_without_block: " << distance_without_block << endl;
  // cout << "dest_x: " << dest_x << endl;
  // cout << "time_one: " << time_one << endl; 
  // cout << "time_two: " << time_two << endl; 
  // cout << "time_total: " << time_total << endl; 
  // cout << "time_without_block: " << time_without_block << endl; 
  // cout << "t_max: " << t_max << endl;
  // cout << "t_min: " << t_min << endl; 
  // cout << "time_total_without_block: " << time_total_without_block << endl;


//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....

  float h = 50;
  float v = 9.2;
  float m = 1;
  float theta = 67.89;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 20;
  float b = 30;
  float w = 20;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
