#ifndef __BIQUAD__H__
#define __BIQUAD__H__

#include <vector>
#include <complex>

// biquad filter expression:
// y[n] = b0 * x[n] + b1 * x[n-1] + b2 * x[n-2] - a1 * y[n-1] - a2 * y[n-2]

class biquad
{
private:
    double m_b0, m_b1, m_b2, m_a1, m_a2;
    double m_xn1, m_xn2, m_yn1, m_yn2;
public:
    biquad(double b0, double b1, double b2, double a1, double a2);
    biquad();
    ~biquad();
    std::vector<double> get_coefficients() { return std::vector<double> {m_b0, m_b1, m_b2, m_a1, m_a2}; }
    double process(double sample);
    std::vector<double> process(std::vector<double> samples);
};

#endif  //!__BIQUAD__H__