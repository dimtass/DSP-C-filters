#include "so_butterworth_bsf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_butterworth_bsf_calculate_coeffs(float bw, int fc, int fs)
{
	F_SIZE c = tan(pi*fc*bw / fs);
	F_SIZE d = 2.0 * cos(2.0 * pi * fc / fs);
	m_coeffs.a0 = 1.0 / (1.0 + c);
	m_coeffs.a1 = -m_coeffs.a0 * d;
	m_coeffs.a2 = m_coeffs.a0;
	m_coeffs.b1 = -m_coeffs.a0 * d;
	m_coeffs.b2 = m_coeffs.a0 * (1.0 - c);
	return(m_coeffs);
}

F_SIZE so_butterworth_bsf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_butterworth_bsf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_butterworth_bsf_get_offset(F_SIZE offset)
{
	return(m_offset);
}