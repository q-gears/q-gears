////////////////////////////////////////////////////
// calculate_smooth_current_value_by_steps
start = A0;
end = A1;
steps = A2;
step = A3;

step = step << C;
A0 = step / steps;
A0 = A0 >> 5;
A0 = A0 - 80;
A0 = A0 & FF;
get_direction_vector_y;
V0 = V0 + 1000;
V0 = V0 * (end - start);
V0 = V0 >> C;
V0 = V0 / 2
V0 = start + V0;
return V0;
////////////////////////////////////////////////////



////////////////////////////////
// field_calculate_distance_to_screen
S0 = A0;
S1 = A1;

func3ae38;

A0 = w[80071e40];
PsyQSetRotMatrix;

A0 = w[80071e40];
PsyQSetTransMatrix;

A0 = 0;
A1 = 0;
PsyQSetGeomOffset;

A0 = S0;
A1 = S1;
A2 = SP + 10;
A3 = SP + 14;
PsyQRotTransPers;

func3aed8;

return V0;
////////////////////////////////
