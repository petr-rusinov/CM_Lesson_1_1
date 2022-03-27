#include "PhoneNumber.h"

ostream& operator << (ostream& out, const PhoneNumber& pn)
{
    cout << "+" << pn.countryCode << "(" << pn.cityCode << ")" << pn.number;
    if (pn.additionalNum)
        cout << " " << pn.additionalNum.value();

    return out;
}

bool operator < (const PhoneNumber& a, const PhoneNumber& b)
{
    return tie(a.countryCode, a.cityCode, a.number, a.additionalNum) < tie(b.countryCode, b.cityCode, b.number, b.additionalNum);
}

bool operator == (const PhoneNumber& a, const PhoneNumber& b)
{
    return !(a < b) && !(b < a);
}
