#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;


class V_Form; // Form + value

typedef class Form {

    private:
        int prec; // precision
        int width;
        ios_base::fmtflags format; // general, scientific, or fixed
        friend ostream& operator<<(ostream&, const V_Form&);

    public:

        explicit Form(int p = 3) : prec(p) { // default = 3
            format = (ios_base::fmtflags)0;
            width = 0; // as wide as necessary
        }

        V_Form operator()(double d) const; // used to import value

        Form& general() {
            format = (ios_base::fmtflags)0;
            return *this;
        }

        Form& scientific() {
            format = ios_base::scientific;
            return *this;
        }

        Form& fixed() {
            format = ios_base::fixed;
            return *this;
        }

        Form& precision(int p) {
            prec = p;
            return *this;
        }
        
}Form;

class V_Form {
    public:
        const Form& f;
        double value;

        V_Form(const Form& form, double v) : f(form), value(v) {}
};

V_Form Form::operator()(double d) const {
    return V_Form(*this, d);
}

ostream& operator<<(ostream& o, const V_Form& vf) {
    stringstream ss; // unchange original output stream
    ss.setf(vf.f.format, ios_base::floatfield);
    ss << setprecision(vf.f.prec) << vf.value;
    return o << ss.str(); // output to original stream
}

#endif