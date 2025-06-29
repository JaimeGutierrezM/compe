//themandelbrot
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Complex {
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
    double magnitude() const {
        return real * real + imag * imag; // Square of magnitude for comparison
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        if (t > 0) cout << '\n'; // Blank line between test cases

        string chars;
        double mini, maxi, preci, minr, maxr, precr;
        cin >> chars >> mini >> maxi >> preci >> minr >> maxr >> precr;

        // Calculate grid dimensions
        int rows = static_cast<int>((maxi - mini + preci) / preci);
        int cols = static_cast<int>((maxr - minr + precr) / precr);

        // Generate plot
        for (double imag = mini; imag <= maxi + 1e-10; imag += preci) {
            for (double real = minr; real <= maxr + 1e-10; real += precr) {
                Complex c(real, imag);
                Complex z(0, 0);
                int iterations = 0;

                // Iterate up to 12 times
                while (iterations < 12) {
                    if (z.magnitude() > 4) break; // Magnitude > 2 means square > 4
                    z = z * z + c;
                    ++iterations;
                }

                // Output character
                if (iterations == 12 && z.magnitude() <= 4) {
                    cout << ' ';
                }
                else {
                    cout << chars[iterations];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}