#pragma once

#include <cmath>
#include <memory>

namespace teb_local_planner
{
    /**
     * converts a number constant to a double constant at compile time
     * to avoid having to cast everything to avoid warnings.
     **/
    inline constexpr double cst(long double v) { return (double)v; }

    constexpr double const_pi() { return cst(3.14159265358979323846); }

    /**
     * return the square value
     */
    template<typename T>
    inline T square(T x)
    {
        return x * x;
    }

    /**
     * return the hypot of x and y
     */
    template<typename T>
    inline T hypot(T x, T y)
    {
        return (T)(std::sqrt(x * x + y * y));
    }

    /**
     * return the squared hypot of x and y
     */
    template<typename T>
    inline T hypot_sqr(T x, T y)
    {
        return x * x + y * y;
    }

    /**
     * convert from degree to radian
     */
    inline double deg2rad(double degree) { return degree * cst(0.01745329251994329576); }

    /**
     * convert from radian to degree
     */
    inline double rad2deg(double rad) { return rad * cst(57.29577951308232087721); }

    /**
     * normalize the angle
     */
    inline double normalize_theta(double theta)
    {
        const double result = fmod(theta + const_pi(), 2.0 * const_pi());
        if (result <= 0.0)
            return result + const_pi();
        return result - const_pi();
    }

    /**
     * inverse of an angle, i.e., +180 degree
     */
    inline double inverse_theta(double th) { return normalize_theta(th + const_pi()); }

    /**
     * sign function.
     * @return the sign of x. +1 for x > 0, -1 for x < 0, 0 for x == 0
     */
    template<typename T>
    inline int sign(T x)
    {
        if (x > 0)
            return 1;
        else if (x < 0)
            return -1;
        else
            return 0;
    }

    /**
     * clamp x to the interval [l, u]
     */
    template<typename T>
    inline T clamp(T l, T x, T u)
    {
        if (x < l)
            return l;
        if (x > u)
            return u;
        return x;
    }

    /**
     * wrap x to be in the interval [l, u]
     */
    template<typename T>
    inline T wrap(T l, T x, T u)
    {
        T intervalWidth = u - l;
        while (x < l)
            x += intervalWidth;
        while (x > u)
            x -= intervalWidth;
        return x;
    }

    // /**
    //  * tests whether there is a NaN in the array
    //  */
    // inline bool arrayHasNaN(const double* array, int size, int* nanIndex = 0)
    // {
    //     for (int i = 0; i < size; ++i)
    //         if (g2o_isnan(array[i]))
    //         {
    //             if (nanIndex)
    //                 *nanIndex = i;
    //             return true;
    //         }
    //     return false;
    // }

} // namespace teb_local_planner