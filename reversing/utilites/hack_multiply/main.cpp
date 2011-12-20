#include <stdio.h>

using namespace std;

int main()
{
    for( __int64 A0 = 0; A0 <= 100; ++A0 )
    {
        printf( "%d:", (int)A0 );

        __int64 A2 = A0 * 0x55555556;
        A2 = A2 >> 0x20;
        int x = A2 - (A0 >> 0x1f);
        printf(" - %d\n", x);
    }
/*
    for (__int64 A0 = 0; A0 <= 100; ++A0)
    {
        printf("%d:", A0);

        __int64 A2 = A0 * 0xcccccccd;
        A2 = A2 >> 0x24;
        printf(" - %d\n", A2);
    }
*/
/*
    for (__int64 x = 0; x <= 1000; x = x + 10)
    {
        printf("%d:", x);
        __int64 A0 = x * 0x10624dd3;
        A0 = A0 >> 0x25;

        __int64 V1 = x >> 0x1f;

        A0 = A0 - V1;
        V1 = A0 << 5;
        V1 = V1 - A0;
        V1 = V1 << 2;
        V1 = V1 + A0;
        V1 = V1 << 2;
        __int64 V0 = x - V1;

        printf(" - %d\n", V0);
    }
*/
/*
    for (__int64 A0 = 0; A0 <= 100; ++A0)
    {
        printf("%d:", A0);

        __int64 V0 = A0 * 0xaaaaaaab;
        V0 = V0 >> 0x23;
        printf(" - %d\n", V0);
    }
*/
/*
    for (__int64 A0 = 0; A0 <= 100; ++A0)
    {
        printf("%d:", A0);

        __int64 V0 = A0 * 0xba2e8ba3;
        V0 = V0 >> 0x23;
        printf(" - %d\n", V0);
    }
*/
/*
    for (__int64 A0 = 0; A0 <= 100; ++A0)
    {
        printf("%d:", A0);

        __int64 T0 = A0 * 0x30c30c31;
        T0 = T0 >> 0x22;
        T0 = (A0 - T0 * 0x15) * 0xc;
        printf(" - %d\n", T0);
    }
*/
/*
    for (__int64 V1 = 0; V1 <= 100; ++V1)
    {
        printf("%d:", V1);
        __int64 V0 = V1 * 0xb8;
        __int64 T3 = V0 * 0x66666667;
        T3 = T3 >> 0x20;
        V0 = V0 >> 0x1f;
        int x = (T3 >> 3) - V0;
        printf(" - %d\n", x);
    }
*/
    return 0;
}
