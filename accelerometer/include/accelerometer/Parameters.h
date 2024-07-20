
// Define typedefs for units
typedef double Meters;
typedef double Grams;
typedef double Seconds;
typedef double G;

const int minRange = -2048;
const int maxRange = 2047;
constexpr G maxForce = 32 ;
constexpr float MeasureToAccConversionFator = 64;

struct accelerometerParameters {
    int minvalue{ minRange };
    int maxvalue{ maxRange };
    float gmax{ maxForce };
    int range{ maxRange - minRange };
    float measureToAcc{ 1 / MeasureToAccConversionFator };
};

accelerometerParameters params;