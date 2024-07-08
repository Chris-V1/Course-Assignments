#include <iostream>
using namespace std;

class Distance {

 public:

   /* Constructs a default Distance of 0 (0 feet and 0.0 inches)
   */
   Distance();


   /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
   Distance(unsigned ft, double in);


   /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
   Distance(double in);


   /* Returns just the feet portion of the Distance
   */
   unsigned getFeet() const;


   /* Returns just the inches portion of the Distance
   */
   double getInches() const;


   /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
   */
   double distanceInInches() const;


   /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
   */
   double distanceInFeet() const;


   /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
   */
   double distanceInMeters() const;


   /* Returns the sum of 2 Distances.
   */
   Distance operator+(const Distance &rhs) const;


   /* Returns the difference between 2 Distances.
   */
   Distance operator-(const Distance &rhs) const;


   /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
   */
   friend ostream & operator<<(ostream &out, const Distance &rhs);

 private:

   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */
   void init();
    

   unsigned feet;
   double inches;    
    
};
