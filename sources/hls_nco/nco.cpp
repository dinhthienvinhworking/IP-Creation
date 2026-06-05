#include "ap_fixed.h"
#include "ap_int.h"

typedef ap_fixed<16, 2> sample_t;
typedef ap_ufixed<16, 12> step_t;

void nco(sample_t *sine_sample, step_t step_size)
{
#pragma HLS INTERFACE mode=s_axilite port=return bundle=control
#pragma HLS INTERFACE mode=s_axilite port=sine_sample bundle=control
#pragma HLS INTERFACE mode=s_axilite port=step_size bundle=control

    static ap_uint<16> phase_acc = 0;

    const sample_t sine_lut[16] = {
        0.0000000000,
        0.3826834324,
        0.7071067812,
        0.9238795325,
        1.0000000000,
        0.9238795325,
        0.7071067812,
        0.3826834324,
        0.0000000000,
       -0.3826834324,
       -0.7071067812,
       -0.9238795325,
       -1.0000000000,
       -0.9238795325,
       -0.7071067812,
       -0.3826834324
    };

    ap_uint<16> step_bits = step_size.range(15, 0);
    phase_acc += step_bits;

    ap_uint<4> lut_index = phase_acc.range(15, 12);
    *sine_sample = sine_lut[lut_index];
}
