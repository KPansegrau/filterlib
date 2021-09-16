#ifndef __BUTTERWORTH__H__
#define __BUTTERWORTH__H__

#include <vector>
#include <complex>
#include "biquad.h"
#include "filter_design.h"

class butterworth
{

private:
    // TODO: Store these and provide getters
    int m_filter_order;
    std::vector<double> m_freq;
    filter_design::filter_type m_filter_type;
    double m_sampling_frequency;
    std::vector<biquad> m_sections;
    std::vector <biquad> coefficients(int filter_order, std::vector <double> freq, filter_design::filter_type filter_type, double sampling_frequency);

public:
    butterworth(int filter_order, std::vector<double> freq, filter_design::filter_type filter_type, double sampling_frequency);
    ~butterworth();
    std::vector<biquad> get_sections() { return m_sections; }
    double process(double sample);
    std::vector<double> process(std::vector<double> samples);
};

#endif //!__BUTTERWORTH__H__