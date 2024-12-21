/*
Parameters class declarations and definitions of Spectrum Analyzer
Copyright (C) 2020 Volkan Orhan

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/
#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
#include <QGradientStops>

struct DiscreteParameters {
    int barLedAmount;
    double ledHeightRatio;
};

struct ContinousParameters {
    double peakHeight;
};

enum class BarType {
    Discrete, Continuous
};

enum class GraphType : int {
    Bars = 0, LineGraph = 1, AreaGraph = 2
};

enum Frequency {
    _16Hz = 16,
    _20Hz = 20,
    _25Hz = 25,
    _30Hz = 30,
    _40Hz = 40,
    _50Hz = 50,
    _60Hz = 60,
    _100Hz = 100,
    _250Hz = 250,
    _500Hz = 500,
    _1kHz = 1000,
    _2kHz = 2000,
    _4kHz = 4000,
    _8kHz = 8000,
    _12kHz = 12000,
    _16kHz = 16000,
    _20kHz = 20000,
    _22kHz = 22000
};

struct FrequencyRange {
    Frequency beginningFrequency;
    Frequency endingFrequency;
};

enum class OctaveBands : int {
    One = 10, OneHalf = 20, OneThird = 30, OneQuarter = 40, OneSixth = 60, OneEighth = 80, OneTwelfth = 120, OneTwentyFourth = 240
};

struct SpectrumAnalyzerParameters {
    GraphType graphType = GraphType::Bars;
    BarType barType = BarType::Discrete;
    OctaveBands octaveBands = OctaveBands::OneHalf;
    FrequencyRange frequencyRange = {.beginningFrequency = Frequency::_20Hz, .endingFrequency = Frequency::_20kHz};
    Qt::Orientation barDirection = Qt::Orientation::Vertical;
    int dimmingRatio = 0;
    unsigned char dimmedTransparencyRatio = 100;
    double blackCoefficient;
    double peakValue;
    double floorValue;
    double barWidthRatio;
    DiscreteParameters discreteParameters;
    ContinousParameters continuousParameters;
    QGradientStops gradientStops;
};

#endif // PARAMETERS_HPP
