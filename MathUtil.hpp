#ifndef MATHUTIL_HPP
#define MATHUTIL_HPP
#include <cmath>

namespace MathUtil
{
    template<class T> inline void divideLineIntoSegmentsAndGaps(T lineSize, unsigned int segmentAmount, T segmentGapRatio, T &resultingSegmentSize, T &resultingGapSize);
    template<class T> inline T clamp(T x, T a, T b);
    template<class T> inline size_t numberOfDigits(T number);
    template<class T> inline int firstDigit(double number);
    /**
     * Rounds given number by first n digits regardless point position
     * @param number Number to be rounded
     * @param n Amount of the first digits to be rounded regardless point position
     * @return Rounded number
     */
    template<class T> inline T roundBy(T number, size_t n);

    namespace ArithmeticProgression{
        template<class T> inline T elementAmount(T firstElement, T lastElement, T commonDifference);
        template<class T> inline T findNthElementByIndex(T firstElement, T commonDifference, size_t n);
        template<class T> inline T findNthElement(T firstElement, T commonDifference, size_t n);
        template<class T> inline T sumFirstNElementsByCommonDifference(T firstElement, T commonDifference, size_t n);
        template<class T> inline T sumFirstNElementsByLastElement(T firstElement, T lastElement, size_t n);
    }
};

template <class T> inline T MathUtil::clamp(T x, T a, T b) {
    return x < a ? a : (x > b ? b : x);
}

template <class T> inline void MathUtil::divideLineIntoSegmentsAndGaps(T lineSize, unsigned int segmentAmount, T segmentGapRatio, T &resultingSegmentSize, T &resultingGapSize) {
    T totalPartsSize = lineSize * segmentGapRatio;
    T totalGapsSize = lineSize - totalPartsSize;

    resultingSegmentSize = totalPartsSize / segmentAmount;
    resultingGapSize = totalGapsSize / (segmentAmount - 1);
}

template<class T> inline T MathUtil::ArithmeticProgression::elementAmount(T firstElement, T lastElement, T commonDifference) {
    return ((lastElement-firstElement)/commonDifference) +1;
}

template<class T> inline T MathUtil::ArithmeticProgression::findNthElementByIndex(T firstElement, T commonDifference, size_t n) {
    return  firstElement + n*commonDifference;
}

//n starts from 1
template<class T> inline T MathUtil::ArithmeticProgression::findNthElement(T firstElement, T commonDifference, size_t n) {
    return  firstElement + commonDifference*(n-1);
}

template<class T> inline T MathUtil::ArithmeticProgression::sumFirstNElementsByCommonDifference(T firstElement, T commonDifference, size_t n) {
    return (firstElement*2 + commonDifference*(n-1))*n/2;

}

template<class T> inline T MathUtil::ArithmeticProgression::sumFirstNElementsByLastElement(T firstElement, T lastElement, size_t n) {
    return (firstElement + lastElement)*n/2;
}


template<class T> inline size_t MathUtil::numberOfDigits(T number){
    return std::log10(number)+1;
}

template<class T> inline int MathUtil::firstDigit(double number) {
    int numOfDigits = numberOfDigits(number);
//   return (int)number/numOfDigits;
    int coeff = 1;
    for(int i=1; i<numOfDigits; i++)
        coeff *= 10;
    //number *= coeff;
    return ((int)number)/coeff;
}

template<class T> inline T MathUtil::roundBy(T number, size_t n) {
    int numOfDigits = numberOfDigits(number);
    int diff = int(n) - numOfDigits;
    double coeff = 1;
    if(diff>0) {
        for(int i=0; i<diff; i++)
            coeff *= 10;
        number = number*coeff;
        number = std::round(number);
        return number/coeff;
    }
    if(diff<0) {
        for(int i=0; i>diff; i--)
            coeff /= 10;
        number = number*coeff;
        number = std::round(number);
        return number/coeff;
    }
    return std::round(number);
}


#endif // MATHUTIL_HPP
