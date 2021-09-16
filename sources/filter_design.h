#ifndef __FILTER_DESIGN__H__
#define __FILTER_DESIGN__H__

#include <vector>
#include <complex>
#include "biquad.h"

namespace filter_design
{
    enum class filter_type
    {
        lowpass,
        highpass,
        bandpass,
        bandstop
    };

    struct zpk
    {
        std::vector<std::complex<double>> zeros{};
        std::vector<std::complex<double>> poles{};
        double gain = 1; // system gain
    };

    filter_design::zpk analog_lowpass(int filter_order);
    filter_design::zpk lp2lp(filter_design::zpk zpk, double cutoff_frequency);
    filter_design::zpk lp2hp(filter_design::zpk zpk, double cutoff_frequency);
    filter_design::zpk lp2bp(filter_design::zpk zpk, double passband_center, double passband_width);
    filter_design::zpk lp2bs(filter_design::zpk zpk, double stopband_center, double stopband_width);
    filter_design::zpk bilinear_transform(filter_design::zpk zpk, double sampling_frequency);
    std::pair <std::vector <std::complex <double> >, std::vector <std::complex <double> > > cplxpair(std::vector <std::complex <double> > z);
    biquad zpk2tf(filter_design::zpk zpk_sos);
    std::vector<biquad> zpk2sos(filter_design::zpk zpk);
};

#endif  //!__FILTER_DESIGN__H__