/**
* Second order Linkwitz-Riley high-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency (-6 dB)
*
* Second-order Linkwitz�Riley HPFs are designed to have an attenuation of -6 dB
* at the corner frequency rather than the standard -3 dB When these
* filters are placed in parallel with the same cutoff frequency, their outputs sum exactly and
* the resulting response is flat. They are often used in crossovers.
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_linkwitz_riley_hpf_calculate_coeffs(int fc, int fs);
F_SIZE so_linkwitz_riley_hpf_filter(F_SIZE sample);
void so_linkwitz_riley_hpf_set_offset(F_SIZE offset);
F_SIZE so_linkwitz_riley_hpf_get_offset(F_SIZE offset);